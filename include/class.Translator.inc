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

/**
 * Get default values
 */
require_once(POC_BASE.'/config.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Logger.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

/**
 * Translator 
 *
 * @author  Michael Oertel <michael@ortelius.de>
 * @access  public
 * @version $Id: class.Translator.inc,v 1.12.2.7 2004/08/10 11:02:02 letreo Exp $
 */
class POC_Translator {
  
  /**
  * @var    string
  * @access public
  * @see    out()
  */
  var $language = '';
  
  /**
  * Constructor.
  *
  * Implements a translator object who translates every output
  *
  * @param string Language in format described by ISO 639
  * @access public
  */
  function POC_Translator($language = 'en')
  {
    $this->language = $language;
  }
  
  /**
  * Getter for language to translate into
  *
  * @return string language in format: ISO 639
  */
  function get_language()
  {
    return $this->language;
  }
  
  /**
  * Setter for language to translate into
  *
  * @param string language in format: ISO 639
  * @return boolean
  */
  function set_language( $language )
  {
    if( $language == '' || strlen($language) != 2 ) return false;
    
    $this->language = $language;
    if( isset($_SESSION['chat']) ) $_SESSION['chat']->set_language($language);
    return true;
  }
  
  /**
  * Searches and translates constans marked with '###' in given string
  *
  * @param string
  * @return string 
  */
  function filter_out( $string, $html_entities = false )
  {
    return ($html_entities)? preg_replace( "/\#{3}([^#]*)\#{3}/e", "\$this->out('\\1',true)", $string ):
                             preg_replace( "/\#{3}([^#]*)\#{3}/e", "\$this->out('\\1')", $string );
  }

  function out($string, $html_entities = false)
  {
    require_once(POC_INCLUDE_PATH.'/languages/'.$this->language.'.inc');
    if( !defined($string) && $this->language != 'en' )
    {
      error_reporting();
      //the (at) to prevent errors messages like: "constant already defined" or something like that.
      @require_once(POC_INCLUDE_PATH.'/languages/en.inc');
    }
    if(!defined($string)) 
    {
      return ($html_entities)? htmlentities('???'.$string.'???'):
                               '???'.$string.'???';
    }
    
    return ($html_entities)? htmlentities(constant($string)):
                             constant($string);
  }
}
?>