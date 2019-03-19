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
require_once(POC_INCLUDE_PATH.'/class.Logger.inc');
require_once(POC_INCLUDE_PATH.'/class.HttpNegotiation.inc');

//Get theme depending properties if exists
/*
if(isset($_SESSION['chatter'])
   && file_exists(POC_INCLUDE_PATH.'/templates/'.$_SESSION['chatter']->get_theme().'/theme_config.inc.php')){
  include_once(POC_INCLUDE_PATH.'/templates/'.$_SESSION['chatter']->get_theme().'/theme_config.inc.php');
}elseif(isset($_COOKIE['poc_theme'])
   && file_exists(POC_INCLUDE_PATH.'/templates/'.$_COOKIE['poc_theme'].'/theme_config.inc.php')){
  include_once(POC_INCLUDE_PATH.'/templates/'.$_COOKIE['poc_theme'].'/theme_config.inc.php');
}else{
  include_once(POC_INCLUDE_PATH.'/templates/'.DEFAULT_THEME.'/theme_config.inc.php');
}
*/

/**
* Handles the complete Templatesystem
*
* @author  Sascha Ragtschaa <sascha@ragtschaa.com>
* @author  Michael Oertel <michael@ortelius.de>
* @access  public
* @version $Id: class Template.inc,v 1.0 2002/09/25
*/
class POC_Template
{

  /**
  * Contains the name of current theme
  * 
  * @var string
  * @access private
  */
  var $theme         = '';
  var $old_theme     = null;
  
  var $include_path  = '';
  var $web_root      = null;
  var $poc_web_root  = null;
  var $tmpl_web_path = null;
  var $tmpl_sys_path = null;
  var $template      = '';
  var $cache_it      = false;
  var $max_age       = 0;
  var $content_type  = 'text/html';
  var $valid_xhtml   = false;
  var $requires_relogin = false;
  var $extra_smileys = array();
  
  /**
  * Constructor
  *
  * @access public
  * @return void
  */
  function POC_Template( $theme = null )
  {
    if ( !defined('DEFAULT_THEME') )
      die('No DEFAULT_THEME specified in config.inc!');
    else
    {
      $this->theme = ( !is_null($theme) )? $this->theme = $theme : $this->theme = DEFAULT_THEME;
      $this->include_path = POC_INCLUDE_PATH;
      $this->_build_pathes();
      if( isset($_COOKIE['poc_theme']) ){
        $this->set_theme($_COOKIE['poc_theme']);
      }
      $this->_set_theme_properties();
      $this->set_content_type();
    }
  }
  
  function _set_theme_properties()
  {
    if( file_exists($this->get_tmpl_sys_path().'/theme_config.inc.php') ){
      include($this->get_tmpl_sys_path().'/theme_config.inc.php');
      $this->valid_xhtml = (defined('VALID_XHTML'))? VALID_XHTML:false;
      $this->requires_relogin = (defined('REQUIRES_RELOGIN'))? REQUIRES_RELOGIN:false;
      $this->extra_smileys = (isset($extra_smileys) && is_array($extra_smileys) && count($extra_smileys)>0)?
                             $extra_smileys:array();
    }
  }
  
  function requires_relogin()
  {
    return $this->requires_relogin;
  }
  
  function has_extra_smileys()
  {
    return ( count($this->extra_smileys) > 0 );
  }
  
  /**
  * Sets the correct mime type for the current theme,
  * this depends on content-type negotioation
  *
  * @access public
  * @return void
  */
  function set_content_type()
  {
    $serverVariants = 'application/xhtml+xml,text/html;q=0.9';
    $defaultVariant = 'text/html';
    if($this->valid_xhtml && isset($_SESSION['httpneg'])){
      $preferredContentType = $_SESSION['httpneg']->getPreferredContentType($serverVariants, $defaultVariant);
      $this->content_type   = $preferredContentType;
      unset($serverVariants);
      unset($preferredContentType);
    }else{
      $this->content_type   = $defaultVariant;
    }
    unset($defaultVariant);
  }

  function is_shockwave()
  {
    $serverVariants = 'application/x-shockwave-flash,text/html;q=0.9';
    $defaultVariant = 'text/html';
    $preferredContentType = $_SESSION['httpneg']->getPreferredContentType($serverVariants, $defaultVariant);

    return(preg_match('/shockwave\-flash/',$preferredContentType));
  }
  
  /**
  * Provides the content-type
  *
  * @access public
  * @return string
  */
  function get_content_type()
  {
    return $this->content_type;
  }

  /**
  * Provides the extra smileys of the current theme
  *
  * @access public
  * @return array
  */
  function get_extra_smileys()
  {
    return $this->extra_smileys;
  }
  
  function _check_pathes($file)
  {
    return file_exists($file);
  }
  
