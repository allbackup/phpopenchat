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

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Language.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel.inc');
require_once(POC_INCLUDE_PATH.'/class.Line.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel_Buffer_'.CHANNEL_BUFFER_TYPE.'.inc');
require_once(POC_INCLUDE_PATH.'/class.Logger.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

/**
* Chat describes the whole chat
*
* @author  Michael Oertel <michael@ortelius.de>
* @access  public
* @version $Id: class.Chat.inc,v 1.70.2.40 2004/08/26 13:53:03 letreo Exp $
*/
class POC_Chat {
  
  /**
  * @var    string
  * @access public
  * @see    Chat()
  */
  var $name = '';
  
  /**
  * @var    integer
  * @see    connect()
  * @see    disconnect()
  */
  var $connection_count = 0;
  
  /**
  * Interface language of chat
  * @var    string
  */
  var $language = '';
  
  /**
  * search string for nicknames
  * @var    string
  */
  var $restrict = '';
  
  /**
  * referer
  * @var    string
  */
  var $referer = '';
  
  /**
  * show profile flag
  * @var    boolean
  */
  var $show_profile = true;
  
  /**
  * nicknames which will never die
  * @var    array
  */
  var $deathless_chatters = array();
  
  /**
  * all supported languages
  * @var    array
  */
  var $supported_languages = array();
  
  /**
  * Constructor.
  *
  * create a new chat object
  *
  * @param  string $channel
  * @access public
  */
  function POC_Chat( $name = CHAT_NAME, $supported_languages = array() )
  {
    $lang  = &new POC_Language();
    //negotiate languages between HTTP_ACCEPT_LANGUAGE and $supported_languages
    //$possible_languages contains the result of negotiation
    if( !$lang->get_list($supported_languages,$possible_languages) )
    {
      //no supported language in HTTP_ACCEPT_LANGUAGE found, so we take
      //the default language, the first entry in array $supported_languages,
      //defined in config.inc
      reset($supported_languages);
      $possible_languages = array();
      $possible_languages[current($supported_languages)] = '';
    }
    reset($possible_languages);
    $this->language = key($possible_languages);// $possible_languages are sorted by Q-factor and so we take the first one
    $this->name = $name;
    $this->supported_languages = $supported_languages;
  }
  
  /**
  * Provides the name of the chat
  *
  * @access public
  * @return string
  */
  function get_name()
  {
    return $this->name;
  }
  
  /**
  * Gets language of the chat
  *
  * @access public
  * @return string interface language of chat
  */
  function get_language()
  {
    return $this->language;
  }
  
  /**
  * Provides the default language of the chat
  *
  * @access public
  * @return string
  */
  function get_default_language()
  {
    return $this->supported_languages[0];
  }
  
  function _check_flag( $lang )
  {
    $flag_dir  = '/images/flags';
    $flag_path = $flag_dir.'/'.strtolower($lang).'.gif';    
    if( file_exists($_SESSION['template']->get_tmpl_sys_path().$flag_path) )
      return '<img src="'.$_SESSION['template']->get_tmpl_web_path().$flag_path.'" align="middle" alt="'.$_SESSION['translator']->out('CHOOSE_LANGUAGE').'" width="24" hight="16" border="0" />';
    
    return $lang;
  }
  
  function get_lang_switch()
  {
    if( isset($_GET['language']) && in_array($_GET['language'], $this->supported_languages) )
    {
      $_SESSION['translator']->set_language($_GET['language']);
      $this->set_language($_GET['language']);
    }
    $content = '';
    reset($this->supported_languages);
    do
    {
      $cur_lang = current($this->supported_languages);
      if( $cur_lang == $this->get_language() )
        {/*$lang_switch .= '<strong>'.check_flag( $cur_lang ).'</strong> | ';*/}
      else
        $content .= '<a class="imageLink" href="'.$_SERVER['PHP_SELF'].'?language='.$cur_lang.'&amp;'.session_name().'='.session_id().'">'.$this->_check_flag( $cur_lang ).'</a> | ';

    }while(next($this->supported_languages));
    
    return substr( $content, 0, -2 );
  }
  
  /**
  * Sets primary language prefix of the chat
  *
  * @access public
  * @param string
  */
  function set_language( $primary_lang_prefix )
  {
    $this->language = $primary_lang_prefix;
  }
  
  /**
  * Gets referer
  *
  * @access public
  * @return string
  */
  function get_referer()
  {
    return $this->referer;
  }
  
  /**
  * Sets referer
  *
  * @access public
  * @param string
  */
  function set_referer( $referer )
  {
    $this->referer = $referer;
  }
  
  /**
  * Sets the show profile flag
  *
  * @access public
  * @param boolean
  */
  function set_show_profile( $bool = true )
  {
    $this->show_profile = $bool;
  }
  
  /**
  * Provides the show profile flag
  *
  * @access public
  * @return boolean
  */
  function get_show_profile()
  {
    return $this->show_profile;
  }
  
  /**
  * Sets dethless chatters
  *
  * @access public
  * @param array
  */
  function set_deathless_chatters( $deathless_chatters )
  {
    $this->deathless_chatters = $deathless_chatters;
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
      return true;

    //create a database object
    $this->db = &NewADOConnection( DATABASE_DRIVER );
    if( USE_PCONNECT )
      $status1 = $this->db->PConnect( DATABASE_HOST, DATABASE_USER, DATABASE_PASSWORD, DATABASE_TABLESPACE );
    else
      $status1 = $this->db->Connect( DATABASE_HOST, DATABASE_USER, DATABASE_PASSWORD, DATABASE_TABLESPACE );
    //$this->db->debug=1;
    $status2 = $this->db->Execute( 'SELECT THEME FROM '.DATABASE_TABLE_PREFIX.'user_data' );

    return ( $status1 && $status2 );
  }

  /**
  * Creates a new instance of class channel within session
  *
  * @access public
  * @return boolean
  */
  function mkinstance_channel($post_channel)
  {
    $channel = &new POC_Channel($post_channel);
    $_SESSION['channel'] = $channel;

    //test if someone posts a wrong channel name
    return ( is_null($_SESSION['channel']->get_name()) == false );
  }

  /**
  * Creates a new instance of class chatter
  *
  * @access public
  * @param string; a nickname of a chatter
  * @return mixed
  */
  function mkinstance_chatter($post_nickname, $force = false)
  {
    $_chatter = &new POC_Chatter(STATUS_BOT_NAME);
    if( isset($_SESSION['translator']) ){
      $guest_nick_prefix = $_SESSION['translator']->out('GUEST_NICK_PREFIX');
      if( preg_match('/'.$guest_nick_prefix.'/i', $post_nickname) ){
        $post_nickname = preg_replace( '/'.$guest_nick_prefix.'/', '###GUEST_NICK_PREFIX###', $post_nickname );
      }
    }
    $_chatter->set_nick($post_nickname);
    
    if( $_chatter->get_regTime() != '' ) {
      $_chatter->init_additional_profile_data();
    }

    return ( $_chatter->get_regTime() != '' || $force)? $_chatter:null;
  }

  /**
  * Writes a message from the system-bot to given recipient
  *
  * @access public
  * @param string; message to write
  * @param object; recipient
  * @return boolean
  */
  function write_sys_msg( $message, $recipient, $whispered = false)
  {
    $_chatter = &new POC_Chatter(STATUS_BOT_NAME);
    $line = &new POC_Line( $_chatter, $message);
    unset($_chatter);
    if( is_object($recipient) )
      $line->set_recipient( $recipient );
    else return false;

    $line->filter_buffer_input();
    if($whispered)
    {
      $line->set_whispered();
      $line->set_info();
    }
    if( isset($_SESSION['channel_buffer']) && is_object($_SESSION['channel_buffer']) )
    {
      $_SESSION['channel_buffer']->connect();
      $_SESSION['channel_buffer']->put_line($line);
      $_SESSION['channel_buffer']->disconnect();
    }
    else return false;

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
  * Sets the confirm code to null
  *
  * @access public
  * @param string
  * @return boolean
  */
  function confirm( $code )
  {
    if( $this->connection_count == 0 )
      die('Not connected! Use connect() first!');
    
    $record = array();
    $record[ 'CONFIRM_CODE' ] = 'null';
    $rs = $this->db->Execute( 'SELECT CONFIRM_CODE FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE CONFIRM_CODE=\''.$code.'\'' );
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );
    unset($record);
    unset($rs);
    
    $this->db->Execute( $update_sql );
    unset($update_sql);
    
    return ( $this->db->Affected_Rows() === 1 );
  }
  
  function set_operator_passwd()
  {
    if( $this->connection_count == 0 )
      die('Not connected! Use connect() first!');
    
    $rs = $this->db->Execute( 'SELECT USER FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER=\'operator\' AND PASSWORD=\'\'' );
    
    if( $rs->RecordCount() == 0 ) {
      return '';
    } else {
      $operator_passwd = substr(md5( strval(rand(10000,99999)) ),0,PASSWORD_MIN_LENGTH);

      $record = array();
      $record[ 'PASSWORD' ] =(MD5_PASSWORDS)? md5($operator_passwd):$operator_passwd;
      $rs = $this->db->Execute( 'SELECT PASSWORD FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER=\'operator\'' );
      $update_sql = $this->db->GetUpdateSQL( $rs, $record );
      
      unset($record);
      unset($rs);
      return ( $this->db->Execute( $update_sql ) )? $operator_passwd:'';
    }
  }

  /**
  * Creates a private channel
  *
  * @access public
  * @param string
  * @return void
  */
  function create_private_channel( $channel_name )
  {
    if( $this->connection_count == 0 )
      die('Not connected! Use connect() first!');
    
    $record = array();
    $record[ 'NAME' ] = $channel_name;
    $record[ 'MAX_LINE_NUMBER' ] = CB_MAX_LINE;
    $record[ 'TYPE' ] = 2; //type=2 it's a private channel
    
    $rs = $this->db->Execute( 'SELECT NAME,MAX_LINE_NUMBER,TYPE FROM '.DATABASE_TABLE_PREFIX.'channels' );
    $insert_sql = $this->db->GetInsertSQL( $rs, $record );
    
    unset($record);
    unset($rs);
    
    //Insert the records into the database
    $this->db->Execute( $insert_sql );
    unset($insert_sql);
    
    //initialize the channel buffer
    $_SESSION['channel_buffer']->init($channel_name);
    
    //invite the owner of this private channel
    $_SESSION['chatter']->invite( $_SESSION['chatter']->get_nick() );
  }
  
  /**
  * Creates a channel (default, moderated)
  *
  * @access public
  * @param string
  * @param integer
  * @return void
  */
  function create_channel( $name, $type, $passwd, $message )
  {
    if( $this->connection_count == 0 )
      die('Not connected! Use connect() first!');
    
    if( $name == '' || $type > 1 ) return false;
    
    $record = array();
    $record[ 'NAME' ] = $name;
    $record[ 'MAX_LINE_NUMBER' ] = CB_MAX_LINE;
    $record[ 'TYPE' ] = $type; //type=0 it's a default channel
    $record[ 'PASSWORD' ] = $passwd;
    $record[ 'MESSAGE' ] = $message;
    //type=1 it's a moderated channel
    $rs = $this->db->Execute( 'SELECT NAME,MAX_LINE_NUMBER,TYPE,PASSWORD,MESSAGE FROM '.DATABASE_TABLE_PREFIX.'channels' );
    $insert_sql = $this->db->GetInsertSQL( $rs, $record );
    
    unset($record);
    unset($rs);
    
    //Insert the records into the database
    $this->db->Execute( $insert_sql );
    unset($insert_sql);
    
    //initialize the channel buffer
    $_SESSION['channel_buffer']->init($name);
  }
  
  /**
  * Creates a channel (default, moderated)
  *
  * @access public
  * @param string
  * @param integer
  * @return void
  */
  function update_channel( $name, $type, $passwd, $message )
  {
    if( $this->connection_count == 0 )
      die('Not connected! Use connect() first!');
    
    if( $type > 1 ) return false;
    
    $record = array();
    $record[ 'TYPE' ] = $type; //type=0 it's a default channel
    $record[ 'PASSWORD' ] = $passwd;
    $record[ 'MESSAGE' ] = $message;
    //type=1 it's a moderated channel
    $rs = $this->db->Execute( 'SELECT TYPE, PASSWORD, MESSAGE FROM '.DATABASE_TABLE_PREFIX.'channels WHERE NAME = \''.$name.'\'' );
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );
    
    unset($record);
    unset($rs);
    
    //Insert the records into the database
    $this->db->Execute( $update_sql );
    unset($update_sql);
    
    return true;
  }

  /**
  * Deletes a channel
  *
  * @access public
  * @param string
  * @return boolean
  */
  function delete_channel( $channel_name )
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    //remove channel
    $rs = $this->db->Execute( 'DELETE FROM '.DATABASE_TABLE_PREFIX.'channels WHERE NAME=\''.$channel_name.'\'' );
    $rows_effected = $this->db->Affected_Rows();
    
    //remove the dependent channel buffer if necessary
    if( CHANNEL_BUFFER_TYPE == 'DB' )
    {
      $rs = $this->db->Execute( 'DELETE FROM '.DATABASE_TABLE_PREFIX.'line_buffer WHERE NAME=\''.$channel_name.'\'' );
      $rows_effected += $this->db->Affected_Rows();
      
      unset($rs);
      return( $rows_effected == 2 );
    }
    
    unset($rs);
    return( $rows_effected == 1 );
  }
  
  /**
  * initialisation of channel_buffers
  *
  * @access public
  * @return void
  * @see create_channel()
  * @see create_private_channel()
  */
  function init_channel_buffers()
  {
    return null;
    
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    $channels = array();
    $channels = $this->get_channels();
    
    reset($channels);
    do{
      $_SESSION['channel_buffer']->init( current($channels) );
    }while( next($channels) );
  }
  
  function move_channel_to_top( $channel )
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    $channels = array();
    $channels = $this->get_channels();
    unset( $channels[array_search($channel,$channels)] );
    $channels=array_reverse ($channels);
    $channels[]=$channel;
    $channels=array_reverse($channels);
    
    foreach($channels as $key => $value)
    {
      $rs = $this->db->Execute( 'UPDATE '.DATABASE_TABLE_PREFIX.'channels SET ORDER_IDX = '.$key.' WHERE NAME=\''.$value.'\'' );
    }
  }
  
  /**
  * Gets all the channels as an option list specially for select boxes in the chat
  *
  * @param int $current_channel
  * @access public
  * @return string
  */
  function get_channels_option_list( $current_channel = '')
  {
    if( $this->connection_count == 0 )
      die('Not connected! Use connect() first!');

    //Get a list of all channels except for private channels
    //ordinary channel:  TYPE = NULL
    //moderated channel: TYPE = 1
    //private channel:   TYPE = 2
    $rs1 = $this->db->Execute( 'SELECT NAME,INVITED,TYPE, 0 AS COUNT FROM '.DATABASE_TABLE_PREFIX.'channels ORDER BY ORDER_IDX' );
    $rs2 = $this->db->Execute( 'SELECT c.NAME AS NAME,
                                       c.INVITED AS INVITED,
                                       c.TYPE AS TYPE,
                                       COUNT(c.NAME) AS COUNT
                                  FROM '.DATABASE_TABLE_PREFIX.'user_data d,
                                       '.DATABASE_TABLE_PREFIX.'channels c 
                                 WHERE ONLINE = \'1\' 
                                   AND LAST_CHANNEL = c.NAME 
                              GROUP BY c.NAME
                              ORDER BY ORDER_IDX'); 

    $channels = array_merge($rs1->GetAssoc(),$rs2->GetAssoc());
    $rs1->Close();
    $rs2->Close();
    unset($rs1);
    unset($rs2);
    
    
    $option_list = '';
    $option_list_of_public_channels = '';
    $option_list_of_moderated_channels = '';
    $option_list_of_private_channels = '';

    foreach ( $channels as $current )
    {
      $occupancy = ' ('.$current['COUNT'].'/'.MAX_CONCURRENT_CHATTER.')';
      $current_value = $current['NAME'];
      $disabled = '';
      if( $current['COUNT'] >= MAX_CONCURRENT_CHATTER )
      {
        $occupancy = ' ('.$_SESSION['translator']->out('FULL').')';
        if( isset($_SESSION['channel'])
        && $_SESSION['channel']->get_name() == $current['NAME'] )
        {}
        elseif(!isset($_SESSION['channel_buffer'])) continue;
        else
        {
          $current_value = '';
          $disabled = 'disabled="disabled"';
        }
      }
      
      if( $current['NAME'] == $current_channel )
        $selected = 'selected="selected"';
      else
        $selected = '';

      $chatters_invited_into = array();
      if( $current['TYPE'] == 2 && is_string($current['INVITED']) ) {
        $chatters_invited_into = unserialize($current['INVITED']);
        if( !is_array($chatters_invited_into) ) $chatters_invited_into = array();
      }
      //add private channels if invited and it's not a call from the login form
      //if( !is_null($chatters_invited_into) &&
      if( $current_channel != '' 
      && isset($_SESSION['chatter'])
      && is_object($_SESSION['chatter'])
      && in_array($_SESSION['chatter']->get_nick(),$chatters_invited_into) )
      {
        $option_list_of_private_channels .= TAB.'<option value="'.$current_value.'" '.$selected.' '.$disabled.'>';
        $option_list_of_private_channels .= preg_replace( "/\#{3}([^#]*)\#{3}/e", "\$_SESSION['translator']->out('\\1')", $current['NAME'] );
        $option_list_of_private_channels .= $occupancy.'</option>'.NL;
      }
      //if( is_null($chatters_invited_into) )
      if( count($chatters_invited_into) == 0 && $current['TYPE'] < 2 )
      {
        if( isset($_SESSION['chatter']) && $_SESSION['chatter']->is_banned( $current['NAME']) )
        {}
        elseif( $current['TYPE'] == 1 )
        $option_list_of_moderated_channels .= TAB.'<option value="'.$current_value.'" '.$selected.' '.$disabled.'>'.$current['NAME'].$occupancy.'</option>'.NL;
        else
        $option_list_of_public_channels .= TAB.'<option value="'.$current_value.'" '.$selected.' '.$disabled.'>'.$current['NAME'].$occupancy.'</option>'.NL;
      }
    }
        

    unset($selected);
    if( $option_list_of_public_channels != '' )
    {
      $option_list .= '<optgroup label="'.$_SESSION['translator']->out('PUBLIC_CHANNEL').'">'.NL;
      $option_list .= $option_list_of_public_channels;
      $option_list .= TAB.TAB.'</optgroup>'.NL;
    }
    if( $option_list_of_moderated_channels != '' )
    {
      $option_list .= '<optgroup label="'.$_SESSION['translator']->out('MODERATED_CHANNEL').'">'.NL;
      $option_list .= $option_list_of_moderated_channels;
      $option_list .= TAB.TAB.'</optgroup>'.NL;
    }
    if( $option_list_of_private_channels != '' )
    {
      $option_list .= '<optgroup label="'.$_SESSION['translator']->out('PRIVATE_CHANNEL').'">'.NL;
      $option_list .= $option_list_of_private_channels;
      $option_list .= TAB.TAB.'</optgroup>'.NL;
    }
    
    return $option_list;
  }
  
  /**
  * Gets all private channels as an option list specially for select boxes in the chat
  *
  * @param int $current_channel
  * @access public
  * @return string
  */
  function get_private_channels_option_list( $current_channel = '')
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    //Get a list of all channels except for private channels
    //ordinary channel:  TYPE = NULL
    //moderated channel: TYPE = 1
    //private channel:   TYPE = 2
    $rs = $this->db->Execute( 'SELECT NAME FROM '.DATABASE_TABLE_PREFIX.'channels WHERE TYPE = 2' );
    $option_list_of_channels = '';
    while( !$rs->EOF ) {
      if( $rs->fields[0] == $current_channel )
      $selected = 'selected="selected"';
      else
      $selected = '';
      
      $option_list_of_channels .= TAB.'<option value="'.$rs->fields[0].'" '.$selected.'>'.$rs->fields[0].'</option>'.NL;
      $rs->MoveNext();
    }
    $rs->Close();
    unset($selected);
    
    return $option_list_of_channels;
  }
  
  /**
  * Gets all the channels
  *
  * @access public
  * @return array
  */
  function get_channels()
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    //Get a list of all channels
    //ordinary channel:  TYPE = NULL
    //moderated channel: TYPE = 1
    //private channel:   TYPE = 2
    $rs = $this->db->Execute( 'SELECT NAME FROM '.DATABASE_TABLE_PREFIX.'channels WHERE TYPE < 2' );
    
    if ($rs->RecordCount() > 0)
    {  //return $rs->fields;
    $fields = array();
    while (!$rs->EOF) {
      $fields[] = $rs->fields[0];
      $rs->MoveNext();
    }
    return $fields;
    }
    return array();
  }
  
  /**
  * Checks if given channel name exists
  *
  * @access public
  * @param string
  * @return boolean
  */
  function channel_exists($channel)
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    $rs = $this->db->Execute( 'SELECT NAME FROM '.DATABASE_TABLE_PREFIX.'channels WHERE NAME = \''.$channel.'\'' );
    $exists = $rs->RecordCount();
    $rs->Close();
    
    return ($exists == 1);
  }
  
  /**
  * Gets all private channels
  *
  * @access public
  * @return array
  */
  function get_private_channels()
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    //Get a list of all channels
    $rs = $this->db->Execute( 'SELECT name FROM '.DATABASE_TABLE_PREFIX.'channels WHERE TYPE = 2' );
    
    if ($rs->RecordCount() > 0)
    return $rs->fields;
    
    return null;
  }
  
  /**
  * Checks if a given nickname is online
  *
  * @param string
  * @return boolean
  * @see POC_Chatter::is_online()
  */
  function is_online( $nick )
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    //Get a list of all channels
    $rs = $this->db->Execute( 'SELECT NICK FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE ONLINE = \'1\'' );
    
    return ($rs->RecordCount() > 0);
    
  }
  
  /**
  * Gets all chatters in given channel
  *
  * @access public
  * @param string name of channel
  * @return array
  */
  function get_channel_chatters( $channel )
  {
    if( $this->connection_count == 0 )
      die('Not connected! Use connect() first!');
    
    if( !is_object($this->db) ) {
      $_SESSION['logger']->error( 'POC_Chat::get_channel_chatters(): ADOdb instance expected', __FILE__, __LINE__ );
      return array();
    }
    //Get a list of all channels
    $rs = $this->db->Execute( 'SELECT NICK FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE ONLINE = \'1\' AND LAST_CHANNEL = \''.$channel.'\'' );
    
    if ($rs->RecordCount() > 0)
    {
      while( !$rs->EOF )
      {
        $chatters[] = $rs->fields[0];
        $rs->MoveNext();
      }
      return $chatters;
    }
    return array();
  }
  
  /**
  * Provides the count of chatters in given channel
  *
  * @access public
  * @param string name of channel
  * @return array
  */
  function get_chatter_count( $channel )
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    //Get a list of all channels
    $rs = $this->db->Execute( 'SELECT NICK FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE ONLINE = \'1\' AND LAST_CHANNEL = \''.$channel.'\'' );
    
    $count = $rs->RecordCount();
    $rs->close();
    unset($rs);
    return $count;
  }
  
  /**
  * Gets all chatters in given channel as an option list
  *
  * @access public
  * @param string name of channel
  * @return string
  */
  function get_channel_chatters_option_list( $channel )
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    if( !isset($_POST['recipient']) )
    $_POST['recipient'] = '';
    
    //Get a list of all channels
    $rs = $this->db->Execute( 'SELECT NICK FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE ONLINE = \'1\' AND LAST_CHANNEL = \''.$channel.'\'' );
    $option_list_of_chatters = '';
    $option_list_of_guests = '';
    $option_list = '';
    if( $rs->RecordCount() > 1 )
    {
      //$option_list_of_chatters = '<optgroup label="'.$_SESSION['translator']->out('ALL_CHATTERS').'">'.NL;
      $friends = array();
      $friends = $_SESSION['chatter']->get_friends();
      while( !$rs->EOF ) {
        if( in_array($rs->fields[0], $friends)
        || $rs->fields[0] == $_SESSION['chatter']->get_nick(true)) {
          $rs->MoveNext();
          continue;
        }
        if( isset($_POST['recipient']) && $rs->fields[0] == $_POST['recipient'] )
          $selected = ' selected="selected"';
        else
          $selected = '';
        
        if( !preg_match('/###GUEST_NICK_PREFIX###/',$rs->fields[0]) ) {
          $option_list_of_chatters .= TAB.TAB.'<option value="'.$rs->fields[0].'"'.$selected.'>';
          $option_list_of_chatters .= $rs->fields[0];
          $option_list_of_chatters .= '</option>'.NL;
        } else {
          $option_list_of_guests .= TAB.TAB.'<option value="'.$rs->fields[0].'"'.$selected.'>';
          $option_list_of_guests .= preg_replace( "/\#{3}([^#]*)\#{3}/e", "htmlentities(\$_SESSION['translator']->out('\\1'))", $rs->fields[0] );
          $option_list_of_guests .= '</option>'.NL;
        }
        $rs->MoveNext();
      }
      //$option_list_of_chatters .= TAB.TAB.'</optgroup>'.NL;
      $rs->Close();
      unset($friends);
      unset($rs);
      unset($selected);
    }
    if($option_list_of_chatters != '' )
    {
      $option_list .= '<optgroup label="'.$_SESSION['translator']->out('CHATTER').'">'.NL;
      $option_list .= $option_list_of_chatters;
      $option_list .= TAB.TAB.'</optgroup>'.NL;
    }
    if($option_list_of_guests != '' )
    {
      $option_list .= '<optgroup label="'.$_SESSION['translator']->out('ALL_GUESTS').'">'.NL;
      $option_list .= $option_list_of_guests;
      $option_list .= TAB.TAB.'</optgroup>'.NL;
    }
    return $option_list;
  }
  
  /**
  * Gets all friends in given channel as an option list
  *
  * @access public
  * @param string name of channel
  * @return string
  */
  function get_friends_option_list( $channel)
  {
    $friends  = array();
    $friends  = $_SESSION['chatter']->get_friends();
    $chatters = array();
    $chatters = $this->get_channel_chatters( $channel );
    $friends_online = array_intersect($friends,$chatters);
    $option_string = '';
    if( count($friends_online) ){      
      $option_string = '<optgroup label="'.$_SESSION['translator']->out('FRIENDS').'">'.NL;
      reset($friends_online);
      do{
        if( isset($_POST['recipient']) && current($friends_online) == $_POST['recipient'] ){
          $selected = ' selected="selected"';
        }else{
          $selected = '';
        }

        $option_string .= TAB.TAB.TAB.'<option value="'.current($friends_online).'"'.$selected.'>'.preg_replace( "/\#{3}([^#]*)\#{3}/e", "htmlentities(\$_SESSION['translator']->out('\\1'))", current($friends_online) ).'</option>'.NL;
      }while( next($friends_online) );
      $option_string .= TAB.TAB.'</optgroup>'.NL;
    }
    return $option_string;
  }
  
  /**
  * Gets all guests in given channel as an option list
  *
  * @access public
  * @return string
  */
  function get_guests_option_list()
  {
    if( $guests = $_SESSION['channel']->get_guests() )
    {
      $option_string = '<optgroup label="'.$_SESSION['translator']->out('GUESTS').'">'.NL;
      reset($guests);
      do{
        if( isset($_POST['recipient']) && current($guests) == $_POST['recipient'] )
        $selected = ' selected="selected"';
        else
        $selected = '';
        
        $option_string .= TAB.TAB.TAB.'<option value="'.current($guests).'"'.$selected.'>'.current($guests).'</option>'.NL;
      }while( next($guests) );
      $option_string .= TAB.TAB.'</optgroup>'.NL;
      return $option_string;
    }
    return '';
  }
  
  /**
  * Gets all chatters in given channel as an option list of unignored users of current chatter
  *
  * @access public
  * @param string nickname
  * @param string name of channel
  * @return array
  */
  function get_unignored_chatters_option_list( $channel, $nick_constraint = '' )
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    $sql = 'SELECT NICK FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE ONLINE = \'1\' AND LAST_CHANNEL = \''.$channel.'\' AND NICK <> \''.$_SESSION['chatter']->get_nick().'\'';
    if($nick_constraint != '' )
    $sql .= ' AND NICK LIKE \'%'.$nick_constraint.'%\'';
    
    $sql .= ' ORDER BY NICK';
    $rs = $this->db->Execute( $sql );
    $unignored_chatters_option_list = '';
    while( !$rs->EOF ) {
      if(  !$_SESSION['chatter']->is_ignored($rs->fields[0]) )
      $unignored_chatters_option_list .= TAB.'<option value="'.$rs->fields[0].'">'.preg_replace( "/\#{3}([^#]*)\#{3}/e", "htmlentities(\$_SESSION['translator']->out('\\1'))", $rs->fields[0] ).'</option>'.NL;
      
      $rs->MoveNext();
    }
    $rs->Close();
    
    return $unignored_chatters_option_list;
  }
  
  function set_nick_restrict( $restrict )
  {
    $this->restrict = $restrict;
  }
  
  /**
  * Provides an array of chatters
  *
  * @access public
  * @param array
  * @param boolean
  * @param string
  * @return array
  */
  function get_chatters_excepting( $chatters_to_skip, $as_option_list = null, $channel = null )
  {
    
    $all_chatters = array();
    $all_chatters = array_unique( $this->get_chatters($channel) );
    
    if(count($all_chatters) <= 0)
    return null;
    
    $chatters = array();
    $chatters_option_list = '';
    reset($all_chatters);
    do
    {
      if( in_array(current($all_chatters),$chatters_to_skip) )
      continue;
      
      if(is_null($as_option_list))
      $chatters[] = current($all_chatters);
      else
      $chatters_option_list .= TAB.'<option value="'.current($all_chatters).'">'.preg_replace( "/\#{3}([^#]*)\#{3}/e", "\$_SESSION['translator']->out('\\1')", current($all_chatters) ).'</option>'.NL;
      
    }while(next($all_chatters));
    
    if(is_null($as_option_list))
    return $chatters;
    else
    return $chatters_option_list;
  }
  
  function get_best_chatter($grade, $limit)
  {
    if( $this->connection_count == 0 )
      die('Not connected! Use connect() first!');
    
    //$now = $this->db->DBTimeStamp( time() );
    $sql = 'SELECT nick,lines_per_day,logins_per_day,online_time FROM '.DATABASE_TABLE_PREFIX.'user_data
                WHERE grade= \''.$grade.'\' AND online_time > 0
                ORDER BY online_time desc'; 
    $rs = $this->db->SelectLimit( $sql, $limit );
    $result = $rs->GetArray();
    $rs->Close();
    //unset($now);
    unset($sql);
    
    return $result;
  }

  /**
  * Provides all members of given group name
  *
  * @param string
  * @return array
  */
  function get_group_members( $group )
  {
    if(! isset($group) ) return array();
    if( $this->connection_count == 0 )
      die('Not connected! Use connect() first!');
    
    $sql    = 'SELECT member FROM '.DATABASE_TABLE_PREFIX.'user_groups WHERE name= \''.$group.'\''; 
    $rs     = $this->db->Execute( $sql );
    $member = array();
    if( $rs->RecordCount() > 0 ) {
      $member = unserialize( $rs->fields[0] );
    }else{
      $member = array();
    }
    $rs->Close();
    unset($rs);
    unset($sql);
    
    return $member;
  }

  /**
  * Provides a chatter instance if exists
  *
  * @param string
  * @return object
  */
  function get_chatter_instance( $nick )
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');

    //$now = $this->db->DBTimeStamp( time() );
    $sql = 'SELECT TMP_INSTANCE FROM '.DATABASE_TABLE_PREFIX.'user_data
                WHERE nick= \''.$nick.'\''; 
    $rs = $this->db->Execute( $sql );
    if ( $rs->RecordCount() <= 0 ) return null;
    $chatter = unserialize($rs->fields[0]);
    $rs->Close();
    //unset($now);
    unset($sql);

    return $chatter;
  }

  /**
  * Gets all chatters
  *
  * @access public
  * @return array
  */
  function get_chatters( $channel = null, $search_query = '' )
  {
    if( $this->connection_count == 0 )
      die('Not connected! Use connect() first!');
    
    $restrict = '';
    if( $this->restrict != '' )
      $restrict = ' AND NICK LIKE \''.$this->restrict.'%\'';
    
    if(is_null($channel))
      //return all chatter online exept guests
      $rs = $this->db->Execute( 'SELECT NICK FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER NOT LIKE \'%###%\' AND USER LIKE \''.$search_query.'%\' '.$restrict.' ORDER BY NICK' );
    else
    {
      if(!isset($_SESSION['chatter']) || ($search_query == '' && $channel =='%'))
        //in case of a call from index.php
        $rs = $this->db->Execute( 'SELECT NICK FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE ONLINE = \'1\'' );
      else
        //return all chatter in given channel
        $rs = $this->db->Execute( 'SELECT NICK FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE ONLINE = \'1\' AND LAST_CHANNEL = \''.$channel.'\' AND NICK <> \''.$_SESSION['chatter']->get_nick().'\''.$restrict );
    }
    
    $chatters = array();
    while (!$rs->EOF)
    {
      $chatters[] = $rs->fields[0];
      $rs->MoveNext();
    }
    
    return $chatters;
  }
  
  /**
  * Checks if an URL exists
  *
  * @access public
  * @param string
  * @return boolean
  */
  function check_URL($url, $checkIMG = true )
  {
    if( !isset($url) || $url == '' )
      return false;
    
    preg_match('#^[http://]*(.[^/:]*):?([0-9]*)(.*)$#i', $url, $parts);
    
    if( isset($parts[1]) )
      $hostname = $parts[1];
    else
      return false;
    
    if( !isset($parts[2]) || $parts[2] == '' )
      $port = 80;
    else
      $port = $parts[2];
    
    if( !isset($parts[3]) || $parts[3] == '' )
      $path = '/';
    else
      $path = $parts[3];
    
    if( $fp = @fsockopen($hostname, $port) ) {
      @fputs($fp, "HEAD $path HTTP/1.1\nUser-Agent: PHPOpenChat-Robot (http://phpopenchat.sourceforge.net/)\nHost: $hostname\n\n");
      $data = '';
      for ($i=0; $i<10; $i++) {
        $data .= @fgets($fp,128);
      }

      @fclose($fp);
      return ( $checkIMG )? preg_match('/Content-[t|T]ype: image\//', $data):
                            preg_match('#HTTP/1\.. 2.. OK#', $data);
    } else {
      return false;
    }
  }

  /**
  * Checks the posted string and replaces the forbidden words with 'Ooops'
  *
  * @param string $string
  * @param array  $forbidden_strings
  * @return string
  */
  function check_chat( $string, $forbidden_strings )
  {
    if(! is_array($forbidden_strings) ) die('forbidden_strings: Array expected!');
    if( count($forbidden_strings) == 0 ) return $string;
    
    do{
	  $search_string = chunk_split(current($forbidden_strings),1,'[\.\-\'\(\=\?\/)_,;:!"`§$%&]*');
      $string = preg_replace('/'.$search_string.'/','<acronym title="'.$_SESSION['translator']->out('FORBIDDEN_WORD').'">...Ooops...</acronym>',$string);
    }while( next($forbidden_strings) );
    unset($search_string);
    return $string;
  }

  /**
  * Returns a parsed template
  *
  * @param string
  * @return string
  */
  function get_template( $template, $inline = null )
  {
    ob_start();
    readfile($_SESSION['template']->get_template($template,true),1);
    $lines  =( !isset($inline) )? addslashes('<?xml version="1.0" encoding="'.$_SESSION['translator']->out('CHARACTER_ENCODING').'"?>'):'';

    $tmp = addslashes(preg_replace('/\r\n|\r|\n/', '', ob_get_contents()));
    $tmp = preg_replace('#</#', '<\\/', $tmp);
    $lines .= $tmp;
    $lines  = $_SESSION['translator']->filter_out($lines);
    $lines  = $_SESSION['template']->filter_placeholder($lines);
    ob_end_clean();
    
    return $lines;
  }
  
  /**
  * Logout a chatter
  */
  function logout()
  {
  	if( AUTOLOGIN_DIRECTLY ){
      $_SESSION['autologin_directly'] = false;
    }

    //chatter wants to go to bed
    //we have to say goodbye in the current channel first»
    if( isset($_SESSION['channel_buffer']) ) {
      $said = $_SESSION['chatter']->get_nick(true).' ###LEAVES_THE_CHAT###';
      $bot = &new POC_Chatter(strval(STATUS_BOT_NAME));
      $line = &new POC_Line($bot, $said);
      $line->set_leave($_SESSION['chatter']->get_nick(true));
      $_SESSION['channel_buffer']->connect();
      $_SESSION['channel_buffer']->put_line($line);
      $_SESSION['channel_buffer']->disconnect();
      unset($line);
      unset($bot);
      unset($said);
    }
    //set chatter status to offline
    if( isset($_SESSION['chatter']) && isset($_SESSION['channel_buffer']) )
      $_SESSION['chatter']->go_offline( $_SESSION['channel_buffer']->get_name() );
    $choosen_lang = 'language='.$_SESSION['chat']->get_language();

    //unset objects in session
    unset($_SESSION['chat']);
    unset($_SESSION['translator']);
    //unset($_SESSION['chatter']);
    unset($_SESSION['channel']);
    unset($_SESSION['channel_buffer']);
    unset($_SESSION['lastRedLine']);
    unset($_SESSION['mailbox']);
    unset($_SESSION['current_mailbox_type']);
    unset($_SESSION['curr_mail_idx']);
    unset($_SESSION['inbox_count_new']);
    unset($_SESSION['outbox_count_new']);
    unset($_SESSION['trash_count_new']);
    unset($_SESSION['template']);
    unset($_SESSION['session_get']);
    unset($_SESSION['session_post']);
    unset($_SESSION['reload_count']);
    unset($_SESSION['httpneg']);
    if( isset($_SESSION['p_in']) ) {
      session_unregister('p_in');
      unset($_SESSION['p_in']);
    }
    if( isset($_SESSION['in']) ) {
      session_unregister('in');
      unset($_SESSION['in']);
    }
    
    session_unregister('chat');
    session_unregister('translator');
    //session_unregister('chatter');
    session_unregister('channel');
    session_unregister('channel_buffer');
    session_unregister('lastRedLine');
    session_unregister('mailbox');
    session_unregister('current_mailbox_type');
    session_unregister('curr_mail_idx');
    session_unregister('inbox_count_new');
    session_unregister('outbox_count_new');
    session_unregister('trash_count_new');
    session_unregister('template');
    session_unregister('session_get');
    session_unregister('session_post');
    session_unregister('reload_count');
    session_unregister('p_id');
    session_unregister('httpneg');
    
    return $choosen_lang;
  }

  function alter_db_schema()
  {
    function alter_db_schema_error($errno, $errmsg, $filename, $linenum, $vars)
    { 
      POC_Chat::display_error( $errno, $errmsg, $filename, $linenum, $vars, POC_DB_ERROR );
    }

    if( $this->connection_count == 0 )
      die('Not connected! Use connect() first!');
    
    /*
    set_error_handler("alter_db_schema_error");
    if( !in_array('PASSWORD_NEW', $this->db->MetaColumnNames(DATABASE_TABLE_PREFIX.'user_account')) ) {
      $this->db->Execute( 'ALTER TABLE '.DATABASE_TABLE_PREFIX.'user_account ADD PASSWORD_NEW varchar(255)' );
    }
    if( !in_array('KICKED', $this->db->MetaColumnNames(DATABASE_TABLE_PREFIX.'user_account')) ) {
      $this->db->Execute( 'ALTER TABLE '.DATABASE_TABLE_PREFIX.'user_account ADD KICKED int NOT NULL DEFAULT \'0\'' );
    }
    restore_error_handler();
    */
  }

  /**
  * Cleans up online status of chatters
  *
  * @return void
  */
  function make_clean()
  {
    if( $this->connection_count == 0 )
      die('Not connected! Use connect() first!');

    /*
    * cleanup unused accounts
    */
    $max_inactive_time = $this->db->DBTimeStamp( (time() - (MAX_INACTIVE_LIFETIME*3600*24))  );
    $rs = $this->db->Execute( 'SELECT NICK,USER FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE LAST_ACTIVE_TIME <= '.$max_inactive_time);
    
    if( $rs->RecordCount() > 0 )
    {
      while(!$rs->EOF)
      {
        if( in_array($rs->fields[0], $this->deathless_chatters) )
        {
          $rs->MoveNext();
          continue;
        }
        
        $sql = 'DELETE FROM '.DATABASE_TABLE_PREFIX.'channels WHERE NAME=\''.$rs->fields[0].'\'';
        if( !$this->db->Execute( $sql ) )
          die('POC_Chat::go_offline(): Can not delete guest account from '.DATABASE_TABLE_PREFIX.'channels.<br>SQL: '.$sql);
        
        $sql = 'DELETE FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER=\''.$rs->fields[1].'\'';
        if( !$this->db->Execute( $sql ) )
          die('POC_Chat::go_offline(): Can not delete guest account from '.DATABASE_TABLE_PREFIX.'user_data.<br>SQL: '.$sql);
        
        $sql = 'DELETE FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER=\''.$rs->fields[1].'\'';
        if( !$this->db->Execute( $sql ) )
          die('POC_Chat::go_offline(): Can not delete guest account from '.DATABASE_TABLE_PREFIX.'user_account.<br>SQL: '.$sql);
        
        $rs->MoveNext();
      }
    }
    
    /*
    * cleanup unclosed private channels
    */
    $max_inactive_time = $this->db->DBTimeStamp( (time() - (MAX_INACTIVE_ONLINETIME + 10))  );
    $rs = $this->db->Execute( 'SELECT NICK,ONLINE FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE LAST_ACTIVE_TIME <= '.$max_inactive_time.' AND ONLINE = \'1\'');
    if( $rs->RecordCount() > 0 )
    {
      while(!$rs->EOF)
      {
        $nick = $rs->fields[0];
        $sql = 'DELETE FROM '.DATABASE_TABLE_PREFIX.'channels WHERE NAME=\''.$nick.'\' AND TYPE = 2';
        if( !$this->db->Execute( $sql ) )
          die('POC_Chat::make_clean(): Can not delete unused private channel.<br>SQL: '.$sql);
        
        $rs->MoveNext();
      }
    }
    
    /*
    * set crashed chatters to offline
    */
    $record = array();
    $record[ 'ONLINE' ] = '0';
    if( $update_sql = $this->db->GetUpdateSQL( $rs, $record ) )
    {
      if( !$this->db->Execute( $update_sql ) )
        die('POC_Chat::make_clean(): Can not update online status.<br>UpdateSQL: '.$update_sql);
    }
    
    /*
    * DELETE unused guest accounts
    */
    $delete_guest_sql = '
    SELECT ua.USER as user
    FROM '.DATABASE_TABLE_PREFIX.'user_account ua NATURAL JOIN '.DATABASE_TABLE_PREFIX.'user_data ud 
    WHERE (ud.online IS NULL OR ud.online=0) 
       AND ua.USER LIKE "###GUEST_NICK_PREFIX###%"';
    
    if( !$rs=$this->db->Execute( $delete_guest_sql ) )
      die('POC_Chat::make_clean(): Can not delete unused guests.<br>DeleteSQL: '.$delete_guest_sql);
      
    if( $rs->RecordCount() > 0 )
    {
      while(!$rs->EOF)
      {
        $user = $rs->fields[0];
        $sql = 'DELETE FROM '.DATABASE_TABLE_PREFIX.'user_account WHERE USER=\''.$user.'\'';
        if( !$this->db->Execute( $sql ) )
          die('POC_Chat::make_clean(): Can not delete unused guests "'.$user.'" from user_account.<br>DeleteSQL: '.$sql);
        $sql = 'DELETE FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER=\''.$user.'\'';
        if( !$this->db->Execute( $sql ) )
          die('POC_Chat::make_clean(): Can not delete unused guests "'.$user.'" from user_data.<br>DeleteSQL: '.$sql);
        
        $rs->MoveNext();
      }
    }
    
    unset($max_inactive_time);
    unset($rs);
    unset($record);
    unset($update_sql);
  }
  
  /**
  * Gets a list of chatters online in fromat:<br>
  * (nickname)(unixtimestamp)(channel)\n
  *
  * @return string
  */
  function get_online_chatters_list( $unix_timestamp = true )
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    $rs = $this->db->Execute( 'SELECT NICK,LAST_ACTIVE_TIME,LAST_CHANNEL FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE ONLINE = \'1\'' );
    
    $chatters = '';
    while (!$rs->EOF)
    {
      if($unix_timestamp)
      $chatters .= '('.$rs->fields[0].')('.$rs->UnixTimeStamp($rs->fields[1]).')('.$rs->fields[2].')'.NL;
      else
      $chatters .= '('.$rs->fields[0].')('.$rs->fields[1].')('.$rs->fields[2].')'.NL;
      $rs->MoveNext();
    }
    $rs->Close();
    return $chatters;
  }
  
  /**
  * Provides a list of online chatters<br>
  *
  * @return array
  */
  function get_online_chatter()
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    $rs = $this->db->Execute( 'SELECT NICK,LAST_CHANNEL FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE ONLINE = \'1\' ORDER BY NICK' );
    
    $chatters = array();
    $chatters = $rs->GetArray();
    $rs->Close();
    unset($rs);
    
    return $chatters;
  }
  
  /**
  * Provides the channel of given chatter
  *
  * @param string; nickname of a chatter
  * @return string
  */
  function get_channel_of( $nickname )
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    $rs = $this->db->Execute( 'SELECT LAST_CHANNEL FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE ONLINE = \'1\' AND NICK = \''.$nickname.'\'' );
    return ($rs->RecordCount() > 0 )? $rs->fields[0]:'';
  }
  
  /**
  * Provides the count of online chatters<br>
  *
  * @return integer
  */
  function get_online_count()
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    $rs = $this->db->Execute( 'SELECT count(NICK) AS count FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE ONLINE = \'1\'' );
    
    $count = $rs->fields[0];
    $rs->Close();
    unset($rs);
    
    return $count;
  }
  
  /**
  * Provides the count of chatters online in the last 24h<br>
  *
  * @return integer
  */
  function get_online_count_last24h()
  {
    if( $this->connection_count == 0 )
      die('Not connected! Use connect() first!');

    $time = $this->db->DBTimeStamp( (time() - (60*60*24)) );
    $rs = $this->db->Execute( 'SELECT count(NICK) AS count FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE LAST_ACTIVE_TIME >= '.$time );

    $count = $rs->fields[0];
    $rs->Close();
    unset($rs);
    
    return $count;
  }
  
  /**
  * Provides the avg. of online time per chatter in seconds per day<br>
  *
  * @return double
  */
  function get_online_time_avg()
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    $rs = $this->db->Execute( 'SELECT SUM(ONLINE_TIME)/SUM(DAYS_REGISTERED) FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE DAYS_REGISTERED > 0' );
    $seconds_per_day = $rs->fields[0];
    $rs->Close();
    
    return $seconds_per_day;
  }
  
  /**
  * Provides the count of registered chatters<br>
  *
  * @return integer
  */
  function get_registered_count()
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    $rs = $this->db->Execute( 'SELECT COUNT(USER) FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE USER NOT LIKE \'###GUEST_NICK_PREFIX###%\'' );
    $count = $rs->fields[0];
    $rs->Close();
    
    return $count;
  }
  
  /**
  * Provides the count of mails in the DB<br>
  *
  * @return integer
  */
  function get_mail_count()
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    $rs = $this->db->Execute( 'SELECT COUNT(MAIL) FROM '.DATABASE_TABLE_PREFIX.'mails' );
    $count = (integer) $rs->fields[0];
    $rs->Close();
    
    return $count;
  }
  
  /**
  * Provides the count of mails in the DB from the last 24h<br>
  *
  * @return integer
  */
  function get_mail_count_last_24h()
  {
    if( $this->connection_count == 0 )
      die('Not connected! Use connect() first!');
    
    $now = date('Y-m-d-H-i-s',( time() - (60*60*24) ));
    $rs = $this->db->Execute( 'SELECT COUNT(MAIL) FROM '.DATABASE_TABLE_PREFIX.'mails WHERE TIME >= \''.$now.'\'' );
    $count = (integer) $rs->fields[0];
    $rs->Close();
    
    return $count;
  }
  
  /**
  * Provides the count of registered chatters<br>
  *
  * @return array
  */
  function get_last_registered()
  {
    if( $this->connection_count == 0 )
      die('Not connected! Use connect() first!');
    
    $rs = $this->db->SelectLimit( 'SELECT REGTIME,NICK FROM '.DATABASE_TABLE_PREFIX.'user_data WHERE NICK NOT LIKE \'###GUEST_NICK_PREFIX###%\' ORDER BY REGTIME DESC', 1, 0 );
    $rookie = $rs->GetArray();
    $rs->Close();
    
    return $rookie;
  }
  
  /**
  * Provides a note about a given chatter<br>
  *
  * @return string
  */
  function get_note_for( $nickname )
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    $rs = $this->db->Execute( 'SELECT NOTE FROM '.DATABASE_TABLE_PREFIX.'user_notes WHERE ABOUT=\''.$nickname.'\' AND NICKNAME=\''.$_SESSION['chatter']->get_nick().'\'' );
    $content = $rs->fields[0];
    $rs->Close();
    
    return $content;
  }
  
  function set_note_for( $nickname, $note )
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    $rs = $this->db->Execute( 'SELECT NOTE,ABOUT,NICKNAME FROM '.DATABASE_TABLE_PREFIX.'user_notes WHERE ABOUT=\''.$nickname.'\' AND NICKNAME=\''.$_SESSION['chatter']->get_nick().'\'' );
    
    if( strlen($rs->fields['NOTE']) >= MAX_NOTE_SIZE )
    {
      $rs->Close();
      return false;
    }
    $record = array();
    $record[ 'NOTE' ] = $note;
    if( $rs->RecordCount() != 1 )
    {
      $record[ 'ABOUT' ] = $nickname;
      $record[ 'NICKNAME' ] = $_SESSION['chatter']->get_nick();
      $insert_sql = $this->db->GetInsertSQL( $rs, $record );
      if( !$this->db->Execute( $insert_sql ) )
      {
        $_SESSION['logger']->error( 'POC_Chat::set_note_for(): Can not insert notes', __FILE__, __LINE__ );
        return false;
      }
      unset($insert_sql);
    }
    else
    {
      $update_sql = $this->db->GetUpdateSQL( $rs, $record, true );
      if( !$this->db->Execute( $update_sql ) )
      {
        $_SESSION['logger']->error( 'POC_Chat::set_note_for(): Can not update notes', __FILE__, __LINE__ );
        return false;
      }
      unset($update_sql);
    }
    
    unset($rs);
    unset($record);
    
    return true;
  }
  
  function get_grade_icon( $nick )
  {
    $grade = 'grade_rookie';
    if(SHOW_GRADE_ICONS)
    {
      if( $nick->is_operator() )$grade = 'grade_operator';
      elseif( $nick->get_grade() != '' ) $grade = strtolower( $nick->get_grade() );
    }
    else return '';
    
    return '<img src="'.$_SESSION['template']->get_theme_path().'/images/icons/'.$grade.'.gif" title="'.$_SESSION['translator']->out(strtoupper($grade)).'" alt="*" width="21" height="8" />&nbsp;';
  }
  
  function put_template_into_cache( $cacheId, $content, $period )
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    if( $period == 0 ) $period = DEFAULT_CACHE_LIFE_TIME;
    $rs = $this->db->Execute( 'SELECT ID,CONTENT,MAX_AGE FROM '.DATABASE_TABLE_PREFIX.'cache WHERE ID=\'dont exist\'' );
    $record = array();
    $record[ 'ID' ] = $cacheId;
    $record[ 'MAX_AGE' ] = $this->db->DBTimeStamp( (time() + (intval($period))) );
    $record[ 'CONTENT' ] = $content.NL.'<!--[POC-Cache] expires: '.$record[ 'MAX_AGE' ].'-->';
    
    if( !($insert_sql = $this->db->GetInsertSQL( $rs, $record )))
      $_SESSION['logger']->error('Could not get insert sql',__FILE__,__LINE__);
    
    $insert_sql = preg_replace('/\'\'/','\'',$insert_sql);
    $rs->Close();
    if( !$this->db->Execute( $insert_sql ) )
      $_SESSION['logger']->error('Could not insert data into cache table. SQL: "'.$insert_sql.'"',__FILE__,__LINE__);
    
    unset($insert_sql);
    unset($record);
    unset($rs);
    return true;
  }
  
  function get_template_from_cache( $cacheId )
  {
    if( $this->connection_count == 0 )
    die('Not connected! Use connect() first!');
    
    $rs = $this->db->Execute( 'SELECT CONTENT FROM '.DATABASE_TABLE_PREFIX.'cache WHERE ID=\''.$cacheId.'\' AND MAX_AGE >= '.$this->db->DBTimeStamp(time()) );
    if( $rs->RecordCount() == 0 )
    {
      $this->db->Execute( 'DELETE FROM '.DATABASE_TABLE_PREFIX.'cache WHERE ID=\''.$cacheId.'\'' );
      $rs->Close();
      return '';
    }
    $content = $rs->fields[0];
    $rs->Close();
    
    return $content;
  }
  
  /**
  * Method to perform an HTTP POST to a web page from a PHP script.
  *
  * Example: http_post( "www.foo.com", 80, "/check.php", array("name" => "foo", "age" => "20") );
  *
  * @author <nf@bigpond.net.au>  {@link http://nf.wh3rd.net/}
  * @param string server to post to
  * @param integer server post, mostly port 80
  * @return mixed
  */
  function http_post($server, $port, $url, $vars)
  {

    $user_agent = "Mozilla/4.0 (compatible; MSIE 5.5; Windows 98)";

    $urlencoded = "";
    while ( list($key,$value) = each($vars) )
      $urlencoded .= urlencode( $key ) . "=" . urlencode( $value ) . "&";
    $urlencoded = substr($urlencoded,0,-1);
    $content_length = strlen($urlencoded);
    $headers = "POST $url HTTP/1.1
Accept: */*
Accept-Language: en
Content-Type: application/x-www-form-urlencoded
User-Agent: $user_agent
Host: $server
Connection: Keep-Alive
Cache-Control: no-cache
Content-Length: $content_length

";

    $fp = fsockopen($server, $port, $errno, $errstr);
    if (!$fp) return false;

    fputs($fp, $headers);
    fputs($fp, $urlencoded);

    $ret = '';
    while (!feof($fp))
      $ret.= fgets($fp, 1024);
          
    fclose($fp);
    
    return $ret;
  }

  
  /**
  * Provides html-code to display errors
  *
  * @param $errno
  * @param $errstr
  * @param $errfile
  * @param $errline
  * @param $vars
  * @param $poc_error_msg
  * @return void
  */
  function display_error( $errno, $errstr, $errfile, $errline, $vars = null, $poc_error_msg = null )
  {
    echo '<html><head>';
	if( isset($_SESSION['template']) )
	  echo '<link title="default" href="'.$_SESSION['template']->get_theme_path().'/css/default.css" rel="stylesheet" media="all" />';
    else
	  echo '<link title="default" href="'.substr(BASETEMPLATE_PATH, 1).'/'.DEFAULT_THEME.'/css/default.css" rel="stylesheet" media="all" />';
    echo '</head><body>';
	echo '
      <div class="content">
        <div class="contentBox" style="margin-top:100px;background-color:#f66;width: 100%;">
          <dl>
            <dt class="contentBoxTitle" style="background-color:#fff">
	';
    if(isset($_SESSION['template'])) {
      echo '<img align="middle" src="'.$_SESSION['template']->get_theme_path().'/images/icons/error.gif" alt="(x)" /> ';
    } else {
      echo '<img align="middle" src="'.substr(BASETEMPLATE_PATH, 1).'/'.DEFAULT_THEME.'/images/icons/error.gif" alt="(x)" /> ';
    }
    switch ($errno) {
      case FATAL:
        echo '<b>FATAL</b></dt>';
        break;
      case ERROR:
        echo '<b>ERROR</b></dt>';
        break;
      case WARNING:
        echo '<b>WARNING</b></dt>';
        break;
      default:
        echo '<b>Unkown Error</b></dt>';
        break;
    }
    echo '<dd style="font-size:14px">';
    echo '<p style="font-weight:bold;font-size:16px">Sorry, an error occurred.</p>';
    if( $errline > 0 )
      echo '<span style="font-size:11px">at&nbsp;'.$errfile.':'. $errline.'</span><br />'.NL;
    ob_start();
    echo '<span style="font-size:11px">['.$errno.'] '.$errstr.'</span><br />'.NL;
    $summary = ob_get_contents();
    ob_end_clean();
    
    echo $summary;
    ob_start();
    echo '<p style="font-style:italic">PHP '.PHP_VERSION.' ('.PHP_OS.')<br />'.NL;
    if( isset($_SERVER['HTTP_USER_AGENT']) ) echo 'Browser: '.$_SERVER['HTTP_USER_AGENT'].'<br />'.NL;
    if( isset($_SERVER['SERVER_SOFTWARE']) ) echo 'Webserver: '.$_SERVER['SERVER_SOFTWARE'].'<br />'.NL;
    if( isset($_SERVER['HTTP_HOST']) && isset($_SERVER['REQUEST_URI']) ) echo 'URI: http://'.$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI'].'<br />'.NL;
    echo '</p>';
    $info = ob_get_contents();
    ob_end_clean();
    echo '<br />';
    switch($poc_error_msg){
      case POC_SESSION_ERROR:
	echo 'Your webserver has <span style="text-decoration: underline">no write permissions</span> in "'.TMPDIR.'"!<br />
	      <a style="font-weight:bold;font-size:12px;text-decoration:none;text-decoration:blink;background:none" href="install.php">Use the Installer</a> to install your chat!
	      Or in your favorite shell, do the following:<br />';
	echo 'chmod 777 '.TMPDIR.'<br />and press ENTER.';
	break;
      case POC_DB_ERROR:
	echo '<span style="text-decoration: underline">Could not connect to database!</span> Please check your database setup in config.inc.php by using the <a style="background:none;font-size:14px" href="install.php">POC Installer</a>!';
	break;
      default:
	echo 'If you are sure this is a bug,<br />Please use our bugtracker to <a style="background:none;font-size:14px" href="http://www.das-board.info/mantisbt/bug_report_page.php?additional_info='.urlencode( strip_tags($info) ).'&amp;summary='.urlencode( substr(strip_tags(preg_replace('/\n|\r|\r\n/','',$summary)),4,20).'...').'&amp;description='.urlencode( strip_tags($summary) ).'">report bugs</a>.';
    }

    echo $info;
    echo '
			</dd>
		  </dl>
        </div>
  	  </div>
	';
    echo '</body></html>';
    //Clean up the session
	
    unset($_SESSION);
    if(function_exists('session_destroy'))
      @session_destroy();
    if( strtolower(session_module_name()) == 'files') {
      @unlink( session_save_path().DELI.'sess_'.session_id() );
      //echo 'debug: session file removed. "'.session_save_path().DELI.'sess_'.session_id().'"';
    }
    exit;
  }
  
  /**
  * @desc 
  * Maps miscellaneous lang codes to iso639-2
  *
  * @param string
  * @see {@link http://www.loc.gov/standards/iso639-2/langcodes.html}
  * @return string
  * @static
  */
  function map_language_code( $code )
  {
    if( is_null($code) || $code == '' ) return false;
    
    global $supported_languages;
    if( in_array($code, $supported_languages) ) return $code;//don't try to map a code if it's not nesessary
    if( preg_match('/([^\.]*)\.lng/', $code, $matches) ){
      //yabbse's language codes have a trailing '.lng' !?
      $code = $matches[1];
      unset($matches);
    }
    
    $mapping_table = array(	
      'ar' => array ('ara','arabic'),
      'br' => array ('bra','brazil'),              //TODO: missused code, move to x-br
      'cn' => array ('zho','chinese'),             //TODO: missused code, move to zh
      'cs' => array ('ces','cze','czech'),
      'de' => array ('deu','ger','deutsch','german'),
      'dk' => array ('dan','danish'),              //TODO: missused code, move to da
      'en' => array ('eng','english','englisch'),
      'eo' => array ('epo','esperanto'),
      'es' => array ('spa','spanish','castilian'), //TODO: missused code, move to da
      'fi' => array ('fin','finnish'),
      'fr' => array ('fre','fra','french'),        //TODO: missused code, move to da
      'hu' => array ('hun','hungarian'),
      'is' => array ('isl','ice','icelandic'),
      'it' => array ('ita','italian'),
      'ja' => array ('jpn','japanese'),
      'ko' => array ('kor','korean'),
      'nl' => array ('dut','nld','dutch','flemish'),
      'pl' => array ('pol','polish'),
      'pt' => array ('por','portuguese'),
      'ru' => array ('rus','russian'),
      'se' => array ('swe','swedish'),              //TODO: missused code, move to sv
      'tr' => array ('tur','turkish'),
      'tw' => array ('tha','thai')                  //TODO: missused code, move to th
    );
    foreach ($mapping_table as $poc_code => $codes){
      if( in_array($code, $codes) && in_array($poc_code, $supported_languages)){
        return $poc_code;
      }
    }
    
    return false;
  }
  
  /**
  * Converts rdf to html
  *
  * @param string URL or file name of rdf source
  * @return string content as html
  */
  function rdf2html( $file )
  {
    //read rdf-file
    $contents = join('', file($file));
    
    preg_match_all('#<item>(.*?)</item>#msi', $contents, $matches);
    $counter = 0;
    $item_array = array();
    foreach($matches[1] as $item){
        $counter++;
        
        //get headlines
        preg_match('#<title>(.*?)</title>#msi', $item, $match);
        $item_array[$counter]['title'] = $match[1];
       
        //get links
        preg_match('#<link>(.*?)</link>#msi', $item, $match);
        $item_array[$counter]['link'] = $match[1];   
    }
    unset($counter);
    
    //html
    $html = '';
    foreach($item_array as $link){
       $html .= '<a href=\"' . $link['link'] . '\">' . $link['title'] . '</a><br />'.NL;   
    }
    unset($item_array);

    return $html;
  }
  
  /**
  * Test class Chat
  *
  * call like: POC_Chat::test();
  */
  function test()
  {
    $start = microtime();
    
    $chat = new POC_Chat( 'schulhof' );
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