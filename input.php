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

/*
  $Author: letreo $
  $Date: 2004/02/29 19:57:11 $
  $Source: /cvsroot/phpopenchat/chat3/input.php,v $
  $Revision: 1.65.2.15 $
*/

require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Recipient.inc');//extents Chatter
require_once(POC_INCLUDE_PATH.'/class.Line.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel_Buffer_'.CHANNEL_BUFFER_TYPE.'.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

session_start();

//check if chatter is authorized to get this page
if( !isset($_SESSION['chatter']) || !isset($_SESSION['channel']) ) {
  header('Status: 301');
  header('Location: index.php?forceOnTop=1');
  exit;
}

if( $_SESSION['chatter']->is_kicked() || $_SESSION['chatter']->is_disabled() ) {
  $_SESSION['chatter']->reset_kick();

  $choosen_lang = 'language='.$_SESSION['chat']->get_language();
  $_SESSION['chat']->logout();

  //redirect to the homepage
  header('Status: 301');
  if( KICK_URL != '' )
    header('Location: index.php?forceOnTop=1&jump='.urlencode(KICK_URL));
  else
    header('Location: index.php?onTop=1&'.session_name().'='.session_id().'&'.$choosen_lang);
  unset($choosen_lang);
  exit;
}

$show_message_locally = '';
$channel_login_form = '';
$TEMPLATE_OUT['js_onload'] = '';
$TEMPLATE_OUT['temp'] = '';

function write_channel_login_form() {
  return ' <form action="unlock_channel.php" method="post" target="dummy" style="display:inline"><input class="unlock" type="password" name="password" /><input class="submit" type="submit" value="'.$_SESSION['translator']->out('UNLOCK_CHANNEL').'" /><\/form>';
}
  
if(!isset($_POST['recipient'])) $_POST['recipient']='';

if(  $_SESSION['channel']->is_password_protected()
 && !$_SESSION['chatter']->is_authorized_for($_SESSION['channel']->get_name()) ) {
  unset($_POST['line']);//chatter isn't authorized to 'speak' in this channel
}

if( isset($_POST['line']) && $_POST['line'] != '' && strlen($_POST['line']) <= MAX_LINE_LENGTH ) {
    $_SESSION['reload_count'] = 0;//reset chat session expiration time
    $skip_line = false;
    $_POST['line'] = preg_replace('/\'/', '&#39;', $_POST['line'] );
    $_POST['line'] = preg_replace('/(.{70})/', '\0&#173;', $_POST['line'] );//&shy; forces a line break if needed
    $_POST['line'] = preg_replace('/</', '&lt;', $_POST['line'] );//disallow html
    $TEMPLATE_OUT['temp'] = $_POST['line'];

    $_POST['line'] = POC_Chat::check_chat( $_POST['line'], $NONO_WORDS);
    if(MULTIPLE_LINE_INPUT) {
       $_POST['line'] = preg_replace('/\r\n|\n|\r/', '<br />', $_POST['line'] );
       $_POST['line'] = preg_replace('/><br \/>/', '>', $_POST['line'] );
       $_POST['line'] = '<p style="padding-left:50px;margin-top:0">'.$_POST['line'].'</p>';
    }

    //adodb doesn't update, if old value equals new value.
    //To force an update, we add a random comment
    //$said = $_POST['line'].'<!--'.rand(0,15).'-->';
    $said = $_POST['line'];
    $line = &new POC_Line( $_SESSION['chatter'], $said);
    $line->set_accepted_mime_types($ACCEPTED_MIME_TYPES);
    $line->filter_irc();
    $irc_command = array();
    $irc_command = $line->get_irc_command();

    // check for an irc-command in line
    if( isset($irc_command[0]) ) {
      //if( isset($irc_command[1]) )
        //$irc_command[1] = preg_replace('/<!--.+-->/','',$irc_command[1]);
      
      $skip_line = true;

     /* IRC-command
      * /join <channelname>
      * to change the channel
      */
      if( $irc_command[0] == 'join' && $irc_command[1] != '' ) {
         $channels = array();
         $_SESSION['chat']->connect();
          $channels = $_SESSION['chat']->get_channels();
         $_SESSION['chat']->disconnect();
         
         if( in_array(strval($irc_command[1]), $channels) ) {
           $_POST['channel'] = $irc_command[1];
         }
      }
      
     /* IRC-command
      * /msg <nickname> <line content>
      * to whisper to a chatter
      */
      if( $irc_command[0] == 'msg' && $irc_command[1] != '' ) {
        if( $_SESSION['channel']->is_attendant($irc_command[1]) ) {
          $_POST['recipient'] = $irc_command[1];
          $_POST['whispered'] = true;
          $said = preg_replace('#/msg '.$irc_command[1].'#', '', $line->get_said() );
          $line->set_said($said);
          $skip_line = false;
        } else {
          $_SESSION['chat']->connect();
          if( $recipient_channel = $_SESSION['chat']->get_channel_of($irc_command[1]) ) {
            $said = preg_replace('#/msg '.$irc_command[1].'#', '', $line->get_said() );
            $line->set_said($said);
            $recipient = POC_Chat::mkinstance_chatter($irc_command[1]);
            $line->set_recipient($recipient);
            $line->set_whispered();
            $_channel_buffer = &new POC_Channel_Buffer($recipient_channel);
            $line->filter_buffer_input();
            $_channel_buffer->connect();
            $tmp = $_channel_buffer->put_line($line);
            $_channel_buffer->disconnect();
            $_SESSION['chatter']->count_hit('line');
            $show_message_locally = '<div style="padding-left:25px"><span>'.STATUS_BOT_NAME.':&nbsp;</span>'.$_SESSION['translator']->out('LINE_HAS_BEEN_SENT_TO').':&nbsp;'.$irc_command[1].'&nbsp;['.$recipient_channel.']</div>';
            unset($_channel_buffer);
            unset($recipient_channel);
          } else {
            $show_message_locally = '<div style="padding-left:25px"><span>'.STATUS_BOT_NAME.':&nbsp;</span>'.$irc_command[1].' '.$_SESSION['translator']->out('IS_NOT_ONLINE').'</div>';
          }
          $_SESSION['chat']->disconnect();
        }
      }

     /* IRC-command
      * /me <line content>
      */
      if( $irc_command[0] == 'me' ) {
        $said = preg_replace('#/me#', $_SESSION['chatter']->get_nick(), $line->get_said() );
        $line->set_said($said);
        $skip_line = false;
      }

     /* IRC-command
      * /locate <nickname>
      */
      if( $irc_command[0] == 'locate' ) {
        unset($said);
        $_chatter = POC_Chat::mkinstance_chatter( $irc_command[1] );
        if( !is_null($_chatter) ) {
          $_channel = $_chatter->get_db_lastChannel();
          if( $_chatter->is_online() )
            $said = '<em>'.$irc_command[1].'</em> '.$_SESSION['translator']->out('LOCATED_AT').' <strong>'.$_channel.'</strong>';
        }
        if( !isset($said) ) {
          $said = '<em>'.$irc_command[1].'</em> '.$_SESSION['translator']->out('UNLOCATED');
        }
        
        $line->set_said($said);
        $_POST['recipient'] = $_SESSION['chatter']->get_nick();
        $line->set_whispered();
        $bot  = &new POC_Chatter(strval(STATUS_BOT_NAME),'');
        $line->set_sender($bot);
        $skip_line = false;
      }
      
     /* IRC-command
      * /ignore <nickname>
      * to ignore a chatter
      */
      if( $irc_command[0] == 'ignore' && $irc_command[1] != '' 
        && $_SESSION['channel']->is_attendant($irc_command[1]) ) {
        $_SESSION['chatter']->ignore( $irc_command[1] );
        $show_message_locally = '<div>'.$irc_command[1].' ignored</div>';
      }
      
     /* IRC-command
      * /unignore <nickname>
      * to ignore a chatter
      */
      if( $irc_command[0] == 'unignore' && $irc_command[1] != '' 
        && $_SESSION['channel']->is_attendant($irc_command[1]) ) {
        $_SESSION['chatter']->unignore( $irc_command[1] );
      }
      
     /* IRC-command
      * /query <nickname>
      * to query for a private chat within the own channel
      */
      if( $irc_command[0] == 'query' && $irc_command[1] != '' 
        && $_SESSION['channel']->is_attendant($irc_command[1]) ) {
        if(IRC_QUERY_OPENS_WINDOW) {
          $TEMPLATE_OUT['js_onload'] .= 'parent.output.privateChatWindow(\''.$irc_command[1].'\',\''.$_SESSION['chatter']->get_nick().'\')';
          $skip_line = true;
        } else {
          /*important notice of my three years old dother ;)
          jkaqas
          (annabel 02/2003)
  	      */
  	      
          //invite given chatter
          $_SESSION['chatter']->invite( $irc_command[1] );
          
          //send invitation to given chatter
          $_POST['recipient'] = $irc_command[1];
          $line->set_whispered();
          $bot  = &new POC_Chatter(strval(STATUS_BOT_NAME),'');
          $line->set_sender($bot);
          $line->set_invitationMsg(true);
          $line->set_said('<span class="invitationMsg">###INVITATION_MESSAGE###'.' "'.$_SESSION['chatter']->get_nick().'"</span>');

          //join the own private channel
          $_POST['channel'] = $_SESSION['chatter']->get_nick();
          $skip_line = false;
        }
      }
      
     /* IRC-command
      * /help
      * to query for a private chat within the own channel
      */
      if( $irc_command[0] == 'help' ) {
        
        $_POST['recipient'] = $_SESSION['chatter']->get_nick();
        $line->set_whispered();
        $bot  = &new POC_Chatter(strval(STATUS_BOT_NAME),'');
        $line->set_sender($bot);
        
        //get template of inline-help
        $content = $_SESSION['chat']->get_template('inline_help', true);
        $line->set_said($content);
        $skip_line = false;
      }
      
     /* IRC-command
      * /quit
      * to quit the chat
      */
      if( $irc_command[0] == 'quit' ) $_GET['exit'] = 1;
      
     /* IRC-command
      * /kick
      * to kick a chatter
      */
      if( $irc_command[0] == 'kick' 
      && ($_SESSION['chatter']->is_operator() || $_SESSION['chatter']->is_moderator()) ) {
        $_chatter = $_SESSION['chat']->mkinstance_chatter($irc_command[1], true);
        $content  = $_chatter->kick()? $irc_command[1].' kicked': $irc_command[1].' not kicked';
        $_POST['recipient'] = $_SESSION['chatter']->get_nick();
        $line->set_whispered();
        $bot      = &new POC_Chatter(STATUS_BOT_NAME,'');
        $line->set_sender($bot);
        
        $line->set_said($content);
        $skip_line = false;
        unset($_chatter);
      }
      
     /* IRC-command
      * /disable
      * to disable a chatter
      */
      if( $irc_command[0] == 'disable' 
      && ($_SESSION['chatter']->is_operator() || $_SESSION['chatter']->is_moderator()) ) {
        $_chatter = $_SESSION['chat']->mkinstance_chatter($irc_command[1], true);
        $content  = $_chatter->disable()? $irc_command[1].' disabled': $irc_command[1].' not disabled';
        $_POST['recipient'] = $_SESSION['chatter']->get_nick();
        $line->set_whispered();
        $bot      = &new POC_Chatter(STATUS_BOT_NAME,'');
        $line->set_sender($bot);
        
        $line->set_said($content);
        $skip_line = false;
        unset($_chatter);
      }

     /* IRC-command
      * /ban <nickname> <period in minutes>
      * to ban a chatter
      */
      if( $irc_command[0] == 'ban' && $_SESSION['chatter']->is_operator() ) {
        $_chatter = &new POC_Chatter(STATUS_BOT_NAME);
        $_chatter->set_nick( $irc_command[1] );
        $content = ( $_chatter->ban( $_SESSION['channel']->get_name(), $irc_command[2] ))? 
          $irc_command[1].' banned for '.$irc_command[2].' minutes.':
          $irc_command[1].' not banned. Format: /ban &lt;nickname&gt; &lt;period in minutes&gt;';
        $_POST['recipient'] = $_SESSION['chatter']->get_nick();
        $line->set_whispered();
        $bot  = &new POC_Chatter(STATUS_BOT_NAME,'');
        $line->set_sender($bot);

        //get template of inline-help

        $line->set_said($content);
        $skip_line = false;
        unset($_chatter);
      }

     /* IRC-command
      * /<nickname> <line content>
      * to speak to a chatter
      */
      if($_SESSION['channel']->is_attendant($irc_command[0])) {
        $_POST['recipient'] = $irc_command[0];
        $said = preg_replace('#/'.$irc_command[0].'#', '', $line->get_said() );
        $line->set_said($said);
        if( $irc_command[1] != '' ) $skip_line = false;
      }
    }
    
    if( isset($_POST['recipient']) && $_POST['recipient'] != '' )
    {
      $recipient = &new POC_Recipient( $_POST['recipient'] );
      $line->set_recipient( $recipient );
      unset($recipient);
    }

    if( isset($_POST['whispered']) )
        $line->set_whispered();

    if( $_SESSION['channel']->is_moderated() )
    {
        $gender_space =( SHOW_GENDER_ICON )? '12px':'0';
      
        if( $_SESSION['chatter']->is_vip() || $_SESSION['chatter']->is_moderator() )
          $line->set_approved();//within moderated channels moderators or vips can post lines directly
        else
          $show_message_locally = '<div style="padding-left:25px"><span style="padding-left:'.$gender_space.'">'.STATUS_BOT_NAME.':&nbsp;</span>'.$_SESSION['translator']->out('MESSAGE_FORWARDED_TO_MODERATOR').'&nbsp;['.$_POST['line'].']</div>';
    }

    if( !$skip_line )
    {
      $line->filter_buffer_input();
      $_SESSION['channel_buffer']->connect();
      $_SESSION['channel_buffer']->put_line($line);
      $_SESSION['channel_buffer']->disconnect();
      $_SESSION['chatter']->count_hit('line');

      if( !$_SESSION['channel']->is_moderated() )
        $show_message_locally = $line->out();
    }
    unset($said);
    unset($line);
}
else $_POST['line']='';

if( isset( $_POST['channel'] ) && ( $_POST['channel'] != $_SESSION['channel']->get_name() ) )
{
   $_SESSION['reload_count'] = 0;//reset chat session expiration time
   $_SESSION['chatter']->join_channel( $_POST['channel'] );
   if( $_SESSION['channel']->is_password_protected()
      && !$_SESSION['chatter']->is_authorized_for($_SESSION['channel']->get_name()) )
       $channel_login_form = write_channel_login_form();
}

if( isset($_GET['exit']) )
{
  $choosen_lang = 'language='.$_SESSION['chat']->get_language();
  $_SESSION['chat']->logout();

  //redirect to the homepage
  header('Status: 301');
  if( EXIT_URL != '' ){
    header('Location: index.php?forceOnTop=1&jump='.urlencode(EXIT_URL));
  }else{
    $no_autologin = (AUTOLOGIN_DIRECTLY)? '&no_autologin=1':''; 
    header('Location: index.php?onTop=1&'.session_name().'='.session_id().'&'.$choosen_lang.$no_autologin);
  }
  exit;
}

if( isset($_POST['filter_form']) )
{
    if( isset($_POST['sys_msg']) )
        $_SESSION['chatter']->set_sys_msg( true );
    
    if( !isset($_POST['sys_msg']) || $_POST['sys_msg'] == '')
        $_SESSION['chatter']->set_sys_msg( false );
    
    if( isset($_POST['private']) )
        $_SESSION['chatter']->set_private( true );
    
    if( !isset($_POST['private']) ||  $_POST['private'] == '')
        $_SESSION['chatter']->set_private( false );
    
    if( isset($_POST['bodies']) )
        $_SESSION['chatter']->set_bodies( true );
    
    if( !isset($_POST['bodies']) ||  $_POST['bodies'] == '')
        $_SESSION['chatter']->set_bodies( false );
}

if( isset($_POST['whispered']) )
 $TEMPLATE_OUT['whispered_checked'] = 'checked="checked"';
else
 $TEMPLATE_OUT['whispered_checked'] = '';
 
if( $_SESSION['chatter']->get_private() )
 $TEMPLATE_OUT['private_checked'] = 'checked="checked"';
else
 $TEMPLATE_OUT['private_checked'] = '';
 
 
if( $_SESSION['chatter']->get_bodies() )
 $TEMPLATE_OUT['bodies_checked'] = 'checked="checked"';
else
 $TEMPLATE_OUT['bodies_checked'] = '';

if( $_SESSION['chatter']->get_sys_msg() )
 $TEMPLATE_OUT['sys_msg_checked'] = 'checked="checked"';
else
 $TEMPLATE_OUT['sys_msg_checked'] = '';

$_SESSION['chat']->connect();
$option_list_of_friends          = $_SESSION['chat']->get_friends_option_list( $_SESSION['channel']->get_name() );
$option_list_of_channel_chatters = $_SESSION['chat']->get_channel_chatters_option_list( $_SESSION['channel']->get_name() );
$option_list_of_channels         = $_SESSION['chat']->get_channels_option_list( $_SESSION['channel']->get_name() );
$_SESSION['chat']->disconnect();

if( isset($_SESSION['curr_mail_idx']) )
  $mail_param = '&amp;body='.$_SESSION['curr_mail_idx'];
else 
  $mail_param = '';

$mod_class = 'class="chatter"';
if( $_SESSION['chatter']->is_moderator() && $_SESSION['channel']->is_moderated() )
  $mod_class = 'class="moderator"';
if( $_SESSION['chatter']->is_vip() && $_SESSION['channel']->is_moderated() )
  $mod_class = 'class="vip"';
if( $_SESSION['chatter']->is_operator() )
  $mod_class = 'class="operator"';
  
if ( !isset($_SESSION['template']) )
{
	$template = &new POC_Template();
	$_SESSION['template'] = $template;
}

$TEMPLATE_OUT['show_message_locally'] = $show_message_locally.$channel_login_form;
$TEMPLATE_OUT['option_list_of_channels'] = $option_list_of_channels;
$TEMPLATE_OUT['option_list_of_friends'] = $option_list_of_friends;
$TEMPLATE_OUT['option_list_of_channel_chatters'] = $option_list_of_channel_chatters;
$TEMPLATE_OUT['mod_class'] = $mod_class;
$TEMPLATE_OUT['mail_param'] = $mail_param;
$TEMPLATE_OUT['salutation'] = $_SESSION['chatter']->get_nick().', '.$_SESSION['translator']->out('LOGIN_WELCOME');
$_SESSION['template']->get_template('input');
?>