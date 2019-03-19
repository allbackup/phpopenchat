<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Frameset//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd">
<html lang="<?=$_SESSION['translator']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
    <meta http-equiv="Content-type" content="<?=$_SESSION['template']->get_content_type()?>; charset='<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>'" />
    <script type="text/javascript">
      <?include($_SESSION['template']->get_tmpl_sys_path().'/js/frameset.js.php')?>
    </script>
    <style type="text/css">
    /*<![CDATA[*/
    
    /*]]>*/
    </style>
  </head>
  <frameset rows="78%,*,0,0" onunload="closeWindows();logout()">
    <frameset cols="85%,*">
      <frame name="output" src="output.php?<?=$_SESSION['session_get']?>" frameborder="0" />
      <frame name="chatter" src="chatter.php?<?=$_SESSION['session_get']?>" frameborder="0" noresize="noresize" scrolling="no" />
    </frameset>
    <frame name="input" src="input.php?<?=$_SESSION['session_get']?>" frameborder="0" noresize="noresize" scrolling="no" />
    <frame name="getlines" src="getlines.php?login=1&amp;<?=$_SESSION['session_get']?>" noresize="noresize" frameborder="0" />
    <frame name="dummy" src="output.php" frameborder="0" noresize="noresize" />
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