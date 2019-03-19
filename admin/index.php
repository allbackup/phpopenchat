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
  $Date: 2004/02/24 17:05:18 $
  $Source: /cvsroot/phpopenchat/chat3/admin/index.php,v $
  $Revision: 1.25.2.5 $
*/

//Get default values
require_once('../config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Recipient.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel_Buffer_'.CHANNEL_BUFFER_TYPE.'.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

session_start();
//check if chatter is authorized to get this page
if( !isset($_SESSION['chatter']) )
{
  header('Status: 301');
  header('Location: ../index.php?forceOnTop=1');
  exit;
}

if( !$_SESSION['chatter']->is_operator() )
  die('Access denied.');

/*$template = &new POC_Template();
$_SESSION['template'] = $template;*/
if( count($_POST) == 0 ) {
  header('Content-type: text/html; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));
  $_SESSION['template']->get_cached_content( 60*60*24*7 );//get cached content with a max age of one week  
}
$_SESSION['reload_count'] = 0;//reset chat session expiration time

$all_chatter = array();
$all_chatter_list = '';
$search_value = '';
$success_msg = '';
$TEMPLATE_OUT['moderation_selected'] = '';
$TEMPLATE_OUT['name'] = '';
$TEMPLATE_OUT['password'] = '';
$TEMPLATE_OUT['name_disabled'] = '';
$TEMPLATE_OUT['success'] = '';
$TEMPLATE_OUT['error'] = '';
$TEMPLATE_OUT['message'] = '';

if( isset($_GET['delete']))
{
  //delete chatter ($_GET['delete'] contains the name of chatter)
  $_chatter = POC_Chat::mkinstance_chatter( $_GET['delete'] );

  if( !in_array($_chatter->get_user(),$DEATHLESS_CHATTERS) && $_chatter->delete() )
  {
    $_chatter->del_from_group('chatter');
    $_chatter->del_from_group('vip');
    $_chatter->del_from_group('moderator');
    $_chatter->del_from_group('operator');
    $success_msg = $_SESSION['translator']->out('CHATTER_DELETE_SUCCESS');
  }
  else 
    $success_msg = $_SESSION['translator']->out('CHATTER_DELETE_FAILED');
  unset($_chatter);
}
elseif( isset($_GET['add2group']) )
{
  //set status of chatter ($_GET['set_status'] contains the status, $_GET['nick'] contains the nickname)
  //delete chatter ($_GET['delete'] contains the name of chatter)
  $_chatter = POC_Chat::mkinstance_chatter( $_GET['user'] );
  
  if( $_GET['add2group'] != 'operator' )
  {
    $_chatter->del_from_group('chatter');
    $_chatter->del_from_group('vip');
    $_chatter->del_from_group('moderator');
  }
  if($_chatter->add_to_group( $_GET['add2group']) )
    $success_msg = $_SESSION['translator']->out('GROUP_UPDATE_SUCCESS');
  else 
    $success_msg = $_SESSION['translator']->out('GROUP_UPDATE_FAILED');
  unset($_chatter);
}
elseif( isset($_GET['delfromgroup']) )
{
  $_chatter = POC_Chat::mkinstance_chatter( $_GET['user'] );
 
  if($_chatter->del_from_group($_GET['delfromgroup']) )
    $success_msg = $_SESSION['translator']->out('GROUP_UPDATE_SUCCESS');
  else 
    $success_msg = $_SESSION['translator']->out('GROUP_UPDATE_FAILED');
  unset($_chatter);
}
elseif( isset($_GET['disable']) )
{
  //disable a chatter ($_GET['user'])
  $_chatter = POC_Chat::mkinstance_chatter( $_GET['user'] );
  if( !in_array($_chatter->get_user(),$DEATHLESS_CHATTERS) && $_chatter->disable())
    $success_msg = $_SESSION['translator']->out('CHATTER_DISABLED');
  else 
    $success_msg = $_SESSION['translator']->out('CHATTER_NOT_DISABLED');
  unset($_chatter);
}
elseif( isset($_GET['enable']) )
{
  //disable a chatter ($_GET['user'])
  $_chatter = POC_Chat::mkinstance_chatter( $_GET['user'] );
  if($_chatter->enable())
    $success_msg = $_SESSION['translator']->out('CHATTER_ENABLED');
  else 
    $success_msg = $_SESSION['translator']->out('CHATTER_NOT_ENABLED');
  unset($_chatter);
}

if(isset($_POST['add_channel']))
{
  $chat = &new POC_Chat(CHAT_NAME, $supported_languages);
  //connect to the line buffer of choosen channel
  //$_channel_buffer = &new POC_Channel_Buffer($_POST['name']);
  $chat->connect();
   //TODO: consideration of $_POST['start'] and $_POST['stop']
   $chat->create_channel($_POST['name'], $_POST['type'], $_POST['password'], $_POST['message']);
  $chat->disconnect();
}
elseif(isset($_POST['update_channel']))
{
  $chat = &new POC_Chat(CHAT_NAME, $supported_languages);
  //connect to the line buffer of choosen channel
  //$_channel_buffer = &new POC_Channel_Buffer($_POST['name']);
  $chat->connect();
   //TODO: consideration of $_POST['start'] and $_POST['stop']
   $bool = $chat->update_channel($_POST['name'], $_POST['type'], $_POST['password'], $_POST['message']);
  $chat->disconnect();
  if($bool) $TEMPLATE_OUT['success'] = $_SESSION['translator']->out('SUCCESS_CHANNEL_UPDATE');
  else  $TEMPLATE_OUT['error'] =  $_SESSION['translator']->out('ERROR_CHANNEL_UPDATE');
}

elseif(isset($_POST['del_channel']) 
   || ( isset($_POST['selected_channel']) && isset($_POST['delete_x']) && $_POST['selected_channel'] != ''))
{
  /*$chat = &new POC_Chat(CHAT_NAME, $supported_languages);
  $chat->connect();
   $chat->delete_channel($_POST['name']);
  $chat->disconnect();*/
  $_SESSION['chat']->connect();
  if(isset($_POST['selected_channel']))
    $_SESSION['chat']->delete_channel($_POST['selected_channel']);
  else 
    $_SESSION['chat']->delete_channel($_POST['name']);
  $_SESSION['chat']->disconnect();
}

elseif( isset($_POST['selected_channel']) && isset($_POST['edit_x']) && $_POST['selected_channel'] != '' )
{
  $_channel = &new POC_Channel($_POST['selected_channel']);
  $TEMPLATE_OUT['moderation_selected'] =($_channel->is_moderated())? 'selected="selected"':'';
  $TEMPLATE_OUT['name'] = $_channel->get_name();
  $TEMPLATE_OUT['password'] = $_channel->get_password();
  $TEMPLATE_OUT['message'] = $_channel->get_message();
  $TEMPLATE_OUT['name_disabled'] = 'disabled="disabled"';

}

elseif( (isset($_POST['get_chatter']) && isset($_POST['name']) && $_POST['name'] != '' )
|| isset($_GET['name']) )
{
  if( isset($_POST['name']) )
    $search_value = $_POST['name'];
  else 
    $search_value = $_GET['name'];
    
  $_chat = &new POC_Chat(CHAT_NAME, $supported_languages);
  $_chat->connect();
   $all_chatter = $_chat->get_chatters( null, $search_value);
  $_chat->disconnect();
  if( count($all_chatter) > 0 )
  {
    $all_chatter_list .= NL.TAB.'<table class="chatterList">'.NL;
    $all_chatter_list .= TAB.TAB.'<tbody>'.NL;
    reset( $all_chatter );
    do{
      $_chatter = &new POC_Chatter(STATUS_BOT_NAME);
      $_chatter->set_nick( current( $all_chatter ) );
      if ($_chatter->is_group_member('moderator'))
        $style='moderator';
      elseif($_chatter->is_group_member('vip'))
        $style='vip';
      elseif($_chatter->is_group_member('chatter'))
        $style='chatter';
      else 
        $style='chatter';
        
      $disable = 'disable';
      if( $_chatter->get_db_disabled() == 1 )
      {
        $disabled_image = 'enable_chatter.gif';
        $style = 'disabled';
        $disable = 'enable';
      }
      else
        $disabled_image = 'disable_chatter.gif';
        
      $operator_param = 'add2group';
      $operator_class = 'class="label"';
      $img_prefix     = '';
      $operator_title = 'set to operator';
      if($_chatter->is_operator())
      {
        $operator_param = 'delfromgroup';
        $operator_class = 'class="operator"';
        $img_prefix     = 'non';
        $operator_title = 'unset operator';
      }
        
      $all_chatter_list .= TAB.TAB.TAB.'<tr class="'.$style.'">';
      $all_chatter_list .= '<td><img src="'.$_SESSION['template']->get_theme_path().'/images/icons/'.$style.'.gif" /></td>';
      $all_chatter_list .= '<td '.$operator_class.'>'.$_chatter->get_nick().'</td>';
      $all_chatter_list .= '
      <td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <a class="imageLink" title="delete chatter" href="index.php?name='.$search_value.'&amp;delete='.$_chatter->get_user().'"
onclick="return confirm(\''.$_SESSION['translator']->out('REALLY_QUESTION').'\')"><img src="'.$_SESSION['template']->get_theme_path().'/images/icons/garbage.gif" border="0"/></a>&nbsp;&nbsp;&nbsp;
        <a class="imageLink" title="'.$disable.' chatter" href="index.php?name='.$search_value.'&amp;'.$disable.'=1&amp;user='.$_chatter->get_user().'"><img src="'.$_SESSION['template']->get_theme_path().'/images/icons/'.$disabled_image.'" border="0"/></a>&nbsp;&nbsp;&nbsp;
        <a class="imageLink" title="set to chatter" href="index.php?name='.$search_value.'&amp;add2group=chatter&amp;user='.$_chatter->get_user().'"><img src="'.$_SESSION['template']->get_theme_path().'/images/icons/status2chatter.gif" border="0"/></a>
        <a class="imageLink" title="set to moderator" href="index.php?name='.$search_value.'&amp;add2group=moderator&amp;user='.$_chatter->get_user().'"><img src="'.$_SESSION['template']->get_theme_path().'/images/icons/status2moderator.gif" border="0"/></a>
        <a class="imageLink" title="set to vip" href="index.php?name='.$search_value.'&amp;add2group=vip&amp;user='.$_chatter->get_user().'"><img src="'.$_SESSION['template']->get_theme_path().'/images/icons/status2vip.gif" border="0"/></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <a class="imageLink" title="'.$operator_title.'" href="index.php?name='.$search_value.'&amp;'.$operator_param.'=operator&amp;user='.$_chatter->get_user().'"><img src="'.$_SESSION['template']->get_theme_path().'/images/icons/status2'.$img_prefix.'operator.gif" border="0"/></a>&nbsp;&nbsp;&nbsp;
        <a class="imageLink" title="send email" href="mailto:'.$_chatter->get_email().'"><img src="'.$_SESSION['template']->get_theme_path().'/images/icons/newmail.gif" border="0"/></a>&nbsp;&nbsp;&nbsp;
        <a class="imageLink" title="about chatter" href="#" onclick="myArray = new Array(\''.$_chatter->get_nick().'\',\''.$_chatter->get_lastActive().'\',\''.$_chatter->get_regTime().'\',\''.$_chatter->get_db_lastChannel().'\',\''.$_chatter->get_last_Host().'\',\''.$_chatter->get_last_IP().'\',\''.$_chatter->get_last_Referer().'\',\''.$_chatter->get_last_UserAgent().'\',\''.$_chatter->get_last_SessionId().'\',\''.$_chatter->get_pictureURL().'\');show_details(myArray,event.screenX,event.screenY);return false"><img src="'.$_SESSION['template']->get_theme_path().'/images/icons/info.gif" border="0"/></a>
      </td>';
      $all_chatter_list .= '<td></td>';
      $all_chatter_list .= '</tr>'.NL;
      unset($_chatter);
    }while( next($all_chatter) );
    $all_chatter_list .= TAB.TAB.'</tbody>'.NL;
    $all_chatter_list .= TAB.'</table>'.NL;
  }
}
$_SESSION['chat']->connect();
if( isset($_POST['selected_channel']) && isset($_POST['move_x']) )
 $_SESSION['chat']->move_channel_to_top($_POST['selected_channel']);

 $TEMPLATE_OUT['channels_option_list'] = $_SESSION['chat']->get_channels_option_list();
$_SESSION['chat']->disconnect();

unset($_chat);

$TEMPLATE_OUT['search_value'] = $search_value;
$TEMPLATE_OUT['success_msg']  = $success_msg;
$TEMPLATE_OUT['all_chatter_list'] = $all_chatter_list;
$_SESSION['template']->get_template('index');
?>