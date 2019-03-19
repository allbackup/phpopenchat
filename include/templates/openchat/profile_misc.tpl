<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['translator']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content="<?=$_SESSION['template']->get_content_type()?>; charset='<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>'" />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <!--
      $Id: profile_misc.tpl,v 1.1.2.2 2004/02/25 22:08:50 letreo Exp $
    -->
    <script type="text/javascript">
    /*<![CDATA[*/

    /*]]>*/
    </script>
  </head>
  <body>
    <div class="contentBox" style="width:97%;height:92%">
    
      <?php if(isset($_GET['action']) && $_GET['action']=='del'){?>
        <?=$_SESSION['translator']->out('REALLY_QUESTION')?>
        <form action="profile_misc.php" method="post">
          <input name="title" value="<?=$TEMPLATE_OUT['title']?>" type="hidden" />
          <input name="content" value="<?=$TEMPLATE_OUT['content']?>" type="hidden" />
          <input class="submit" style="margin-top:20px" name="del" type="submit" value="<?=$_SESSION['translator']->out('DELETE')?>" />&nbsp;&nbsp;
          <input class="submit" style="margin-top:20px" type="submit" onclick="window.close();return false" value="<?=$_SESSION['translator']->out('CANCEL')?>" />
        </form>
      <?php }else{?>
    
      <form action="profile_misc.php" method="post">
          <dl>
            <dt class="contentBoxTitle"><?=$_SESSION['translator']->out('MISCELLANEOUS')?></dt>
            <dd>
              <table>
                <tbody>
                  <tr>
                    <td>
                    <?php if(isset($_GET['action']) && $_GET['action']=='add'){?>
                      <input class="profileInput" style="width:300px" name="title" value="<?=$TEMPLATE_OUT['title']?>" type="text" maxlength="25" />
                    <?php }else{?>
                      <strong><?=$TEMPLATE_OUT['title']?></strong>
                      <input name="title" value="<?=$TEMPLATE_OUT['title']?>" type="hidden" />
                    <?php }?>
                    </td>
                  </tr>
                  <tr>
                    <td>
                      <textarea class="profileInput" style="width:300px" name="content" rows="4"><?=$TEMPLATE_OUT['content']?></textarea>
                    </td>
                  </tr>
                  <tr>
                    <td colspan="2">
                      <input class="submit" style="margin-top:20px" name="<?=$_GET['action']?>" type="submit" value="<?=$_SESSION['translator']->out('SAVE')?>" />
                    </td>
                  </tr>
                </tbody>
              </table>
            </dd>
          </dl>
      </form>
      <?php }?>
    </div>
  </body>
</html>