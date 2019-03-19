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
  $Source: /cvsroot/phpopenchat/chat3/frameset.php,v $
  $Revision: 1.39.2.4 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

session_start();

if(!isset($_SESSION['chatter']))
  die('Login first!');
  
$TEMPLATE_OUT['interval'] = LINE_POLLING_INTERVAL * 1000;
session_unregister('in');
unset($_SESSION['in']);
$TEMPLATE_OUT['operator_label'] =(isset($_SESSION['chatter'])&&$_SESSION['chatter']->is_operator())? '@':'';
$members                 = array();
$TEMPLATE_OUT['members'] = '';
if( isset($_SESSION['chat']) ) {
  $_SESSION['chat']->connect();
   $members = $_SESSION['chat']->get_group_members('operator');
  $_SESSION['chat']->disconnect();
  if( is_array($members) && count($members) > 0 ) {
    reset($members);
    do{
      $TEMPLATE_OUT['members'] .= ',\''.current($members).'\'';
    }while( next($members) );
    $TEMPLATE_OUT['members'] = substr_replace($TEMPLATE_OUT['members'],'',0,1);
  }
} else {
  $_SESSION['logger']->warning('$_SESSION[\'chat\'] doesn\'t exists.', __FILE__, __LINE__ - 9 );
}
unset($members);
sleep(1);
header('Content-type: text/html; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));
$_SESSION['template']->get_template();
?>