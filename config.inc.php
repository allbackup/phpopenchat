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
  $Date: 2004/08/26 11:57:24 $
  $Source: /cvsroot/phpopenchat/chat3/config.inc.php,v $
  $Revision: 1.33.2.38 $
*/

// configuration file for PHPOpenChat
// will be included by almost all source files
define('POC_BASE', dirname(__FILE__));

if( strtoupper( substr(PHP_OS,0,3) ) == 'WIN' )
{
  define('POC_OS','win');
  define('DELI','\\');

  /**
  * Temp-directory where we write the channel lock files
  * This define will either be 'Unix' or 'Windows'
  */
  define('TMPDIR', 'c:\cvs\rel300\tmp');
} else {
  //This is the Linux/Unix case
  define('POC_OS','unix');
  define('DELI','/');
  //For security reasons change TMPDIR to a directory,
  //outsite of your webroot. NOTE: This directory must be
  //writeable for the webserver.
  define('TMPDIR', POC_BASE.'/tmp');
}

/*
 * set include path for phpopenchat includes
 */
define('POC_INCLUDE_PATH', POC_BASE.'/include');
//ini_set('include_path', POC_BASE.'/include');

/*
 * use_trans_sid produce unvalid XHTML (strict)!
 * The form element requires a blocklevel element before using elements like input or select
 * see http://www.w3.org/TR/html4/interact/forms.html#h-17.3
 * because of this fact, we switch off this feature
 */
ini_set('session.use_trans_sid','0');
ini_set('session.bug_compat_warn','0');

/*
 * Name of PHPOpenChat's session cookie (session name)
 */
//if( function_exists('pnUserGetVar') ) ini_set('session.name', 'POCSID');

/*
 * Lifetime of cookies
 */
define('COOKIE_EXPIRE', time() + 60*60*24*30*12*25,true);
define('COOKIE_PATH',"/",true);
define('COOKIE_DOMAIN','',true);
define('COOKIE_SECURE','0',true);
//ini_set('session.cookie_lifetime', COOKIE_EXPIRE);//currently set to 25 years

/*
 * It is highly recommended that you configure/compile
 * php so, that session data are stored in shared
 * memory, not in files. In the 'file' case, we setup
 * the directory where php will store the session-files
 * NOTE: This directory MUST be writeable by the webserver
 */
//ini_set('session.save_path',TMPDIR);
session_save_path(TMPDIR);

/*
 * At this time there are two authentification methods
 * available. PHPOpenChat's own authentification database
 * or authentification using a LDAP server.
 */
define('AUTHENTICATION_METHOD','poc');

/**
 * LDAP settings.
 * Used if you choose 'ldap' as authentication method (see above)
 * Enter the DNS of you local ldap server.
 */
define('LDAP_SERVER','ldap.pixelpark.com');

/*
 * If you don't know the 'dn' of your local ldap server,
 * use test/ldap.php to ask the ldap server for it
 */
define('LDAP_DN','ou=NTUser,ou=Accounts,o=pixelpark.com');

/*
 * Ringbuffer settings
 * If you have:
 * - shared memory and semaphores compiled in,
 *   (search for 'sysvshm' and 'sysvsem' in a page generated by phpinfo() ) and,
 * - specified the initial memory size for the shared memory
 *   (add 'sysvshm.init_mem = 32595000' to your php.ini)
 * set this to 'Mem' for the best performance of your chat.
 * otherwise set to 'DB'
 */
define('CHANNEL_BUFFER_TYPE','DB');

/*
 * database account settings
 */
define('DATABASE_HOST', 'localhost');
define('DATABASE_USER', 'root');
define('DATABASE_PASSWORD', '');
define('DATABASE_TABLESPACE', 'poc');/* The value 'poc' is an example only!
                                     * a tablespace contains your sql-tables
                                     * MySQL calls it 'database', so you have to enter the name of your database here.
                                     * If you don't have such a tablespace already, MySQL users have to do:
                                     * # mysqladmin create DATABASE_TABLESPACE
                                     * # mysql -u DATABASE_USER -pDATABASE_PASSWORD DATABASE_TABLESPACE < /your/path/to/phpopenchat/db.schema
                                     */
define('DATABASE_TABLE_PREFIX', 'poc_');

/*
 * As a database layer we use ADODB (http://php.weblogs.com/adodb) to be
 * database independent.
 * Possible database drivers are mysql, mssql, oracle, oci8,
 * postgres, sybase, vfp, access, ibase and many others. (see adodb homepage)
 * NOTE: mysql is tested only!
 */
define('DATABASE_DRIVER','mysql');

/*
 * Set this true, if you like a persistant database connection for each user
 * NOTE: You will have one database instance per chatter.
 */
define('USE_PCONNECT',false);

/*
 * Template related settings
 */
define('TEMPLATE_EXTENSION','tpl');
define('DEFAULT_THEME','openchat');
define('BASETEMPLATE_PATH','/include/templates');
define('ALLOW_TEMPLATE_CHANGES',true);
// the following configuration are nessesary only if  POC is used as PostNuke module
// Integration into postnuke
define('PN_MODULE_NAME','phpopenchat-3.0.0');//directory name of POC in /path/to/postnuke/modules

