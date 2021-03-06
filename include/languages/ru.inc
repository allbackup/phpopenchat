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
  $Date: 2004/02/12 13:40:42 $
  $Source: /cvsroot/phpopenchat/chat3/include/languages/Attic/ru.inc,v $
  $Revision: 1.1.2.2 $
*/

/**
* russian language file
* 
* defines constants for an russian language interface
* 
* @author Michael Oertel <michael@ortelius.de>
* @version $Id: ru.inc,v 1.1.2.2 2004/02/12 13:40:42 letreo Exp $
*/

/* * * * * * * * * * CHAT MODULE * * * * * * * * * */
define('CHARACTER_ENCODING','windows-1251');

/**
* title for html header
*/
define('TITLE','PHPOpenChat');

/**
* used within index.php
*/
define('WELCOME','����� ���������� �� PHPOpenChat');
define('INTRO','������ ��� �������������� � ���, �������� ����������� ��������� <a href="netiquette.php">�������</a>');
define('GREETING','���� ������� ��� �����!');
define('LOGIN_WELCOME','�������� �� ������, � ������� ������ ����, ��� ������ ���������� ����');
define('NICKNAME','���');
define('PASSWORD','������');
define('CHANNEL','�������');
define('LOGIN','����');
define('GO','������');
define('EXIT_CHAT','�����');
define('FORGOT_PASSWORD','������ ���� ������?');
define('STORE_ACCOUNT_DATA','��������� ��� ������');
//since version 3.1.0

/**
* used within chat output/input interface
*/
define('LEAVES_THE_CHAT','������� ���.');
define('LEAVES_THIS_CHANNEL','������� �������.');
define('GOES_TO_CHANNEL','���� � �������:'); //channel name follows
define('IS_TOO_BUSY','�����'); //nickname in front
define('IS_NOT_ONLINE','�� ��������');
define('JOINS_THIS_CHANNEL','����� � �������.');
define('JOINS_THE_CHAT','����� � ���.');
define('SAYS_TO','�������');
define('WHISPERS_TO','�������� �');
define('SAY_TO','�������� �');
define('WHISPER_TO','��������� �');
define('EVERYBODY','����');
define('INVITATION_MESSAGE','��� ���������� � ��������� �������:'); //a channel name follows
define('SPEAK_TO','�������� �');
define('WHISPERED','�������');
define('OUTPUT_FILTER','������ ���������');
define('PRIVATE','������ �������');
define('BODIES','������ ������');
define('SYSTEM_MESSAGES','��� ���������');
define('IGNORE','������������');
define('INVITE','����������');
define('CONFIGURE','���������');
define('HELP','������');
define('INFO','����������');
define('GUESTS','�����');
define('EMAIL_US','�������� ������');
define('NOTE_ABOUT','�������');
define('ICON_LIST','������');
define('CHOOSE_CHANNEL','������ �������');
define('CHOOSE_RECIPIENT','������ ����������');
define('ADD_TO_FRIENDLIST','�������� � ������ ������');
define('NO_CLICKETY_CLICK','����������� ������������ ������� �� ������.');
define('LINE_HAS_BEEN_SENT_TO','���� ��������� ���� ���������� '); //nickname follows
define('FULL','�����');
define('UNLOCK_CHANNEL','�������������� �������');//channel name follows
define('YOU_HAVE_NEW_MAIL','��������� �����!');
define('LOGOUT_SHORTLY','�� ���� ��������� �� ����� '.CHAT_NAME.' ��-�� ������������! ��������?');
define('FORBIDDEN_WORD','���� ������� ����������� �����.');
define('RELOAD_MAKES_NO_SENSE', '���� ����� ����� �������������� ������������!');
define('FOLLOWING_NOTE_ADDED','������� ������� ���������');
define('ADD_SELECTION_TO_NOTES','�������� � �������');
//since version 3.1.0
define('POC_ABOUT','� PHPOpenChat');
define('HINT_RECIPIENT_AMBIGUOUS','������������� ���! ����������, ������� ����������.');
define('HINT_CHATTERLIST_NICKNAME','������ ����� � ������ ���������� �� ������ ����, ���� ������� ����� ������ - @ , �� ���� ����� �������� ����������, ������� ����� ����������� ����� �� ���� ����.');
define('HINT_CHATTERLIST_ACTIVITY','���������� ������� ������ �������� ��������� �� �������� - #. #### - �������� - ����� ��������, # - ����� ��������.');

