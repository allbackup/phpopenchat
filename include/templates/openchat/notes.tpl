<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['chat']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['chat']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <title><?=$_SESSION['translator']->out('CHATTER_NOTES')?>: <?=$_POST['nick']?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <!--
      $Id: notes.tpl,v 1.4.2.2 2004/02/25 22:08:50 letreo Exp $
    -->
  </head>
  <body>
    <div class="satContent">
      <h1><?=$_SESSION['translator']->out('CHATTER_NOTES')?>: <?=$_POST['nick']?></h1>
      <p><?=$_SESSION['translator']->out('HINT_NOTES')?></p>
      <div class="satContentBox">
        <form action="notes.php" method="post">
          <table width="100%">
            <thead><tr><td><span class="success"><?=$TEMPLATE_OUT['success']?></span></td></tr></thead>
            <tbody>
              <tr>
                <td style="text-align:center;">
                  <textarea  name="note" style="width:90%;font:10px verdana, arial, sans-serif;" rows="14"><?=$TEMPLATE_OUT['note']?></textarea>
                  <input name="nick" type="hidden" value="<?=$_POST['nick']?>" />
                </td>
              </tr>
              <tr>
                <td style="text-align:center;">
                  <input name="update" type="submit" value="<?=$_SESSION['translator']->out('UPDATE_NOTES')?>" />
                </td>
              </tr>
            </tbody>
          </table>
        </form>
      </div>
    </div>
    <div class="menu">
      <ul>
        <li>
          <a href="#" onclick="window.close()"><?=$_SESSION['translator']->out('CLOSE_WINDOW')?></a>
        </li>
      </ul>
    </div>
  </body>
</html>