define('OPERATOR_LABEL','@');//this character labels operators in the chatter list.

/*
* when a new user enters the chat they can see nothing from before,
* with this property you can enable a history of spoken lines so that users 
* can experience what was going on in the current channel before.
*/
define('SHOW_CHAT_HISTORY', false);

/*
* allow channel spying before users login
*/
define('ALLOW_SPYING', true);

/*
 * removes unnecessary white spaces and line breaks from html-output
 * to decrease traffic
 * NOTE: Setting this true makes only sense if you can't use gzip compression for your webserver output.
 */
define('TRIM_OUTPUT',true);

/*
 * Generic settings
 */

/*
 * To add a language, copy the desired language file to the
 * directory /path/to/poc/include/languages
 * and add the language code here. Language codes are described by ISO-639
 * (see http://www.oasis-open.org/cover/iso639a.html)
 */
$supported_languages = array('en','br','cn','de','dk','es','fr','it','nl','pl','se','tr','tw'); //first language will be choosen,
                                         //in case of no language are specified by client browser
                                         //or no supported language we are found
                                         //in the list of languages of client browser
/*
 * The name of your chat. Mostly used to label HTML-pages
 */
define('CHAT_NAME','PHPOpenChat');

/*
 * Exit URL
 */
define('EXIT_URL','');//Example: http://phpopenchat.org/

/*
 * Kick URL
 */
define('KICK_URL','');//Example: http://www.geocities.com/aniquiz/hero/reason.html

/*
 * Context menu
 */
define('DISABLE_CONTEXT_MENU','false');//Context menu in the output frame shown on right click (It MUST be a string!)
define('DISABLE_CONTEXT_MENU_ICONS',false);

/*
 * If this true, a login without a password is possible.
 * Format of guest nickname: 'Guest_23543'
 */
define('ALLOW_GUEST_LOGIN',true);

/*
 * Status messages within the chat will be spoken by this name
 */
define('STATUS_BOT_NAME','System');

/*
 * Minimum length of a nickname
 */
define('MAX_LINE_LENGTH',300);//chars per line

/*
 * Minimum length of a nickname
 */
define('NICKNAME_MAX_LENGTH',16);

/*
 * Minimum length of user passwords
 */
define('PASSWORD_MIN_LENGTH', 5);

/*
 * If it is set to true POC will store the passwords as a md5-checksum in the db
 */
define('MD5_PASSWORDS', false);

/*
 * Maximum of concurrent chatters within one channel
 */
define('MAX_CONCURRENT_CHATTER', 50);//a max. of 100 chatters is recommended

/*
 * Maximum count for registered nicknames per e-mail address
 */
define('MAX_EMAIL_REGISTER_COUNT', 5);

/*
 * If a confirmation of registration by email desired
 * set this true.
 */
define('SEND_CONFIRMATION_MAIL', true);

/*
 * The confirmation mail contains a link for confirming a registration.
 * If this mail ought to contain an other host within the URL,
 * set this property otherwise leave it blank.
 * Nesessary only, if the generated mail contains an wrong host within the link
 * in the mail.
 */
define('CONFIRMATION_HOST','');

/*
 * Set this to false to exclude the most of chatters with freemail-accounts.
 *
 * For Windows users: If this set to true, you can likely set the SMTP directive in the php.ini
 * configuration file to your isp's SMTP mail server - the same as you use for outgoing mail
 * in your email client (Eudora, Outlook, etc.) . However, check with your ISP before doing this!
 * eg
 * SMTP = mail.your_isp.com
 */
define('SEND_MAIL_TO_FREEMAIL_ACCOUNTS',true);

/*
 * Your email address
 * NOTE: This email address MUST exist to send confirmation mails!
 */
define('ADMIN_MAIL_ADDRESS','me@mydomain.com');
define('ADMIN_MAIL_NAME','Chat-Team');

/*
 * Entered URLs within the chat becomes to links automatically.
 * A forward to such a site will be canceled,
 * if this specified words in the content are found.
 */
define('UNACCEPTABLE_CONTENT','fuck|cunt|bitch');

/*
 * Prohibited nicknames
 */
$NO_NICKS = array('me','you','operator','admin','moderator','vip','join','msg','help','quit','ignore','unignore','query','locate','kick','ban','hitler','adolf','nazi', STATUS_BOT_NAME);

/*
 * nicknames which will newer die
 */
$DEATHLESS_CHATTERS = array('operator','admin','micha','superman','tux');

/*
 * Words which are forbidden in the chat
 */
$NONO_WORDS = array('asshole','fuck');

/*
 * If you want to integrate your PHPOpenChat-Installation
 * into an other PHP-based application with it's own account
 * management, you have to define an entry-channel, which the chatter
 * will join automatically.
 * NOTE: This channel name MUST exist!
 */
