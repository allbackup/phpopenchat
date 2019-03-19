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

/**
* Implements a logging mechanism
*
* @author  Michael Oertel <michael@ortelius.de>
* @access  public
* @version $Id: class.Logger.inc,v 1.7.2.3 2004/02/24 17:05:17 letreo Exp $
*/
class POC_Logger
{

  
  /**
  * Constructor
  *
  * @access public
  */
  function POC_Logger()
  {
  }
  
  /**
  * Writes lines into the log file
  *
  * @access private
  * @return void
  */
  function _write( $case, $message, $file = '', $line = '' )
  {
    if( NO_LOGGING ) return null;
    
    define_syslog_variables();
    $file = ($file!='')? $file.':'.$line.' ' : '';
    $log = $file.$message.NL;

    openlog('[POC-'.$case.']', LOG_PERROR, LOG_LOCAL0);
    switch($case)
    {
      case 'INFO':   syslog(LOG_INFO, $log);    break;
      case 'LINE':   syslog(LOG_INFO, $log);    break;
      
      case 'DEBUG':  syslog(LOG_DEBUG, $log);   break;
      case 'WARNING':syslog(LOG_WARNING, $log); break;
      case 'ERROR':  syslog(LOG_ERR, $log);     break;
      case 'EMERG':  syslog(LOG_EMERG, $log);   break;
    }
    closelog();
  }

  /**
  * Loggs info messages
  *
  * @access public
  */
  function info( $message )
  {
    if( !LOG_POC_INFOS ) return null;
    $this->_write('INFO',$message);
  }
  
  /**
  * Loggs lines
  *
  * @access public
  */
  function line($message)
  {
    if( !LOG_POC_LINES ) return null;
    $this->_write('LINE',$message);
  }
  
  /**
  * Loggs debug messages
  *
  * @access public
  */
  function debug($message, $file, $line)
  {
    if( !LOG_POC_DEBUG ) return null;
    $this->_write('DEBUG',$message, $file, $line);
  }

  /**
  * Loggs warnings
  *
  * warning conditions
  *
  * @access public
  */
  function warning($message)
  {
    if( !LOG_POC_WARNING ) return null;
    $this->_write('WARNING',$message);
  }

  /**
  * Loggs errors
  *
  * error conditions
  *
  * @access public
  */
  function error($message, $file, $line)
  {
    if( !LOG_POC_ERROR ) return null;
    $this->_write('ERROR',$message, $file, $line);
  }

  /**
  * Loggs emergency errors
  *
  * system is unusable
  *
  * @access public
  */
  function emerg($message, $file, $line)
  {
    if( !LOG_POC_EMERG ) return null;
    $this->_write('EMERG',$message, $file, $line);
  }
}
?>