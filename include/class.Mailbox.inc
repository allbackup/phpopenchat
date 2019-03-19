<?php //-*-php-*-
/*   ********************************************************************   **
**   Copyright notice                                                       **
**                                                                          **
**   (c) 1995-2004 PHPOpenChat Development Team                             **
**   http://phpopenchat.sourceforge.net/                                    **
**                                                                          **
**   All rights reserved                                                    **
**                                                                          **
**   This script is part of the PHPOpenChat project. The PHPOpenChat        **
**   project is free software; you can redistribute it and/or modify        **
**   it under the terms of the GNU General Public License as published by   **
**   the Free Software Foundation; either version 2 of the License, or      **
**   (at your option) any later version.                                    **
**                                                                          **
**   The GNU General Public License can be found at                         **
**   http://www.gnu.org/copyleft/gpl.html.                                  **
**   A copy is found in the textfile GPL and important notices to the       **
**   license from the team is found in the textfile LICENSE distributed     **
**   with these scripts.                                                    **
**                                                                          **
**   This script is distributed in the hope that it will be useful,         **
**   but WITHOUT ANY WARRANTY; without even the implied warranty of         **
**   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          **
**   GNU General Public License for more details.                           **
**                                                                          **
**   This copyright notice MUST APPEAR in all copies of the script!         **
**   ********************************************************************   */

//Get default values
require_once(POC_BASE.'/config.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Mail.inc');
require_once(POC_INCLUDE_PATH.'/class.Logger.inc');

/**
* Implements a Mailbox within the chat
*
* @author  Michael Oertel <michael@ortelius.de>
* @access  public
* @version $Id: class.Mailbox.inc,v 1.14.2.6 2004/05/08 18:49:46 letreo Exp $
*/
class POC_Mailbox {
  
  /**
  * @var    object
  * @access private
  * @see    connect()
  */
  var $db;
  
  /**
  * @var    integer
  * @see    connect()
  * @see    disconnect()
  */
  var $connection_count = 0;
    
  /**
  * @var    array
  */
  var $mailbox = array();
    
  /**
  * @var    array
  */
  var $mails = array();
    
  /**
  * @var    array
  */
  var $subjects = array();
    
  /**
  * @var    array
  */
  var $bodies = array();
    
  /**
  * @var    array
  */
  var $times = array();
    
  /**
  * @var    array
  */
  var $recipients = array();
    
  /**
  * @var    string
  */
  var $type = '';
    
  /**
  * @var    integer
  */
  var $unread_mail_count = 0;
    
  /**
  * Constructor
  *
  * @param $box string
  * @desc Implements a mailbox
  */
  function POC_Mailbox( $box_type )
  {
    $this->type = $box_type;
        
    switch( $box_type )
    {
      case'inbox':
        $this->connect();
        $rs = $this->db->Execute( 'SELECT MAIL FROM '.DATABASE_TABLE_PREFIX.'mails WHERE RECIPIENT=\''.$_SESSION['chatter']->get_nick().'\' AND TRASHED_BY_RECIPIENT=0');
        $this->disconnect();
        break;
      case'outbox':
        $this->connect();
        $rs = $this->db->Execute( 'SELECT MAIL FROM '.DATABASE_TABLE_PREFIX.'mails WHERE SENDER=\''.$_SESSION['chatter']->get_nick().'\' AND TRASHED_BY_SENDER=0 AND NOT(TRASHED_BY_RECIPIENT=1 AND RECIPIENT=\''.$_SESSION['chatter']->get_nick().'\')');
        $this->disconnect();
        break;
      case'trash':
        $this->connect();
        $rs = $this->db->Execute( 'SELECT MAIL FROM '.DATABASE_TABLE_PREFIX.'mails WHERE (SENDER=\''.$_SESSION['chatter']->get_nick().'\' OR RECIPIENT=\''.$_SESSION['chatter']->get_nick().'\') AND (TRASHED_BY_SENDER = 1 OR TRASHED_BY_RECIPIENT = 1)');
        $this->disconnect();
        break;
      
      default:
        die('Please specify the type of mailbox! Type can be "inbox", "outbox" or "trash"');
    }
    while( !$rs->EOF ) {
      $this->mailbox[] = unserialize( $rs->fields[0] );
      $rs->MoveNext();
    }
    $rs->Close();
    
    $this->_load_mails();
  }

