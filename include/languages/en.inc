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
  $Date: 2004/08/10 10:37:49 $
  $Source: /cvsroot/phpopenchat/chat3/include/languages/en.inc,v $
  $Revision: 1.86.2.10 $
*/

/**
* english language file
* 
* defines constants for an english language interface
* 
* @author Michael Oertel <michael@ortelius.de>
* @version $Id: en.inc,v 1.86.2.10 2004/08/10 10:37:49 letreo Exp $
*/

/* * * * * * * * * * CHAT MODULE * * * * * * * * * */
define('CHARACTER_ENCODING','ISO-8859-1');

/**
* title for html header
*/
define('TITLE','PHPOpenChat');

/**
* used within index.php
*/
define('WELCOME','Welcome to your PHPOpenChat-Installation');
define('INTRO','This is a chat, you should read the <a href="netiquette.php">rules</a> before you join!');
define('GREETING','Nice to see you again!');
define('LOGIN_WELCOME','click on a chatter in the upper right corner to get more options.');
define('NICKNAME','Nickname');
define('PASSWORD','Password');
define('CHANNEL','Channel');
define('LOGIN','Login');
define('GO','Go');
define('EXIT_CHAT','Exit chat');
define('FORGOT_PASSWORD','Forgot your password?');
define('STORE_ACCOUNT_DATA','store account data');
define('SPY_THIS_CHANNEL','Spy this channel');

/**
* used within chat output/input interface
*/
define('LEAVES_THE_CHAT','leaves the chat.');
define('LEAVES_THIS_CHANNEL','leaves the channel.');
define('GOES_TO_CHANNEL','goes to channel:');//channel name follows
define('IS_TOO_BUSY','is too busy');//nickname in front
define('IS_NOT_ONLINE','is not online');
define('JOINS_THIS_CHANNEL','joins the channel.');
define('JOINS_THE_CHAT','joins the chat.');
define('SAYS_TO','says to');
define('WHISPERS_TO','whispers to');
define('SAY_TO','say to');
define('WHISPER_TO','whisper to');
define('EVERYBODY','everybody');
define('INVITATION_MESSAGE','You are invited to join a private channel! Please go into the channel:');//a channel name follows
define('SPEAK_TO','speak to');
define('WHISPERED','whispered');
define('OUTPUT_FILTER','Output filter');
define('PRIVATE','private text only');
define('BODIES','friends only');
define('SYSTEM_MESSAGES','No system messages');
define('IGNORE','Ignore');
define('INVITE','Invite');
define('CONFIGURE','Configure');
define('HELP','Help');
define('INFO','Information');
define('GUESTS','Guests');
define('EMAIL_US','Email us');
define('NOTE_ABOUT','Note about');
define('ICON_LIST','Smiley-List');
define('CHOOSE_CHANNEL','Choose channel');
define('CHOOSE_RECIPIENT','Choose recipient');
define('ADD_TO_FRIENDLIST','add to friends list');
define('NO_CLICKETY_CLICK','Sure, I will not clickety click on the send button in the future.');
define('LINE_HAS_BEEN_SENT_TO','Your line has been sent to');//nickname follows
define('FULL','full');
define('UNLOCK_CHANNEL','unlock channel');//channel name follows
define('YOU_HAVE_NEW_MAIL','You have new mail!');
define('LOGOUT_SHORTLY','You will be logged out shortly from '.CHAT_NAME.', because of inactivity! Refresh?');
define('FORBIDDEN_WORD','Forbidden word was replaced here.');
define('RELOAD_MAKES_NO_SENSE', 'It makes no sense to reload this frame!');
define('FOLLOWING_NOTE_ADDED','The following note was added successfully');
define('ADD_SELECTION_TO_NOTES','selection to notes');

/**
* used within ignore-dialog
*/
define('IGNORED','ignored');
define('IGNORE_CHATTERS','Ignore chatters');
define('IGNORED_CHATTER','ignored chatter');
define('IGNORE_CHATTER','ignore chatter');
define('UNIGNORE_CHATTER','unignore chatter');
define('UNIGNORED_CHATTER','unignored chatter');
define('HINT_IGNORE_CHATTERS','Here you can ignore harassers.');

/**
* used within invite-dialog
*/
define('INVITE_CHATTERS','Invite chatters');
define('INVITED_CHATTERS','invited chatters');
define('INVITE_CHATTER','invite chatter');
define('DISINVITE_CHATTER','disinvite chatter');
define('DISINVITED_CHATTERS','disinvited chatters');
define('HINT_INVITE_CHATTERS','If you want to talk private within your own channel, you have to invite somebody to dispense access rights to your channel.');

