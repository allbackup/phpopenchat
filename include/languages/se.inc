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
  $Source: /cvsroot/phpopenchat/chat3/include/languages/se.inc,v $
  $Revision: 1.1.2.3 $
*/

/**
* english language file
* 
* defines constants for a swedish language interface
* 
* @author Mats Stromberg <ms@network23.net>
* @version $Id: se.inc,v 1.1.2.3 2004/02/12 13:40:42 letreo Exp $
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
define('WELCOME','Välkommen till din PHPOpenChat-Installation');
define('INTRO','Detta är en chat, du bör läsa <a href="netiquette.php">reglerna</a> innan du ansluter!');
define('GREETING','Trevligt att se dig igen!');
define('LOGIN_WELCOME','klicka på en chattare i övre högra hörnet för att få mer information.');
define('NICKNAME','Nick namn');
define('PASSWORD','Lösenord');
define('CHANNEL','Kanal');
define('LOGIN','Logga in');
define('GO','GO');
define('EXIT_CHAT','Lämna chatten');
define('FORGOT_PASSWORD','Glömt ditt lösenord?');
define('STORE_ACCOUNT_DATA','spara kontoinformation');

/**
* used within chat output/input interface
*/
define('LEAVES_THE_CHAT','lämnar chatten.');
define('LEAVES_THIS_CHANNEL','lämnar kanalen.');
define('IS_TOO_BUSY','är för upptagen');//nickname in front
define('IS_NOT_ONLINE','är inte online');
define('JOINS_THIS_CHANNEL','ansluter till kanalen.');
define('JOINS_THE_CHAT','ansluter till chatten.');
define('SAYS_TO','säger till');
define('WHISPERS_TO','viskar till');
define('SAY_TO','säg till');
define('WHISPER_TO','viska till');
define('EVERYBODY','alla');
define('INVITATION_MESSAGE','Du är inbjuden att ansluta till en privat kanal! Var vänlig anslut till kanalen:');//a channel name follows
define('SPEAK_TO','tala till');
define('WHISPERED','viskade');
define('OUTPUT_FILTER','Ut filter');
define('PRIVATE','privat text enbart');
define('BODIES','vänner enbart');
define('SYSTEM_MESSAGES','Inga system meddelanden');
define('IGNORE','Ignorera');
define('INVITE','Bjud in');
define('CONFIGURE','Konfigurera');
define('HELP','Hjälp');
define('INFO','Information');
define('GUESTS','Gäster');
define('EMAIL_US','Maila oss');
define('NOTE_ABOUT','Info om');
define('ICON_LIST','Smiley-Lista');
define('CHOOSE_CHANNEL','Välj kanal');
define('CHOOSE_RECIPIENT','Välj mottagare');
define('ADD_TO_FRIENDLIST','addera till listan vänner');
define('NO_CLICKETY_CLICK','Självklart, Jag kommer inte att klicketi-klicka på Send knappen i fortsättningen.');
define('LINE_HAS_BEEN_SENT_TO','Ditt meddelande har skickats till');//nickname follows
define('FULL','full');
define('UNLOCK_CHANNEL','lås upp kanal');//channel name follows
define('YOU_HAVE_NEW_MAIL','Du har ny e-post!');
define('LOGOUT_SHORTLY','Du kommer att loggas ut inom kort från '.CHAT_NAME.', på grund av inaktivitet! Uppdatera?');

/**
* used within ignore-dialog
*/
define('IGNORED','ignorerad');
define('IGNORE_CHATTERS','Ignorera chattare');
define('IGNORED_CHATTER','ignorad chattarr');
define('IGNORE_CHATTER','ignorera chattare');
define('UNIGNORE_CHATTER','sluta ignorera chattare');
define('UNIGNORED_CHATTER','ej ignorerade chattare');
define('HINT_IGNORE_CHATTERS','Här kan du ignorera störande chattare.');

/**
* used within invite-dialog
*/
define('INVITE_CHATTERS','Bjud in chattare');
define('INVITED_CHATTERS','inbjudna chattare');
define('INVITE_CHATTER','bjud in chattare');
define('DISINVITE_CHATTER','bjud inte in chattare');
define('DISINVITED_CHATTERS','ej inbjudna chattare');
define('HINT_INVITE_CHATTERS','Om du vill prata privat i din egen kanal måste du bjuda in någon för att de skall få access rättigheter till din kanal.');

/**
* used within friends-dialog
*/
define('FRIENDS','Vänner');
define('ALL_CHATTERS','alla chattare');
define('ADD_TO_FRIENDS','Addera till vänner');
define('DEL_FRIEND','Radera vän');
define('HINT_ADD_FRIENDS','I denna dialog kan du lägga till vänner till din vän-lista.');

