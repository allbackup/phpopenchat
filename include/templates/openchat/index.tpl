<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['chat']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['chat']->get_language()?>">
  <head>
    <!--base href="<?=$_SESSION['template']->get_poc_web_root()?>"-->
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <meta name="generator" content="PHPOpenChat v3 (http://phpopenchat.org/)" />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
      <link title="default" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" rel="stylesheet" media="all" />
      <script type="text/javascript">
      /*<![CDATA[*/
        <?=$TEMPLATE_OUT['jScript']?>
		
        function openHelpWindow(helpText,coordX,coordY)
        {
          coordY -= 210;
          satHelp = window.open('','satHelp','width=140,height=170,screenX='+coordX+',screenY='+coordY+',top='+coordY+',left='+coordX+',dependent=yes,scrollbars=yes');
          
          satHelp.document.write('<html><head><title><?=$_SESSION['translator']->out('HELP')?><\/title>');
          satHelp.document.write('<link rel="stylesheet" title="Default" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />');
          satHelp.document.write('<\/head>');
          satHelp.document.write('<body>');
          satHelp.document.write('<dl class="help"><dt><?=$_SESSION['translator']->out('HELP')?><\/dt><dd>');
          satHelp.document.write(helpText);
          satHelp.document.write('<\/dd><\/dl>');
          satHelp.document.write('<div style="text-align:right;padding-right:3px"><a href="#" onclick="window.close()" style="font-size: .7em"><?=$_SESSION['translator']->out('CLOSE_WINDOW')?><\/a><\/div>');
          satHelp.document.write('<\/body><\/html>');
        }

        var satHelp;
        function openWindow ()
        {
          satHelp = window.open("","satHelp","width=720,height=430,left=30,top=50,dependent=yes,scrollbars=yes");
          window.satHelp.focus();
        }
        
        function focusNick()
        {
          if(document.forms[0].elements['nick'].value=='')
            document.forms[0].elements['nick'].focus();
        }
        
        function spy( channel )
        {
          satSpy = window.open("spy.php?channel="+channel.replace(/ /, '%20'),"satSpy","width=720,height=430,left=30,top=50,dependent=yes,scrollbars=yes");
          window.satSpy.focus();
        }
        
        function closeWindows()
        {
          if(window.satSpy)window.satSpy.close();
        }
      /*]]>*/
      </script>
    <!--
      $Id: index.tpl,v 1.37.2.12 2004/05/08 18:49:46 letreo Exp $
    -->
  </head>
  <body onload="focusNick()" onunload="closeWindows()">
    <div class="content">
      <h1><?=$_SESSION['translator']->out('WELCOME')?>!</h1>
      <p>
        <strong><?=$TEMPLATE_OUT['nickname']?></strong> <?=$TEMPLATE_OUT['greeting']?>
        <br /><?=$_SESSION['translator']->out('INTRO')?>
      </p>
      <div class="contentBox">
        <form action="index.php" method="post">
          <dl>
            <dt class="contentBoxTitle">&nbsp;<?=$_SESSION['translator']->out('LOGIN')?></dt>
            <dd>
              <table border="0">
                <tbody class="loginTable">
                  <tr>
                    <th class="formFieldLabel" colspan="2"><?=$_SESSION['translator']->out('NICKNAME')?>:</th>
                    <td><input tabindex="1" class="loginInput" name="nick" type="text" value="<?=$_GET['nickname']?>" <?=$TEMPLATE_OUT['disable']?> /></td>
                    <td class="helpIcon"><a class="imageLink" title="<?=$_SESSION['translator']->out('HELP')?>" onclick="openHelpWindow('<?=$_SESSION['translator']->out('HINT_NICKNAME',true)?>',event.screenX,event.screenY)" href="#"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/help.gif" alt="?" border="0" /></a></td>
                  </tr>
                  <tr>
                    <th class="formFieldLabel" colspan="2"><?=$_SESSION['translator']->out('PASSWORD')?>:</th>
                    <td><input tabindex="2" class="loginInput" name="password" type="password" value="<?=$_GET['password']?>" <?=$TEMPLATE_OUT['disable']?> /></td>
                    <td class="helpIcon"><a class="imageLink" title="<?=$_SESSION['translator']->out('HELP')?>" href="#" onclick="openHelpWindow('<?=$_SESSION['translator']->out('HINT_PASSWORD',true)?>',event.screenX,event.screenY)"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/help.gif" alt="?" border="0" /></a></td>
                  </tr>
                  <tr>
                    <th class="formFieldLabel"><?=$_SESSION['translator']->out('CHANNEL')?>:</th>
                    <td style="text-align:right;vertical-align:middle">
                      <?=$TEMPLATE_OUT['spy_icon']?>
                    </td>
                    <td>
                      <select tabindex="3" class="loginInput" name="channel">
                        <?=$TEMPLATE_OUT['option_list_of_channels']?>
                      </select>
                      <?=$_SESSION['session_post']?>
                    </td>
                    <td class="helpIcon">
                      <a class="imageLink" title="<?=$_SESSION['translator']->out('HELP')?>" href="#" onclick="openHelpWindow('<?=$_SESSION['translator']->out('HINT_CHANNELS',true)?>',event.screenX,event.screenY)">
                        <img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/help.gif" alt="?" border="0" />
                      </a>
                    </td>
                  </tr>
                  <tr>
                    <th class="formFieldLabel" colspan="2"><?=$_SESSION['translator']->out('STORE_ACCOUNT_DATA')?>:</th>
                    <td>
                      <input style="margin:0" type="checkbox" tabindex="4" name="storeAccountData" <?=$TEMPLATE_OUT['disable']?> />
                    </td>
                    <td>&nbsp;</td>
                  </tr>
                  <tr>
                    <td colspan="3" style="text-align: right">
                      <input tabindex="5" class="submit" name="account_data" type="submit" value="<?=$_SESSION['translator']->out('GO')?>" />
                    </td>
                    <td>&nbsp;</td>
                  </tr>
                </tbody>
              </table>
            </dd>
          </dl>
        </form>
      </div>
      <span>
       <?php if( $_SESSION['chat']->get_show_profile() ){?>
        <a class="contentLink" href="register.php?<?=$_SESSION['session_get']?>"><?=$_SESSION['translator']->out('REGISTER')?>!</a>&nbsp;|
        <a class="contentLink" href="send_passwd.php?<?=$_SESSION['session_get']?>"><?=$_SESSION['translator']->out('FORGOT_PASSWORD')?></a>&nbsp;|
       <?php }?>
        <a class="contentLink" href="regulars.php?<?=$_SESSION['session_get']?>"><?=$_SESSION['translator']->out('REGULARS')?></a>&nbsp;|
        <a class="contentLink" onclick="openWindow()" href="help.php?sat=1&amp;<?=$_SESSION['session_get']?>" target="satHelp"><?=$_SESSION['translator']->out('HELP')?></a>
      </span>
      <br />
      <div class="contentBox">
        <dl>
          <dt class="contentBoxTitle">&nbsp;<?=$_SESSION['translator']->out('CHATTER_COUNT')?>: &nbsp;<?=$TEMPLATE_OUT['count_chatters_online']?></dt>
          <dd>
            <br />
            <table cellpadding="0" cellspacing="0">
              <tbody>
                <?=$TEMPLATE_OUT['chatters_online_list']?>
              </tbody>
            </table>
          </dd>
        </dl>
      </div>
      <!-- remove the following <div>, if you gonna start your community -->
      <!-- begin -->
      <div style="padding-top: 20px">
        <span style="font: 10px Verdana, sans-serif;">
          <?=$_SESSION['translator']->out('ADMIN_HINT')?>
        </span><br />
        <?php if($TEMPLATE_OUT['operator_passwd']){?>
        <script type="text/javascript">
          document.forms[0].elements['nick'].value = 'operator';
          document.forms[0].elements['password'].value = '<?=$TEMPLATE_OUT['operator_passwd']?>';
          alert('Please remember to delete install.php or rename it so it can\'t be executed!');
        </script>
        <span style="color: #f00; font-size: 15px; font-weight: bold">
          <?=$_SESSION['translator']->out('IMPORTANT')?>! 
          <?=$_SESSION['translator']->out('OPERATOR_PASSWORD')?>: <?=$TEMPLATE_OUT['operator_passwd']?>
        </span><br />
        <span style="font: 12px Verdana, sans-serif;text-decoration: blink; font-weight: bold">
          <?=$_SESSION['translator']->out('MAKE_NOTE')?>
        </span>
        <?php }?>
      </div>
      <!--end-->
    </div>
    <div class="menu">
      <div class="flagBox"><?=$TEMPLATE_OUT['lang_switch']?></div>
      <div class="menuBox">
        <dl>
          <dt class="menuBoxTitle">&nbsp;<?=$_SESSION['translator']->out('STATISTICS')?></dt>
          <dd>
            <table cellpadding="0" cellspacing="0" border="0">
              <thead>
                <tr><th align="left" colspan="2"><?=$_SESSION['translator']->out('CHAT')?></th></tr>
              </thead>
              <tbody>
                <tr><td colspan="2">&nbsp;</td></tr>
                <tr>
                  <td valign="top" class="menuBoxItemOdd"><?=$_SESSION['translator']->out('ONLINE_COUNT_LAST24h')?>:&nbsp;</td>
                  <td valign="top" class="menuBoxItemOdd"><?=$TEMPLATE_OUT['online_count_last24h']?></td>
                </tr>
                <tr>
                  <td valign="top" class="menuBoxItemEven"><?=$_SESSION['translator']->out('ONLINE_TIME_AVG')?>:&nbsp;</td>
                  <td valign="top" class="menuBoxItemEven"><?=$TEMPLATE_OUT['online_time_avg']?> min.</td>
                </tr>
                <tr>
                  <td valign="top" class="menuBoxItemOdd"><?=$_SESSION['translator']->out('REGISTERED_COUNT')?>:&nbsp;</td>
                  <td valign="top" class="menuBoxItemOdd"><?=$TEMPLATE_OUT['registered_count']?></td>
                </tr>
                <tr>
                  <td valign="top" class="menuBoxItemEven"><?=$_SESSION['translator']->out('LAST_REGISTERED')?>:&nbsp;</td>
                  <td valign="top" class="menuBoxItemEven">
                    <strong><?=$TEMPLATE_OUT['last_registered']['NICK']?></strong>
                    (<?=$TEMPLATE_OUT['last_registered']['REGTIME']?>)
                  </td>
                </tr>
              </tbody>
            </table>
            &nbsp;<br />
            <table cellpadding="0" cellspacing="0" border="0">
              <thead>
                <tr><th align="left" colspan="2"><?=$_SESSION['translator']->out('CHATMAIL')?></th></tr>
              </thead>
              <tbody>
                <tr><td colspan="2">&nbsp;</td></tr>
                <tr>
                  <td valign="top" class="menuBoxItemOdd"><?=$_SESSION['translator']->out('MAIL_COUNT')?>:&nbsp;</td>
                  <td valign="top" class="menuBoxItemOdd"><?=$TEMPLATE_OUT['mail_count']?></td>
                </tr>
                <tr>
                  <td valign="top" class="menuBoxItemEven"><?=$_SESSION['translator']->out('MAIL_COUNT_LAST_24h')?>:&nbsp;</td>
                  <td valign="top" class="menuBoxItemEven"><?=$TEMPLATE_OUT['mail_count_last_24h']?></td>
                </tr>
              </tbody>
            </table>
          </dd>
        </dl>
      </div>
      <div class="buttonBox">
        <p>
          <a href="http://phpopenchat.org/"><img alt="POC Logo" src="<?=$_SESSION['template']->get_theme_path()?>/images/buttons/poc_button.gif" height="33" width="90" border="0" /></a>
          
          <a href="http://validator.w3.org/check/referer">
            <img src="<?=$_SESSION['template']->get_theme_path()?>/images/buttons/valid-xhtml10.png" alt="Valid XHTML 1.0!" height="31" width="88" border="0" /></a>
           
          <a href="http://jigsaw.w3.org/css-validator/">
            <img src="<?=$_SESSION['template']->get_theme_path()?>/images/buttons/vcss.png" alt="Valid CSS!" height="31" width="88" border="0" /></a>

          <a title="FOAF - RDF/XML 'Semantic Web'" href="rdf.php"><!--http://www.apocalypse.org/~nicole/FOAF/foaf-website2/index.html-->
            <img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/foaf.gif" alt="FOAF - RDF/XML 'Semantic Web'" height="14" width="26" border="0" /></a>
        </p>
      </div>
    </div>
  </body>
</html>