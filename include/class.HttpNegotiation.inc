<?php
/*   ********************************************************************   **
**   Copyright notice                                                       **
**                                                                          **
**   (c) 2002 - 2003 HttpNegotiation Development Team                       **
**   http://httpneg.sourceforge.net/                                        **
**                                                                          **
**   All rights reserved                                                    **
**                                                                          **
**   This script is part of the HttpNegotiation project. The                **
**   HttpNegotiation project is free software; you can redistribute it      **
**   and/or modify it under the terms of the GNU General Public License as  **
**   published by the Free Software Foundation; either version 2 of the     **
**   License, or (at your option) any later version.                        **
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
 * <p>This class performs HTTP-based content negotiation. It provides methods to
 * get the preferred content-type, character encoding (charset), language, and
 * content coding (encoding).</p>
 *
 * <p>The format of the HTTP headers as defined in HTTP (for more information see
 * http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html and
 * http://www.w3.org/Protocols/rfc2616/rfc2616-sec3.html) are as follows:</p>
 *
 * <dl>
 * <dt>Accept<dt>
 * <dd><pre>"Accept" ":" #( media-range [ accept-params ] )
 * media-range    = ( "&#42/&#42" | ( type "/" "&#42" ) | ( type "/" subtype ) ) &#42 ( ";" parameter )
 * accept-params  = ";" "q" "=" qvalue *( accept-extension )
 * accept-extension = ";" token [ "=" ( token | quoted-string )</pre></dd>
 *
 * <dt>Accept-Charset</dt>
 * <dd><pre>"Accept-Charset" ":" 1#( ( charset | "*" )[ ";" "q" "=" qvalue ] )</pre></dd>
 *
 * <dt>Accept-Encoding</dt>
 * <dd><pre>"Accept-Encoding" ":"  1#( codings [ ";" "q" "=" qvalue ] )
 * codings          = ( content-coding | "*" )</pre></dd>
 *
 * <dt>Accept-Language<dt>
 * <dd><pre>"Accept-Language" ":" 1#( language-range [ ";" "q" "=" qvalue ] )
 * language-range  = ( ( 1*8ALPHA *( "-" 1*8ALPHA ) ) | "*" )</pre></dd>
 * </dl>
 *
 * @author Johannes Koch
 * @version CVS $Id: class.HttpNegotiation.inc,v 1.1.2.2 2004/02/29 19:57:10 letreo Exp $
 */
class HttpNegotiation {

  /**
   * The array of accept content types
   *
   * @var    string
   * @access private
   */
  var $_acceptContent;

  /**
   * The array of accept charset
   *
   * @var    string
   * @access private
   */
  var $_acceptCharset;

  /**
   * The array of accept languages
   *
   * @var    string
   * @access private
   */
  var $_acceptLanguage;

  /**
   * The array of accept encoding
   *
   * @var    string
   * @access private
   */
  var $_acceptEncoding;

  /**
   * The delimiter between type and subtype of content type
   *
   * @var    string
   * @access private
   */
  var $_DEL_CONTENT = '/';

  /**
   * The delimiter between type and subtype of language
   *
   * @var    string
   * @access private
   */
  var $_DEL_LANGUAGE = '-';

  /**
   * The delimiter which should never be found if variant has no type subtype combination
   *
   * @var    string
   * @access private
   */
  var $_DEL_NEVER = '##########';

  /**
   * The axis for content-type negotiation
   *
   * @var    string
   * @access private
   */
  var $_AXIS_CONTENT = 'content-type';

  /**
   * The axis for charset negotiation
   *
   * @var    string
   * @access private
   */
  var $_AXIS_CHARSET = 'charset';

  /**
   * The axis for language negotiation
   *
   * @var    string
   * @access private
   */
  var $_AXIS_LANGUAGE = 'language';

  /**
   * The axis for encoding negotiation
   *
   * @var    string
   * @access private
   */
  var $_AXIS_ENCODING = 'encoding';

  /**
   * Class constructor
   * Creates a new instance of HttpNegotiation
   *
   * @access public
   */
  function HttpNegotiation() {
    $this->_decodeAcceptHeaders();
  }

