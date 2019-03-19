<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['chat']->get_language()?>" xml:lang="<?=$_SESSION['chat']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <!--
      $Id: chatter.tpl,v 1.2.2.10 2004/08/26 11:58:00 letreo Exp $
    -->
    <script type="text/javascript">
      <?include($_SESSION['template']->get_tmpl_sys_path().'/js/chatter.js.php')?>
    </script>
  </head>
  <body onmouseover="parent.setPOCsFocus(true)" onmouseout="parent.setPOCsFocus(false)">
    <div class="content" style="width:90%;padding:0;margin:0">
      <form action="" name="chattersOnline">
        <input class="chatterCountField" style="width:100%;border:none;font-size:10px" type="text" name="chatterCount" value="connecting..." readonly="readonly" /><br />
        <select style="height:340px;width:120px;border:none;font-size:10px" name="chatters" multiple="multiple" onchange="showContextMenu(getNick(this.selectedIndex),this.selectedIndex)"></select>
      </form>
    </div>
  </body>
</html>
