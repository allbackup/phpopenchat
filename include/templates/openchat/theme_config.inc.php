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

/*
  $Author: letreo $
  $Date: 2004/08/10 11:28:00 $
  $Source: /cvsroot/phpopenchat/chat3/include/templates/openchat/Attic/theme_config.inc.php,v $
  $Revision: 1.1.2.6 $
*/

//if your theme containing valid xhtml templates only...
if( ini_get('session.use_trans_sid') == 0 )
{
  define('VALID_XHTML', true); // ...set this true otherwise false
  //Note: if is set true, all the content will be delivered as application/xhtml+xml instead of text/html
}
else
{
  define('VALID_XHTML', false);
}
//some changes i.e. of framesets, requires a relogin
//So, if your theme needs a relogin to work properly, set this true
define('REQUIRES_RELOGIN', false);

/*
* To add extra smileys to your theme, copy an image file to
* /path/to/poc/include/templates/<your theme>/images/icons/smileys
* and add the filename as code to this array.
*
* Example:
* [copy]
* > copy foo.gif /path/to/poc/include/templates/<your theme>/images/icons/smileys
* > copy bar.gif /path/to/poc/include/templates/<your theme>/images/icons/smileys
* [edit]
* $extra_smileys = array(
*   ':foo:',
*   ':bar:'
* );
*/
$extra_smileys = array(
);
?>