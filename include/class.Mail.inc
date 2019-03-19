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

/**
* Mail implements a mail within the chat
*
* @author  Michael Oertel <michael@ortelius.de>
* @access  public
* @version $Id: class.Mail.inc,v 1.9.2.3 2004/02/24 17:05:17 letreo Exp $
*/
class POC_Mail {

  /**
  * Sender of mail
  *
  * @var object
  */
  var $sender = null;
  
  /**
  * Recipients of mail
  *
  * @var array
  */
  var $recipients = array();
  
  /**
  * Recipient of mail
  *
  * @var string
  */
  var $recipient = '';
  
  /**
  * Body of mail
  *
  * @var string
  */
  var $body = '';
  
  /**
  * Subject of mail
  *
  * @var string
  */
  var $subject = '';
  
  /**
  * Send time of mail
  *
  * @var integer
  */
  var $send_time = 0;
  
  /**
  * Time of last touch by sender
  *
  * @var integer
  */
  var $last_touch_sender = 0;
  
  /**
  * Time of last touch by recipient
  *
  * @var integer
  */
  var $last_touch_recipient = 0;
  
  /**
  * Time of first touch by recipient
  *
  * @var integer
  */
  var $first_touch_recipient = 0;

  /**
  * Status flag of mail
  *
  * @var boolean
  */
  var $red_by_sender = false;

  /**
  * Status flag of mail
  *
  * @var boolean
  */
  var $red_by_recipient = false;

  
  
  function POC_Mail()
  {
    $this->sender = $_SESSION['chatter'];
  }

  /**
  * Adds a chatter to the list of recipients
  *
  * @access public
  * @param string
  */
  function add_recipient( $recipient )
  {
    if( !$this->is_in_recipients($recipient) )
      array_push ($this->recipients, $recipient);
  }

  /**
  * Sets the subject
  *
  * @access public
  * @param string
  */
  function set_subject( $subject )
  {
      $this->subject = $subject;
  }

  /**
  * Provides the subject of mail
  *
  * @access public
  * @return string
  */
  function get_subject()
  {
    return $this->subject;
  }
  
  /**
  * Sets the send time 
  *
  * @access public
  * @param integer
  */
  function set_send_time( $unix_timestamp )
  {
      $this->send_time = $unix_timestamp;
  }
  
  /**
  * Gets the send time 
  *
  * @access public
  * @return integer
  */
  function get_send_time()
  {
      return $this->send_time;
  }

  /**
  * Sets the subject
  *
  * @access public
  * @param string
  */
  function set_body( $body )
  {
    $this->body = $body;
  }

  /**
  * Gets the body of current mail
  *
  * @access public
  * @param string
  */
  function get_body()
  {
    return $this->body;
  }
  
  /**
  * Gets the sender
  *
  * @access public
  * @return string
  */
  function get_sender()
  {
    return $this->sender;
  }
  
  /**
  * Gets the sender
  *
  * @access public
  * @return array
  */
  function get_recipients()
  {
    return $this->recipients;
  }
  
  function set_recipient( $recipient )
  {
    $this->recipient = $recipient;
  }
  
  function get_recipient()
  {
    return $this->recipient;
  }
  
  function is_forwarded()
  {
    
  }
  
  function is_replied()
  {
    
  }
  
  /**
  * Sets red_by_recipient flag

  */
  function set_red_by_recipient()
  {
    $this->red_by_recipient = true;
  }

  
  /**
  * Sets red flag
  */
  function set_red_by_sender()
  {
    $this->red_by_sender = true;
  }
  
  /**
  * Returns true if mail is red by recipient, otherwise false
  *
  * @return boolean
  */
  function get_red_by_recipient()
  {
    return $this->red_by_recipient;
  }
  
  /**
  * @ignore
  */
  function is_red_by_recipient()
  {
    return $this->get_red_by_recipient();
  }

    
  /**
  * Returns true if mail is red, otherwise false
  *
  * @return boolean
  */
  function get_red_by_sender()
  {
    return $this->red_by_sender;
  }
  
  /**
  * @ignore
  */
  function is_red_by_sender()
  {
    return $this->get_red_by_sender();
  }
  
  /**
  * Returns true if given chatter already in recipient list, otherwise false
  *
  * @param string
  * @return boolean
  */
  function is_in_recipients( $chatter )
  {
    return in_array( $chatter, $this->recipients );
  }
  
  /**
  * Sets the time of last touch by sender
  *
  */  
  function set_last_touch_sender()
  {
    $this->last_touch_sender = time();
  }
  
  /**
  * Gets the time of last touch by sender
  *
  */  
  function get_last_touch_sender()
  {
    return $this->last_touch_sender;
  }
  
  /**
  * Sets the time of last touch by recipient
  *
  */  
  function set_last_touch_recipient()
  {
    $this->last_touch_recipient = time();
  }
  
  /**
  * Gets the time of last touch by recipient
  *
  */  
  function get_last_touch_recipient()
  {
    return $this->last_touch_recipient;
  }
  
  /**
  * Sets the time of first touch by recipient
  *
  */  
  function set_first_touch_recipient()
  {
    $this->first_touch_recipient = time();
  }
  
  /**
  * Gets the time of first touch by recipient
  *
  */  
  function get_first_touch_recipient()
  {
    return $this->first_touch_recipient;
  }
}
?>