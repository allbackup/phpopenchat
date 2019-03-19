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
  $Date: 2004/02/26 17:07:53 $
  $Source: /cvsroot/phpopenchat/chat3/configure.php,v $
  $Revision: 1.20.2.8 $
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
$TEMPLATE_OUT['js_onload']='';
//if( $_SESSION['chatter']->is_guest() )
//  die($_SESSION['translator']->out('DENIED_FOR_GUESTS'));

$TEMPLATE_OUT['lang_switch'] = $_SESSION['chat']->get_lang_switch();

$TEMPLATE_OUT['error'] = '';
if( isset($_POST['color']) )
{
  if( !$_SESSION['chatter']->set_color($_POST['color']))
    $TEMPLATE_OUT['error'] = $_SESSION['translator']->out('ERROR_WRONG_FORMAT'); 
}

if( isset($_POST['advice']) )
{
  $_SESSION['chatter']->set_advice($_POST['advice']);
}

if( isset($_POST['options']) )
{
  $_SESSION['chatter']->set_scrollspeed($_POST['options']);
}

$js_logout = '';
if( isset($_POST['theme']) && ALLOW_TEMPLATE_CHANGES)
{
  $_SESSION['chatter']->set_theme($_POST['theme']);//cookie is set in this methode
  $_SESSION['template']->set_theme($_POST['theme']);
  if( $_SESSION['template']->requires_relogin() ){
    $js_logout = 'if(confirm(\''.$_SESSION['translator']->out('CONFIRM_RELOGIN').'\')){logout()}';
  }
  //setcookie('poc_theme',$_POST['theme'],COOKIE_EXPIRE,COOKIE_PATH,COOKIE_DOMAIN,COOKIE_SECURE);
}

$TEMPLATE_OUT['theme_option_list']=$_SESSION['template']->get_theme_option_list();

$TEMPLATE_OUT['color'] = $_SESSION['chatter']->get_color();

$TEMPLATE_OUT['advice_quiet_selected'] = '';
$TEMPLATE_OUT['advice_alert_selected'] = '';
$TEMPLATE_OUT['advice_sound_selected'] = '';
$TEMPLATE_OUT['advice_'.$_SESSION['chatter']->get_advice().'_selected'] = 'checked="checked"';

$TEMPLATE_OUT['scroll_value_0_selected'] = '';
$TEMPLATE_OUT['scroll_value_1_selected'] = '';
$TEMPLATE_OUT['scroll_value_2_selected'] = '';
$TEMPLATE_OUT['scroll_value_3_selected'] = '';
$TEMPLATE_OUT['scroll_value_'.strval($_SESSION['chatter']->get_scrollspeed()).'_selected'] = 'selected="selected"';

if(( isset($_GET['language']) ) || ( isset($_POST['theme']) && ALLOW_TEMPLATE_CHANGES)) {
  $TEMPLATE_OUT['js_onload'] .= '
  opener.parent.labelChatterCount = \''.$_SESSION['translator']->out('CHATTER_COUNT').': \';
  opener.document.location.href=\'input.php?'.$_SESSION['session_get'].'\';
  window.self.focus();
  ';
}
if(!empty($js_logout)) $TEMPLATE_OUT['js_onload'] .= $js_logout;
$_SESSION['template']->get_template('configure');
?>