/**
* used within mail-dialog
*/
define('MAIL','Mail');
define('INBOX','In box');
define('OUTBOX','Ut box');
define('TRASH','Papperskorg');
define('COMPOSE','Skriv nytt');
define('REPLY','Svara');
define('FORWARD','Vidarebefodra');
define('SUBJECT','Ämne');
define('BODY','Text');
define('SEND','Skicka');
define('MAIL_SEND_HINT','OBS: "'.SEND.'"-knappen fungerar enbart om du fyllt i ett existerande nick-namn som mottagare!');
define('RECIPIENT_HINT','Mer än en mottagare tillåstet, separera nick namn med komma.');
define('MOVE_TO_TRASH','Flytta till papperskorgen');
define('GET_MAIL','Hämta nytt meddelande');
define('DELETE_MAIL','Radera mail');
define('SENDER','Avsändare');
define('RECIPIENT','Mottagare');
define('MAIL_SEND_DATE','Skickat datum');
define('MAIL_RECEIVED','mottaget');
define('LAST_TOUCH_RECIPIENT','Läst konfirmation');
define('LAST_TOUCH_SENDER','senast hanterat');
define('NO_FRIENDS_FOUND','inga vänner hittades');
define('NO_SUCH_RECIPIENT_FOUND','En av mottagarna kunde inte hittas.');
define('BODY_TO_SHORT','Innehållet i ditt mail är för kort.');

/**
* used within help-dialog
*/
define('HELP_TITLE','Chat-Hjälp');
define('HELP_HINT','Tips: Lämna detta fönster öppet, chatta och leta efter kommandon här');
define('HELP_SUBTITLE1','Manual');
define('HELP_TEASER1','Här beskrivs basfunktionaliteten i chatten!');
define('HELP_CHANNEL','Kanal: Hoppa mellan tillgängliga kanaler');
define('HELP_SPEAK','Box "says to"/"whispered": Prata eller viska direkt till en chattare.');
define('HELP_IGNORE','Meny Ignore: Här kan du ignorera chattare.');
define('HELP_INVITE','Meny Bjud in: Bjud in chattare till din privata kanal.');
define('HELP_FRIENDS','Meny Vänner: Du kan markera andra chattare som dina vänner, szstemet kommer att visa dig vilka vänner som för stunden är on/offline.');
define('HELP_CONFIGURE','Meny Konfigurera: I denna modul kan du ändra dina inställningar, t.ex. färg mm.');
define('HELP_MAIL','Meny Mail: Skicka ett mail till en chattare samt kolla din egen in-box.');
define('HELP_HELP','Meny Hjälp: Det är var du är just nu ...');
define('HELP_SUBTITLE2','IRC-Kommandon:');
define('HELP_TEASER2','Arbete pågår ...');
define('HELP_SUBTITLE3','Smileys:');
define('HELP_TEASER3','Arbete pågår ...');

define('SMILEY_CODE','Kod');
define('SMILEY_EXPLANATION','Beskrivning');
define('MORE_SMILEY_CODES','fler koder');
define('OWN_PRIVATE_IMAGE','Din egen ikon, uppladdad inom profilen');
define('RECIPIENT_PRIVATE_IMAGE','Din konversationspartners ikon');

/**
* Registration
*/
define('REGISTRATION','Registration');
define('FILLOUT_TO_REGISTER','Fyll i dina data o skicka iväg för att registrera dig');
define('ERROR_NICKNAME','Valt nicknamn finns redan');
define('ERROR_PASSWORD','Lösenordet är för kort eller tomt');
define('ERROR_NAME','Ange ditt namn');
define('ERROR_USER','Inget användarnamn angivet');
define('ERROR_EMAIL','Fel format');
define('ERROR_PICTURE_URL','Hittar inte denna bild');
define('ERROR_COLOR','Fel format');
define('ERROR_MAIL_HOST','Kunde inte skicka mail till angiven host');
define('NAME','Förnamn Efternamn');
define('EMAIL','E-Mail adress');
define('REGISTER','Registrera dig');
define('PICTURE_URL','URL till bild');
define('REGISTRATION_SUCCESSFULLY','Din registrering lyckades!');
define('LOGIN_NOW','Du är nu redo att logga in. Om du inte automatiskt skickas till inloggningssidan klicka på länken nedan');
define('CONFIRMATION','Konfirmera');
define('STATUS_CONFIRMATION','Status');
define('CONFIRM_SUCCESS','Din konfirmering lyckades');
define('CONFIRM_FAILED','Din konfirmering misslyckades');
define('CONFIRMATION_MESSAGE','Du har fått ett e-mail från oss. För att fullfölja registreringen, klicka på länken i detta mail!');
define('FORGOT_PASSWORD_HINT','Du måste fylla i ditt nicknam för att får ditt lösenord skickat.');

