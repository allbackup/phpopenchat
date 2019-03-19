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
  $Source: /cvsroot/phpopenchat/chat3/invite.php,v $
  $Revision: 1.19.2.6 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel_Buffer_'.CHANNEL_BUFFER_TYPE.'.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');
require_once(POC_INCLUDE_PATH.'/class.Line.inc');

session_start();

//check if chatter is authorized to get this page
if( !isset($_SESSION['chatter']) )
  die('Login first!');
$_SESSION['reload_count'] = 0;//reset chat session expiration time

//if( $_SESSION['chatter']->is_guest() )
//  die($_SESSION['translator']->out('DENIED_FOR_GUESTS'));

function post_line( $to, $string )
{
  $line = &new POC_Line();
  $recipient = &new POC_Chatter( STATUS_BOT_NAME );
  $recipient->set_nick( $to );
  $line->set_recipient( $recipient );
  $line->set_sender( $_SESSION['chatter'] );
  $line->set_said( $string );
  $line->set_whispered();
  //$line->set_invitationMsg();

  $_SESSION['channel_buffer']->connect();
  $_SESSION['channel_buffer']->put_line($line);
  $_SESSION['channel_buffer']->disconnect();
  $_SESSION['chatter']->count_hit('line');
}

$invited_chatters_option_list = '';
$option_list_of_disinvited_chatters = '<option />';

if( (isset($_POST['add'])&&$_POST['add']!='') && isset($_POST['disinvited_chatter']) )
  $_SESSION['chatter']->invite( $_POST['disinvited_chatter'] );
elseif( isset($_GET['disinvited_chatter']) )
{
  /* launched by the right click menu within the output frame*/
  define('CONFIRM_MSG',$_SESSION['translator']->out('CONFIRM_INVITE'));
  $_SESSION['chatter']->invite( $_GET['disinvited_chatter'] );
  post_line( $_GET['disinvited_chatter'], '<span class="invitationMsg">###INVITATION_MESSAGE###'.' "'.$_SESSION['chatter']->get_nick().'"</span>' );
  if( isset($_GET['silent']) )
  {
    print '<?xml version="1.0" encoding="'.$_SESSION['translator']->out('CHARACTER_ENCODING').'"?>'.NL;
    include_once($_SESSION['template']->get_template('confirmation_message'));
    exit;
  }
}
  
if( (isset($_POST['del_x'])&&$_POST['del_x']>0) && isset($_POST['invited_chatter']) )
  $_SESSION['chatter']->disinvite( $_POST['invited_chatter'] );
elseif( isset($_GET['invited_chatter']) )
{
  /* launched by the right click menu within the output frame*/
  define('CONFIRM_MSG',$_SESSION['translator']->out('CONFIRM_DISINVITE'));
  $_SESSION['chatter']->disinvite( $_GET['invited_chatter'] );
  if( isset($_GET['silent']) )
  {
    print '<?xml version="1.0" encoding="'.$_SESSION['translator']->out('CHARACTER_ENCODING').'"?>'.NL;
    include_once($_SESSION['template']->get_template('confirmation_message'));
    exit;
  }
}
  
//get list of invited chatters
$invited = $_SESSION['chatter']->get_db_invited();

if( !isset($_POST['nick_constraint']) )
  $_POST['nick_constraint'] = $_SESSION['translator']->out('RESTRICT');
elseif( $_POST['nick_constraint'] != $_SESSION['translator']->out('RESTRICT') 
&& $_POST['nick_constraint'] != '' )
{
  $_SESSION['chat']->set_nick_restrict($_POST['nick_constraint']);
  $_SESSION['chat']->connect();
   //get option list of disinvited chatters
   $option_list_of_disinvited_chatters = $_SESSION['chat']->get_chatters_excepting( $invited, true );
  $_SESSION['chat']->disconnect();
  $_SESSION['chat']->set_nick_restrict('');
}

reset($invited);
do{
  $invited_chatters_option_list .= TAB.'<option value="'.current($invited).'">'.preg_replace( "/\#{3}([^#]*)\#{3}/e", "htmlentities(\$_SESSION['translator']->out('\\1'))", current($invited) ).'</option>'.NL;
}while(next($invited));

$TEMPLATE_OUT['invited_chatters_option_list'] = $invited_chatters_option_list;
$TEMPLATE_OUT['option_list_of_disinvited_chatters'] = $option_list_of_disinvited_chatters;

$_SESSION['template']->get_template();
?>