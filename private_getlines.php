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
  $Source: /cvsroot/phpopenchat/chat3/private_getlines.php,v $
  $Revision: 1.6.2.4 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Recipient.inc');//extents Chatter
require_once(POC_INCLUDE_PATH.'/class.Line.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel_Buffer_'.CHANNEL_BUFFER_TYPE.'.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

session_start();
if(!isset($_SESSION['chatter']) || !is_object($_SESSION['chatter']))
  die('Login first!');

$all_lines = '';
$js_onload = '';
$TEMPLATE_OUT['js_onunload'] = '';
$prefix = abs(crc32($_REQUEST['channel']));
if( isset($_GET['login']) && $_GET['login']==1 && !isset($_SESSION['p_in']))
{
  /* mozilla 1.4b uses the source of frameset every time where this page are reloaded, 
   * so $_GET['login'] is set everytime to 1
   * Workaround:
   */
  if(function_exists('session_register')) {
    session_register('p_in');
  }
  $_SESSION['p_in'] = '';

  $js_onload .= 'parent.scroll_it();';
  if( !defined('_LANG') )
    define('_LANG',$_SESSION['chat']->get_language());
  $all_lines = $_SESSION['chat']->get_template('private_output');
}

$_SESSION[$prefix.'_channel_buffer']->connect();

if( $lines = $_SESSION[$prefix.'_channel_buffer']->get_lines_since( $_SESSION[$prefix.'_lastRedLine'] ) )
{
    $js_onload .= 'parent.focus();';
    $max_line_idx = $_SESSION[$prefix.'_channel_buffer']->get_max_line_idx();
    $_SESSION[$prefix.'_channel_buffer']->disconnect();
    reset($lines);
    $i = $_SESSION[$prefix.'_lastRedLine'];
    $moderate_line = '';
    do{
        $i = ++$i % $max_line_idx;
        $current_line   = current($lines);
        if( !is_object($current_line) )
        {
          $js_debug.='alert("'.$current_line.'");';
          continue;
        }
        
        $line_sender    = $current_line->get_chatter();
        $line_recipient = $current_line->get_recipient();
        
        //and now here come some 'guards'
        if(is_object($line_sender) && $line_sender->get_nick() == $_SESSION['chatter']->get_nick())
          continue;

	      if( !$current_line->in_private_window() )
	        continue;

	      if( $current_line->is_sender_busy() )
	        $TEMPLATE_OUT['js_onunload'] = "parent.close();";

	      $ranking = $_SESSION['chat']->get_grade_icon( $line_sender );
	      $all_lines .= '<div style="color: #'.$line_sender->get_color().'">'.HTML_BEFORE_LINE.$ranking.'<span>';
	      $all_lines .= $line_sender->get_nick();
	      $all_lines .= '</span>';
	      $all_lines .= '&nbsp;';
        $all_lines .= $_SESSION['translator']->out('SAYS_TO');
        if(is_object($line_recipient))
          $all_lines .= '&nbsp;<span>'.$line_recipient->get_nick().'</span>';
        $all_lines .= ':&nbsp;';
        $current_line->filter_buffer_output();
        $all_lines .= $current_line->get_said().HTML_AFTER_LINE.'</div>';
    }while( next($lines) );

    $_SESSION[$prefix.'_lastRedLine'] = intval($i);
    unset($i);
}
else
{
	$_SESSION[$prefix.'_channel_buffer']->disconnect();
	if( !isset($_GET['login']) )
	  die('<html><body onload="parent.serialize_privat_refresh=0"></body></html>');
}
unset($lines);
unset($current_line);
unset($line_sender);
unset($lines);
unset($max_line_idx);

$TEMPLATE_OUT['all_lines'] = &$all_lines;
$TEMPLATE_OUT['js_debug'] = $js_debug;
$TEMPLATE_OUT['js_onload'] = $js_onload;

$_SESSION['template']->get_template();
?>