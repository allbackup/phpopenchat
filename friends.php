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
  $Date: 2004/02/12 13:39:10 $
  $Source: /cvsroot/phpopenchat/chat3/friends.php,v $
  $Revision: 1.18.2.3 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel_Buffer_'.CHANNEL_BUFFER_TYPE.'.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

session_start();

//check if chatter is authorized to get this page
if( !isset($_SESSION['chatter']) )
  die('Login first!');
$_SESSION['reload_count'] = 0;//reset chat session expiration time

if( isset($_GET['silent']) )
{
  /*call from right click menu*/
  $_SESSION['chat']->connect();
   if($_SESSION['chat']->is_online($_GET['new_friend']))
     $_SESSION['chatter']->add_friend( $_GET['new_friend'] );
  $_SESSION['chat']->disconnect();
  print '
  <html>
    <body onload="alert(\''.$_SESSION['translator']->out('CONFIRM_FRIEND').'\')"></body>
  </html>
  ';
  exit;
}
if( $_SESSION['chatter']->is_guest() )
  die($_SESSION['translator']->out('DENIED_FOR_GUESTS'));

$TEMPLATE_OUT['option_list_of_no_friends'] = '<option />';
if( isset($_POST['add']) && isset($_POST['all_chatters']) )
  $_SESSION['chatter']->add_friend( $_POST['all_chatters'] );
  
if( (isset($_POST['del_x'])&&$_POST['del_x']>0) && isset($_POST['friends']) )
  $_SESSION['chatter']->del_friend( $_POST['friends'] );

if( !isset($_POST['nick_constraint']) )
  $_POST['nick_constraint'] = $_SESSION['translator']->out('RESTRICT');
elseif( $_POST['nick_constraint'] != $_SESSION['translator']->out('RESTRICT') 
&& $_POST['nick_constraint'] != '' )
{
  $_SESSION['chat']->set_nick_restrict($_POST['nick_constraint']);
  $_SESSION['chat']->connect();
  $TEMPLATE_OUT['option_list_of_no_friends'] = $_SESSION['chat']->get_chatters_excepting( $_SESSION['chatter']->get_friends(), 'as_option_list' );
  $_SESSION['chat']->disconnect();
  $_SESSION['chat']->set_nick_restrict('');
}

$TEMPLATE_OUT['option_list_of_friends'] = $_SESSION['chatter']->get_friends_as_option_list();
header('Content-type: text/html; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));
$_SESSION['template']->get_template();
?>
