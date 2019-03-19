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
  $Date: 2004/02/29 23:01:45 $
  $Source: /cvsroot/phpopenchat/chat3/insert_icon.php,v $
  $Revision: 1.2.2.7 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

session_start();

//check if chatter is authorized to get this page
if( !isset($_SESSION['chatter']) )
  die('Login first!');

$_SESSION['reload_count'] = 0;//reset chat session expiration time
header('Content-type: text/html; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));
$_SESSION['template']->get_cached_content( 60*60*24*30 );//get cached content with a max age of one month
$TEMPLATE_OUT['more_icons'] = '';
if(defined('OFFER_MORE_ICONS') && OFFER_MORE_ICONS){
  $available_themes = $_SESSION['template']->get_theme_list();
  foreach ( $available_themes as $value ){
    $templ = &new POC_Template( $value );
    $templ->set_theme($value);
    $smileys = $templ->get_extra_smileys();
    if(count($smileys)>0)
      $TEMPLATE_OUT['more_icons'] .= '<p><strong>'.$value.'</strong><br />'.NL;
    $is_current_theme = ($_SESSION['template']->get_theme() == $value);
    foreach($smileys as $smiley){
      $smiley = preg_replace('/:/', '', $smiley);
      if($is_current_theme){
        $onclick = 'insert_icon_code(\''.$smiley.'\')';
      }else{
        $onclick = 'insert_theme_icon_code(\''.$smiley.'\', \''.$templ->get_theme().'\')';
      }      
      $TEMPLATE_OUT['more_icons'] .= '<a href="#" onclick="'.$onclick.'"><img title=":'.$smiley.':" src="'.$templ->get_theme_path().'/images/icons/smileys/'.$smiley.'.gif" border="0" alt=":'.$smiley.':" /></a> '.NL;      
    }
    if(count($smileys)>0)
      $TEMPLATE_OUT['more_icons'] .= '</p>';
  }
  $_SESSION['template']->get_template('insert_more_icons');
}else{
  $_SESSION['template']->get_template('insert_icon');
}
?>