/**
* used within friends-dialog
*/
define('FRIENDS','Friends');
define('ALL_CHATTERS','all chatters');
define('ADD_TO_FRIENDS','Add to friends');
define('DEL_FRIEND','Remove friend');
define('HINT_ADD_FRIENDS','In this dialog you can add friends to your friends list.');

/**
* used within mail-dialog
*/
define('MAIL','Mail');
define('INBOX','Inbox');
define('OUTBOX','Outbox');
define('TRASH','Trash');
define('COMPOSE','Compose');
define('REPLY','Reply');
define('FORWARD','Forward');
define('SUBJECT','Subject');
define('BODY','Body');
define('SEND','Send');
define('MAIL_SEND_HINT','Note: The "'.SEND.'"-Button will work only, if you filled in existent nicknames as recipients!');
define('RECIPIENT_HINT','More than one comma separated recipients are allowed.');
define('MOVE_TO_TRASH','Move to trash');
define('GET_MAIL','Get new messages');
define('DELETE_MAIL','Delete mail');
define('SENDER','Sender');
define('RECIPIENT','Recipient');
define('MAIL_SEND_DATE','Send date');
define('MAIL_RECEIVED','received');
define('LAST_TOUCH_RECIPIENT','Reading confirmation');
define('LAST_TOUCH_SENDER','last touch');
define('NO_FRIENDS_FOUND','no friends found');
define('NO_SUCH_RECIPIENT_FOUND','One of the recipient could not be found.');
define('BODY_TO_SHORT','The content of your mail is to short.');

/**
* used within help-dialog
*/
define('HELP_TITLE','Chat-Help');
define('HELP_HINT','Hint: Leave this Window open, chat and look for commands here');
define('HELP_SUBTITLE1','Manual');
define('HELP_TEASER1','Here we will present you the basic functionality of the chat!');
define('HELP_CHANNEL','Channel: Switch between the channels available');
define('HELP_SPEAK','Box "says to"/"whispered": Speak or wisper directly to a chatter.');
define('HELP_IGNORE','Menu Ignore: Here you can ignore chatters.');
define('HELP_INVITE','Menu Invite: Invite chatters into your private channel.');
define('HELP_FRIENDS','Menu Friends: You can mark other Chatters as your friends, the system will show you, which friend is currently on/offline.');
define('HELP_CONFIGURE','Menu Configure: In this area you can change your preferred chat settings, e.g. color etc.');
define('HELP_MAIL','Menu Mail: Send a mail message to a chatter and check your own inbox.');
define('HELP_HELP','Menu Help: That\'s where you\'re in right now ...');
define('HELP_SUBTITLE2','IRC-Commands:');
define('HELP_TEASER2','Work in progress ...');
define('HELP_SUBTITLE3','Smileys:');
define('HELP_TEASER3','Work in progress ...');

define('SMILEY_CODE','Code');
define('SMILEY_EXPLANATION','Explanation');
define('MORE_SMILEY_CODES','more codes');
define('OWN_PRIVATE_IMAGE','Your own icon, uploaded within the profile');
define('RECIPIENT_PRIVATE_IMAGE','The icon of your conversational partner');

/**
* Registration
*/
define('REGISTRATION','Registration');
define('FILLOUT_TO_REGISTER','Fill in your data and send to register');
define('ERROR_NICKNAME','The choosen nickname exists');
define('ERROR_PASSWORD','The password is too short or empty');
define('ERROR_NAME','Please enter your name');
define('ERROR_USER','No user name given');
define('ERROR_EMAIL','Wrong format');
define('ERROR_PICTURE_URL','Can\'t find this picture');
define('ERROR_COLOR','Wrong format');
define('ERROR_MAIL_HOST','Could not send a mail to the specified host');
define('NAME','First Name Last Name');
define('EMAIL','E-Mail address');
define('REGISTER','register');
define('PICTURE_URL','URL of a picture');
define('REGISTRATION_SUCCESSFULLY','Your registration was successfully!');
define('LOGIN_NOW','You are ready to login now. If you are not forwarded to the login page, please click the link below');
define('CONFIRMATION','Confirmation');
define('STATUS_CONFIRMATION','Status');
define('CONFIRM_SUCCESS','Your confirmation was successfully');
define('CONFIRM_FAILED','Your confirmation failed');
define('CONFIRMATION_MESSAGE','You got an e-mail from us. To complete your registration, please click on the link within this mail!');
define('FORGOT_PASSWORD_HINT','You have to fill in your nickname, to get a mail containing the appendant password.');
define('ERROR_EMAIL_REGISTER_COUNT','You have registered to many nicknames with this email address.');

