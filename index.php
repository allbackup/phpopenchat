<?php // -*-php-*-
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
  $Source: /cvsroot/phpopenchat/chat3/index.php,v $
  $Revision: 1.74.2.32 $
*/
// Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH . '/adodb/adodb.inc.php');

require_once(POC_INCLUDE_PATH . '/class.Chat.inc');
require_once(POC_INCLUDE_PATH . '/class.Chatter.inc');
require_once(POC_INCLUDE_PATH . '/class.Line.inc');
require_once(POC_INCLUDE_PATH . '/class.Channel.inc');
require_once(POC_INCLUDE_PATH . '/class.Channel_Buffer_' . CHANNEL_BUFFER_TYPE . '.inc');
require_once(POC_INCLUDE_PATH . '/class.Template.inc');
require_once(POC_INCLUDE_PATH . '/class.Translator.inc');
require_once(POC_INCLUDE_PATH . '/class.Logger.inc');
require_once(POC_INCLUDE_PATH . '/class.HttpNegotiation.inc');

function session_error($errno, $errmsg, $filename, $linenum, $vars)
{
    POC_Chat::display_error($errno, $errmsg, $filename, $linenum, $vars, POC_SESSION_ERROR);
} 
function db_error($errno, $errmsg, $filename, $linenum, $vars)
{
    POC_Chat::display_error($errno, $errmsg, $filename, $linenum, $vars, POC_DB_ERROR);
} 

set_error_handler('session_error');
/*don't start the the session, if we are in postnuke context*/
if (!function_exists('pnUserGetVar')) {
    session_start();
} 
restore_error_handler();

$jScript = '';
$operator_passwd = '';
$chatters_online_list = '';
$_tmp = (isset($_SESSION['chatter'])&&is_object($_SESSION['chatter']))? $_SESSION['chatter']->get_user():'';
if (!isset($_GET['nickname']))
    $_GET['nickname'] = (isset($_COOKIE['poc_nick']))? $_COOKIE['poc_nick']:$_tmp;
if (!isset($_GET['password']))
    $_GET['password'] = (isset($_COOKIE['poc_password']))? $_COOKIE['poc_password']:$_tmp; //it's a fake, only to show some stars in the password field
unset($_tmp);

function check_private_icon($nick)
{
    global $ACCEPTED_MIME_TYPES;
    $smiley_dir = '/images/icons/chatter';
    for ($i = 0;$i < count($ACCEPTED_MIME_TYPES);$i++) {
        preg_match('#image/[x\-]?(.*)#', $ACCEPTED_MIME_TYPES[$i], $parts);
        $file_extension = $parts[1];
        $smiley_path = $smiley_dir . '/' . strtolower($nick) . '.' . $file_extension;
        if (file_exists($_SESSION['template']->get_tmpl_sys_path() . $smiley_path))
            return '<img src="' . $_SESSION['template']->get_tmpl_web_path() . $smiley_path . '" align="middle" alt="' . $_SESSION['translator']->out('PRIVATE_IMAGE') . '" />';
    }

    return '&nbsp;';
} 

if (!isset($_SESSION['chat']) || !is_object($_SESSION['chat'])) {
    if (!isset($_SESSION['chatter']) && function_exists('session_register')) {
        session_register('chatter');
    } 
    if (!isset($_SESSION['template']) && function_exists('session_register')) {
        session_register('template');
    } 
    if (function_exists('session_register')) {
        session_register('chat', 'translator', 'channel', 'channel_buffer', 'lastRedLine', 'mailbox', 'current_mailbox_type', 'curr_mail_idx', 'inbox_count_new', 'outbox_count_new', 'trash_count_new', 'session_get', 'session_post', 'reload_count', 'logger', 'autologin_directly','httpneg');
    } 
    if (AUTOLOGIN_DIRECTLY && is_null($_SESSION['autologin_directly'])) {
        $_SESSION['autologin_directly'] = true;
    } 

    $reload_count = 0;
    $session_get = session_name() . '=' . session_id();
    $_SESSION['session_get'] = $session_get;
    $session_post = '<input type="hidden" name="' . session_name() . '" value="' . session_id() . '" />';
    $_SESSION['session_post'] = $session_post;
    $logger = &new POC_Logger();
    $_SESSION['logger'] = $logger;
    $chat = &new POC_Chat(strval(CHAT_NAME), $supported_languages);
    $_SESSION['chat'] = $chat;
    $translator = &new POC_Translator($_SESSION['chat']->get_language());
    $_SESSION['translator'] = $translator;
    $httpneg = &new HttpNegotiation();
    $_SESSION['httpneg'] = $httpneg;
    
    $_SESSION['chat']->set_deathless_chatters($DEATHLESS_CHATTERS);
    if (isset($_SERVER['HTTP_REFERER'])) {
        $_SESSION['chat']->set_referer($_SERVER['HTTP_REFERER']);
    } 
    set_error_handler('db_error');
    $_SESSION['chat']->connect();
    restore_error_handler();
    $_SESSION['chat']->alter_db_schema();
    $_SESSION['chat']->make_clean(); 
    // Set operator password
    $operator_passwd = $_SESSION['chat']->set_operator_passwd();
    $_SESSION['chat']->disconnect();
} 

