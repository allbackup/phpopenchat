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

//Get default values
require_once(POC_BASE.'/config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');

/**
* Installs PHPOpenChat (POC)
*
* @author  Michael Oertel <michael@ortelius.de>
* @access  public
* @version $Id: class.Installer.inc,v 1.1.2.11 2004/08/26 13:56:05 letreo Exp $
*/
class POC_Installer {

  /**
  * @var    string
  * @access public
  * @see    Installer()
  */
  var $installPath = '';
  var $installWebPath = '';
  
  /**
  * @var    integer
  * @access public
  */
  var $current_step;
  
  /**
  * @var    array
  * @access public
  * @see    breadcrumb()
  */
  var $steps       = array(
                        1 => 'Check write permissions',
                        2 => 'Database account settings',
                        3 => 'Database import',
                        4 => 'Goto login page'/*,
                        5 => 'Permission setup',
                        6 => '',
                        7 => '',
                        8 => '',
                        9 => '',*/
                     );
  
  
  /**
  * Constructor.
  *
  * Creates a new installer
  *
  * @param  string $path
  * @access public
  * @return void
  */
  function POC_Installer ($path){
    if( is_null($path) || !is_string($path) ) return;
    $this->installPath    = $path;
  }
  
  /**
  * Sets the current step of installation procedure
  *
  * @access public
  * @param integer $step
  * @return void
  */
  function set_current_step( $step = 1 ) {
    if( $step > count($this->steps) || $step=='' ) $step = 1;
    $this->current_step = (integer) $step;
  }
  
  /**
  * Provides the current step of installation procedure
  *
  * @access public
  * @return integer
  */
  function get_current_step() {
    return $this->current_step;
  }
  
  /**
  * Provides current document root of webserver
  *
  * @access public
  * @return string
  */
  function get_install_path(){
    return $this->installPath;
  }
  
  /**
  * Provides a breadcrumb navigation
  *
  * @access public
  * @return string
  */
  function breadcrumb(){
    $out = '<table id="breadcrumbs"><tr><td><img src="include/templates/openchat/images/icons/steps.gif" /></td>' . NL;
    reset($this->steps);
    do{
      if( $this->current_step == key($this->steps) ){
        $out .= '<td><img title="current: '.current($this->steps).'" alt="current: '.current($this->steps).'" src="include/templates/openchat/images/icons/step_'.key($this->steps).'_current.jpg" /></td>' . NL;
      }elseif( $this->current_step < key($this->steps) ){
        $out .= '<td><img title="uncompleted: '.current($this->steps).'" alt="uncompleted: '.current($this->steps).'" src="include/templates/openchat/images/icons/step_'.key($this->steps).'_uncompleted.jpg" /></td>' . NL;
      }else{
        $out .= '<td><img title="completed: '.current($this->steps).'" alt="completed: '.current($this->steps).'" src="include/templates/openchat/images/icons/step_'.key($this->steps).'_completed.jpg" /></td>' . NL;
      }
    }while( next($this->steps) );
    $out .= '<td><img src="include/templates/openchat/images/icons/steps_end.gif" /></td></tr></table><hr style="border: 1px dashed green;" />';
    
    return $out;
  }
  
  
  /**
  * Provides the next button to goto a step forward
  * within the install procedure
  *
  * @access public
  * @return string
  */
  function next_button(){
    $out = '
      <a title="Next step" href="'.$_SERVER['SCRIPT_NAME'].'?step='.($this->current_step+1).'"><img src="include/templates/openchat/images/icons/next.gif" alt="Next step" style="border:0"/></a>
    ';
    
    return $out;
  }
  
  
  
