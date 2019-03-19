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
  $Date: 2004/02/25 22:11:06 $
  $Source: /cvsroot/phpopenchat/chat3/mail.php,v $
  $Revision: 1.30.2.7 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');
require_once(POC_INCLUDE_PATH.'/class.Mail.inc');
require_once(POC_INCLUDE_PATH.'/class.Mailbox.inc');
require_once(POC_INCLUDE_PATH.'/class.Mail_Dispatcher.inc');

session_start();

//check if chatter is authorized to get this page
if( !isset($_SESSION['chatter']) )
  die('Login first!');

$_SESSION['reload_count'] = 0;//reset chat session expiration time
if( $_SESSION['chatter']->is_guest() )
  die($_SESSION['translator']->out('DENIED_FOR_GUESTS'));
  
$errors = array();
if( isset($_POST['display_content']) && $_POST['display_content'] == 'compose' )
  $_GET['display_content'] = $_POST['display_content'];

function count_all_mails()
{
  $inbox  = &new POC_Mailbox( 'inbox' );
  $outbox = &new POC_Mailbox( 'outbox' );
  $trash  = &new POC_Mailbox( 'trash' );
  
  $_SESSION['inbox_count_new'] = $inbox->get_unread_mail_count(); 
  $_SESSION['outbox_count_new'] = $outbox->get_unread_mail_count(); 
  $_SESSION['trash_count_new'] = $trash->get_unread_mail_count();
  
  unset($inbox);
  unset($outbox);
  unset($trash);
}

function reload_mailbox()
{
  $mailbox = &new POC_Mailbox( $_SESSION['current_mailbox_type'] );
  $_SESSION['mailbox'] = $mailbox;
}
  
function load_subjects()
{
  global $TEMPLATE_OUT;
  
  if( !$_SESSION['mailbox']->is_empty() )
  {
    $mail_count = $_SESSION['mailbox']->get_mail_count();
    $TEMPLATE_OUT['subjects'] = '';
    for ($i = 0; $i <= $mail_count-1; $i++)
    {
      $mail = $_SESSION['mailbox']->get_current_mail( $i );
      
      if( isset($_SESSION['curr_mail_idx']) 
             && $_SESSION['curr_mail_idx'] != null 
             && $_SESSION['curr_mail_idx'] == $i )
        $class = 'active';
      else 
        $class = '';
        
      $sender = $mail->get_sender();
            
      if( $mail->is_red_by_recipient() ) {
        $mail_icon = '<img src="'.$_SESSION['template']->get_theme_path().'/images/icons/openmail.gif" alt="red mail" border="0" />';
        $newmail= '';
        $newmail_class= '';
      } else {
        $mail_icon = '<img src="'.$_SESSION['template']->get_theme_path().'/images/icons/newmail.gif" alt="new mail" border="0" />';
        $newmail= 'style="font-weight: bolder;"';
        $newmail_class=(empty($class))? 'boldLink':' boldLink';
      }
      if( $mail->get_last_touch_recipient() > 0 )
        $rcpt_last_touch = gmdate('d.m.y H:i', $mail->get_last_touch_recipient());
      else
        $rcpt_last_touch = '--';
      $TEMPLATE_OUT['subjects'] .= '
            <tr>
              <td style="width:30px" class="noDeco">
                <a class="imageLink" href="mail.php?display_content=mailbody&amp;body='.$i.'">'.$mail_icon.'</a></td>
              <td class="'.$class.'" '.$newmail.'>
                &nbsp;<a href="mail.php?display_content=mailbody&amp;body='.$i.'" class="'.$class.$newmail_class.'">'.$mail->get_subject().'</a>
              </td>
              <td class="'.$class.'" '.$newmail.'>
                <a href="mail.php?display_content=mailbody&amp;body='.$i.'" class="'.$class.$newmail_class.'">'.$_SESSION['mailbox']->get_chatter( $mail, $_SESSION['chatter']->get_nick() ).'</a>
              </td>
              <td class="'.$class.'" '.$newmail.'>
                <a href="mail.php?display_content=mailbody&amp;body='.$i.'" class="'.$class.$newmail_class.'">'.gmdate('d.m.y H:i', $mail->get_send_time()).'</a>
              </td>
              <td class="'.$class.'" '.$newmail.'>
                <a href="mail.php?display_content=mailbody&amp;body='.$i.'" class="'.$class.$newmail_class.'">'.$rcpt_last_touch.'</a>
              </td>
            </tr>
      ';
    }
  }
}

