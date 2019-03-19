<?php
//nocaching headers
header ('Cache-Control: private, pre-check=0, post-check=0, max-age=0');
header ('Expires: ' . gmdate('D, d M Y H:i:s', time()) . ' GMT');
header ('Last-Modified: ' . gmdate('D, d M Y H:i:s') . ' GMT');

require_once('config.inc.php');

if( !defined('ALLOW_SPYING') || !ALLOW_SPYING )
  die('<html><body onload="window.close()"></body></html>');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Recipient.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel.inc');
require_once(POC_INCLUDE_PATH.'/class.Line.inc');
require_once(POC_INCLUDE_PATH.'/class.HttpNegotiation.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

$myChat       = &new POC_Chat();
$myTranslator = &new POC_Translator();
$myTemplate   = &new POC_Template();
$channels     = array();
$myChat->connect();
  $channels = $myChat->get_channels();
$myChat->disconnect();


if(!isset($_GET['channel'])
||  empty($_GET['channel'])
|| !in_array($_GET['channel'],$channels)){
  die('<html><body onload="window.close()"></body></html>');
}

$serverVariants    = 'en,de,fr;q=0.9';
$defaultVariant    = 'en';
$myhttpneg         = &new HttpNegotiation();
$preferredLanguage = $myhttpneg->getPreferredLanguage($serverVariants, $defaultVariant);
$myTranslator->set_language($preferredLanguage);

$_SESSION['translator'] = $myTranslator;

$myChannel = &new POC_Channel($_GET['channel']);
$chatters  = $myChannel->get_chatters();

$TEMPLATE_OUT['chatters'] = '';
foreach ($chatters as $history_chatter){
  $TEMPLATE_OUT['chatters'] .= '<li>'.preg_replace("/\#{3}([^#]*)\#{3}/e", "htmlentities(\$_SESSION['translator']->out('\\1'))", $history_chatter['NICK']).'</li>';
}

$myBuffer = &new POC_Channel_Buffer($myChannel->get_name());
$myBuffer->connect();
 $lines = $myBuffer->get_all_lines_in_buffer();
$myBuffer->disconnect();
$TEMPLATE_OUT['lines'] = '';
foreach($lines as $history_line){
  if(!is_object($history_line)) continue;
  if($history_line->is_whispered() || ($myChannel->is_moderated() && !$history_line->get_approved()))
    continue;
  $history_line_sender    = $history_line->get_sender();
  $history_line_recipient = $history_line->get_recipient();
  $TEMPLATE_OUT['lines'] .= '<div class="spyLine" style="color:#'.$history_line_sender->get_color().'">'.HTML_BEFORE_LINE;
  $TEMPLATE_OUT['lines'] .= '<span>'.$history_line->get_time('H:i:s').'</span>';
  $TEMPLATE_OUT['lines'] .= '&nbsp;<span>'.$history_line_sender->get_nick().'</span>';
  if(is_object($history_line_recipient)){
    $TEMPLATE_OUT['lines'] .= '&nbsp;';
    $TEMPLATE_OUT['lines'] .= ($history_line->get_whispered())? 
                  $myTranslator->out('WHISPERS_TO',true):
                  $myTranslator->out('SAYS_TO',true);
    $TEMPLATE_OUT['lines'] .= '&nbsp;<span>'.$history_line_recipient->get_nick().'</span>';
  }
  
  $TEMPLATE_OUT['lines'] .= ':&nbsp;';
  $history_line->filter_buffer_output();
  $TEMPLATE_OUT['lines'] .= $history_line->get_said().HTML_AFTER_LINE.'</div>';
}

if(!isset($_SESSION['template'])){
  if(function_exists('session_register')){
    session_register('template');
  }
  $template = &new POC_Template();
  $_SESSION['template'] = $template;
  if( isset($_SESSION['chatter']) )
    $_SESSION['template']->set_theme( $_SESSION['chatter']->get_theme() );
}
$_SESSION['template']->get_template();
?>