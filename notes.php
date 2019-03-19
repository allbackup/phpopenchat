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
  $Source: /cvsroot/phpopenchat/chat3/notes.php,v $
  $Revision: 1.6.2.5 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
//require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

session_start();
/*if(isset($_GET['silent'])) echo '<html>
									<body onload="alert(\'debug: \'+\''.$_GET['new_note'].'\')">
									</body>
								</html>';
*/
//check if chatter is authorized to get this page
if( !isset($_SESSION['chatter']) )
  die('Login first!');
$_SESSION['reload_count'] = 0;//reset chat session expiration time

if( isset($_GET['nick']) )
  $_POST['nick'] = $_GET['nick'];

if( !isset($_POST['nick']) )
  die('No nickname given!');
  
$nickname=$_POST['nick'];
$TEMPLATE_OUT['note'] = '';
$TEMPLATE_OUT['success'] = '';
$TEMPLATE_OUT['error'] = '';
if(!isset($_POST['note'])) {
  $_POST['note'] = $_GET['new_note'];
  unset($_GET['new_note']);
}
if( isset($_POST['note']) && strlen($_POST['note'])> MAX_NOTE_SIZE )
  unset($_POST['note']);

$bool=false;
$_SESSION['chat']->connect();
 if( isset($_POST['note']) ) {
   if( isset($_GET['silent']) ) {
     //the call comes from context menu
	 // so we have to append the selection to the stored note
     $currentNote = $_SESSION['chat']->get_note_for( $_POST['nick'] );
	 $_POST['note'] = $currentNote.NL.$_POST['note'];
	 unset($currentNote);
   }
   $bool = $_SESSION['chat']->set_note_for( $_POST['nick'], $_POST['note'] );

   if($bool) {
     $TEMPLATE_OUT['success'] = $_SESSION['translator']->out('NOTES_UPDATED_SUCCESSFULLY');
   } else {
     $TEMPLATE_OUT['error'] = $_SESSION['translator']->out('NOTES_NOT_UPDATED');
   }
 }
$TEMPLATE_OUT['note'] = $_SESSION['chat']->get_note_for( $_POST['nick'] );
$_SESSION['chat']->disconnect();
if( !isset($_GET['silent']) ){
  $_SESSION['template']->get_template();
}
?>
