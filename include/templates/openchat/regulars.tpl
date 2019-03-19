<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['translator']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <script type="text/javascript">
    /*<![CDATA[*/
      function showUserPage(nick)
      {
          satUserPage = window.open('userpage.php?nick='+nick,'satUserPage','width=740,height=350,screenX=50,screenY=50,top=50,left=50,dependent=yes,scrollbars=yes');
          return false;
      }
      
      function openInfoWindow(infoText,coordX,coordY)
      {
        coordY -= 210;
        satInfo = window.open('','satInfo','width=140,height=170,screenX='+coordX+',screenY='+coordY+',top='+coordY+',left='+coordX+',dependent=yes,scrollbars=no');
        
        satInfo.document.write('<html><head><title><?=$_SESSION['translator']->out('INFO')?><\/title>');
        satInfo.document.write('<link rel="stylesheet" title="Default" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />');
        satInfo.document.write('<\/head>');
        satInfo.document.write('<body>');
        satInfo.document.write('<dl class="help"><dt><?=$_SESSION['translator']->out('INFO')?><\/dt><dd>');
        satInfo.document.write(infoText);
        satInfo.document.write('<\/dd><\/dl>');
        satInfo.document.write('<div style="text-align:right;padding-right:3px"><a href="#" onclick="window.close()" style="font-size: .7em"><?=$_SESSION['translator']->out('CLOSE_WINDOW')?><\/a><\/div>');
        satInfo.document.write('<\/body><\/html>');
      }
    /*]]>*/
    </script>
    <!--
      $Id: regulars.tpl,v 1.12.2.2 2004/02/25 22:08:50 letreo Exp $
    -->
  </head>
  <body onload="document.forms[0].elements['chatter'].focus()">
   <?php if(isset($_REQUEST['sat'])){?>
    <div class="satContent">
   <?php }else{?>
    <div class="content">
   <?php }?>
      <h1><?=$_SESSION['translator']->out('REGULARS')?></h1>   
      <div class="contentBox">
        <dl>
          <dt class="contentBoxTitle">
            <?=$_SESSION['translator']->out('REGULARS_HINT')?>&nbsp;<a class="imageLink" title="<?=$_SESSION['translator']->out('INFO')?>" onclick="openInfoWindow('<?=$_SESSION['translator']->out('INFO_RANKING',true)?>',event.screenX,event.screenY)" href="#"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/info.gif" alt="!" border="0" align="middle" /></a>
          </dt>
          <dd style="margin-left:10px;">
            <table width="100%" border="0" cellspacing="0" cellpadding="0">
              <tbody>
                <tr>
                   <th class="formFieldLabel" colspan="4">
                     <form action="regulars.php" method="post">
                       <p>
                         <?=$_SESSION['translator']->out('CHATTER')?>:&nbsp;<input type="text" name="chatter" />
                         <input class="submit" style="width:80px" type="submit" value="<?=$_SESSION['translator']->out('SEARCH')?>" />
                         <?php if(isset($_REQUEST['sat'])){?>
                         <input name="sat" type="hidden" value="1" />
                         <?php }?>
                       </p>
                     </form>
                   </th>
                   <td align="right">*<?=$_SESSION['translator']->out('SINCE_REGISTRATION')?></td>
                </tr>
              </tbody>
              <?php if(count($TEMPLATE_OUT['search_results'])>1){?>
                <tbody>
                   <tr>
                   <th colspan="2" align="left" width="150"><u><?=$_SESSION['translator']->out('SEARCH_RESULTS')?></u>:</th>
                     <th align="left"><?=$_SESSION['translator']->out('LINES_PER_DAY')?>*</th>
                     <th align="left"><?=$_SESSION['translator']->out('LOGINS_PER_DAY')?>*</th>
                     <th align="left"><?=$_SESSION['translator']->out('ONLINE_TIME')?></th>
                   </tr>
                </tbody>
                <tbody>
                   <tr>
                     <td colspan="2">
                       <a style="font-weight:bold" onclick="showUserPage('<?=$TEMPLATE_OUT['search_results']['chatter']?>');return false" href="#" target="satUserPage"><?=$TEMPLATE_OUT['search_results']['chatter']?></a><br />
                       <?=$_SESSION['translator']->out('RANK')?>: <strong><?=$TEMPLATE_OUT['search_results']['rank']?>.</strong><br />
                       <?=$_SESSION['translator']->out('GRADE')?>: <strong><?=$TEMPLATE_OUT['search_results']['grade']?></strong>
                     </td>
                     <td align="center" valign="top"><?=$TEMPLATE_OUT['search_results']['lines_per_day']?></td>
                     <td align="center" valign="top"><?=$TEMPLATE_OUT['search_results']['logins_per_day']?></td>
                     <td align="center" valign="top"><?=$TEMPLATE_OUT['search_results']['online_time']?></td>
                   </tr>
                </tbody>
              <?php }else{?>
              <tbody>
                <tr>
                   <td colspan="5"><?=$TEMPLATE_OUT['search_results']['not_found']?>.</td>
                </tr>
              </tbody>
              <?php }?>
              <tbody>
                <tr>
                   <td style="border-top: 1px solid #000" colspan="5">&nbsp;</td>
                </tr>
                <tr>
                   <th colspan="2" align="left" width="150"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/grade_elite.gif" alt="" />&nbsp;<?=$_SESSION['translator']->out('GRADE')?> "<?=$_SESSION['translator']->out('GRADE_ELITE')?>"</th>
                   <th align="left"><?=$_SESSION['translator']->out('LINES_PER_DAY')?>* >= <?=$TEMPLATE_OUT['min_lines_per_day_elite']?></th>
                   <th align="left"><?=$_SESSION['translator']->out('LOGINS_PER_DAY')?>* >= <?=$TEMPLATE_OUT['min_logins_per_day_elite']?></th>
                   <th align="left"><?=$_SESSION['translator']->out('ONLINE_TIME')?> >= <?=$TEMPLATE_OUT['min_online_time_elite']?><!-- (<?=$_SESSION['translator']->out('DAYS')?>)--></th>
                </tr>
              </tbody>
              <tbody>
                <?=$TEMPLATE_OUT['elite_table_rows']?>
              </tbody>
              <tbody>
                <tr>
                   <th colspan="2" align="left" width="150"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/grade_regular.gif" alt="" />&nbsp;<?=$_SESSION['translator']->out('GRADE')?> "<?=$_SESSION['translator']->out('GRADE_REGULAR')?>"</th>
                   <th align="left"><?=$_SESSION['translator']->out('LINES_PER_DAY')?>* >= <?=$TEMPLATE_OUT['min_lines_per_day_regular']?></th>
                   <th align="left"><?=$_SESSION['translator']->out('LOGINS_PER_DAY')?>* >= <?=$TEMPLATE_OUT['min_logins_per_day_regular']?></th>
                   <th align="left"><?=$_SESSION['translator']->out('ONLINE_TIME')?> >= <?=$TEMPLATE_OUT['min_online_time_regular']?><!-- (<?=$_SESSION['translator']->out('DAYS')?>)--></th>
                </tr>
              </tbody>
              <tbody>
                <?=$TEMPLATE_OUT['regular_table_rows']?>
              </tbody>
              <tbody>
                <tr>
                   <th colspan="2" align="left" width="150"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/grade_member.gif" alt="" />&nbsp;<?=$_SESSION['translator']->out('GRADE')?> "<?=$_SESSION['translator']->out('GRADE_MEMBER')?>"</th>
                   <th align="left"><?=$_SESSION['translator']->out('LINES_PER_DAY')?>* >= <?=$TEMPLATE_OUT['min_lines_per_day_member']?></th>
                   <th align="left"><?=$_SESSION['translator']->out('LOGINS_PER_DAY')?>* >= <?=$TEMPLATE_OUT['min_logins_per_day_member']?></th>
                   <th align="left"><?=$_SESSION['translator']->out('ONLINE_TIME')?> >= <?=$TEMPLATE_OUT['min_online_time_member']?><!-- (<?=$_SESSION['translator']->out('DAYS')?>)--></th>
                </tr>
              </tbody>
              <tbody>
                <?=$TEMPLATE_OUT['member_table_rows']?>
              </tbody>
              <tbody>
                <tr>
                   <th colspan="2" align="left" width="150"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/grade_rookie.gif" alt="" />&nbsp;<?=$_SESSION['translator']->out('GRADE')?> "<?=$_SESSION['translator']->out('GRADE_ROOKIE')?>"</th>
                   <th>&nbsp;</th>
                   <th>&nbsp;</th>
                   <th>&nbsp;</th>
                </tr>
              </tbody>
              <tbody>
                <?=$TEMPLATE_OUT['rookie_table_rows']?>
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