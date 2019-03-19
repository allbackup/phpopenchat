<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['chat']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <title></title>
      <script type="text/javascript">
      /*<![CDATA[*/
        <?=$TEMPLATE_OUT['js_update_chatter']?>
        while(typeof(parent.frames['output']) == "undefined") parent.delay(500);
        if(parent.is_opera && !parent.is_opera7up) {
          parent.lines += '<?=$TEMPLATE_OUT['all_lines']?>';
          parent.output.document.writeln(parent.lines);
        } else {
          parent.output.document.writeln('<?=$TEMPLATE_OUT['all_lines']?>');
        }
        parent.setTitle();
        <?=$TEMPLATE_OUT['alert_recipient']?>
        <?=$TEMPLATE_OUT['js_debug']?>
      /*]]>*/
      </script>
  </head>
  <body onload="parent.serialize_refresh=0;<?=$TEMPLATE_OUT['js_onload']?>"><?=$TEMPLATE_OUT['sound_recipient']?><?php if(!empty($TEMPLATE_OUT['debug'])) print $TEMPLATE_OUT['debug'];?></body>
</html>