if (isset($_GET['pnlogin']) || isset($_GET['use_db_instance']) ){

    $_nickname = (isset($_GET['use_db_instance']))? $_GET['use_db_instance']:$_GET['pnlogin'];
    // here a postnuke user has a chatter object already in the db
    // this object was created by the first request from postnuke enviroment
    // see below if( function_exists('pnUserGetVar') )...
    set_error_handler('db_error');
    $_SESSION['chat']->connect();
    restore_error_handler();
    $_SESSION['chatter'] = $_SESSION['chat']->get_chatter_instance($_nickname);
    if (!is_object($_SESSION['chatter']) || $_SESSION['chatter']->db_instance_is_outdated()){
        unset($_SESSION['chatter']);
    } else {
        $_SESSION['chatter']->mkinstance_clean();
        $_SESSION['chat']->set_show_profile(false); //profile data are managed by PN or other application
    } 
    $_SESSION['chat']->disconnect();
}

if( isset($_GET['language']) && in_array($_GET['language'], $supported_languages) )
{
  $_SESSION['chat']->set_language($_GET['language']);
  $_SESSION['translator']->set_language($_GET['language']);
}

if (!isset($_SESSION['template'])) {
    $template = &new POC_Template();
    $_SESSION['template'] = $template;
    
    if (isset($_SESSION['chatter'])){
      
      $_SESSION['template']->set_theme($_SESSION['chatter']->get_theme());
    }
    unset($theme);

    if (function_exists('pnUserGetVar')) {
        // this is a request from the postnuke enviroment
        if (pnUserLoggedIn()) {
            // register or update POC userdata
            $_chatter = POC_Chat::mkinstance_chatter(pnUserGetVar('uname'), true);
            $poc_current_chatter = $_chatter;
			
            $_chatter->set_user(pnUserGetVar('uname'));
            $_chatter->set_email(pnUserGetVar('email')); //is hidden by default
            $_chatter->set_name(pnUserGetVar('name'));
            $_chatter->set_homePageURL(pnUserGetVar('url'));
            $_chatter->set_icqNumber(pnUserGetVar('user_icq'));
            $_chatter->set_motto(pnUserGetVar('user_sig'));
            $_chatter->set_aimNickname(pnUserGetVar('user_aim'));
            $_chatter->set_yimNickname(pnUserGetVar('user_yim'));
            $_chatter->set_interests(pnUserGetVar('user_intrest'));
			
            if (!$_chatter->is_registered()) $_chatter->register();

            $data   = array();
            $data[] = $_SESSION['translator']->out('MISCELLANEOUS');
            $data[] = pnUserGetVar('bio');
            $_chatter->insert_profile_misc($data);

            /* setup group rights */
            if (pnSecAuthAction(0, 'Blocks::', '::', ACCESS_ADMIN)) {
                $_chatter->add_to_group('operator');
            } 
            
            /* setup language settings */
            if( $pn_lang = pnUserGetLang() ){
              $_chatter->set_preferred_language($pn_lang);
            }
            
            /* setup theme */
            $pnTheme = pnUserGetTheme();
            if( in_array($pnTheme, $_SESSION['template']->get_theme_list()) ) {
              $_chatter->set_theme( $pnTheme );
              $_SESSION['template']->set_theme( $pnTheme );
            }
            
            if( $poc_current_chatter != $_chatter ){
              $_chatter->update();
            }
            unset($poc_current_chatter);
			
            //$_chatter->set_db_instance_lifetime();
            $_chatter->mkinstance_persist();
            unset($_chatter);
            $poc_web_root = $_SESSION['template']->get_poc_web_root(); 
            // clean PN session
            unset($_SESSION['chat']); 
            // unset($_SESSION['chatter']);
            unset($_SESSION['reload_count']);
            unset($_SESSION['template']);
            unset($_SESSION['translator']);
            unset($_SESSION['logger']);
            unset($_SESSION['session_post']);
            unset($_SESSION['session_get']);

            header('Status: 301');
            header('Location: ' . $poc_web_root . '/index.php?pnlogin=' . pnUserGetVar('uname'));
            exit;
        } else {
            $_SESSION['template']->get_template('pn_login_failure');
        } 
    } 
} 
//$TEMPLATE_OUT['lang_switch'] = $_SESSION['chat']->get_lang_switch();

