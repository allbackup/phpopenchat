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
require_once(POC_INCLUDE_PATH.'/class.Logger.inc');

/**
* Describes a channel
*
* @author  Michael Oertel <michael@ortelius.de>
* @access  public
* @version $Id: class.Channel.inc,v 1.9.2.5 2004/03/02 21:05:16 letreo Exp $
*/
class POC_Channel {

  /**
  * @var    string
  * @access public
  */
  var $name;

  /**
  * @var    boolean
  * @access public
  */
  var $moderated = false;

  /**
  * @var    string
  * @access public
  */
  var $password = '';

  /**
  * @var    string
  * @access public
  */
  var $message = '';

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
  * Constructor.
  *
  * create and setup a new channel object
  * channel types:
  * null = normal channel
  * 1    = moderated channel
  *
  * @param  string channel name
  * @access public
  */
  function POC_Channel( $name )
  {
    $this->connect();
    $rs = $this->db->Execute( 'SELECT TYPE, PASSWORD, MESSAGE FROM '.DATABASE_TABLE_PREFIX.'channels WHERE name=\''.$name.'\'');
    if($rs->RecordCount() <= 0)
      $this->name = null;
    else
      $this->name = $name;

		//if type 1 (moderated channel) set the instance variable
    $this->moderated = ( !is_null($rs->fields[0]) && $rs->fields[0] == 1 )? true:false;
		$this->password  = ( !is_null($rs->fields[1]) && $rs->fields[1] != '')? $rs->fields[1]:'';
		$this->message   = ( !is_null($rs->fields[2]) && $rs->fields[2] != '')? $rs->fields[2]:'';
    $rs->Close();
    $this->disconnect();
  }

  /**
  * Checks if the given nickname in channel
  * 
  * @access public
  * @param string
  * @return string
  */
  function is_attendant($nick)
  {
    $this->connect();
    $rs = $this->db->Execute( 'SELECT LAST_CHANNEL FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE ONLINE = \'1\' AND LAST_CHANNEL =\''.$this->name.'\' AND NICK = \''. $nick .'\'' );
    $online = $rs->RecordCount();
    $rs->Close();
    $this->disconnect();
    
    return($online == 1);
  }

  /**
  * Provides all nicknames of chatters in the current channel
  * 
  * @access public
  * @return array
  */
  function get_chatters()
  {
    $this->connect();
    $rs = $this->db->Execute( 'SELECT NICK FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE ONLINE = \'1\' AND LAST_CHANNEL =\''.$this->name.'\'' );
    $result = $rs->GetArray();
    $rs->Close();
    $this->disconnect();
    
    return $result;
  }
  
  /**
  * Get channel name.
  *
  * @access public
  */
  function get_name()
  {
    return $this->name;
  }

  /**
  * Provides the password of current channel.
  *
  * @access public
  */
  function get_password()
  {
    return $this->password;
  }

  /**
  * Provides the message of current channel.
  *
  * @access public
  */
  function get_message()
  {
    return $this->message;
  }
  
  /**
  * Provides the moderated flag
  *
  * @access public
  * @return boolean
  */
  function is_moderated()
  {
    return $this->moderated;
  }
  
  /**
  * Provides inforamtion about password protection of current channel
  *
  * @access public
  * @return boolean
  */
  function is_password_protected()
  {
    return ( $this->password != '' );
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
      return true;
    }
    
    return null;
  }
  
  /**
  * Test class Channel
  *
  * call like: POC_Channel::test();
  */
  function test()
  {
    $start = microtime();

    $chat = new POC_Channel( 'schulhof' );
    $chat->connect(); // connect to chat
    $chat->disconnect();
    $end = microtime();
    
    $array_s = explode(' ',$start);
    $array_e = explode(' ',$end);
    $time = round($array_e[ 1 ] + $array_e[ 0 ] - ( $array_s[1] + $array_s[0] ),2);
    print 'time needed: '.$time.'<br>';
  }

}
?>