<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['chat']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
      <script type="text/javascript">
      /*<![CDATA[*/
        var clickCount = 0;
        if( parent && parent.output )
        {
          parent.output.document.writeln('<?=$TEMPLATE_OUT['show_message_locally']?>');
        }

        function checkValue( checkValue )
        {
          if(checkValue.value == '' || clickCount > 3) return false;
          return true;
        }

        function countClick()
        {
          clickCount += 1;
        }
      /*]]>*/
      </script>
    <!--link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/input.css" /-->
    <!--
      $Id: private_input.tpl,v 1.2.2.2 2004/02/25 22:08:50 letreo Exp $
    -->
  </head>
  <body onload="document.forms[0].elements[0].focus();" style="background-color:#fff;border-top: 1px solid blue;"><br />
    <div style="margin:0;padding:0;">
      <form action="private_input.php" method="post">
        <p style="margin:0;padding:0;">
          <input style="width: 350px" name="line" type="text" value="" />
          <input type="hidden" name="channel" value="<?=$TEMPLATE_OUT['channel']?>" />
          <input type="hidden" name="recipient" value="<?=$TEMPLATE_OUT['recipient']?>" />
          <input type="submit" value="<?=$_SESSION['translator']->out('GO')?>" onclick="countClick();return checkValue(document.forms[0].elements['line'])" />
          <input name="<?=session_name()?>" type="hidden" value="<?=session_id()?>" />
        </p>
      </form>
    </div>
  </body>
</html>