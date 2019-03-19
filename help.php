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
  $Date: 2004/02/29 19:57:11 $
  $Source: /cvsroot/phpopenchat/chat3/help.php,v $
  $Revision: 1.10.2.6 $
*/

require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

session_start();

if( !isset($_SESSION['chat']) ) {
  if(function_exists('session_register')) {
    session_register('translator');
  }
  $chat  = &new POC_Chat( strval(CHAT_NAME), $supported_languages );
  $translator = &new POC_Translator( $chat->get_language() );
  $_SESSION['translator'] = $translator;
  unset($chat);
}
if( !isset($_SESSION['template']) ) {
	$template = &new POC_Template();
	$_SESSION['template'] = $template;
}

$TEMPLATE_OUT['extra_smileys'] = '';
if( $_SESSION['template']->has_extra_smileys() ){
  $extra_smileys = $_SESSION['template']->get_extra_smileys();
  foreach ($extra_smileys as $value){
    $TEMPLATE_OUT['extra_smileys'] .= $value.' ';
  }
  unset($extra_smileys);
}

$_SESSION['template']->get_cached_content( 60*60*24*30 );//get cached content with a max age of one month  
$_SESSION['template']->get_template('help');
?>