  /**
   * Decodes the headers 'Accept'
   *
   * @param string serverVariants variants the server supports
   * @param string defaultVariant fallback variant
   * @return string in case no match between request variants and server
   * variants where found the fallback value will be returned
   * @access public
   */
  function getPreferredContentType($serverVariants, $defaultVariant) {
    // return value
    $rVariant = $defaultVariant;
    // variants supplied?
    if (($serverVariants == null) || (strlen($serverVariants) == 0)) {
      return $rVariant;
    }
    // decode the server variants
    // encoding has no type/subtype so
    // simply set the type-subtype delimiter to a value
    // that never exists so that we still can use our once design method
    $variants = $this->_convertAcceptToArray($serverVariants, $this->_DEL_CONTENT);
    // now check for match
    $match = $this->_checkForMatch($this->_acceptContent, $variants, $this->_AXIS_CONTENT);
    // get the result
    // if best match exits and best match is not some wildcard,
    // return best match
    if (($match[1] != null) && (strcasecmp($match[2], '*')))
      $rVariant = $match[1] . $this->_DEL_CONTENT . $match[2];
    return $rVariant;
  }

  /**
   * Decodes the headers 'Accept-Charset'
   *
   * @param string serverVariants variants the server supports
   * @param string defaultVariant fallback variant
   * @return string in case no match between request variants and server
   * variants where found the fallback value will be returned
   * @access public
   */
  function getPreferredCharset($serverVariants, $defaultVariant) {
    // return value
    $rVariant = $defaultVariant;
    // variants supplied?
    if (($serverVariants == null) || (strlen($serverVariants) == 0)) {
      return $rVariant;
    }
    // decode the server variants
    // encoding has no type/subtype so
    // simply set the type-subtype delimiter to a value
    // that never exists so that we still can use our once design method
    $variants = $this->_convertAcceptToArray($serverVariants, $this->_DEL_NEVER);
    // now check for match
    $match = $this->_checkForMatch($this->_acceptCharset, $variants, $this->_AXIS_CHARSET);
    // get the result
    // if best match exits,
    // return best match
    if ($match[1] != null)
      $rVariant = $match[1];
    return $rVariant;
  }

  /**
   * Decodes the headers 'Accept-Language'
   *
   * @param string serverVariants variants the server supports
   * @param string defaultVariant fallback variant
   * @return string in case no match between request variants and server
   * variants where found the fallback value will be returned
   * @access public
   */
  function getPreferredLanguage($serverVariants, $defaultVariant) {
    // return value
    $rVariant = $defaultVariant;
    // variants supplied?
    if (($serverVariants == null) || (strlen($serverVariants) == 0)) {
      return $rVariant;
    }
    // decode the server variants
    // encoding has no type/subtype so
    // simply set the type-subtype delimiter to a value
    // that never exists so that we still can use our once design method
    $variants = $this->_convertAcceptToArray($serverVariants, $this->_DEL_LANGUAGE);
    // now check for match
    $match = $this->_checkForMatch($this->_acceptLanguage, $variants, $this->_AXIS_LANGUAGE);
    // get the result
    // if best match exits and best match is not some wildcard,
    // return best match
    if ($match[1] != null) {
      if (($match[2] != null) && (strlen($match[2]) > 0)) {
        $rVariant = $match[1] . $this->_DEL_LANGUAGE . $match[2];
      } else {
        $rVariant = $match[1];
      }
    }
    return $rVariant;
  }

  /**
   * Decodes the headers 'Accept-Encoding'
   *
   * @param string serverVariants variants the server supports
   * @param string defaultVariant fallback variant
   * @return string in case no match between request variants and server
   * variants where found the fallback value will be returned
   * @access public
   */
  function getPreferredEncoding($serverVariants, $defaultVariant) {
    // return value
    $rVariant = $defaultVariant;
    // variants supplied?
    if (($serverVariants == null) || (strlen($serverVariants) == 0)) {
      return $rVariant;
    }
    // decode the server variants
    // encoding has no type/subtype so
    // simply set the type-subtype delimiter to a value
    // that never exists so that we still can use our once design method
    $variants = $this->_convertAcceptToArray($serverVariants, $this->_DEL_NEVER);
    // now check for match
    $match = $this->_checkForMatch($this->_acceptEncoding, $variants, $this->_AXIS_ENCODING);
    // get the result
    // if best match exits and best match is not some wildcard,
    // return best match
    if ($match[1] != null)
      $rVariant = $match[1];
    return $rVariant;
  }