  function _check_path( $path, &$out, $error_key = '' ){
    $errors = array();
    $errors['USER ICON UPLOAD DIR'] = 'Do a \'chmod 777\' for USER ICON UPLOAD DIR to give the webserver write access.';

    if( substr($path, -1) == DELI ){
      $test_file = 'tmp~';
      $out_path  = substr($path, 0, -1);
    }else{
      $test_file = '';
      $out_path  = $path;
    }
    $_tmp = null;
    if(POC_OS=='win') echo '<br />';
    if( $_tmp = @fopen($path.$test_file, 'a+')){
      //okay, we have write permissions and now we have to delete our test file
      if(POC_OS=='unix')    system('rm -rf '.$path.$test_file);
      elseif(POC_OS=='win') system('del '.$path.$test_file);
      $out .= $out_path . ' <img title="okay" alt="okay" src="include/templates/openchat/images/icons/okay.gif" /><br />'.NL;
      return $out_path;
    }else{
      $out .= $out_path . ' <img title="error" alt="error" src="include/templates/openchat/images/icons/error.gif" /><br />'.NL;
      if(isset($errors[$error_key]) && $errors[$error_key] != ''){
        print '
          <div style="background-color: #f00;border: 1px solid #000;font-weight: bold;padding-left:5px">
            '.$errors[$error_key].' 
          </div>
        ';
      }
      return false;
    }
  }
   
  
  /**
  * Checks write permissions for various directories and 
  * for various files
  *
  * @access public
  * @return string
  */
  function check_write_permissions(){
   
    //for the corresponding error messages see function _check_path() above
    $check_on = array(
      'CONFIG FILE' => $this->installPath . DELI . 'config.inc.php',
      'USER ICON UPLOAD DIR' => $this->installPath . DELI . 'include' . DELI . 'templates' . DELI . 'openchat' . DELI . 'images' . DELI . 'icons' . DELI . 'chatter' . DELI,
      'TMPDIR'      => array(
                         $this->installPath . DELI . 'tmp' . DELI,
                         ini_get('session.save_path') . DELI,
                         $_ENV['WINDIR'] . '\\TEMP' . DELI,
                         $_ENV['windir'] . '\\TEMP' . DELI,
                         $_ENV['TEMP'] . DELI,
                         $_ENV['TMP'] . DELI,
                         DELI . 'tmp' . DELI,
                         $_SERVER['DOCUMENT_ROOT'] . DELI
                       )
    );
    $out = '';
    reset($check_on);
    $error_count = 0;
    do{
      $out .= '<br />checking write permissions for:&nbsp;<strong>' . key($check_on) . '</strong><br /><p style="margin:0;padding:0;padding-left:30px">';
      $path_found  = false;
      if( is_array(current($check_on)) ) {
        $pathes = current($check_on);
        foreach ($pathes as $path){
          if( $checked_path = $this->_check_path($path,$out)){
            $path_found = true;
            //remove old session data
            if(POC_OS=='unix') system('rm -rf '.$path.'/sess_*');
            elseif(POC_OS=='win') system('del '.$path.'\sess_*');
            break;
          }else{
            $path_found = false;
          }
        }
        if( !$path_found ) $error_count++;
      }else{
        $checked_path = $this->_check_path(current($check_on).$test_file, $out, key($check_on));
        if(! $checked_path ) $error_count++;
      }
      
      if( $checked_path ){
        $this->set_conf_property(key($check_on), $checked_path);
      }
      $out .= '</p><br />'.NL;
            
    }while( next($check_on) );
    
    if( $error_count == 0 ){
      $out .= $this->next_button();
    }
    
    return $out;
  }

  /**
  * Set-up properties within POCs configuration file
  * 
  * @access public
  * @return string
  */
  function set_conf_property( $property, $value){
    if(!defined(strtoupper($property))) return;
    if(constant(strtoupper($property))==$value) return;
    if(!function_exists(_config_not_writeable)){
      function _config_not_writeable(){
        print'
        <div style="background-color: #f00;border: 1px solid #000;font-weight: bold;padding-left:5px">
          Your webserver has no write permissions for configuration file (config.inc.php)!<br />
          Do a \'chmod 666\' for the file described below (CONFIG FILE).<br />
          After the installation procedure please reset config file to the old permissions. Mostly this means a \'chmod 644\'.
          <p style="font-size:14px;font-weight:bold">
            <a href="install.php">Retry</a>
          </p>
        </div>
        ';
      }
    }
    
    $config     = $this->installPath.DELI.'config.inc.php';
    $new_config = '';
    if(! ($fp = @fopen($config, 'r')) ) return false;

    //ignore_user_abort(true);
    while( $line = fgets($fp, 65536) ) {
      if( preg_match('/^( *)define\(\''.strtoupper($property).'.*;(.*)$/', $line, $matches) ){
        //overwrite the current line
        if(is_string($value)){
          $new_config .= $matches[1]."define('".strtoupper($property)."', '".$value."');".$matches[2]."\n";
        }else{
          $new_config .= $matches[1]."define('".strtoupper($property)."', ".$value.");". $matches[2]."\n";
        }
      }else{
        //leave the current line untouched
        $new_config .= $line;
      }
    }
    fclose($fp);
    set_error_handler('_config_not_writeable');
    $fp = fopen($config, 'w+');
    restore_error_handler();
    if($fp){
      @fwrite($fp, $new_config);
      @fclose($fp);
    }
    return($fp)? true:false;
  }

  function _no_connect_to_DB($errno, $errmsg, $filename, $linenum, $vars){
      print'
      <div style="background-color: #f00;border: 1px solid #000;font-weight: bold;padding-left:5px;margin-bottom:5px">
        ['.$errno.'] '.$errmsg.'
      </div>
      ';    
  }
  function _no_tablespace ($tabl){
      print'
      <div style="background-color: #f00;border: 1px solid #000;font-weight: bold;padding-left:5px;margin-bottom:5px">
        A database (tablespace) with name "'.$tabl.'" could not be found!
      </div>
      ';
  }
  function check_connection($db, $host, $user, $pass, $tabl = false){
    if($tabl){
      return ($db->Connect( $host, $user, $pass, $tabl ) == false)? false:true;
    }else{
      return ($db->Connect( $host, $user, $pass ) == false)? false:true;
    }
  }

