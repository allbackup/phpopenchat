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
  $Source: /cvsroot/phpopenchat/chat3/private_frameset.php,v $
  $Revision: 1.6.2.6 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel_Buffer_'.CHANNEL_BUFFER_TYPE.'.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel.inc');
require_once(POC_INCLUDE_PATH.'/class.Line.inc');
require_once(POC_INCLUDE_PATH.'/class.Logger.inc');

session_start();

if(!isset($_SESSION['chatter']))
  die('Login first!');

if( !isset($_GET['channel'])
   || (   $_GET['channel'] != $_SESSION['chatter']->get_nick() 
       && $_GET['channel'] != $_SESSION['invited_from'] ) 
) {
  die('Permission denied!');
}

if(function_exists('session_unregister')) {
  session_unregister('p_in');unset($_SESSION['p_in']);
}
$prefix = abs(crc32($_REQUEST['channel']));
if(function_exists('session_register')) {
  session_register($prefix.'_channel', $prefix.'_channel_buffer', $prefix.'_lastRedLine');
}
/* invited chatter*/
if(isset($_SESSION['invited_from']) && $_GET['channel'] == $_SESSION['invited_from'] )
{
  $recipient = $_GET['channel'];
  $_SESSION['chatter']->join_channel( $_GET['channel'], true );
  unset($_SESSION['invited_from']);
}
/* inviting chatter */
if( $_GET['channel'] == $_SESSION['chatter']->get_nick() )
{
  $recipient = $_GET['dialog_partner'];
  $_SESSION['chatter']->join_channel( $_GET['channel'], true );
  $_SESSION['chatter']->invite_private( $_SESSION['chatter']->get_nick(), $_GET['dialog_partner'] );
}

$TEMPLATE_OUT['channel'] = urlencode( $_GET['channel'] );
$TEMPLATE_OUT['recipient'] = urlencode($recipient);
$TEMPLATE_OUT['recipient_title'] = $recipient;
$TEMPLATE_OUT['channel_prefix'] = $prefix;
$TEMPLATE_OUT['interval'] = LINE_POLLING_INTERVAL * 1000;

header('Content-type: text/html; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));
print '<?xml version="1.0" encoding="'.$_SESSION['translator']->out('CHARACTER_ENCODING').'"?>'.NL;
flush();
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Frameset//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd">
<html>
  <head>
    <title><?=$TEMPLATE_OUT['recipient_title']?></title>
    <meta http-equiv="Content-type" content="text/html; charset='<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>'" />
    <script type="text/javascript">
    /*<![CDATA[*/
      var refresh    = <?=$TEMPLATE_OUT['interval']?>;
      var BufferInt  = window.setInterval("reload_getlines()",refresh);
      var serialize_private_refresh = 0;

      function reload_getlines(){
	      if(serialize_privat_refresh == 0)
	      {
	        serialize_privat_refresh = 1;
	        getlines.location.href = 'private_getlines.php?login=0&<?=session_name()."=".session_id()?>&channel=<?=$TEMPLATE_OUT['channel']?>&recipient=<?=$TEMPLATE_OUT['recipient']?>';
	      }
      }

      var scrollTO;
      var timeout_on = false;
      var speed = 1;
      function scroll_it() {
        to=20;
        if(speed != 0){
          if(speed==3){
           to = 5;
           down=3;
          }else if(speed == 2){
           to = 10;
           down=2;
          }else{
           to = 20;
           down=1;
          }
          window.output.scrollBy(-1,down);
          if (timeout_on == true) {
           clearTimeout(scrollTO);
          }
          timeout_on = true;
          scrollTO = setTimeout('scroll_it()',to);
        }
       }

       function mk_clean()
       {
         opener.parent.dummy.location.href = 'private_destroy.php?<?=session_name()."=".session_id()?>&channel=<?=$TEMPLATE_OUT['channel']?>&recipient=<?=$TEMPLATE_OUT['recipient']?>';
       }
    /*]]>*/
    </script>
  </head>
  <frameset rows="75%,*,0,0" onunload="mk_clean();">
    <frame name="output" src="output.php?<?=session_name()."=".session_id()?>" frameborder="0" />
    <frame name="input" src="private_input.php?<?=session_name()."=".session_id()?>&amp;channel=<?=$TEMPLATE_OUT['channel']?>&amp;recipient=<?=$TEMPLATE_OUT['recipient']?>" frameborder="0" />
    <frame name="getlines" src="private_getlines.php?login=1&amp;<?=session_name()."=".session_id()?>&amp;channel=<?=$TEMPLATE_OUT['channel']?>&amp;recipient=<?=$TEMPLATE_OUT['recipient']?>" frameborder="0" />
    <frame name="_dummy" src="output.php?<?=session_name()."=".session_id()?>" frameborder="0" />
    <noframes>
      <body>
        Sorry you are using an outdated browser, please download the newest release of:
        <menu>
          <li>Mozilla at <a href="http://www.mozilla.org/">http://www.mozilla.org/</a> or</li>
          <li>Opera at <a href="http://www.opera.com/">http://www.opera.com/</a> or</li>
          <li>Konqueror at <a href="http://www.konqueror.org/">http://www.konqueror.org/</a> or</li>
          <li>Netscape at <a href="http://www.netscape.com/">http://www.netscape.com/</a> or</li>
          <li>Lynx at <a href="http://lynx.browser.org/">http://lynx.browser.org/</a></li>
        </menu>
      </body>
    </noframes>
  </frameset>
</html>