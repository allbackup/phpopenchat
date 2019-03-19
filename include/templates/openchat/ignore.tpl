<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['chat']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['chat']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content="<?=$_SESSION['template']->get_content_type()?>; charset='<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>'" />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <!--
      $Id: ignore.tpl,v 1.19.2.2 2004/02/25 22:08:50 letreo Exp $
    -->
    <script type="text/javascript">
    /*<![CDATA[*/
      function clearText(field){
        if (field.value=="<?=$_SESSION['translator']->out('RESTRICT')?>")
          field.value = "";
      }       
    /*]]>*/
    </script>
  </head>
  <body>
    <div class="satContent">
    <h1><?=$_SESSION['translator']->out('IGNORE_CHATTERS')?></h1>
    <p><?=$_SESSION['translator']->out('HINT_IGNORE_CHATTERS')?></p>
      <div class="contentBox">
        <form action="ignore.php" method="post">
          <table border="0" cellpadding="0" cellspacing="0">
            <thead>
              <tr>
                <th class="title"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/ignore_list.gif" alt="<?=$_SESSION['translator']->out('IGNORED_CHATTER')?>" />&nbsp;<?=$_SESSION['translator']->out('IGNORED_CHATTER')?></th>
                <td>&nbsp;</td>
                <th class="title"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/chatter.gif" alt="<?=$_SESSION['translator']->out('UNIGNORED_CHATTER')?>" /><?=$_SESSION['translator']->out('UNIGNORED_CHATTER')?></th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="vertical-align: bottom"><?=$_SESSION['translator']->out('CHOOSEN')?>:</td>
                <td>&nbsp;</td>
                <td><input style="width:145px" onfocus="clearText(this)" name="nick_constraint" type="text" value="<?=$_POST['nick_constraint']?>" /></td>
              </tr>
              <tr>
                <td>
                  <select style="width:146px" class="selectBox" name="ignored_chatter" size="10">
                    <?=$TEMPLATE_OUT['ignored_chatters_option_list']?>
                  </select>
                </td>
                <td width="40">

<input src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/trash.gif" title="<?=$_SESSION['translator']->out('UNIGNORE_CHATTER')?>" alt="<?=$_SESSION['translator']->out('UNIGNORE_CHATTER')?>" type="image" name="del" /><br />
                </td>
                <td>
                  <input name="add" type="hidden" value="" />
                  <select title="<?=$_SESSION['translator']->out('IGNORE_CHATTER')?>" style="width:146px" class="selectBox" name="unignored_chatter" size="10" onchange="document.forms[0].elements['add'].value=1;submit()">
                    <?=$TEMPLATE_OUT['option_list_of_channel_chatters']?>
                  </select>
                  <?=$_SESSION['session_post']?>
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