  function database_setup(){
    
    if( isset($_POST['form_data']) ){
      $host = (string) $_POST['DATABASE_HOST'];
      $user = (string) $_POST['DATABASE_USER'];
      $pass = (string) $_POST['DATABASE_PASSWORD'];
      $tabl = (string) $_POST['DATABASE_TABLESPACE'];
      $prefix = (string) $_POST['DATABASE_TABLE_PREFIX'];

      $this->set_conf_property('DATABASE_HOST', $host);
      $this->set_conf_property('DATABASE_USER', $user);
      $this->set_conf_property('DATABASE_PASSWORD', $pass);
      $this->set_conf_property('DATABASE_TABLESPACE', $tabl);
      $this->set_conf_property('DATABASE_TABLE_PREFIX', $prefix);
    }else{
      $host = DATABASE_HOST;
      $user = DATABASE_USER;
      $pass = DATABASE_PASSWORD;
      $tabl = DATABASE_TABLESPACE;
      $prefix = DATABASE_TABLE_PREFIX;
    }

    $out = '
    checking database access at:&nbsp;<strong>' . $host . '</strong>
    ';
    
    //try to connect to DB
    $db         = &NewADOConnection( DATABASE_DRIVER );
    set_error_handler(array(&$this, '_no_connect_to_DB'));
    $connection = $this->check_connection($db, $host, $user, $pass);
    restore_error_handler();
    $disabled   = '';
    $databases  = '<option selected="selected" />';
    if($connection){
      $disabled = 'readonly="readonly"';
      $dict     = NewDataDictionary($db);
      $db->Connect( $host, $user, $pass );
      $meta_databases = $db->MetaDatabases();
      foreach ($meta_databases as $database){
        $databases.= '<option value="'.$database.'">'.$database.'</option>'.NL;
      }
      while(true){
        if(!$this->check_connection($db, $host, $user, $pass, $tabl) ){
          //no database (tablespace) found
          if( isset($_REQUEST['create_db']) ){
            //so, we try to create one
            $sql = array();
            $sql = $dict->CreateDatabase($tabl);
            $db->Connect( $host, $user, $pass );
            $db->Execute($sql[0]);
            $db->Close();
            unset($_REQUEST['create_db']);
            continue;
          }
          $connection = false;
          _no_tablespace($tabl);
          unset($db);
          break;
        }
        break;
      }
    }

    if( !$connection || !isset($_POST['form_data']) ){
      $out .=(!$connection )?
       '<img title="error" alt="error" src="include/templates/openchat/images/icons/error.gif" />':
       '<img title="okay" alt="okay" src="include/templates/openchat/images/icons/okay.gif" />';
      $out .= '      
      <br />
      <p style="margin:0;padding:0;padding-left:30px">
        <form action="'.$_SERVER['SCRIPT_NAME'].'" method="post">
          <table>
            <tr>
              <td><input name="step" type="hidden" value="'.$this->current_step.'" />'. NL .'
                DATABASE_HOST: </td><td><input name="DATABASE_HOST" type="text" value="'.$host.'" '.$disabled.' />'. NL .'
              <td>
            </tr>
            <tr>
              <td>
                DATABASE_USER: </td><td><input name="DATABASE_USER" type="text" value="'.$user.'" '.$disabled.' />'. NL .'
              </td>
            </tr>
            <tr>
              <td>
                DATABASE_PASSWORD: </td><td><input name="DATABASE_PASSWORD" type="text" value="'.$pass.'" '.$disabled.' />'. NL .'
              </td>
            </tr>
            <tr>
              <td>
                DATABASE_TABLE_PREFIX: </td><td><input name="DATABASE_TABLE_PREFIX" type="text" value="'.$prefix.'" />'. NL .'
              </td>
            </tr>
            <tr>
              <td style="vertical-align: top">
                DATABASE_TABLESPACE: </td><td><input onfocus="document.forms[0].elements[\'create_db\'].disabled=false" name="DATABASE_TABLESPACE" type="text" value="'.$tabl.'" />&nbsp;'. NL .'

                <input id="new_db" name="create_db" type="checkbox" /><label style="cursor:hand" for="new_db"> create this database (tablespace)!</label><br />
                Choose one of the existent databases (tablespaces):<br />';
                if( $connection ){
                  $out .= '<select onchange="document.forms[0].elements[\'DATABASE_TABLESPACE\'].value = this.options[this.selectedIndex].value;selectDB(this);this.options[0].selected = true;" name="databases">
                    '.$databases.'
                  </select>';
                }
                $out .= '</td>
            </tr>
            <tr>
                <td>&nbsp;</td><td><input name="form_data" type="submit" value="submit" /></td>
            </tr>
          </table>        
        </form>
      </p><br />
      ';
    }else{
      $out .= ' <img title="okay" alt="okay" src="include/templates/openchat/images/icons/okay.gif" />';
      $out .= '<br /><p style="margin:0;padding:0;padding-left:30px">';
      $out .= 'DATABASE_HOST: '.$host.'<br />'.NL;
      $out .= 'DATABASE_USER: '.$user.'<br />'.NL;
      $out .= 'DATABASE_PASSWORD: '.$pass.'<br />'.NL;
      $out .= 'DATABASE_TABLE_PREFIX: '.$prefix.'<br />'.NL;
      $out .= 'DATABASE_TABLESPACE: '.$tabl.'<br />'.NL;
      $out .= '</p><br />'.NL;
      $out .= $this->next_button();
    }
    
    return $out;
  }
  
  
  function init_database(){
    $comment[0] = "#";// mysql standard comment
    $comment[1] = "-- ";
    
    $file = $this->installPath . DELI . 'db.schema.' . DATABASE_DRIVER;
    if(! ($fp = @fopen($file, 'r')) ) {
      $file = $this->installPath . DELI . 'db.schema';//standard schema for mysql
      $fp = fopen($file, 'r');
    }
    if(isset($_REQUEST['init_DB'])){
      $db = &NewADOConnection( DATABASE_DRIVER );
      $db->Connect( DATABASE_HOST, DATABASE_USER, DATABASE_PASSWORD, DATABASE_TABLESPACE );
    }
    $out = '<p style="font-size:9px;margin:0;padding:0;margin-bottom:5px">';
    while( $line = fgets($fp, 65536) ) {
      //print 'debug';
      $line = ereg_replace("\r\n$", "\n", $line);
      $line = ereg_replace("\r$",   "\n", $line);
      $line = eregi_replace("DROP TABLE IF EXISTS poc_", "DROP TABLE IF EXISTS ".DATABASE_TABLE_PREFIX, $line);
      $line = eregi_replace("CREATE TABLE poc_", "CREATE TABLE ".DATABASE_TABLE_PREFIX, $line);
      $line = eregi_replace("ALTER TABLE poc_", "ALTER TABLE ".DATABASE_TABLE_PREFIX, $line);
      $line = eregi_replace("INSERT INTO poc_", "INSERT INTO ".DATABASE_TABLE_PREFIX, $line);

      $quotes = substr_count ($line, "'") - substr_count ($line, "\\'");
      if( $quotes % 2 != 0 ) {
        $within_quotes = !$within_quotes;
      }

      // Skip comments and blank lines only if not within quotes
      if( !$within_quotes ) { 
        $skipline = false;
        reset( $comment );
        foreach ($comment as $comment_value) { 
          if (!$within_quotes && (trim($line) == "" 
          || strpos ($line, $comment_value) === 0)) { 
            $skipline = true;
            break;
          }
        }
        if( $skipline ) { 
          continue;
        }
      }
      
      $query .= $line;
      
      // Execute query if end of query detected (; as last character) AND NOT within quotes
      if (ereg(";$",trim($line)) && !$within_quotes) { 
        $sql[] = trim($query);
        if(isset($_REQUEST['init_DB'])){
          $db->Execute( trim($query) );
        }else{
          $out .= trim($query).'</p>';
        }
        $out .='<p style="font-size:9px;margin:0;padding:0;margin-bottom:5px">';
        $query='';
      }
    }
    if(!isset($_REQUEST['init_DB'])){
      $out .= '
      <form action="'.$_SERVER['SCRIPT_NAME'].'" method="post">
        <input name="step" type="hidden" value="'. $this->current_step .'" />
        <input name="init_DB" type="submit" value="initialize database!" />
      </form>
      ';
    }
    
    if(isset($_REQUEST['init_DB']) && $db->Execute('select * from '.DATABASE_TABLE_PREFIX.'user_data')){
      //data successfully imported
      $out  = 'PHPOpenChat database schema import. <img title="okay" alt="okay" src="include/templates/openchat/images/icons/okay.gif" /><br />&nbsp;<br />&nbsp;<br />&nbsp;<br />&nbsp;<br />';
      $out .= $this->next_button();
    }
    
    return $out;
  }
  
  function install_complete(){
     $out  = '<div style="background-color: #0c0;border: 1px solid #000;font-weight: bold;padding-left:5px;margin-bottom:5px">
          Congratulations! The installation of PHPOpenChat is accomplished. <a href="index.php">Now login to your new high performance chat server</a>. 
              </div>
           ';
     
     return $out;
  }
}
?>