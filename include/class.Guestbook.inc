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

/**
* Get default values
*/
require_once(POC_BASE.'/config.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Guestbook_Post.inc');
require_once(POC_INCLUDE_PATH.'/class.Logger.inc');

/**
 * Class Guestbook holds posts written by chatters
 *
 * @author Michael Oertel <michael@ortelius.de>
 * @access  public
 * @version $Id: class.Guestbook.inc,v 1.1.2.4 2004/02/24 22:00:48 letreo Exp $
 */
class POC_Guestbook {

  /**
  * chatter object represents a person taking part in a chat session
  *
  * @var object
  */
  var $chatter = null;

  /**
  * Contains all posts for current chatter
  *
  * @var array
  */
  var $posts = array();
  
  /**
  * @var    integer
  * @see    connect()
  * @see    disconnect()
  */
  var $connection_count = 0;
  
  /**
  * @var    object
  * @access private
  * @see    connect()
  */
  var $db;

  /**
   * Constructor for class Guestbook
   *
   * @param object $chatter chatter object represents a person taking part in a chat session
   */
  function POC_Guestbook( $_chatter )
  {
    // check $chatter - should be of class Chatter
    if( !is_object($_chatter) )
    {
      $_SESSION['logger']->error('Parameter is not an object',__FILE__,__LINE__);
      die('object expected');
    }
    $this->chatter = $_chatter;
    $this->load_posts();
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
  * Loads all posts for current chatter from DB
  *
  * @return void
  */
  function load_posts()
  {
    $this->connect();
    $sql = 'SELECT POST FROM '.DATABASE_TABLE_PREFIX.'guestbook 
             WHERE USER=\''.$this->chatter->get_user().'\' 
             ORDER BY TIME';
    $rs = $this->db->Execute( $sql );
    if( $rs->RecordCount() > 0 )
      $this->posts = $rs->GetArray();
    else 
      $this->posts = array();
    $rs->Close();
    $this->disconnect();
  }

  /**
  * Writes posts into the guestbook
  *
  * @param object
  * @access public
  */
  function put_post( $post )
  {
    if( !is_object($post) ) die('Object expected');

    $record = array();
    $record[ 'USER' ] = $this->chatter->get_user();
    $sender = $post->get_sender();
    $record[ 'SENDER' ] = $sender->get_nick();
    $record[ 'TIME' ] = time();
    $record[ 'POST' ] = serialize($post);

    $this->connect();
    $rs = $this->db->Execute( 'SELECT USER, SENDER, TIME, POST FROM '.DATABASE_TABLE_PREFIX.'guestbook' );
    $insert_sql = $this->db->GetInsertSQL( $rs, $record );
    unset($record);
    unset($rs);

    //Insert the records into the database
    if( !$this->db->Execute( $insert_sql ) )
    {
      $_SESSION['logger']->error('Can not update DB. SQL: "'.$insert_sql.'"', __FILE__, __LINE__ );      return false;
    }

    unset($insert_sql);
    $this->disconnect();
    
    return true;
  }
  
  function get_posts()
  {
    return $this->posts;
  }
  
  function del_post( $sender, $time )
  {
    $this->connect();
    $rs = $this->db->Execute( 'DELETE FROM '.DATABASE_TABLE_PREFIX.'guestbook WHERE SENDER = \''.$sender.'\' AND TIME = '.$time.' AND USER = \''.$_SESSION['chatter']->get_user().'\'' );
    $rs->Close();
    $this->disconnect();
    
    //reload posts
    $this->load_posts();
  }
}
?>