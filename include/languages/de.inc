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
  $Date: 2004/08/10 10:37:25 $
  $Source: /cvsroot/phpopenchat/chat3/include/languages/de.inc,v $
  $Revision: 1.87.2.12 $
*/

/**
* german language file
* 
* defines constants for a german language interface
* 
* @author Michael Oertel <michael@ortelius.de>
* @version $Id: de.inc,v 1.87.2.12 2004/08/10 10:37:25 letreo Exp $
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
define('WELCOME','Willkommen zu Deiner PHPOpenChat-Installation');
define('INTRO','Dies ist ein Chat, bevor du ihn benutzt, solltest du die geltenden <a href="netiquette.php">Regeln</a> gelesen haben!');
define('GREETING','Schön, dass du wieder da bist!');
define('LOGIN_WELCOME','klicke rechts oben auf einen Chatter, für mehr Optionen.');
define('NICKNAME','Spitzname');
define('PASSWORD','Passwort');
define('CHANNEL','Raum');
define('LOGIN','Anmeldung');
define('GO','Los');
define('EXIT_CHAT','Chat verlassen');
define('FORGOT_PASSWORD','Passwort vergessen?');
define('STORE_ACCOUNT_DATA','Zugangsdaten merken');
define('SPY_THIS_CHANNEL','In diesen Raum reinschauen');

/**
* used within chat output/input interface
*/
define('LEAVES_THE_CHAT','verläßt den Chat.');
define('LEAVES_THIS_CHANNEL','verläßt den Raum.');
define('GOES_TO_CHANNEL','geht in den Raum:');//channel name follows
define('IS_TOO_BUSY','ist zu beschäftigt');
define('IS_NOT_ONLINE','ist nicht online');
define('JOINS_THIS_CHANNEL','betritt den Raum.');
define('JOINS_THE_CHAT','betritt den Chat.');
define('SAYS_TO','sagt zu');
define('WHISPERS_TO','flüstert zu');
define('SAY_TO','sage zu');
define('WHISPER_TO','flüstere zu');
define('EVERYBODY','allen');
define('INVITATION_MESSAGE','Du wurdest in einen privaten Channel eingeladen! Bitte gehe in den Raum:');
define('SPEAK_TO','sag zu');
define('WHISPERED','geflüstert');
define('OUTPUT_FILTER','Ausgabefilter');
define('PRIVATE','Nur Privates');
define('BODIES','Nur Freunde');
define('SYSTEM_MESSAGES','Keine Systemmeldungen');
define('IGNORE','Ignorieren');
define('INVITE','Einladen');
define('CONFIGURE','Konfigurieren');
define('HELP','Hilfe');
define('INFO','Information');
define('GUESTS','Gäste');
define('EMAIL_US','E-Mail an uns');
define('NOTE_ABOUT','Notiz über');
define('ICON_LIST','Smiley-Liste');
define('CHOOSE_CHANNEL','Raum wählen');
define('CHOOSE_RECIPIENT','Empfänger wählen');
define('ADD_TO_FRIENDLIST','in Freundesliste');
define('NO_CLICKETY_CLICK','Nein, ich werde in Zukunft nicht mehr wie wild auf den Send-Knopf klicken.');
define('LINE_HAS_BEEN_SENT_TO','Deine Zeile wurde weitergeleitet an');//nickname follows
define('FULL','voll');
define('UNLOCK_CHANNEL','Aufschließen des Channels');//channel name follows
define('YOU_HAVE_NEW_MAIL','Du hast neue Nachrichten in deinem Postfach!');
define('LOGOUT_SHORTLY','Du wirst bald automatisch aus dem '.CHAT_NAME.' ausgeloggt, weil Du zu lange inaktiv warst! Möchtest Du Auffrischen?');
define('FORBIDDEN_WORD','Hier wurde ein nicht gewünschtes Wort gelöscht.');
define('RELOAD_MAKES_NO_SENSE', 'Ein Reload macht hier keinen Sinn!');
define('FOLLOWING_NOTE_ADDED','Die folgende Notiz wurde hinzugefügt');
define('ADD_SELECTION_TO_NOTES','Selection zu Notizen');

