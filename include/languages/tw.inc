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
  $Source: /cvsroot/phpopenchat/chat3/include/languages/tw.inc,v $
  $Revision: 1.1.2.3 $
*/

/**
* english language file
* 
* defines constants for an english language interface
* 
* @author Michael Oertel <michael@ortelius.de>
* @version $Id: tw.inc,v 1.1.2.3 2004/02/12 13:40:42 letreo Exp $
*/

/* * * * * * * * * * CHAT MODULE * * * * * * * * * */
define('CHARACTER_ENCODING','big5');

/**
* title for html header
*/
define('TITLE','PHPOpenChat');

/**
* used within index.php
*/
define('WELCOME','歡迎光臨 PHPOpenChat-Installation');
define('INTRO','聊天室, 在您開始使用之前, 請先閱讀 <a href="netiquette.php">使用規定</a> !');
define('GREETING','歡迎再次光臨!');
define('LOGIN_WELCOME','click on a chatter in the upper right corner to get more options.');
define('NICKNAME','暱稱');
define('PASSWORD','密碼');
define('CHANNEL','頻道');
define('LOGIN','登錄');
define('GO','Go');
define('EXIT_CHAT','離開聊天室');
define('FORGOT_PASSWORD','忘記密碼?');
define('STORE_ACCOUNT_DATA','記住我的帳號');

/**
* used within chat output/input interface
*/
define('LEAVES_THE_CHAT','離開這個話題');
define('LEAVES_THIS_CHANNEL','離開這個頻道');
define('IS_TOO_BUSY','忙碌中');//username in front
define('IS_NOT_ONLINE','不在線上');
define('JOINS_THIS_CHANNEL','加入此頻道');
define('JOINS_THE_CHAT','加入此話題');
define('SAYS_TO','對');
define('WHISPERS_TO','悄悄對');
define('SAY_TO','對');
define('WHISPER_TO','悄悄說');
//define('EVERYBODY','每一位');
define('EVERYBODY','everybody');
define('INVITATION_MESSAGE','您目前受邀加入一個私人頻道! 請進入此頻道:');//a channel name follows
define('SPEAK_TO','對');
define('WHISPERED','悄悄地');
define('OUTPUT_FILTER','顯示項目');
define('PRIVATE','只顯示私人訊息');
define('BODIES','只限朋友');
define('SYSTEM_MESSAGES','沒有系統訊息');
define('IGNORE','忽略');
define('INVITE','邀請');
define('CONFIGURE','設定');
define('HELP','說明');
define('INFO','相關資訊');
define('GUESTS','訪客');
define('EMAIL_US','Email us');
define('NOTE_ABOUT','Note about');
define('ICON_LIST','表情清單');
define('CHOOSE_CHANNEL','選擇頻道');
define('CHOOSE_RECIPIENT','Choose recipient');
define('ADD_TO_FRIENDLIST','加入朋友清單');
define('NO_CLICKETY_CLICK','Sure, I will not clickety click on the send button in the future.');
define('LINE_HAS_BEEN_SENT_TO','Your line has been sent to');//username follows
define('FULL','full');
define('UNLOCK_CHANNEL','unlock channel');//channel name follows
define('YOU_HAVE_NEW_MAIL','您有新信件!');
define('LOGOUT_SHORTLY','You will be logged out shortly from '.CHAT_NAME.', because of inactivity! Refresh?');

/**
* used within ignore-dialog
*/
define('IGNORED','忽略');
define('IGNORE_CHATTERS','不理她/他們');
define('IGNORED_CHATTER','不理她/他');
define('IGNORE_CHATTER','不理她/他');
define('UNIGNORE_CHATTER','unignore chatter');
define('UNIGNORED_CHATTER','unignored chatter');
define('HINT_IGNORE_CHATTERS','Here you can ignore harassers.');

/**
* used within invite-dialog
*/
define('INVITE_CHATTERS','邀請她/他們');
define('INVITED_CHATTERS','邀請她/他們');
define('INVITE_CHATTER','邀請她/他');
define('DISINVITE_CHATTER','不邀請她/他');
define('DISINVITED_CHATTERS','邀請她/他們');
define('HINT_INVITE_CHATTERS','If you want to talk private within your own channel, you have to invite somebody to dispense access rights to your channel.');

/**
* used within friends-dialog
*/
define('FRIENDS','朋友');
define('ALL_CHATTERS','所有使用者');
define('ADD_TO_FRIENDS','加入朋友');
define('DEL_FRIEND','移除朋友');
define('HINT_ADD_FRIENDS','In this dialog you can add friends to your friends list.');

