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
  $Date: 2004/02/12 13:39:11 $
  $Source: /cvsroot/phpopenchat/chat3/profile_misc.php,v $
  $Revision: 1.1.2.3 $
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
if( !isset($_SESSION['chatter']) )
  die('Permission denied');
  
$TEMPLATE_OUT['title'] = '';
$TEMPLATE_OUT['content'] = '';
if( isset($_POST['add']) )
{
  $data   = array();
  $data[] = $_POST['title'];
  $data[] = $_POST['content'];
  $_SESSION['chatter']->insert_profile_misc($data);
}

if( isset($_POST['del']) )
{
  $misc = $_SESSION['chatter']->get_profile_misc();
  foreach($misc as $key => $value)
  {
    if( $value[0] == $_POST['title'] ) unset($misc[$key]);
  }
  $_SESSION['chatter']->insert_profile_misc($misc,true);
}

if( isset($_POST['edit']) )
{
  $misc = $_SESSION['chatter']->get_profile_misc();
  foreach($misc as $key => $value)
  {
    if( $value[0] == $_POST['title'] ) unset($misc[$key]);
  }
  $data   = array();
  $data[] = $_POST['title'];
  $data[] = $_POST['content'];
  $misc[] = $data;
  $_SESSION['chatter']->insert_profile_misc($misc,true);
}


if(count($_POST)>0)
{
  echo'<html><head>
  <script type="text/javascript">
    opener.document.location.href=\'profile.php?'.$_SESSION['session_get'].'&rand='.rand(0,20).'#misc\';
    window.close();
  </script>
  </head><body></body></html>
  ';exit;
}

if( isset($_GET['action']) && ($_GET['action']=='edit' || $_GET['action']=='del'))
{
  $misc = $_SESSION['chatter']->get_profile_misc();
  foreach($misc as $key => $value)
  {
    $TEMPLATE_OUT['title'] = $value[0];
    $TEMPLATE_OUT['content'] = $value[1];
    if ($value[0] == $_GET['title']) break;
  }
}
header('Content-type: text/html; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));
$_SESSION['template']->get_template();
?>