  function _build_pathes( $old_theme = null )
  {
    if( is_null($old_theme) ) {
      
      //set absolut path to templates
      //$this->web_root = dirname($_SERVER['SCRIPT_NAME']);
      $this->web_root   = preg_replace('#/[^/]*$#', '', $_SERVER['REQUEST_URI']);
      //echo'debug: '.$this->web_root;
      //                   /var/www/html/chat3 . /include/templates . / . openchat
      $this->tmpl_sys_path = realpath('.') . BASETEMPLATE_PATH .'/'. $this->theme;
      $this->tmpl_web_path = BASETEMPLATE_PATH .'/'. $this->theme;
      if( $this->web_root != '/' && $this->web_root != '\\' ) {
        $this->tmpl_web_path = $this->web_root . $this->tmpl_web_path;
      }
      //unset($pathinfo);
      //check path
      $value      = '';
      $tmpl_found = false;
      if( !$this->_check_pathes($this->tmpl_sys_path.'/index.tpl') ) {
        //okay, this isn't a standallone installation
        $tried = array();
        $ties  = array(
                  'postnuke'=>'/modules/' . PN_MODULE_NAME,
                  '' => ''
                 );
        foreach ($ties as $value) {
          $this->tmpl_web_path = $this->web_root .$value. BASETEMPLATE_PATH  .'/'. $this->theme;
          $this->tmpl_sys_path = realpath('.')   .$value. BASETEMPLATE_PATH  .'/'. $this->theme;
          $tried[] = $this->tmpl_sys_path;
          if($this->_check_pathes($this->tmpl_sys_path.'/index.tpl')){
            $tmpl_found = true;
            break;
          }
        }
        if( !$tmpl_found ){
          print_r($tried);
          die('Couln\'t find any template, giving up.');
        }

        //BASETEMPLATE_PATH','/include/templates $this->theme
        //include/templates/openchat
        $this->poc_web_root = str_replace(BASETEMPLATE_PATH.'/'.$this->theme,'',$this->tmpl_web_path);
        //$this->poc_web_root = $this->tmpl_web_path;
      }
    } else {
      $this->tmpl_web_path = preg_replace('/'.$old_theme.'$/', $this->theme, $this->tmpl_web_path);
      $this->tmpl_sys_path = preg_replace('/'.$old_theme.'$/', $this->theme, $this->tmpl_sys_path);
    }
  }

  /**
  * Calculates a unique key to store data in the db
  *
  * @access private
  * @return string
  */
  function _calculate_cacheId()
  {
    $_request = array();
    $_request = $_REQUEST;//copy request array
    unset($_request[ 'chatter_image' ]);//remove posted image data from request (used in profile)
    $sessionName = session_name();
    unset($_request[ $sessionName ]);//remove session id from request
    unset($sessionName);
    $cacheId = serialize($_request);
    $cacheId .= '_'.$_SERVER['PHP_SELF'].'_'.$_SESSION['chat']->get_language();//append template name and language
    
    return $cacheId;
  }
  
  function get_include_path()
  {
    return $this->include_path;
  }
  
  /**
  * Finds the given template in the POC-install-directory tree
  *
  * @access private
  * @param string
  * @return mixed
  */
  function _find_template($template=null)
  {
    if( is_null($template) ) {
      if(false){
	    //In serveral cases pathinfo produces unexpected results %-) 
        $pathinfo  = array();
        $pathinfo  = pathinfo( $_SERVER['REQUEST_URI'] );
        $template  = '/'. str_replace( '.'.$pathinfo['extension'], '', $pathinfo['basename'] );
        unset($pathinfo);
      } else {
        preg_match('#^.*/(.*)\.php[\?|\#]?.*$#', $_SERVER['REQUEST_URI'], $matches);
        $template = $matches[1];
        unset($matches);
      }
      $template .= '.'.TEMPLATE_EXTENSION;
    } else {
      $template  = '/'.$template.'.'.TEMPLATE_EXTENSION;
    }
	
    //$tmpl_subdirectory = str_replace( $this->web_root, '', dirname($_SERVER['SCRIPT_NAME']));
    $tmpl_subdirectory = str_replace( $this->web_root, '', dirname($_SERVER['REQUEST_URI']));
    //BugFix: http://sourceforge.net/tracker/index.php?func=detail&aid=733343&group_id=14195&atid=114195
    $tmpl_directory    = $this->tmpl_sys_path . '/' . $tmpl_subdirectory;
    $tmpl              = str_replace('//','/',$tmpl_directory.$template);
    return (POC_OS == 'win')? str_replace( '/', DELI, $tmpl):$tmpl;
  }

  /**
  * Puts content into the cache
  *
  * @access private
  * @param string
  * @return boolean
  */
  function _put_into_cache( $content )
  {
    $cacheId = $this->_calculate_cacheId();
    $_SESSION['chat']->connect();
     $success = $_SESSION['chat']->put_template_into_cache( $cacheId, $content, $this->cache_max_age );
    $_SESSION['chat']->disconnect();
    
    return $success;
  }
  
