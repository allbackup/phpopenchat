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

/** Get configuration settings */
require_once(POC_BASE.'/config.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Logger.inc');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');

/**
 * Class Chatter represents a person taking part in a chat session
 *
 * @author Frerk Meyer <frerk@meychern.de>
 * @author Michael Oertel <michael@ortelius.de>
 * @access  public
 * @version $Id: class.Chatter.inc,v 1.84.2.31 2004/08/26 14:33:00 letreo Exp $
 */
class POC_Chatter
{
  /**
  * every chatter is identified by a uniq nick name
  *
  * @var string
  */
  var $nick = '';
  
  /**
  * password of chatter
  *
  * @var string
  */
  var $password = '';
  var $password_new = '';
  
  /**
  * every chatter has an user name
  *
  * @var string
  */
  var $user = '';

  /**
  * user name
  *
  * @var string
  */
  var $name = '';

  /**
  * birthday of chatter
  *
  * @var string
  */
  var $birthday = '';

  /**
  * gender of chatter
  *
  * @var string
  */
  var $gender = '';

  /**
  * email of chatter
  *
  * @var string
  */
  var $email = '';

  /**
  * hide email
  *
  * @var boolean
  */
  var $hide_email = true;

  /**
  * skip confirmation email
  *
  * @var boolean
  */
  var $skip_email = false;

  /**
  * A URL of a picture of chatter
  *
  * @var string
  */
  var $pictureURL = '';

  /**
  * A home page URL of chatter
  *
  * @var string
  */
  var $homePageURL = '';

  /**
  * Interests of chatter
  *
  * @var string
  */
  var $interests = '';

  /**
  * Motto of chatter
  *
  * @var string
  */
  var $motto = '';

  /**
  * A ICQ number of chatter
  *
  * @var integer
  */
  var $icqNumber = 0;

  /**
  * A AIM nickname of chatter
  *
  * @var string
  */
  var $aimNickname = '';

  /**
  * A YIM nickname of chatter
  *
  * @var string
  */
  var $yimNickname = '';

  /**
  * chatter grade
  *
  * @var string
  */
  var $grade = '';

  /**
  * chatter grade
  *
  * @var string
  */
  var $theme = DEFAULT_THEME;

  /**
  * chatter groups
  *
  * @var array
  */
  var $groups = array();

  /**
  * chatter disabled
  *
  * @var int
  */
  var $disabled = 0;

  /**
  * online time in seconds
  *
  * @var int
  */
  var $online_time = 0;

  /**
  * stores chatter objects of ignored chatters
  *
  * @var array
  */
  var $ignored_sender = array();

  /**
  * stores friends of chatter
  *
  * @var array
  */
  var $friends = array();

  /**
  * @var    boolean
  * @access private
  */
  var $private = false;

  /**
  * @var    boolean
  * @access private
  */
  var $bodies = false;

  /**
  * @var    boolean
  * @access private
  */
  var $sys_msg = false;
  
  /**
  * @var    string
  * @access public
  */
  var $color = '';
  
  /**
  * @var    string
  * @access public
  */
  var $advice = null;
  
  /**
  * @var    string
  * @access public
  */
  var $scrollspeed = -1;
  
  /**
  * @var    string
  * @access public
  */
  var $regTime = '';
  
  /**
  * @var    string
  * @access public
  */
  var $lastActive = '';
  
  /**
  * @var    string
  * @access public
  */
  var $lastHost = '';
  
  /**
  * @var    string
  * @access public
  */
  var $lastIP = '';
  
  /**
  * @var    string
  * @access public
  */
  var $lastReferer = '';
  
  /**
  * @var    string
  * @access public
  */
  var $lastUserAgent = '';
  
  /**
  * @var    string
  * @access public
  */
  var $lastSessionId = '';
  
  /**
  * @var    object
  * @access private
  * @see    connect()
  */
  var $db;
  
  /**
  * @var    boolean
  * @access private
  * @see    check_user()
  */
  var $guest = false;
  
  /**
  * @var    integer
  * @see    connect()
  * @see    disconnect()
  */
  var $connection_count = 0;
  
  /**
  * @var    float
  */
  var $lines_per_day = 0;
  
  /**
  * @var    float
  */
  var $logins_per_day = 0;

  /**
  * @var    integer
  */
  var $days_registered = 0;

  /**
  * @var    integer
  */
  var $db_instance_lifetime = 0;

  /**
  * @var    array
  */
  var $unlocked_channels = array();

  /**
  * @var    string
  */
  var $preferred_language = '';
  
  /**
  * Constructor
  * 
  * Implements a chat user
  * @desc Implements a chat user
  * 
  * @param string $nick
  * @param string $password
  */
  function POC_Chatter($user = STATUS_BOT_NAME, $password = null )
  {

    if ( $_user = $this->check_user($user,$password) )
    {
      $this->set_nick( $_user );
      if( $this->is_guest() )
        $this->register();
      $this->password = $password;
    }
    else
      $this->nick = null;
  }
  
  /**
  * Check if user name and it's account data are valid
  * 
  * Return false if $user is not valid
  * 
  * @param string
  * @param string
  * @return boolean
  */
  function check_user($user,$password)
  {
    //don't check if nick equals STATUS_BOT_NAME
    //note: chat users can't login as 'STATUS_BOT_NAME'
    if ( $user == strval(STATUS_BOT_NAME) )
      return STATUS_BOT_NAME;

    // nick names must be strings
    if (!isset($user))
      return '';

    // passwords can't be empty
    if ($password == '')
    {
      if( ALLOW_GUEST_LOGIN )
      {
        $this->guest = true;
        $guest_nickname = '###GUEST_NICK_PREFIX###'.'_'.rand(10000,99999);
        return $guest_nickname;
      }
      else
        return '';
    }

    // nick names must be strings
    if (!is_string($user))
      return '';

    // nick names are no longer than 16 characters
    if (strlen($user) > NICKNAME_MAX_LENGTH)
      return '';
      
    // nick names start with a character and go on with alphanumeric
    // Attention: Spaces are allowed
    if (!eregi("^[[:alpha:]]+[[:alnum:]]*",$user))
      return '';
    
    //poc uses the '+' as placeholder for a SPACE in a nickname.
    //So, a PLUS character can't be a part of a nickname.
    if(preg_match('/\+/',$user))
      return '';
    
    // the given password must match with the db-password
    return $this->is_authorized($user, $password);

  }

  /**
  * Provides the status of chatter
  *
  * @access public
  * @return boolean
  */
  function is_moderator()
  {
      return in_array('moderator', $this->groups);
  }

  /**
  * Provides the status of chatter
  *
  * @access public
  * @return boolean
  */
  function is_vip()
  {
      return in_array('vip', $this->groups);
  }

  /**
  * Provides the status of chatter
  *
  * @access public
  * @return boolean
  */
  function is_kicked()
  {
    $this->connect();
     $user = $this->is_guest()? $this->nick:$this->user;
     $rs = $this->db->Execute( 'SELECT KICKED FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER=\''.$user.'\'');
     $status = intval($rs->fields[0]);
     $rs->Close();
    $this->disconnect();

    return ($status === 1 );
  }
  
  function is_disabled()
  {
      $this->connect();
	   $user = $this->is_guest()? $this->nick:$this->user;
       $rs = $this->db->Execute( 'SELECT DISABLED FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER=\''.$user.'\'');
       $status = intval($rs->fields[0]);
       $rs->Close();
      $this->disconnect();

      return ($status === 1 );
      
  }