  /**
   * checks for matches of server and browser variants and if found
   * multiplicates the q factors. Returns the match with the highest qfactor.
   *
   * @param array acceptedByBrowser string array of variants the browser supports
   * @param array acceptedByServer string array of variants the serversupports
   * @param string axis - negotiation axis
   * @return array of best match or empty array if no match was found;
   * in case the best match on the client side is some wildcard, the wildcard
   * will be returned, otherwise the server variant will be returned.
   * @access private
   */
  function _checkForMatch($acceptedByBrowser, $acceptedByServer, $axis) {
    $bvidx = 0; // browser variants
    $ividx = 0; // server variants
    $browserType = '';
    $serverType = '';
    // result array of multiplication
    $resultVariants = array();
    // index for result array of multiplication
    $resultidx = -1;
    // the highest qfactor
    $highestQ = 0.;
    // the record with the highest qfactor
    $idx = 0;
    $numberOfServerVariants = count($acceptedByServer);
    for ($svidx = 0; $svidx < $numberOfServerVariants; $svidx++) {
      // get server type
      $serverType = $acceptedByServer[$svidx][1];
      if ($serverType != null) {
        $numberOfBrowserVariants = count($acceptedByBrowser);
        for ($bvidx = 0; $bvidx < $numberOfBrowserVariants; $bvidx++) {
          // get browser type
          $browserType = $acceptedByBrowser[$bvidx][1];
          if ($browserType != null) {
            // compare them and check for wildcard
            if ((!strcasecmp($browserType, $serverType)) || (!strcmp($browserType, '*'))) {
              // types are equal or
              // browser type is wildcard
              // compare subtypes
              if ((!strcasecmp($acceptedByBrowser[$bvidx][2], $acceptedByServer[$svidx][2])) ||
                  (!strcmp($acceptedByBrowser[$bvidx][2], '*')) ||
                  ((!strcmp($axis, $this->_AXIS_LANGUAGE)) &&
                   ((!strcmp($acceptedByBrowser[$bvidx][2], '')) ||
                    (!strcmp($acceptedByServer[$svidx][2], '')) ||
                    (strcasecmp($acceptedByBrowser[$bvidx][2], $acceptedByServer[$svidx][2]))))) {
                // subtypes are equal or
                // browser subtype is wildcard or
                // called by getPreferredLanguage
                // (e.g. de should also match de-DE,
                //  de-DE should also match de,
                //  de-AT should also match de-DE,
                //  but with a very low priority)
                // found match: multiplicate q-factors and add to result array
                $bqfactor = $acceptedByBrowser[$bvidx][0];
                $sqfactor = $acceptedByServer[$svidx][0];
                $rqfactor = $bqfactor * $sqfactor;
                // langugage-country match should be better
                if (!strcmp($axis, $this->_AXIS_LANGUAGE)) {
                  // browser country is '' or server country is ''
                  if (((!strcmp($acceptedByBrowser[$bvidx][2], '')) ||
                       (!strcmp($acceptedByServer[$svidx][2], ''))) &&
                      (strcasecmp($acceptedByBrowser[$bvidx][2], $acceptedByServer[$svidx][2]))) {
                    $rqfactor *= 0.02;
                  }
                  // browser country is different from server country
                  elseif (strcasecmp($acceptedByBrowser[$bvidx][2], $acceptedByServer[$svidx][2])) {
                    $rqfactor *= 0.01;
                  }
                }
                /*
                // Print the calculated matches
                echo $acceptedByServer[$svidx][1];
                if (strcmp($acceptedByServer[$svidx][2], '')) {
                  if (!strcmp($axis, $this->_AXIS_LANGUAGE)) {
                    echo $this->_DEL_LANGUAGE;
                  } else {
                    echo $this->_DEL_CONTENT;
                  }
                  echo $acceptedByServer[$svidx][2];
                }
                echo ';qs=' . $acceptedByServer[$svidx][0];
                echo ", ";
                echo $acceptedByBrowser[$bvidx][1];
                if (strcmp($acceptedByBrowser[$bvidx][2], '')) {
                  if (!strcmp($axis, $this->_AXIS_LANGUAGE)) {
                    echo $this->_DEL_LANGUAGE;
                  } else {
                    echo $this->_DEL_CONTENT;
                  }
                  echo $acceptedByBrowser[$bvidx][2];
                }
                echo ';q=' . $acceptedByBrowser[$bvidx][0];
                echo ' -> qr=' . $rqfactor . '<br/>';
                */
                $resultidx += 1;
                if (!strcmp($acceptedByBrowser[$bvidx][2],'*')) {
                  // browser subtype is wildcard
                  // return type and subtype (wildcard)
                  $resultVariants[] = array($rqfactor, $acceptedByBrowser[$bvidx][1], $acceptedByBrowser[$bvidx][2]);
                } else {
                  // return server type and subtype
                  $resultVariants[] = array($rqfactor, $acceptedByServer[$svidx][1], $acceptedByServer[$svidx][2]);
                }
                // check if this was the highest factor
                if ($rqfactor > $highestQ) {
                  $idx = $resultidx;
                  $highestQ = $rqfactor;
                }
              }
            }
          }
        }
      }
    }
    // return object
    $match = array($resultVariants[$idx][0], $resultVariants[$idx][1], $resultVariants[$idx][2]);
    return $match;
  }