  /**
  * Provides the template with path and outputs html
  *
  * @access public
  */
  function get_template( $template=null, $path_only = false )
  {

    if( ! $this->template = $this->_find_template($template) )
      die('No such template found, giving up.');

    if($path_only) return $this->template;

    global $TEMPLATE_OUT;
    ob_start();
    if( !file_exists($this->template) ) {
      /* in case user changed directory structure and
       * has created the session object already */
      $this->_build_pathes();
      $this->template = $this->_find_template();
    }

    include_once($this->template);
    $content = (TRIM_OUTPUT)? preg_replace('/([\r\n])[\s]+/', "\r\n", ob_get_contents()):ob_get_contents();
    ob_end_clean();
    $content = '<?xml version="1.0" encoding="'.$_SESSION['translator']->out('CHARACTER_ENCODING').'"?>'.NL.$content;
    header('Content-type: '.$this->content_type.'; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));      
    print $content;
    flush();

    if( $this->cache_it )
    {
      if( !$this->_put_into_cache( $content ) )
        $_SESSION['logger']->debug('Could not cache template',__FILE__,__LINE__);

      $this->cache_it = false;
      $this->cache_max_age = 0;
    }
    exit;
  }

  /**
  * Searches for a template in right language, if such template not found 
  * the template in default language will be returned
  *
  * @access public
  */
  function get_language_template( $template = null )
  {
    if( ! $this->template = $this->_find_template($template) )
      die('No such template found, giving up.');

    global $TEMPLATE_OUT;
    ob_start();
    if( file_exists($this->template.'.'.$_SESSION['chat']->get_language()) )
      include_once($this->template.'.'.$_SESSION['chat']->get_language());
    else 
      include_once($this->template.'.'.$_SESSION['chat']->get_default_language());

    $content = (TRIM_OUTPUT)? preg_replace('/([\r\n])[\s]+/', "\r\n", ob_get_contents()):ob_get_contents();
    ob_end_clean();
    $content = '<?xml version="1.0" encoding="'.$_SESSION['translator']->out('CHARACTER_ENCODING').'"?>'.NL.$content;
    
    header('Content-type: '.$this->content_type.'; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));
    print $content;
    exit;
  }
  
  /**
  * Provides the current choosen theme
  *
  * @return string
  */
  function get_theme()
  {
    return $this->theme;
  }

  /**
  * Provides content from cache
  * @param string maximum age for the cached content
  * @return string
  */
  function get_cached_content( $max_age )
  {
    if( !is_object($_SESSION['chat']) || !CACHE_ENGINE ) return false;
    
    $cacheId = $this->_calculate_cacheId();
    $_SESSION['chat']->connect();
     $cached_content = $_SESSION['chat']->get_template_from_cache($cacheId);
    $_SESSION['chat']->disconnect();
    
    if($cached_content == '')
    {
      $this->cache_it = true;
      $this->cache_max_age = intval($max_age);
      return false;
    }

    print $cached_content;
    exit;
  }

  function get_web_root()
  {
    return $this->web_root;
  }
  
  /**
  * Provides the path to the current theme
  *
  * @return string
  */
  function get_tmpl_web_path()
  {
    //path clean up
  //$this->tmpl_web_path = preg_replace('#//#','',$this->tmpl_web_path);
    return $this->tmpl_web_path;
  }
  function get_theme_path() {return $this->get_tmpl_web_path();}

  /**
  * Provides the path to the current theme
  *
  * @return string
  */
  function get_path( $path )
  {
    if($path=='THEME_PATH')
      return $this->get_theme_path();
      
  }
  
  /**
  * Provides the web path to POC
  *
  * @return string
  */
  function get_poc_web_root()
  {
    return 'http://'.$_SERVER['SERVER_NAME'].$this->poc_web_root;
  }
  
  /**
  * Provides the path to the current theme
  *
  * @return string
  */
  function get_tmpl_sys_path()
  {
    return $this->tmpl_sys_path;
  }

  /**
  * Sets the current theme
  *
  * @param string
  */
  function set_theme( $theme )
  {
    $old_theme = $this->theme;
    $this->theme = $theme;
    $this->_build_pathes($old_theme);
    $this->set_content_type();
    unset($old_theme);
    $this->_set_theme_properties();
  }

  /**
  * Provides all installed themes
  *
  * @return array All available themes
  */
  function get_theme_list()
  {
    $handle = opendir($this->include_path . '/templates'); 
    $themes = array();  
    while ( $dir = readdir($handle) )
    {
      if ( !is_file($dir)
      && $dir != '.'
      && $dir != '..'
      && $dir != 'CVS'
      ) {
	     $themes[] = $dir;
      }
    }
    return $themes;
  }
  
  
  /**
  * Provides all installed themes as an option list
  *
  * @return string; html options
  */
  function get_theme_option_list()
  {
    $theme_option_list = '';
	$themes = array();
	$themes = $this->get_theme_list();
	
    foreach ($themes as $dir) {
      $selected =( $dir == $this->get_theme() )? 'selected="selected"':'';
      $theme_option_list .= NL.'<option value="'.$dir.'" '.$selected.'>'.$dir.'</option>';
      //$theme_option_list .= NL.'<option>'.$dir.'</option>';
    }
    return $theme_option_list;
  }
  
  /**
  * Filters the given string and replaces some placeholders
  *
  * @see get_path()
  * @param string
  * @return string
  */
  function filter_placeholder( $string )
  {
    return preg_replace( "/\@{3}([^@]*)\@{3}/e", "\$this->get_path('\\1')", $string );
  }
}
?>