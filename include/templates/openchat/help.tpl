<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['translator']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content="<?=$_SESSION['template']->get_content_type()?>; charset='<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>'" />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <!--
      $Id: help.tpl,v 1.15.2.3 2004/02/29 19:57:11 letreo Exp $
    -->
  </head>
  <body>
   <?php if(isset($_REQUEST['sat'])){?>
    <div class="satContent">
   <?php }else{?>
    <div class="content">
   <?php }?>
      <h1><?=$_SESSION['translator']->out('HELP_TITLE')?></h1>
      <p><?=$_SESSION['translator']->out('HELP_HINT')?></p>
      <div class="contentBox">
        <dl>
          <dt class="contentBoxTitle"><?=$_SESSION['translator']->out('HELP_SUBTITLE1')?></dt>
          <dd>
            <table border="0" cellspacing="0" cellpadding="0">
              <tbody>
                <tr>
                  <td colspan="4"><?=$_SESSION['translator']->out('HELP_TEASER1')?>
                    <ul>
                      <li><?=$_SESSION['translator']->out('HELP_CHANNEL')?></li>
                      <li><?=$_SESSION['translator']->out('HELP_SPEAK')?></li>
                      <li><?=$_SESSION['translator']->out('HELP_IGNORE')?></li>
                      <li><?=$_SESSION['translator']->out('HELP_INVITE')?></li>
                      <li><?=$_SESSION['translator']->out('HELP_FRIENDS')?></li>
                      <li><?=$_SESSION['translator']->out('HELP_CONFIGURE')?></li>
                      <li><?=$_SESSION['translator']->out('HELP_MAIL')?></li>
                      <li><?=$_SESSION['translator']->out('HELP_HELP')?></li>
                    </ul>
                  </td>
                </tr>
              </tbody>
            </table>
          </dd>
        </dl>
      </div>
      <div class="contentBox">
        <dl>
          <dt class="contentBoxTitle"><?=$_SESSION['translator']->out('HELP_SUBTITLE2')?></dt>
          <dd>
            <table border="0" cellspacing="0" cellpadding="0">
              <tbody>
                <tr>
                  <th align="left"><?=$_SESSION['translator']->out('IRC_COMMAND')?>&nbsp;</th>
                  <th align="left" colspan="3"><?=$_SESSION['translator']->out('IRC_EXPLANATION')?></th>
                </tr>
                <tr>
                  <td class="helpText">/me</td>
                  <td class="helpText" colspan="3"><?=$_SESSION['translator']->out('IRC_ME')?></td>
                </tr>
                <tr>
                  <td class="helpText">/msg</td>
                  <td class="helpText" colspan="3"><?=$_SESSION['translator']->out('IRC_MSG')?></td>
                </tr>
                <tr>
                  <td class="helpText">/&lt;nickname&gt;</td>
                  <td class="helpText" colspan="3"><?=$_SESSION['translator']->out('IRC_NICK')?></td>
                </tr>
                <tr>
                  <td class="helpText">/join &lt;channel name&gt;</td>
                  <td class="helpText" colspan="3"><?=$_SESSION['translator']->out('IRC_JOIN')?></td>
                </tr>
                <tr>
                  <td class="helpText">/query &lt;nickname&gt;</td>
                  <td class="helpText" colspan="3"><?=$_SESSION['translator']->out('IRC_QUERY')?></td>
                </tr>
                <tr>
                  <td class="helpText">/locate &lt;nickname&gt;</td>
                  <td class="helpText" colspan="3"><?=$_SESSION['translator']->out('IRC_LOCATE')?></td>
                </tr>
                <tr>
                  <td class="helpText">/ignore &lt;nickname&gt;</td>
                  <td class="helpText" colspan="3"><?=$_SESSION['translator']->out('IRC_IGNORE')?></td>
                </tr>
                <tr>
                  <td class="helpText">/unignore &lt;nickname&gt;</td>
                  <td class="helpText" colspan="3"><?=$_SESSION['translator']->out('IRC_UNIGNORE')?></td>
                </tr>
                <tr>
                  <td class="helpText">/kick &lt;nickname&gt;</td>
                  <td class="helpText" colspan="3"><?=$_SESSION['translator']->out('IRC_KICK')?></td>
                </tr>
                <tr>
                  <td class="helpText">/ban &lt;nickname&gt; &lt;period&gt;</td>
                  <td class="helpText" colspan="3"><?=$_SESSION['translator']->out('IRC_BAN')?></td>
                </tr>
                <tr>
                  <td class="helpText">/help</td>
                  <td class="helpText" colspan="3"><?=$_SESSION['translator']->out('IRC_HELP')?></td>
                </tr>
                <tr>
                  <td class="helpText">/quit</td>
                  <td class="helpText" colspan="3"><?=$_SESSION['translator']->out('IRC_QUIT')?></td>
                </tr>
              </tbody>
            </table>
          </dd>
        </dl>
      </div>
      <div class="contentBox">
        <dl>
          <dt class="contentBoxTitle"><?=$_SESSION['translator']->out('HELP_SUBTITLE3')?></dt>
          <dd>
            <table border="0" cellspacing="0" cellpadding="0">
              <tbody>
                <tr>
                  <th align="left"><?=$_SESSION['translator']->out('SMILEY_CODE')?></th>
                  <th align="left"><?=$_SESSION['translator']->out('SMILEY_EXPLANATION')?></th>
                  <th align="left"><?=$_SESSION['translator']->out('SMILEY_CODE')?></th>
                  <th align="left"><?=$_SESSION['translator']->out('SMILEY_EXPLANATION')?></th>
                </tr>
                <tr>
                  <td class="helpText">:me</td>
                  <td class="helpText"><?=$_SESSION['translator']->out('OWN_PRIVATE_IMAGE')?></td>
                  <td class="helpText">:you</td>
                  <td class="helpText"><?=$_SESSION['translator']->out('RECIPIENT_PRIVATE_IMAGE')?></td>
                </tr>
                <tr>
                  <td class="helpText">:-) or :)</td>
                  <td class="helpText">smile</td>
                  <td class="helpText">:-p or :p</td>
                  <td class="helpText">tongue</td>
                </tr>
                <tr>
                  <td class="helpText">:-( or :(</td>
                  <td class="helpText">frown</td>
                  <td class="helpText">:-x or :kiss:</td>
                  <td class="helpText">kiss</td>
                </tr>
                <tr>
                  <td class="helpText">:,-( or :,(</td>
                  <td class="helpText">crying</td>
                  <td class="helpText">:-D or :D</td>
                  <td class="helpText">biggrin</td>
                </tr>
                <tr>
                  <td class="helpText">:-] or :]</td>
                  <td class="helpText">evillaugh</td>
                  <td class="helpText">:eating:</td>
                  <td class="helpText">eating</td>
                </tr>
                <tr>
                  <td class="helpText">:-)=</td>
                  <td class="helpText">beard</td>
                  <td class="helpText">=:-)</td>
                  <td class="helpText">punk</td>
                </tr>
                <tr>
                  <td class="helpText">~o</td>
                  <td class="helpText">bomb</td>
                  <td class="helpText">~==</td>
                  <td class="helpText">candle</td>
                </tr>
                <tr>
                  <td class="helpText">(:(=</td>
                  <td class="helpText">ghost</td>
                  <td class="helpText">(/)</td>
                  <td class="helpText">denied</td>
                </tr>
                <tr>
                  <td class="helpText">~--</td>
                  <td class="helpText">dynamite</td>
                  <td class="helpText">8)</td>
                  <td class="helpText">frog</td>
                </tr>
                <tr>
                  <td class="helpText">B-))</td>
                  <td class="helpText">very big grin</td>
                  <td class="helpText">:#D</td>
                  <td class="helpText">sail</td>
                </tr>
                <tr>
                  <td class="helpText">:[=]</td>
                  <td class="helpText">trash</td>
                  <td class="helpText">&nbsp;</td>
                  <td class="helpText">&nbsp;</td>
                </tr>
                <tr>
                  <td colspan="4">&nbsp;</td>
                </tr>
                <tr>
                  <td class="helpText" colspan="4"><?=$_SESSION['translator']->out('MORE_SMILEY_CODES')?></td>
                </tr>
                <tr>
                  <td class="helpText" colspan="4">
                    :cool: :rolleyes: :yawn: :crying: :angel: :wow: :finger: :hehe: :evillaugh:  :fairy: 
                    :lovestory: :verysad: :help: :repuke: :scream: :male: :female: :rambo: :nono: 
                    :stoned: :thumbsup: :toilet: :smoky: :kidding: :lol: :question: :hi: :phoneme: 
                    :confused: :borg: :apresent: :alarm: :dazzler: :tombstone: :director: :cloud: 
                    :flower: :kisslipps: :love: :massa: :rain: :rose: :sun: :toffline:
                    <?=$TEMPLATE_OUT['extra_smileys']?>
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
         <?php if(isset($_REQUEST['sat'])){?>
          <a href="#" onclick="window.close()"><?=$_SESSION['translator']->out('CLOSE_WINDOW')?></a>
         <?php }else{?>
          <a href="index.php"><?=$_SESSION['translator']->out('GOTO_HOME')?></a>
         <?php }?>
        </li>
      </ul>
    </div>
  </body>
</html>