/**
* used within ignore-dialog
*/
define('IGNORED','�����������');
define('IGNORE_CHATTERS','������������� �������');
define('IGNORED_CHATTER','�������������� ������');
define('IGNORE_CHATTER','������������ ������');
define('UNIGNORE_CHATTER','���������������');
define('UNIGNORED_CHATTER','��������� ������');
define('HINT_IGNORE_CHATTERS','����� �� ������ ������� ������ ������������ �������.');
//since version 3.1.0

/**
* used within invite-dialog
*/
define('INVITE_CHATTERS','���������� �������');
define('INVITED_CHATTERS','������������ ������');
define('INVITE_CHATTER','���������� ������');
define('DISINVITE_CHATTER','�������� ������');
define('DISINVITED_CHATTERS','�������� ������');
define('HINT_INVITE_CHATTERS','���� �� ������ ���������� � ����������� ��������� �������, �� ������ ���������� ����-���� � ��������� ��� �������������� � ���.');
//since version 3.1.0

/**
* used within friends-dialog
*/
define('FRIENDS','������');
define('ALL_CHATTERS','��� ������');
define('ADD_TO_FRIENDS','�������� � ������');
define('DEL_FRIEND','������� �� ������');
define('HINT_ADD_FRIENDS','� ���� ���� ������� �� ������ �������� ����� � ������ ����� ������.');
//since version 3.1.0

/**
* used within mail-dialog
*/
define('MAIL','�����');
define('INBOX','��������');
define('OUTBOX','���������');
define('TRASH','���������');
define('COMPOSE','������������');
define('REPLY','��������');
define('FORWARD','���������');
define('SUBJECT','����');
define('BODY','�����');
define('SEND','���������');
define('MAIL_SEND_HINT','��������: ������ "'.SEND.'" ��������� ������ �����, ����� �� ������� � ���� ���������� ������������ ���!');
define('RECIPIENT_HINT','����� ������ ��������� �����������, �������� �� ������ ";"');
define('MOVE_TO_TRASH','������� � �������');
define('GET_MAIL','�������� ����� ���������');
define('DELETE_MAIL','������� ���������');
define('SENDER','�����������');
define('RECIPIENT','����������');
define('MAIL_SEND_DATE','���� ��������');
define('MAIL_RECEIVED','�������');
define('RED_MAIL','��������');
define('NEW_MAIL','����� �����');
define('LAST_TOUCH_RECIPIENT','������������� � ���������');
define('LAST_TOUCH_SENDER','�����������');
define('NO_FRIENDS_FOUND','������ �� �������');
define('NO_SUCH_RECIPIENT_FOUND','�����-�� �� ����������� �� ������.');
define('BODY_TO_SHORT','���������� ������ ������ ������� ��������.');
//since version 3.1.0

