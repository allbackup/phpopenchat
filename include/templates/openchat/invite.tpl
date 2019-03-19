<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['chat']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['chat']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content="<?=$_SESSION['template']->get_content_type()?>; charset='<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>'" />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <!--
      $Id: invite.tpl,v 1.17.2.2 2004/02/25 22:08:50 letreo Exp $
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
    <h1><?=$_SESSION['translator']->out('INVITE_CHATTERS')?></h1>
    <p><?=$_SESSION['translator']->out('HINT_INVITE_CHATTERS')?></p>
      <div class="contentBox">
        <form action="invite.php" method="post">
          <table border="0" cellpadding="0" cellspacing="0">
            <thead>
              <tr>
                <th class="title"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/invite_chatter.gif" alt="<?=$_SESSION['translator']->out('INVITED_CHATTERS')?>" />&nbsp;<?=$_SESSION['translator']->out('INVITED_CHATTERS')?></th>
                <td>&nbsp;</td>
                <th class="title"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/chatter.gif" alt="<?=$_SESSION['translator']->out('DISINVITED_CHATTERS')?>" /><?=$_SESSION['translator']->out('DISINVITED_CHATTERS')?></th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="vertical-align: bottom"><?=$_SESSION['translator']->out('CHOOSEN')?>:</td>
                <td>&nbsp;</td>
                <td><input style="width:145px" onfocus="clearText(this)" class="selectBox" name="nick_constraint" type="text" value="<?=$_POST['nick_constraint']?>" /></td>
              </tr>
              <tr>
                <td>
                  <select style="width:146px" class="selectBox" name="invited_chatter" size="10">
                    <?=$TEMPLATE_OUT['invited_chatters_option_list']?>
                  </select>
                </td>
                <td width="40">
                  <input src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/trash.gif" title="<?=$_SESSION['translator']->out('DISINVITE_CHATTER')?>" type="image" name="del" /><br />
                  <input type="hidden" name="add" value="" /><br />
                </td>
                <td>
                  <select title="<?=$_SESSION['translator']->out('INVITE_CHATTER')?>" style="width:146px" class="selectBox" name="disinvited_chatter" size="10" onchange="document.forms[0].elements['add'].value=1;submit()">
                    <?=$TEMPLATE_OUT['option_list_of_disinvited_chatters']?>
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