<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['translator']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['chat']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
      <script type="text/javascript">
      /*<![CDATA[*/
        function openHelpWindow(helpText,coordX,coordY)
        {
          coordY -= 210;
          satHelp = window.open('','satHelp','width=140,height=170,screenX='+coordX+',screenY='+coordY+',top='+coordY+',left='+coordX+',dependent=yes,scrollbars=no');
          
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
      /*]]>*/
      </script>
    <!--
      $Id: send_passwd.tpl,v 1.6.2.2 2004/02/25 22:08:50 letreo Exp $
    -->
  </head>
  <body onload="document.forms[0].elements['nickname'].focus()">
    <div class="content">
      <h1><?=$_SESSION['translator']->out('FORGOT_PASSWORD')?></h1>
      <div class="contentBox">
        <form action="send_passwd.php" method="post">
          <dl>
            <dt class="contentBoxTitle"><?=$_SESSION['translator']->out('RETRIEVE_PASSWORD')?></dt>
            <dd>
              <span class="error">
                <?=$TEMPLATE_OUT['error']?>
              </span>
              <span class="success">
                <?=$TEMPLATE_OUT['success']?>
              </span>&nbsp;<br />
              <table border="0" cellspacing="0" cellpadding="0">
                <tbody>
                  <tr>
                    <th class="formFieldLabel">
                      <?=$_SESSION['translator']->out('NICKNAME')?>:&nbsp;
                    </th>
                    <td>
                      <input name="nickname" type="text" value="" />
                    </td>
                    <td class="helpIcon">
                      <a href="#" onclick="openHelpWindow('<?=$_SESSION['translator']->out('FORGOT_PASSWORD_HINT')?>',event.screenX,event.screenY)"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/help.gif" alt="?" border="0" /></a>
                    </td>
                  </tr>
                  <tr>
                    <td>&nbsp;</td>
                    <td colspan="2">&nbsp;<br />
                      <input class="submit" type="submit" value="<?=$_SESSION['translator']->out('GO')?>" />
                    </td>
                  </tr>
                </tbody>
              </table>
            </dd>
          </dl>
        </form>
      </div>
    </div>
    <div class="menu">
      <ul>
        <li>
          <a href="index.php"><?=$_SESSION['translator']->out('GOTO_HOME')?></a>
        </li>
      </ul>
    </div>
  </body>
</html>