/**
* used within help-dialog
*/
define('HELP_TITLE','���-������');
define('HELP_HINT','�����: �������� ��� ���� ��������, ��� ����, ����� � ���������� ��������������� � ���� ������������� ����� ���������');
define('HELP_SUBTITLE1','�����������');
define('HELP_TEASER1','����� ������������ ������� ����������� ����!');
define('HELP_CHANNEL','�������: �������� ������� ����� ���������');
define('HELP_SPEAK','������ "�������� �" / "���������": �������� ��� ��������� ��������������� � �������.');
define('HELP_IGNORE','���� ������������: ����� �� ������ ������� ������ ������������ �������.');
define('HELP_INVITE','���� ����������: ����������� ������� � ���� ������ ��������� �������.');
define('HELP_FRIENDS','���� ������: �� ������ ������� ������ ������, ������� ����� ���������� ���, ����� �� ����� ������ �������� ��� ���.');
define('HELP_CONFIGURE','���� ���������: � ���� ������� �� ������ �������� ���� ������ ��������� � ����, ��� �������� ���� ��������� � �.�.');
define('HELP_MAIL','���� �����: ��������� �������� ��������� ������ ������� � ������� ������ ������� ��������� ����� � ����.');
define('HELP_HELP','���� ������: �� ��� ����� ...');
define('HELP_SUBTITLE2','IRC-�������:');
define('HELP_TEASER2','� �������� ���������� ...');
define('HELP_SUBTITLE3','������:');
define('HELP_TEASER3','� �������� ���������� ...');

define('SMILEY_CODE','���');
define('SMILEY_EXPLANATION','����������');
define('MORE_SMILEY_CODES','��� ����');
define('OWN_PRIVATE_IMAGE','���� ����������� ������, ����������� ����� ��� �������');
define('RECIPIENT_PRIVATE_IMAGE','������ ������ �����������');
//since version 3.1.0

/**
* Registration
*/
define('REGISTRATION','�����������');
define('FILLOUT_TO_REGISTER','��������� ���� ������ � ��������� �� �� �����������');
define('ERROR_NICKNAME','��������� ���� ��� ��� ����������');
define('ERROR_PASSWORD','������ ������� �������� ��� ������');
define('ERROR_NAME','����������, ������� ���� ���');
define('ERROR_USER','��� ������������ � ������ ������');
define('ERROR_EMAIL','�������� ������');
define('ERROR_PICTURE_URL','�� ���� ����� ��� ��������');
define('ERROR_COLOR','�������� ������');
define('ERROR_MAIL_HOST','�� ���� ��������� �������� ��������� �� ��������� ����');
define('NAME','��� �������');
define('EMAIL','E-Mail');
define('REGISTER','�����������');
define('PICTURE_URL','URL ��������');
define('REGISTRATION_SUCCESSFULLY','�� ������� ����������������!');
define('LOGIN_NOW','������ �� ������ ��������� ����. ���� ��� ������������� �� ���������� �� �������� �����, ���������� �������� �� ������ ����');
define('CONFIRMATION','�������������');
define('STATUS_CONFIRMATION','������');
define('CONFIRM_SUCCESS','������������� ������� ���������');
define('CONFIRM_FAILED','���� �������������');
define('CONFIRMATION_MESSAGE','�� �������� ����� ���������. ��� ����, ����� ����������� �����������, ����������, �������� �� ������ ����������� � ������ ������!');
define('FORGOT_PASSWORD_HINT','�� ������ ������ ��� ���, ����� �������� �����, ���������� ��� ������� ������.');
//since version 3.1.0

/**
* Configuration
*/
define('CONFIGURATION','���������');
define('TEXT_COLOR','���� ������');
define('ADVICE','���������');
define('QUIET','��� ���������');
define('ALERT','����������� ����');
define('SOUND','�����');
define('SCROLL_SPEED','�������� ���������');
define('CHOOSE_SCROLL_SPEED','�������� �������� ���������');
define('SCROLL_SPEED_NORMAL','����������');
define('SCROLL_SPEED_FAST','������');
define('SCROLL_SPEED_FASTER','����� ������');
define('SCROLL_SPEED_OFF','����');
define('SWITCH_OFF_IE_CLICK','��������� ���� �� ������ � Internet Explorer!');
define('CHOOSE_THEME','����� ����');
//since version 3.1.0
define('DEFINE_LINE_STYLES','���������� ������� ����� ��� ������ �������.');
define('SELECT_STYLES','�������� �����');
define('FONT_COLOR','���� ������');
define('FONT_SIZE',' ������ ������');
define('FONT_FAMILY','�����');
define('FONT_DECORATION','���������� ������');
define('LINE_TO_TEST_STYLES','������� ��� ����� ������ �����.');

