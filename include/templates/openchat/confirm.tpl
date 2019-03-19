<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['translator']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <?=$TEMPLATE_OUT['meta_refresh']?>
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <!--
      $Id: confirm.tpl,v 1.5.2.3 2004/02/25 22:08:50 letreo Exp $
    -->
  </head>
  <body>
    <div class="content">
      <h1><?=$_SESSION['translator']->out('CONFIRMATION')?></h1>
      <div class="contentBox">
        <dl>
          <dt class="contentBoxTitle"><?=$_SESSION['translator']->out('STATUS_CONFIRMATION')?></dt>
          <dd>
            <?=$TEMPLATE_OUT['confirmation_message']?>
          </dd>
        </dl>
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