  /**
   * decodes the Accept* string
   *
   * @param string accept
   * @param string typedelimiter
   * @access private
   */
  function _convertAcceptToArray($accept, $typedelimiter) {
    $rAccept = array();
    if (($accept == null) || (strlen($accept) == 0))
      return $rAccept;
    // single values delimited by ','
    $tok1 = split(',', $accept);
    foreach ($tok1 as $token) {
      $token = trim($token);
      // check for q-factor
      if (strpos($token, ';') > 0) {
        $tok2 = split(';', $token);
        $typeSubtypeCombination = trim($tok2[0]);
        for ($i = 1; $i < count($tok2); $i++) {
          $qfactor = trim($tok2[$i]);
          $tok3 = split('=', $qfactor);
          $qfactor = trim($tok3[0]);
          if (!strcasecmp($qfactor, 'q')) {
            $qfactor = trim($tok3[1]);
            break;
          } else {
            $qfactor = 'not set'; // to identifiy that no qfactor was supplied
          }
        }          
      } else {
        $typeSubtypeCombination = $token;
        $qfactor = 'not set'; // to identifiy that no qfactor was supplied
      }
      // now split type and subtype, language and country
      if (strpos($typeSubtypeCombination, $typedelimiter) > 0) {
        $tok2 = split($typedelimiter, $typeSubtypeCombination);
        $type = trim($tok2[0]);
        $subtype = trim($tok2[1]);
      } else {
        $type = $typeSubtypeCombination;
        $subtype = '';
      }
      // check q-factor and take care if no qfactor was supplied
      if (!strcmp($qfactor, 'not set')) {
        if (($type == '*') && ($subtype == '*')) {
          // */*
          $qfactor = 0.01;
        } elseif (($type != '*') && ($subtype == '*')) {
          // type/*
          $qfactor = 0.02;
        } elseif (($type == '*') && ($subtype == '')) {
          // *
          $qfactor = 0.01;
        } else {
          $qfactor = 1.0;
        }
      }
      $rAccept[] = array($qfactor, $type, $subtype);
    }
    return $rAccept;
  }

  /**
   * Decodes the headers Accept, Accept-Charset, Accept-Encoding, Accept-Language
   *
   * @access private
   */
  function _decodeAcceptHeaders() {
    //$headers = getallheaders();
    $sAccept = $_SERVER['HTTP_ACCEPT'];
    //$sAccept = $headers['Accept'];
    $this->_acceptContent = $this->_convertAcceptToArray($sAccept, $this->_DEL_CONTENT);
    $sAcceptCharset = (isset($_SERVER['HTTP_ACCEPT_CHARSET']))? $_SERVER['HTTP_ACCEPT_CHARSET']:'';
    //$sAcceptCharset = $headers['Accept-Charset'];
    $this->_acceptCharset = $this->_convertAcceptToArray($sAcceptCharset, $this->_DEL_NEVER);
    $sAcceptLanguage = (isset($_SERVER['HTTP_ACCEPT_LANGUAGE']))? $_SERVER['HTTP_ACCEPT_LANGUAGE']:'';
    //$sAcceptLanguage = $headers['Accept-Language'];
    $this->_acceptLanguage = $this->_convertAcceptToArray($sAcceptLanguage, $this->_DEL_LANGUAGE);
    $sAcceptEncoding = (isset($_SERVER['HTTP_ACCEPT_ENCODING']))? $_SERVER['HTTP_ACCEPT_ENCODING']:'';
    //$sAcceptEncoding = $headers['Accept-Encoding'];
    $this->_acceptEncoding = $this->_convertAcceptToArray($sAcceptEncoding, $this->_DEL_NEVER);
  }
}
?>