/**
* Profile
*/
define('PROFILE','��� �������');
define('PERSONAL_DATA','������������ ������');//a nickname follows
define('CHANGE_PROFILE','�������� �������');
define('PROFILE_UPDATA_SUCCESSFUL','��� ������� ������� ��������');
define('PROFILE_UPDATA_NOT_SUCCESSFUL','������ ��� ���������� �������');
define('WRONG_MIME_TYPE','������������ ��� �����');
define('IMG_FILE_TO_BIG','���� ������� �������');
define('IMG_SIZE_TO_BIG','������ �������� ������� �������');
define('SIZE_EXPECTED','������ �������� � ��������:');//a digit follows
define('PRIVATE_IMAGE','��������� ����');
define('CONFIRMATION_MAIL_SUBJECT','������������� �����������');
define('CONFIRMATION_MAIL_BODY','��� ������������� ����������� �� ����� ����, �������� �� ������ ����!');
define('ICQ_NUMBER','ICQ �����');
define('ERROR_ICQ_NUMBER','��� ICQ ������');
define('AIM_NICKNAME','AIM ���');
define('ERROR_AIM_NICKNAME','AIM ��� ������� �������.');
define('YIM_NICKNAME','Yahoo! ������� ���');
define('ERROR_YIM_NICKNAME','��� ������� �������.');
define('HOMEPAGE_URL','�����');
define('ERROR_HOMEPAGE_URL','������ ��������� �� �������.');
define('BIRTHDAY','���� ��������');
define('ERROR_BIRTHDAY','�������� ������');
define('AGE','�������');
define('INTERESTS','��������');
define('ERROR_INTERESTS','������ "��������" ������� �������!');
define('MOTTO','�����');
define('ERROR_MOTTO','����� ������� �������!');
define('LINES_PER_DAY','��������� � ����');
define('LOGINS_PER_DAY','��������� � ����');
//since version 3.1.0
define('PRIVATE_ICON','������ ��������');

/**
* Notes
*/
define('CHATTER_NOTES','������� � ������');//a nickname follows
define('UPDATE_NOTES','�������� �������');
define('NOTES_UPDATED_SUCCESSFULLY','���� ������� ������� ���������.');
define('HINT_NOTES','���� ������� ����� �� �������, ����� ���.');
define('NOTES_NOT_UPDATED','�� ���� �������� �������, �������� �� ���������� ����� ��� �� ����������.');

/**
* Moderation
*/
define('APPROVE','��������');
define('DISAPPROVE','��������');
define('MESSAGE_FORWARDED_TO_MODERATOR','��������� ���� �������� ����������');
define('MODERATOR','���������');
define('VIP','VIP');
//since version 3.1.0

/**
* Error messages
*/
define('ERROR_WRONG_FORMAT','������, ������� �� �����������, ����� �������� ������.');
//since version 3.1.0

/**
* Jumper
*/
define('JUMP_FAILED','������ ��������!');
define('JUMP_ERROR_CONTENT','������������ ���������� �� ��������� �����!');
define('JUMP_ERROR_HOST','���� �� ������!');
//since version 3.1.0

