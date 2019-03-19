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
  $Source: /cvsroot/phpopenchat/chat3/status.php,v $
  $Revision: 1.1.2.5 $
*/

//Include this script to output statisics about current online chatters of your chat.

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');

$_chat = &new POC_Chat(CHAT_NAME,$supported_languages);
if(!isset($_SESSION['translator'])) {
  if(function_exists('session_register')) {
    session_register('translator');
  }
  $translator = &new POC_Translator( $_chat->get_language() );
  $_SESSION['translator'] = $translator;
}
$_chat->connect();
 $online_chatters = $_chat->get_chatters('%');
$_chat->disconnect();
$chatter_count = count($online_chatters);
print '<table cellpadding="2" cellspacing="0" border="0">
        <thead>
          <tr>
            <td colspan="2" style="background-color:#0a0;color:#ff0;font-family: arial,sans-serif;font-size: 10px;font-weight: bold">
              Online: '.$chatter_count.'
            </td>
          </tr>
        </thead>
        <tbody>';
if($chatter_count > 0)
{
  reset($online_chatters);
  do{
    print '<tr>';
    print '  <td style="background-color:#ffce00;color:#000;font-family: arial,sans-serif;font-size: 10px">'.preg_replace( "/\#{3}([^#]*)\#{3}/e", "htmlentities(\$_SESSION['translator']->out('\\1'))", current($online_chatters) ).'</td>';
    if(next($online_chatters))
      print '<td style="background-color:#ffce00;color:#000;font-family: arial,sans-serif;font-size: 10px">'.preg_replace( "/\#{3}([^#]*)\#{3}/e", "htmlentities(\$_SESSION['translator']->out('\\1'))", current($online_chatters) ).'</td>';
    else
    {
      print '<td style="background-color:#ffce00;color:#000;font-family: arial,sans-serif;font-size: 10px">&nbsp;</td>';
      print'</tr>';
      break;
    }
    print '</tr>';
  }while(next($online_chatters));
} else print '<tr><td colspan="2">&nbsp;</td></tr>';
print ' </tbody>
       </table>
';
unset($_chat);
unset($chatter_count);
unset($online_chatters);
?>