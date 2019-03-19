<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['translator']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <title><?=$_SESSION['translator']->out('WHO_IS_ONLINE')?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <script type="text/javascript">
    /*<![CDATA[*/
      function showUserPage(nick)
      {
        satUserPage = window.open('userpage.php?nick='+nick,'satUserPage','width=770,height=350,screenX=50,screenY=50,top=50,left=50,dependent=yes,scrollbars=yes');
        return false;
      }
      
      function change_channel(channel)
      {
        opener.document.forms[0].elements['channel'].value = channel;
        opener.document.forms[0].submit();
      }
      
      function select_nick(nick)
      {
        opener.document.forms[0].elements['recipient'].value = nick;
      }
    /*]]>*/
    </script>
    <!--
      $Id: whois_online.tpl,v 1.4.2.2 2004/02/25 22:08:50 letreo Exp $
    -->
  </head>
  <body>
    <div class="satContent">
      <h1><?=$_SESSION['translator']->out('WHO_IS_ONLINE')?></h1>
      <p><?=$_SESSION['translator']->out('HINT_WHO_IS_ONLINE')?></p>
      <div class="contentBox">
        <table width="100%" border="0" cellpadding="0" cellspacing="0">
      	  <tbody>
      	    <?=$TEMPLATE_OUT['chatters_online_list']?>
      	  </tbody>
      	</table>
      </div>
    </div>
    <div class="menu">
      <ul>
        <li>
          <a onclick="window.close();return false;" href="#"><?=$_SESSION['translator']->out('CLOSE_WINDOW')?></a>
        </li>
      </ul>
    </div>
  </body>
</html>