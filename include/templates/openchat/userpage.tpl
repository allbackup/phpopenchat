<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['translator']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <?php if(isset($_GET['delete_post'])){?>
     <meta http-equiv="pragma" content="no-cache" />
     <meta http-equiv="Cache-control" content="no-cache" />
    <?php }?>
    <title><?=$_SESSION['translator']->out('USER_PAGE')?>: <?=$_POST['nick']?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <script type="text/javascript">
    /*<![CDATA[*/
    function openWindow()
    {
      satNewEntry = window.open("","satNewEntry","width=400,height=200,left=230,top=330,dependent=yes,scrollbars=yes");
      satNewEntry.focus();
    }
    /*]]>*/
    </script>
    <!--
      $Id: userpage.tpl,v 1.15.2.3 2004/02/25 22:08:50 letreo Exp $
    -->
  </head>
  <body>
    <div class="satContent">
      <table width="100%" border="0">
        <tbody>
          <tr>
            <td><h1><?=$_SESSION['translator']->out('USER_PAGE')?></h1></td>
            <td style="text-align:right"><p><?=$_SESSION['translator']->out('PAGE_VIEWS')?>: <?=$TEMPLATE_OUT['hit_count']?></p></td>
          </tr>
        </tbody>
      </table>
      <div class="satContentBox">
        <p style="margin:0;padding:0;text-align:right">
        *<?=$_SESSION['translator']->out('SINCE_REGISTRATION')?>
        </p>
        <dl>
          <dt class="contentBoxTitle">
            &nbsp;<?=$_SESSION['translator']->out('PERSONAL_DATA')?>
            <?=$_POST['nick']?> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <?=$TEMPLATE_OUT['onlineStatusImg']?>
            <?=$TEMPLATE_OUT['icq']?>
            <?=$TEMPLATE_OUT['aim']?>
            <?=$TEMPLATE_OUT['yahoo']?>
            <?=$TEMPLATE_OUT['homePageLink']?>
            <?=$TEMPLATE_OUT['emailLink']?>
          </dt>
          <dd>
            <table>
              <tbody>
                <tr>
                  <td><?=$_SESSION['translator']->out('USER_SINCE')?>:&nbsp;</td>
                  <td><?=$TEMPLATE_OUT['registrationTime']?></td>
                  <td style="border-left: 1px solid yellow" rowspan="9">
                    <?php foreach($TEMPLATE_OUT['misc'] as $key => $value){?>
                      <p style="margin-top:0;margin-left:10px">
                      <strong><?=$value[0]?></strong><br />
                      <?=$value[1]?>
                      </p>
                    <?php }?>
                  </td>
                </tr>
                <tr>
                  <td><?=$_SESSION['translator']->out('LAST_SEEN')?>:&nbsp;</td>
                  <td><?=$TEMPLATE_OUT['lastActive']?></td>
                </tr>
                <tr>
                  <td><?=$_SESSION['translator']->out('GRADE')?>:&nbsp;</td>
                  <td><?=$TEMPLATE_OUT['grade']?></td>
                </tr>
                <tr>
                  <td><?=$_SESSION['translator']->out('LINES_PER_DAY')?>*:&nbsp;</td>
                  <td><?=$TEMPLATE_OUT['lines_per_day']?></td>
                </tr>
                <tr>
                  <td><?=$_SESSION['translator']->out('LOGINS_PER_DAY')?>*:&nbsp;</td>
                  <td><?=$TEMPLATE_OUT['logins_per_day']?></td>
                </tr>
                <tr>
                  <td><?=$_SESSION['translator']->out('AGE')?>:&nbsp;</td>
                  <td>
                    <?=$TEMPLATE_OUT['age']?>
                  </td>
                </tr>
                <tr>
                  <td><?=$_SESSION['translator']->out('GENDER')?>:&nbsp;</td>
                  <td>
                    <?=$TEMPLATE_OUT['gender']?>
                  </td>
                </tr>
                <tr>
                  <td><?=$_SESSION['translator']->out('FRIENDS')?>:&nbsp;</td>
                  <td>
                    <?=$TEMPLATE_OUT['friends_list']?>
                  </td>
                </tr>
                <tr>
                  <td><?=$_SESSION['translator']->out('INTERESTS')?>:&nbsp;</td>
                  <td>
                    <?=$TEMPLATE_OUT['user_interests']?>
                  </td>
                </tr>
              </tbody>
            </table>
          </dd>
        </dl>
      </div>
      <div class="satContentBox">
        <dl>
          <dt class="contentBoxTitle"><a name="gb"></a>
            &nbsp;<?=$_SESSION['translator']->out('GUESTBOOK')?>&nbsp;&nbsp;&nbsp;
            <?php if(isset($_SESSION['chatter']) && $_POST['nick']!=$_SESSION['chatter']->get_nick()){?>
              <a class="imageLink" style="background:none" title="<?=$_SESSION['translator']->out('GUESTBOOK_NEW_ENTRY')?>" href="new_guestbook_entry.php?nickname=<?=urlencode($_POST['nick'])?>&amp;<?=$_SESSION['session_get']?>" onclick="openWindow()" target="satNewEntry"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/guestbook.gif" alt="<?=$_SESSION['translator']->out('GUESTBOOK_NEW_ENTRY')?>" border="0" align="middle" /></a>
            <?php }?>
          </dt>
          <dd>
            <table>
              <tbody>
                <tr>
                  <td>
                    <?php foreach($TEMPLATE_OUT['guestbook_posts'] as $post){?>
                      <?=$post['gender_icon']?> 
                      <?=$post['birthday_icon']?> 
                      <span class="guestbookEntryTitle">
                        <a title="<?=$_SESSION['translator']->out('USER_PAGE')?>" href="userpage.php?nick=<?=urlencode($post['sender'])?>&amp;<?=$_SESSION['session_get']?>">
                          <?=$post['sender']?>
                        </a>
                      </span>
                      <?=$post['grade']?>
                      &nbsp;[<?=$post['time']?>]&nbsp;&nbsp;<?=$post['delete']?>
                      <br />
                      <?=$post['content']?><br />
                    <?php }?>
                  </td>
                </tr>
              </tbody>
            </table>
          </dd>
        </dl>
      </div>
    </div>
    <div class="menu">
      <ul>
        <li>
          <a href="#" onclick="window.close()"><?=$_SESSION['translator']->out('CLOSE_WINDOW')?></a>
        </li>
      </ul>
      <div class="menuBox">
        <?=$TEMPLATE_OUT['user_pic']?>
        <dl>
          <dt class="menuBoxTitle">&nbsp;<?=$_SESSION['translator']->out('MOTTO')?></dt>
          <dd>
            <p>
              <?=$TEMPLATE_OUT['user_motto']?>
            </p>
          </dd>
        </dl>
      </div>
    </div>
  </body>
</html>