/**
* Configuration
*/
define('CONFIGURATION','Konfiguration');
define('TEXT_COLOR','text färg');
define('ADVICE','advice');
define('QUIET','no advice');
define('ALERT','popup fönster');
define('SOUND','spela ljud');
define('SCROLL_SPEED','Scroll hastighet');
define('CHOOSE_SCROLL_SPEED','välj scroll hastighet');
define('SCROLL_SPEED_NORMAL','normal');
define('SCROLL_SPEED_FAST','snabb');
define('SCROLL_SPEED_FASTER','snabbare');
define('SCROLL_SPEED_OFF','av');
define('SWITCH_OFF_IE_CLICK','Stäng av Klick-ljudet i Internet Explorer!');
define('CHOOSE_THEME','Välj tema');

/**
* Profile
*/
define('PROFILE','min profil');
define('PERSONAL_DATA','personliga data');//a nickname follows
define('CHANGE_PROFILE','Uppdatera Profil');
define('PROFILE_UPDATA_SUCCESSFUL','Din profil har uppdaterats');
define('PROFILE_UPDATA_NOT_SUCCESSFUL','Din profil kunde inte uppdateras');
define('WRONG_MIME_TYPE','Denna fil har fel mime typ');
define('IMG_FILE_TO_BIG','Denna fil är för stor');
define('IMG_SIZE_TO_BIG','Dimensionerna är för stora');
define('SIZE_EXPECTED','Bildstorlek i pixels:');//a digit follows
define('PRIVATE_IMAGE','Privat bild');
define('CONFIRMATION_MAIL_SUBJECT','Registrerings konfirmering');
define('CONFIRMATION_MAIL_BODY','För att konfirmera din registrering i vår Chat, klicka på länken nedan!');
define('ICQ_NUMBER','ICQ Nummer');
define('ERROR_ICQ_NUMBER','Inget ICQ nummer');
define('AIM_NICKNAME','AIM Nicknamn');
define('ERROR_AIM_NICKNAME','AIM nicknamnet är för långt.');
define('YIM_NICKNAME','Yahoo! Instant Messenger nick namn');
define('ERROR_YIM_NICKNAME','nicknamnet är för långt.');
define('HOMEPAGE_URL','Hemsida');
define('ERROR_HOMEPAGE_URL','Hittade ingen hemsida.');
define('BIRTHDAY','Födelsedag');
define('ERROR_BIRTHDAY','fel format');
define('AGE','Ålder');
define('INTERESTS','Intressen');
define('ERROR_INTERESTS','Innehållet i intressen för långt!');
define('MOTTO','Motto');
define('ERROR_MOTTO','Motto för långt!');
define('LINES_PER_DAY','Rader per dag');
define('LOGINS_PER_DAY','Inloggningar per dag');

/**
* Notes
*/
define('CHATTER_NOTES','Notiser för chattare');//a nickname follows
define('UPDATE_NOTES','Uppdaterings notiser');
define('NOTES_UPDATED_SUCCESSFULLY','Dina notiser har uppdaterats.');
define('HINT_NOTES','Dina notiser är osynliga för alla andra chattare.');
define('NOTES_NOT_UPDATED','Kunde inte uppdatera dina notiser, möjligen finns det inte utrymme kvar för dina notiser.');

/**
* Moderation
*/
define('APPROVE','godkänn');
define('DISAPPROVE','godkänn ej');
define('MESSAGE_FORWARDED_TO_MODERATOR','Meddelandet har vidarebefodrats till Moderatorn');
define('MODERATOR','Moderator');
define('VIP','VIP');

/**
* Error messages
*/
define('ERROR_WRONG_FORMAT','Informationen du skickat har fel format.');

/**
* Jumper
*/
define('JUMP_FAILED','Hoppet fallerade!');
define('JUMP_ERROR_CONTENT','Oacceptabelt innehåll på angiven website hittad!');
define('JUMP_ERROR_HOST','Host kunde inte hittas!');