  /**
  * Provides the online status of chatter
  *
  * @access public
  * @return boolean
  */
  function is_online()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT ONLINE FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER=\''.$this->user.'\'');
       $status = intval($rs->fields[0]);
       $rs->Close();
      $this->disconnect();

      return ($status === 1 );
  }

  /**
  * Provides the status of chatter
  *
  * @access public
  * @return boolean
  */
  function is_banned( $channel )
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT TIME_BANNED FROM '.DATABASE_TABLE_PREFIX.'banned_users WHERE USER=\''.$this->user.'\' AND TIME_BANNED >= '.$this->db->DBTimeStamp(time()).' AND BANNED_FOR=\''.$channel.'\'');
       $status = ( $rs->RecordCount() >= 1 );
       $rs->Close();
      $this->disconnect();

      return $status;
  }

  /**
  * Banishment of chatter
  *
  * @access public
  * @return boolean
  */
  function ban( $channel, $period )
  {
    if( $this->is_banned($channel) ) return null;
    
    $this->count_hit('bann');
    $this->connect();
    $rs = $this->db->Execute( 'DELETE FROM '.DATABASE_TABLE_PREFIX.'banned_users WHERE USER = \''. $this->user .'\' AND BANNED_FOR = \''.$channel.'\'' );
    $rs = $this->db->Execute( 'SELECT USER,BANNED_FOR,TIME_BANNED FROM '.DATABASE_TABLE_PREFIX.'banned_users WHERE USER = \''. $this->user .'\'' );
    $record = array();
    $record[ 'TIME_BANNED' ] = $this->db->DBTimeStamp( (time() + (intval($period) * 60)) );
    $record[ 'BANNED_FOR' ] = $channel;
    $record[ 'USER' ] = $this->user;
    $insert_sql = $this->db->GetInsertSQL( $rs, $record );
    $insert_sql = preg_replace('/\'\'/','\'',$insert_sql);
    //Insert the records into the database
    $status = $this->db->Execute( $insert_sql );

    $this->disconnect();
    unset($record);
    unset($insert_sql);
    unset($rs);
    
    return $status;
  }
  
  /**
  * Changes the channel
  *
  */
  function join_channel( $post_channel, $private_new_window = false )
  {
    $prefix = ($private_new_window)? abs(crc32($post_channel)).'_':'';
    if(!$private_new_window)
    {
      //chatter want's to change the channel
      //we have to say goodbye in the old channel first» 
      //$said = $_SESSION['chatter']->get_nick().' ###LEAVES_THIS_CHANNEL### <!--'.rand(0,15).'-->';
      $said  = $this->get_nick(true).htmlentities(' ###LEAVES_THIS_CHANNEL### ');
      $said .= htmlentities(' ###GOES_TO_CHANNEL### ').$post_channel;
      $bot  = &new POC_Chatter(strval(STATUS_BOT_NAME),'');
      $line = &new POC_Line($bot, $said);
      $line->set_leave($_SESSION['chatter']->get_nick(true));
      $_SESSION['channel_buffer']->connect();
      $_SESSION['channel_buffer']->put_line($line);
      $_SESSION['channel_buffer']->disconnect();
    }
     //create the new channel object and write it into the session
     
     //because of a critical bug: http://bugs.php.net/bug.php?id=18071
     //do stupid things to register a new channel object in session
     //if bug is fixed, use:
     //$_SESSION[$prefix.'channel_buffer'] = &new POC_Channel_Buffer(strval($post_channel));
     //$_SESSION[$prefix.'channel'] = &new POC_Channel(strval($post_channel));
     //change buffer
     if(function_exists('session_unregister')) {
       @session_unregister($prefix.'channel_buffer');
     }
     if(function_exists('session_register')) {
       session_register($prefix.'channel_buffer');
     }
     ${$prefix.'channel_buffer'} = &new POC_Channel_Buffer($post_channel);
     $_SESSION[$prefix.'channel_buffer'] = ${$prefix.'channel_buffer'};
     //change channel
     if(function_exists('session_unregister')) {
       @session_unregister($prefix.'channel');
     }
     if(function_exists('session_register')) {
       session_register($prefix.'channel');
     }
     ${$prefix.'channel'} = &new POC_Channel($post_channel);
     $_SESSION[$prefix.'channel'] = ${$prefix.'channel'};
     //get current line index
     $_SESSION[$prefix.'channel_buffer']->connect();
      ${$prefix.'lastRedLine'} = $_SESSION[$prefix.'channel_buffer']->get_cur_line_idx();
     $_SESSION[$prefix.'channel_buffer']->disconnect();
     $_SESSION[$prefix.'lastRedLine'] = ${$prefix.'lastRedLine'};
     
     if(!$private_new_window)
       $_SESSION['chatter']->go_online($post_channel);
     
     //now we have to say hello in the new channel«
     $said  = $this->get_nick(true).htmlentities(' ###JOINS_THIS_CHANNEL### "').$_SESSION[$prefix.'channel']->get_name().'"';
     $line = &new POC_Line($bot, $said);
     $line->set_login($_SESSION['chatter']->get_nick(true));
     $_SESSION[$prefix.'channel_buffer']->connect();
      $_SESSION[$prefix.'channel_buffer']->put_line($line);
     $_SESSION[$prefix.'channel_buffer']->disconnect();
     if( $_SESSION[$prefix.'channel']->get_message() != '' )
       $_SESSION['chat']->write_sys_msg( '<br />'.$_SESSION[$prefix.'channel']->get_message(),$_SESSION['chatter'], true );
     unset($bot);
     unset($said);
     unset($line);
     unset($prefix);
  }

  function is_authorized_for( $channel )
  {
    if( !$_SESSION['channel']->is_password_protected() ) return true;
    return ( in_array($channel,$this->unlocked_channels ) );
  }

  function unlock_channel( $channel )
  {
    if( !is_string($channel) ) die('String expected');
    $this->unlocked_channels[] = $channel;
  }
  
  /**
  * Provides the status of chatter
  *
  * @access public
  * @return boolean
  */
  function is_operator()
  {
      return in_array('operator', $this->groups);
  }
  
  /**
  * Connect to the database
  *
  * Establish a database connection
  *
  * @access public
  * @return boolean
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
  * Sets chatter status to online
  *
  * @access public
  * @see go_offline()
  * @param string
  */
  function go_online( $channel )
  {
    $this->connect();
    $rs = $this->db->Execute( 'SELECT ONLINE,LAST_CHANNEL,LAST_ACTIVE_TIME,LAST_HOST,LAST_IP,LAST_USER_AGENT,LAST_SESSIONID,LAST_REFERER FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK = \''. $this->nick .'\'' );
    $record = array();
    $record[ 'ONLINE' ] = 1;
    $record[ 'LAST_CHANNEL' ] = $channel;
    //$record[ 'LAST_ACTIVE_TIME' ] = date( "Y-m-d H:i:s", time() );
    $record[ 'LAST_ACTIVE_TIME' ] = $this->db->DBTimeStamp( time() );
    if ( isset($_SERVER['HTTP_X_FORWARDED_FOR']) && $_SERVER['HTTP_X_FORWARDED_FOR'] != '' )
    {
      $record[ 'LAST_HOST' ] = @gethostbyaddr( $_SERVER['HTTP_X_FORWARDED_FOR'] );
      $record[ 'LAST_IP' ]   = $_SERVER['HTTP_X_FORWARDED_FOR'];
    }
    else
    {
      $record[ 'LAST_HOST' ] = @gethostbyaddr($_SERVER['REMOTE_ADDR']);
      $record[ 'LAST_IP' ]   = $_SERVER['REMOTE_ADDR'];
    }
    $record[ 'LAST_USER_AGENT' ] = $_SERVER['HTTP_USER_AGENT'];
    $record[ 'LAST_SESSIONID' ] = session_id();
    if( $_SESSION['chat']->get_referer() != '' )
      $record[ 'LAST_REFERER' ] = $_SESSION['chat']->get_referer();
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );
    $update_sql = preg_replace('/\'\'/','\'',$update_sql);

    //Insert the records into the database
    if( !$this->db->Execute( $update_sql ) )
      $_SESSION['logger']->error('DB-Update failed. SQL: "'.$update_sql.'"', __FILE__, __LINE__);

    $this->disconnect();
    unset($record);
    unset($update_sql);
    unset($rs);
  }
  
  /**
  * Refreshs chatter's online time
  *
  * @access public
  * @see go_online()
  * @param string
  */
  function refresh()
  {
    $this->connect();
    $rs = $this->db->Execute( 'SELECT LAST_ACTIVE_TIME,ONLINE_TIME FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER = \''. $this->user .'\'' );
    $online_time = $rs->fields[1];
    $this->set_online_time((intval(LINE_POLLING_INTERVAL) * 2) + $online_time);
    $record = array();
    //$record[ 'LAST_ACTIVE_TIME' ] = date( "Y-m-d H:i:s", time() );//SQL92 date format
    $record[ 'LAST_ACTIVE_TIME' ] = $this->db->DBTimeStamp( time() );
    $record[ 'ONLINE_TIME' ] = (intval(LINE_POLLING_INTERVAL) * 2) + $online_time;
    unset($online_time);
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );
    $update_sql = preg_replace('/\'\'/','\'',$update_sql);//DBTimeStamp and GetUpdateSQL quotes time-strings and so we have to remove the double single quotes

    //Insert the records into the database
    if( !$this->db->Execute( $update_sql ) )
      $_SESSION['logger']->error('DB-Update failed. SQL: "'.$update_sql.'"', __FILE__, __LINE__);

    $this->disconnect();
    unset($record);
    unset($update_sql);
    unset($rs);
  }
  
  /**
  * Sets chatter's preferred language. 
  * Mostly used by integration scripts to adopt language settings.
  *
  * @access public
  * @param string
  */
  function set_preferred_language( $lang )
  {
    if( $mapped_lang = POC_Chat::map_language_code($lang) ){
      $this->preferred_language = $mapped_lang;
    }
  }
  
  /**
  * Provides chatter's preferred language
  *
  * @access public
  * @return string
  */
  function get_preferred_language()
  {
    return $this->preferred_language;
  }
  
  /**
  * Sets chatter's online time
  *
  * @access public
  * @see refresh()
  * @param integer
  */
  function set_online_time( $time )
  {
    $this->online_time = $time;
  }
  
  /**
  * Provides chatter's online time
  *
  * @access public
  * @return integer
  */
  function get_online_time()
  {
    return $this->online_time;
  }
  
  /**
  * Sets skip_email flag. If flag is set, no email will be send while registration procedure
  *
  * This setter is used mostly within scripts to integrate phpopenchat into other php-applications
  *
  * @access public
  */
  function set_skip_email()
  {
    $this->skip_email = true;
  }

  
  /**
  * Provides chatter's online time from DB
  *
  * @access public
  * @return integer
  */
  function get_db_online_time()
  {
    $this->connect();
    $rs = $this->db->Execute( 'SELECT ONLINE_TIME FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER = \''. $this->user .'\'' );
    $online_time = $rs->fields[0];
    $rs->Close();
    $this->disconnect();
    unset($rs);
    
    return $online_time;
  }
  
  /**
  * Sets chatter status to offline
  *
  * @access public
  * @see go_online()
  * @param string
  */
  function go_offline( $channel )
  {
       
    $this->connect();
    $rs = $this->db->Execute( 'SELECT ONLINE,LAST_CHANNEL FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK = \''. $this->nick .'\'' );
    $record = array();
    $record[ 'ONLINE' ] = '0';
    $record[ 'LAST_CHANNEL' ] = $channel;
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );

    //Insert the records into the database
    if( !$this->db->Execute( $update_sql ) )
      $_SESSION['logger']->error('DB-Update failed. SQL: "'.$update_sql.'"', __FILE__, __LINE__);

    //Delete private channel
    $sql = 'DELETE FROM '.DATABASE_TABLE_PREFIX.'channels WHERE NAME=\''.$this->get_nick(true).'\' AND TYPE = 2';
    if( !$this->db->Execute( $sql ) )
      $_SESSION['logger']->error('DB-Delete failed. SQL: "'.$sql.'"', __FILE__, __LINE__);

    /*
     * If is guest, remove account and 
     */
    $rs = $this->db->Execute( 'SELECT USER FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE ONLINE = 0 AND USER LIKE \'%###%\'' );
    //only guest have no name, because the name is required to register
    //$rs = $this->db->Execute( 'SELECT USER FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE ONLINE = 0 AND NAME = \'\'' );
    if( $rs->RecordCount() > 0 )
    {
      while(!$rs->EOF)
      {
        $sql = 'DELETE FROM '.DATABASE_TABLE_PREFIX.'channels WHERE NAME=\''.$rs->fields[0].'\' AND TYPE = 2';
        if( !$this->db->Execute( $sql ) )
          $_SESSION['logger']->error('POC_Chatter::go_offline(): Can not delete guest account from '.DATABASE_TABLE_PREFIX.'channels.<br>SQL: '.$sql, __FILE__, __LINE__);

        $sql = 'DELETE FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER=\''.$rs->fields[0].'\'';
        if( !$this->db->Execute( $sql ) )
          $_SESSION['logger']->error('POC_Chatter::go_offline(): Can not delete guest account from '.DATABASE_TABLE_PREFIX.'user_data.<br>SQL: '.$sql, __FILE__, __LINE__);

        $sql = 'DELETE FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER=\''.$rs->fields[0].'\'';
        if( !$this->db->Execute( $sql ) )
          $_SESSION['logger']->error('POC_Chatter::go_offline(): Can not delete guest account from '.DATABASE_TABLE_PREFIX.'user_account.<br>SQL: '.$sql, __FILE__, __LINE__);
  
        $rs->MoveNext();
      }
    }

    $this->disconnect();
    unset($user);
    unset($record);
    unset($sql);
    unset($update_sql);
    unset($rs);
  }

  /**
  * Sets the nickname of chatter
  * Used while registration 
  *
  * @access public
  */
  function set_nick($user)
  {
    if ( $user == strval(STATUS_BOT_NAME) )
    {
      $this->nick = $user;
      return null;
    }

    $this->connect();
     $rs = $this->db->Execute( 'SELECT NICK FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER=\''.$user.'\'');

     if ($rs->RecordCount() <= 0)
     {
       if( !preg_match('/  /', $user) )
         $this->nick = $user;//in case of registration
       if( $this->user = $this->get_db_user() )
         $this->_set_db_attributes();
     }
     else
     {
       $this->nick = $rs->fields[0];
       $this->_set_db_attributes();
       $nick = '';
     }

     $rs->Close();
    $this->disconnect();

    return ($this->nick == $user);
  }
  
  /**
  * Sets all attributes of chatter stored in DB
  *
  * @access private
  * @return void
  */
  function _set_db_attributes()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT EMAIL, 
                                         COLOR,
                                         ADVICE,
                                         SCROLLSPEED,
                                         FRIENDS,
                                         NAME,
                                         USER,
                                         PICTURE_URL,
                                         GRADE,
                                         THEME
                                    FROM '.DATABASE_TABLE_PREFIX.'user_data 
                                   WHERE NICK=\''.$this->nick.'\'');
       $this->email       = $rs->fields[0];
       $this->color       = $rs->fields[1];
       $this->advice      = $rs->fields[2];
       $this->scrollspeed = $rs->fields[3];
       $this->friends = array();
       if ( strlen($rs->fields[4]) ) {
         $this->friends     = (is_array(unserialize($rs->fields[4])))?unserialize($rs->fields[4]):array();
       }
       $this->name        = $rs->fields[5];
       $this->user        = $rs->fields[6];
       $this->pictureURL  = $rs->fields[7];
       $this->grade       = $rs->fields[8];
       if($rs->fields[9] != '')
         $this->theme       = $rs->fields[9];
       
       $rs->Close();
      $this->disconnect();
      unset($rs);

      $this->groups     = $this->get_db_groups();
      $this->get_db_user_info();
      $this->get_db_times();
      
      if(AUTHENTICATION_METHOD == 'poc')
        $this->password = $this->get_db_password();
       
  }
  
  /**
  * Initializes additional data of chatter stored in DB
  *
  * @access private
  * @return void
  */
  function init_additional_profile_data()
  {
    $this->connect();
     $rs = $this->db->Execute( 'SELECT ICQ_NUMBER,AIM_NICKNAME,YIM_NICKNAME,HOMEPAGE_URL,BIRTHDAY,HIDE_EMAIL,GENDER,INTERESTS,MOTTO,GRADE FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER=\''.$this->user.'\'');
     $this->icqNumber   = $rs->fields[0];
     $this->aimNickname = $rs->fields[1];
     $this->yimNickname = $rs->fields[2];
     $this->homePageURL = $rs->fields[3];
     $this->birthday    = $rs->fields[4];
     $this->hide_email  = ($rs->fields[5]=='1')? true:false;
     $this->gender      = $rs->fields[6];
     $this->interests   = $rs->fields[7];
     $this->motto       = $rs->fields[8];
     $this->grade       = $rs->fields[9];
     $rs->Close();
    $this->disconnect();
  }

  /**
  * Sets the user name of chatter
  *
  * @access public
  */
  function set_password($password)
  {
     if ( strlen($password) < PASSWORD_MIN_LENGTH )
       return false;
       
     if( MD5_PASSWORDS ) {
       $this->password = md5($password);
     } else {
       $this->password = $password;
     }
     
     return true;
  }

  /**
  * Sets user a new password
  *
  * @access public
  * @param string
  */
  function set_password_new( $passwd )
  {
    $this->password_new = $passwd;
  }

  /**
  * Gets the password of chatter
  *
  * @access public
  * @return string
  */
  function get_password()
  {
    return $this->password;
  }

  /**
  * Gets user name of chatter
  *
  * @access public
  * @return string
  */
  function get_user()
  {
    return $this->user;
  }

  /**
  * Provides the choosen theme of chatter
  *
  * @access public
  * @return string
  */
  function get_theme()
  {
    return $this->theme;
  }

  /**
  * Gets grade of chatter
  *
  * @access public
  * @return string
  */
  function get_grade()
  {
    return $this->grade;
  }
  function is_grade($grade){return ($this->get_grade() == $grade);}
  
  /**
  * Sets the user name of chatter
  *
  * @access public
  */
  function set_name($user)
  {
     if ( is_string($user) && strlen($user) >= 5 && preg_match('/.[^ ]+ .[^ ]+/', $user))
       $this->name = $user;
     else
       $user = '';

     return ($this->name == $user);
  }
  
  /**
  * Gets the name of chatter
  *
  * @access public
  * @return string
  */
  function get_name()
  {
    return $this->name;
  }

  /**
  * Sets the email address of chatter
  *
  * @access public
  */
  function set_email($email)
  {
    if( preg_match('/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@([0-9a-z](-?[0-9a-z])*\.)+[a-z]{2}([zmuvtg]|fo|me)?$/i', $email) )
    {
      $this->email = $email;
      return true;
    }
    return false;
  }
 
  /**
  * Sets user name of chatter
  *
  * @access public
  */
  function set_user( $user )
  {
    $this->user = $user;
  }

  /**
  * Sets icq number of chatter
  *
  * @access public
  * @return boolean
  */
  function set_icqNumber( $icqNumber )
  {
    $this->icqNumber = intval( $icqNumber );
    return true;
  }

  /**
  * Provides the icq number of chatter
  *
  * @access public
  * @return integer
  */
  function get_icqNumber()
  {
    return $this->icqNumber;
  }

  /**
  * Sets AIM nickname of chatter
  *
  * @access public
  * @return boolean
  */
  function set_aimNickname( $aimNickname )
  {
    if( strlen($aimNickname) > 30 ) return false;
    $this->aimNickname = $aimNickname;
    return true;
  }

  /**
  * Provides the AIM nickname of chatter
  *
  * @access public
  * @return integer
  */
  function get_aimNickname()
  {
    return $this->aimNickname;
  }

  /**
  * Sets YIM nickname of chatter
  *
  * @access public
  * @return boolean
  */
  function set_yimNickname( $yimNickname )
  {
    if( strlen($yimNickname) > 30 ) return false;
    $this->yimNickname = $yimNickname;
    return true;
  }

  /**
  * Provides the YIM nickname of chatter
  *
  * @access public
  * @return integer
  */
  function get_yimNickname()
  {
    return $this->yimNickname;
  }

  /**
  * Sets the birthday of chatter. Format is yyyy-mm-dd
  *
  * @access public
  * @return boolean
  */
  function set_birthday( $birthday )
  {
    if( strlen($birthday) > 10 ) return false;
    $this->birthday = $birthday;
    return true;
  }

  /**
  * Provides birthday of chatter
  *
  * @access public
  * @return string
  */
  function get_birthday()
  {
    return $this->birthday;
  }

  /**
  * Provides birthday of chatter
  *
  * @access public
  * @return string
  */
  function has_birthday()
  {
    $this->init_additional_profile_data();
    return preg_match('/\d{4}\-'.date('m').'\-'.date('d').'/',$this->birthday);
  }

  /**
  * Sets the gender of chatter. Possible values are 'f' or 'm'
  *
  * @access public
  * @return boolean
  */
  function set_gender( $gender )
  {
    if( strlen($gender)>1 ) die('Possible values for gender are \'f\' or \'m\'');
    $this->gender = $gender;
    return true;
  }

  /**
  * Provides gender of chatter
  *
  * @access public
  * @return string possible values are 'f' or 'm'
  */
  function get_gender()
  {
    return $this->gender;
  }
  
  /**
  * checks if chatter has something to hide
  *
  * @access public
  * @return boolean
  */
  function get_hide( $attribute )
  {
    switch($attribute)
    {
      case 'email': return ($this->hide_email);
      default:      return false;
    }
  }
  
  /**
  * hides attributes
  *
  * @access public
  */
  function set_hide( $attribute, $bool = false)
  {
    switch($attribute)
    {
      case 'email': $this->hide_email = $bool;
      default:      return false;
    }
  }

  /**
  * Provides the age of chatter
  *
  * @access public
  * @return mixed
  */
  function get_age()
  {
    $now_month   = date('m');
    $now_day     = date('d');
    $now_year    = date('Y');
    
    $parts = split('-', $this->birthday);
    if( intval($parts[0]) == 0 ) return '';
    $birth_month = $parts[1];
    $birth_day   = $parts[2];
    $birth_year  = $parts[0];
    unset($parts);

    $baseyear    = $now_year - $birth_year - 1;
    if( $birth_month < $now_month || ($birth_month == $now_month && $birth_day <= $now_day))
      $baseyear++;

    return $baseyear;
  }

  /**
  * Provides the guest flag
  *
  * @access public
  */
  function is_guest()
  {
    return $this->guest;
  }
  
  /**
  * Gets the E-Mail of chatter
  *
  * @access public
  * @return string
  */
  function get_email()
  {
    return $this->email;
  }

  /**
  * Sets a pictureURL of chatter
  *
  * @access public
  * @return boolean
  */
  function set_pictureURL($url)
  {
    if( $url=='' )
    {
      $this->pictureURL='';
      return true;
    }
    
    if( POC_Chat::check_URL($url) )
    {
      $this->pictureURL = $url;
      return true;
    }
    return false;
  }

  /**
  * Sets a home page URL of chatter
  *
  * @access public
  * @return boolean
  */
  function set_homePageURL($url)
  {
    $this->homePageURL = $url;
    if( $url=='' ) return true;
    if( POC_Chat::check_URL($url,false) ) return true;

    return false;
  }
  
  /**
  * Gets the pictureURL of chatter
  *
  * @access public
  * @return string
  */
  function get_pictureURL()
  {
    return $this->pictureURL;
  }

  /**
  * Gets the homePageURL of chatter
  *
  * @access public
  * @return string
  */
  function get_homePageURL()
  {
    return $this->homePageURL;
  }

  /**
  * Gets interests of chatter
  *
  * @access public
  * @return string
  */
  function get_interests()
  {
    return $this->interests;
  }

  /**
  * Sets interests of chatter
  *
  * @access public
  * @return string
  */
  function set_interests( $interests )
  {
    if( strlen($interests) >= 1024 )
      return false;
    $this->interests = $interests;
    return true;
  }

  /**
  * Gets interests of chatter
  *
  * @access public
  * @return string
  */
  function get_motto()
  {
    return $this->motto;
  }

  /**
  * Sets motto of chatter
  *
  * @access public
  * @return string
  */
  function set_motto( $motto )
  {
    if( strlen($motto) >= 1024 )
      return false;
    $this->motto = $motto;
    return true;
  }

  /**
  * Deletes this user
  *
  * @access public
  * @return boolean
  */
  function delete()
  {
    $bool = true;
    $sql1 = 'DELETE FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER = \''.$this->user.'\'';
    $sql2 = 'DELETE FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER = \''.$this->user.'\'';
    $this->connect();
    if ( !$this->db->Execute( $sql1 ) )
      $bool = false;
    if ( !$this->db->Execute( $sql2 ) )
      $bool = false;
    
    $this->disconnect();
    return $bool;
  }

  /**
  * Enables this chatter
  *
  * @access public
  * @return boolean
  */
  function enable()
  {
    $this->connect();
    $rs = $this->db->Execute( 'SELECT DISABLED FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER = \''. $this->user .'\'' );
    $record = array();
    $record[ 'DISABLED' ] = 0;
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );

    //Insert the records into the database
    if ( !$this->db->Execute( $update_sql ) )
    {
      $this->disconnect();
      return false;
    }
    $this->disconnect();
    unset($record);
    unset($update_sql);
    unset($rs);
    
    return true;
  }
  
  /**
  * Resets the kick flag
  *
  * @access public
  * @return boolean
  */
  function reset_kick()
  {
    $this->connect();
    $rs = $this->db->Execute( 'SELECT KICKED FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER = \''. $this->user .'\'' );
    $record = array();
    $record[ 'KICKED' ] = 0;
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );

    //Insert the records into the database
    if ( !$this->db->Execute( $update_sql ) )
    {
      $this->disconnect();
      return false;
    }
    $this->disconnect();
    unset($record);
    unset($update_sql);
    unset($rs);
    
    return true;
  }
  
  /**
  * Counts hits within the chat
  *
  * @access public
  * @param string
  */
  function count_hit( $page )
  {
    $this->connect();
    $rs = $this->db->Execute( 'SELECT '.strtoupper($page).' FROM '.DATABASE_TABLE_PREFIX.'hits WHERE USER = \''. $this->user .'\'' );
    if( !$rs->recordcount() )
    {
      $this->db->Execute( 'INSERT INTO '.DATABASE_TABLE_PREFIX.'hits (USER) VALUES (\''.$this->user.'\')' );
      $current_count = 0;
    }
    else
      $current_count = $rs->fields[0];

    $record = array();
    $record[ strtoupper($page) ] = ++$current_count;
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );

    //Insert the records into the database
    if ( !$this->db->Execute( $update_sql ) )
    {
      $this->disconnect();
      return false;
    }
    $this->disconnect();
    unset($record);
    unset($update_sql);
    unset($rs);
    
    return true;
  }
  
  /**
  * Provides the hit count of a given page
  *
  */
  function get_hit_count( $page )
  {
    $this->connect();
    $rs = $this->db->Execute( 'SELECT '.strtoupper($page).' FROM '.DATABASE_TABLE_PREFIX.'hits WHERE USER = \''. $this->user .'\'' );
    $count = ( !$rs->recordcount() )? 0:$rs->fields[0];
    $this->disconnect();
    return $count;
  }

  /**
  * Disables this chatter
  *
  * @access public
  * @return boolean
  */
  function disable()
  {
    $this->connect();
    $rs = $this->db->Execute( 'SELECT DISABLED FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER = \''. $this->user .'\'' );
    $record = array();
    $record[ 'DISABLED' ] = 1;
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );

    //Insert the records into the database
    if ( !$this->db->Execute( $update_sql ) )
    {
      $this->disconnect();
      return false;
    }

    $this->disconnect();
    unset($record);
    unset($update_sql);
    unset($rs);
    
    return true;
  }

  /**
  * Kicks this chatter out of the chat
  *
  * @access public
  * @return boolean
  */
  function kick()
  {
    $this->connect();
    $rs = $this->db->Execute( 'SELECT KICKED FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER = \''. $this->user .'\'' );
    $record = array();
    $record[ 'KICKED' ] = 1;
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );

    //Insert the records into the database
    if ( !$this->db->Execute( $update_sql ) )
    {
      $this->disconnect();
      return false;
    }

    $this->disconnect();
    unset($record);
    unset($update_sql);
    unset($rs);
    
    return true;
  }

  function is_registered()
  {
    $this->connect();
    $rs = $this->db->Execute( 'SELECT count(USER) FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER="'.$this->user.'"' );
    $bool = ( $rs->fields[0] > 0 );
    $rs->Close();
    unset($rs);
    $this->disconnect();

    return $bool;
  }

  /**
  * Register a new user
  *
  * @access public
  * @return boolean
  */
  function register()
  {
    //if( $this->is_registered() ) return $this->update();
    if(!isset($_SESSION['translator'])){
      $trans = &new POC_Translator();
    }else{
      $trans = &$_SESSION['translator'];
    }

    $mail = true;
    $confirm_sql = ',NULL';
    if( SEND_CONFIRMATION_MAIL && !preg_match('/#{3}GUEST_NICK_PREFIX#{3}/',$this->nick) )
    {   
      $headers  = 'From: "'.ADMIN_MAIL_NAME.'" <'.ADMIN_MAIL_ADDRESS.'>'.NL;
      $headers .= 'Reply-To: <'.ADMIN_MAIL_ADDRESS.'>'.NL;
      $headers .= 'Bcc: <'.ADMIN_MAIL_ADDRESS.'>'.NL;
      $headers .= 'Return-path: <'.ADMIN_MAIL_ADDRESS.'>'.NL;
      $headers .= 'Errors-To: <'.ADMIN_MAIL_ADDRESS.'>'.NL;
      $headers .= 'MIME-Version: 1.0'.NL;
      $headers .= 'X-Priority: 1'.NL;
      $headers .= 'X-MSMail-Priority: High'.NL;
      $headers .= 'X-Mailer: PHPOpenChat-Mail (http://phpopenchat.sourceforge.net/)'.NL;
      $headers .= 'Content-type: text/plain; charset='.$trans->out('CHARACTER_ENCODING').NL;
      
      $subject  = $trans->out('CONFIRMATION_MAIL_SUBJECT',true);
      $body     = $trans->out('CONFIRMATION_MAIL_BODY');
      $confim_code = md5(strval(rand(1,100000)));
      $confirm_sql = ",'$confim_code'";
      $uri      = (isset($_SERVER['REQUEST_URI']))? $_SERVER['REQUEST_URI']: $_SERVER['PHP_SELF'];
      preg_match('#^(.*)/register\.php.*$#', $uri, $parts);
      unset($uri);
      $script_path = $parts[1];
      $server   = (CONFIRMATION_HOST != '')? CONFIRMATION_HOST:$_SERVER['SERVER_NAME'];
      $url      = 'http://'.$server.$script_path;
      unset($server);
      unset($script_path);
      
      if(!$this->skip_email){
	      if( !SEND_MAIL_TO_FREEMAIL_ACCOUNTS
	      && !$this->_send_confirmation_mail($this->email, $subject, $body."\n\n".$url."/confirm.php?code=$confim_code" ))
	        $mail = false;
	
	      if( SEND_MAIL_TO_FREEMAIL_ACCOUNTS
	      && !mail($this->email, $subject, $body."\n\n".$url."/confirm.php?code=$confim_code", $headers))
	        $mail = false;
      }
    }

    if( $mail )
    {
      $sql1  = 'INSERT INTO '.DATABASE_TABLE_PREFIX.'user_account (USER,PASSWORD,CONFIRM_CODE)';
      $sql1 .= "VALUES ('".$this->nick."','".$this->password."'$confirm_sql)";
      
      $sql2  = 'INSERT INTO '.DATABASE_TABLE_PREFIX.'user_data (NICK,USER,NAME,EMAIL,PICTURE_URL,REGTIME)';
      $this->connect();
      $sql2 .= "VALUES ('".$this->nick."','".$this->nick."','".$this->name."','".$this->email."','".$this->pictureURL."',".$this->db->DBTimeStamp(time()).")";
  
      //Insert the records into the database
      if( !$this->db->Execute( $sql1 ) )
        $_SESSION['logger']->error('POC: Can\'t write to DB. SQL: "'.$sql1.'"', __FILE__, __LINE__ );
      if( !$this->db->Execute( $sql2 ) )
        $_SESSION['logger']->error('POC: Can\'t write to DB. SQL: "'.$sql2.'"', __FILE__, __LINE__ );
        
      $this->disconnect();
      
      return true;
    }
    else 
      return false;
  }
  
  function send_passwd()
  {
    $headers  = 'From: '.ADMIN_MAIL_NAME.NL;
    $headers .= 'X-Mailer: PHPOpenChat-Mail (http://phpopenchat.sourceforge.net/)'.NL;
    $headers .= 'Content-type: text/plain; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING');
    
    if( MD5_PASSWORDS ) {
      /*calculate a new password*/
      $passwd = substr( md5(rand(100000,999999)), 0, PASSWORD_MIN_LENGTH);
      $this->set_password_new( md5($passwd) );
      $this->update( true );//update password only
    } else {
      $passwd = $this->password;
    }
    //echo '[DEBUG] passwd: ' . $passwd;
    return mail($this->email,$_SESSION['translator']->out('FORGOT_PASSWD_MAIL_SUBJECT'),$_SESSION['translator']->out('FORGOT_PASSWD_MAIL_BODY').NL.NL.$_SESSION['translator']->out('YOUR_PASSWORD_IS').$passwd.NL.NL.$_SESSION['translator']->out('FORGOT_PASSWD_MAIL_HINT'),$headers);
  }

  /**
  * Sends a mail to the new chatter
  *
  * @access private
  * @return boolean
  * @see register()
  */
  function _send_confirmation_mail($to, $subject, $message, $from = ADMIN_MAIL_ADDRESS)
  {
    $headers  = 'From: '.ADMIN_MAIL_NAME.NL;
    $headers .= 'X-Mailer: PHPOpenChat-Mail (http://phpopenchat.sourceforge.net/)'.NL;
    $headers .= 'Content-type: text/plain; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING');
    list($me,$mydomain) = split("@",$from);
    
    // Now look up the mail exchangers for the recipient
    list($user,$domain) = split("@",$to,2);
    if( !getmxrr($domain,$mx,$weight) ) return false;
    
    // Try them in order of lowest weight first
    array_multisort($mx,$weight);
    $success=0;
    
    foreach($mx as $host) {
      // Open an SMTP connection
      $connection = fsockopen ($host, 25, $errno, $errstr, 1);
      //try twice if necessary
      if (!$connection)
        $connection = fsockopen ($host, 25, $errno, $errstr, 1);
      if (!$connection)
        continue;
        
      $res=fgets($connection,256);
      if(substr($res,0,3) != "220") break;
      
      // Introduce ourselves
      fputs($connection, "HELO $mydomain\n");
      $res=fgets($connection,256);
      if(substr($res,0,3) != "250") break;
      
      // Envelope from
      fputs($connection, "MAIL FROM: $from\n");
      $res=fgets($connection,256);
      if(substr($res,0,3) != "250") break;
      
      // Envelope to
      fputs($connection, "RCPT TO: $to\n");
      $res=fgets($connection,256);
      if(substr($res,0,3) != "250") break;
      
      // The message
      fputs($connection, "DATA\n");
      $res=fgets($connection,256);
      if(substr($res,0,3) != "354") break;
      
      // Send To:, From:, Subject:, other headers, blank line, message, and finish
      // with a period on its own line.
      fputs($connection, "To: $to\nFrom: $from\nSubject: $subject\n$headers\n\n$message\n.\n");
      $res=fgets($connection,256);
      if(substr($res,0,3) != "250") break;
      
      // Say bye bye
      fputs($connection,"QUIT\n");
      $res=fgets($connection,256);
      if(substr($res,0,3) != "221") break;
      
      // It worked! So break out of the loop which tries all the mail exchangers.
      $success=1;
      break;
    }
    // Debug for if we fall over - uncomment as desired
    //print $success?"Mail sent":"Failure: $res\n";
    if($connection) {
      if($success==0) fputs($connection, "QUIT\n");
      fclose ($connection);
    }
    
    return ( $success == 1 );
  }
  
  /**
  * Updates chatter's profile data
  *
  * @access public
  * @param  boolean 
  * @return boolean
  */
  function update( $pwd_only = false )
  {
    $this->connect();
    if( !$pwd_only ) {
      $record1 = array();
      $record1[ 'NAME' ]          = $this->name;
      $record1[ 'BIRTHDAY' ]      = $this->birthday;
      $record1[ 'GENDER' ]        = $this->gender;
      $record1[ 'EMAIL' ]         = $this->email;
      $record1[ 'HIDE_EMAIL' ]    = ($this->hide_email==true)? '1':'0';
      $record1[ 'PICTURE_URL' ]   = $this->pictureURL;
      $record1[ 'HOMEPAGE_URL' ]  = $this->homePageURL;
      $record1[ 'ICQ_NUMBER' ]    = $this->icqNumber;
      $record1[ 'AIM_NICKNAME' ]  = $this->aimNickname;
      $record1[ 'YIM_NICKNAME' ]  = $this->yimNickname;
      $record1[ 'INTERESTS' ]     = $this->interests;
      $record1[ 'MOTTO' ]         = $this->motto;

      $rs1 = $this->db->Execute( 'SELECT NAME,BIRTHDAY,GENDER,EMAIL,HIDE_EMAIL,PICTURE_URL,HOMEPAGE_URL,ICQ_NUMBER,AIM_NICKNAME,YIM_NICKNAME,INTERESTS,MOTTO FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER="'.$this->user.'"' );
      $update_sql1 = $this->db->GetUpdateSQL( $rs1, $record1 );
      unset($record1);
      unset($rs1);
    }
    $record2 = array();
    
    $record2[ 'PASSWORD' ] = $this->password;
    $record2[ 'PASSWORD_NEW' ] = $this->password_new;

    $rs2 = $this->db->Execute( 'SELECT PASSWORD,PASSWORD_NEW FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER="'.$this->user.'"' );
    $update_sql2 = $this->db->GetUpdateSQL( $rs2, $record2 );
    unset($record2);
    unset($rs2);

    //Insert the records into the database
    if( !$pwd_only && !$this->db->Execute( $update_sql1 ) ) {
      if(isset($_SESSION['logger']))
        $_SESSION['logger']->error('Can not update DB. SQL: "'.$update_sql1.'"', __FILE__, __LINE__ );
    }
    if( !$this->db->Execute( $update_sql2 ) ) {
      if(isset($_SESSION['logger']))
        $_SESSION['logger']->error('Can not update DB. SQL: "'.$update_sql2.'"', __FILE__, __LINE__ );
    }
    unset($update_sql1);
    unset($update_sql2);

    $this->disconnect();

    return true;
  }

  /**
  * Returns the nickname of chatter
  *
  * class Recipients extents class chatter. In case of recipient is 'EVERY_BODY'
  * we have to translate 'EVERY_BODY' to the respective language of chatter
  *
  * @access public
  */
  function get_nick( $parse = false )
  {
      if( !$parse && preg_match('/^#.*$/',$this->nick)){
        if(!isset($_SESSION['translator'])){
          $trans = &new POC_Translator();
        }else{
          $trans = &$_SESSION['translator'];
        }
        //in case of the line is addressed to everybody, we have to translate 'everybody'
        $nick = preg_replace( "/\#{3}([^#]*)\#{3}/e", "htmlentities(\$trans->out('\\1'))", $this->nick );
        return $nick;
      }
      else
        return $this->nick;
  }
  
  /**
  * Authentication of given nickname
  * 
  * @access public
  * @param string
  * @param string
  * @return boolean
  */
  function is_authorized($user, $password)
  {
      switch ( strval(AUTHENTICATION_METHOD) ) {
          case 'poc':
            //get password stored in db from current nick
            $this->connect();
             $rs = $this->db->Execute( 'SELECT PASSWORD,PASSWORD_NEW,CONFIRM_CODE,DISABLED FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER=\''.$user.'\'');
             $dbpassword = $rs->fields[0];
             $dbpassword_new = $rs->fields[1];
             $confirm_code = $rs->fields[2];
             $disabled = $rs->fields[3];
             $rs->Close();
            $this->disconnect();
            if( SEND_CONFIRMATION_MAIL && !is_null($confirm_code) )
              return '';
            if( $disabled == 1 )
              return '';
            
            
            if((!MD5_PASSWORDS && $password == $dbpassword)
            ||(MD5_PASSWORDS && (md5($password) == $dbpassword))) {
              return $user;
            } elseif( MD5_PASSWORDS && (md5($password) == $dbpassword_new)) {
              $this->password = $dbpassword_new;
              $this->password_new = 'null';
              $this->set_user($user);
              $this->update( true );
              return $user;
            } else {
              $ip = (isset($_SERVER['HTTP_X_FORWARDED_FOR']))? $_SERVER['HTTP_X_FORWARDED_FOR']:$_SERVER['REMOTE_ADDR'];
              $_SESSION['logger']->warning('Login denied for user \''.$user.'\' trying from '.$ip);
              unset($ip);

              return '';
            }
            break;

          case 'ldap':
            $dn = 'uid='.$user.','.LDAP_DN;
        
            // Connect to ldap server
            if ( !$dsCon = @ldap_connect(strval(LDAP_SERVER)) )
              return '';

            // Attempt a bind, if it works, the password is acceptable
            if ( !$bind = @ldap_bind($dsCon, $dn, $password))
              return '';
              
            // The username/password worked.
            ldap_close($dsCon);

            return $user;
            break;
      }
  }
  
  /**
  * Adds the given chatter to ignore list
  * 
  * @access public
  * @param string
  */
  function ignore( $chatter )
  {
    $chatter_to_ignore = POC_Chat::mkinstance_chatter($chatter);
    if($chatter_to_ignore->is_operator()
	  || $chatter_to_ignore->is_moderator()) {
		  unset($chatter_to_ignore);
	    return null;
	  }
	  unset($chatter_to_ignore);
    if( !$this->is_ignored($chatter) )
      $this->ignored_sender[] = $chatter;
  }

  /**
  * Removes the given chatter from ignore list
  * 
  * @access public
  * @param string
  */
  function unignore( $chatter )
  {
    unset( $this->ignored_sender[ array_search ( $chatter, $this->ignored_sender ) ] );
  }

  /**
  * Finds given chatter in ignore list
  * 
  * @access public
  * @param string
  * @return boolean
  */
  function is_ignored( $sender )
  {
    return in_array( $sender, $this->ignored_sender );
  }
  
  /**
  * Provides the ignore list of chatter
  * 
  * @access public
  * @return array
  */
  function get_ignored_sender()
  {
    return $this->ignored_sender;
  }

  /**
  * Provides the array of invited chatters
  *
  * @access public
  * @param boolean
  * @return array
  */
  function get_db_invited($private = null)
  {
      $invited_chatters = array();
      $this->connect();
       $rs = $this->db->Execute( 'SELECT INVITED FROM '.DATABASE_TABLE_PREFIX.'channels WHERE NAME=\''.$this->nick.'\'');
       if( is_string($rs->fields[0]) )
         $invited_chatters = unserialize($rs->fields[0]);
       $rs->Close();
      $this->disconnect();
      unset($rs);
	
      //remove current chatter, if it's a public call
      if(is_null($private))
        unset( $invited_chatters[ array_search ( $this->nick, $invited_chatters ) ] );
      
      if( is_array($invited_chatters) )
        return $invited_chatters;
      else
        return array();
    
  }
  
  /**
  * Writes the array of invited chatters into the database
  *
  * @access private
  * @param array
  * @return void
  */
  function set_db_invited( $invited_chatters )
  {
      $record = array();
      $record[ 'INVITED' ] = serialize($invited_chatters);

      $this->connect();
      $rs = $this->db->Execute( 'SELECT INVITED FROM '.DATABASE_TABLE_PREFIX.'channels WHERE NAME = \''. $this->nick .'\'' );
      $update_sql = $this->db->GetUpdateSQL( $rs, $record );

      unset($record);
      unset($rs);

      //Insert the records into the database
      if( !$this->db->Execute( $update_sql ) )
        $_SESSION['logger']->error('Can not update DB. SQL: "'.$update_sql.'"', __FILE__, __LINE__ );
      unset($update_sql);

      $this->disconnect();
    
  }
  
  /**
  * Writes the chatter object into the database
  *
  * @access public
  * @return void
  */
  function mkinstance_persist()
  {
      $this->set_db_instance_lifetime();
      $record = array();
      $record[ 'TMP_INSTANCE' ] = serialize($this);

      $this->connect();
      $rs = $this->db->Execute( 'SELECT TMP_INSTANCE FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER = \''. $this->user .'\'' );
      $update_sql = $this->db->GetUpdateSQL( $rs, $record );

      unset($record);
      unset($rs);

      //Insert the records into the database
      if( !$this->db->Execute( $update_sql ) )
        $_SESSION['logger']->error('Can not update DB. SQL: "'.$update_sql.'"', __FILE__, __LINE__ );
      unset($update_sql);

      $this->disconnect();
    
  }
  
  /**
  * Cleans the chatter instance in database
  *
  * @access public
  * @return void
  */
  function mkinstance_clean()
  {
      $record = array();
      $record[ 'TMP_INSTANCE' ] = 'null';

      $this->connect();
      $rs = $this->db->Execute( 'SELECT TMP_INSTANCE FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER = \''. $this->user .'\'' );
      $update_sql = $this->db->GetUpdateSQL( $rs, $record );

      unset($record);
      unset($rs);

      //Insert the records into the database
      if( !$this->db->Execute( $update_sql ) )
        $_SESSION['logger']->error('Can not update DB. SQL: "'.$update_sql.'"', __FILE__, __LINE__ );
      unset($update_sql);

      $this->disconnect();
  }
  
  function set_db_instance_lifetime()
  {
    $this->db_instance_lifetime = time();
  }
  function db_instance_is_outdated()
  {
    return ((( time() - $this->db_instance_lifetime ) > 60) || $this->db_instance_lifetime == 0);
  }
  
  /**
  * Invites a chatter
  * 
  * @access public
  * @param string
  * @return boolean
  */
  function invite( $chatter )
  {
      $invited_chatters = array();
      $invited_chatters = $this->get_db_invited(true);
      if( !$this->is_invited($chatter, $invited_chatters) ){
        $invited_chatters[] = $chatter;
        $this->set_db_invited($invited_chatters);
        return true;
      }
      unset($invited_chatters);
      return false;
  }
  
  /**
  * Disinvites a chatter
  * 
  * @access public
  * @param string
  * @return void
  */
  function disinvite( $chatter )
  {
      $invited_chatters = array();
      $invited_chatters = $this->get_db_invited(true);
      if( $this->is_invited($chatter, $invited_chatters) )
      {
        unset( $invited_chatters[ array_search ( $chatter, $invited_chatters ) ] );          
        $this->set_db_invited($invited_chatters);
      }
  }
  
  /**
  * Searches invited chatters for chatter and returns true if it is found in the array, false otherwise. 
  *
  * @access public
  * @param string
  * @param array
  * @return boolean
  */
  function is_invited( $chatter, &$invited_chatters )
  {
      return in_array( $chatter, $invited_chatters );
  }

  /**
  * Adds a chatter to the friends list
  * 
  * @access public
  * @param string
  * @return boolean
  */
  function add_friend( $chatter )
  {
    if( !empty($chatter) && !$this->is_friend($chatter) && $chatter != $this->nick){
      $this->friends[] = $chatter;
      $this->set_db_friends($this->friends);
      return true;
    }
    return false;
  }
  
  /**
  * Deletes a chatter from the friends list
  * 
  * @access public
  * @param string
  * @return null
  */
  function del_friend( $chatter )
  {
    unset( $this->friends[ array_search ( $chatter, $this->friends ) ] );
    $this->set_db_friends($this->friends);
  }
  
  /**
  * Checks if given chatter it's a friend
  * 
  * @access public
  * @param string
  * @return boolean
  */
  function is_friend( $chatter )
  {
    if( empty($chatter) ) return false;
    return in_array( $chatter, $this->friends );
  }
  
  function get_friends()
  {
    return $this->friends;
  }
  
  /**
  * Returns all friends as an html-option list
  * 
  * @access public
  * @return string
  */
  function get_friends_as_option_list()
  {
    if( is_array($this->friends) )
    {
      $option_list = '';
      reset($this->friends);
      do{
        $option_list .= TAB.'<option value="'.current($this->friends).'">'.preg_replace( "/\#{3}([^#]*)\#{3}/e", "htmlentities(\$_SESSION['translator']->out('\\1'))", current($this->friends) ).'</option>'.NL;
      }while( next($this->friends) );
      return $option_list;
    }
    else
      return '';
  }
  
  /**
  * Gets the friends list from database
  * 
  * @access private
  * @return array
  */
  function get_db_friends()
  {
      $friends = array();
      $this->connect();
       $rs = $this->db->Execute( 'SELECT FRIENDS FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK=\''.$this->nick.'\'');
       $friends = @unserialize($rs->fields[0]);
       $rs->Close();
      $this->disconnect();
      unset($rs);

      if( is_array($friends) )
        return $friends;
      else
        return array();

  }
  
  /**
  * Sets friends list in database
  * 
  * @access private
  * @param string
  * @return null
  */
  function set_db_friends( $friends )
  {
      $record = array();
      $record[ 'FRIENDS' ] = serialize($friends);

      $this->connect();
      $rs = $this->db->Execute( 'SELECT * FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK = \''. $this->nick .'\'' );
      $update_sql = $this->db->GetUpdateSQL( $rs, $record );

      unset($record);
      unset($rs);

      //Insert the records into the database
      if( !$this->db->Execute( $update_sql ) )
        $_SESSION['logger']->error('Can not update DB. SQL: "'.$update_sql.'"', __FILE__, __LINE__ );
      unset($update_sql);

      $this->disconnect();
  }

  function get_days_registered()
  {
    $registrationTime = $this->get_regTime();
    if( preg_match('/[^0-9]*([0-9]+)-([0-9]+)-([0-9]+)[^0-9]*/', $registrationTime, $parts) )
    {
      $nowdate = mktime(0,0,0,date('m'),date('d'),date('Y'));
      $regdate = mktime(0,0,0,$parts[2],$parts[3],$parts[1]);
      // calculate in days: (60*60*24) in years: (60*60*24*365)
      $days_registered = intval(($nowdate-$regdate)/(60*60*24));
      
      return $days_registered;
    }
    return false;
  }
  
  /**
  * Sets the grade of chatter if nesessary
  * 
  * @access public
  * @return boolean
  */
  function set_grade( $grades )
  {
    $ml_lines  = $grades['GRADE_MEMBER'][0];//ml = member_limit
    $ml_logins = $grades['GRADE_MEMBER'][1];//ml = member_limit
    $ml_online = $grades['GRADE_MEMBER'][2];//ml = member_limit
    $rl_lines  = $grades['GRADE_REGULAR'][0];//rl = regular_limit
    $rl_logins = $grades['GRADE_REGULAR'][1];//rl = regular_limit
    $rl_online = $grades['GRADE_REGULAR'][2];//rl = regular_limit
    $el_lines  = $grades['GRADE_ELITE'][0];//el = elite_limit
    $el_logins = $grades['GRADE_ELITE'][1];//el = elite_limit
    $el_online = $grades['GRADE_ELITE'][2];//el = elite_limit
    //$registrationTime = $this->get_regTime();
    $line_count       = $this->get_hit_count('line');
    $login_count      = $this->get_hit_count('login');
    $online_time      = $this->get_online_time();
    $current_grade    = $this->get_grade();

    //days since registration
    if( $days_registered = $this->get_days_registered() )
    {
      $this->days_registered = $days_registered;
      if( $days_registered <= 0 ) return null;
      $this->lines_per_day  = round(($line_count / $days_registered),1);
      $this->logins_per_day = round(($login_count / $days_registered),1);
      $this->update_stats();
    }
    $grade = '';
    if( $current_grade  != 'GRADE_REGULAR'
     && $current_grade  != 'GRADE_ELITE'
     && $this->lines_per_day  >= $ml_lines 
     && $this->logins_per_day >= $ml_logins
     && $online_time    >= ($ml_online * 60 * 60)
      )
      $grade = 'GRADE_MEMBER';
    if ( $current_grade  != 'GRADE_ELITE'
      && $this->lines_per_day  >= $rl_lines 
      && $this->logins_per_day >= $rl_logins
      && $online_time    >= ($rl_online * 60 * 60)
      ) 
      $grade = 'GRADE_REGULAR';
    if ( $this->lines_per_day  >= $el_lines 
      && $this->logins_per_day >= $el_logins
      && $online_time    >= ($el_online * 60 * 60)
      )
      $grade = 'GRADE_ELITE';
      
    if( $grade == '' ) return null;
    
    $record = array();
    $record[ 'GRADE' ] = $grade;

    $this->connect();
    $rs = $this->db->Execute( 'SELECT GRADE FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER = \''. $this->user .'\'' );
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );

    unset($record);
    unset($rs);

    //Insert the records into the database
    if( !$this->db->Execute( $update_sql ) )
      $_SESSION['logger']->error('Can not update DB. SQL: "'.$update_sql.'"', __FILE__, __LINE__ );
    unset($update_sql);

    $this->disconnect();
    
  }
  
  function update_stats()
  {
    $record = array();
    $record[ 'LINES_PER_DAY' ]   = (double) $this->lines_per_day;
    $record[ 'LOGINS_PER_DAY' ]  = (double) $this->logins_per_day;
    $record[ 'DAYS_REGISTERED' ] = (integer) $this->days_registered;

    $this->connect();
    $sql = 'SELECT LINES_PER_DAY, LOGINS_PER_DAY, DAYS_REGISTERED FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER = \''. $this->user .'\'';
    $rs = $this->db->Execute( $sql );
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );
    unset($record);
    $rs->Close();
    unset($rs);
    //Insert the records into the database
    if( !$this->db->Execute( $update_sql ) )
      $_SESSION['logger']->error('DB-Update failed. SQL: "'.$update_sql.'"', __FILE__, __LINE__);
    $this->disconnect();
    unset($update_sql);
  }
  
  function get_lines_per_day()
  {
    return $this->lines_per_day;
  }
  
  function get_logins_per_day()
  {
    return $this->logins_per_day;
  }
  
  function get_db_lines_per_day()
  {
    $this->connect();
     $rs = $this->db->Execute( 'SELECT LINES_PER_DAY FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK=\''.$this->nick.'\'');
     $data = $rs->fields[0];
     $rs->Close();
    $this->disconnect();
    unset($rs);
    
    return $data;
  }
  
  function get_db_logins_per_day()
  {
    $this->connect();
     $rs = $this->db->Execute( 'SELECT LOGINS_PER_DAY FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK=\''.$this->nick.'\'');
     $data = $rs->fields[0];
     $rs->Close();
    $this->disconnect();
    unset($rs);
    
    return $data;
  }
  
  /**
  * Sets status of chatter in database
  * 
  * @access puplic
  * @return boolean
  */
  function set_db_status( $status )
  {
      $record = array();
      $record[ 'STATUS' ] = $status;

      $this->connect();
      $rs = $this->db->Execute( 'SELECT STATUS FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER = \''. $this->user .'\'' );
      $update_sql = $this->db->GetUpdateSQL( $rs, $record );
      unset($record);
      unset($rs);

      //Insert the records into the database
      if( !$this->db->Execute( $update_sql ) )
        $_SESSION['logger']->error('DB-Update failed. SQL: "'.$update_sql.'"', __FILE__, __LINE__);

      $affected_rows = $this->db->Affected_Rows();
      unset($update_sql);
      $this->disconnect();
      
      return ( $affected_rows === 1 );
  }

  /**
  * Gets all the groups of chatter from DB
  *
  * @return array
  */
  function get_db_groups()
  {
    $this->connect();
    $rs = $this->db->Execute( 'SELECT * FROM '.DATABASE_TABLE_PREFIX.'user_groups' );
    $all_groups = $rs->GetAssoc();
    $rs->Close();
    $groups = array();
    foreach ($all_groups as $key => $value) {
      $members = array();
      if( !empty($value) ) {
        $members = unserialize($value);
      }else{
        continue;
      }
      if( in_array( $this->user, $members ) ) { /////////////////////////////////////////////
        $groups[] = $key;
      }
      unset($members);
    }

    $this->disconnect();

    return $groups;
  }
  
  /**
  * Gets all groups where current chatter is a member
  * 
  * @access public
  * @return boolean
  */
  function is_group_member( $group_name )
  {
    $this->connect();

    $rs = $this->db->Execute( 'SELECT MEMBER FROM '.DATABASE_TABLE_PREFIX.'user_groups WHERE NAME=\''.$group_name.'\'' );
    $group_members = array();
    if( !is_null($rs->fields[0]) )
      $group_members = unserialize( $rs->fields[0] );

    $rs->Close();
    $this->disconnect();

    return in_array( $this->user, $group_members );
  }

  /**
  * @desc Adds the chatter to given group
  *
  * @param string Name of the group
  * @return boolean
  */
  function add_to_group( $group_name )
  {
    $this->connect();
    if( !$this->is_group_member( $group_name) )
    {
      //Get group
      $rs = $this->db->Execute( 'SELECT MEMBER FROM '.DATABASE_TABLE_PREFIX.'user_groups WHERE NAME=\''.$group_name.'\'' );
      $group_members = array();
      if( !is_null($rs->fields[0]) )
        $group_members = unserialize( $rs->fields[0] );
      $rs->Close();
      //Add to group
      $group_members[] = $this->user;
      /*
	  if( isset($_SESSION['chatter'])
      && $_SESSION['chatter']->user == $this->user ) {
        $_SESSION['chatter']->groups[] = $group_name;
      }
	  */
	  $this->groups[] = $group_name;
    }
    else
    {
      $this->disconnect();
      return false;
    }
    
    //Write group
    $record = array();
    $record[ 'NAME' ] = $group_name;
    $record[ 'MEMBER' ] = serialize($group_members);
    $rs = $this->db->Execute( 'SELECT NAME,MEMBER FROM '.DATABASE_TABLE_PREFIX.'user_groups WHERE NAME=\''.$group_name.'\'' );
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );

    unset($record);
    unset($rs);

    //Insert the records into the database
    if( !$this->db->Execute( $update_sql ) )
      $_SESSION['logger']->error('DB-Update failed. SQL: "'.$update_sql.'"', __FILE__, __LINE__);

    $this->disconnect();
    unset($update_sql);
    return true;
  }

  /**
  * Deletes the chatter from given group
  *
  * @param string Name of the group
  * @return boolean
  */
  function del_from_group( $group_name )
  {
    if( $this->is_group_member( $group_name) ) {
      $this->connect();
      //Get group
      $rs = $this->db->Execute( 'SELECT MEMBER FROM '.DATABASE_TABLE_PREFIX.'user_groups WHERE NAME=\''.$group_name.'\'' );
      $group_members = array();
      if( !is_null($rs->fields[0]) )
        $group_members = unserialize( $rs->fields[0] );
      $rs->Close();

      //Delete
      unset( $group_members[ array_search ( $this->user, $group_members ) ] );
      if( isset($_SESSION['chatter'])
      && $_SESSION['chatter']->user == $this->user ) {
        unset( $_SESSION['chatter']->groups [ array_search ( $group_name, $_SESSION['chatter']->groups ) ] );
      }

      //Write group
      $record = array();
      $record[ 'NAME' ] = $group_name;
      $record[ 'MEMBER' ] = serialize($group_members);
      $rs = $this->db->Execute( 'SELECT NAME,MEMBER FROM '.DATABASE_TABLE_PREFIX.'user_groups WHERE NAME=\''.$group_name.'\'' );
      $update_sql = $this->db->GetUpdateSQL( $rs, $record );
  
      unset($record);
      unset($rs);
  
      //Insert the records into the database
      $this->db->Execute( $update_sql );
      $this->disconnect();
      unset($update_sql);
      return true;
    }
    return false;
  }

  /**
  * Sets or unsets the private flag of chatter
  * 
  * @access public
  * @param boolean
  */
  function set_private( $bool = true )
  {
      $this->private = $bool;
  }

  /**
  * Provides the private flag of chatter
  * 
  * @access public
  * @param boolean
  */
  function get_private()
  {
      return $this->private;
  }
  
  /**
  * Sets or unsets the bodies flag of chatter
  * 
  * @access public
  * @see get_bodies()
  * @param boolean
  */
  function set_bodies( $bool = true )
  {
      $this->bodies = $bool;
  }

  /**
  * @desc
  * Provides the bodies flag of chatter
  * 
  * If is set, the chatter gets only messages from or spoken to friends of him.
  *
  * @access public
  * @param boolean
  */
  function get_bodies()
  {
    return $this->bodies;
  }

  /**
  * Sets or unsets the system messages flag of chatter
  * 
  * Chatters can hide the messages sent by the system
  *
  * @access public
  * @param boolean
  */
  function set_sys_msg( $bool = true )
  {
      $this->sys_msg = $bool;
  }

  /**
  * Gets the system messages flag of chatter
  * 
  * Chatters can hide the messages sent by the system
  *
  * @access public
  * @return boolean
  */
  function get_sys_msg()
  {
      return $this->sys_msg;
  }

  /**
  * Sets the text color of chatter
  * 
  * @access public
  * @param string
  */
  function set_color( $color )
  {
      if( !preg_match('/[0-9a-fA-F]{6}/', $color ))
        return false;
        
      //set instance variable
      $this->color = $color;
        
      //write into database
      $record = array();
      $record[ 'COLOR' ] = $color;

      $this->connect();
      $rs = $this->db->Execute( 'SELECT * FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK = \''. $this->nick .'\'' );
      $update_sql = $this->db->GetUpdateSQL( $rs, $record );

      unset($record);
      unset($rs);

      //Insert the records into the database
      $this->db->Execute( $update_sql );
      unset($update_sql);

      $this->disconnect();
      return true;
  }

  /**
  * Sets the choosen theme of chatter
  * 
  * @access public
  * @param string
  */
  function set_theme( $theme )
  {
      //if( !file_exists() )
      //  return false;
        
      //set instance variable
      $this->theme = $theme;
      setcookie('poc_theme',$theme,COOKIE_EXPIRE,COOKIE_PATH,COOKIE_DOMAIN,COOKIE_SECURE);
	    
      //write into database
      $record = array();
      $record[ 'THEME' ] = $theme;

      $this->connect();
      $rs = $this->db->Execute( 'SELECT THEME FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER = \''. $this->user .'\'' );
      $update_sql = $this->db->GetUpdateSQL( $rs, $record );

      unset($record);
      unset($rs);

      //Insert the records into the database
      $this->db->Execute( $update_sql );
      unset($update_sql);

      $this->disconnect();
      return true;
  }

  /**
  * Provides the text color of chatter
  * 
  * @access public
  * @return string
  */
  function get_color()
  {
      return $this->color;
  }

  /**
  * Provides the registration time of chatter
  * 
  * @access public
  * @return string
  */
  function get_regTime()
  {
      return $this->regTime;
  }

  /**
  * Provides the last active time of chatter
  * 
  * @access public
  * @return string
  */
  function get_lastActive()
  {
      return $this->lastActive;
  }

  /**
  * Provides the last host of chatter
  * 
  * @access public
  * @return string
  */
  function get_last_Host()
  {
      return $this->lastHost;
  }

  /**
  * Provides the last IP of chatter
  * 
  * @access public
  * @return string
  */
  function get_last_IP()
  {
      return $this->lastIP;
  }

  /**
  * Provides the last user agent of chatter
  * 
  * @access public
  * @return string
  */
  function get_last_UserAgent()
  {
      return $this->lastUserAgent;
  }
  
  /**
  * Sets property to remember a referer
  * 
  * @param string
  */
  function set_last_Referer( $referer )
  {
    $this->lastReferer = $referer;
  }
  
  /**
  * Provides the last referer of chatter
  * 
  * @access public
  * @return string
  */
  function get_last_Referer()
  {
      return $this->lastReferer;
  }

  /**
  * Provides the last referer of chatter
  * 
  * @access public
  * @return string
  */
  function get_last_SessionId()
  {
      return $this->lastSessionId;
  }

  /**
  * Gets the text color of chatter from the database
  * 
  * @access private
  * @return string
  */
  function get_db_color()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT COLOR FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK=\''.$this->nick.'\'');
       $color = $rs->fields[0];
       $rs->Close();
      $this->disconnect();
      unset($rs);
      
      return $color;
  }

  /**
  * Sets the advice flag
  *
  * null  = no advice
  * alert = javascript alert
  * sound = play a soundfile
  * 
  * @access public
  * @return string
  */
  function set_advice( $advice )
  {
      if( !preg_match('/^(quiet|alert|sound)$/', $advice ))
        return false;
        
      $this->advice = $advice;
      
      $record = array();
      $record[ 'ADVICE' ] = $this->advice;
      $this->connect();
      $rs = $this->db->Execute( 'SELECT ADVICE FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK = \''. $this->nick .'\'' );
      $update_sql = $this->db->GetUpdateSQL( $rs, $record );

      unset($record);
      unset($rs);

      $this->db->Execute( $update_sql );
      unset($update_sql);

      $this->disconnect();
      
      return true;
  }

  /**
  * Provides the advice flag
  *
  * Is set, if user wants to be adviced if he gets new messages within the chat
  * 
  * @access public
  * @return string
  */
  function get_advice()
  {
      return $this->advice;
  }
  
  /**
  * Sets the scrollspeed of the output frame
  *
  * @access public
  * @param integer
  * @see configure.php
  */
  function set_scrollspeed($speed)
  {
    $this->scrollspeed = (integer) $speed;
    $record = array();
    $record[ 'SCROLLSPEED' ] = $this->scrollspeed;
    $this->connect();
    $rs = $this->db->Execute( 'SELECT SCROLLSPEED FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK = \''. $this->nick .'\'' );
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );

    unset($record);
    unset($rs);

    $this->db->Execute( $update_sql );
    unset($update_sql);

    $this->disconnect();
    
    return true;
    
  }
  
  /**
  * Provides the scrollspeed of the output frame
  *
  * @access public
  * @return integer
  */
  function get_scrollspeed()
  {
    return $this->scrollspeed;
  }
  
  /**
  * Gets the advice flag from the database
  *
  * @access private
  * @return string
  */
  function get_db_advice()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT ADVICE FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK=\''.$this->nick.'\'');
       $advice = $rs->fields[0];
       $rs->Close();
      $this->disconnect();
      unset($rs);
      
      return $advice;
  }
  
  function get_db_scrollspeed()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT SCROLLSPEED FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK=\''.$this->nick.'\'');
       $advice = $rs->fields[0];
       $rs->Close();
      $this->disconnect();
      unset($rs);
      
      return $advice;
  }
  
  /**
  * Gets the disabled flag from the database
  *
  * @access public
  * @return integer
  */
  function get_db_disabled()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT DISABLED FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER=\''.$this->user.'\'');
       $disabled = $rs->fields[0];
       $rs->Close();
      $this->disconnect();
      unset($rs);
      
      return $disabled;
  }
  
  /**
  * Gets the user name from database
  *
  * @access private
  * @return string
  */
  function get_db_user()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT USER FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK=\''.$this->nick.'\'');
       if( $rs->RowCount() > 0 )
         $value = $rs->fields[0];
       else 
         $value = '';
       $rs->Close();
      $this->disconnect();
      unset($rs);
      
      return $value;
  }
  
  /**
  * Gets the grade of user from DB
  *
  * @access private
  * @return string
  */
  function get_db_grade()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT GRADE FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER=\''.$this->user.'\'');
       $value = ( $rs->RowCount() > 0 )? $rs->fields[0]:'';
       $rs->Close();
      $this->disconnect();
      unset($rs);
      
      return $value;
  }
  
  /**
  * Gets the name from database
  *
  * @access private
  * @return string
  */
  function get_db_name()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT NAME FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK=\''.$this->nick.'\'');
       $value = $rs->fields[0];
       $rs->Close();
      $this->disconnect();
      unset($rs);
      
      return $value;
  }
  
  /**
  * Provides the password from poc-database account database
  *
  * @access private
  * @return string
  */
  function get_db_password()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT PASSWORD FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER=\''.$this->user.'\'');
       $value = $rs->fields[0];
       $rs->Close();
      $this->disconnect();
      unset($rs);
      
      return $value;
  }
  
  /**
  * Gets the e-mail from database
  *
  * @access private
  * @return string
  */
  function get_db_email()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT EMAIL FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK=\''.$this->nick.'\'');
       $value = $rs->fields[0];
       $rs->Close();
      $this->disconnect();
      unset($rs);
      
      return $value;
  }
    
  /**
  * Checks for the count of nicknames registered by given e-mail address
  *
  * @access public
  * @return integer
  */
  function get_db_email_count()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT count(*) AS count FROM '.DATABASE_TABLE_PREFIX.'user_data 
                                  WHERE EMAIL=\''.$this->email.'\'');
       $value = $rs->fields[0];
       $rs->Close();
      $this->disconnect();
      unset($rs);
      
      return $value;
  }
  
  /**
  * Gets the name from database
  *
  * @access private
  * @return string
  */
  function get_db_lastChannel()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT LAST_CHANNEL FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK=\''.$this->nick.'\'');
       $value = $rs->fields[0];
       $rs->Close();
      $this->disconnect();
      unset($rs);
      
      return $value;
  }
  
  /**
  * Gets the name from database
  *
  * @access private
  * @return string
  */
  function get_db_pictureURL()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT PICTURE_URL FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK=\''.$this->nick.'\'');
       $value = $rs->fields[0];
       $rs->Close();
      $this->disconnect();
      unset($rs);
      
      return $value;
  }
  
  function invite_private( $from, $to )
  {
    $record = array();
    $record[ 'PRIVATE_INVITED' ] = $from;
    $this->connect();
    $rs = $this->db->Execute( 'SELECT PRIVATE_INVITED FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK = \''. $to .'\'' );
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );
    unset($record);
    unset($rs);

    $this->db->Execute( $update_sql );
    unset($update_sql);

    $this->disconnect();
    
  }
  
  function check_private()
  {
    $value = '';
    $this->connect();
     $rs = $this->db->Execute( 'SELECT PRIVATE_INVITED FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK = \''. $_SESSION['chatter']->get_nick() .'\' AND PRIVATE_INVITED <> \'\' AND PRIVATE_INVITED IS NOT NULL' );
     if( $rs->RecordCount() > 0 )
     {
       $value = $rs->fields[0];
       //reset PRIVATE_INVITED
       $record = array();
       $record[ 'PRIVATE_INVITED' ] = 'null';
       $update_sql = $this->db->GetUpdateSQL( $rs, $record );
       unset($record);
       $this->db->Execute( $update_sql );
       unset($update_sql);
     }

     $rs->Close();
    $this->disconnect();
    unset($rs);
    
    return $value;
  }
  
  /**
  * Gets the registration time from database
  *
  * @access private
  * @return void
  */
  function get_db_times()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT REGTIME,LAST_ACTIVE_TIME FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK=\''.$this->nick.'\'');
       $this->regTime = $rs->fields[0];
       $this->lastActive = $rs->fields[1];
       $rs->Close();
      $this->disconnect();
      unset($rs);
  }
  
  /**
  * Gets some data about the current chatter from database
  *
  * @access private
  * @return void
  */
  function get_db_user_info()
  {
      $this->connect();
       $rs = $this->db->Execute( 'SELECT LAST_HOST,LAST_IP,LAST_USER_AGENT,LAST_REFERER,LAST_SESSIONID FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK=\''.$this->nick.'\'');
       $this->lastHost = $rs->fields[0];
       $this->lastIP = $rs->fields[1];
       $this->lastUserAgent = $rs->fields[2];
       $this->lastReferer = $rs->fields[3];
       $this->lastSessionId = $rs->fields[4];
       $rs->Close();
      $this->disconnect();
      unset($rs);
  }

  /**
   * checks last login time
   * 
   * @return boolean
   */
  function already_seen_today()
  {
    $parts  = split(' ', $this->get_lastActive());
    $date   = split('-', $parts[0]);

    if( !isset($parts[1]) ) return false;
    return ( date('m') == $date[1] && date('d') == $date[2] && date('Y') == $date[0] );
  }

  /**
  * Searches the regular's table
  *
  * @return integer
  */
  function get_regulars_table_rank()
  {
    $this->lines_per_day  = $this->get_db_lines_per_day();
    $this->logins_per_day = $this->get_db_logins_per_day();
    $this->online_time    = $this->get_db_online_time();
    
    if(!$this->online_time) $this->online_time = 1;
    $sql = '
      SELECT ((lines_per_day + logins_per_day + online_time)/days_registered) FROM '.DATABASE_TABLE_PREFIX.'user_data 
       WHERE nick = \''.$this->nick.'\'
    ';
    //echo $sql;
    $this->connect();
    if(!($rs = $this->db->Execute( $sql ))) return false;
    $sum = $rs->fields[0];

    $sql = ( DATABASE_DRIVER == 'mysql' )?'
      SELECT nick FROM '.DATABASE_TABLE_PREFIX.'user_data 
       WHERE TRUNCATE(((lines_per_day + logins_per_day + online_time)/days_registered),3) >= TRUNCATE('.$sum.',3)
    ':'
      SELECT nick FROM '.DATABASE_TABLE_PREFIX.'user_data 
       WHERE ((lines_per_day + logins_per_day + online_time)/days_registered) >= '.$sum.'
    ';
    $rs = $this->db->Execute( $sql );
    if( !is_object($rs) ) return false;
    $rank = $rs->RecordCount();
    $rs->Close();
    $this->disconnect();
    unset($rs);
    unset($sql);
    unset($sum);

    return $rank;
  }

  /**
  * Adds misc. data to the profile
  *
  * @param array
  * @return boolean
  */
  function insert_profile_misc( $data, $overwrite = false )
  {
    if( ! is_array($data) ) return false;

    $this->connect();
    $rs = $this->db->Execute( 'SELECT MISC FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER=\''.$this->user.'\'' );
    $misc = (is_null($rs->fields[0]))? array():unserialize($rs->fields[0]);

	/* check if posted data exist */
    foreach($misc as $value){
      if( $value == $data ) {
	    /* the given profile data exists already -> return */
		$this->disconnect();
		return false;
	  }
    }
    $misc[] = $data;

    $record = array();
    $record[ 'MISC' ] = ($overwrite)? serialize($data):serialize($misc);
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );
    unset($record);
    $this->db->Execute( $update_sql );
    unset($update_sql);
    
    $this->disconnect();
	
	return true;
  }
  
  /**
  * Provides miscellaneous profile data
  * 
  * @return array
  */
  function get_profile_misc()
  {
    $this->connect();
    $rs = $this->db->Execute( 'SELECT MISC FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER=\''.$this->user.'\'' );
    $misc = @unserialize($rs->fields[0]);
    if( !is_array($misc) )
    {
      unset($misc);
      $rs->Close();
      unset($rs);
      $this->disconnect();
      return array();
    }
    
    $rs->Close();
    unset($rs);
    $this->disconnect();
    
    return $misc;
  }
  
  
  /**
  * Test class Chatter
  * 
  * call like this: POC_Chatter::test();
  */
  function test()
  {
    // create a new chatter
    $nl="<br>\n";
    $chatter = new POC_Chatter("Chatter a_2");
    // if nick name is wrong it will be NULLed, so check!
    if (is_null($chatter->get_nick()))
      die ("Nick name not allowed$nl");
      
    $nick = $chatter->get_nick();
    print "Created chatter with nick name: $nick$nl";
  }
}
?>