define('ENTRY_CHANNEL','default');
define('AUTOLOGIN_DIRECTLY', false);//if is set to false, ENTRY_CHANNEL doesn't matter

/*
 * here you can define a channel which are selected per
 * default within the login form
 */
define('CHANNEL_SELECTED','default');

/*
 * Every chat client polls lines from the server.
 * Setup the sleep time for clients here.
 * NOTE: The more time, the better the load of server! But, you know,
 * your chatters must wait this time for new lines!
 */
define('LINE_POLLING_INTERVAL', 8);//Time in seconds.

/*
 * After a while without activity, a client will be disconnected
 * automatically.
 * Define a maximum of inactive time, after the client will be disconnected.
 */
define('MAX_INACTIVE_ONLINETIME', 600);//Time in seconds

define('MAX_INACTIVE_LIFETIME', 60);//Time in days

/*
 * There are two possibilities for the IRC-command /query
 * first: inviting to the own private channel
 * second: opening a chat request in a separat window
 */
define('IRC_QUERY_OPENS_WINDOW',true);

/*
 * Set this true and all emoticons will be replaced by an image.
 */
define('SMILEYS_AS_IMAGES', true);

/*
 * Max count of images per line
 */
define('MAX_SMILEYS_PER_LINE', 3);

/*
 * Enables a bigger window containing more icons
 */
define('OFFER_MORE_ICONS', true);
 
/*
 * Set this true and user are able to upload private
 * images. Users can use this images by enter ':me' or ':you'
 * within the chat.
 */
define('ALLOW_PRIVATE_IMAGES', true);

define('SHOW_GENDER_ICON',true);

/*
 * Max bytes of private image
 */
define('PRIVATE_IMG_MAX_BYTES', 20000);

/*
 * Max image height in pixels
 */
define('PRIVATE_IMG_SIZE_X', 16);

/*
 * Max image width in pixels
 */
define('PRIVATE_IMG_SIZE_Y', 16);

/*
 * Accepted mime types for private image
 */
$ACCEPTED_MIME_TYPES = array('image/gif','image/png','image/x-png');//for private images used by chatters by typing ':me' or ':you' within the chat

/*
 * Save mode for private images
 * 1: overwrite mode
 * 2: do nothing if exists, highest protection
 */
define('PRIVATE_IMG_SAVE_MODE', 1);

/*
 * used in profile
 */
define('MIN_BIRTHDAY_YEAR', 1930);

/*
 * Minimum length of a mail body
 */
define('MIN_MAIL_LENGTH', 3);//in characters

/*
 * Maximum length of a note
 */
define('MAX_NOTE_SIZE', 1024);//in bytes

/*
 * Colum count of chatter table on chat home page
 */
define('COL_COUNT_CHATTER_LIST', 3);

/*
 * Show ranking icons
 *
 */
define('SHOW_GRADE_ICONS',true);

/*
 * Multiple line input
 *
 * true: chatters are able to insert more than only one line, this means the chatters can submit line breaks
 * false: chatters can't send line breaks
 */
define('MULTIPLE_LINE_INPUT',false);

/*
 * Limits for the ranking system
 *
 * line count / days since registration = lines per day
 * five logins per week = (5 / 7 = 0.7)
 * over-all online time in hours
 * Grade 'GRADE_ROOKIE' is default
 */
$GRADES = array(
  //50 lines averaged per day (since registration); 0,1 logins per week; over-all online time in hours
  'GRADE_MEMBER' => array('50' , 0.1, 10),
  'GRADE_REGULAR'=> array('100', 0.4, 50),
  'GRADE_ELITE'  => array('200', 0.7, 100),
);

/*
 * Content caching
 *
 * Cached pages:    max. cache life time:
 * - HomePage       2  minutes
 * - Administration 1  week
 * - UserPage       10 minutes
 * - Registration   1  month
 * - RegularsPage   1  day
 * - Help           1  month
 */
define('CACHE_ENGINE', false);
define('DEFAULT_CACHE_LIFE_TIME', 86400);//in seconds (one day = 86400 sec.)

define('HTML_BEFORE_LINE','');
define('HTML_AFTER_LINE','');

/* It's not necessary to setup things below this line */
/*
 * see your system's logfile for log messages! (Linux: /var/log/messages)
 */
define('NO_LOGGING', true);

define('LOG_POC_INFOS', true);
define('LOG_POC_LINES', true);
define('LOG_POC_DEBUG', true);
define('LOG_POC_WARNING', true);
define('LOG_POC_ERROR', true);
define('LOG_POC_EMERG', true);

//channel related
define('CB_MAX_LINE', 50); // channel buffer maximum line number.
                          // Depends on db-scheme, if CHANNEL_BUFFER_TYPE = 'DB'!

define('NL',"\r\n");
define('TAB',"\t");
define('FATAL', E_USER_ERROR);
define('ERROR', E_USER_WARNING);
define('WARNING', E_USER_NOTICE);
define('POC_SESSION_ERROR',1);
define('POC_DB_ERROR',2);

//set version information
include_once(POC_BASE.'/Version.php');
?>