/**
* IRC-Commands related stuff
*/
define('INLINE_HELP','Hjälp');
define('IRC_COMMAND','IRC-Kommando');
define('IRC_EXPLANATION','Beskrivning');
define('IRC_ME','Ersätts av ditt Nick namn.');
define('IRC_MSG','Skicka et viskat meddelande till vald chattare, även om han/hon befinner sig i en annan kanal.');
define('IRC_NICK','Skicka ett meddelande till vald chattare.');
define('IRC_JOIN','Byt kanal.');
define('IRC_QUERY','Begär en privat chat med vald chattare, som bjuds in automatiskt, i din privata kanal.');
define('IRC_LOCATE','Söker en chattare i hela chatten oavsett kanal.');
define('IRC_IGNORE','Lägg till vald chattare till din Ignorera lista.');
define('IRC_UNIGNORE','Raderar val chattare från din Ignorera lista.');
define('IRC_KICK','Kickar vald chattare. Kan enbart användas av en Moderator.');
define('IRC_BAN','Bannar en chattare för en specificerad period från aktuell kanal. Får att återställa använd "/ban nickname 0"! Kan enbart användas av en Moderator.');
define('IRC_HELP','Skriv ut denna hjälp.');
define('IRC_QUIT','Avslutar denna chat-session.');
define('LOCATED_AT','befinner sig i');//a channelname follows, nickname in front of this sentence
define('UNLOCATED','kunde inte hittas.');//nickname in front of this sentence

/**
* Admin area
*/
define('ADMINISTRATION','Administration');
define('WELCOME_ADMIN','Administrations area');
define('PUBLIC_CHANNEL','publik');
define('MODERATED_CHANNEL','modererad');
define('PRIVATE_CHANNEL','privat');
define('CHANNEL_ADMIN','Kanal-Administration');
define('CHATTER_ADMIN','Chattar-Administration');
define('ADD_CHANNEL','Skapa kanal');
define('DEL_CHANNEL','Radera kanal');
define('UPDATE_CHANNEL','Uppdatera kanal');
define('CHATTER_DELETE_SUCCESS','Chattare raderad.');
define('CHATTER_DELETE_FAILED','Kunde inte radera chattare.');
define('GROUP_UPDATE_SUCCESS','Grupp-medlemsskapet har ändrats.');
define('GROUP_UPDATE_FAILED','Ändring av grupp-medlemsskapet misslyckades.');
define('CHATTER_DISABLED','Chattare är spärrad');
define('CHATTER_NOT_DISABLED','Kunde inte spärra denna chattare');
define('CHATTER_ENABLED','Chattare aktiverad');
define('CHATTER_NOT_ENABLED','Kunde inte aktivera denna chattare');
define('LAST_CHANNEL','Senaste kanal');
define('LAST_ACTIVE_TIME','Senast aktiv');
define('LAST_HOST','senaste host');
define('LAST_IP','senaste IP');
define('LAST_REFERER','senaste referrer');
define('LAST_USER_AGENT','senaste user agent');
define('LAST_SESSIONID','senaste sessionId');
define('REGTIME','Registrerings datum');
define('MOVE_TO_TOP','Flytta till toppen');
define('SUCCESS_CHANNEL_UPDATE','kanalen uppdaterad.');
define('ERROR_CHANNEL_UPDATE','kunde inte uppdaterakanalen.');

/**
* Confirmation messages
*/
define('CONFIRM_IGNORE','Chattare adderades till ignoreralistan.');
define('CONFIRM_UNIGNORE','Chattare raderad frün ignoreralistan.');
define('CONFIRM_INVITE','Chattare inbjuden.');
define('CONFIRM_DISINVITE','Chattare ej inbjuden.');
define('CONFIRM_FRIEND','Chattare adderades till Vänner listan.');

/**
* User page
*/
define('USER_PAGE','Användarsida');
define('USER_SINCE','Medlem sedan');//a time statement follows
define('LAST_SEEN','senast aktiv');//a time statement follows

/**
* Regulars' table
*/
define('REGULARS',"Stammis' tabell");
define('REGULARS_HINT','Här kan du se de mest aktiva chattarna per ranking.');
define('SINCE_REGISTRATION','sen registrering');
define('NOT_FOUND','kunde inte hittas');
define('RANK','total ranking');
define('ONLINE_TIME','totalt online dagar');
define('ACCOUNT_DATA','Konto info');
define('INDIVIDUAL_DATA','Personlig info');

/**
* right click menu within the output frame
*/
define('PRIVATE_CHAT_NEW_WINDOW','privat chat');

/**
* Who is online window
*/
define('WHO_IS_ONLINE','vem är online?');
define('CHANGE_CHANNEL','byt kanal');
define('SELECT_NICK','välj nick');
define('OPEN_USER_PAGE','äppna användarsida');
define('HINT_WHO_IS_ONLINE','Här hittar du alla chattare som är online i chatten. Använd ikonen efter varje nicknamn för atr chatta med eller ansluta till kanalen.');

