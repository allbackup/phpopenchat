<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['translator']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content="<?=$_SESSION['template']->get_content_type()?>; charset='<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>'" />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
      <script type="text/javascript">
        <?include($_SESSION['template']->get_tmpl_sys_path().'/js/input.js.php')?>
      </script>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <!--
      $Id: input.tpl,v 1.50.2.16 2004/08/26 11:58:00 letreo Exp $
    -->
  </head>
  <body class="background" onload="do_focus();<?=$TEMPLATE_OUT['js_onload']?>" onunload="logout()" onmouseover="setPOCsFocus(true)" onmouseout="setPOCsFocus(false)">
    <div class="content" style="margin:0px;padding:0px;padding-left:10px;width: 576px;height: 85%">
      <div class="contentBox" style="float: left;margin-bottom: 0px;height: 95%;width:410px">
        <form accept-charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>" enctype="text/plain; charset='<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>'" action="input.php" method="post" style="margin:0" onsubmit="formPost=1;return checkValue()">
          <dl style="margin:0"><dt class="contentBoxTitle" style="font-size:.7em;margin-bottom:8px;"><?=$TEMPLATE_OUT['salutation']?></dt>
            <dd style="margin:0;padding:0">
              <?=$_SESSION['translator']->out('CHANNEL')?>:
              <select title="<?=$_SESSION['translator']->out('CHOOSE_CHANNEL')?>" class="selectbox" name="channel" onchange="parent.setChannel(this);checkChannel(this);formPost=1;submit()">
                <?=$TEMPLATE_OUT['option_list_of_channels']?>
              </select>
              &nbsp;
              <?=$_SESSION['translator']->out('SPEAK_TO')?>:
              <select title="<?=$_SESSION['translator']->out('CHOOSE_RECIPIENT')?>" class="selectbox" name="recipient">
                <option value="###EVERYBODY###"><?=$_SESSION['translator']->out('EVERYBODY')?></option>
                <?=$TEMPLATE_OUT['option_list_of_friends']?>
                <?=$TEMPLATE_OUT['option_list_of_channel_chatters']?>
              </select><a class="imageLink" title="<?=$_SESSION['translator']->out('WHO_IS_ONLINE')?>" onclick="openWindow()" href="whois_online.php?<?=$_SESSION['session_get']?>" target="satModules"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/whois_online.gif" alt="online?" border="0" align="middle" width="16" height="16" vspace="2" hspace="2" /></a>&nbsp;&nbsp;&nbsp;
              <script type="text/javascript">
                label_operators();
              </script>
              <?=$_SESSION['translator']->out('WHISPERED')?>!
              <input size="2" align="top" name="whispered" type="checkbox" <?=$TEMPLATE_OUT['whispered_checked']?> />
              <div style="padding-top:3px">
               <a class="imageLink" title="<?=$_SESSION['translator']->out('ICON_LIST')?>" onclick="openIconList()" href="insert_icon.php?<?=$_SESSION['session_get']?>" target="satIcons"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys.gif" alt="Smileys" border="0" /></a>&nbsp;
              <?php if(MULTIPLE_LINE_INPUT){?>
               <textarea <?=$TEMPLATE_OUT['mod_class']?> style="font-size:9px;width: 300px" rows="2" name="line" onfocus="parent.resetTitle()" onmouseover="setPOCsFocus(true)" onmouseout="setPOCsFocus(false)"></textarea>
              <?php }else{?>
               <input <?=$TEMPLATE_OUT['mod_class']?> style="width: 330px;color:#<?=$_SESSION['chatter']->get_color()?>" name="line" type="text" value="" maxlength="<?=MAX_LINE_LENGTH?>" onfocus="parent.resetTitle()" onmouseover="setPOCsFocus(true)" onmouseout="setPOCsFocus(false)" />
              <?php }?>
               <input title="[Alt+s] <?=$_SESSION['translator']->out('SUBMIT')?>" class="submit" style="font-size:8px" accesskey="s" type="submit" value=" <?=$_SESSION['translator']->out('GO')?> " onclick="countClick()" onmouseover="setPOCsFocus(true)" onmouseout="setPOCsFocus(false)" />
               <input name="<?=session_name()?>" type="hidden" value="<?=session_id()?>" />
              </div>
            </dd>
          </dl>
        </form>
      </div>
      <div class="inputFilterBox" style="margin-top: 0px;margin-left: 426px;width: 125px;height: 95%">
        <dl style="margin:0"><dt class="contentBoxTitle">
        <?=$_SESSION['translator']->out('OUTPUT_FILTER')?></dt><dd style="margin-left:1px">
        <form style="margin:0" action="input.php" method="post" name="filter" onsubmit="formPost=1">
          <table>
            <tr>
              <td>
                <input name="filter_form" type="hidden" value="1" />
                <input name="<?=session_name()?>" type="hidden" value="<?=session_id()?>" />
                <input name="private" type="checkbox" onclick="formPost=1;submit();" <?=$TEMPLATE_OUT['private_checked']?> />
                </td>
              <td class="filterboxItems"><?=$_SESSION['translator']->out('PRIVATE')?></td>
            </tr>
            <tr>
              <td>
                <input name="bodies" type="checkbox" onclick="formPost=1;submit();" <?=$TEMPLATE_OUT['bodies_checked']?> />
                </td>
              <td class="filterboxItems"><?=$_SESSION['translator']->out('BODIES')?></td>
            </tr>
            <tr>
              <td>
                <input name="sys_msg" type="checkbox" onclick="formPost=1;submit();" <?=$TEMPLATE_OUT['sys_msg_checked']?> />
                </td>
              <td class="filterboxItems"><?=$_SESSION['translator']->out('SYSTEM_MESSAGES')?></td>
            </tr>
          </table>
        </form>
        </dd></dl>
      </div>
    </div>
    <div class="menu" style="border-top: 2px dotted black;border-bottom:0;margin-left: 74%">
     <table style="margin:0" width="100%" border="0" cellspacing="0" cellpadding="0">
       <tbody>
         <tr>
           <td valign="top">
            <ul>
              <li>
                <a title="[Alt+1] <?=$_SESSION['translator']->out('HELP')?>" accesskey="1" onclick="openWindow()" href="help.php?<?=session_name()."=".session_id()?>&amp;sat=1" target="satModules">
                  <?=$_SESSION['translator']->out('HELP')?>
                </a>
              </li>
              <?php if( $_SESSION['chat']->get_show_profile() ){?>
              <li>
                <a title="[Alt+2] <?=$_SESSION['translator']->out('PROFILE')?>" accesskey="2" onclick="openWindow()" href="profile.php?<?=session_name()."=".session_id()?>" target="satModules">
                  <?=$_SESSION['translator']->out('PROFILE')?>
                </a>
              </li>
              <?php }?>
              <li>
                <a title="[Alt+3] <?=$_SESSION['translator']->out('IGNORE')?>" accesskey="3" onclick="openWindow()" href="ignore.php?<?=session_name()."=".session_id()?>" target="satModules">
                  <?=$_SESSION['translator']->out('IGNORE')?>
                </a>
              </li>
              <li>
                <a title="[Alt+4] <?=$_SESSION['translator']->out('INVITE')?>" accesskey="4" onclick="openWindow()" href="invite.php?<?=session_name()."=".session_id()?>" target="satModules">
                  <?=$_SESSION['translator']->out('INVITE')?>
                </a>
              </li>
              <li>
                <a title="[Alt+5] <?=$_SESSION['translator']->out('FRIENDS')?>" accesskey="5" onclick="openWindow()" href="friends.php?<?=session_name()."=".session_id()?>" target="satModules">
                  <?=$_SESSION['translator']->out('FRIENDS')?>
                </a>
              </li>
            </ul>
          </td>
          <td valign="top">
            <ul style="margin-left:5px">
              <li>
                <a title="[Alt+6] <?=$_SESSION['translator']->out('REGULARS')?>" accesskey="6" onclick="openWindow()" href="regulars.php?sat=1&amp;<?=session_name()."=".session_id()?>" target="satModules">
                  <?=$_SESSION['translator']->out('REGULARS')?>
                </a>
              </li>
              <li>
                <a title="[Alt+7] <?=$_SESSION['translator']->out('CONFIGURE')?>" accesskey="7" onclick="openWindow()" href="configure.php?<?=session_name()."=".session_id()?>" target="satModules">
                  <?=$_SESSION['translator']->out('CONFIGURE')?>
                </a>
              </li>
              <li>
                <a title="[Alt+8] <?=$_SESSION['translator']->out('MAIL')?>" accesskey="8" onclick="openWindow()" href="mail.php?<?=session_name()."=".session_id()?>&amp;display_content=mailbody<?=$TEMPLATE_OUT['mail_param']?>" target="satModules">
                  <?=$_SESSION['translator']->out('MAIL')?>
                </a>
              </li>
              <?php if($_SESSION['chatter']->is_operator()){?>
              <li>
                <a title="[Alt+9] <?=$_SESSION['translator']->out('ADMINISTRATION')?>" accesskey="9" onclick="openWindow()" href="admin/index.php?<?=session_name()."=".session_id()?>" target="satModules">
                  <?=$_SESSION['translator']->out('ADMINISTRATION')?>
                </a>
              </li>
              <?php }?>
              <li style="list-style-type: disc;color:#f00">
                <a name="exit" title="[Alt+0] <?=$_SESSION['translator']->out('EXIT_CHAT')?>" accesskey="0" href="input.php?<?=session_name()."=".session_id()?>&amp;exit=1" onclick="parent.exitLinkClicked=1" target="_top">
                  <?=$_SESSION['translator']->out('EXIT_CHAT')?>
                </a>
              </li>
            </ul>
          </td>
          <td style="text-align:right" valign="top">
          <?php if(preg_match('/MSIE/',$_SERVER['HTTP_USER_AGENT'])){?>
            <a class="imageLink" onclick="inputWindow()" href="input.php" target="satInput">
              <img src="<?=$_SESSION['template']->get_theme_path()?>/images/buttons/window_controls.gif" alt="" height="14" width="32" border="1" />
            </a>
            <?php }?>
          </td>
        </tr>
       </tbody>
     </table>
    </div>
  </body>
</html>