  /**
  * Connect to the database
  *
  * Establish a database connection
  *
  * @access public
  */
  function connect()
  {
    if( ++$this->connection_count > 1 )
      return null;

    //create a database object
    $this->db = &NewADOConnection( DATABASE_DRIVER );
    if( USE_PCONNECT )
      $this->db->PConnect( DATABASE_HOST, DATABASE_USER, DATABASE_PASSWORD, DATABASE_TABLESPACE );
    else
      $this->db->Connect( DATABASE_HOST, DATABASE_USER, DATABASE_PASSWORD, DATABASE_TABLESPACE );

    return true;
  }

  /**
  * Disconnect the database
  *
  * @access public
  * @see connect()
  */
  function disconnect()
  {
    if( --$this->connection_count == 0 )
    {
      $this->db->Close();
      
      /*
       * NOTE: a db->Close() will be not enough! without setting $this->db to null,
       * PHP 4.2.1 can't serialize the object $line ( see POC_Channel_Buffer_DB::put_line() )
       * who contains a chatter object.
       */
      $this->db = null;
      
      return true;
    }
    
    return null;
  }

  /**
  * Loads all mail objects into an arrays
  *
  * @access private
  * @return boolean
  * @desc Loads all mail objects into an arrays
  */
  function _load_mails()
  {
    if( count($this->mailbox) == 0 )
      return false;
      
    //clear array of mails
    $this->mails = array();
    reset( $this->mailbox );
    do
    {
      $mail = current($this->mailbox);
      if( !is_object($mail) ) continue;
      if( !$mail->is_red_by_recipient() )
        $this->unread_mail_count++;
      $this->mails[] = $mail;
    }while( next($this->mailbox) );
    unset($mail);

    return true;
  }

  /**
  * Provides the fill level of mailbox
  *
  * @access public
  * @return boolean
  */
  function is_empty()
  {
    return count( $this->mails ) == 0;
  }

  /**
  * Provides the count of mails in the current mailbox
  *
  * @access public
  * @return integer
  */
  function get_mail_count()
  {
    return count( $this->mails );
  }

  /**
  * Provides the count of *new* mails in the current mailbox
  *
  * @access public
  * @return integer
  */
  function get_unread_mail_count()
  {
    return $this->unread_mail_count;
  }

  /**
  * Provides the type of mailbox
  *
  * @access public
  * @return string
  */
  function get_type()
  {
    return $this->type;
  }

  /**
  * Provides an mail-object of current mailbox
  *
  * @access public
  * @return array
  */
  function get_current_mail( $key )
  {
    if( isset($this->mails[ $key ]) )
      return $this->mails[ $key ];
    else
      die('get_current_mail(): No mail with this index found! Key: '.$key.'array count: '.count($this->mails));
  }

  /**
  * Deletes an mail-object in current mailbox
  *
  * @access public
  * @return boolean
  */
  function delete_mail( $key )
  {
    if( isset($this->mails[ $key ]) )
      unset( $this->mails[ $key ] );
    else
      die('delete_mail: No mail with this index found!');
  }

  /**
  * Provides the name of sender or recipient of given mail
  *
  * @access public
  * @return string
  * @param object
  */
  function get_chatter( $mail, $chatter )
  {
    if( $mail->get_recipient() == $chatter )
    {
      $sender = $mail->get_sender();
      return $sender->get_nick();
    }
    else
      return $mail->get_recipient();
  }
}
?>