/**
* Password reminder
*/
define('FORGOT_PASSWD_MAIL_SUBJECT','Ditt lösenord för '.TITLE);
define('FORGOT_PASSWD_MAIL_BODY','Detta meddelande har skickats till dig då du
har glömt ditt lösenord för '.TITLE);
define('HINT_REG_PASSWORD','Ditt lösenord måste vara minst '.PASSWORD_MIN_LENGTH.' tecken långt.');
define('HINT_REG_NICKNAME','Ditt nicknamn kan innehålla siffror och bokstäver samt även mellanslag.');
define('YOUR_PASSWORD_IS','Ditt lösenord är:');//a password follows
define('FORGOT_PASSWD_MAIL_HINT','
');
define('RETRIEVE_PASSWORD','Hämta ditt lösenord');

/**
* Statistics
*/
define('STATISTICS','Statistik');
define('ONLINE_COUNT_LAST24h','Online de senaste 24h');
define('ONLINE_TIME_AVG','Snitt Onlinetid i minuter per dag');
define('REGISTERED_COUNT','Antal registerade chattare');
define('LAST_REGISTERED','Senast registerad chattare');
define('MAIL_COUNT','Antal Mail');
define('UNRED_MAILS','olästa mail');
define('MAIL_COUNT_LAST_24h','Antal Mail de senaste 24h');

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
define('GUESTBOOK','Gästbok');
define('GUESTBOOK_NEW_ENTRY','Nytt inlägg i gästboken');
define('GUESTBOOK_ENTRY_SAVED','Det nya inlägget har sparats.');

/**
* Generic
*/
define('GUEST_NICK_PREFIX','Gäst');
define('ALL_GUESTS','Gäster');
define('SUBMIT','Skicka');
define('CANCEL','Ångra');
define('SEARCH','Sök');
define('SEARCH_RESULTS','sökresultat');
define('ALERT_NEW_LINE','Någon vill chatta med dig');
define('CLOSE_WINDOW','Stäng fönster');
define('GOTO_HOME','Gå till hemsida');
define('CONTACT_HINT','Om du har frågor kontakta oss!');
define('REALLY_QUESTION','Är du säker?');
define('CHATTER','Chattare');
define('OPERATOR','Operator');
define('ADMIN_HINT','För att administrera chatten, logga in som "operator" och klicka på "'.ADMINISTRATION.'".');
define('IMPORTANT','Viktigt');
define('OPERATOR_PASSWORD','Operator-Lösenord');
define('MAKE_NOTE','Vänligen notera ditt operator-lösenord');
define('RESTRICT','Sök nicknamn');
define('DENIED_FOR_GUESTS','Denna tjänst är inte tillgänglig för gäster!');
define('BANNED_MSG','Du är bannad för den valda kanalen så du skickas till din privata kanal.');
define('CHATTER_COUNT','antal online');//a digit follows
define('HIDE','göm');
define('GENDER','Kön');
define('GENDER_NOTE','Du kan enbart välja kön en gång!');
define('FEMALE','kvinna');
define('MALE','man');
define('PAGE_VIEWS','Page Views');
define('GRADE','Gradering');
define('GRADE_ROOKIE','Rookie');
define('GRADE_MEMBER','Medlem');
define('GRADE_REGULAR','Stammis');
define('GRADE_ELITE','Elit-Chattare');
define('GRADE_OPERATOR','Operatör/Admin');
define('YOU_ARE_BUSY','Du pratar redan med någon annan i det privata fönstret!');
define('CHATTER_IS_BUSY','Tyvärr kan denna chattare inte prata med dig, han/hon är upptagen.');
define('WANTS_TO_TALK','vill prata med dig!');//nickname in front of this
define('DAYS','Dagar');
define('CHAT','Chatta');
define('CHATMAIL','Chat-Mail');
define('NICKNAME_NOT_FOUND','Angivet nicknamn kunde inte hittas.');
define('PASSWORD_HAS_BEEN_SENT','Lösenordet har skickats');
define('CHOOSE_LANGUAGE','Annat språk');
define('OPTIONAL','option');
define('MISCELLANEOUS','generellt');
define('SAVE','Spara');
define('DELETE','Radera');
define('EDIT','Editera');
define('CREATE_NEW','skapa ny');
define('JS_ALERT','Var vänlig o aktivera JavaScript');
define('HAPPY_BIRTHDAY','Ha den äran!');
define('CHOOSEN','vald');

/**
 * PostNuke related
 */
define('PN_NOT_LOGGED_IN','Chat-Login fallerade!');
define('PN_HINT_NOT_LOGGED_IN','För att delta i chatten måste du logga in först!');
?>