/**
* used within ignore-dialog
*/
define('IGNORED','ignoriert');
define('IGNORE_CHATTERS','Ignorieren von Chattern');
define('IGNORED_CHATTER','ignorierte Chatter');
define('IGNORE_CHATTER','Chatter ignorieren');
define('UNIGNORE_CHATTER','Chatter nicht ignorieren');
define('UNIGNORED_CHATTER','nicht ignorierte Chatter');
define('HINT_IGNORE_CHATTERS','Falls dir im Chat jemand so auf den Wecker geht, dass du von ihm nichts mehr "hören" möchtest, kannst du denjenigen hier ignorieren. Du suchst ihn einfach durch eintragen des Nicks im Eingabefeld und anschließendes ENTER drücken. Im rechten Ergebnisfeld erscheint dann das Suchergebnis mit den Spitznamen zur Suchanfrage. Durch einen Klick auf den entsprechenden Spitznamen (Nicknamen) fügst du ihn zu deiner Ignoreliste hinzu.');

/**
* used within invite-dialog
*/
define('INVITE_CHATTERS','Einladen von Chattern');
define('INVITED_CHATTERS','eingeladene Chatter');
define('INVITE_CHATTER','Chatter einladen');
define('DISINVITE_CHATTER','Chatter ausladen');
define('DISINVITED_CHATTERS','nicht eingeladene Chatter');
define('HINT_INVITE_CHATTERS','Möchtest du innerhalb deines eigenen Channels (Raums) mit ausgesuchten Benutzern chatten, musst du diese hier in deinen privaten Channel einladen. Du suchst sie einfach durch eintragen eines Nicks im Eingabefeld und anschließendes ENTER drücken. Im rechten Ergebnisfeld erscheint dann das Suchergebnis mit den Spitznamen zur Suchanfrage. Durch einen Klick auf den entsprechenden Spitznamen (Nicknamen) lädst du diesen in deinen privaten channel ein.');

/**
* used within friends-dialog
*/
define('FRIENDS','Freunde');
define('ALL_CHATTERS','alle Chatter');
define('ADD_TO_FRIENDS','zu Freunden hinzufügen');
define('DEL_FRIEND','Freund löschen');
define('HINT_ADD_FRIENDS','Hier kannst du Chatter zu deiner Freundesliste hinzufügen.');

/**
* used within mail-dialog
*/
define('MAIL','Post');
define('INBOX','Posteingang');
define('OUTBOX','Postausgang');
define('TRASH','Müll');
define('COMPOSE','Erstellen');
define('REPLY','Antworten');
define('FORWARD','Weiterleiten');
define('SUBJECT','Betreff');
define('BODY','Inhalt');
define('SEND','Senden');
define('MAIL_SEND_HINT','Hinweis: Der "'.SEND.'"-Button funktioniert nur, wenn Du existierende Spitznamen im "To:"-Eingabefeld angegeben hast!');
define('RECIPIENT_HINT','Es können mehr als nur ein Empfänger angegeben werden. Bitte trenne sie durch Kommas.');
define('MOVE_TO_TRASH','In den Müll verschieben');
define('GET_MAIL','Neue Nachrichten abholen');
define('DELETE_MAIL','Lösche Mail');
define('SENDER','Sender');
define('RECIPIENT','Empfänger');
define('MAIL_SEND_DATE','Sendedatum');
define('MAIL_RECEIVED','erhalten');
define('LAST_TOUCH_RECIPIENT','Lesebestätigung');
define('LAST_TOUCH_SENDER','zuletzt gelesen');
define('NO_FRIENDS_FOUND','keine Freunde gefunden');
define('NO_SUCH_RECIPIENT_FOUND','Einer der angegebenen Empfänger konnte nicht gefunden werden.');
define('BODY_TO_SHORT','Der Inhalt Deiner Mail ist zu kurz.');

