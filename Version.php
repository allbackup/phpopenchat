<?php //$Id: Version.php,v 1.1.2.9 2004/08/26 12:17:59 letreo Exp $

if( function_exists('pnUserGetVar') ) {
  $modversion['name'] = 'PHPOpenChat';
  $modversion['version'] = '3.0.1';
  $modversion['description'] = 'PHPOpenChat a PHP based Chatsoftware';
  $modversion['credits'] = '';
  $modversion['help'] = 'INSTALL';
  $modversion['changelog'] = '';
  $modversion['license'] = 'LICENSE';
  $modversion['official'] = 1;
  $modversion['author'] = 'Michael Oertel - The PHPOpenChat Project';
  $modversion['contact'] = 'http://phpopenchat.org/';
  $modversion['admin'] = 0;
  $modversion['securityschema'] = array('PHPOpenChat::' => '::');
}
define('POC_VERSION', '3.0.1 ($Date: 2004/08/26 12:17:59 $)');
?>