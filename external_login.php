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
  $Date: 2004/02/24 17:05:17 $
  $Source: /cvsroot/phpopenchat/chat3/external_login.php,v $
  $Revision: 1.5.2.4 $
*/

/*
This is an example, how-to integrade the PHPOpenChat
into an other PHP-based application (for example "phpfoobar")
*/

//Include this three PHPOpenChat files into the login script of phpfoobar
require_once(''.dirname(__FILE__).'/config.inc.php');
require_once('class.Chat.inc');
require_once('class.Chatter.inc');
require_once('adodb/adodb.inc.php');

$link_to_chat = '';

//search for the right position where phpfoobar checks the posted login data
if( isset($_POST['submit']) )
{
  //check of posted login data by phpfoobar
  // ...
  
  //add the following code at the position, where the login data are accepted
  //by phpfoobar's login procedure
  //...
  
  $chatter = POC_Chat::mkinstance_chatter( $_POST['nick'] );
  if( !$chatter->is_registered())
    $chatter->register();
  else
  {
    $chatter->set_gender('m');//possible values: 'f' or 'm'
    $chatter->set_email('address.stored@other.application');
    //for more setter see API-doc

    $chatter->update();
  }
  session_start();
  if(function_exists('session_register')) {
    session_register('chatter');
  }
  $_SESSION['chatter'] = $chatter;
  
  //to add a link within phpfoobar to the chat, use:
  if( isset($_SESSION['chatter']) )
    $link_to_chat = '<a href="index.php?'.session_name().'='.session_id().'">Chat</a>';//add the correct path to PHPOpenChat's index.php within the 'href' attribute!
}
print '<?xml version="1.0" encoding="UTF-8"?>'.NL;
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
  <head>
    <meta http-equiv="Content-type" content="text/html; charset='UTF-8'" />
    <title>External Login</title>
  </head>
  <body>
    <form action="external_login.php" method="post">
      <p>
        Login: <input name="nick" type="text" /><br/>
        Password: <input name="password" type="text" /><br/>
        <input name="submit" type="submit" />
      </p>
    </form>
    <p><?=$link_to_chat?></p>
  </body>
</html>