if( isset($_GET['trash']) )
{
  $dispatcher = &new POC_Mail_Dispatcher();
  $mail = $_SESSION['mailbox']->get_current_mail( $_GET['trash'] );
  $dispatcher->trash_mail( $mail, $_SESSION['mailbox'], $_SESSION['chatter']);

  unset($dispatcher);
  unset($mail);
  
  //delete mail from session array
  //$_GET['trash'] is verified by dispatcher
  $_SESSION['mailbox']->delete_mail($_GET['trash']);
  $_SESSION['curr_mail_idx'] = null;
}

if( isset($_POST['send_mail']) )
{      
  $recipients = array();
  $recipients = explode(',', $_POST['recipient']);
  $recipients = array_unique ($recipients);
  $dispatcher = &new POC_Mail_Dispatcher();
  
  while( true )
  {
    if( !isset($_POST['recipient']) || !$dispatcher->check_recipient($recipients) )
    {
      $errors[] = $_SESSION['translator']->out('NO_SUCH_RECIPIENT_FOUND');
      break;
    }
    
    //Create mail object
    $mail = &new POC_Mail();
    reset($recipients);
    do {
      $mail->add_recipient( current($recipients) );
    }while( next($recipients) );
    unset($recipients);
    if( is_string($_POST['subject']) && $_POST['subject'] != '' )
      $mail->set_subject( $_POST['subject'] );
    else
      $mail->set_subject( '(no subject)' );
  
    if( is_string($_POST['body']) && strlen($_POST['body']) >= MIN_MAIL_LENGTH )
      $mail->set_body( $_POST['body'].NL );
    else
    {
      $errors[] = $_SESSION['translator']->out('BODY_TO_SHORT');
      break;
    }
  
    $mail->set_send_time(time());
    //Send mail
    $dispatcher->send_mail($mail);
    unset($dispatcher);
    unset($mail);
    break;
  }
}

$mail_form = '';
$TEMPLATE_OUT['mail_body'] = '';
$TEMPLATE_OUT['title']     = '';
$TEMPLATE_OUT['subjects']  = '';
$TEMPLATE_OUT['body']      = '';
$TEMPLATE_OUT['class_inbox'] = '';
$TEMPLATE_OUT['class_outbox'] = '';
$TEMPLATE_OUT['class_trash'] = '';
$reply_attribute= '';
$TEMPLATE_OUT['mail_body'] = '';
$TEMPLATE_OUT['mail_subject'] = '';
$TEMPLATE_OUT['mail_to'] = '';

if( !isset($_GET['display_content']) )
  $_GET['display_content'] = '';

