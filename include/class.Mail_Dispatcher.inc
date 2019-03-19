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
require_once(POC_INCLUDE_PATH.'/class.Logger.inc');

/**
* Mail_Dispatcher sends and gets mail
*
* @author  Michael Oertel <michael@ortelius.de>
* @access  public
* @version $Id: class.Mail_Dispatcher.inc,v 1.13.2.7 2004/02/24 22:21:06 letreo Exp $
*/
class POC_Mail_Dispatcher {
  
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

  function POC_Mail_Dispatcher()
  {
    
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
      return true;

    //create a database object
    $this->db = &NewADOConnection( DATABASE_DRIVER );
    if( USE_PCONNECT )
      $status = $this->db->PConnect( DATABASE_HOST, DATABASE_USER, DATABASE_PASSWORD, DATABASE_TABLESPACE );
    else
      $status = $this->db->Connect( DATABASE_HOST, DATABASE_USER, DATABASE_PASSWORD, DATABASE_TABLESPACE );

    //$status = $this->db->Execute( 'SELECT name FROM '.DATABASE_TABLE_PREFIX.'channels' );

    return $status;
  }

  /**
  * Disconnect the database
  *
  * @access public
  * @see connect()
  
  * @desc Disconnect the database
*/
  function disconnect()
  {
    if( --$this->connection_count == 0 )
    {
      $this->db->Close();
      return true;
    }
    
    return null;
  }
  
  /**
  * Updates a Mail
  *
  * @param object
  */
  function make_persistent( $mail )
  {
    $sender_obj = $mail->get_sender();
    $sender = $sender_obj->get_nick();
    unset($sender_obj);
    
    $this->connect();
    $rs = $this->db->Execute( 'SELECT * FROM '.DATABASE_TABLE_PREFIX.'mails WHERE SENDER = \''. $sender .'\' AND RECIPIENT=\''.$mail->get_recipient().'\' AND TIME=\''.gmdate('Y-m-d-H-i-s', $mail->get_send_time()).'\'' );
    $record = array();
    $record[ 'MAIL' ] = serialize($mail);
    
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );

    //Insert the records into the database
    $this->db->Execute( $update_sql );
    $this->disconnect();
    unset($record);
    unset($update_sql);
    unset($rs);
    
  }
  
  /**
  * Sends a Mail
  *
  * @param object
  */
  function send_mail( $mail )
  {
    $sender_obj = $mail->get_sender();
    $sender = $sender_obj->get_nick();
    unset($sender_obj);
    $recipients = array();
    $recipients = $mail->get_recipients();
    reset($recipients);
    
    $this->connect();
    $sql1 = 'INSERT INTO '.DATABASE_TABLE_PREFIX.'mails (SENDER,RECIPIENT,MAIL,TIME)';
    
    $timestamp = $mail->get_send_time();
    do 
    {
      $mail->set_recipient( current($recipients) );
      $sql2 = 'VALUES (\''.$sender.'\',\''.current($recipients).'\',\''.serialize($mail).'\',\''.gmdate('Y-m-d-H-i-s', $timestamp).'\')';
      
      //Insert the records into the database
      if ( !$this->db->Execute( $sql1.$sql2 ) )
        die ( 'POC: Could\'t send mail, because of a DB-Error.' );
      
	  //notify chatter, if he is online
      $_SESSION['chat']->connect();
	  if(isset( $_SESSION['chat']) && $_SESSION['chat']->is_online( current($recipients) ) ) {
	  	$_chatter = $_SESSION['chat']->mkinstance_chatter(current($recipients));
	  	$_SESSION['chat']->write_sys_msg( $_SESSION['translator']->out('YOU_HAVE_NEW_MAIL'),$_chatter, true );
	  }
      $_SESSION['chat']->disconnect();
	  
    }while( next($recipients) );
    $this->disconnect();

    unset( $recipients );
    unset( $mail_serialized );
    unset( $timestamp );
    unset( $sql1 );
    unset( $sql2 );
  }
  
  /**
  * Check if given recipient exists
  *
  * @param string
  * @return boolean
  */
  function check_recipient( $recipients )
  {
      $this->connect();
      do
      {
        $rs = $this->db->Execute( 'SELECT NICK FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK = \''.current($recipients).'\'' );
        if($rs->EOF)
        {
          $rs->Close();
          $this->disconnect();
          return false;
        }
          
        $rs->Close();
      }while( next($recipients) );
      
      $this->disconnect();
      
      return true;
  }
  
  /**
  * Moves a mail into trashbin
  *
  * @param object
  * @param object
  * @param object
  * @return boolean
  */
  function trash_mail( $mail, $mailbox, $chatter )
  {
    $sender_obj = $mail->get_sender();
    $sender     = $sender_obj->get_nick();
    
    $this->connect();
    $rs = $this->db->Execute( 'SELECT * FROM '.DATABASE_TABLE_PREFIX.'mails WHERE SENDER = \''. $sender .'\' AND RECIPIENT=\''.$mail->get_recipient().'\' AND TIME=\''.gmdate('Y-m-d-H-i-s', $mail->get_send_time()).'\'' );
    $record = array();
    
    if ($mailbox->get_type() == 'trash')
      $flag = 2;//mail is scheduled to delete and is no longer shown within the trashbin
    else
      $flag = 1;//mail is scheduled to delete and is no longer shown within the trashbin
    
    
    if( $chatter->get_nick() == $mail->get_recipient() )
      $record[ 'TRASHED_BY_RECIPIENT' ] = $flag;
    elseif( $chatter->get_nick() == $sender )
      $record[ 'TRASHED_BY_SENDER' ]    = $flag;
    else 
      die('maildispatcher->trash_mail(): Can\'t move mail into trashbin.');
    
    if( $sender == $mail->get_recipient() )
    {
      $record[ 'TRASHED_BY_RECIPIENT' ] = $flag;
      $record[ 'TRASHED_BY_SENDER' ]    = $flag;
    }
    
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );

    //Insert the records into the database
    $this->db->Execute( $update_sql );
    
    if( $mailbox->get_type() == 'trash' )
    {
      $rs = $this->db->Execute( 'DELETE FROM '.DATABASE_TABLE_PREFIX.'mails WHERE SENDER = \''. $sender .'\' AND RECIPIENT=\''.$mail->get_recipient().'\' AND TIME=\''.gmdate('Y-m-d-H-i-s', $mail->get_send_time()).'\' AND TRASHED_BY_RECIPIENT=2 AND TRASHED_BY_SENDER=2' );
    }

    $this->disconnect();
    unset($record);
    unset($update_sql);
    unset($rs);
    
    return true;
  }
  
  /**
  * Deletes a mail
  *
  * @param string
  * @param string
  * @param integer
  * @return boolean
  */
  function delete_mail( $sender, $recipient, $time )
  {
    
  }
  
  /**
  * Checks Mails
  *
  * @param object
  */
  function check_mail( $mail )
  {
  }
}
?>