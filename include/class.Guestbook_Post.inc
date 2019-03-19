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

//has to be moved to config in the future
define('TIME_FORMAT', 'Y-m-d h:i:s');

/**
* Get default values
*/
require_once(POC_BASE.'/config.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Logger.inc');

/**
 * Class Guestbook_Post describes a guestbook post written by chatters
 *
 * @author Michael Oertel <michael@ortelius.de>
 * @access  public
 * @version $Id: class.Guestbook_Post.inc,v 1.1.2.3 2004/02/24 17:05:17 letreo Exp $
 */
class POC_Guestbook_Post {

  /**
  * chatter object represents a person taking part in a chat session
  *
  * @var object
  */
  var $sender = null;

  /**
  * Time of post
  *
  * @var integer
  */
  var $time = 0;

  /**
  * Content of post
  *
  * @var string
  */
  var $said = '';

  /**
   * Constructor for class Guestbook
   *
   * @param object $chatter chatter object represents a person taking part in a chat session
   */
  function POC_Guestbook_Post( $sender )
  {
    if( !is_object($sender) ) die('Object expected');
    
    $this->sender    = $sender;
  }
  
  function set_time( $time = null )
  {
    if( !is_null($time) && !is_integer($time) ) die('Integer expected');
    $this->time =( is_null($time) )? time():$time;
  }
  
  function get_time()
  {
    return date(TIME_FORMAT,$this->time);
  }
  
  function get_db_time()
  {
    return $this->time;
  }

  function get_sender()
  {
    return $this->sender;
  }
  
  function set_said( $said )
  {
    if( !is_string($said) ) return false;
    $this->said = $said;
  }
  
  function get_said()
  {
    return $this->said;
  }
  function get_content()
  {
    return $this->get_said();
  }
}
?>