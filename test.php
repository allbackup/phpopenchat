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
  $Source: /cvsroot/phpopenchat/chat3/test.php,v $
  $Revision: 1.26.2.11 $
*/
//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Recipient.inc');//extents Chatter
require_once(POC_INCLUDE_PATH.'/class.Line.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');
require_once(POC_INCLUDE_PATH.'/class.Channel_Buffer_'.CHANNEL_BUFFER_TYPE.'.inc');
require_once(POC_INCLUDE_PATH.'/class.HttpNegotiation.inc');

$myTemplate = new POC_Template();

//create a database object
$db = &NewADOConnection( DATABASE_DRIVER );
$db_col = (@$db->Connect( DATABASE_HOST, DATABASE_USER, DATABASE_PASSWORD, DATABASE_TABLESPACE ))? 'green':'red';
$schema_col = (@$db->Execute( 'SELECT THEME FROM '.DATABASE_TABLE_PREFIX.'user_data' ) && $db_col!='red')? 'green':'red';
$separator = (POC_OS=='win')? '\\':'/'; 
$tmp_col = (@fopen( TMPDIR.$separator.'poc_testfile', 'w' ))? 'green':'red';
$tmpl_col = (file_exists($myTemplate->get_template('index',true)) )? 'green':'red';
$chatter_icon_upload_dir = $myTemplate->get_tmpl_sys_path().$separator.'images'.$separator.'icons'.$separator.'chatter';
$chatter_icon_col = (@fopen( $chatter_icon_upload_dir.$separator.'poc_testfile', 'w' ))? 'green':'red';
if(isset($_GET['phpinfo'])&& md5($_GET['phpinfo'])=='302fac1d6d73cf4fdf2c9919195df864'){echo phpinfo();exit;}
echo '
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
  <head>
    <title></title>
  </head>
  <body>

';
if(isset($_GET['error'])) echo '<span style="color:#f00">'.$_GET['error'].'</span>';
echo'
    <table>
      <thead>
        <tr>
          <th>Check</th>
          <th>Status</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td>POC-Database: </td>
          <td bgcolor="'.$db_col.'">&nbsp;&nbsp;&nbsp;</td>
          <td></td>
        </tr>
        <tr>
          <td>POC-Tables: </td>
          <td bgcolor="'.$schema_col.'">&nbsp;&nbsp;&nbsp;</td>
          <td>POC database schema checked</td>
        </tr>
        <tr>
          <td>POC-Templates: </td>
          <td bgcolor="'.$tmpl_col.'">&nbsp;&nbsp;&nbsp;</td>
          <td>tried to open templates in \'<em>'.$myTemplate->get_theme_path().'</em>\'</td>
        </tr>
        <tr>
          <td>Webserver write access in <em>'.TMPDIR.'</em>: </td>
          <td bgcolor="'.$tmp_col.'">&nbsp;&nbsp;&nbsp;</td>
          <td>The temporary directory, where the webserver MUST have write access, is defined as \'TMPDIR\' in config.inc.php<br />If you have setup the rights for \'TMPDIR\' to full read and write access (Unix \'chmod 777\') but the test shows even so red, your ISP has switched on \'safe_mode\' or has defined \'open_basedir\' within the PHP configuration file (php.ini). open_basedir, if set, limits all file operations to the defined directory.</td>
        </tr>
        <tr>
          <td>Webserver write access in <em>'.$chatter_icon_upload_dir.'</em>: </td>
          <td bgcolor="'.$chatter_icon_col.'">&nbsp;&nbsp;&nbsp;</td>
          <td>Each chatter has the possibility to upload a private icon, which he can use within the chat. So, the webserver needs write access to this directory to store private images.</td>
        </tr>
      </tbody>
    </table>
    <p>
    If you see always green, all is fine, <a href="index.php">login</a>.<br>If you see red, please:';
if( $db_col == 'red' )
  echo '
    <ul>
      <li>Edit the file config.inc.php and setup your database connection. Change:
        <ul>
          <li>DATABASE_HOST</li>
          <li>DATABASE_USER</li>
          <li>DATABASE_PASSWORD</li>
          <li>DATABASE_TABLESPACE</li>
        </ul>
        to your values. (Hint: DATABASE_TABLESPACE contains your SQL-tables and hopefully the POC-SQL-tables.)
      </li>
    </ul>';
if( $schema_col == 'red' )
  echo '
    <ul>
      <li>
       Import the POC database tables<br />
       Open a command-shell and do a:<ol>
       <li># mysqladmin create poc</li>
       <li># mysql poc &lt; /path/to/poc/db.schema</li>
       </ol>
       First point only, if you want to have the POC-SQL-tables in a separat tablespace. In the most cases, user have already such a tablespace and there are no problems to import POC-SQL-tables into this tablespace.
      </li>
    </ul>';

if( $tmp_col == 'red' )
  echo '<p>If you have enabled safe_mode, or open_basedir further restrictions may apply.<br />
  In case you have no write access to <em>'.TMPDIR.'</em>
  <ul>
    <li>Create a director \'tmp\' for example in '.realpath('../..').'</li>
    <li>Give webserver write access to this directory. (chmod 666)</li>
  </ul></p>
  ';
 
echo'
    <ul>
      <li>
      Please read the <a href="INSTALL">INSTALL</a> instructions!
      </li>
    </ul>
    </p>
  </body>
</html>';
exit;

// Unit tests on classes
// POC_Line::test();
// POC_Channel_Buffer::test();
// POC_Chatter::test();
?>