/**
* Configuration
*/
define('CONFIGURATION','Configuration');
define('TEXT_COLOR','text color');
define('ADVICE','advice');
define('QUIET','no advice');
define('ALERT','window popup');
define('SOUND','play a sound');
define('SCROLL_SPEED','Scroll speed');
define('CHOOSE_SCROLL_SPEED','choose scroll speed');
define('SCROLL_SPEED_NORMAL','normal');
define('SCROLL_SPEED_FAST','fast');
define('SCROLL_SPEED_FASTER','faster');
define('SCROLL_SPEED_OFF','off');
define('SWITCH_OFF_IE_CLICK','Switch off click sound of Internet Explorer!');
define('CHOOSE_THEME','Choose a theme');
define('CONFIRM_RELOGIN','You must relogin for that template change to take effect!');

/**
* Profile
*/
define('PROFILE','my profile');
define('PERSONAL_DATA','personal data');//a nickname follows
define('CHANGE_PROFILE','Update Profile');
define('PROFILE_UPDATA_SUCCESSFUL','Your profile was successfully updated');
define('PROFILE_UPDATA_NOT_SUCCESSFUL','Your profile was not updated');
define('WRONG_MIME_TYPE','The file has a wrong mime type');
define('IMG_FILE_TO_BIG','The file is too big');
define('IMG_SIZE_TO_BIG','The dimensions are too big');
define('SIZE_EXPECTED','Expected image size in pixels:');//a digit follows
define('PRIVATE_IMAGE','Private image');
define('CONFIRMATION_MAIL_SUBJECT','Registration confirmation');
define('CONFIRMATION_MAIL_BODY','To confirm your registration at our chat, click the link below!');
define('ICQ_NUMBER','ICQ Nummer');
define('ERROR_ICQ_NUMBER','No ICQ number');
define('AIM_NICKNAME','AIM Nickname');
define('ERROR_AIM_NICKNAME','The AIM nickname is to long.');
define('YIM_NICKNAME','Yahoo! Instant Messenger nick name');
define('ERROR_YIM_NICKNAME','nickname is to long.');
define('HOMEPAGE_URL','Home Page');
define('ERROR_HOMEPAGE_URL','No home page found.');
define('BIRTHDAY','Birthday');
define('ERROR_BIRTHDAY','wrong format');
define('AGE','Age');
define('INTERESTS','Interests');
define('ERROR_INTERESTS','String of interests to long!');
define('MOTTO','Motto');
define('ERROR_MOTTO','Motto to long!');
define('LINES_PER_DAY','Lines per day');
define('LOGINS_PER_DAY','Logins per day');

/**
* Notes
*/
define('CHATTER_NOTES','Notes for chatter');//a nickname follows
define('UPDATE_NOTES','Update notes');
define('NOTES_UPDATED_SUCCESSFULLY','Your notes has been updated successfully.');
define('HINT_NOTES','Your notes are unreadable for any other chatter.');
define('NOTES_NOT_UPDATED','Could not update your notes, may there is no space left for your notes.');

/**
* Moderation
*/
define('APPROVE','approve');
define('DISAPPROVE','disapprove');
define('MESSAGE_FORWARDED_TO_MODERATOR','Message has been forwarded to the Moderator');
define('MODERATOR','Moderator');
define('VIP','VIP');

/**
* Error messages
*/
define('ERROR_WRONG_FORMAT','Data do you have posted has wrong format.');

/**
* Jumper
*/
define('JUMP_FAILED','Jump failed!');
define('JUMP_ERROR_CONTENT','Unacceptable content on target site found!');
define('JUMP_ERROR_HOST','Host could not be found!');

/**
* IRC-Commands related stuff
*/
define('INLINE_HELP','Help');
define('IRC_COMMAND','IRC-Command');
define('IRC_EXPLANATION','Explanation');
define('IRC_ME','Will be replaced with your nickname.');
define('IRC_MSG','Sends a whispered message to specified chatter, also if he is located in an other channel.');
define('IRC_NICK','Sends a message to specified chatter.');
define('IRC_JOIN','Changes the channel.');
define('IRC_QUERY','Requests a private chat with specified chatter, who are invited automatically, within your own private channel.');
define('IRC_LOCATE','Searches a chatter within the whole chat.');
define('IRC_IGNORE','Adds specified chatter to your ignore list.');
define('IRC_UNIGNORE','Removes specified chatter from your ignore list.');
define('IRC_KICK','Kicks specified chatter. Can be used by operators only.');
define('IRC_BAN','Ban a chatter for the specified period from the current channel. To unban use "/ban nickname 0"! Can be used by operators only.');
define('IRC_HELP','Prints this help.');
define('IRC_QUIT','Quits this chat session.');
define('LOCATED_AT','located at');//a nickname follows, nickname in front of this sentence
define('UNLOCATED','could not be found.');//nickname in front of this sentence

