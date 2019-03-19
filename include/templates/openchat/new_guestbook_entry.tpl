<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['chat']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content="<?=$_SESSION['template']->get_content_type()?>; charset='<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>'" />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <!--
      $Id: new_guestbook_entry.tpl,v 1.1.2.2 2004/02/25 22:08:50 letreo Exp $
    -->
  </head>
  <body>
    <div class="contentBox" style="width:97%;height:92%">
      <form action="new_guestbook_entry.php" method="post">
          <dl>
            <dt class="contentBoxTitle"><?=$_SESSION['translator']->out('GUESTBOOK_NEW_ENTRY')?></dt>
            <dd>
             <?php if($TEMPLATE_OUT['success']){?>
             <p>
              <span class="success"><?=$_SESSION['translator']->out('GUESTBOOK_ENTRY_SAVED')?></span>
             </p>
             <a href="#" onclick="opener.document.location.href='userpage.php?nick=<?=urlencode($_POST['nickname'])?>&amp;rand=<?=rand(0,99)?>#gb';window.close()"><?=$_SESSION['translator']->out('CLOSE_WINDOW')?></a>
             <?php }else{?>
              <table>
                <tbody>
                  <tr>
                    <td>
                      <input name="nickname" type="hidden" value="<?=$_GET['nickname']?>" />
                      <textarea class="profileInput" style="width:300px" name="content" rows="4"></textarea>
                    </td>
                  </tr>
                  <tr>
                    <td colspan="2">
                      <input class="submit" style="margin-top:20px" name="add" type="submit" value="<?=$_SESSION['translator']->out('SAVE')?>" />
                    </td>
                  </tr>
                </tbody>
              </table>
             <?php }?>
            </dd>
          </dl>
      </form>
    </div>
  </body>
</html>