/**
* used within help-dialog
*/
define('HELP_TITLE','Chat-Hilfe');
define('HELP_HINT','TIP: Dieses Fenster stehen lassen, weiterchatten und hier nachgucken!');
define('HELP_SUBTITLE1','Bedienung und Erklärung:');
define('HELP_TEASER1','An dieser Stelle wird dir die generelle Funktionalität des Chats erklärt. Lies weiter, und werde erleuchtet!');
define('HELP_CHANNEL','Raum: Channel wechseln');
define('HELP_SPEAK','Box "sag zu"/"geflüßtert": Du kannst so jemanden gezielt "ansprechen". Was Du flüsterst, siehst nur Du und der Angesprochene.');
define('HELP_IGNORE','Menüpunkt Ignorieren: "Klicke auf "Ignorieren". So kannst Du wählen, welchen Teilnehmern Du nicht mehr "zuhören" möchtest');
define('HELP_INVITE','Menüpunkt Einladen: Hier kannst Du wählen, welchen Teilnehmern Du Zugang zu Deinem privaten Raum gewährst');
define('HELP_FRIENDS','Menüpunkt Freunde: So kannst du Chatter als Freunde vormerken.');
define('HELP_CONFIGURE','Menüpunkt Konfigurieren: In diesem Bereich hast du die Möglichkeit, deine Chat-Einstellungen wie z.B. Textfarbe usw. zu verändern');
define('HELP_MAIL','Menüpunkt Post: Hier kannst Du einem Chatter eine Nachricht hinterlegen.');
define('HELP_HELP','Menüpunkt Hilfe: Hier befindest Du Dich grade.');
define('HELP_SUBTITLE2','IRC-Kommandos:');
define('HELP_TEASER2','IRC-Kommandos sind in Bearbeitung ...');
define('HELP_SUBTITLE3','Smileys:');
define('HELP_TEASER3','Smileys sind in Bearbeitung ...');

define('SMILEY_CODE','Code');
define('SMILEY_EXPLANATION','Erklärung');
define('MORE_SMILEY_CODES','weitere Codes');
define('OWN_PRIVATE_IMAGE','Das eigene, zuvor über das Profil hochgeladene Icon');
define('RECIPIENT_PRIVATE_IMAGE','Das persönliche Icon des Gesprächspartners');

/**
* Registration
*/
define('REGISTRATION','Registration');
define('FILLOUT_TO_REGISTER','Trage bitte Deine Daten hier ein');
define('ERROR_NICKNAME','Dieser Spitzname existiert bereits oder ist leer.');
define('ERROR_PASSWORD','Das Passwort ist zu kurz oder leer');
define('ERROR_NAME','Es wurde kein Benutzername angegeben');
define('ERROR_EMAIL','Falsches Format der E-Mail-Adresse');
define('ERROR_PICTURE_URL','Kein Bild gefunden');
define('ERROR_COLOR','Falsches Format');
define('ERROR_MAIL_HOST','Konnte keine E-Mail an die angegebene Adresse schicken');
define('NAME','Vor- und Nachname');
define('EMAIL','E-Mailadresse');
define('REGISTER','registriere Dich');
define('PICTURE_URL','URL eines Bildes');
define('REGISTRATION_SUCCESSFULLY','Deine Registrierung war erfolgreich!');
define('LOGIN_NOW','Du kannst Dich jetzt einloggen. Solltest Du nicht automatisch zum Login weitergeleitet werden, klicke bitte auf den nachstehenden Link.');
define('CONFIRMATION','Bestätigung');
define('STATUS_CONFIRMATION','Status');
define('CONFIRM_SUCCESS','Die Bestätigung Deiner Anmeldung war erfolgreich.');
define('CONFIRM_FAILED','Die Bestätigung Deiner Anmeldung war nicht erfolgreich.');
define('CONFIRMATION_MESSAGE','Dir wurde eine E-Mail an die von Dir angegebene Adresse geschickt. Um Deine Registration abzuschließen, musst Du auf den, in der Mail vorhandenen Link klicken!');
define('FORGOT_PASSWORD_HINT','Trage hier den Spitznamen (Nicknamen) ein, mit dem Du Dich registriert hattest. Das zum Spitznamen gehörende Passwort, wird dann an Deine, bei uns eingetragene, E-Mail-Adresse geschickt.');
define('ERROR_EMAIL_REGISTER_COUNT','Du hast zu viele Spitznamen (Nicknamen) unter dieser E-Mailadresse registriert.');

/**
* Configuration
*/
define('CONFIGURATION','Konfiguration');
define('TEXT_COLOR','Textfarbe');
define('ADVICE','Benachrichtigung');
define('QUIET','keine Benachrichtigung');
define('ALERT','Popup-Fenster');
define('SOUND','Sound abspielen');
define('SCROLL_SPEED','Scrollgeschwindigkeit');
define('CHOOSE_SCROLL_SPEED','wähle die Scrollgeschwindigkeit');
define('SCROLL_SPEED_NORMAL','normal');
define('SCROLL_SPEED_FAST','schnell');
define('SCROLL_SPEED_FASTER','schneller');
define('SCROLL_SPEED_OFF','aus');
define('SWITCH_OFF_IE_CLICK','Klick-Sound des Internet Explorers ausschalten!');
define('CHOOSE_THEME','Wähle ein Motiv');
define('CONFIRM_RELOGIN','Du musst Dich neu einloggen, damit die Konfigurationsänderung wirksam wird!');

