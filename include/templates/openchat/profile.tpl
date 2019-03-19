<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['translator']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content="<?=$_SESSION['template']->get_content_type()?>; charset='<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>'" />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <script type="text/javascript">
    /*<![CDATA[*/
    function confirmGender( gender )
    {
      var genders = new Array();
      genders['f'] = '<?=$_SESSION['translator']->out('FEMALE')?>';
      genders['m'] = '<?=$_SESSION['translator']->out('MALE')?>';
      
      confirm('<?=$_SESSION['translator']->out('GENDER_NOTE')?> <?=$_SESSION['translator']->out('GENDER')?>: "' + genders[gender.value] + '"?');
    }

    function openWindow (url)
    {
      var param = '';
      if( url != '' )
      {
        param = document.forms[0].elements['misc'].value;
        if( param == '' ) return false;
      }
      satProfileMisc = window.open(url+"&title="+param,"satProfileMisc","width=520,height=190,left=30,top=30,dependent=yes,scrollbars=yes");
      window.satProfileMisc.focus();
    }
    
    function closeWindow()
    {
      if(window.satProfileMisc) window.satProfileMisc.close();
    }
    /*]]>*/
    </script>
    <!--
      $Id: profile.tpl,v 1.20.2.3 2004/02/25 22:08:50 letreo Exp $
    -->
  </head>
  <body onunload="closeWindow()">
    <div class="satContent">
      <h1><?=$_SESSION['translator']->out('PROFILE')?></h1>
      <div class="contentBox">
        <span class="status"><?=$TEMPLATE_OUT['update_status']?></span>
        <form action="profile.php" method="post">
        <table width="100%" cellpadding="0" cellspacing="0" border="0">
          <tbody>
            <tr>
              <th class="leftColum"><?=$_SESSION['translator']->out('NICKNAME')?>:&nbsp;</th>
              <td class="rightColum"><?=$_SESSION['chatter']->get_nick()?></td>
            </tr>
            <tr>
              <th class="leftColum"><?=$_SESSION['translator']->out('PASSWORD')?>:&nbsp;</th>
              <td class="rightColum">
                <span class="error"><?php if(isset($TEMPLATE_OUT['errors']['password']))echo$TEMPLATE_OUT['errors']['password']?></span><br />
                <input class="profileInput" name="password" type="password" value="<?=$_SESSION['chatter']->get_password()?>" />
              </td>
            </tr>
            <tr>
              <th class="leftColum"><?=$_SESSION['translator']->out('NAME')?>:&nbsp;</th>
              <td class="rightColum">
                <span class="error"><?php if(isset($TEMPLATE_OUT['errors']['name']))echo$TEMPLATE_OUT['errors']['name']?></span><br />
                <input class="profileInput" name="name" type="text" value="<?=$_SESSION['chatter']->get_name()?>" />
              </td>
            </tr>
            <tr>
              <th class="leftColum"><?=$_SESSION['translator']->out('GENDER')?>:&nbsp;</th>
              <td class="rightColum">
                <?=$TEMPLATE_OUT['hiddenGender']?>
                <select onchange="confirmGender(this)" class="formField" name="gender" <?=$TEMPLATE_OUT['disableGender']?>>
                  <option value=""></option>
                  <option value="f" <?=$TEMPLATE_OUT['genderFemaleSelected']?>>
                    <?=$_SESSION['translator']->out('FEMALE')?>
                  </option>
                  <option value="m" <?=$TEMPLATE_OUT['genderMaleSelected']?>>
                    <?=$_SESSION['translator']->out('MALE')?>
                  </option>
                </select>
              </td>
            </tr>
            <tr>
              <th class="leftColum"><?=$_SESSION['translator']->out('BIRTHDAY')?>:&nbsp;</th>
              <td class="rightColum">
                <span class="error">&nbsp;</span><br />
                <select class="formField" name="birthday">
                  <option value="00"></option>
                  <?=$TEMPLATE_OUT['day_option_list']?>
                </select>.
                <select class="formField" name="birthmonth">
                  <option value="00"></option>
                  <?=$TEMPLATE_OUT['month_option_list']?>
                </select>.
                <select class="formField" name="birthyear">
                  <option value="0000"></option>
                  <?=$TEMPLATE_OUT['year_option_list']?>
                </select>
              </td>
            </tr>
            <tr>
              <th class="leftColum"><?=$_SESSION['translator']->out('EMAIL')?>:&nbsp;</th>
              <td class="rightColum">
                <span class="error"><?php if(isset($TEMPLATE_OUT['errors']['email']))echo$TEMPLATE_OUT['errors']['email']?></span><br />
                <input class="profileInput" name="email" type="text" value="<?=$_SESSION['chatter']->get_email()?>" /><br />
                <?=$_SESSION['translator']->out('HIDE')?> <input name="hideEmail" type="checkbox" value="1" <?=$TEMPLATE_OUT['hideEmail_checked']?> />
              </td>
            </tr>
            <tr>
              <th class="leftColum"><?=$_SESSION['translator']->out('PICTURE_URL')?>:&nbsp;</th>
              <td class="rightColum">
                <span class="error"><?php if(isset($TEMPLATE_OUT['errors']['pictureURL']))echo$TEMPLATE_OUT['errors']['pictureURL']?></span><br />
                <input class="profileInput" name="pictureURL" type="text" value="<?=$_SESSION['chatter']->get_pictureURL()?>" /></td>
            </tr>
            <tr>
              <th class="leftColum"><?=$_SESSION['translator']->out('HOMEPAGE_URL')?>:&nbsp;</th>
              <td class="rightColum">
                <span class="error"><?php if(isset($TEMPLATE_OUT['errors']['homePageURL']))echo$TEMPLATE_OUT['errors']['homePageURL']?></span><br />
                <input class="profileInput" name="homePageURL" type="text" value="<?=$_SESSION['chatter']->get_homePageURL()?>" /></td>
            </tr>
            <tr>
              <th class="leftColum"><?=$_SESSION['translator']->out('INTERESTS')?>:&nbsp;</th>
              <td class="rightColum">
                <span class="error"><?php if(isset($TEMPLATE_OUT['errors']['interests']))echo$TEMPLATE_OUT['errors']['interests']?></span><br />
                <textarea class="profileInput" name="interests" rows="3" cols="30"><?=$_SESSION['chatter']->get_interests()?></textarea></td>
            </tr>
            <tr>
              <th class="leftColum"><?=$_SESSION['translator']->out('MOTTO')?>:&nbsp;</th>
              <td class="rightColum">
                <span class="error"><?php if(isset($TEMPLATE_OUT['errors']['motto']))echo$TEMPLATE_OUT['errors']['motto']?></span><br />
                <textarea class="profileInput" name="motto" rows="3" cols="30"><?=$_SESSION['chatter']->get_motto()?></textarea></td>
            </tr>
            <tr>
              <th class="leftColum"><?=$_SESSION['translator']->out('ICQ_NUMBER')?>:&nbsp;</th>
              <td class="rightColum">
                <span class="error"><?php if(isset($TEMPLATE_OUT['errors']['icqNumber']))echo$TEMPLATE_OUT['errors']['icqNumber']?></span><br />
                <input class="profileInput" name="icqNumber" type="text" value="<?=$_SESSION['chatter']->get_icqNumber()?>" /></td>
            </tr>
            <tr>
              <th class="leftColum"><?=$_SESSION['translator']->out('AIM_NICKNAME')?>:&nbsp;</th>
              <td class="rightColum">
                <span class="error"><?php if(isset($TEMPLATE_OUT['errors']['aimNickname']))echo$TEMPLATE_OUT['errors']['aimNickname']?></span><br />
                <input class="profileInput" name="aimNickname" type="text" value="<?=$_SESSION['chatter']->get_aimNickname()?>" /></td>
            </tr>
            <tr>
              <th class="leftColum"><?=$_SESSION['translator']->out('YIM_NICKNAME')?>:&nbsp;</th>
              <td class="rightColum">
                <span class="error"><?php if(isset($TEMPLATE_OUT['errors']['yimNickname']))echo$TEMPLATE_OUT['errors']['yimNickname']?></span><br />
                <input class="profileInput" name="yimNickname" type="text" value="<?=$_SESSION['chatter']->get_yimNickname()?>" /></td>
            </tr>
            <tr>
              <th class="leftColum"><a name="misc"></a><?=$_SESSION['translator']->out('MISCELLANEOUS')?></th>
              <td class="rightColum" style="padding-top:10px;">
                <select name="misc" style="width:160px;float:left" size="5">
                  <?=$TEMPLATE_OUT['misc_options']?>
                </select>
                <a title="<?=$_SESSION['translator']->out('EDIT')?>" class="imageLink" href="#" onclick="openWindow('profile_misc.php?action=edit&amp;<?=$_SESSION['session_get']?>');return false" target="satProfileMisc">
                  <img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/edit.gif" alt="" border="0" /></a><br />
                <a title="<?=$_SESSION['translator']->out('CREATE_NEW')?>" class="imageLink" href="profile_misc.php?action=add&amp;<?=$_SESSION['session_get']?>" onclick="openWindow('')" target="satProfileMisc">
                  <img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/add.gif" alt="" border="0" /></a><br />

                <a title="<?=$_SESSION['translator']->out('DELETE')?>" class="imageLink" href="#" onclick="openWindow('profile_misc.php?action=del&amp;<?=$_SESSION['session_get']?>');return false" target="satProfileMisc">
                  <img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/trash.gif" alt="" border="0" /></a>              </td>
            </tr>
            <tr>
              <td class="leftColum">&nbsp;</td>
              <td class="rightColum"><input class="submit" style="margin-top:20px" name="changeProfile" type="submit" value="<?=$_SESSION['translator']->out('CHANGE_PROFILE')?>!" /></td>
            </tr>
          </tbody>
        </table>
        </form>
        <?php if(ALLOW_PRIVATE_IMAGES){?>
        <form enctype="multipart/form-data" action="profile.php" method="post">
        <table width="100%" border="0">
          <tbody>
            <tr>
              <th align="left" valign="bottom"><?=$_SESSION['translator']->out('PRIVATE_IMAGE')?>: </th>
              <td align="left" valign="bottom"><?=$TEMPLATE_OUT['private_image']?></td>
            </tr>
            <tr>
              <td colspan="2"><?=$TEMPLATE_OUT['file_upload_errors']?></td>
            </tr>
            <tr>
              <td colspan="2">
                <input class="profileInput" type="file" name="chatter_image" />
                <input class="submit" style="margin-left:100px;width:50px" type="submit" name="uploadImage" value="Upload" />
              </td>
            </tr>
          </tbody>
        </table>
        </form>
        <?php }?>
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