/**
* IRC-Commands related stuff
*/
define('INLINE_HELP','������');
define('IRC_COMMAND','IRC-�������');
define('IRC_EXPLANATION','��������');
define('IRC_ME','�������� ��� ���.');
define('IRC_MSG','��������� ������� ��������� ���������� ������, ���� ���� �� ��������� � ������ �������.');
define('IRC_NICK','������� ��������� ���������� ������.');
define('IRC_JOIN','������� �������.');
define('IRC_QUERY','������ �� ��������� ��� ���������� ������, ������� ����� ������������� ��������� � ���� ����������� ��������� �������.');
define('IRC_LOCATE','������ ������ �� ����� ����.');
define('IRC_IGNORE','�������� ���������� ������ � ��� ������ ������������.');
define('IRC_UNIGNORE','������� ���������� ������ �� ������ ������ ������������.');
define('IRC_KICK','������� ���������� ������. ����� ���� ������������ ������ ������������.');
define('IRC_BAN','������� ������ �� ������������ ������ �� ������� �������. ��� ������������ ����������� "/ban nickname 0"! ����� ���� ������������ ������ ������������.');
define('IRC_HELP','�������� ������.');
define('IRC_QUIT','����� �� ����.');
define('LOCATED_AT','��������� �');//a nickname follows, nickname in front of this sentence
define('UNLOCATED','�� ������.');//nickname in front of this sentence
//since version 3.1.0
define('CHATTER_IS_AWAY','���� ����� �� ������ ������ ������� keybord!');
define('CHATTERS_AWAY_MSG','�� ������� ��������� ���������:');
define('AFK_MODE_IS_SET','AFK-����� ����������.');
define('AFK_MODE_IS_UNSET','AFK-����� ����.');
define('HINT_YOU_ARE_AFK','�� � AFK-������. ����������� "/back" ��� ��������.');
define('DIE','�����');
define('YOUR_BODDIES','���� boddies');
define('IRC_SHOWBODY','�������� ������ ����� ������.');
define('IRC_ROLL','����� ����. ��� ���������� ����������� "/roll &lt;die count&gt;"');

/**
* Admin area
*/
define('ADMINISTRATION','�����������������');
define('WELCOME_ADMIN','���� �����������������');
define('PUBLIC_CHANNEL','���������');
define('MODERATED_CHANNEL','������������');
define('PRIVATE_CHANNEL','�������');
define('CHANNEL_ADMIN','����������������� ������');
define('CHATTER_ADMIN','����������������� �������');
define('ADD_CHANNEL','������� �������');
define('DEL_CHANNEL','������� �������');
define('UPDATE_CHANNEL','�������� �������');
define('CHATTER_DELETE_SUCCESS','����� ������� ������.');
define('CHATTER_DELETE_FAILED','�� ���� ������� ������.');
define('GROUP_UPDATE_SUCCESS','�������� � ������ ��������.');
define('GROUP_UPDATE_FAILED','������ ��������� �������� � ������.');
define('CHATTER_DISABLED','����� ��������');
define('CHATTER_NOT_DISABLED','�� ���� ��������� ����� ������');
define('CHATTER_ENABLED','����� �������');
define('CHATTER_NOT_ENABLED','�� ���� �������� ����� ������');
define('LAST_CHANNEL','��������� �������');
define('LAST_ACTIVE_TIME','��������� ����������');
define('LAST_HOST','��������� ����');
define('LAST_IP','�������� IP');
define('LAST_REFERER','��������� �������');
define('LAST_USER_AGENT','��������� �������');
define('LAST_SESSIONID','��������� Id ������');
define('REGTIME','����� �����������');
define('MOVE_TO_TOP','�������� �����');
define('SUCCESS_CHANNEL_UPDATE','������� ������� ���������.');
define('ERROR_CHANNEL_UPDATE','�� ���� �������� �������.');
//since version 3.1.0
define('TRAFFIC_STATISTICS','���������� �� �������');
define('LAST_SEVEN_DAYS','��������� 7 ����');
define('LAST_SEVEN_WEEKS','��������� 7 ������');
define('LAST_SEVEN_MONTH','��������� 7 �������');
define('GROUP_MEMBERSHIP_FOR_CHANNEL','���� ������ � �������');//channel name follows

