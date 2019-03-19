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
  $Source: /cvsroot/phpopenchat/chat3/send_passwd.php,v $
  $Revision: 1.4.2.6 $
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

if( count($_POST) == 0 )
  $_SESSION['template']->get_cached_content( 60*60*24*30 );//get cached content with a max age of one month  

$TEMPLATE_OUT['error']='';
$TEMPLATE_OUT['success']='';
if( isset($_POST['nickname']) && $_POST['nickname'] != '' ) {
  if( $_chatter = POC_Chat::mkinstance_chatter($_POST['nickname']) ) {
    $_chatter->send_passwd();
    $TEMPLATE_OUT['success'] = $_SESSION['translator']->out('PASSWORD_HAS_BEEN_SENT');
  } else {
    $TEMPLATE_OUT['error'] = $_SESSION['translator']->out('NICKNAME_NOT_FOUND');
  }
}
$_SESSION['template']->get_template();
?>