/**
* Profile
*/
define('PROFILE','Mein Profil');
define('PERSONAL_DATA','Persönliche Daten von');//a nickname follows
define('CHANGE_PROFILE','Profil aktualisieren');
define('PROFILE_UPDATA_SUCCESSFUL','Dein Profil wurde erfolgreich aktualisiert');
define('PROFILE_UPDATA_NOT_SUCCESSFUL','Dein Profil wurde nicht aktualisiert');
define('WRONG_MIME_TYPE','Die Datei ist keine Bilddatei');
define('IMG_FILE_TO_BIG','Die Datei ist zu groß.');
define('IMG_SIZE_TO_BIG','Die Abmaße des Bildes sind zu groß.');
define('SIZE_EXPECTED','Erwartete Bildgröße in Pixeln:');//a digit follows
define('PRIVATE_IMAGE','Privates Bild');
define('CONFIRMATION_MAIL_SUBJECT','Registrationsbestätigung');
define('CONFIRMATION_MAIL_BODY','Zum Bestätigen Deiner Registration bei unserem Chat, klicke bitte auf den untenstehenden Link!');
define('ICQ_NUMBER','ICQ Nummer');
define('ERROR_ICQ_NUMBER','Es wurde keine ICQ-Nummer angegeben');
define('AIM_NICKNAME','AIM Spitzname');
define('ERROR_AIM_NICKNAME','Der AIM Spitzname ist zu lang.');
define('YIM_NICKNAME','Yahoo! Instant Messenger Spitzname');
define('ERROR_YIM_NICKNAME','Der Spitzname ist zu lang.');
define('HOMEPAGE_URL','HomePage');
define('ERROR_HOMEPAGE_URL','keine HomePage gefunden');
define('BIRTHDAY','Geburtstag');
define('ERROR_BIRTHDAY','falsches Format');
define('AGE','Alter');
define('INTERESTS','Interessen');
define('ERROR_INTERESTS','Zu viele Interessen!');
define('MOTTO','Motto');
define('ERROR_MOTTO','Zu langes Motto');
define('LINES_PER_DAY','Zeilen pro Tag');
define('LOGINS_PER_DAY','Logins pro Tag');

/**
* Notes
*/
define('CHATTER_NOTES','Notizen zum Chatter');//a nickname follows
define('UPDATE_NOTES','Notizen speichern');
define('NOTES_UPDATED_SUCCESSFULLY','Deine Notiz wurde erfolgreich gespeichert.');
define('HINT_NOTES','Deine Notizen, die du dir hier zu einem Chatter machst, kannst nur du lesen.');
define('NOTES_NOT_UPDATED','Deine Notizen konnten nicht ergänzt werden. Ein Grund kann sein, dass der Speicherplatz für deine Notizen erschöpft ist.');

/**
* Moderation
*/
define('APPROVE','Freigeben');
define('DISAPPROVE','Verwerfen');
define('MESSAGE_FORWARDED_TO_MODERATOR','Die Nachricht wurde an den Moderator weitergeleitet');
define('MODERATOR','Moderator');
define('VIP','Prominenter');

/**
* Error messages
*/
define('ERROR_WRONG_FORMAT','Die geposteten Daten haben das falsche Format.');

/**
* Jumper
*/
define('JUMP_FAILED','Weiterleitung fehlgeschlagen!');
define('JUMP_ERROR_CONTENT','Inakzeptable Inhalte auf der Ziel-Website gefunden!');
define('JUMP_ERROR_HOST','Der angegebene Server konnte nicht gefunden werden!');

