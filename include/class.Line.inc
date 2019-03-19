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
require_once(POC_INCLUDE_PATH.'/class.Template.inc');
require_once(POC_INCLUDE_PATH.'/class.Logger.inc');

/**
 * Class Line holds lines written by chatters
 *
 * @todo rewrite of method filter_input_buffer() based on preg_replace()
 * @author Frerk Meyer <frerk@meychern.de>
 * @author Michael Oertel <michael@ortelius.de>
 * @access  public
 * @version $Id: class.Line.inc,v 1.42.2.12 2004/03/04 12:50:58 letreo Exp $
 */
class POC_Line {

  /**
  * chatter object represents a person taking part in a chat session
  *
  * @var object
  */
  var $chatter = null;

  /**
  * recipient object represents a person receiving a chat message
  *
  * @var object
  */
  var $recipient = null;

  /**
  * string said by chatter
  *
  * @var string
  */
  var $said = '';

  /**
  * true if line is whispered
  *
  * @var boolean
  */
  var $whispered = false;
  
  /**
  * true if line is approved by a moderator
  *
  * @var boolean
  */
  var $approved = false;
  
  /**
  * contains an irc-command found in the line
  *
  * @var array
  */
  var $irc_command = array();
  
  /**
  * contains accepted mime types for private images
  *
  * @var array
  */
  var $mime_types = array();
  
  /**
  * counts smileys within a line
  *
  * @var integer
  */
  var $smiley_count = 0;

  /**
  * marks a line as invitation message
  *
  * @var boolean
  */
  var $invitationMsg = false;

  /**
  * private window flag
  *
  * @var boolean
  */
  var $in_private_window = false;

  /**
  * sender busy flag
  *
  * @var boolean
  */
  var $sender_busy = false;

  /**
  * @var string
  */
  var $join = '';

  /**
  * @var string
  */
  var $leave = '';

  /**
  * @var boolean
  */
  var $info = false;

  /**
  * @var integer
  */
  var $time;

  /**
   * Constructor for class Line
   *
   * @param object $chatter chatter object represents a person taking part in a chat session
   * @param string $said string said by chatter
   * @param object recipient of the text line
   */
  function POC_Line($chatter, $said)
  {
    // check $chatter - should be of class Chatter
    // check $said - should be of type string
    $this->chatter   = $chatter;
    $this->said      = $said;
    $this->time      = time();
  }
  
  /**
  * provides the HTML code for a chosen smiley
  * @access private
  * @param string smiley code
  * @param object template
  * @return string HTML image tag
  */
  function _mk_smiley_img_tag($smiley, $templ = null)
  {
    if(is_null($templ)){
      $templ = &$_SESSION['template'];
    }
    return '<img src="'.$templ->get_tmpl_web_path().'/images/icons/smileys/'.$smiley.'.gif" align="middle" border="0" />';
  }

  /**
   * Provides send time of line
   *
   * @return string
   */
  function get_time( $format = 'Y-m-d H:i:s')
  {
    return (!empty($this->time))? date($format, $this->time):'';
  }

  /**
   * Getter for chatter object
   *
   * @return object
   */
  function get_chatter()
  {
    return $this->chatter;
  }
  
  /**
   * alias for get chatter
   * @see get_chatter()
   */
  function get_sender()
  {
    return $this->get_chatter();
  }
  
  /**
   * Getter for recipient object
   *
   * @return object
   */
  function get_recipient()
  {
    return $this->recipient;
  }

  /**
   * Setter for recipient object
   *
   * @param object
   */
  function set_recipient( $recipient )
  {
    if(!is_object( $recipient) ) die('Recipient MUST be an object!');
    $this->recipient = $recipient;
  }

  /**
   * Setter for invitationMsg
   *
   * @param boolean
   */
  function set_invitationMsg( $bool = true )
  {
      $this->invitationMsg = $bool;
  }

  /**
   * Provides the invitationMsg flag
   *
   * @return boolean
   */
  function get_invitationMsg()
  {
      return $this->invitationMsg;
  }
  
