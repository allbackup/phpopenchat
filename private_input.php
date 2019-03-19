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
  $Source: /cvsroot/phpopenchat/chat3/private_input.php,v $
  $Revision: 1.2.2.6 $
*/

require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Recipient.inc');//extents Chatter
require_once(POC_INCLUDE_PATH.'/class.Line.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel_Buffer_'.CHANNEL_BUFFER_TYPE.'.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

session_start();

//check if chatter is authorized to get this page
if( !isset($_SESSION['chatter']) )
{
  header('Status: 301');
  header('Location: index.php?forceOnTop=1');
  exit;
}

$prefix = abs(crc32($_REQUEST['channel']));
//$TEMPLATE_OUT['test'] = $_SESSION[$prefix.'_channel_buffer']->get_name();

if( isset($_POST['line']) && $_POST['line'] != '' )
{
  $_SESSION['reload_count'] = 0;//reset chat session expiration time
  $_POST['line'] = preg_replace('/\'/', '&#39;', $_POST['line'] );

  $said = $_POST['line'];
  $line = &new POC_Line( $_SESSION['chatter'], $said);
  $recipient = &new POC_Chatter(STATUS_BOT_NAME);
  $recipient->set_nick($_REQUEST['recipient']);
  $line->set_recipient($recipient);
  $line->set_in_private_window();
  $line->filter_buffer_input();
  //Bug: sometimes, the channel buffer doen't exits in the session
  //may be a timing problem, so we try to wait if this problem occur
  if( is_object( $_SESSION[$prefix.'_channel_buffer']) ){
    $_SESSION[$prefix.'_channel_buffer']->connect();
     $_SESSION[$prefix.'_channel_buffer']->put_line($line);
    $_SESSION[$prefix.'_channel_buffer']->disconnect();
  }
  $_SESSION['chatter']->count_hit('line');
  $TEMPLATE_OUT['show_message_locally'] = $line->out();
}
$TEMPLATE_OUT['channel'] = $_REQUEST['channel'];
$TEMPLATE_OUT['recipient'] = $_REQUEST['recipient'];
$_SESSION['template']->get_template('private_input');
?>