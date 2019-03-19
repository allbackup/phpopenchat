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
* Implements language negotiation
*
* @author  Carlos Falo Hervás <carles@bisinteractive.net> {@link http://www.bisinteractive.net/}
* @access  public
* @version $Id: class.Language.inc,v 1.3.2.4 2004/02/29 19:57:11 letreo Exp $
*/
class POC_Language {
  
  /**
  * Counter for how many languages are supported
  *
  * @var    int
  * @access public
  * @see    lang_init()
  */
  var $langs = 0;
  
  /**
  * Language List [lang,q] pairs
  *
  * @var    array
  * @access public
  * @see    lang_init()
  */
  var $lang_list;
  
  /**
  * Original http header field HTTP_ACCEPT_LANGUAGES
  *
  * @var    string
  * @access private
  * @see    lang_detect()
  */
  var $accept_lang;
  
  /**
  * Constructor.
  *
  * Sets values for initial workout
  *
  * @access public
  */
  function POC_Language()
  {
    $this->accept_lang = (isset($_SERVER['HTTP_ACCEPT_LANGUAGE']))?$_SERVER['HTTP_ACCEPT_LANGUAGE']:'';
    $this->lang_init();
  }
  
  /**
  * Compares given locale PREFIX with PRIMARY LANG PREFIX
  *
  * @access public
  * @return int if given locale PREFIX matches PRIMARY LANG PREFIX
  */
  function is_primarylang($locale)
  {
    $this->reset_list();
    $slist = explode('-',$locale);
    $lc = $slist[0];
    $slist = explode('-',key($this->lang_list));
    $tlc = $slist[0];
    
    if ($lc==$tlc)
    {
      return 1;
    }
    else 
    {
      return 0;
    }
   }
  
  /**
  * Compares given locale PREFIX with PRIMARY LANG PREFIX
  *
  * @access public
  * @return int if given locale PREFIX matches PRIMARY LANG PREFIX
  */
  function get_primarylang()
  {
    // Return full locale string for primary language
    $this->reset_list();
    
    return key($this->lang_list);
  }
  
  /**
  * Returns the PREFIX string for the client's primary language selection
  * 
  * @access public
  * @return int PREFIX string for primary language
  */
  function get_primaryprefix()
  {
    $this->reset_list();
    $slist = explode('-',key($this->lang_list));
    
    return $slist[0];
  }
  
  /**
  * Retunrs QUALITY for PREFIX in given $loc (QUALITY = q*100 -> percent)
  * 
  * @access public
  * @return int for the PREFIX in given locale
  */
  function find_lang($loc)
  {
    $found = 0;
    $this->reset_list();
    $slist = explode('-',$locale);
    $lc = $slist[0];
    while ($curr = each($this->lang_list))
    {
      $slist = explode('-',$curr[0]);
      $tlc = $slist[0];
      if ($tlc==$lc)
        return $curr[1];
    }
    
    return 0;
  }
  
  /**
  * Fills sublist with an ordered list of accepted languages from given array
  * based on each locale PREFIX... ordering is on Q DESC so first element in
  * the array is best match from the given list.
  *
  * @access public
  * @return int
  */
  function get_list($arr,&$sublist)
  {
    $sublist = array();
    $this->reset_list();
    while($curr = each($this->lang_list))
    {
      $slist = explode('-',$curr[0]);
      //letreo, 07/13/2002
      //bugfix: without a trim, there is a leading space in $loc
      //from this it follows that no language within $arr will be found
      $loc = trim($slist[0]);
      if (in_array($loc,$arr))
        $sublist += array($loc => $curr[1]);
    }
    
    if (count($sublist))
    {
      // This will order based on Q DESC
      arsort($sublist);
      return true;
    } else {
      return false;
    }
  }
  
  /**
  * @access public
  */
  function print_list()
  {
    $this->reset_list();
    while($curr=each($this->lang_list))
    {
      echo $curr[0] . ': ' . $curr[1] .'<br>';
    }
  }
  
  /**
  * Initialize language list
  *
  * @access private
  * @return array
  */
  function lang_init()
  {
    $this->lang_list = Array();
    $list = explode(',',$this->accept_lang);
    for ($i=0;$i<count($list);$i++)
    {
      $pos = strchr($list[$i],';');
      if ($pos === false)
      {
        // No Q it is only a locale...
        $this->lang_list += Array($list[$i] => 100);
        $this->langs++;
      } else {
        // Has a Q rating        
        $q = explode(';',$list[$i]);
        $loc = $q[0];
        $q = explode('=',$q[1]);
        $this->lang_list += Array($loc => ($q[1]*100));
        $this->langs++;
      }
    }
    
    return ($this->langs);
  }
  
  /**
  * Reset language list
  *
  * @access private
  */
  function reset_list()
  {
    reset($this->lang_list);
  }
}
?>