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
  $Source: /cvsroot/phpopenchat/chat3/private_destroy.php,v $
  $Revision: 1.3.2.4 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Line.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel_Buffer_'.CHANNEL_BUFFER_TYPE.'.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Logger.inc');

session_start();

function write_line($prefix, $busy = false)
{
  $said = $_SESSION['chatter']->get_nick().' ###LEAVES_THIS_CHANNEL###';
  $bot = &new POC_Chatter(strval(STATUS_BOT_NAME));
  $line = &new POC_Line($bot, $said);
  $recipient = &new POC_Chatter(STATUS_BOT_NAME);
  if($busy)
  {
    $recipient->set_nick($_SESSION['invited_from']);
    $line->set_said($_SESSION['chatter']->get_nick().' ###IS_TOO_BUSY###');
    $line->set_sender_busy();
  }
  else
    $recipient->set_nick($_REQUEST['recipient']);

  $line->set_recipient($recipient);
  $line->set_in_private_window();
  $_SESSION[$prefix.'_channel_buffer']->connect();
   $_SESSION[$prefix.'_channel_buffer']->put_line($line);
  $_SESSION[$prefix.'_channel_buffer']->disconnect();
  unset($line);
  unset($bot);
  unset($said);
}

if( isset($_GET['busy']) )
{
  $prefix = abs(crc32($_SESSION['invited_from']));
  $_SESSION['chatter']->join_channel( $_SESSION['invited_from'], true );
  write_line($prefix,true);
}
else
{
  $prefix = abs(crc32($_REQUEST['channel']));
  write_line($prefix);
}

session_unregister($prefix.'_channel');
session_unregister($prefix.'_channel_buffer');
session_unregister($prefix.'_lastRedLine');
session_unregister('p_in');
unset($_SESSION[$prefix.'_channel']);
unset($_SESSION[$prefix.'_channel_buffer']);
unset($_SESSION[$prefix.'_lastRedLine']);
unset($_SESSION['p_in']);
?>