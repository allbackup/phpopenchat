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
  $Source: /cvsroot/phpopenchat/chat3/approve.php,v $
  $Revision: 1.14.2.3 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Recipient.inc');
require_once(POC_INCLUDE_PATH.'/class.Line.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel_Buffer_'.CHANNEL_BUFFER_TYPE.'.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

session_start();

//check if chatter is authorized to get this page
if( !isset($_SESSION['chatter']) )
  die('Login first!');

if( !$_SESSION['chatter']->is_moderator() )
  die('Permission denied');

$_SESSION['reload_count'] = 0;//reset chat session expiration time
if( isset($_POST['approved_line']) )
{
	//write line to buffer and mark it as approved
	$line = unserialize(stripslashes(urldecode($_POST['line'])));
	$line->set_said( $_POST['said'] );

  //put line into the channel buffer
  $line->filter_buffer_input();
  $line->set_approved();
  $_SESSION['channel_buffer']->connect();
  $_SESSION['channel_buffer']->put_line($line);
  $_SESSION['channel_buffer']->disconnect();

  die('<html><body onload="window.close()"></body></html>');
}

if( isset($_POST['approve']) )
{
  $line = unserialize(stripslashes(urldecode($_POST['line'])));
  
  //put line into the channel buffer
  //$line->filter_buffer_input();
  $line->set_approved();
  $_SESSION['channel_buffer']->connect();
  $_SESSION['channel_buffer']->put_line($line);
  $_SESSION['channel_buffer']->disconnect();
  exit;
}

$line = unserialize( urldecode($_POST['line']) );
$said = $line->get_said();

//strip html tags
$TEMPLATE_OUT['said'] = strip_tags($said);

if( $line->get_whispered() )
  $TEMPLATE_OUT['to'] = $_SESSION['translator']->out('WHISPERS_TO');
else 
  $TEMPLATE_OUT['to'] = $_SESSION['translator']->out('SAYS_TO');

$chatter_object = $line->get_chatter();
$TEMPLATE_OUT['chatter'] = $chatter_object->get_nick();
$recipient_object = $line->get_recipient();
$TEMPLATE_OUT['recipient'] = $recipient_object->get_nick();
$TEMPLATE_OUT['post_line'] = urlencode(serialize( $line ));

$_SESSION['template']->get_template('approve');
?>