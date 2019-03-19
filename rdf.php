<?php
// XML and nocaching headers
header ('Cache-Control: private, pre-check=0, post-check=0, max-age=0');
header ('Expires: ' . gmdate('D, d M Y H:i:s', time()) . ' GMT');
header ('Last-Modified: ' . gmdate('D, d M Y H:i:s') . ' GMT');

require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Recipient.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel.inc');
require_once(POC_INCLUDE_PATH.'/class.Line.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');
require_once(POC_INCLUDE_PATH.'/class.HttpNegotiation.inc');

session_start();

if(!isset($_SESSION['template']))die('<html><body onload="window.close()"></body></html>');

if(!isset($_SESSION['translator'])){
  if(function_exists('session_register'))session_register('translator'); 
  
  $serverVariants    = 'en,de,fr;q=0.9';
  $defaultVariant    = 'en';
  $myhttpneg         = &new HttpNegotiation();
  $preferredLanguage = $myhttpneg->getPreferredLanguage($serverVariants, $defaultVariant);
  $translator->set_language($preferredLanguage);
  $_SESSION['translator'] = $translator;
}

$serverVariants = 'application/rdf+xml,text/xml;q=0.9';
$defaultVariant = 'text/xml';
$myhttpneg = &new HttpNegotiation();
$preferredContentType = $myhttpneg->getPreferredContentType($serverVariants, $defaultVariant);
header ('Content-Type: '.$preferredContentType);

$myChat       = &new POC_Chat();
$myTranslator = &new POC_Translator();
$myTemplate   = &new POC_Template();
$channels     = array();
$myChat->connect();
  $channels = $myChat->get_channels();
$myChat->disconnect();

$TEMPLATE_OUT['chat_name'] = $myChat->get_name();
$TEMPLATE_OUT['chat_link'] = $myTemplate->get_poc_web_root().$myTemplate->get_web_root();

foreach ($channels as $_channel){
  $myChannel = &new POC_Channel($_channel);
  $TEMPLATE_OUT['chat_channels'][] = $_channel;
  $TEMPLATE_OUT[$_channel.'channel_title'] = $myChannel->get_name();
  $TEMPLATE_OUT[$_channel.'channel_message'] = $myChannel->get_message();
  $TEMPLATE_OUT[$_channel.'channel_chatters'] = $myChannel->get_chatters();

  $myBuffer = &new POC_Channel_Buffer($myChannel->get_name());
  $myBuffer->connect();
    $lines = $myBuffer->get_all_lines_in_buffer();
  $myBuffer->disconnect();
  
  $TEMPLATE_OUT[$_channel.'all_lines'] = array();
  $TEMPLATE_OUT[$_channel.'all_lines_said'] = array();
  $c = 0;
  foreach ($lines as $line){
    if(!is_object($line)) continue;
    
    if($line->is_whispered() 
    || ($myChannel->is_moderated() 
    && !$line->get_approved()))continue;
    $TEMPLATE_OUT[$_channel.'all_lines'][] = 1;
    $line_sender    = $line->get_chatter();
    $line_recipient = $line->get_recipient();
    $nick = (is_object($line_recipient))? $line_recipient->get_nick().': ':'';
    
    $img_prefixed = preg_replace('#<img.*/>#e', 'image', $line->get_said());
    $TEMPLATE_OUT[$_channel.'all_lines_said'][]   = $nick.preg_replace( "/\#{3}([^#]*)\#{3}/e", "htmlentities(\$myTranslator->out('\\1'))", $img_prefixed );
    $timeTrailer = (isset($oldTime) && $oldTime==$line->get_time('\TH-i-s'))? '-'.++$c:'';
    $TEMPLATE_OUT[$_channel.'all_lines_time1'][]  = $line->get_time('\TH-i-s').$timeTrailer;//T19-52-40-1 the last digit is needed to make the ID unique
    $oldTime = $line->get_time('\TH-i-s');
    $TEMPLATE_OUT[$_channel.'all_lines_time2'][]  = $line->get_time('Y-m-d\TH:i:s\Z');//2002-08-10T19:52:40Z
    $TEMPLATE_OUT[$_channel.'all_lines_sender'][] = $line_sender->get_nick();
  }
}

$_SESSION['template']->get_template();
?>