if ( isset($_POST['account_data']) ||
(isset($_SESSION['chatter']) 
 && is_object($_SESSION['chatter'])
 && !$_SESSION['chatter']->is_kicked() 
 && !$_SESSION['chatter']->is_disabled() 
 && (AUTOLOGIN_DIRECTLY && $_SESSION['autologin_directly'] && !isset($_GET['no_autologin'])))) {

    if( file_exists(POC_BASE.DELI.'install.php') ){
      POC_Chat::display_error(0, '
          <span style="font-size:14px;">Congratulations, the installation is complete but<br />
            <span style="font-weight:bold">
              please remember to <span style="text-decoration:underline">delete install.php</span>
            </span>
            before you start with your community!
          </span>
        ', __FILE__, __LINE__);
    }

    /*
     * Create a new chatter to check account data
     * Object chatter has no nick, if
     *  -the password doesn't match
     *  -the nick contains incorrect characters
     *  -the nick is too long
     */
    if (isset($_POST['nick']) && $_POST['nick'] == strval(STATUS_BOT_NAME))
        unset($_POST['nick']);

    if (!isset($_SESSION['chatter']) || $_SESSION['chatter']->is_guest()) {
        if (!POC_Chat::mkinstance_channel($_POST['channel']))
            die('Channel doesn\'t exists!');
        $_chatter = &new POC_Chatter($_POST['nick'], $_POST['password']);
    } else {
        if (!isset($_POST['channel']))
            $_POST['channel'] = ENTRY_CHANNEL;
        if (!POC_Chat::mkinstance_channel($_POST['channel']))
            die('Channel doesn\'t exists!');
        $_chatter = $_SESSION['chatter'];
    } 

    if (!is_null($_chatter->get_nick()) || isset($_SESSION['chatter'])) {
        if (!isset($_SESSION['chatter']) || $_SESSION['chatter']->is_guest())
            $_SESSION['chatter'] = $_chatter;

        if (isset($_POST['storeAccountData'])) {
            setcookie('poc_nick', $_POST['nick'], COOKIE_EXPIRE, COOKIE_PATH, COOKIE_DOMAIN, COOKIE_SECURE);
            setcookie('poc_password', $_POST['password'], COOKIE_EXPIRE, COOKIE_PATH, COOKIE_DOMAIN, COOKIE_SECURE);
        } 
        // connect to the line buffer of choosen channel
        $channel_buffer = &new POC_Channel_Buffer($_POST['channel']);
        $_SESSION['channel_buffer'] = $channel_buffer;

        $_SESSION['channel_buffer']->connect();
        $lastRedLine = $_SESSION['channel_buffer']->get_cur_line_idx();
        $_SESSION['lastRedLine'] = $lastRedLine;

        $max_lines = $_SESSION['channel_buffer']->get_max_line_idx();
        if( defined('SHOW_CHAT_HISTORY') && SHOW_CHAT_HISTORY && $max_lines>SHOW_CHAT_HISTORY){
          $_SESSION['lastRedLine'] = ($_SESSION['lastRedLine']+($max_lines-SHOW_CHAT_HISTORY)) % $max_lines;
        }
        unset($max_lines);
        $_SESSION['channel_buffer']->disconnect();

        $_SESSION['chat']->connect();
        $_SESSION['chat']->create_private_channel($_chatter->get_nick(true));
        $_SESSION['chat']->disconnect();

        $banned_msg = '';
        if ($_SESSION['chatter']->is_banned($_POST['channel'])) {
            $banned_msg = ' ###BANNED_MSG###';
            $_SESSION['chatter']->join_channel($_SESSION['chatter']->get_nick());
        } 

        if (!$_SESSION['chatter']->already_seen_today())
            $_SESSION['chatter']->count_hit('login');

        $_SESSION['chatter']->refresh();
        $_SESSION['chatter']->set_grade($GRADES);
        $_SESSION['template']->set_theme($_SESSION['chatter']->get_theme()); 
        // hey, the chatter is authorized
        $_SESSION['chatter']->go_online($_SESSION['channel']->get_name()); 
        // we have to say hello in the current channel first»
        $bot = &new POC_Chatter(strval(STATUS_BOT_NAME));

        $said = $_SESSION['chatter']->get_nick(true) . ' ###JOINS_THE_CHAT###';
        $said .= $banned_msg;
        $line = &new POC_Line($bot, $said);
        $line->set_login($_SESSION['chatter']->get_nick(true));

        $_SESSION['channel_buffer']->connect(); 
        // get current line number within channel buffer
        $_SESSION['channel_buffer']->put_line($line);
        $_SESSION['channel_buffer']->disconnect();
        if ($_SESSION['channel']->get_message() != '') {
            $_SESSION['chat']->write_sys_msg('<br />' . $_SESSION['channel']->get_message(), $_SESSION['chatter'], true);
        } 

        /* if current user has a preferred language, we use this language */
        if( $pref_lang = $_SESSION['chatter']->get_preferred_language() ){
          $_SESSION['translator']->set_language($pref_lang);
        }

        unset($pref_lang);
        unset($line);
        unset($line_message);
        unset($bot);
        unset($said);
        unset($_SESSION['in']);

        header('Status: 301');
        header('Location: frameset.php?' . session_name() . '=' . session_id());

        exit;
    } else {
        unset($_SESSION['channel']);
        unset($_chatter);
    } 
} else {
    header('Content-type: text/html; charset=' . $_SESSION['translator']->out('CHARACTER_ENCODING'));
    $_SESSION['template']->get_cached_content(60 * 2); //get cached content with a max age of 2 minutes
} 

$TEMPLATE_OUT['lang_switch'] = $_SESSION['chat']->get_lang_switch();

set_error_handler('db_error');
if (!$_SESSION['chat']->connect()) {
    restore_error_handler();
    unset($_SESSION['chat']);
    unset($_SESSION['chatter']);
    unset($_SESSION['channel_buffer']);
    unset($_SESSION['lastRedLine']);

    header('Status: 301');
    header('Location: test.php');
    exit;
} 
restore_error_handler();

$chatters_online = array();
$chatters_online = $_SESSION['chat']->get_chatters('%');
$count_chatters_online = count($chatters_online);
if ($count_chatters_online > 0) {
    $td_count = 0;
    for($i = 0;$i < $count_chatters_online;$i++) {
        $td_count++;
        if ($i == 0 || ($i % COL_COUNT_CHATTER_LIST) == 0) $chatters_online_list .= NL . TAB . '<tr>';
        $chatters_online_list .= NL . TAB . TAB . '<td class="chatterTableImgCell">' . check_private_icon($chatters_online[$i]) . '</td>
     <td class="chatterTable">&nbsp;' . preg_replace("/\#{3}([^#]*)\#{3}/e", "htmlentities(\$_SESSION['translator']->out('\\1'))", $chatters_online[$i]) . '&nbsp;</td>';
        if ($i > 0 && ($i % COL_COUNT_CHATTER_LIST) == 0) {
            $td_count = 0;
            $chatters_online_list .= NL . TAB . '</tr>';
        } 
    } 
    for ($i = $td_count; $i < COL_COUNT_CHATTER_LIST; $i++) {
        $chatters_online_list .= NL . TAB . TAB . '<td colspan="2"></td>';
    } 
    if ($td_count > 0) $chatters_online_list .= NL . TAB . '</tr>';
} else
    $chatters_online_list = '<tr><td>&nbsp;</td></tr>';

$TEMPLATE_OUT['count_chatters_online'] = $count_chatters_online; 
// get statistics
$TEMPLATE_OUT['online_count_last24h'] = $_SESSION['chat']->get_online_count_last24h();
$TEMPLATE_OUT['online_time_avg'] = round($_SESSION['chat']->get_online_time_avg() / (60 * 60 * 24), 3);
$TEMPLATE_OUT['registered_count'] = $_SESSION['chat']->get_registered_count();
$TEMPLATE_OUT['last_registered'] = array();
$last_registered_user = $_SESSION['chat']->get_last_registered();
$TEMPLATE_OUT['last_registered']['NICK'] = $last_registered_user[0]['NICK'];
$TEMPLATE_OUT['last_registered']['REGTIME'] = $last_registered_user[0]['REGTIME'];
$TEMPLATE_OUT['mail_count'] = $_SESSION['chat']->get_mail_count();
$TEMPLATE_OUT['mail_count_last_24h'] = $_SESSION['chat']->get_mail_count_last_24h();
$TEMPLATE_OUT['option_list_of_channels'] = $_SESSION['chat']->get_channels_option_list(CHANNEL_SELECTED);
$_SESSION['chat']->disconnect();
// unset objects in session
// unset($_SESSION['chatter']);
unset($_SESSION['channel_buffer']);
unset($_SESSION['lastRedLine']);
if (AUTOLOGIN_DIRECTLY && !isset($_GET['no_autologin'])) {
    $_SESSION['autologin_directly'] = true;
}

$jump = (isset($_GET['jump']))? $_GET['jump']:'index.php';

if (isset($_GET['onTop']))
    $jScript .= '
  if( opener ) {
    /*click on exit within satellit*/
    opener.parent.location.href="' . $jump . '";
    window.close();
  }
  else {
    //alert(\'debug\');
    top.location.href="' . $jump . '";
  }
  ';
if (isset($_GET['forceOnTop']))
    $jScript .= '
     top.location.href="' . $jump . '";
   ';

$TEMPLATE_OUT['disable'] = '';
if (isset($_SESSION['chatter']) && !AUTOLOGIN_DIRECTLY && !$_SESSION['chatter']->is_guest()) {
    $TEMPLATE_OUT['disable'] = 'disabled="disabled"';
} 

$TEMPLATE_OUT['spy_icon'] = ( defined('ALLOW_SPYING') && ALLOW_SPYING )? 
'<a class="imageLink" title="'.$_SESSION['translator']->out('SPY_THIS_CHANNEL').'" href="#" onclick="spy(document.forms[0].elements[\'channel\'].options[document.forms[0].elements[\'channel\'].selectedIndex].value)">
  <img style="border:0;background-image:none" src="'.$_SESSION['template']->get_theme_path().'/images/icons/watch.gif" width="18" height="12" alt="'.$_SESSION['translator']->out('SPY_THIS_CHANNEL').'" />
</a>':'';

$TEMPLATE_OUT['nickname'] = '';
$TEMPLATE_OUT['greeting'] = '';
if (isset($_SESSION['chatter'])) {
    $TEMPLATE_OUT['nickname'] = $_SESSION['chatter']->get_nick() . ':';
    $TEMPLATE_OUT['greeting'] = $_SESSION['translator']->out('GREETING');
} 
$TEMPLATE_OUT['jScript'] = $jScript;
$TEMPLATE_OUT['operator_passwd'] = $operator_passwd;
$TEMPLATE_OUT['chatters_online_list'] = $chatters_online_list;

//nocaching headers
header ('Cache-Control: private, pre-check=0, post-check=0, max-age=0');
header ('Expires: ' . gmdate('D, d M Y H:i:s', time()) . ' GMT');
header ('Last-Modified: ' . gmdate('D, d M Y H:i:s') . ' GMT');
$_SESSION['template']->get_template('index');
?>