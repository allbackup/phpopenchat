<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['chat']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['chat']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
      <link title="Default" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" rel="stylesheet" media="all" />
      <script type="text/javascript">
      /*<![CDATA[*/
      
      /*]]>*/
      </script>
    <!--
      $Id: pn_login_failure.tpl,v 1.1.2.2 2004/02/25 22:08:50 letreo Exp $
    -->
  </head>
  <body class="body">
    <div class="content">
      <h1><?=$_SESSION['translator']->out('WELCOME')?>!</h1>
      <div class="contentBox">
        <dl>
          <dt class="contentBoxTitle">&nbsp;
            <?=$_SESSION['translator']->out('PN_NOT_LOGGED_IN')?>
          </dt>
          <dd>
            <p>
              <?=$_SESSION['translator']->out('PN_HINT_NOT_LOGGED_IN')?>
            </p>
            <p>
              <a href="index.php"><?=$_SESSION['translator']->out('LOGIN')?></a><br />
              <a href="user.php"><?=$_SESSION['translator']->out('REGISTRATION')?></a>
            </p>
          </dd>
        </dl>
      </div>
    </div>
    <div class="menu">
    
    </div>
  </body>
</html>