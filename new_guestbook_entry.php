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
  $Source: /cvsroot/phpopenchat/chat3/new_guestbook_entry.php,v $
  $Revision: 1.1.2.4 $
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
//check if chatter is authorized to get this page
if( !isset($_SESSION['chatter']) )
  die('Permission denied');

$TEMPLATE_OUT['success'] = false;
if( isset($_POST['add']) && isset($_SESSION['chatter']) )
{
  $recipient = POC_Chat::mkinstance_chatter( $_POST['nickname'] );
  $guestbook = &new POC_Guestbook( $recipient );
  $post = &new POC_Guestbook_Post( $_SESSION['chatter'] );
  $post->set_said( $_POST['content'] );
  $post->set_time();
  $TEMPLATE_OUT['success'] = $guestbook->put_post( $post );
}

header('Content-type: text/html; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));
$_SESSION['template']->get_template();
?>