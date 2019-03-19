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
  $Date: 2004/02/12 13:39:10 $
  $Source: /cvsroot/phpopenchat/chat3/jump.php,v $
  $Revision: 1.6.2.3 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

session_start();

//check if chatter is authorized to get this page
if( !isset($_SESSION['chatter']) )
  die('Login first!');

function content_check($url){

  global $errortext;

  ereg("^http://(.[^/:]*):?([1234567890]*)(.*)",$url,$piece);
  $hostname = $piece[1];
  if(!$piece[2]){
    $port = 80;
  }else{
    $port = $piece[2];
  }
  if(!$piece[3]){
    $pfad = "/";
  }else{
    $pfad = $piece[3];
  }

  $fp=fsockopen($hostname,$port);
  if(!$fp)
  {
    $errortext = $_SESSION['translator']->out('JUMP_ERROR_HOST');
    return false;
  }

  @fputs($fp,"GET $pfad HTTP/1.0\nUser-Agent: PHPOpenChat-Robot (http://phpopenchat.sourceforge.net/)\nHost: $hostname\n\n");
  $header = @fgets($fp,256);
  if(eregi(" 40",$header)){
    $errortext = $header;
    return false;
  }
  $content = '';
  while(!feof($fp)){
    $content .= fgets($fp,1024);
  }
  @fclose($fp);

  if( preg_match('/'.UNACCEPTABLE_CONTENT.'/', $content) ){
    $errortext = $_SESSION['translator']->out('JUMP_ERROR_CONTENT');
    return false;
  }  

  return true;
}
if( !preg_match('/^[http|ftp]+.*/', $_GET['url']) )
  $_GET['url']="http://".$_GET['url'];

if(content_check($_GET['url'])){
  die('
   <html>
   <head>
    <title>Jump</title>
    <meta http-equiv="Refresh" content="0; url='.$_GET['url'].'">
   </head>
    <body>
     <a href="'.$_GET['url'].'">'.$_GET['url'].'</a><br>
    </body>
   </html>
  ');
}
header('Content-type: text/html; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));
$_SESSION['template']->get_template();
?>