/**
* used within mail-dialog
*/
define('MAIL','郵件');
define('INBOX','收件夾');
define('OUTBOX','寄件夾');
define('TRASH','垃圾桶');
define('COMPOSE','草稿');
define('REPLY','回覆');
define('FORWARD','轉寄');
define('SUBJECT','主題');
define('BODY','內容');
define('SEND','送出');
define('MAIL_SEND_HINT','Note: The "'.SEND.'"-Button will work only, if you filled in existent usernames as recipients!');
define('RECIPIENT_HINT','More than one comma separated recipients are allowed.');
define('MOVE_TO_TRASH','移進垃圾桶');
define('GET_MAIL','有新信件');
define('DELETE_MAIL','刪除信件');
define('SENDER','寄件者');
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
define('REGISTRATION','註冊');
define('FILLOUT_TO_REGISTER','Fill in your data and send to register');
define('ERROR_USERNAME','The choosen username exists');
define('ERROR_PASSWORD','The password is too short or empty');
define('ERROR_NAME','Please enter your name');
define('ERROR_USER','No user name given');
define('ERROR_EMAIL','格式錯誤');
define('ERROR_PICTURE_URL','Can\'t find this picture');
define('ERROR_COLOR','Wrong format');
define('ERROR_MAIL_HOST','Could not send a mail to the specified host');
define('NAME','姓名');
define('EMAIL','電子郵件');
define('REGISTER','註冊');
define('PICTURE_URL','URL of a picture');
define('REGISTRATION_SUCCESSFULLY','註冊成功!');
define('LOGIN_NOW','You are ready to login now. If you are not forwarded to the login page, please click the link below');
define('CONFIRMATION','確認程序');
define('STATUS_CONFIRMATION','狀態');
define('CONFIRM_SUCCESS','確認通過');
define('CONFIRM_FAILED','確認失敗');
define('CONFIRMATION_MESSAGE','您將收到我們寄發給您的確認信函. 為完成註冊程序, 請點選該信件內的連結!');
define('FORGOT_PASSWORD_HINT','You have to fill in your username, to get a mail containing the appendant password.');

/**
* Configuration
*/
define('CONFIGURATION','設定');
define('TEXT_COLOR','文字顏色');
define('ADVICE','advice');
define('QUIET','no advice');
define('ALERT','window popup');
define('SOUND','play a sound');
define('SCROLL_SPEED','Scroll speed');
define('CHOOSE_SCROLL_SPEED','choose scroll speed');
define('SWITCH_OFF_IE_CLICK','Switch off click sound of Internet Explorer!');
define('CHOOSE_THEME','選擇布景主題');

/**
* Profile
*/
define('PROFILE','個人資料');
define('PERSONAL_DATA','個人資料');//a username follows
define('CHANGE_PROFILE','更新個人資料');
define('PROFILE_UPDATA_SUCCESSFUL','您的個人資料已經成功地更新了');
define('PROFILE_UPDATA_NOT_SUCCESSFUL','您的個人資料更新失敗');
define('WRONG_MIME_TYPE','The file has a wrong mime type');
define('IMG_FILE_TO_BIG','檔案太大嘍');
define('IMG_SIZE_TO_BIG','解析度太高嘍');
define('SIZE_EXPECTED','Expected image size in pixels:');//a digit follows
define('PRIVATE_IMAGE','Private image');
define('CONFIRMATION_MAIL_SUBJECT','Registration confirmation');
define('CONFIRMATION_MAIL_BODY','To confirm your registration at our chat, click the link below!');
define('ICQ_NUMBER','ICQ Nummer');
define('ERROR_ICQ_NUMBER','No ICQ number');
define('AIM_USERNAME','AIM Nickname');
define('ERROR_AIM_USERNAME','The AIM username is to long.');
define('YIM_USERNAME','Yahoo! Instant Messenger nick name');
define('ERROR_YIM_USERNAME','username is to long.');
define('HOMEPAGE_URL','首頁');
define('ERROR_HOMEPAGE_URL','找不到您的首頁.');
define('BIRTHDAY','生日');
define('ERROR_BIRTHDAY','格式錯誤');
define('AGE','年齡');
define('INTERESTS','興趣');
define('ERROR_INTERESTS','您興趣打太多了!');
define('MOTTO','Motto');
define('ERROR_MOTTO','Motto to long!');
define('LINES_PER_DAY','Lines per day');
define('LOGINS_PER_DAY','Logins per day');

/**
* Notes
*/
define('CHATTER_NOTES','Notes for chatter');//a username follows
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
define('IRC_ME','Will be replaced with your username.');
define('IRC_MSG','Sends a whispered message to specified chatter, also if he is located in an other channel.');
define('IRC_NICK','Sends a message to specified chatter.');
define('IRC_JOIN','Changes the channel.');
define('IRC_QUERY','Requests a private chat with specified chatter, who are invited automatically, within your own private channel.');
define('IRC_LOCATE','Searches a chatter within the whole chat.');
define('IRC_IGNORE','Adds specified chatter to your ignore list.');
define('IRC_UNIGNORE','Removes specified chatter from your ignore list.');
define('IRC_KICK','Kicks specified chatter. Can be used by operators only.');
define('IRC_BAN','Ban a chatter for the specified period from the current channel. To unban use "/ban username 0"! Can be used by operators only.');
define('IRC_HELP','Prints this help.');
define('IRC_QUIT','Quits this chat session.');
define('LOCATED_AT','located at');//a username follows, username in front of this sentence
define('UNLOCATED','could not be found.');//username in front of this sentence

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
define('ACCOUNT_DATA','帳戶資料');
define('INDIVIDUAL_DATA','個人資料');

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
define('HINT_WHO_IS_ONLINE','Here you find all chatters online in the chat. Use the icons behind every username to chat with or to join a channel.');

