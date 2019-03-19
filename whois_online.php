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
  $Date: 2004/02/12 13:39:11 $
  $Source: /cvsroot/phpopenchat/chat3/whois_online.php,v $
  $Revision: 1.10.2.4 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

session_start();

//check if chatter is authorized to get this page
if( !isset($_SESSION['chatter']) )
  die('Login first!');

header('Content-type: text/html; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));
$_SESSION['template']->get_cached_content( 60 );//get cached content with a max age of one minute
$_SESSION['reload_count'] = 0;//reset chat session expiration time
$chatters_online_list = '';
function check_private_icon( $nick )
{
  global $ACCEPTED_MIME_TYPES;
  $smiley_dir  = '/images/icons/chatter';
  for ($i=0;$i<count($ACCEPTED_MIME_TYPES);$i++)
  {
    preg_match('#image/[x\-]?(.*)#',$ACCEPTED_MIME_TYPES[$i], $parts);
    $file_extension = $parts[1];
    $smiley_path = $smiley_dir.'/'.strtolower($nick).'.'.$file_extension;
    if( file_exists($_SESSION['template']->get_tmpl_sys_path().$smiley_path) )
      return '<img title="'.$_SESSION['translator']->out('OPEN_USER_PAGE').'" src="'.$_SESSION['template']->get_tmpl_web_path().$smiley_path.'" align="middle" alt="'.$_SESSION['translator']->out('PRIVATE_IMAGE').'" border="0" />';
  }
  
  return '';
}

$_SESSION['chat']->connect();
 $chatters_online = array();
 $chatters_online = $_SESSION['chat']->get_online_chatter();
 $count_chatters_online = count($chatters_online);
 if( $count_chatters_online > 0 )
 {
/*   reset($chatters_online);
   do{
     $key = key($chatters_online);
     $current = current($chatters_online);
     if( ($key % COL_COUNT_CHATTER_LIST) == 0)
       $chatters_online_list .= NL.TAB.'<tr>';
*/
   $td_count = 0;
   for($i=0;$i<$count_chatters_online;$i++)
   {
     $current = $chatters_online[$i];
     $td_count++;
     if($i==0 || ($i % COL_COUNT_CHATTER_LIST) == 0) $chatters_online_list .= NL.TAB.'<tr>';

     $prefix='';
     $postfix='';
     if( $_SESSION['chatter']->is_friend($current['NICK']) )
     {
       $prefix='<strong>';
       $postfix='</strong>';
     }

     $chatters_online_list .= NL.TAB.TAB.'<td class="chatterTableImgCell" style="padding-left: 3px;border-right: 1px solid yellow;">&nbsp;';
     //$chatters_online_list .= check_private_icon( $current['NICK'] ).'</a></td>';
     $chatters_online_list .= $prefix.preg_replace( "/\#{3}([^#]*)\#{3}/e", "htmlentities(\$_SESSION['translator']->out('\\1'))", $current['NICK'] ).$postfix.'&nbsp;';
     
     $chatters_online_list .= '['.$current['LAST_CHANNEL'].']';
     //ignored?
     if($_SESSION['chatter']->is_ignored($current['NICK']))
       $chatters_online_list .= '<img title="'.$_SESSION['translator']->out('IGNORED').'" src="'.$_SESSION['template']->get_tmpl_web_path().'/images/icons/ignore_list.gif" alt="'.$_SESSION['translator']->out('IGNORED').'" border="0" align="middle" />';
       
     //userpage
     $chatters_online_list .= '&nbsp;<a class="imageLink" href="#" onclick="showUserPage(\''.$current['NICK'].'\');return false">';
     $chatters_online_list .= '<img title="'.$_SESSION['translator']->out('USER_PAGE').'" src="'.$_SESSION['template']->get_tmpl_web_path().'/images/icons/userpage.gif" alt="'.$_SESSION['translator']->out('USER_PAGE').'" border="0" align="middle" /></a>';
     
     if( $_SESSION['channel']->get_name() == $current['LAST_CHANNEL'] )
     {
       //select nick
       $chatters_online_list .= '&nbsp;<a class="imageLink" href="#" onclick="select_nick(\''.$current['NICK'].'\');window.close();return false">';
       $chatters_online_list .= '<img title="'.$_SESSION['translator']->out('SAY_TO').' '.$current['NICK'].'" src="'.$_SESSION['template']->get_tmpl_web_path().'/images/icons/face_to_face.gif" alt="'.$_SESSION['translator']->out('SAY_TO').'" border="0" align="middle" /></a></td>';
     }
     else
     {
       //change channel
       $chatters_online_list .= '&nbsp;<a class="imageLink" href="#" onclick="change_channel(\''.$current['LAST_CHANNEL'].'\');window.close();return false;">';
       $chatters_online_list .= '<img title="'.$_SESSION['translator']->out('CHANGE_CHANNEL').' ('.$current['LAST_CHANNEL'].')" src="'.$_SESSION['template']->get_tmpl_web_path().'/images/icons/change_channel.gif" alt="'.$_SESSION['translator']->out('CHANGE_CHANNEL').' ('.$current['LAST_CHANNEL'].')" border="0" align="middle" /></a></td>';
     }
     
     if($i > 0 && ($i % COL_COUNT_CHATTER_LIST) == 0)
     {
       $td_count = 0;
       $chatters_online_list .= NL.TAB.'</tr>';
     }
   }
   for ($i = $td_count; $i < COL_COUNT_CHATTER_LIST; $i++)
   {
     $chatters_online_list .= NL.TAB.TAB.'<td></td>';
   }
   if( $td_count > 0 ) $chatters_online_list .= NL.TAB.'</tr>';
 }
 else
   $chatters_online_list  = '<tr><td>&nbsp;</td></tr>';
   
$_SESSION['chat']->disconnect();
$TEMPLATE_OUT['chatters_online_list'] = $chatters_online_list;

header('Content-type: text/html; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));
$_SESSION['template']->get_template();
?>