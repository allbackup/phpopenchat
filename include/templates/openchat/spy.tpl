<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
  <title><?=$_SESSION['translator']->out('CHANNEL')?>: <?=$_GET['channel']?></title>
  <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/output.css" />
  <script type="text/javascript">
  /*<![CDATA[*/

  /*]]>*/
  </script>
</head>
<body>
<h1 style="font-size:14px;font-weight:bold"><?=$_SESSION['translator']->out('CHANNEL')?>: <?=$_GET['channel']?></h1>
  <div style="width:25%;float:right">
    <ul>
      <?=$TEMPLATE_OUT['chatters']?>
    </ul>
  </div>
  <div style="width:75%;border-right:1px dotted #000">
    <?=$TEMPLATE_OUT['lines']?>
  </div>
</body>
</html>