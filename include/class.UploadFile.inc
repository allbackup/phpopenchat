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
 * Upload class - wrapper for uploading files.
 *
 * @author Michael Oertel <michael@ortelius.de>
 * @access  public
 * @version $Id: class.UploadFile.inc,v 1.4.2.3 2004/02/24 17:05:17 letreo Exp $
 */
class POC_UploadFile {
  
  /**
  * Contains all file attributes
  *
  * @var array
  */
  var $file_attributes = array();
  
  /**
  * Expected mime types
  *
  * @var array
  */
  var $types = array();
  
  /**
  * Image size in pixels
  *
  * @var integer
  */
  var $size_x = PRIVATE_IMG_SIZE_X;
  
  /**
  * Image size in pixels
  *
  * @var integer
  */
  var $size_y = PRIVATE_IMG_SIZE_Y;
  
  /**
  * Image size in bytes
  *
  * @var integer
  */
  var $size_bytes = PRIVATE_IMG_MAX_BYTES;
  
  /**
  * Contains upload errors
  *
  * @var array
  */
  var $errors = array();
  
  /**
  * Contains upload path
  *
  * @var string
  */
  var $path = '';
  
  /**
  * Constructor
  *
  * @param array
  */
  function POC_UploadFile( $file_attributes )
  {
    $this->file_attributes = $file_attributes;
  }
  
  /**
  * Sets expected mime types
  *
  * @param array
  */
  function set_types( $types )
  {
    $this->types = $types;
  }
  
  /**
  * Gets all upload errors
  *
  * @return array
  */
  function get_errors()
  {
    return $this->errors;
  }
  
  /**
  * Gets upload path
  *
  * @return string
  */
  function get_upload_path()
  {
    return $this->path;
  }
  
  /**
  * Gets upload path
  *
  * @return string
  */
  function set_upload_path($path)
  {
    $this->path = $path;
  }
  
  /**
  * Checks the posted file
  *
  * @param array
  * @return boolean
  */
  function check()  
  {
    if( !in_array($this->file_attributes['type'], $this->types) )
      $this->errors[] = $_SESSION['translator']->out('WRONG_MIME_TYPE');
    if( $this->file_attributes['size'] > PRIVATE_IMG_MAX_BYTES )
      $this->errors[] = $_SESSION['translator']->out('IMG_FILE_TO_BIG');
      
    $image = @getimagesize($this->file_attributes['tmp_name']);
    if(  ( $image[0] > PRIVATE_IMG_SIZE_X )
      || ( $image[1] > PRIVATE_IMG_SIZE_Y ))
      $this->errors[] = $_SESSION['translator']->out('IMG_SIZE_TO_BIG').'. '.$_SESSION['translator']->out('SIZE_EXPECTED').' '.PRIVATE_IMG_SIZE_X.'x'.PRIVATE_IMG_SIZE_Y;
    
    return( count($this->errors) == 0);
  }

  /**
  * Uploads the file
  *
  * @return boolean
  */
  function upload($mode = 1)
  {
    preg_match('#image/[x\-]?(.*)#',$this->file_attributes['type'], $parts);
    $file_extension = $parts[1];
    $new_file = $this->path . strtolower($_SESSION['chatter']->get_nick()) .'.'. $file_extension;

    switch($mode) {
      case 1: // overwrite mode
        return @copy($this->file_attributes['tmp_name'], $new_file);
      case 2: // do nothing if exists, highest protection
        if(file_exists($new_file)) {
          $this->errors[] = 'File "' . $this->new_file . '" already exists';
          return false;
        } else {
          return copy($this->file_attributes['tmp_name'], $new_file);
        }
    }
  }
}
?>