  /**
  * alias for get_invitationMsg
  * @see get_invitationMsg()
  */
  function is_invitationMsg()
  {
      return $this->get_invitationMsg();
  }

  /**
   * Setter for sender object
   *
   * @param object
   */
  function set_sender( $sender )
  {
      $this->chatter = $sender;
      return true;
  }

  /**
   * Setter for sender busy flag
   *
   * @param boolean
   */
  function set_sender_busy( $bool = true )
  {
      $this->sender_busy = $bool;
  }

  /**
   * Setter for info flag
   *
   * @param boolean
   */
  function set_info( $bool = true )
  {
      $this->info = $bool;
  }

  /**
   * Getter for info flag
   *
   * @return boolean
   */
  function is_info()
  {
      return $this->info;
  }

  /**
   * Getter for sender busy flag
   * 
   * if is set, the chatter is using the private chat window 
   * and so hi is bussy to chat private with another one
   * 
   * @return boolean
   */
  function get_sender_busy()
  {
      return $this->sender_busy;
  }
  
  /** 
  * alias for get_sender_busy()
  * @see get_sender_busy()
  * @return boolean
  */
  function is_sender_busy(){return $this->get_sender_busy();}
  
  /**
   * alias
   * @ignore
   */
  function set_chatter( $sender )
  {
      return set_sender($sender);
  }

  /**
   * Getter for said string
   *
   * @return string
   */
  function get_said()
  {
    return $this->said;
  }
  
  /**
   * Setter for said string
   *
   * @param string
   */
  function set_said( $said )
  {
    $this->said = $said;
  }

  /**
  * Getter for chatter object
  *
  * @return object
  */
  function get_whispered()
  {
    return $this->whispered;
  }
  function is_whispered(){return $this->get_whispered();}//alias
  
  /**
   * Setter for var $whispered
   *
   * @param boolean
   * @return boolean
   */
  function set_whispered( $bool = true )
  {
    $this->whispered = $bool;
  }
  
  /**
   * Sets approved flag
   *
   * @param boolean
   */
  function set_approved( $bool = true )
  {
    $this->approved = $bool;
  }
  
  /**
   * Gets approved flag
   *
   * @return boolean
   */
  function get_approved()
  {
    return $this->approved;
  }
  
  /**
   * Gets the irc-command of line
   *
   * @return string
   */
  function get_irc_command()
  {
    return $this->irc_command;
  }
  
  /**
   * Provides the nickname of the chatter who is logging in.
   *
   * @return string
   */
  function get_login()
  {
    return $this->login;
  }
  
  /**
   * Provides the nickname of the chatter who is leaving the chat.
   *
   * @return string
   */
  function get_leave()
  {
    return $this->leave;
  }
  
  /**
   * Sets the nickname of the chatter who is logging in.
   *
   * @return string
   */
  function set_login($login)
  {
    $this->login = $login;
  }
  
  /**
   * Sets the nickname of the chatter who is leaving the chat.
   *
   * @return string
   */
  function set_leave($leave)
  {
    $this->leave = $leave;
  }

  function is_loginMsg()
  {
    return ( $this->login != '' );
  }

  function is_leavingMsg()
  {
    return ( $this->leave != '' );
  }
  
  /**
   * Sets accepted mime types for private images
   *
   * @param array
   */
  function set_accepted_mime_types($types)
  {
    $this->mime_types = $types;
  }
  