/**
* IRC-Commands related stuff
*/
define('INLINE_HELP','Hilfe');
define('IRC_COMMAND','IRC-Kommando');
define('IRC_EXPLANATION','Erklärung');
define('IRC_ME','Wird mit Deinem Spitznamen ersetzt.');
define('IRC_MSG','Sendet eine geflüßterte Nachricht zum angegebenen Chatter, auch wenn er sich in einem anderen Raum befindet.');
define('IRC_NICK','Sendet eine Nachricht zum angegebenen Chatter.');
define('IRC_JOIN','Wechselt den Raum (channel).');
define('IRC_QUERY','Eröffnet einen privaten Chat im eigenen privaten Raum und läd den angegebenen Chatter dazu ein.');
define('IRC_LOCATE','Sucht nach einem Chatter im Chat.');
define('IRC_IGNORE','Setzt den angegebenen Chatter auf die Ignoreliste.');
define('IRC_UNIGNORE','Löscht den angegebenen Chatter von der Ignoreliste.');
define('IRC_KICK','Kickt den angegebenen Chatter. Nur vom "Operator" nutzbar.');
define('IRC_BAN','Verbannt den angegebenen Chatter für die angegebene Zeit (in Minuten) aus dem aktuellen Raum. Einen Chatter kann man mit "/ban &lt;nickname&gt; 0" sofort wieder zulassen! Nur vom "Operator" nutzbar.');
define('IRC_HELP','Gibt diese Hilfe aus.');
define('IRC_QUIT','Beendet diese Chatsitzung.');
define('LOCATED_AT','gefunden in');//a nickname follows, nickname in front of this sentence
define('UNLOCATED','konnte nicht gefunden werden.');//nickname in front of this sentence

/**
* Admin area
*/
define('ADMINISTRATION','Administration');
define('WELCOME_ADMIN','Administrationsbereich');
define('PUBLIC_CHANNEL','öffentlich');
define('MODERATED_CHANNEL','moderiert');
define('PRIVATE_CHANNEL','privat');
define('CHANNEL_ADMIN','Channel-Administration');
define('CHATTER_ADMIN','Chatter-Administration');
define('ADD_CHANNEL','Channel addieren');
define('DEL_CHANNEL','Channel löschen');
define('UPDATE_CHANNEL','Channel aktualisieren');
define('CHATTER_DELETE_SUCCESS','Chatter wurde erfolgreich gelöscht.');
define('CHATTER_DELETE_FAILED','Chatter konnte nicht gelöscht werden.');
define('GROUP_UPDATE_SUCCESS','Die Gruppenzugehörigkeit des Chatters wurde geändert.');
define('GROUP_UPDATE_FAILED','Die Gruppenzugehörigkeit des Chatters konnte nicht geändert werden.');
define('CHATTER_DISABLED','Der Chatter wurde deaktiviert.');
define('CHATTER_NOT_DISABLED','Der Chatter konnte nicht deaktiviert werden.');
define('CHATTER_ENABLED','Der Chatter wurde aktiviert');
define('CHATTER_NOT_ENABLED','Der Chatter konnte nicht aktiviert werden.');
define('LAST_CHANNEL','Letzter Raum');
define('LAST_ACTIVE_TIME','zuletzt gesehen am');
define('LAST_HOST','letzter Hostname');
define('LAST_IP','letzte IP');
define('LAST_REFERER','letzter Referer');
define('LAST_USER_AGENT','letzter User-Agent');
define('LAST_SESSIONID','letzte Session-Id');
define('REGTIME','Registriert am');
define('MOVE_TO_TOP','an den Anfang setzen');
define('SUCCESS_CHANNEL_UPDATE','Der angegebene Channel wurde erfolgreich aktualisiert.');
define('ERROR_CHANNEL_UPDATE','Der angegebene Channel konnte nicht aktualisiert werden.');

/**
* Confirmation messages
*/
define('CONFIRM_IGNORE','Chatter wurde erfolgreich ignoriert.');
define('CONFIRM_IGNORE_FAILED','Chatter konnte nicht ignoriert werden.');
define('CONFIRM_UNIGNORE','Chatter wurde erfolgreich von der Liste der ignorierten Chatter gestrichen.');
define('CONFIRM_INVITE','Chatter wurde erfolgreich eingeladen.');
define('CONFIRM_DISINVITE','Chatter wurde erfolgreich ausgeladen.');
define('CONFIRM_FRIEND','Chatter wurde erfolgreich zum Freund gemacht.');

/**
* User page
*/
define('USER_PAGE','UserPage');
define('USER_SINCE','Registriert am');//a time statement follows
define('LAST_SEEN','zuletzt gesehen am');//a time statement follows

/**
* Regulars' table
*/
define('REGULARS','Stammtisch');
define('REGULARS_HINT','Hier siehst Du die aktivsten Chatter pro Rang.');
define('SINCE_REGISTRATION','seit Registrierung');
define('NOT_FOUND','konnte nicht gefunden werden');
define('RANK','Gesamtplatzierung');
define('ONLINE_TIME','Gesamt-Onlinetage');
define('ACCOUNT_DATA','Zugangsdaten');
define('INDIVIDUAL_DATA','Persönliche Daten');

