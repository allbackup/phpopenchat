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
  $Source: /cvsroot/phpopenchat/chat3/userpage.php,v $
  $Revision: 1.20.2.8 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Guestbook.inc');
require_once(POC_INCLUDE_PATH.'/class.Guestbook_Post.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

session_start();

/*check if chatter is authorized to get this page
if( !isset($_SESSION['chatter']) )
  die('Login first!');*/
  
if( !isset($_SESSION['chat']) )
{
  header('Status: 302');
  header('Location: index.php');
  exit;
}
if ( !isset($_SESSION['template']) )
{
	$template = &new POC_Template();
	$_SESSION['template'] = $template;
}

if(!isset($_GET['rand'])) {
  header('Content-type: text/html; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));
  $_SESSION['template']->get_cached_content( 60*10 );//get cached content with a max age of 10 minutes  
}
$_SESSION['reload_count'] = 0;//reset chat session expiration time

if( isset($_GET['nick']) )
  $_POST['nick'] = $_GET['nick'];

if( !isset($_POST['nick']) )
  die('No nickname given!');

$nickname = $_POST['nick'];
$_chatter = &new POC_Chatter(STATUS_BOT_NAME);
$_chatter->set_nick($nickname);
$_chatter->init_additional_profile_data();
//if( isset($_SESSION['chatter']) && $nickname != $_SESSION['chatter']->get_nick() )
  $_chatter->count_hit('userpage');
$pictureURL     = $_chatter->get_pictureURL();
$homePageURL    = $_chatter->get_homePageURL();
$TEMPLATE_OUT['age'] = $_chatter->get_age();
$gender         = $_chatter->get_gender();
$TEMPLATE_OUT['user_interests'] = $_chatter->get_interests();
$TEMPLATE_OUT['user_motto']     = $_chatter->get_motto();
$TEMPLATE_OUT['hit_count']      = $_chatter->get_hit_count('userpage');
$TEMPLATE_OUT['lastActive']     = $_chatter->get_lastActive();
$line_count     = $_chatter->get_hit_count('line');
$login_count    = $_chatter->get_hit_count('login');

if( $gender != '' )
  $gender = ($gender=='f')? $_SESSION['translator']->out('FEMALE'):$_SESSION['translator']->out('MALE');

$TEMPLATE_OUT['gender'] = $gender;
$email = $_chatter->get_email();
if( $email == '' ) $email = ADMIN_MAIL_ADDRESS;//in case of user page of system bot
$TEMPLATE_OUT['registrationTime'] = $_chatter->get_regTime();

$TEMPLATE_OUT['lines_per_day']  = '';
$TEMPLATE_OUT['logins_per_day'] = '';
//days since registration
if( preg_match('/[^0-9]*([0-9]+)-([0-9]+)-([0-9]+)[^0-9]*/', $TEMPLATE_OUT['registrationTime'], $parts) )
{
  $nowdate = mktime(0,0,0,date('m'),date('d'),date('Y'));
  $regdate = mktime(0,0,0,$parts[2],$parts[3],$parts[1]);
  // calculate the age in days
  $days_registered = intval(($nowdate-$regdate)/(60*60*24));
  
  if($days_registered>0)
  {
    $TEMPLATE_OUT['lines_per_day']  = round(($line_count / $days_registered),4);
    $TEMPLATE_OUT['logins_per_day'] = round(($login_count / $days_registered),4);
  }
}
  
$icqNumber = $_chatter->get_icqNumber();
$aimNickname = $_chatter->get_aimNickname();
$yimNickname = $_chatter->get_yimNickname();
$friends = array();
$friends = $_chatter->get_friends();
$TEMPLATE_OUT['friends_list'] = '';
if( count($friends) > 0 )
{
  reset($friends);
  do {
    $TEMPLATE_OUT['friends_list'] .= current($friends).', ';
  }while( next($friends) );
  $TEMPLATE_OUT['friends_list'] = preg_replace('/, $/', '', $TEMPLATE_OUT['friends_list']);
}

$user_pic='';
if( $pictureURL != '' )
  $user_pic='<img src="'.$pictureURL.'" width="150" height="200" alt="" />';

$icon_path = $_SESSION['template']->get_theme_path() . '/images/icons/';
if( $_chatter->is_online() || $nickname == STATUS_BOT_NAME)
  $TEMPLATE_OUT['onlineStatusImg'] = '<img title="Status" src="'.$icon_path.'chatter_online.gif" alt="online status" align="middle" />';
else
  $TEMPLATE_OUT['onlineStatusImg'] = '<img title="Status" src="'.$icon_path.'chatter_offline.gif" alt="offline status" align="middle" />';

$TEMPLATE_OUT['icq'] = '';
if( intval($icqNumber) >= 1000  )
  $TEMPLATE_OUT['icq'] = '<a class="imageLink" title="'.$_SESSION['translator']->out('ICQ_NUMBER').': '.$icqNumber.'" href="http://wwp.mirabilis.com/'.$icqNumber.'" target="_blank" style="background:none">
              <img hspace="2" src="http://wwp.icq.com/scripts/online.dll?icq='.$icqNumber.'&amp;img=5" align="middle" alt="online status for '.$nickname.'" height="18" width="18" border="0" />
          </a>';

$TEMPLATE_OUT['aim'] = '';
if( $aimNickname != '' )
  $TEMPLATE_OUT['aim'] = '<img title="'.$_SESSION['translator']->out('AIM_NICKNAME').': '.$aimNickname.'" src="'.$icon_path.'aim.gif" alt="'.$aimNickname.'" align="middle" />&nbsp;&nbsp;';

$TEMPLATE_OUT['yahoo'] = '';
if( $yimNickname != '' )
  $TEMPLATE_OUT['yahoo'] = '<img title="'.$_SESSION['translator']->out('YIM_NICKNAME').': '.$yimNickname.'" src="'.$icon_path.'yahoo.gif" alt="'.$yimNickname.'" align="middle" />';
  
$TEMPLATE_OUT['homePageLink'] = '';
if( $homePageURL != '' )
  $TEMPLATE_OUT['homePageLink'] = '<a class="imageLink" title="'.$homePageURL.'" href="jump.php?url='.$homePageURL.'" style="background: none" target="_blank"><img src="'.$icon_path.'home.gif" alt="'.$homePageURL.'" align="middle" border="0" /></a>';

$TEMPLATE_OUT['emailLink'] = '';
if(!$_chatter->get_hide('email'))
  $TEMPLATE_OUT['emailLink'] = '<a class="imageLink" title="'.$email.'" href="mailto:'.$email.'" style="background:none"><img src="'.$icon_path.'email.gif" alt="'.$email.'" align="middle" border="0" /></a>&nbsp;&nbsp;';

$TEMPLATE_OUT['grade'] = ($_chatter->get_grade()!='')? $_SESSION['translator']->out($_chatter->get_grade()):'';
$TEMPLATE_OUT['user_pic'] = $user_pic;

$TEMPLATE_OUT['misc'] = '';
$TEMPLATE_OUT['misc'] = array();
$TEMPLATE_OUT['misc'] = $_chatter->get_profile_misc();

/*
* Guestbook stuff
*
*/
function gender_icon ($gender)
{
  return(file_exists($_SESSION['template']->get_tmpl_sys_path().'/images/icons/'.$gender.'.gif'))?
  '<img src="'.$_SESSION['template']->get_tmpl_web_path().'/images/icons/'.$gender.'.gif" width="8" height="8" alt="'.$_SESSION['translator']->out('GENDER').'" />':'';
}

function grade_icon (&$sender)
{
  if($sender->is_group_member('operator'))
    return '<img src="'.$_SESSION['template']->get_tmpl_web_path().'/images/icons/grade_operator.gif" title="'.$_SESSION['translator']->out('OPERATOR').'" alt="'.$_SESSION['translator']->out('OPERATOR').'" align="middle" />';
    
  $grade=strtolower($sender->get_grade());
  return(file_exists($_SESSION['template']->get_tmpl_sys_path().'/images/icons/'.$grade.'.gif'))?
  '<img src="'.$_SESSION['template']->get_tmpl_web_path().'/images/icons/'.$grade.'.gif" alt="'.$_SESSION['translator']->out('GRADE').'" />':'';
}

function bday_icon()
{
  return '<img src="'.$_SESSION['template']->get_tmpl_web_path().'/images/icons/smileys/birthday.gif" align="middle" />';
}

$TEMPLATE_OUT['guestbook_posts'] = array();
$guestbook = &new POC_Guestbook( $_chatter ); 
if( isset($_GET['delete_post']) )
  $guestbook->del_post( $_GET['sender'],$_GET['time'] );

$posts = $guestbook->get_posts();
$c=0;
foreach ( $posts as $post )
{
  $current = unserialize( $post['POST'] );
  if( !is_object($current) ) continue;
  $sender = $current->get_sender();
  $TEMPLATE_OUT['guestbook_posts'][$c]['gender_icon'] = gender_icon($sender->get_gender());
  $TEMPLATE_OUT['guestbook_posts'][$c]['sender'] = $sender->get_nick();
  $TEMPLATE_OUT['guestbook_posts'][$c]['time'] = $current->get_time();
  $TEMPLATE_OUT['guestbook_posts'][$c]['birthday_icon'] = ($sender->has_birthday())? bday_icon():'';
  $TEMPLATE_OUT['guestbook_posts'][$c]['grade'] = grade_icon($sender);
  $TEMPLATE_OUT['guestbook_posts'][$c]['db_time'] = $current->get_db_time();
  $TEMPLATE_OUT['guestbook_posts'][$c]['content'] = $current->get_said();
  if( isset($_SESSION['chatter']) && $_SESSION['chatter']->is_online() 
    && $_chatter->get_nick() == $_SESSION['chatter']->get_nick())
    $TEMPLATE_OUT['guestbook_posts'][$c]['delete'] = '<a class="imageLink" title="'.$_SESSION['translator']->out('DELETE').'" href="userpage.php?nick='.urlencode($_POST['nick']).'&amp;delete_post=1&amp;time='.$current->get_db_time().'&amp;sender='.urlencode($sender->get_nick()).'&amp;rand='.rand(0,99).'&amp;'.$_SESSION['session_get'].'#gb"><img src="'.$icon_path.'/trash.gif" alt="" border="0" align="middle" /></a>';
  else 
    $TEMPLATE_OUT['guestbook_posts'][$c]['delete'] = '';
  $c++;
}
unset($_chatter);
$_SESSION['template']->get_template();
?>