  /**
   * Returns a file name for the given smiley
   *
   * @access private
   * @param string
   * @return string
   */
  function _smiley_mapping($code)
  {
    if( $this->smiley_count >= MAX_SMILEYS_PER_LINE )
      return $code;
    else 
      $this->smiley_count++;
    
    if( $code == ':me' )
    {
      $sender = $this->get_sender();
      $smiley_dir  = '/images/icons/chatter';
      for ($i=0;$i<count($this->mime_types);$i++)
      {
        preg_match('#image/[x\-]?(.*)#',$this->mime_types[$i], $parts);
        $file_extension = $parts[1];
        $smiley_path = $smiley_dir.'/'.strtolower($sender->get_nick()).'.'.$file_extension;
        if( file_exists($_SESSION['template']->get_tmpl_sys_path().$smiley_path) )
          return '<img src="'.$_SESSION['template']->get_tmpl_web_path().$smiley_path.'" align="middle" alt="'.$_SESSION['translator']->out('PRIVATE_IMAGE').'" width="'.PRIVATE_IMG_SIZE_X.'" height="'.PRIVATE_IMG_SIZE_Y.'" />';
      }
      
      return $code;
    }

    if( $code == ':you' )
    {
      $recipient = $this->get_recipient();
      $smiley_dir  = '/images/icons/chatter';
      for ($i=0;$i<count($this->mime_types);$i++)
      {
        preg_match('#image/[x\-]?(.*)#',$this->mime_types[$i], $parts);
        $file_extension = $parts[1];
        $smiley_path = $smiley_dir.'/'.strtolower($recipient->get_nick()).'.'.$file_extension;
        if( file_exists($_SESSION['template']->get_tmpl_sys_path().$smiley_path) )
          return '<img src="'.$_SESSION['template']->get_tmpl_web_path().$smiley_path.'" align="middle" alt="'.$_SESSION['translator']->out('PRIVATE_IMAGE').'" width="'.PRIVATE_IMG_SIZE_X.'" height="'.PRIVATE_IMG_SIZE_Y.'" />';
      }

      return $code;
    }

    //if the current theme comes with new smileys than
    //check for that new smileys
    if( isset($_SESSION['template']) 
    &&  $_SESSION['template']->has_extra_smileys()
    &&  in_array($code, $_SESSION['template']->get_extra_smileys()) ){
      return $this->_mk_smiley_img_tag( preg_replace('/:/','',$code) );
    }

    if( defined('OFFER_MORE_ICONS') && OFFER_MORE_ICONS ){
      $parts  = split('@', preg_replace('/:/','',$code));
      $theme  = $parts[1];
      $_code  = $parts[0];
      unset($parts);
      if( in_array( $theme, $_SESSION['template']->get_theme_list() )){
        $templ = &new POC_Template();
        $templ->set_theme($theme);
        return $this->_mk_smiley_img_tag($_code, $templ);
      }
      unset($theme);
    }
    
    
    switch ($code)
    {
      case ':-)': return $this->_mk_smiley_img_tag('smile');
      case ':)' : return $this->_mk_smiley_img_tag('smile');
      case ':-(': return $this->_mk_smiley_img_tag('frown');
      case ':(':  return $this->_mk_smiley_img_tag('frown');
      case ':,-(':return $this->_mk_smiley_img_tag('crying');
      case ':,(': return $this->_mk_smiley_img_tag('crying');
      case ':-p': return $this->_mk_smiley_img_tag('tongue');
      case ':p':  return $this->_mk_smiley_img_tag('tongue');
      case ':-x': return $this->_mk_smiley_img_tag('kiss');
      case ':-D': return $this->_mk_smiley_img_tag('biggrin');
      case ':D':  return $this->_mk_smiley_img_tag('biggrin');
      case ':-]': return $this->_mk_smiley_img_tag('evillaugh');
      case ':]':  return $this->_mk_smiley_img_tag('evillaugh');
      case '=:-)':return $this->_mk_smiley_img_tag('punk');
      case ':-)=':return $this->_mk_smiley_img_tag('beard');
      case 'B-))':return $this->_mk_smiley_img_tag('poc');
      case 'B-)': return $this->_mk_smiley_img_tag('poc');
      case '(/)': return $this->_mk_smiley_img_tag('denied');
      case '(:(=':return $this->_mk_smiley_img_tag('ghost');
      case '~==': return $this->_mk_smiley_img_tag('candle');
      case '~o':  return $this->_mk_smiley_img_tag('bomb');
      case '~--': return $this->_mk_smiley_img_tag('dynamite');
      case ':#D': return $this->_mk_smiley_img_tag('sail');
      case ':-Q': return $this->_mk_smiley_img_tag('smoke');
      case ':[=]':return $this->_mk_smiley_img_tag('trash');
      case '8)':  return $this->_mk_smiley_img_tag('frog');

      case ':alarm:':
      case ':angel:':
      case ':angry:':
      case ':angryfire:':
      case ':apresent:':
      case ':asskick:':
      case ':at:':
      case ':beard:':
      case ':biggrin:':
      case ':birthday:':
      case ':blank:':
      case ':bomb:':
      case ':borg:':
      case ':candle:':
      case ':cheesy:':
      case ':cloud:':
      case ':confused:':
      case ':cool:':
      case ':cry:':
      case ':crying:':
      case ':dazzler:':
      case ':denied:':
      case ':director:':
      case ':dynamite:':
      case ':eating:':
      case ':evillaugh:':
      case ':eviltongue:':
      case ':fairy:':
      case ':female:':
      case ':finger:':
      case ':flower:':
      case ':frog:':
      case ':frown:':
      case ':ghost:':
      case ':grin:':
      case ':hehe:':
      case ':help:':
      case ':hi:':
      case ':huh:':
      case ':kidding:':
      case ':kiss:':
      case ':kisslipps:':
      case ':icon_aetsch:':
      case ':icon_beten:':
      case ':icon_bussi:':
      case ':icon_knabber:':
      case ':icon_megaphon:':
      case ':icon_nurse:':
      case ':icon_redface:':
      case ':icon_rolleyes:':
      case ':icon_rolleyes2:':
      case ':icon_thumb:':
      case ':icon_verwirrt:':
      case ':icon_wut:':
      case ':lol:':
      case ':love:':
      case ':lovestory:':
      case ':mail:':
      case ':male:':
      case ':massa:':
      case ':msg:':
      case ':none:':
      case ':nono:':
      case ':pa:':
      case ':phoneme:':
      case ':phone:':
      case ':poc:':
      case ':punk:':
      case ':question:':
      case ':rain:':
      case ':rambo:':
      case ':repuke:':
      case ':rettass:':
      case ':rolleyes:':
      case ':rose:':
      case ':sad:':
      case ':sail:':
      case ':scream:':
      case ':shocked:':
      case ':sleep:':
      case ':smile:':
      case ':smoke:':
      case ':smoky:':
      case ':stoned:':
      case ':sun:':
      case ':thumbsup:':
      case ':toffline:':
      case ':toilet:':
      case ':tombstone:':
      case ':tongue:':
      case ':trash:':
      case ':verysad:':
      case ':wow:':
      case ':yawn:':

      case ':SM001:':
      case ':SM002:':
      case ':SM003:':
      case ':SM004:':
      case ':SM005:':
      case ':SM006:':
      case ':SM007:':
      case ':SM008:':
      case ':SM009:':
      case ':SM010:':
      case ':SM011:':
      case ':SM012:':
      case ':SM013:':
      case ':SM014:':
      case ':SM015:':
      case ':SM016:':
      case ':SM017:':
      case ':SM018:':
      case ':SM019:':
      case ':SM020:':
      case ':SM021:':
      case ':SM022:':
      case ':SM023:':
      case ':SM024:':
      case ':SM025:':
      case ':SM026:':
      case ':SM027:':
      case ':SM028:':
      case ':SM029:':
      case ':SM030:':
      case ':SM031:':
      case ':SM032:':
      case ':SM033:':
      case ':SM034:':
      case ':SM035:':
      case ':SM036:':
      case ':SM037:':
      case ':SM038:':
      case ':SM039:':
      case ':SM040:':
      case ':SM041:':
      case ':SM042:':
      case ':SM043:':
      case ':SM044:':
      case ':SM045:':
      case ':SM046:':
      case ':SM047:':
      case ':SM048:':
      case ':SM049:':
      case ':SM050:':
      case ':SM051:':
      case ':SM052:':
      case ':SM053:':
      case ':SM054:':
      case ':SM055:':
      case ':SM056:':
      case ':SM057:':
      case ':SM058:':
      case ':SM059:':
      case ':SM060:':
      case ':SM061:':
      case ':SM062:':
      case ':SM063:':
      case ':SM064:':
      case ':SM065:':
      case ':SM066:':
      case ':SM067:':
      case ':SM068:':
      case ':SM069:':
      case ':SM070:':
      case ':SM071:':
      case ':SM072:':
      case ':SM073:':
      case ':SM074:':
      case ':SM075:':
      case ':SM076:':
      case ':SM077:':
      case ':SM078:':
      case ':SM079:':
      case ':SM080:':
      case ':SM081:':
      case ':SM082:':
      case ':SM083:':
      case ':SM084:':
      case ':SM085:':
      case ':SM086:':
      case ':SM087:':
      case ':SM088:':
      case ':SM089:':
      case ':SM090:':
      case ':SM091:':
      case ':SM092:':
      case ':SM093:':
      case ':SM094:':
      case ':SM095:':
      case ':SM096:':
      case ':SM097:':
      case ':SM098:':
      case ':SM099:':
      case ':SM100:':
      case ':SM101:':
      case ':SM102:':
      case ':SM103:':
      case ':SM104:':
      case ':SM105:':
      case ':SM106:':
      case ':SM107:':
      case ':SM108:':
      case ':SM109:':
      case ':SM110:':
      case ':SM111:':
      case ':SM112:':
      case ':SM113:':
      case ':SM114:':
      case ':SM115:':
      case ':SM116:':
      case ':SM117:':
      case ':SM118:':
      case ':SM119:':
      case ':SM120:':
      case ':SM121:':
      case ':SM122:':
      case ':SM123:':
      case ':SM124:':
      case ':SM125:':
      case ':SM126:':
      case ':SM127:':
      case ':SM128:':
      case ':SM129:':
      case ':SM130:':
      case ':SM131:':
      case ':SM132:':
      case ':SM133:':
      case ':SM134:':
      case ':SM135:':
      case ':SM136:':
      case ':SM137:':
      case ':SM138:':
      case ':SM139:':
      case ':SM140:':
      case ':SM141:':
      case ':SM142:':
      case ':SM143:':
      case ':SM144:':
      case ':SM145:':
      case ':SM155:':
      case ':smiley:':
      case ':smiley1:':
      case ':smiley10:':
      case ':smiley11:':
      case ':smiley2:':
      case ':smiley21:':
      case ':smiley3:':
      case ':smiley4:':
      case ':smiley5:':
      case ':smiley6:':
      case ':smiley7:':
      case ':smiley8:':
      case ':smiley9:':
        return $this->_mk_smiley_img_tag( preg_replace('/:/','',$code) );
      default: return $code;
    }
  }

