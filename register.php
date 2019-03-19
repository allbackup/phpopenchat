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
  $Date: 2004/08/10 11:07:47 $
  $Source: /cvsroot/phpopenchat/chat3/register.php,v $
  $Revision: 1.19.2.6 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

session_start();

//check if chatter is authorized to get this page
if( !isset($_SESSION['chat']) )
{
  header('Status: 302');
  header('Location: '.$_SESSION['template']->get_poc_web_root().'/index.php');
  exit;
}

if ( !isset($_SESSION['template']) )
{
	$template = &new POC_Template();
	$_SESSION['template'] = $template;
}

if( count($_POST) == 0 ){
  header('Content-type: text/html; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));
  $_SESSION['template']->get_cached_content( 60*60*24*30 );//get cached content with a max age of one month  
}
$_chatter = &new POC_Chatter('','');
$TEMPLATE_OUT['errors']  = array();
$TEMPLATE_OUT['registration_successfully'] = false;

function analyze_post_data()
{
  global $_chatter, $TEMPLATE_OUT, $NO_NICKS;
  
  //nickname
  if( !isset($_POST['nickname'])
  || $_POST['nickname']==''
  || $_POST['nickname']==STATUS_BOT_NAME
  || in_array($_POST['nickname'], $NO_NICKS)
  || strlen($_POST['nickname']) > NICKNAME_MAX_LENGTH
  || !eregi("^[[:alpha:]]+[[:alnum:]]*",$_POST['nickname'])
  || !$_chatter->set_nick( $_POST['nickname']) )
    $TEMPLATE_OUT['errors']['nickname'] = $_SESSION['translator']->out('ERROR_NICKNAME');

  //password
  if( !isset($_POST['password']) 
  || $_POST['password'] == '' 
  || !$_chatter->set_password( $_POST['password'] ) )
    $TEMPLATE_OUT['errors']['password'] = $_SESSION['translator']->out('ERROR_PASSWORD');

  //user name
  if( !isset($_POST['name'])
  || !$_chatter->set_name( $_POST['name'] )
  || $_POST['name'] == '' )
    $TEMPLATE_OUT['errors']['name'] = $_SESSION['translator']->out('ERROR_NAME');

  //email
  if( !isset($_POST['email']) 
  || $_POST['email'] == ''
  || !$_chatter->set_email( $_POST['email'] ) )
  {
    $TEMPLATE_OUT['errors']['email'] = $_SESSION['translator']->out('ERROR_EMAIL');
  }
  elseif (defined('MAX_EMAIL_REGISTER_COUNT') 
  && ($reg_count = $_chatter->get_db_email_count()) > MAX_EMAIL_REGISTER_COUNT)
  {
    $TEMPLATE_OUT['errors']['email'] = $_SESSION['translator']->out('ERROR_EMAIL_REGISTER_COUNT').' ['.$reg_count.']';
  }
  
  //pictureURL
  if( isset($_POST['pictureURL']) && $_POST['pictureURL']=='http://' )
    $URL='';
  else 
    $URL=$_POST['pictureURL'];
    
  if( !isset($_POST['pictureURL'])
  || !$_chatter->set_pictureURL( $URL ) )
    $TEMPLATE_OUT['errors']['pictureURL'] = $_SESSION['translator']->out('ERROR_PICTURE_URL');
    
  return ( count($TEMPLATE_OUT['errors']) == 0);
}
$TEMPLATE_OUT['meta_refresh'] = '';
$TEMPLATE_OUT['success'] = '';
if( isset($_POST['register']) )
{
  if( analyze_post_data() )
  {
    if($_chatter->register() === true)
    {
      $TEMPLATE_OUT['success'] = $_SESSION['translator']->out('REGISTRATION_SUCCESSFULLY');
      if( !SEND_CONFIRMATION_MAIL )
      {
        $TEMPLATE_OUT['meta_refresh'] = '<meta http-equiv="refresh" content="5; url=\'index.php?nickname='.$_POST['nickname'].'&amp;'.$_SESSION['session_get'].'\'">';
        $TEMPLATE_OUT['success'] .= '<br />'.$_SESSION['translator']->out('LOGIN_NOW').'<br /><a href="index.php?'.$_SESSION['session_get'].'">'.$_SESSION['translator']->out('LOGIN').'</a></p>';
      }
      $TEMPLATE_OUT['registration_successfully'] = true;
    }
    else
      $TEMPLATE_OUT['errors']['nomailhost'] = $_SESSION['translator']->out('ERROR_MAIL_HOST');
  }
}
else
{
  $_POST['nickname'] = '';
  $_POST['password'] = '';
  $_POST['name'] = '';
  $_POST['email'] = '';
  $_POST['pictureURL'] = 'http://';
}

$TEMPLATE_OUT['confirmation_message'] = '';
if( SEND_CONFIRMATION_MAIL )
  $TEMPLATE_OUT['confirmation_message'] = $_SESSION['translator']->out('CONFIRMATION_MESSAGE');

$_SESSION['template']->get_template();
?>