/**
* Password reminder
*/
define('FORGOT_PASSWD_MAIL_SUBJECT','Your login password for '.TITLE);
define('FORGOT_PASSWD_MAIL_BODY','This message is sent to you because you informed us that
you lost your password for '.TITLE);
define('HINT_REG_PASSWORD','Your password must be at least '.PASSWORD_MIN_LENGTH.' characters long.');
define('HINT_REG_USERNAME','Your username can contain numeric and alphanumeric characters as well as white spaces.');
define('YOUR_PASSWORD_IS','Your password is:');//a password follows
define('FORGOT_PASSWD_MAIL_HINT','
');
define('RETRIEVE_PASSWORD','Retrieve your password');

/**
* Statistics
*/
define('STATISTICS','統計');
define('ONLINE_COUNT_LAST24h','二十四小時內上線者');
define('ONLINE_TIME_AVG','Online time average in minutes per day');
define('REGISTERED_COUNT','使用者數目');
define('LAST_REGISTERED','最近註冊的使用者');
define('MAIL_COUNT','信件數量');
define('UNRED_MAILS','unred mails');
define('MAIL_COUNT_LAST_24h','二十四小時內信件數量');

/**
* context sesitive help
*/
define('HINT_PASSWORD','Enter the password what you got by a mail from us. For a guest login leave this input field empty.');
define('HINT_USERNAME','You must register to get your own username. For a guest login leave this input field empty.');
define('HINT_CHANNELS','There are three kinds of channels, <em>moderated</em>, <em>public</em> and <em>private</em>. In public channels, lines are shown directly, in moderated channels, lines must be approved by a moderator. Private channels are shown only, if you are logged in.');
define('INFO_RANKING','If the necessary values for a rank are reached, you are ready for an advancement and you keeps the rank, even if the values fall under the necessary borders in the future.');
define('HINT_ADVICE_QUIET','If you choose this option, you will not be notified if a chatter tries to speak to you.');
define('HINT_ADVICE_ALERT','If you choose this option, you will get an alert within a small <strong>popup window</strong>, if a chatter tries to speak to you.');
define('HINT_ADVICE_SOUND','If you choose this option, you will get an <strong>sound</strong> alert, if a chatter tries to speak to you.');

/**
* Guestbook
*/
define('GUESTBOOK','留言本');
define('GUESTBOOK_NEW_ENTRY','留下我的訊息');
define('GUESTBOOK_ENTRY_SAVED','您輸入的文章已成功地存檔');

/**
* Generic
*/
define('GUEST_NICK_PREFIX','訪客');
define('ALL_GUESTS','訪客');
define('SUBMIT','送出');
define('CANCEL','取消');
define('SEARCH','尋找');
define('SEARCH_RESULTS','搜尋結果');
define('ALERT_NEW_LINE','有人要找妳/你聊天喔');
define('CLOSE_WINDOW','關閉視窗');
define('GOTO_HOME','回聊天室');
define('CONTACT_HINT','IF you have question, please let us know!');
define('REALLY_QUESTION','妳/你確定嗎?');
define('CHATTER','Chatter');
define('OPERATOR','Operator');
define('ADMIN_HINT','To administrate your chat, login as "operator" and click within the input-frame on "'.ADMINISTRATION.'".');
define('IMPORTANT','重要');
define('OPERATOR_PASSWORD','The Operator-Password');
define('MAKE_NOTE','Please make a note of your operator-password');
define('RESTRICT','搜尋使用者');
define('DENIED_FOR_GUESTS','This service is not available for guests!');
define('BANNED_MSG','Your are banned for the chosen channel and so you are kicked into your private channel.');
define('CHATTER_COUNT','目前線上使用者');//a digit follows
define('HIDE','隱藏');
define('GENDER','性別');
define('GENDER_NOTE','您的性別之後將無法修改, 請小心選取!');
define('FEMALE','女性');
define('MALE','男性');
define('PAGE_VIEWS','Page Views');
define('GRADE','階級');
define('GRADE_ROOKIE','新手');
define('GRADE_MEMBER','會員');
define('GRADE_REGULAR','Regular');
define('GRADE_ELITE','菁英');
define('GRADE_OPERATOR','管理者');
define('YOU_ARE_BUSY','You talk already with someone else in the private window!');
define('CHATTER_IS_BUSY','Unfortunately this Chatter cannot chat with you, he is too busy.');
define('WANTS_TO_TALK','wants to talk with you!');//username in front of this
define('DAYS','Tage');
define('CHAT','Chat');
define('CHATMAIL','Chat-Mail');
define('USERNAME_NOT_FOUND','帳號輸入錯誤.');
define('PASSWORD_HAS_BEEN_SENT','密碼已送出');
define('CHOOSE_LANGUAGE','其他語言');
define('OPTIONAL','非必須的');
define('MISCELLANEOUS','其他');
define('SAVE','儲存');
define('DELETE','刪除');
define('EDIT','編輯');
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