  /**
   * Filters irc-commands in $said
   *
   * @return void
   */
  function filter_irc()
  {
    //filter IRC like commands
    if( preg_match ( '#^/([a-z]+) ?([^ ]*) ?([0-9]*).*$#i', $this->said, $irc_command ) && $irc_command[1] != '')
    {
      $this->irc_command[] = $irc_command[1];
      $this->irc_command[] = preg_replace('/\+/', ' ', $irc_command[2]);
      $this->irc_command[] = $irc_command[3];
    }
  }
  
  /**
   * Filters icons, links, etc. in $said
   *
   * @todo replace eregi_replace with preg_replace.
   * @return null
   */
  function filter_buffer_input()
  {
    if( count($this->irc_command) > 0 )
      return null;
    //filter urls
    elseif ( preg_match ( '#www\.|https?://|ftp://|.+@.+\..+#', $this->said) )
    {
      $pieces = explode(' ',$this->said);
      reset($pieces);
      do{
        if( preg_match ('#www\.|https?://|ftp://#',current($pieces)) )
        {
          $pieces[key($pieces)] = eregi_replace("((((https?://([^ :@]*(:[^ :@]*)?@)?)|(ftp://([^ :@]*(:[^ :@]*)?@)?))?[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}(:[0-9]{1,5})?(/[^][ <>@()]*)?)|(((https?://([^ :@]*(:[^ :@]*)?@)?)|(ftp://([^ :@]*(:[^ :@]*)?@)?)|(www\.))[^] <>/@()]+\.[a-z]{2,}(:[0-9]{1,5})?(/[^][ <>@()]*)?))",
            "<a class=\"linkWithinOutputFrame\" href=\"jump.php?url=\\0\" target=\"_blank\">\\0</a>",current($pieces));
        }
        elseif( preg_match('/.*@.*\..*/',current($pieces)) )
        {
          $pieces[key($pieces)] = eregi_replace("[^][ <>@():]+@[^][ <>@():]+\.[a-z]{2,}","<a class=\"linkWithinOutputFrame\" href=\"mailto:\\0\">\\0</a>",current($pieces));
        }
      }while(next($pieces));
      $this->said = implode($pieces,' ');
      
      return null;
    }
    
    //insert smiley-images if configured
    if( SMILEYS_AS_IMAGES )
      $this->said = preg_replace('/(=?[:|B|\(|~|8]\w*[@\w]*:?[^ |\<|\w]*[D|x|Q]?)/e', '\$this->_smiley_mapping("\1")' ,$this->said );

    //insert private-images if configured
    if( ALLOW_PRIVATE_IMAGES )
      $this->said = preg_replace('/(:[me|you]*)/e', '\$this->_smiley_mapping("\1")' ,$this->said );
    
    $this->said = preg_replace( "/\#{3}([^#]*)\#{3}/e", '\1', $this->said );

    return null;
  }