/**
* Confirmation messages
*/
define('CONFIRM_IGNORE','����� ������� �������� � ������ ������������.');
define('CONFIRM_IGNORE_FAILED','���� ����� �� ����� ���� �������� � ������ ������������.');
define('CONFIRM_UNIGNORE','����� ������� ������ �� ������ ������������.');
define('CONFIRM_INVITE','����� ���������.');
define('CONFIRM_DISINVITE','������ ��������.');
define('CONFIRM_FRIEND','����� ������� �������� � ������ ������.');
//since version 3.1.0

/**
* User page
*/
define('USER_PAGE','��������� ������������');
define('USER_SINCE','���� �����������');//a time statement follows
define('LAST_SEEN','��������� ����');//a time statement follows
//since version 3.1.0

/**
* Regulars' table
*/
define('REGULARS',"���������");
define('REGULARS_HINT','�������� �������� ������, � ������� �� ������.');
define('SINCE_REGISTRATION','� ������ �����������');
define('NOT_FOUND','�� ������');
define('RANK','����');
define('ONLINE_TIME','����� ���� � �������');
define('ACCOUNT_DATA','��������� ������');
define('INDIVIDUAL_DATA','������ ������');
//since version 3.1.0

/**
* right click menu within the output frame
*/
define('PRIVATE_CHAT_NEW_WINDOW','������');
//since version 3.1.0

/**
* Who is online window
*/
define('WHO_IS_ONLINE','��� � �������?');
define('CHANGE_CHANNEL','������� �������');
define('SELECT_NICK','������� ���');
define('OPEN_USER_PAGE','������� �������� ������������');
define('HINT_WHO_IS_ONLINE','����� �� ������ ����� ���� ������� ����������� ������ � �������. ����������� ������ ����� ����� ��� ����, ����� ���������� ��� ������� � ������� � ��������� �������.');
//since version 3.1.0

/**
* Password reminder
*/
define('FORGOT_PASSWD_MAIL_SUBJECT','��� ������ ��� '.TITLE);
define('FORGOT_PASSWD_MAIL_BODY','����������� ������ �������� ������ � ����� "'.TITLE.'"');
define('HINT_REG_PASSWORD','��� ������ ������ ���� �� ����� '.PASSWORD_MIN_LENGTH.' ��������.');
define('HINT_REG_NICKNAME','��� ��� ������ ��������� ����� �������� ��� �����.');
define('YOUR_PASSWORD_IS','��� ������:');//a password follows
define('FORGOT_PASSWD_MAIL_HINT','');
define('RETRIEVE_PASSWORD','��������� ������');
//since version 3.1.0

/**
* Statistics
*/
define('STATISTICS','����������');
define('ONLINE_COUNT_LAST24h','� ������� �� ��������� 24�');
define('ONLINE_TIME_AVG','������� ����� � ������� (����� � ����)');
define('REGISTERED_COUNT','����� ����������������� �������');
define('LAST_REGISTERED','��������� ������������������ �����');
define('MAIL_COUNT','����� ���������� ���������');
define('UNRED_MAILS','������������� ���������');
define('MAIL_COUNT_LAST_24h','��������� �� ��������� 24�');
//since version 3.1.0

/**
* context sesitive help
*/
define('HINT_PASSWORD','������� ��� ������. ��� ��������� �����, � ������������� ���������, ���� ������ ������ ���� ������.');
define('HINT_NICKNAME','�� ������ ������������������, ����� ����� ����������� ���.  ��� ��������� �����, � ������������� ���������, ���� ��� ����� ���� ������.');
define('HINT_CHANNELS','���������� ��� ���� ������, <em>������������</em>, <em>���������</em> � <em>���������</em>. � ��������� ������� ���� ��������� ������������ ��������������� � ���, � ������������ ��� ���������� ������ ����� ��������� �����������. ��������� ������� �������� ������ ���, ��� ����� � ��� ������.');
define('INFO_RANKING','���� ����������� �������� ��� ����� ����������, �� � ��� ��� ����������� ��������, ���� ���� � ������� ����� �������� ��������� ������� ������������.');
define('HINT_ADVICE_QUIET','���� �� �������� ��� �����, ��� �� ����� ��������, ���� ����� ����� �������� ���������� � ����.');
define('HINT_ADVICE_ALERT','���� �� �������� ��� �����, �� ������ �������� ���������� ����� <strong>������������ ����</strong>, ���� ����� ����� �������� ���������� � ����.');
define('HINT_ADVICE_SOUND','���� �� �������� ��� �����, �� ������ �������� <strong>��������</strong> ����������, ���� ����� ����� �������� ���������� � ����.');
//since version 3.1.0

