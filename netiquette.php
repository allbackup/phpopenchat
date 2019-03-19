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
  $Date: 2004/03/04 17:44:33 $
  $Source: /cvsroot/phpopenchat/chat3/netiquette.php,v $
  $Revision: 1.1.2.7 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');

session_start();

if(!isset($_SESSION['chat']))
{
  if(function_exists('session_register')) {
    session_register('chat','translator');
  }
  $chat = new POC_Chat( CHAT_NAME, $supported_languages );
  $_SESSION['chat'] = $chat;
  $translator = &new POC_Translator( $_SESSION['chat']->get_language() );
  $_SESSION['translator'] = $translator;
}
if(!isset($_SESSION['template'])){
  if(function_exists('session_register')) {
    session_register('template');
  }
  $template = &new POC_Template();
  $_SESSION['template'] = $template;
  if( isset($_SESSION['chatter']) )
    $_SESSION['template']->set_theme( $_SESSION['chatter']->get_theme() );
}
$TEMPLATE_OUT['lang_switch'] = $_SESSION['chat']->get_lang_switch();
$_SESSION['template']->get_language_template('netiquette');
?>
