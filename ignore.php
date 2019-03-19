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
  $Source: /cvsroot/phpopenchat/chat3/ignore.php,v $
  $Revision: 1.22.2.4 $
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
//if( $_SESSION['chatter']->is_guest() )
//  die($_SESSION['translator']->out('DENIED_FOR_GUESTS'));

$ignored_chatters_option_list = '';
$ignore_success = false;
$option_list_of_channel_chatters = '<option />'.NL;
if( (isset($_POST['add'])&&$_POST['add']!='') && isset($_POST['unignored_chatter']) )
  $ignore_success = $_SESSION['chatter']->ignore( $_POST['unignored_chatter'] );
elseif( isset($_GET['unignored_chatter']) )
{
  /* launched by the right click menu within the output frame*/
  if($ignore_success) {
    define('CONFIRM_MSG',$_SESSION['translator']->out('CONFIRM_IGNORE'));
  } else {
    define('CONFIRM_MSG',$_SESSION['translator']->out('CONFIRM_IGNORE_FAILED'));
  }
  $_SESSION['chatter']->ignore( $_GET['unignored_chatter'] );
  if( isset($_GET['silent']) )
  {
    include_once($_SESSION['template']->get_template('confirmation_message'));
    exit;
  }
}

if( ( isset($_POST['del']) || (isset($_POST['del_x']) && $_POST['del_x'] > 0) )
&& isset($_POST['ignored_chatter']) )
  $_SESSION['chatter']->unignore( $_POST['ignored_chatter'] );
elseif( isset($_GET['ignored_chatter']) )
{
  /* launched by the right click menu within the output frame*/
  define('CONFIRM_MSG',$_SESSION['translator']->out('CONFIRM_UNIGNORE'));
  $_SESSION['chatter']->unignore( $_GET['ignored_chatter'] );
  if( isset($_GET['silent']) )
  {
    include_once($_SESSION['template']->get_template('confirmation_message'));
    exit;
  }
}

$nick_constraint = '';
if( !isset($_POST['nick_constraint']) )
  $_POST['nick_constraint'] = $_SESSION['translator']->out('RESTRICT');
elseif( $_POST['nick_constraint'] != $_SESSION['translator']->out('RESTRICT') 
&& $_POST['nick_constraint'] != '' )
{
  //get the list of unignored chatters
  $_SESSION['chat']->connect();
  $option_list_of_channel_chatters = $_SESSION['chat']->get_unignored_chatters_option_list( $_SESSION['channel_buffer']->get_name(), $_POST['nick_constraint'] );
  $_SESSION['chat']->disconnect();
}

//create the list of ignored chatters
$ignored = $_SESSION['chatter']->get_ignored_sender();
reset($ignored);
do{
	$ignored_chatters_option_list .= TAB.'<option value="'.current($ignored).'">'.preg_replace( "/\#{3}([^#]*)\#{3}/e", "htmlentities(\$_SESSION['translator']->out('\\1'))", current($ignored) ).'</option>'.NL;
}while(next($ignored));

$TEMPLATE_OUT['ignored_chatters_option_list'] = $ignored_chatters_option_list;
$TEMPLATE_OUT['option_list_of_channel_chatters'] = $option_list_of_channel_chatters;
$_SESSION['template']->get_template();
?>