while( count($errors) == 0 )
{
  switch ( $_GET['display_content'] )
  {
    case 'compose':
      $TEMPLATE_OUT['title'] = '&nbsp;'.$_SESSION['translator']->out('MAIL').' - '.$_SESSION['translator']->out(strtoupper($_GET['display_content']));
      break;
    case 'reply':
      if( !isset($_SESSION['curr_mail_idx']) 
      || is_null($_SESSION['curr_mail_idx']))
      {
        $errors[] = 'no mail index given';
        break 2;
      }
      $TEMPLATE_OUT['title'] = '&nbsp;'.$_SESSION['translator']->out('MAIL').' - '.$_SESSION['translator']->out(strtoupper($_GET['display_content']));
      $mail = $_SESSION['mailbox']->get_current_mail( $_SESSION['curr_mail_idx'] );
      $sender_obj = $mail->get_sender();
      $TEMPLATE_OUT['mail_to'] = $sender_obj->get_nick();
      $TEMPLATE_OUT['mail_subject'] = $mail->get_subject();
      $TEMPLATE_OUT['mail_subject'] = preg_replace('/^Re: (.*)|^(.*)/', 'Re: \0', $TEMPLATE_OUT['mail_subject']);
      $TEMPLATE_OUT['mail_body'] = $mail->get_body();
      $TEMPLATE_OUT['mail_body'] = preg_replace('/(.*)\r\n|(.*)\r|(.*)\n/', '> \0', $TEMPLATE_OUT['mail_body']);
      break;
    case 'forward':
      if( !isset($_SESSION['curr_mail_idx']) 
      || is_null($_SESSION['curr_mail_idx']))
      {
        $errors[] = 'no mail index given';
        break 2;
      }
      $TEMPLATE_OUT['title'] = '&nbsp;'.$_SESSION['translator']->out('MAIL').' - '.$_SESSION['translator']->out(strtoupper($_GET['display_content']));
      $mail = $_SESSION['mailbox']->get_current_mail( $_SESSION['curr_mail_idx'] );
      $sender_obj = $mail->get_sender();
      $sender = $sender_obj->get_nick();
      $TEMPLATE_OUT['mail_subject'] = $mail->get_subject();
      $TEMPLATE_OUT['mail_subject'] = preg_replace('/^(.*)/', 'Fwd: \0', $TEMPLATE_OUT['mail_subject']);
      $TEMPLATE_OUT['mail_body'] = '
  
  
  -------- Original Message --------
  Send date: '.gmdate('D, d M Y H:i:s O', $mail->get_send_time()).'
  From: '.$sender.'
  To: '.$mail->get_recipient().'
  X-Mailer: POC-Mail (http://phpopenchat.sourceforge.net/)
  
  
  ';
      $TEMPLATE_OUT['mail_body'] .= $mail->get_body();
      break;
    case 'mailbody':
      if( !isset($_SESSION['mailbox']) ){
        $current_mailbox_type = 'inbox';
        $_SESSION['current_mailbox_type'] = $current_mailbox_type;
  
        reload_mailbox();
      }
  
      if( isset($_GET['body']) )
      {
        $_SESSION['curr_mail_idx'] = $_GET['body'];
        $reply_attribute='&amp;insert_content=1';
        $mail = $_SESSION['mailbox']->get_current_mail( $_GET['body'] );
        
        //set mail to 'red by reciepient'
        if( $_SESSION['mailbox']->get_type() == 'inbox' 
           && !$mail->is_red_by_recipient() )
        {
          $dispatcher = &new POC_Mail_Dispatcher();
          $mail->set_first_touch_recipient();
          $mail->set_red_by_recipient();
          $dispatcher->make_persistent( $mail );
          unset($dispatcher);
          reload_mailbox();
        }
        
        if( $_SESSION['mailbox']->get_type() == 'inbox' )
        {
          $dispatcher = &new POC_Mail_Dispatcher();
          $mail->set_last_touch_recipient();
          $dispatcher->make_persistent( $mail );
          unset($dispatcher);
          reload_mailbox();        
        }
        
        //set mail to 'red by sender'
        if( $_SESSION['mailbox']->get_type() == 'outbox' 
           && !$mail->is_red_by_sender() )
        {
          $dispatcher = &new POC_Mail_Dispatcher();
          $mail->set_red_by_sender();
          $dispatcher->make_persistent( $mail );
          unset($dispatcher);
          reload_mailbox();
        }
        
        if($_SESSION['mailbox']->get_type() == 'outbox')
        {
          $dispatcher = &new POC_Mail_Dispatcher();
          $mail->set_last_touch_sender();
          $dispatcher->make_persistent( $mail );
          unset($dispatcher);
          reload_mailbox();        
        }
        if($mail->get_last_touch_recipient() != 0)
        {
          if($mail->get_first_touch_recipient() != 0)
            $rcpt_time = gmdate('d.m.y H:i', $mail->get_first_touch_recipient());
          else
            $rcpt_time = '--';
        }
        else 
          $rcpt_time = '';
          
        $TEMPLATE_OUT['body'] = '<div class="header">';
        $sender = $mail->get_sender();
        $TEMPLATE_OUT['body'].= 'Send date: '.gmdate('d.m.Y H:i', $mail->get_send_time()).'<br/>';
        $TEMPLATE_OUT['body'].= 'Opened by recipient: '.$rcpt_time.'<br/>';
        $TEMPLATE_OUT['body'].= 'From: '.$sender->get_nick().'<br/>';
        $TEMPLATE_OUT['body'].= 'To: '.$mail->get_recipient().'<br/>';
        $TEMPLATE_OUT['body'].= '</div>';
        $TEMPLATE_OUT['body'].= preg_replace('/\r\n|\r|\n/', '<br/>', $mail->get_body());
      }
      load_subjects();
      break;
    default:
      if( $_GET['display_content'] != '' )
        die('no such option');
      else 
      {
        if( isset($_GET['current_mailbox_type'] )
           && $_GET['current_mailbox_type'] != $_SESSION['current_mailbox_type'])
        {
          $_SESSION['curr_mail_idx'] = null;
          $current_mailbox_type = $_GET['current_mailbox_type'];
          $_SESSION['current_mailbox_type'] = $current_mailbox_type;
          
          reload_mailbox();
        }
        elseif( !isset($_SESSION['current_mailbox_type']) )
        {
          $current_mailbox_type = 'inbox';
          $_SESSION['current_mailbox_type'] = $current_mailbox_type;
          
          reload_mailbox();
        }
        elseif( isset($_GET['trash']) || isset($_GET['reload_mailbox']) )
        {
          //reload current mailbox
          reload_mailbox();
        }
        
        load_subjects();
      }
  }
  break;
}
//${'class_'.$_SESSION['current_mailbox_type']} = 'class="active"';
$TEMPLATE_OUT['mark_'.$_SESSION['current_mailbox_type']]='border-top: thin solid black;border-bottom: thin solid black;';
count_all_mails();
$TEMPLATE_OUT['new_in_inbox'] = '';$TEMPLATE_OUT['newmail_inbox'] ='';
$TEMPLATE_OUT['new_in_outbox']= '';$TEMPLATE_OUT['newmail_outbox']='';
$TEMPLATE_OUT['new_in_trash'] = '';$TEMPLATE_OUT['newmail_trash'] ='';

if($_SESSION['inbox_count_new'] > 0)
{
  $TEMPLATE_OUT['new_in_inbox'] = '<strong>('.$_SESSION['inbox_count_new'].')</strong>';
  $TEMPLATE_OUT['newmail_inbox'] = 'font-weight: bolder;';
}
if($_SESSION['outbox_count_new'] > 0)
{
  $TEMPLATE_OUT['new_in_outbox'] = '<strong>('.$_SESSION['outbox_count_new'].')</strong>';
  $TEMPLATE_OUT['newmail_outbox'] = 'font-weight: bolder;';
}
 
if($_SESSION['trash_count_new'] > 0)
{
  $TEMPLATE_OUT['new_in_trash'] = '<strong>('.$_SESSION['trash_count_new'].')</strong>';
  $TEMPLATE_OUT['newmail_trash'] = 'font-weight: bolder;';
}

$friends = array();
$friends = $_SESSION['chatter']->get_friends();
$TEMPLATE_OUT['friends_links'] = '';
if( count($friends) > 0 )
{
  reset($friends);
  do
  {
    $TEMPLATE_OUT['friends_links'] .= TAB.'<a href="#" onclick="insertValue(\''.current($friends).'\'); toggleDiv(\'friendsList\')" class="friend">'.current($friends).'</a><br />'.NL;
  }while( next($friends) );
}
else
  $TEMPLATE_OUT['friends_links'] = $_SESSION['translator']->out('NO_FRIENDS_FOUND');

$TEMPLATE_OUT['error'] = '';
if( count($errors) != 0 )
{
  $TEMPLATE_OUT['error'] = '<ul class="error">';
  reset($errors);
  do{
    $TEMPLATE_OUT['error'] .= '<li>'.current($errors).'</li>';
  }while( next($errors) );
  $TEMPLATE_OUT['error'] .= '</ul>';
  
  if( isset($_POST['subject']) )
    $TEMPLATE_OUT['mail_subject'] = $_POST['subject'];
  if( isset($_POST['recipient']) )
    $TEMPLATE_OUT['mail_to'] = $_POST['recipient'];
  if( isset($_POST['body']) )
    $TEMPLATE_OUT['mail_body'] = $_POST['body'];
}
$_SESSION['template']->get_template();
?>