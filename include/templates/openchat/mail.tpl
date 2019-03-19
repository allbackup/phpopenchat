<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['chat']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['chat']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content="<?=$_SESSION['template']->get_content_type()?>; charset='<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>'" />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/mail.css" />
    <script type="text/javascript">
    /*<![CDATA[*/
      function insertValue( nickname )
      {
        if(document.forms[0].elements['recipient'].value == '')
          document.forms[0].elements['recipient'].value = nickname;
        else
          document.forms[0].elements['recipient'].value = document.forms[0].elements['recipient'].value + ',' + nickname;
      }
      
      function toggleDiv(id)
      {
        if (document.getElementById)
        {
            if (document.getElementById(id).className == "friendsHidden")
            {
              document.getElementById(id).className = "friends";
            } else {
              document.getElementById(id).className = "friendsHidden";
            }
        }
        else if (document.all)
        {
          if (document.all(id).className == "friendsHidden")
          {
            document.all(id).className = "friends";
          } else {
            document.all(id).className = "friendsHidden";
          }
        }
       
        else if (document.layers)
        {
          if (document.layers[id].className == "friendsHidden") {
            document.layers[id].className = "friends";
          } else {
            document.layers[id].className = "friendsHidden";
          }
        } 
      }
    /*]]>*/
    </script>
    <!--
      $Id: mail.tpl,v 1.22.2.7 2004/02/25 22:08:50 letreo Exp $
    -->
  </head>
  <body>
    <div class="toolbar">
     <?php if($_SESSION['mailbox']->get_type()=='inbox'){?>
      <a title="<?=$_SESSION['translator']->out('GET_MAIL')?>" href="mail.php?<?=$_SESSION['session_get']?>&amp;reload_mailbox=1">
        <img src="<?=$_SESSION['template']->get_tmpl_web_path()?>/images/icons/get_new_mail.gif" alt="<?=$_SESSION['translator']->out('GET_MAIL')?>" border="0" />
      </a>&nbsp;&nbsp;|&nbsp;&nbsp;
     <?php }?>
      <a title="<?=$_SESSION['translator']->out('COMPOSE')?>" href="mail.php?<?=$_SESSION['session_get']?>&amp;display_content=compose">
        <img src="<?=$_SESSION['template']->get_tmpl_web_path()?>/images/icons/new_mail.gif" alt="<?=$_SESSION['translator']->out('COMPOSE')?>" border="0" />
      </a>&nbsp;&nbsp;|&nbsp;&nbsp;
      <a title="<?=$_SESSION['translator']->out('REPLY')?>" href="mail.php?<?=$_SESSION['session_get']?>&amp;display_content=reply">
        <img src="<?=$_SESSION['template']->get_tmpl_web_path()?>/images/icons/reply_mail.gif" alt="<?=$_SESSION['translator']->out('REPLY')?>" border="0" />
      </a>&nbsp;&nbsp;|&nbsp;&nbsp;
      <a title="<?=$_SESSION['translator']->out('FORWARD')?>" href="mail.php?<?=$_SESSION['session_get']?>&amp;display_content=forward">
        <img src="<?=$_SESSION['template']->get_tmpl_web_path()?>/images/icons/forward_mail.gif" alt="<?=$_SESSION['translator']->out('FORWARD')?>" border="0" />
      </a>
     <?php if(isset($_SESSION['curr_mail_idx'])){?>
      &nbsp;&nbsp;|&nbsp;&nbsp;
       <?php if( $_SESSION['current_mailbox_type'] != 'trash'){?>
        <a title="<?=$_SESSION['translator']->out('MOVE_TO_TRASH')?>" href="mail.php?<?=$_SESSION['session_get']?>&amp;trash=<?=$_SESSION['curr_mail_idx']?>">
         <img src="<?=$_SESSION['template']->get_tmpl_web_path()?>/images/icons/move_to_recycler.gif" alt="<?=$_SESSION['translator']->out('MOVE_TO_TRASH')?>" border="0" />
       <?php }else{?>
        <a title="<?=$_SESSION['translator']->out('DELETE_MAIL')?>" href="mail.php?<?=$_SESSION['session_get']?>&amp;trash=<?=$_SESSION['curr_mail_idx']?>">
         <img src="<?=$_SESSION['template']->get_tmpl_web_path()?>/images/icons/recycler.gif" alt="<?=$_SESSION['translator']->out('DELETE_MAIL')?>" border="0" />
       <?php }?>
      </a>
     <?php }?>
    </div>
    <div class="satContent">
      <div class="sidebar"><br />
        <strong><?=$_SESSION['translator']->out('MAIL')?><br />&lt;<?=$_SESSION['chatter']->get_nick()?>&gt;</strong>
        <menu style="padding-left:0px;margin-left:0px">
          <li class="box" style="<?=$TEMPLATE_OUT['newmail_inbox']?><?=$TEMPLATE_OUT['mark_inbox']?>"><a href="mail.php?<?=$_SESSION['session_get']?>&amp;current_mailbox_type=inbox" <?=$TEMPLATE_OUT['class_inbox']?>><?=$_SESSION['translator']->out('INBOX')?></a> <?=$TEMPLATE_OUT['new_in_inbox']?></li>
          <li class="box" style="<?=$TEMPLATE_OUT['newmail_outbox']?><?=$TEMPLATE_OUT['mark_outbox']?>"><a href="mail.php?<?=$_SESSION['session_get']?>&amp;current_mailbox_type=outbox" <?=$TEMPLATE_OUT['class_outbox']?>><?=$_SESSION['translator']->out('OUTBOX')?></a> <?=$TEMPLATE_OUT['new_in_outbox']?></li>
          <li class="trash" style="<?=$TEMPLATE_OUT['newmail_trash']?><?=$TEMPLATE_OUT['mark_trash']?>"><a href="mail.php?<?=$_SESSION['session_get']?>&amp;current_mailbox_type=trash" <?=$TEMPLATE_OUT['class_trash']?>><?=$_SESSION['translator']->out('TRASH')?></a> <?=$TEMPLATE_OUT['new_in_trash']?></li>
        </menu>
      </div>
      <div class="messages">
        <?php if($_GET['display_content'] != 'compose'){?>
          <table cellpadding="0" cellspacing="0" border="0" width="100%">
            <thead>
             <tr>
              <th class="title">&nbsp;</th>
              <th class="title"><u><?=$_SESSION['translator']->out('SUBJECT')?></u></th>
                <?php if($_SESSION['mailbox']->get_type()=='outbox'){?>
                  <th class="title"><u><?=$_SESSION['translator']->out('RECIPIENT')?></u></th>
                  <th class="title"><u><?=$_SESSION['translator']->out('MAIL_SEND_DATE')?></u></th>
                  <th class="title"><u><?=$_SESSION['translator']->out('LAST_TOUCH_RECIPIENT')?></u></th>
                <?php }elseif($_SESSION['mailbox']->get_type()!='trash'){?>
                  <th class="title"><u><?=$_SESSION['translator']->out('SENDER')?></u></th>
                  <th class="title"><u><?=$_SESSION['translator']->out('MAIL_RECEIVED')?></u></th>
                  <th class="title"><u><?=$_SESSION['translator']->out('LAST_TOUCH_SENDER')?></u></th>
                <?php }else{?>
                  <th class="title">&nbsp;</th>
                  <th class="title">&nbsp;</th>
                  <th class="title">&nbsp;</th>
                <?php }?>
             </tr>
            </thead>
            <tbody>
              <?=$TEMPLATE_OUT['subjects']?>
            </tbody>
          </table>
        <hr noshade="noshade" size="2" />
        <?php }?>
        <div class="messagePane">
          <p><strong><?=$TEMPLATE_OUT['title']?></strong></p>
          
          <?php if($_GET['display_content'] == 'compose' || $_GET['display_content'] == 'reply' || $_GET['display_content'] == 'forward'){?>
          
          <form class="mailform" action="mail.php" method="post">
            <table>
              <tbody>
                <tr>
                  <td class="hint">&nbsp;<input name="display_content" type="hidden" value="compose" /></td>
                  <td class="hint">
                    <?=$_SESSION['translator']->out('RECIPIENT_HINT')?><br />
                    <?=$TEMPLATE_OUT['error']?>
                  </td>
                </tr>
                <tr>
                  <td class="msgPane"><?=$_SESSION['translator']->out('RECIPIENT')?>:</td>
                  <td class="msgPane"><input class="inputField" name="recipient" type="text" value="<?=$TEMPLATE_OUT['mail_to']?>" size="30" />&nbsp;<a href="#" onclick="toggleDiv('friendsList')"><?=$_SESSION['translator']->out('FRIENDS')?></a></td>
                </tr>
                <tr>
                  <td class="msgPane"><?=$_SESSION['translator']->out('SUBJECT')?>:</td>
                  <td class="msgPane"><input class="inputField" name="subject" type="text" value="<?=$TEMPLATE_OUT['mail_subject']?>" maxlength="30" size="30" /></td>
                </tr>
                <tr>
                  <td class="msgPane" valign="top"><?=$_SESSION['translator']->out('BODY')?>:</td>
                  <td class="msgPane"><textarea class="inputField" name="body" cols="50" rows="10"><?=$TEMPLATE_OUT['mail_body']?></textarea></td>
                </tr>
                <tr>
                  <td class="hint">&nbsp;</td>
                  <td class="hint"><?=$_SESSION['translator']->out('MAIL_SEND_HINT')?></td>
                </tr>
                <tr>
                  <td class="msgPane">&nbsp;</td>
                  <td class="msgPane">
				    <?=$_SESSION['session_post']?>
				  	<input name="send_mail" type="submit" value="<?=$_SESSION['translator']->out('SEND')?>" />
                  </td>
                </tr>
              </tbody>
            </table>
          </form>
          
          <?php }elseif($_GET['display_content'] == 'mailbody'){ ?>
            <?=$TEMPLATE_OUT['body']?>
          <?php } ?>
          
        </div>
      </div>
    </div>
    <div class="menu">
      <ul>
        <li>
          <a href="#" onclick="window.close()"><?=$_SESSION['translator']->out('CLOSE_WINDOW')?></a>
        </li>
      </ul>
    </div>
    <div id="friendsList" class="friendsHidden" onmouseout="toggleDiv('friendsList')">
      <?=$TEMPLATE_OUT['friends_links']?>
    </div>
  </body>
</html>