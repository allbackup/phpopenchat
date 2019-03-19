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
  $Date: 2004/08/26 11:57:24 $
  $Source: /cvsroot/phpopenchat/chat3/getlines.php,v $
  $Revision: 1.74.2.20 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Recipient.inc');//extents Chatter
require_once(POC_INCLUDE_PATH.'/class.Line.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel_Buffer_'.CHANNEL_BUFFER_TYPE.'.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');
require_once(POC_INCLUDE_PATH.'/class.Mail.inc');
require_once(POC_INCLUDE_PATH.'/class.Mailbox.inc');

session_start();
if(!isset($_SESSION['chatter']) || !is_object($_SESSION['chatter'])) {
  die('Login first!');
}

if( $_SESSION['chatter']->is_kicked() || $_SESSION['chatter']->is_disabled() ) {
  die('
  <html><head>
    <script type="text/javascript">
    if(parent.input && parent.input.document.forms[0]){
      //switch off polling
      parent.serialize_refresh=0;
    
      parent.input.document.forms[0].elements[\'line\'].value = parent.input.last_sent_line + \'foo\';
      parent.input.document.forms[0].submit();
    }
    </script>
	</head>
    <body></body>
  </html>
  ');
}
  
if(( $_SESSION['reload_count'] * LINE_POLLING_INTERVAL ) >= MAX_INACTIVE_ONLINETIME)
{
  $lang = $_SESSION['chat']->logout();

  //redirect to the homepage
  header('Status: 301');
  if( EXIT_URL != '' ) {
    header('Location: index.php?forceOnTop=1&jump='. urlencode(EXIT_URL));
  } else {
    header('Location: index.php?forceOnTop=1&'.session_name().'='.session_id().'&'.$lang);
  }
  exit;
} else {    
  $_SESSION['reload_count']++;
  if( ($_SESSION['reload_count'] % 2) == 0 ) //do not refresh every time
    $_SESSION['chatter']->refresh();
}

$alert_recipient = '';
$sound_recipient = '';
$css_line_class  = '';
$js_debug        = '';
$all_lines       = '';
$TEMPLATE_OUT['js_onload']         = '';
$TEMPLATE_OUT['all_chatters']      = '';
$TEMPLATE_OUT['js_update_chatter'] = '';
$login           = false;

function addSound( $sound ){
  if( $_SESSION['chatter']->get_advice() != 'sound' )return'';
  
  return '
    <object classid="CLSID:6BF52A52-394A-11d3-B153-00C04F79FAA6" height="0" width="0">
      <param name="url" value="'.$_SESSION['template']->get_theme_path().'/sounds/'.$sound.'.wav" />
      <param name="autostart" value="true" />
    </object>
    <object data="'.$_SESSION['template']->get_theme_path().'/sounds/'.$sound.'.wav" type="audio/wav" width="0" height="0">
      <param name="src" value="'.$_SESSION['template']->get_theme_path().'/sounds/'.$sound.'.wav" />
      <param name="autostart" value="true" />
    </object>
    ';
}


if( ( $_SESSION['reload_count'] * LINE_POLLING_INTERVAL ) > (MAX_INACTIVE_ONLINETIME - 10) )
  $TEMPLATE_OUT['js_onload'] .= 'parent.autoLogoutNotice();';

if( isset($_GET['login']) && $_GET['login'] == 1 && !isset($_SESSION['in']))
{
  /* mozilla 1.4b uses the source of frameset every time where this page are reloaded, 
   * so $_GET['login'] is set everytime 
   * Workaround:
   */
  $login = true;
  if(function_exists('session_register')) {
    session_register('in');
  }
  $_SESSION['in'] = '';
  
  $TEMPLATE_OUT['js_onload'] .= 'parent.scroll_it();parent.currentChannel=\''.$_SESSION['channel']->get_name().'\';';
  define('MY_NICK', $_SESSION['chatter']->get_nick());
  if(! DISABLE_CONTEXT_MENU_ICONS)
  { $img_path = $_SESSION['template']->get_tmpl_web_path();
    //define('ADD_ICON','<img src="'.$img_path.'/images/icons/add_chatter.gif" />');
    define('NOTICE_ICON','<img src="'.$img_path.'/images/icons/notice.gif" width="16" height="16" />');
    define('PRIVATE_CHAT_ICON','<img src="'.$img_path.'/images/icons/private_chat.gif" width="16" height="16" />');
    define('SAY_TO_ICON','<img src="'.$img_path.'/images/icons/say_to.gif" width="16" height="16" />');
    define('WHISPER_TO_ICON','<img src="'.$img_path.'/images/icons/whisper_to.gif" width="16" height="16" />');
    define('USERPAGE_ICON','<img src="'.$img_path.'/images/icons/userpage.gif" width="16" height="16" />');
    define('INVITE_ICON','<img src="'.$img_path.'/images/icons/invite_chatter.gif" width="16" height="16" />');
    define('DISINVITE_ICON','<img src="'.$img_path.'/images/icons/disinvite_chatter.gif" width="16" height="16" />');
    define('IGNORE_CHATTER_ICON','<img src="'.$img_path.'/images/icons/add_ignore_list.gif" width="16" height="16" />');
    define('UNIGNORE_CHATTER_ICON','<img src="'.$img_path.'/images/icons/del_ignore_list.gif" width="16" height="16" />');
    define('ADD_FRIEND_ICON','<img src="'.$img_path.'/images/icons/add_friend_list.gif" width="16" height="16" />');
    define('MAIL_ICON','<img style="border:0" src="'.$img_path.'/images/icons/newmail.gif" width="16" height="16" />');
    define('TRANSPARENT_ICON','<img src="'.$img_path.'/images/dot_clear.gif" width="16" height="16" />');
  }
  else
  {
    //define('ADD_ICON','');
    define('NOTICE_ICON','');
    define('PRIVATE_CHAT_ICON','');
    define('SAY_TO_ICON','');
    define('WHISPER_TO_ICON','');
    define('USERPAGE_ICON','');
    define('INVITE_ICON','');
    define('DISINVITE_ICON','');
    define('IGNORE_CHATTER_ICON','');
    define('UNIGNORE_CHATTER_ICON','');
    define('ADD_FRIEND_ICON','');
    define('MAIL_ICON','');
    define('TRANSPARENT_ICON','');
  }
  define('_LANG',$_SESSION['chat']->get_language());
  $all_lines = $_SESSION['chat']->get_template('output');
  /*
  $TEMPLATE_OUT['all_chatters']  = 'parent.chatter.document.writeln(\'';
  $TEMPLATE_OUT['all_chatters'] .= $_SESSION['chat']->get_template('chatter');
  $TEMPLATE_OUT['all_chatters'] .= '\');';
  */
  
  //if the chatter has birthday, we send him congratulations
  if( $_SESSION['chatter']->has_birthday() )
  {
    $_SESSION['chat']->write_sys_msg( ':birthday: '.$_SESSION['translator']->out('HAPPY_BIRTHDAY',true),$_SESSION['chatter'] );
    $sound_recipient .= addSound('birthday');
  }
  $inbox = &new POC_Mailbox( 'inbox' );
  if( $inbox->get_unread_mail_count()>0 ){
    $_SESSION['chat']->write_sys_msg( ':mail: '.$_SESSION['translator']->out('YOU_HAVE_NEW_MAIL',true),$_SESSION['chatter'], true );
    $sound_recipient .= addSound('new_mail');
  }
  unset($inbox);
} elseif( $private_request = $_SESSION['chatter']->check_private() ) {
  if(function_exists('session_register') && !session_is_registered('invited_from') ) {
    session_register('invited_from');
  }
  $invited_from = $private_request;
  $_SESSION['invited_from'] = $invited_from;
  $TEMPLATE_OUT['js_onload'] .= 'parent.output.privateChatWindow(\''.$_SESSION['chatter']->get_nick().'\',\''.$private_request.'\');';
}

/* Do not load any new line if channel is password protected and the chatter are not authorized */
if(  $_SESSION['channel']->is_password_protected() 
 && !$_SESSION['chatter']->is_authorized_for($_SESSION['channel']->get_name()) 
 && isset($_GET['polling']) )
  die('<html><body onload="parent.serialize_refresh=0"></body></html>');

$_SESSION['channel_buffer']->connect();

if( $lines = $_SESSION['channel_buffer']->get_lines_since( $_SESSION['lastRedLine'] ) )
{
    $max_line_idx = $_SESSION['channel_buffer']->get_max_line_idx();
    $_SESSION['channel_buffer']->disconnect();
    reset($lines);
    $i = $_SESSION['lastRedLine'];
    $moderate_line = '';
    do{
        $i = ++$i % $max_line_idx;
        $current_line   = current($lines);
        if( !is_object($current_line) ){
          if( defined('DEBUG') && DEBUG )
            $js_debug.='alert("'.$current_line.'");';
          continue;
        }
        $line_sender    = $current_line->get_chatter();
        $line_recipient = $current_line->get_recipient();
        
        //whispering to somebody?!
        if( is_object($line_recipient) && $line_recipient->get_nick() == $_SESSION['translator']->out('EVERYBODY'))
          $current_line->set_whispered(false);
          
        if(  $current_line->is_loginMsg() 
        && $current_line->get_login() != $_SESSION['chatter']->get_nick() ){
          $TEMPLATE_OUT['js_update_chatter'] .= 'parent.addNewChatter(\''.$current_line->get_login().'\');';
          if($_SESSION['chatter']->is_friend( $current_line->get_login() ))
            $sound_recipient .= addSound('friend_login');
        }elseif(  $current_line->is_leavingMsg() 
        && $current_line->get_leave() != $_SESSION['chatter']->get_nick() ){
          $TEMPLATE_OUT['js_update_chatter'] .= 'parent.delChatter(\''.$current_line->get_leave().'\');';
          if($_SESSION['chatter']->is_friend( $current_line->get_leave() ))
            $sound_recipient .= addSound('friend_logout');
        }
        
        if( SHOW_CHAT_HISTORY && $current_line->is_loginMsg() 
        && $current_line->get_login() == $_SESSION['chatter']->get_nick() ){
          $all_lines .= '<div style="margin-top:30px;font-size:16px;font-weight:bold">'.$_SESSION['translator']->out('CHANNEL').': '.$_SESSION['channel']->get_name().'</div>';
          $_SESSION['channel_buffer']->connect();
          $chat_history = $_SESSION['channel_buffer']->get_all_lines_in_buffer();
          $_SESSION['channel_buffer']->disconnect();
          array_pop($chat_history);//no need for the last line
          foreach($chat_history as $history_line){
            if($history_line->is_whispered() || ($_SESSION['channel']->is_moderated() && !$history_line->get_approved()))
              continue;
            $history_line_sender    = $history_line->get_sender();
            $history_line_recipient = $history_line->get_recipient();
            $all_lines .= '<div style="margin-left:34px;color: #'.$history_line_sender->get_color().'">'.HTML_BEFORE_LINE;
            $all_lines .= '&nbsp;<span>'.$history_line_sender->get_nick().'</span>';
            if(is_object($history_line_recipient)){
              $all_lines .= '&nbsp;';
              $all_lines .= ($history_line->get_whispered())? 
                            $_SESSION['translator']->out('WHISPERS_TO',true):
                            $_SESSION['translator']->out('SAYS_TO',true);
              $all_lines .= '&nbsp;<span>'.$history_line_recipient->get_nick().'</span>';
            }
            
            $all_lines .= ':&nbsp;';
            $history_line->filter_buffer_output();
            $all_lines .= $history_line->get_said().HTML_AFTER_LINE.'</div>';
          }
          unset($chat_history);
          unset($history_line_sender);
          unset($history_line_recipient);
        }
        //and now here come some 'guards'

        //skip curent line if chatter wants to talk private or it's a whispered line or chatter
        //doesn't want system messages
        if( $_SESSION['chatter']->get_private() 
        && ($line_sender->get_nick()      != $_SESSION['chatter']->get_nick())
        && (@$line_recipient->get_nick()  != $_SESSION['chatter']->get_nick())
        )
           continue;

        if( $_SESSION['chatter']->get_bodies() 
        && !$_SESSION['chatter']->is_friend($line_sender->get_nick())
        && !$_SESSION['chatter']->is_friend(@$line_recipient->get_nick())
        && (@$line_recipient->get_nick()  != $_SESSION['chatter']->get_nick())
        ){
           continue;
        }
        
        
        if( $current_line->get_whispered() 
        && ($line_sender->get_nick()      != $_SESSION['chatter']->get_nick())
        && (@$line_recipient->get_nick()  != $_SESSION['chatter']->get_nick())
        )
           continue;

        if( $_SESSION['chatter']->get_sys_msg() 
        && ($line_sender->get_nick() == strval(STATUS_BOT_NAME)) 
        )
           continue;
         
        if( !$_SESSION['channel']->is_moderated()
        && ($line_sender->get_nick() == $_SESSION['chatter']->get_nick() )
        )
           continue;
        
        if( ($line_sender->get_nick() == strval(STATUS_BOT_NAME))
        && !$current_line->is_info()
        && $current_line->get_whispered()
        && !$current_line->is_invitationMsg()
        && ($line_recipient->get_nick() == $_SESSION['chatter']->get_nick() )
        )
           continue;
           
        //skip line, if sender is ignored by the current chatter
        if( $_SESSION['chatter']->is_ignored( $line_sender->get_nick() ) )
           continue;
           
        if( $current_line->in_private_window() )
           continue;

        //channel moderated? if( $_SESSION['channel']->is_moderated() )
        //line approved?     if( $current_line->get_approved() 
        if( $_SESSION['channel']->is_moderated() )
        {
          //channel is moderated
          if( !$current_line->get_approved() && $_SESSION['chatter']->is_vip() )
            continue; //skip line if current chatter is a vip and line are not approved
            
          if( !$current_line->get_approved() 
              && !$_SESSION['chatter']->is_moderator()
              && $line_sender->get_nick() != strval(STATUS_BOT_NAME)
              )
            continue; //skip line if current a profane chatter, line are not approved, and line isn't from the system-bot

          if( !$current_line->get_approved() && $_SESSION['chatter']->is_moderator()
              && $line_sender->get_nick()    != strval(STATUS_BOT_NAME)
            )
          {
            //the line isn't from a moderator, vip, or system-bot
            $moderate_line  = '
              <form name="approve" class="moderate" action="approve.php" method="post" target="satModeration">
                '.$_SESSION['session_post'].'
                <input name="line" type="hidden" value="'.urlencode(serialize($current_line)).'" />
                <input class="moderate" type="button" value="'.$_SESSION['translator']->out('DISAPPROVE').'" onclick="taggedDiv.style.display=\\\'none\\\'" />
                <input class="moderate" name="moderate" type="submit" value="'.$_SESSION['translator']->out('EDIT').'" onclick="openWindow();blur();this.style.display=\\\'none\\\'" />
              </form>
              <form action="approve.php" method="post" target="dummy" class="moderate">
                '.$_SESSION['session_post'].'
                <input name="line" type="hidden" value="'.urlencode(serialize($current_line)).'" />
                <input class="moderate" name="approve" type="submit" onclick="blur();this.style.display=\\\'none\\\'" value="'.$_SESSION['translator']->out('APPROVE').'" />
              </form>
            ';
            //$moderate_line = preg_replace('/\r\n|\r|\n|<!--.[^-]*-->|  /', '', $moderate_line);
            $moderate_line = preg_replace('/\r\n|\r|\n|  /', '', $moderate_line);
            
            $css_line_class = ' class="unapprovedLine"';
          }
          
          if( $current_line->get_approved() && $_SESSION['chatter']->is_moderator() )
            $css_line_class = ' class="approvedLine"';
        }

        if( $_SESSION['chatter']->is_friend( $line_sender->get_nick()) )
          $friend_class = ' class="friend"';
        else
          $friend_class = '';

        $ranking = $_SESSION['chat']->get_grade_icon( $line_sender );
        $gender  = '';
        if( SHOW_GENDER_ICON )
          $gender=($line_sender->get_gender())? '<img src="'.$_SESSION['template']->get_tmpl_web_path().'/images/icons/'.$line_sender->get_gender().'.gif" width="8" height="8" alt="'.$_SESSION['translator']->out('GENDER').'" /> ':'<img src="'.$_SESSION['template']->get_tmpl_web_path().'/images/dot_clear.gif" width="8" height="8" alt="" /> ';
        $italic = ( $current_line->is_whispered() )? ';font-style:italic':'';
        $all_lines .= '<div'.$css_line_class.' style="color: #'.$line_sender->get_color().$italic.'" onmouseover="setNickname(\\\''.preg_replace( "/\#{3}([^#]*)\#{3}/e", "htmlentities(\$_SESSION['translator']->out('\\1'))", $line_sender->get_nick() ).'\\\');tagDiv(this)">'.HTML_BEFORE_LINE.$moderate_line.$ranking.$gender.'<span'.$friend_class.'>';
        unset($italic);
        if( $line_sender->get_nick()!=STATUS_BOT_NAME 
        && !$line_sender->is_guest()
        && !$_SESSION['channel']->is_moderated() )
        {
          $all_lines .= '<a style="color: #'.$line_sender->get_color().'" href="#" oonclick="return showNotice(event.screenX,event.screenY,\\\''.urlencode($line_sender->get_nick()).'\\\')" onclick="return selectNick(\\\''.$line_sender->get_nick().'\\\',\\\''.$current_line->get_whispered().'\\\')" onmouseover="setNickname(\\\''.$line_sender->get_nick().'\\\')">';
          $all_lines .= $line_sender->get_nick();
          $all_lines .= '</a>';
        } else 
          $all_lines .= $line_sender->get_nick();
        $all_lines .= '</span>';
        if( !is_null($line_recipient) )
        {
          if( $line_recipient->get_nick() == $_SESSION['chatter']->get_nick() 
              && $line_sender->get_nick() != STATUS_BOT_NAME
              && !is_null($_SESSION['chatter']->get_advice())
              && $_SESSION['chatter']->get_advice() != 'quiet')
          {
            if($_SESSION['chatter']->get_advice() == 'alert'){
              $alert_content    = $_SESSION['chat']->get_template('messageWindow');
              $alert_recipient  = 'msgWindow = window.open("","displayWindow","menubar=no,width=350,height=50,scrollbars=no");'.NL;
              $alert_recipient .= 'msgWindow.document.write("'.$alert_content.'");'.NL;
              $alert_recipient .= 'msgWindow.focus();'.NL;
            }else{
              $sound_recipient .= addSound('new_line');
            }
          }
          $all_lines .= '&nbsp;';
          $all_lines .= ($current_line->get_whispered())? 
                        $_SESSION['translator']->out('WHISPERS_TO',true):
                        $_SESSION['translator']->out('SAYS_TO',true);
          $all_lines .= '&nbsp;<span>'.$line_recipient->get_nick().'</span>';
        }
        $all_lines .= ':&nbsp;';
        $current_line->filter_buffer_output();
        $all_lines .= $current_line->get_said().HTML_AFTER_LINE.'</div>';
    }while( next($lines) );

    $_SESSION['lastRedLine'] = intval($i);
    unset($i);
    
    if( empty($all_lines)){
      if(isset($_SESSION['invited_from']) ) die('<html><body onload="parent.serialize_refresh=0;'.$TEMPLATE_OUT['js_onload'].'"></body></html>');
      else die('<html><body onload="parent.serialize_refresh=0"></body></html>');
    }
}else{
	$_SESSION['channel_buffer']->disconnect();
	if( isset($_SESSION['invited_from']) )
	  die('<html><body onload="parent.serialize_refresh=0;'.$TEMPLATE_OUT['js_onload'].'"></body></html>');
	else
	  die('<html><body onload="parent.serialize_refresh=0"></body></html>');
}



unset($lines);
unset($current_line);
unset($line_sender);
unset($lines);
unset($max_line_idx);

if( $login && $_SESSION['channel']->is_password_protected() 
 && !$_SESSION['chatter']->is_authorized_for($_SESSION['channel']->get_name()) )
{
  $all_lines .= '<form action="unlock_channel.php" method="post" target="dummy" style="display:inline"><input class="unlock" type="password" name="password" /><input class="submit" type="submit" value="'.$_SESSION['translator']->out('UNLOCK_CHANNEL',true).'" /><\/form>';
}
$TEMPLATE_OUT['all_lines'] = $all_lines;
$TEMPLATE_OUT['alert_recipient'] = $alert_recipient;
$TEMPLATE_OUT['js_debug'] = $js_debug;
$TEMPLATE_OUT['sound_recipient'] = $sound_recipient;

$_SESSION['template']->get_template();
?>