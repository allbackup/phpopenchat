<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['translator']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content="<?=$_SESSION['template']->get_content_type()?>; charset='<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>'" />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
      <link rel="stylesheet" title="Default" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <!--
      $Id: admin_index.tpl,v 1.10.2.2 2004/02/25 22:08:50 letreo Exp $
    -->
    <style type="text/css">
    /*<![CDATA[*/
      .moderator{color: #f00;}
      .vip{color: #22aa00;}
      .operator {
        font: 11px verdana, arial, sans-serif;
        color: #f0f;
        text-decoration: blink;
      }
      .chatter{color: #00f;}
      .disabled{
        color: #777;
        font-style: italic;
      }
    /*]]>*/
    </style>
    <script type="text/javascript">
    /*<![CDATA[*/
      function show_details(data,coordX,coordY)
      {
        satData = window.open('','satData','width=550,height=120,screenX='+coordX+',screenY='+coordY+',top='+coordY+',left='+coordX+',dependent=yes,scrollbars=no');
        satData.document.writeln('<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">');
        satData.document.writeln('<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>" lang="<?=$_SESSION['translator']->get_language()?>">');
        satData.document.writeln('<head><title>User data<\/title><\/head>');
        satData.document.writeln('<body style="margin-top:0px;padding-top:0px;background-color:#fff;font-size:10px;">');
        satData.document.writeln('<strong><?=$_SESSION['translator']->out('NICKNAME')?>:<\/strong> '+data[0]+'<br \/>');
        satData.document.writeln('<strong><?=$_SESSION['translator']->out('REGTIME')?>:<\/strong> '+data[2]+'<br \/>');
        satData.document.writeln('<strong><?=$_SESSION['translator']->out('LAST_CHANNEL')?>:<\/strong> '+data[3]+'<br \/>');
        satData.document.writeln('<strong><?=$_SESSION['translator']->out('LAST_ACTIVE_TIME')?>:<\/strong> '+data[1]+'<br \/>');
        satData.document.writeln('<strong><?=$_SESSION['translator']->out('LAST_HOST')?>:<\/strong> '+data[4]+'<br \/>');
        satData.document.writeln('<strong><?=$_SESSION['translator']->out('LAST_IP')?>:<\/strong> '+data[5]+'<br \/>');
        satData.document.writeln('<strong><?=$_SESSION['translator']->out('LAST_REFERER')?>:<\/strong> <a href="'+data[6]+'" target="_new">'+data[6]+'</a><br \/>');
        satData.document.writeln('<strong><?=$_SESSION['translator']->out('LAST_USER_AGENT')?>:<\/strong> '+data[7]+'<br \/>');
        satData.document.writeln('<strong><?=$_SESSION['translator']->out('LAST_SESSIONID')?>:<\/strong> '+data[8]+'<br \/>');
        satData.document.writeln('<strong><?=$_SESSION['translator']->out('PICTURE_URL')?>:<\/strong> <a href="'+data[9]+'" target="_new">'+data[9]+'</a><br \/>');
        satData.document.writeln('');
        satData.document.writeln('<\/body>');
        satData.document.writeln('<\/html>');
        satData.focus();
      }
    /*]]>*/
    </script>
  </head>
  <body>
    <div class="satContent">
      <h1><?=$_SESSION['translator']->out('WELCOME_ADMIN')?>!</h1>
      <div class="contentBox">
        <form action="index.php" method="post">
          <dl>
            <dt class="contentBoxTitle"><?=$_SESSION['translator']->out('CHANNEL_ADMIN')?></dt>
            <dd>
              <table>
                <tbody>
                  <tr>
                    <th>Name:</th><td><input name="name" type="text" value="" /></td>
                  </tr>
                  <tr>
                    <th>Start:</th><td><input readonly="readonly" name="start" type="text" value="" /></td>
                  </tr>
                  <tr>
                    <th>Stop:</th><td><input readonly="readonly" name="stop" type="text" value="" /></td>
                  </tr>
                  <tr>
                    <th>Type:</th>
                    <td>
                      <select name="type">
                        <option value="0"><?=$_SESSION['translator']->out('PUBLIC_CHANNEL')?></option>
                        <option value="1"><?=$_SESSION['translator']->out('MODERATED_CHANNEL')?></option>
                      </select>
                    </td>
                  </tr>
                </tbody>
              </table>
            </dd>
            <dt>&nbsp;</dt>
            <dt>
              <input class="submit" style="color:#fff;font-weight:bold;background-color:#0f0;" name="add_channel" type="submit" value="<?=$_SESSION['translator']->out('ADD_CHANNEL')?>" />&nbsp;
              <input class="submit" style="color:#fff;font-weight:bold;background-color:#f00;" name="del_channel" type="submit" value="<?=$_SESSION['translator']->out('DEL_CHANNEL')?>" onclick="return confirm('<?=$_SESSION['translator']->out('REALLY_QUESTION')?>');" />
            </dt>
          </dl>
        </form>
      </div>
      <div class="contentBox">
        <form action="index.php" method="post">
          <dl>
            <dt class="contentBoxTitle">&nbsp;<?=$_SESSION['translator']->out('CHATTER_ADMIN')?></dt>
            <dd>
              <table>
                <tbody>
                  <tr>
                    <td class="label"><?=$_SESSION['translator']->out('NICKNAME')?>:</td><td><input name="name" type="text" value="<?=$TEMPLATE_OUT['search_value']?>" /></td>
                  </tr>
                </tbody>
              </table>
            </dd>
            <dt>
              <input class="submit" style="color:#fff;font-weight:bold;background-color:#0f0;" name="get_chatter" type="submit" value="<?=$_SESSION['translator']->out('SEARCH')?>" />
            </dt>
          </dl>
        </form>
        <span class="success"><?=$TEMPLATE_OUT['success_msg']?></span><br />
        <span class="moderator">&#9830;</span>&nbsp;<?=$_SESSION['translator']->out('MODERATOR')?>&nbsp;&nbsp;
        <span class="vip">&#9830;</span>&nbsp;<?=$_SESSION['translator']->out('VIP')?>&nbsp;&nbsp;
        <span class="chatter">&#9830;</span>&nbsp;<?=$_SESSION['translator']->out('CHATTER')?>&nbsp;&nbsp;
        <span class="operator" style="text-decoration: none">&#9830;</span>&nbsp;<?=$_SESSION['translator']->out('OPERATOR')?>
        <?=$TEMPLATE_OUT['all_chatter_list']?>
      </div>
    </div>
    <div class="menu">
      <ul>
        <li><a href="#" onclick="window.close()"><?=$_SESSION['translator']->out('CLOSE_WINDOW')?></a></li>
      </ul>
    </div>
  </body>
</html>