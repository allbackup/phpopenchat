<?php //-*-php-*-
/*   ********************************************************************   **
**   Copyright notice                                                       **
**                                                                          **
**   (c) 1995-2004 PHPOpenChat Development Team                             **
**   http://phpopenchat.sourceforge.net/                                    **
**                                                                          **
**   All rights reserved                                                    **
**                                                                          **
**   This script is part of the PHPOpenChat project. The PHPOpenChat        **
**   project is free software; you can redistribute it and/or modify        **
**   it under the terms of the GNU General Public License as published by   **
**   the Free Software Foundation; either version 2 of the License, or      **
**   (at your option) any later version.                                    **
**                                                                          **
**   The GNU General Public License can be found at                         **
**   http://www.gnu.org/copyleft/gpl.html.                                  **
**   A copy is found in the textfile GPL and important notices to the       **
**   license from the team is found in the textfile LICENSE distributed     **
**   with these scripts.                                                    **
**                                                                          **
**   This script is distributed in the hope that it will be useful,         **
**   but WITHOUT ANY WARRANTY; without even the implied warranty of         **
**   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          **
**   GNU General Public License for more details.                           **
**                                                                          **
**   This copyright notice MUST APPEAR in all copies of the script!         **
**   ********************************************************************   */

/*
  $Author: letreo $
  $Date: 2004/02/24 17:05:18 $
  $Source: /cvsroot/phpopenchat/chat3/profile.php,v $
  $Revision: 1.20.2.4 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');
require_once(POC_INCLUDE_PATH.'/class.UploadFile.inc');

session_start();

//check if chatter is authorized to get this page
if( !isset($_SESSION['chatter']) )
  die('Login first!');
  
$_SESSION['reload_count'] = 0;
if( $_SESSION['chatter']->is_guest() )
  die($_SESSION['translator']->out('DENIED_FOR_GUESTS'));

$errors = array();
$update_status = '';

$_SESSION['chatter']->init_additional_profile_data();
function analyze_post_data()
{
  global $errors;

  //password
  if( !isset($_POST['password']) 
  || $_POST['password'] == '' 
  || !$_SESSION['chatter']->set_password( $_POST['password'] ) )
    $errors['password'] = $_SESSION['translator']->out('ERROR_PASSWORD');

  //user name
  if( !isset($_POST['name'])
  || !$_SESSION['chatter']->set_name( $_POST['name'] )
  || $_POST['name'] == '' )
    $errors['name'] = $_SESSION['translator']->out('ERROR_NAME');

  //birthday
  if( !$_SESSION['chatter']->set_birthday($_POST['birthyear'].'-'.$_POST['birthmonth'].'-'.$_POST['birthday']) )
    $errors['birthday'] = $_SESSION['translator']->out('ERROR_BIRTHDAY');

  //email
  if( !isset($_POST['email']) 
  || $_POST['email'] == ''
  || !$_SESSION['chatter']->set_email( $_POST['email'] ) )
    $errors['email'] = $_SESSION['translator']->out('ERROR_EMAIL');

  //hide email?
  $bool = ($_POST['hideEmail']==1)? true:false;
  $_SESSION['chatter']->set_hide('email',$bool);
  
  //gender
  $_SESSION['chatter']->set_gender( $_POST['gender'] );
  
  //pictureURL
  if( !isset($_POST['pictureURL'])
  || !$_SESSION['chatter']->set_pictureURL( $_POST['pictureURL'] ) )
    $errors['pictureURL'] = $_SESSION['translator']->out('ERROR_PICTURE_URL');
    
  //homePageURL
  if( !isset($_POST['homePageURL'])
  || !$_SESSION['chatter']->set_homePageURL( $_POST['homePageURL'] ) )
    $errors['homePageURL'] = $_SESSION['translator']->out('ERROR_HOMEPAGE_URL');
  
  //Interests
  if( !$_SESSION['chatter']->set_interests($_POST['interests']) )
    $errors['interests'] = $_SESSION['translator']->out('ERROR_INTERESTS');

  //Motto
  if( !$_SESSION['chatter']->set_motto($_POST['motto']) )
    $errors['motto'] = $_SESSION['translator']->out('ERROR_MOTTO');

  //ICQ number
  if( !isset($_POST['icqNumber']) || !$_SESSION['chatter']->set_icqNumber($_POST['icqNumber']) )
    $errors['icqNumber'] = $_SESSION['translator']->out('ERROR_ICQ_NUMBER');
    
  //AIM nickname
  if( !isset($_POST['aimNickname']) || !$_SESSION['chatter']->set_aimNickname($_POST['aimNickname']) )
    $errors['aimNickname'] = $_SESSION['translator']->out('ERROR_AIM_NICKNAME');
    
  //YIM nickname
  if( !isset($_POST['yimNickname']) || !$_SESSION['chatter']->set_yimNickname($_POST['yimNickname']) )
    $errors['yimNickname'] = $_SESSION['translator']->out('ERROR_YIM_NICKNAME');

  return ( count($errors) == 0);
}

if(!isset($_POST['hideEmail'])) $_POST['hideEmail'] = 0;

if( isset($_POST['changeProfile']) )
{
  if( analyze_post_data() )
  {
    $update_status = $_SESSION['translator']->out('PROFILE_UPDATA_SUCCESSFUL');
    $_SESSION['chatter']->update();
  }
  else 
    $update_status = $_SESSION['translator']->out('PROFILE_UPDATA_NOT_SUCCESSFUL');
}
else
{
  $day_of_birth        = $_SESSION['chatter']->get_birthday();
  $parts               = split('-',$day_of_birth);
  $_POST['birthday']   = $parts[2];
  $_POST['birthmonth'] = $parts[1];
  $_POST['birthyear']  = $parts[0];
  unset($parts);
  $_POST['hideEmail']  = ($_SESSION['chatter']->get_hide('email')==true)? '1':'0';
  $_POST['gender']     = $_SESSION['chatter']->get_gender();
}
$disableGender = ($_POST['gender']=='')? '':'disabled="disabled"';
$hiddenGender = ($disableGender=='disabled="disabled"')? '<input type="hidden" name="gender" value="'.$_POST['gender'].'"/>'.NL:'';
$file_upload_errors = '';
$upload_errors = array();
if( isset($_POST['uploadImage']) && isset($_FILES['chatter_image']) )
{
  
  $uploader = &new POC_UploadFile( $_FILES['chatter_image'] );
  $uploader->set_types( $ACCEPTED_MIME_TYPES );//defined in config.inc.php
  $uploader->set_upload_path( $_SESSION['template']->get_tmpl_sys_path().'/images/icons/chatter/' );

  if( !$uploader->check() )
    $upload_errors = $uploader->get_errors();
  else
  {
    if(!$uploader->upload( PRIVATE_IMG_SAVE_MODE ))
    {
      $upload_errors = $uploader->get_errors();
      if(isset($upload_errors[0]))
        print $upload_errors[0];
      die('Unable to create file: Permission denied<br>Check write permissions of your web server in: '.$uploader->get_upload_path() );
    }
  }

  if( count($upload_errors) > 0 )
  {
    $file_upload_errors = '<menu class="uploadErrors">'.NL;
    reset($upload_errors);
    do{
      $file_upload_errors .= TAB.'<li>'.current($upload_errors).'</li>'.NL;
    }while(next($upload_errors));
    $file_upload_errors .= '</menu>'.NL;
  }
}

$private_image = '';
$smiley_dir  = '/images/icons/chatter';
for ($i=0;$i<count($ACCEPTED_MIME_TYPES);$i++)
{
  preg_match('#image/[x\-]?(.*)#',$ACCEPTED_MIME_TYPES[$i], $parts);
  $file_extension = $parts[1];
  $smiley_path = $smiley_dir . '/' . strtolower($_SESSION['chatter']->get_nick()).'.'.$file_extension;
  if( file_exists($_SESSION['template']->get_tmpl_sys_path().$smiley_path) )
    $private_image = '<img src="'.$_SESSION['template']->get_tmpl_web_path().$smiley_path.'" align="middle" alt="'.$_SESSION['translator']->out('PRIVATE_IMAGE').'" />';
}

$year_option_list = '';
$selected='';
$current_year = date('Y', time());
for ($i=MIN_BIRTHDAY_YEAR;$i<=$current_year;$i++)
{
  if( isset($_POST['birthyear']) && $_POST['birthyear'] == $i ) $selected='selected="selected"';
  $year_option_list .= '<option value="'.$i.'" '.$selected.'>'.$i.'</option>';
  $selected='';
}

$month_option_list = '';
for ($i=1;$i<=12;$i++)
{
  if( isset($_POST['birthmonth']) && intval($_POST['birthmonth']) == $i ) $selected='selected="selected"';
  $month_option_list .= '<option value="'.$i.'" '.$selected.'>'.$i.'</option>';
  $selected='';
}

$day_option_list = '';
for ($i=1;$i<=31;$i++)
{
  if( isset($_POST['birthday']) && intval($_POST['birthday']) == $i ) $selected='selected="selected"';
  $day_option_list .= '<option value="'.$i.'" '.$selected.'>'.$i.'</option>';
  $selected='';
}

$genderFemaleSelected = ( $_POST['gender'] == 'f')? 'selected="selected"':'';
$genderMaleSelected   = ( $_POST['gender'] == 'm')? 'selected="selected"':'';
$hideEmail_checked    = ( $_POST['hideEmail'] == 1 )? 'checked="checked"':'';

$TEMPLATE_OUT['update_status'] = $update_status;
$TEMPLATE_OUT['errors'] = $errors;
$TEMPLATE_OUT['private_image'] = $private_image;
$TEMPLATE_OUT['file_upload_errors'] = $file_upload_errors;
$TEMPLATE_OUT['hiddenGender'] = $hiddenGender;
$TEMPLATE_OUT['disableGender'] = $disableGender;
$TEMPLATE_OUT['genderFemaleSelected'] = $genderFemaleSelected;
$TEMPLATE_OUT['genderMaleSelected'] = $genderMaleSelected;
$TEMPLATE_OUT['day_option_list'] = $day_option_list;
$TEMPLATE_OUT['month_option_list'] = $month_option_list;
$TEMPLATE_OUT['year_option_list'] = $year_option_list;
$TEMPLATE_OUT['hideEmail_checked'] = $hideEmail_checked;

$TEMPLATE_OUT['misc_options'] = '<option />';
$misc = array();
$misc = $_SESSION['chatter']->get_profile_misc();
foreach($misc as $key => $value)
{
  $TEMPLATE_OUT['misc_options'] .= TAB.'<option value="'.$value[0].'">'.$value[0].'</option>'.NL;
}

header('Content-type: text/html; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));
$_SESSION['template']->get_template();
?>