/**
* Admin area
*/
define('ADMINISTRATION','Administration');
define('WELCOME_ADMIN','Administration area');
define('PUBLIC_CHANNEL','public');
define('MODERATED_CHANNEL','moderated');
define('PRIVATE_CHANNEL','private');
define('CHANNEL_ADMIN','Channel-Administration');
define('CHATTER_ADMIN','Chatter-Administration');
define('ADD_CHANNEL','Create channel');
define('DEL_CHANNEL','Delete channel');
define('UPDATE_CHANNEL','Update channel');
define('CHATTER_DELETE_SUCCESS','Chatter removed successfully.');
define('CHATTER_DELETE_FAILED','Could not remove chatter.');
define('GROUP_UPDATE_SUCCESS','The group-membership is changed.');
define('GROUP_UPDATE_FAILED','Change of group-membership failed.');
define('CHATTER_DISABLED','Chatter is disabled');
define('CHATTER_NOT_DISABLED','Could not disable this chatter');
define('CHATTER_ENABLED','Chatter enabled');
define('CHATTER_NOT_ENABLED','Could not enable this chatter');
define('LAST_CHANNEL','Last channel');
define('LAST_ACTIVE_TIME','Last seen');
define('LAST_HOST','last host');
define('LAST_IP','last IP');
define('LAST_REFERER','last referer');
define('LAST_USER_AGENT','last user agent');
define('LAST_SESSIONID','last sessionId');
define('REGTIME','Registration time');
define('MOVE_TO_TOP','Move to top');
define('SUCCESS_CHANNEL_UPDATE','channel update successfully.');
define('ERROR_CHANNEL_UPDATE','could not update channel.');

/**
* Confirmation messages
*/
define('CONFIRM_IGNORE','Chatter successfully added to the ignore list.');
define('CONFIRM_IGNORE_FAILED','Chatter could not added to the ignore list.');
define('CONFIRM_UNIGNORE','Chatter successfully removed from the ignore list.');
define('CONFIRM_INVITE','Chatter successfully invited.');
define('CONFIRM_DISINVITE','Chatter successfully disinvited.');
define('CONFIRM_FRIEND','Chatter successfully added to the friends list.');

/**
* User page
*/
define('USER_PAGE','User page');
define('USER_SINCE','User since');//a time statement follows
define('LAST_SEEN','last seen');//a time statement follows

/**
* Regulars' table
*/
define('REGULARS',"Regulars' table");
define('REGULARS_HINT','Here you see the most active chatters per rank.');
define('SINCE_REGISTRATION','since registration');
define('NOT_FOUND','could not be found');
define('RANK','over all rank');
define('ONLINE_TIME','over all online days');
define('ACCOUNT_DATA','Account data');
define('INDIVIDUAL_DATA','Personal data');

/**
* right click menu within the output frame
*/
define('PRIVATE_CHAT_NEW_WINDOW','private chat');

/**
* Who is online window
*/
define('WHO_IS_ONLINE','who is online?');
define('CHANGE_CHANNEL','change channel');
define('SELECT_NICK','select nick');
define('OPEN_USER_PAGE','open user page');
define('HINT_WHO_IS_ONLINE','Here you find all chatters online in the chat. Use the icons behind every nickname to chat with or to join a channel.');

