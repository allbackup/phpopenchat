<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['chat']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['chat']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
      <script type="text/javascript">
      /*<![CDATA[*/
        parent.output.document.writeln('<?=$TEMPLATE_OUT['all_lines']?>');
        <?=$TEMPLATE_OUT['alert_recipient']?>
        <?=$TEMPLATE_OUT['js_debug']?>
      /*]]>*/
      </script>
    <!--
      $Id: private_getlines.tpl,v 1.3.2.2 2004/02/25 22:08:50 letreo Exp $
    -->
  </head>
  <body onload="<?=$TEMPLATE_OUT['js_onload']?>" onunload="<?=$TEMPLATE_OUT['js_onunload']?>"><script type="text/javascript">parent.serialize_privat_refresh = 0</script>
  </body>
</html>