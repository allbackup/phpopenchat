<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['chat']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['chat']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content="<?=$_SESSION['template']->get_content_type()?>; charset='<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>'" />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <script type="text/javascript">
      <?include($_SESSION['template']->get_tmpl_sys_path().'/js/configure.js.php')?>
    </script>
    <!--
      $Id: configure.tpl,v 1.26.2.8 2004/08/26 11:58:00 letreo Exp $
    -->
  </head>
  <body onload="<?=$TEMPLATE_OUT['js_onload']?>" onunload="closeColPickWin()">
    <div class="satContent">
    <h1><?=$_SESSION['translator']->out('CONFIGURATION')?></h1>
      <div class="contentBox">
        <span class="error"><?=$TEMPLATE_OUT['error']?></span>
        <form action="configure.php" method="post">
          <table width="100%">
            <tr>
              <th colspan="2" class="title">
                <?=$_SESSION['session_post']?>
                <?=$_SESSION['translator']->out('TEXT_COLOR')?>:&nbsp;
              </th>
            </tr>
            <tr>
              <td width="22%" bgcolor="#<?=$_SESSION['chatter']->get_color()?>">
                &nbsp;<br />&nbsp;<br />
              </td>
              <td></td>
            </tr>
            <tr>
              <td colspan="2">
                <input class="inputField" name="color" type="hidden" value="<?=$TEMPLATE_OUT['color']?>" maxlength="6" size="6" />
                <input class="sendButton" type="hidden" value="<?=$_SESSION['translator']->out('SUBMIT')?>" />
                <?php if($_SESSION['template']->is_shockwave()){ // classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000"?>
                  <object type="application/x-shockwave-flash" data="color2php.swf" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=5,0,0,0" width="200" height="50">
                    <param name="movie" value="color2php.swf" />
                    <param name="loop" value="false" />
                    <param name="menu" value="false" />
                    <param name="quality" value="high" />
                    <param name="salign" value="LB" />
                    <param name="scale" value="showall" />
                    <param name="bgcolor" value="#284628" />
                    <!--embed src="color2php.swf" loop="false" scale="showall"  menu="false" quality="high" salign="LB" bgcolor="#284628"  width="200" height="50" type="application/x-shockwave-flash" PLUGINSPAGE="http://www.macromedia.com/shockwave/download/index.cgi?P1_Prod_Version=ShockwaveFlash"></embed-->
                  </object>
                <?php }else{?>
                  <a href="#" onclick="showColorPickerHTML(event.screenX,event.screenY)">Color picker</a>
                <?php }?>                
              </td>
            </tr>
          </table>
        </form>
        <form action="configure.php" method="post">
          <table width="100%" cellpadding="0" cellspacing="0" border="0">
            <thead>
              <tr>
                <th class="title" colspan="2">&nbsp;
                  <?=$_SESSION['session_post']?>
                  <?=$_SESSION['translator']->out('ADVICE')?>:
                </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td width="30%">&nbsp;
                  <input id="quiet" onclick="submit()" class="inputField" name="advice" type="radio" value="quiet" <?=$TEMPLATE_OUT['advice_quiet_selected']?> /> <label for="quiet"><?=$_SESSION['translator']->out('QUIET')?></label>:&nbsp;</td>
                
                <td class="helpIcon"><a title="<?=$_SESSION['translator']->out('HELP')?>" onclick="openHelpWindow('<?=$_SESSION['translator']->out('HINT_ADVICE_QUIET',true)?>',event.screenX,event.screenY)" href="#"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/help.gif" alt="?" border="0" /></a></td>
              </tr>
              <tr>
                <td width="30%">&nbsp;
                  <input id="alert" onclick="submit()" class="inputField" name="advice" type="radio" value="alert" <?=$TEMPLATE_OUT['advice_alert_selected']?> /> <label for="alert"><?=$_SESSION['translator']->out('ALERT')?></label>:&nbsp;</td>
                <td class="helpIcon"><a title="<?=$_SESSION['translator']->out('HELP')?>" onclick="openHelpWindow('<?=$_SESSION['translator']->out('HINT_ADVICE_ALERT',true)?>',event.screenX,event.screenY)" href="#"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/help.gif" alt="?" border="0" /></a></td>
              </tr>
              <tr>
                <td width="30%">&nbsp;
                  <input align="middle" id="sound" onclick="submit()" class="inputField" name="advice" type="radio" value="sound" <?=$TEMPLATE_OUT['advice_sound_selected']?> /> <label for="sound"><?=$_SESSION['translator']->out('SOUND')?></label>:&nbsp;</td>
                <td class="helpIcon"><a title="<?=$_SESSION['translator']->out('HELP')?>" onclick="openHelpWindow('<?=$_SESSION['translator']->out('HINT_ADVICE_SOUND',true)?>',event.screenX,event.screenY)" href="#"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/help.gif" alt="?" border="0" /></a></td>
              </tr>
            </tbody>
          </table>
        </form>
        <form action="configure.php" name="speed" method="post">
          <table width="100%">
            <tr>
              <th class="title"><?=$_SESSION['translator']->out('SCROLL_SPEED')?></th>
            </tr>
            <tr>
              <td>
                <select name="options" onchange="setSpeed();submit()">
                  <option value="-1"><?=$_SESSION['translator']->out('CHOOSE_SCROLL_SPEED')?>...</option>
                  <option value="1" <?=$TEMPLATE_OUT['scroll_value_1_selected']?>><?=$_SESSION['translator']->out('SCROLL_SPEED_NORMAL')?></option>
                  <option value="2" <?=$TEMPLATE_OUT['scroll_value_2_selected']?>><?=$_SESSION['translator']->out('SCROLL_SPEED_FAST')?></option>
                  <option value="3" <?=$TEMPLATE_OUT['scroll_value_3_selected']?>><?=$_SESSION['translator']->out('SCROLL_SPEED_FASTER')?></option>
                  <option value="0" <?=$TEMPLATE_OUT['scroll_value_0_selected']?>><?=$_SESSION['translator']->out('SCROLL_SPEED_OFF')?></option>
                </select>
                <?=$_SESSION['session_post']?>
              </td>
            </tr>
          </table>
        </form>
        <?php if(ALLOW_TEMPLATE_CHANGES){?>
        <form action="configure.php" name="theme" method="post">
          <table width="100%">
            <tr>
              <th class="title">&nbsp;
                <?=$_SESSION['translator']->out('CHOOSE_THEME')?>:
              </th>
            </tr>
            <tr>
              <td>
                <select name="theme" onchange="submit()">
                  <?=$TEMPLATE_OUT['theme_option_list']?>
                </select>
              </td>
            </tr>
          </table>
        </form>
        <?php }?>
        <a href="noIEClick.reg"><?=$_SESSION['translator']->out('SWITCH_OFF_IE_CLICK')?></a>
      </div>
    </div>
    <div class="menu">
    <div class="flagBox"><?=$TEMPLATE_OUT['lang_switch']?></div>
      <ul>
        <li>
          <a href="#" onclick="window.close()"><?=$_SESSION['translator']->out('CLOSE_WINDOW')?></a>
        </li>
      </ul>
    </div>
  </body>
</html>