/**
* Password reminder
*/
define('FORGOT_PASSWD_MAIL_SUBJECT','Your login password for '.TITLE);
define('FORGOT_PASSWD_MAIL_BODY','This message is sent to you because you informed us that
you lost your password for '.TITLE);
define('HINT_REG_PASSWORD','Your password must be at least '.PASSWORD_MIN_LENGTH.' characters long.');
define('HINT_REG_NICKNAME','Your nickname can contain numeric and alphanumeric characters as well as white spaces.');
define('YOUR_PASSWORD_IS','Your password is:');//a password follows
define('FORGOT_PASSWD_MAIL_HINT','
');
define('RETRIEVE_PASSWORD','Retrieve your password');

/**
* Statistics
*/
define('STATISTICS','Statistics');
define('ONLINE_COUNT_LAST24h','Online in the last 24h');
define('ONLINE_TIME_AVG','Online time average in minutes per day');
define('REGISTERED_COUNT','Count of registered chatters');
define('LAST_REGISTERED','Last registered chatter');
define('MAIL_COUNT','Mail count');
define('UNRED_MAILS','unred mails');
define('MAIL_COUNT_LAST_24h','Mail count of the last 24h');

/**
* context sesitive help
*/
define('HINT_PASSWORD','Enter the password what you got by a mail from us. For a guest login leave this input field empty.');
define('HINT_NICKNAME','You must register to get your own nickname. For a guest login leave this input field empty.');
define('HINT_CHANNELS','There are three kinds of channels, <em>moderated</em>, <em>public</em> and <em>private</em>. In public channels, lines are shown directly, in moderated channels, lines must be approved by a moderator. Private channels are shown only, if you are logged in.');
define('INFO_RANKING','If the necessary values for a rank are reached, you are ready for an advancement and you keeps the rank, even if the values fall under the necessary borders in the future.');
define('HINT_ADVICE_QUIET','If you choose this option, you will not be notified if a chatter tries to speak to you.');
define('HINT_ADVICE_ALERT','If you choose this option, you will get an alert within a small <strong>popup window</strong>, if a chatter tries to speak to you.');
define('HINT_ADVICE_SOUND','If you choose this option, you will get an <strong>sound</strong> alert, if a chatter tries to speak to you.');

/**
* Guestbook
*/
define('GUESTBOOK','Guestbook');
define('GUESTBOOK_NEW_ENTRY','Add a new guestbook entry');
define('GUESTBOOK_ENTRY_SAVED','The new guestbook entry has been saved successfully');

/**
* Generic
*/
define('GUEST_NICK_PREFIX','Guest');
define('ALL_GUESTS','Guests');
define('SUBMIT','Submit');
define('CANCEL','Cancel');
define('SEARCH','Search');
define('SEARCH_RESULTS','search results');
define('ALERT_NEW_LINE','Someone wants to chat with you');
define('CLOSE_WINDOW','Close window');
define('GOTO_HOME','Goto home page');
define('CONTACT_HINT','IF you have question, please let us know!');
define('REALLY_QUESTION','You are sure?');
define('CHATTER','Chatter');
define('OPERATOR','Operator');
define('ADMIN_HINT','To administrate your chat, login as "operator" and click within the input-frame on "'.ADMINISTRATION.'".');
define('IMPORTANT','Important');
define('OPERATOR_PASSWORD','The Operator-Password');
define('MAKE_NOTE','Please make a note of your operator-password');
define('RESTRICT','Search nicknames');
define('DENIED_FOR_GUESTS','This service is not available for guests!');
define('BANNED_MSG','Your are banned for the chosen channel and so you are kicked into your private channel.');
define('CHATTER_COUNT','chatters online');//a digit follows
define('HIDE','hide');
define('GENDER','Gender');
define('GENDER_NOTE','You can choose a gender only one time!');
define('FEMALE','female');
define('MALE','male');
define('PAGE_VIEWS','Page Views');
define('GRADE','Grade');
define('GRADE_ROOKIE','Rookie');
define('GRADE_MEMBER','Member');
define('GRADE_REGULAR','Regular');
define('GRADE_ELITE','Elite-Chatter');
define('GRADE_OPERATOR','Operator/Admin');
define('YOU_ARE_BUSY','You talk already with someone else in the private window!');
define('CHATTER_IS_BUSY','Unfortunately this Chatter cannot chat with you, he is too busy.');
define('WANTS_TO_TALK','wants to talk with you!');//nickname in front of this
define('DAYS','Tage');
define('CHAT','Chat');
define('CHATMAIL','Chat-Mail');
define('NICKNAME_NOT_FOUND','The given nickname could not be found.');
define('PASSWORD_HAS_BEEN_SENT','The password has been sent');
define('CHOOSE_LANGUAGE','Other language');
define('OPTIONAL','optional');
define('MISCELLANEOUS','miscellaneous');
define('SAVE','Save');
define('DELETE','Delete');
define('EDIT','Edit');
define('CREATE_NEW','create new');
define('JS_ALERT','Please activate JavaScript');
define('HAPPY_BIRTHDAY','Happy Birthday!');
define('CHOOSEN','choosen');

/**
 * PostNuke related
 */
define('PN_NOT_LOGGED_IN','Chat-Login failed!');
define('PN_HINT_NOT_LOGGED_IN','To join the chat, you have to login first!');
?>