<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['translator']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['chat']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <?=$TEMPLATE_OUT['meta_refresh']?>
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <script type="text/javascript">
    /*<![CDATA[*/
      <?=$TEMPLATE_OUT['jScript']?>
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
      $Id: register.tpl,v 1.16.2.5 2004/03/04 20:35:48 letreo Exp $
    -->
  </head>
  <body onload="if(document.forms[0] &amp;&amp; document.forms[0].elements['nickname'])document.forms[0].elements['nickname'].focus()">
    <div class="content">
      <h1><?=$_SESSION['translator']->out('REGISTRATION')?></h1>
      <div class="contentBox">
       <?php if(!$TEMPLATE_OUT['registration_successfully']){?>
        <form action="register.php" method="post">
        <dl>
          <dt class="contentBoxTitle"><?=$_SESSION['translator']->out('FILLOUT_TO_REGISTER')?></dt>
          <dd>
            <div style="width:100%;text-align:right;font-size:11px"><span style="color:#f00">*</span>&nbsp;<?=$_SESSION['translator']->out('OPTIONAL')?></div>
            <fieldset>
              <legend><?=$_SESSION['translator']->out('ACCOUNT_DATA')?></legend>
              <table border="0" cellpadding="0" cellspacing="0">
                <thead><tr><td><span class="success"><?=$TEMPLATE_OUT['success']?></span></td></tr></thead>
                <tbody>
                  <tr>
                    <th class="formFieldLabel" style="width:120px">&nbsp;<br /><?=$_SESSION['translator']->out('NICKNAME')?>:&nbsp;</th>
                    <td>
                      <span class="error"><?php if(isset($TEMPLATE_OUT['errors']['nickname']))echo$TEMPLATE_OUT['errors']['nickname']?></span><br />
                      <input class="registerInput" type="text" name="nickname" value="<?=$_POST['nickname']?>" tabindex="1" />
                    </td>
                    <td class="helpIcon">&nbsp;<br />
                      <a href="#" onclick="openHelpWindow('<?=$_SESSION['translator']->out('HINT_REG_NICKNAME')?>',event.screenX,event.screenY)"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/help.gif" alt="?" border="0" /></a>
                    </td>
                  </tr>
                  <tr>
                    <th class="formFieldLabel">&nbsp;<br /><?=$_SESSION['translator']->out('PASSWORD')?>:&nbsp;</th>
                    <td>
                      <span class="error"><?php if(isset($TEMPLATE_OUT['errors']['password']))echo$TEMPLATE_OUT['errors']['password']?></span><br />
                      <input class="registerInput" name="password" type="text" value="<?=$_POST['password']?>" tabindex="2" />
                    </td>
                    <td class="helpIcon">&nbsp;<br />
                      <a href="#" onclick="openHelpWindow('<?=$_SESSION['translator']->out('HINT_REG_PASSWORD')?>',event.screenX,event.screenY)"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/help.gif" alt="?" border="0" /></a>
                    </td>
                  </tr>
                </tbody>
              </table>
            </fieldset>
            <fieldset>
              <legend><?=$_SESSION['translator']->out('INDIVIDUAL_DATA')?></legend>
              <table border="0" cellpadding="0" cellspacing="0">
                <tbody>
                  <tr>
                    <th class="formFieldLabel" style="width:120px">&nbsp;<br /><?=$_SESSION['translator']->out('NAME')?>:&nbsp;</th>
                    <td>
                      <span class="error"><?php if(isset($TEMPLATE_OUT['errors']['name']))echo$TEMPLATE_OUT['errors']['name']?></span><br />
                      <input class="registerInput" name="name" type="text" value="<?=$_POST['name']?>" tabindex="3" />
                    </td>
                  </tr>
                  <tr>
                    <th class="formFieldLabel">&nbsp;<br /><?=$_SESSION['translator']->out('EMAIL')?>:&nbsp;</th>
                    <td>
                      <span class="error">
                        <?php if(isset($TEMPLATE_OUT['errors']['email']))echo$TEMPLATE_OUT['errors']['email']?>
                        <?php if(isset($TEMPLATE_OUT['errors']['nomailhost']))echo$TEMPLATE_OUT['errors']['nomailhost']?>
                      </span><br />
                      <input class="registerInput" name="email" type="text" value="<?=$_POST['email']?>" tabindex="4" />
                    </td>
                  </tr>
                  <tr>
                    <th class="formFieldLabel">&nbsp;<br /><?=$_SESSION['translator']->out('PICTURE_URL')?>:<span style="color:#f00">*</span>&nbsp;</th>
                    <td>
                      <span class="error"><?php if(isset($TEMPLATE_OUT['errors']['pictureURL']))echo$TEMPLATE_OUT['errors']['pictureURL']?></span><br />
                      <input class="registerInput" name="pictureURL" type="text" value="<?=$_POST['pictureURL']?>" tabindex="5" />
                    </td>
                  </tr>
                </tbody>
              </table>
              </fieldset>
              <div style="padding-left:132px;padding-top:10px">
			  	<?=$_SESSION['session_post']?>
                <input class="submit" name="register" type="submit" value="<?=$_SESSION['translator']->out('REGISTER')?>!" />
              </div>
            </dd>
          </dl>
        </form>
       <?php }else{?>
        <span class="success">
        <?=$TEMPLATE_OUT['success']?> 
        <?=$TEMPLATE_OUT['confirmation_message']?>
        </span>
       <?php }?>
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