  /**
   * Filters 'says to', 'leaves us', ... messages within output frame
   *
   * used in getlines.php only
   *
   * @param object Translator
   * @return null
   */
  function filter_buffer_output()
  {
    $this->said = preg_replace( "/\#{3}([^#]*)\#{3}/e", "\$_SESSION['translator']->out('\\1')", $this->said );

    return null;
  }

  /**
  * @desc
  * Returns a formatted line, 
  * but at this time only used to format the locally displayed lines! 
  * 
  * @todo use this function in getlines also
  * @see getlines.php
  * @return string
  */
  function out()
  {
    $sender = $this->chatter;
    $recipient = $this->recipient;
    
    //whispering to somebody?!
    if( $this->get_whispered()
    && is_object($recipient)
    && $recipient->get_nick() == $_SESSION['translator']->out('EVERYBODY')
    )
      $this->set_whispered(false);
    $italic = ( $this->is_whispered() )? ';font-style:italic':'';
    $line  = '<div style="color: #'.$sender->get_color().$italic.'">'.HTML_BEFORE_LINE;
    unset($italic);
    $line .= $_SESSION['chat']->get_grade_icon( $sender );
    $gender  = '';
    if( SHOW_GENDER_ICON )
      $gender = ($sender->get_gender())?'<img src="'.$_SESSION['template']->get_tmpl_web_path().'/images/icons/'.$sender->get_gender().'.gif" width="8" height="8" alt="'.$_SESSION['translator']->out('GENDER').'" /> ':'<img src="'.$_SESSION['template']->get_tmpl_web_path().'/images/dot_clear.gif" width="8" height="8" alt="" /> ';
    $line .= $gender.'<span>'.$sender->get_nick().'</span>&nbsp;';
    if( $this->get_whispered() )
      $line .= $_SESSION['translator']->out('WHISPERS_TO');
    else
      $line .= $_SESSION['translator']->out('SAYS_TO');
    
    if( is_object($recipient) )
      $line .= '&nbsp;<span>'.$recipient->get_nick().'</span>:&nbsp;';
    
    $this->filter_buffer_output();
    $line .= $this->get_said().HTML_AFTER_LINE.'</div>';

    unset($sender);
    unset($recipient);
    
    return preg_replace('#</#', '<\\/', $line);
  }
  
  /**
  * Provides the private window flag
  * 
  * if is set, the line will be displayed in the private chat window only 
  *
  * @return boolean
  */
  function in_private_window()
  {
    return $this->in_private_window;
  }
  
  /**
  * Sets the private window flag 
  *
  * @param boolean
  */
  function set_in_private_window( $bool = true )
  {
    $this->in_private_window = $bool;
  }
  
  /**
  * Test class Line
  * 
  * Call like this: POC_Line::test();
  */
  function test() {
    $line = new POC_Line("Fritz","Hello World!");
    print "Line test, ";
    print $line->get_chatter();
    print " said: ";
    print $line->get_said();
    print "<br>\n";
  }
}
?>