/**
* Guestbook
*/
define('GUESTBOOK','��������');
define('GUESTBOOK_NEW_ENTRY','���������� ������ � ��������');
define('GUESTBOOK_ENTRY_SAVED','����� ������ ���� ������� ��������� � �������� �����');
//since version 3.1.0

/**
* Generic
*/
define('GUEST_NICK_PREFIX','�����');
define('ALL_GUESTS','�����');
define('SUBMIT','�����������');
define('CANCEL','��������');
define('SEARCH','�����');
define('SEARCH_RESULTS','��������� ������');
define('ALERT_NEW_LINE','���-�� ����� ���������� � ����');
define('CLOSE_WINDOW','������� ����');
define('GOTO_HOME','� ������');
define('CONTACT_HINT','���� � ��� ���� �������, ���������� ����� ��� �����!');
define('REALLY_QUESTION','�� �������?');
define('CHATTER','�����');
define('OPERATOR','��������');
define('ADMIN_HINT','��� ����������������� ����� ����, ������� ��� "��������" � ������� � ����  "'.ADMINISTRATION.'".');
define('IMPORTANT','�����');
define('OPERATOR_PASSWORD','������ ���������');
define('MAKE_NOTE','����������, ��������� ��� ������ ���������');
define('RESTRICT','������ ���');
define('DENIED_FOR_GUESTS','���� ������ ���������� ��� ������!');
define('BANNED_MSG','� ��� ��� ������� � ������ ������� � so you are kicked into your private channel.');
define('CHATTER_COUNT','������� � �������');//a digit follows
define('HIDE','��������');
define('GENDER','���');
define('GENDER_NOTE','�� ������ �������� ��� ������ ���� ���!');
define('FEMALE','�');
define('MALE','�');
define('PAGE_VIEWS','���������� ��������');
define('GRADE','������');
define('GRADE_ROOKIE','�������');
define('GRADE_MEMBER','�������');
define('GRADE_REGULAR','�����������');
define('GRADE_ELITE','�����');
define('GRADE_OPERATOR','��������/�����');
define('YOU_ARE_BUSY','�� ������ ������������� � ���-�� ��� � ��������� �������!');
define('CHATTER_IS_BUSY','� ���������, ���� ����� �� ����� ���������� � ����, �� ������� �����.');
define('WANTS_TO_TALK','���� ���������� � �����!');//nickname in front of this
define('DAYS','����');
define('CHAT','���');
define('CHATMAIL','�����');
define('NICKNAME_NOT_FOUND','������������� ��� �� ������.');
define('PASSWORD_HAS_BEEN_SENT','������ ��� ������� ���������');
define('CHOOSE_LANGUAGE','������ �����');
define('OPTIONAL','�����������');
define('MISCELLANEOUS','������');
define('SAVE','��������');
define('DELETE','�������');
define('EDIT','�������������');
define('CREATE_NEW','create new');
define('JS_ALERT','����������, ������������� JavaScript');
define('HAPPY_BIRTHDAY','� ���� ��������!');
define('CHOOSEN','������');
//since version 3.1.0

/**
 * PostNuke related
 */
define('PN_NOT_LOGGED_IN','������ ��� ����� � ���!');
define('PN_HINT_NOT_LOGGED_IN','����� �������������� � ����, ������ �� ������ ��������� ����!');
//since version 3.1.0
?>