/**
* right click menu within the output frame
*/
define('PRIVATE_CHAT_NEW_WINDOW','Privater Chat');

/**
* Who is online window
*/
define('WHO_IS_ONLINE','wer ist online?');
define('CHANGE_CHANNEL','Channel wechseln');
define('SELECT_NICK','wähle Spitznamen');
define('OPEN_USER_PAGE','UserPage öffnen');
define('HINT_WHO_IS_ONLINE','Alle Chatter, die sich zur Zeit im Chat befinden, findest du hier. Benutze die hinter den Spitznamen stehenden Icons, um mit einem bestimmten Chatter zu Chatten oder in seinen Raum zu wechseln.');

/**
* Password reminder
*/
define('FORGOT_PASSWD_MAIL_SUBJECT','Dein Passwort bei '.TITLE);
define('FORGOT_PASSWD_MAIL_BODY','Diese Nachricht wurde Ihnen gesandt, weil Sie uns über den Verlust Ihres Passwortes bei '.TITLE.' informiert haben.');
define('YOUR_PASSWORD_IS','Ihr Password lautet:');//a password follows
define('FORGOT_PASSWD_MAIL_HINT','
FUER DEN FALL, DASS DIESER ANTRAG NICHT VON IHNEN STAMMT:
Jeder kann ohne Kenntnis eines Passwortes einen Antrag auf Zusendung des zu einem Spitznamen gehörenden Passwortes stellen. Das muss so sein, denn es ist für den Fall gedacht, dass Sie Ihr Passwort vergessen haben. Diese Mail bedeutet aber nicht, dass ein Dritter Ihr Passwort kennt. Sie sind der Einzige, der das Passwort zu Ihrem Spitznamen auf Anfrage zugesandt bekommt. Für den Fall, dass Sie Ihr Password nicht angefordert haben, ignorieren Sie diese Mail und benutzen Sie Ihr Passwort wie gewohnt weiter.
');
define('RETRIEVE_PASSWORD','Password zusenden lassen');

/**
* Statistics
*/
define('STATISTICS','Statistiken');
define('ONLINE_COUNT_LAST24h','Letzte 24 Stunden online');
define('ONLINE_TIME_AVG','Durchschnittliche Onlinezeit pro Tag');
define('REGISTERED_COUNT','Registrierte Chatter');
define('LAST_REGISTERED','Letzte Registration');
define('MAIL_COUNT','Mails insgesamt');
define('UNRED_MAILS','ungelesene Mails');
define('MAIL_COUNT_LAST_24h','Mails in den letzten 24h');

/**
* context sesitive help/info
*/
define('HINT_PASSWORD','Gib das Passwort, was Du von uns bei Deiner Registration per Mail zugeschickt bekommen hast hier ein. Du kannst Dich auch als Gast einloggen, dafür lässt Du dieses Eingabefeld einfach leer.');
define('HINT_NICKNAME','Um einen eigenen Spitznamen (Nicknamen) zu bekommen, musst Du Dich registrieren. Du kannst Dich auch als Gast einloggen, dafür lässt Du dieses Eingabefeld einfach leer.');
define('HINT_REG_PASSWORD','Das Passwort muss mindestens '.PASSWORD_MIN_LENGTH.' Zeichen lang sein.');
define('HINT_REG_NICKNAME','Dein Spitzname kann zusätzlich zu alphanumerischen und numerischen Zeichen auch Leerzeichen enthalten.');
define('HINT_CHANNELS','Es gibt drei Arten von Räumen (Channels), <em>öffentliche</em>, <em>moderierte</em> und <em>private</em>. In <em>öffentlichen</em> werden die Zielen direkt angezeigt, in <em>moderierten</em>, müssen sie von Moderatoren freigegeben werden. <em>Private</em> Räume sieht man nur, wenn man in sie eingeladen wurde und online ist.');
define('INFO_RANKING','Sind die erforderlichen Werte für einen Rang erreicht, wird man in diesen erhoben und behält ihn auch dann, wenn die Werte wieder unter die erforderlichen Grenzen fallen.');
define('HINT_ADVICE_QUIET','Du wirst, wenn Du diese Option gewählt hast, weder durch einen Sound noch durch ein kleines Popupfenster darauf aufmerksam gemacht, dass Du angesprochen wurdest');
define('HINT_ADVICE_ALERT','Hast Du diese Option gewählt, wirst Du durch ein <strong>Popupfenster</strong> darauf aufmerksam gemacht, dass Du im Chat direkt angesprochen wurdest.');
define('HINT_ADVICE_SOUND','Hast Du diese Option gewählt, wirst Du durch einen <strong>Soundsignal</strong> darauf aufmerksam gemacht, dass Du im Chat direkt angesprochen wurdest.');

/**
* Guestbook
*/
define('GUESTBOOK','Gästebuch');
define('GUESTBOOK_NEW_ENTRY','Neuen Gästebucheintrag hinzufügen');
define('GUESTBOOK_ENTRY_SAVED','Der neue Gästebucheintrag wurde erfolgreich gespeichert');

/**
* Generic
*/
define('GUEST_NICK_PREFIX','Gast');
define('ALL_GUESTS','Gäste');
define('SUBMIT','Ok');
define('CANCEL','Abbrechen');
define('SEARCH','Suchen');
define('SEARCH_RESULTS','Suchergebnisse');
define('ALERT_NEW_LINE','Du wurdest soeben angesprochen');
define('CLOSE_WINDOW','Fenster schließen');
define('GOTO_HOME','Zur Startseite');
define('CONTACT_HINT','Solltest Du Fragen haben, kannst Du Dich gern an uns wenden!');
define('REALLY_QUESTION','Willst Du das wirklich?');
define('CHATTER','Chatter');
define('OPERATOR','Operator');
define('ADMIN_HINT','Um Deinen Chat zu Verwalten, loge Dich als "operator" ein und klicke dann im Eingabefenster auf "'.ADMINISTRATION.'".');
define('IMPORTANT','Wichtig');
define('OPERATOR_PASSWORD','Das Operator-Passwort');
define('MAKE_NOTE','Dieses Operator-Password bitte notieren');
define('RESTRICT','Nach Spitznamen suchen');
define('DENIED_FOR_GUESTS','Dieser Service steht für Gäste nicht zur Verfügung!');
define('BANNED_MSG','Aus dem gewählten Raum, wurdest Du verbannt und deswegen in Deinen privaten Raum geschickt.');
define('CHATTER_COUNT','Chatter online');//a digit follows
define('HIDE','verstecken');
define('GENDER','Geschlecht');
define('GENDER_NOTE','Du kannst dies nur ein mal angeben!');
define('FEMALE','weiblich');
define('MALE','männlich');
define('PAGE_VIEWS','Page Views');
define('GRADE','Rang');
define('GRADE_ROOKIE','Grünschnabel');
define('GRADE_MEMBER','Mitglied');
define('GRADE_REGULAR','Stammchatter');
define('GRADE_ELITE','Elitechatter');
define('GRADE_OPERATOR','Operator/Admin');
define('YOU_ARE_BUSY','Du unterhälst Dich schon mit jemanden anderen im privaten Fenster!');
define('CHATTER_IS_BUSY','Leider kann sich dieser Chatter mit Dir nicht unterhalten, er ist zu beschäftigt.');
define('WANTS_TO_TALK','möchte sich mit Dir unterhalten!');//nickname in front
define('DAYS','Tage');
define('CHAT','Chat');
define('CHATMAIL','Chat-Mail');
define('NICKNAME_NOT_FOUND','Der angegebene Spitzname konnte nicht gefunden werden.');
define('PASSWORD_HAS_BEEN_SENT','Das Passwort wurde an die eingetragene E-Mail-Adresse geschickt.');
define('CHOOSE_LANGUAGE','Sprache wechseln');
define('OPTIONAL','optional');
define('MISCELLANEOUS','sonstiges');
define('SAVE','Speichern');
define('DELETE','Löschen');
define('EDIT','Bearbeiten');
define('CREATE_NEW','Neuen Eintrag hinzufügen');
define('JS_ALERT','Bitte activiere JavaScript');
define('HAPPY_BIRTHDAY','Herzlichen Glückwunsch zu Deinem Geburtstag!');
define('CHOOSEN','ausgewählt');

/**
 * PostNuke related
 */
define('PN_NOT_LOGGED_IN','Chat-Login fehlgeschlagen!');
define('PN_HINT_NOT_LOGGED_IN','Um in den Chat zu gelangen, musst Du Dich erst anmelden!');
?>