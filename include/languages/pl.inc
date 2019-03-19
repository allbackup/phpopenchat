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
  $Source: /cvsroot/phpopenchat/chat3/include/languages/pl.inc,v $
  $Revision: 1.1.2.3 $
*/

/**
* polish language file
* 
* defines constants for an english language interface
* 
* @author Piotrr Koski <piotr.koski@comserwis.pl>
* @version $Id: pl.inc,v 1.1.2.3 2004/02/12 13:40:42 letreo Exp $
*/

/* * * * * * * * * * CHAT MODULE * * * * * * * * * */
define('CHARACTER_ENCODING','ISO-8859-2');

/**
* title for html header
*/
define('TITLE','PHPOpenChat');

/**
* used within index.php
*/
define('WELCOME','Witamy na czacie!');
define('INTRO','To jest czat, powinienie¶ przeczytaæ <a href="netiquette.php">zasady</a> zanim do³±czysz!');
define('GREETING','Mi³o Ciê ponownie widzieæ!');
define('LOGIN_WELCOME','w celu uzyskania wiêkszej liczby opcji kliknij na u¿ytkownika w prawym górnym rogu.');
define('NICKNAME','Pseudonim');
define('PASSWORD','Has³o');
define('CHANNEL','Kana³');
define('LOGIN','Login');
define('GO','Wejd¼');
define('EXIT_CHAT','Wyj¶cie z czata');
define('FORGOT_PASSWORD','Zapomnia³e¶ has³o?');
define('STORE_ACCOUNT_DATA','zapamiêtaj dane');

/**
* used within chat output/input interface
*/
define('LEAVES_THE_CHAT','opuszcza czat.');
define('LEAVES_THIS_CHANNEL','opuszcza kana³.');
define('IS_TOO_BUSY','jest zbyt zajêty');//nickname in front
define('IS_NOT_ONLINE','jest nieobecny');
define('JOINS_THIS_CHANNEL','do³±cza do kana³u.');
define('JOINS_THE_CHAT','do³±cza do czata.');
define('SAYS_TO','mówi do');
define('WHISPERS_TO','szepcze do');
define('SAY_TO','mówi do');
define('WHISPER_TO','szepcz± do');
define('EVERYBODY','wszystkich');
define('INVITATION_MESSAGE','Zosta³a¶(³e¶) zaproszona(y) na prywatny kana³! Proszê wejd¼ na kana³:');//a channel name follows
define('SPEAK_TO','mów do');
define('WHISPERED','szeptanie');
define('OUTPUT_FILTER','Filtr wyj¶ciowy');
define('PRIVATE','tylko prywatny tekst');
define('BODIES','tylko przyjaciele');
define('SYSTEM_MESSAGES','bez komunikatów systemowych');
define('IGNORE','Ignoruj');
define('INVITE','Zapro¶');
define('CONFIGURE','Konfiguracja');
define('HELP','Pomoc');
define('INFO','Informacja');
define('GUESTS','Go¶cie');
define('EMAIL_US','Napisz do nas');
define('NOTE_ABOUT','Note about');
define('ICON_LIST','Lista u¶miechów');
define('CHOOSE_CHANNEL','Wybierz kana³');
define('CHOOSE_RECIPIENT','Wybierz odbiorcê');
define('ADD_TO_FRIENDLIST','dodaj do listy przyjació³');
define('NO_CLICKETY_CLICK','Sure, I will not clickety click on the send button in the future.');
define('LINE_HAS_BEEN_SENT_TO','twój tekst zosta³ wys³any do');//nickname follows
define('FULL','pe³ny');
define('UNLOCK_CHANNEL','odblokuj kana³');//channel name follows
define('YOU_HAVE_NEW_MAIL','Masz nowego maila!');
define('LOGOUT_SHORTLY','Zostaniesz wkrótce wylogowany z '.CHAT_NAME.' z powodu nieaktywno¶ci! Od¶wie¿yæ?');

/**
* used within ignore-dialog
*/
define('IGNORED','ignorowany');
define('IGNORE_CHATTERS','Ignoruj u¿ytkowników');
define('IGNORED_CHATTER','ignorowany u¿ytkownik');
define('IGNORE_CHATTER','ignoruj u¿ytkownika');
define('UNIGNORE_CHATTER','nie ignoruj u¿ytkownika');
define('UNIGNORED_CHATTER','nie ignorowani u¿ytkownicy');
define('HINT_IGNORE_CHATTERS','Tu mo¿esz ignorowaæ u¿ytkowników.');

/**
* used within invite-dialog
*/
define('INVITE_CHATTERS','Zapro¶ u¿ytkowników');
define('INVITED_CHATTERS','zaproszeni u¿ytkownicy');
define('INVITE_CHATTER','zapro¶ u¿ytkownika');
define('DISINVITE_CHATTER','wypro¶ u¿ytkownika');
define('DISINVITED_CHATTERS','wyproszeni u¿ytkownicy');
define('HINT_INVITE_CHATTERS','Je¶li chcesz porozmawiaæ prywatnie na twoim kanale, you have to invite somebody to dispense access rights to your channel.');

/**
* used within friends-dialog
*/
define('FRIENDS','Przyjaciele');
define('ALL_CHATTERS','wszyscy u¿ytkownicy');
define('ADD_TO_FRIENDS','Dodaj do przyjació³');
define('DEL_FRIEND','Usuñ przyjaciela');
define('HINT_ADD_FRIENDS','W tym oknie dialogowym mo¿esz dodawaæ u¿ytkowników do listy przyjació³.');

/**
* used within mail-dialog
*/
define('MAIL','Poczta');
define('INBOX','Skrzynka odbiorcza');
define('OUTBOX','Skrzynka nadawcza');
define('TRASH','Kosz');
define('COMPOSE','Nowa wiadomo¶æ');
define('REPLY','Odpowiedz');
define('FORWARD','Prze¶lij dalej');
define('SUBJECT','Temat');
define('BODY','Tre¶æ');
define('SEND','Wy¶lij');
define('MAIL_SEND_HINT','Note: The "'.SEND.'"-Button will work only, if you filled in existent nicknames as recipients!');
define('RECIPIENT_HINT','More than one comma separated recipients are allowed.');
define('MOVE_TO_TRASH','Do kosza');
define('GET_MAIL','Pobierz nowe wiadomo¶ci');
define('DELETE_MAIL','Usuñ wiadomo¶æ');
define('SENDER','Nadawca');
define('RECIPIENT','Odbiorca');
define('MAIL_SEND_DATE','Data wys³ania');
define('MAIL_RECEIVED','otrzymane');
define('LAST_TOUCH_RECIPIENT','Potwierdzenie przeczytania');
define('LAST_TOUCH_SENDER','ostatnio otwarte');
define('NO_FRIENDS_FOUND','nie znaleziono przyjació³');
define('NO_SUCH_RECIPIENT_FOUND','Nie znaleziono jednego z odbiorców.');
define('BODY_TO_SHORT','Zawarto¶æ wiadomo¶ci za ma³a.');

/**
* used within help-dialog
*/
define('HELP_TITLE','Pomoc');
define('HELP_HINT','Podpowied¼: zostaw to okno otwarte, czatuj i szukaj komend tutaj');
define('HELP_SUBTITLE1','Instrukcja');
define('HELP_TEASER1','Podstawowe fukcje czata!');
define('HELP_CHANNEL','Kana³: prze³±cza miêdzy kana³ami');
define('HELP_SPEAK','Pole "mów do"/"szeptanie": mów lub szeptaj bezpo¶rednio do u¿ytkownika.');
define('HELP_IGNORE','Menu Ignoruj: Tu mo¿esz ignorowaæ u¿ytkowników.');
define('HELP_INVITE','Menu Zapro¶: Zapro¶ u¿ytkowników na swój prywatny kana³.');
define('HELP_FRIENDS','Menu Przyjaciele: Mo¿esz dodawaæ u¿ytkowników do listy przyjació³, system poka¿e Ci którzy z nich s± aktualnie na czacie.');
define('HELP_CONFIGURE','Menu Konfiguracja: Tu mo¿esz zmieniaæ ustawienia czata, np. kolor.');
define('HELP_MAIL','Menu Poczta: wy¶lij wiadomo¶æ do u¿ytkownika lub sprawd¼ w³asn± skrzynkê.');
define('HELP_HELP','Menu Pomoc: Tu w³a¶nie jeste¶ ...');
define('HELP_SUBTITLE2','Komendy IRC:');
define('HELP_TEASER2','Work in progress ...');
define('HELP_SUBTITLE3','Miny:');
define('HELP_TEASER3','Work in progress ...');

define('SMILEY_CODE','Kod');
define('SMILEY_EXPLANATION','Wyja¶nienie');
define('MORE_SMILEY_CODES','wiêcej kodów');
define('OWN_PRIVATE_IMAGE','Twoja ikonka, za³adowana w profilu');
define('RECIPIENT_PRIVATE_IMAGE','Ikonka twojego rozmówcy');

/**
* Registration
*/
define('REGISTRATION','Rejestracja');
define('FILLOUT_TO_REGISTER','Wype³nij pola');
define('ERROR_NICKNAME','Wybrany pseudonim ju¿ zarejestrowano');
define('ERROR_PASSWORD','Has³o za krótkie lub puste');
define('ERROR_NAME','Wpisz imiê');
define('ERROR_USER','Nie podale¶ imienia!');
define('ERROR_EMAIL','Z³y format');
define('ERROR_PICTURE_URL','Nie mogê znale¼æ obrazka!');
define('ERROR_COLOR','Z³y format');
define('ERROR_MAIL_HOST','Nie mogê wys³aæ poczty!');
define('NAME','Imiê i Nazwisko');
define('EMAIL','adres e-mail');
define('REGISTER','zarejestruj siê');
define('PICTURE_URL','URL do obrazka');
define('REGISTRATION_SUCCESSFULLY','Zarejestrowa³e¶ siê poprawnie!');
define('LOGIN_NOW','Jeste¶ gotowy do wej¶cia. Je¶li nie zosta³e¶ przekierowany na stronê wej¶ciow± naci¶nij link poni¿ej');
define('CONFIRMATION','Potwierdzenie');
define('STATUS_CONFIRMATION','Status');
define('CONFIRM_SUCCESS','Potwierdzenie ok!');
define('CONFIRM_FAILED','B³±d potwierdzenia');
define('CONFIRMATION_MESSAGE','Dosta³e¶ od nas wiadomo¶æ. Kliknij na link w wiadomo¶ci, ¿eby dokoñczyæ proces rejestracji.');
define('FORGOT_PASSWORD_HINT','Musisz podaæ pseudonim, ¿eby otrzymaæ wiadomo¶æ z has³em.');

/**
* Configuration
*/
define('CONFIGURATION','Konfiguracja');
define('TEXT_COLOR','kolor tekstu');
define('ADVICE','advice');
define('QUIET','no advice');
define('ALERT','window popup');
define('SOUND','zagraj d¼wiêk');
define('SCROLL_SPEED','Prêdko¶æ przesuwania');
define('CHOOSE_SCROLL_SPEED','wybierz prêdko¶æ przesuwania');
define('SWITCH_OFF_IE_CLICK','wy³±cz d¼wiêk klikania w Internet Explorerze!');
define('CHOOSE_THEME','Wybierz schemat');

/**
* Profile
*/
define('PROFILE','mój profil');
define('PERSONAL_DATA','dane osobowe');//a nickname follows
define('CHANGE_PROFILE','Aktualizacja profilu');
define('PROFILE_UPDATA_SUCCESSFUL','Twój profil zosta³ zaktualizowany');
define('PROFILE_UPDATA_NOT_SUCCESSFUL','Twój profil nie zosta³ zaktualizowany');
define('WRONG_MIME_TYPE','Z³y typ pliku');
define('IMG_FILE_TO_BIG','Za du¿y plik');
define('IMG_SIZE_TO_BIG','Za du¿e rozmiary');
define('SIZE_EXPECTED','Oczekiwana wielko¶æ obrazka w pixelach:');//a digit follows
define('PRIVATE_IMAGE','Twoja ikonka');
define('CONFIRMATION_MAIL_SUBJECT','Potwierdzenie rejestracji');
define('CONFIRMATION_MAIL_BODY','To confirm your registration at our chat, click the link below!');
define('ICQ_NUMBER','Numer ICQ');
define('ERROR_ICQ_NUMBER','No ICQ number');
define('AIM_NICKNAME','AIM Nickname');
define('ERROR_AIM_NICKNAME','The AIM nickname is to long.');
define('YIM_NICKNAME','Yahoo! Instant Messenger nick name');
define('ERROR_YIM_NICKNAME','za d³ugi pseudonim.');
define('HOMEPAGE_URL','Strona domowa');
define('ERROR_HOMEPAGE_URL','Nie znaleziono strony domowej.');
define('BIRTHDAY','Data urodzin');
define('ERROR_BIRTHDAY','z³y format');
define('AGE','Wiek');
define('INTERESTS','Zainteresowania');
define('ERROR_INTERESTS','Za d³uga lista zainteresowañ!');
define('MOTTO','Motto');
define('ERROR_MOTTO','Motto za d³ugie!');
define('LINES_PER_DAY','Linii na dzieñ');
define('LOGINS_PER_DAY','Wej¶æ na dzieñ');

/**
* Notes
*/
define('CHATTER_NOTES','Notatki dla u¿ytkownika');//a nickname follows
define('UPDATE_NOTES','Zaktualizuj notatki');
define('NOTES_UPDATED_SUCCESSFULLY','Notatki poprawnie zaktualizowane.');
define('HINT_NOTES','Inni u¿ytkownicy nie mog± odczytywaæ twoich notatek.');
define('NOTES_NOT_UPDATED','Nie mo¿na zaktualizowaæ notatek, prawdopodobnie brak miejsca na twoje notatki.');

/**
* Moderation
*/
define('APPROVE','zatwierd¼');
define('DISAPPROVE','nie zatwierdzaj');
define('MESSAGE_FORWARDED_TO_MODERATOR','wiadomo¶æ zosta³a przes³ana do Moderatora');
define('MODERATOR','Moderator');
define('VIP','VIP');

/**
* Error messages
*/
define('ERROR_WRONG_FORMAT','Dane które przes³a³e¶ s± w z³ym formacie.');

/**
* Jumper
*/
define('JUMP_FAILED','Skok nieudany!');
define('JUMP_ERROR_CONTENT','Unacceptable content on target site found!');
define('JUMP_ERROR_HOST','Nie mogê znale¼æ hosta!');

/**
* IRC-Commands related stuff
*/
define('INLINE_HELP','Pomoc');
define('IRC_COMMAND','Komenda IRC');
define('IRC_EXPLANATION','Wyja¶nienie');
define('IRC_ME','Wy¶wietla twój pseudonim.');
define('IRC_MSG','Wysy³a prywatn± wiadomo¶æ do wybranego u¿ytkownika, tak¿e wtedy gdy jest on na innym kanale.');
define('IRC_NICK','Wysy³a wiadomo¶æ do u¿ytkownika.');
define('IRC_JOIN','Zmienia kana³.');
define('IRC_QUERY','Requests a private chat with specified chatter, who are invited automatically, within your own private channel.');
define('IRC_LOCATE','Szuka u¿ytkownika na czacie.');
define('IRC_IGNORE','Dodaje u¿ytkownika do listy ignorowanych.');
define('IRC_UNIGNORE','Usuwa u¿ytkownika z listy ignorowanych.');
define('IRC_KICK','Wyrzuca u¿ytkownika. Mo¿e byæ u¿ywane tylko przez operatorów.');
define('IRC_BAN','Ban a chatter for the specified period from the current channel. To unban use "/ban nickname 0"! Can be used by operators only.');
define('IRC_HELP','Pokazuje pomoc');
define('IRC_QUIT','Wychodzi z czata.');
define('LOCATED_AT','located at');//a nickname follows, nickname in front of this sentence
define('UNLOCATED','nie znaleziona(y).');//nickname in front of this sentence

/**
* Admin area
*/
define('ADMINISTRATION','Administracja');
define('WELCOME_ADMIN','Panel administracyjny');
define('PUBLIC_CHANNEL','publiczny');
define('MODERATED_CHANNEL','moderowany');
define('PRIVATE_CHANNEL','prywatny');
define('CHANNEL_ADMIN','Administracja Kana³ami');
define('CHATTER_ADMIN','Administracja U¿ytkownikami');
define('ADD_CHANNEL','Utwórz kana³');
define('DEL_CHANNEL','Usuñ kana³');
define('UPDATE_CHANNEL','Zaktualizuj kana³');
define('CHATTER_DELETE_SUCCESS','U¿ytkownik poprawnie usuniêty.');
define('CHATTER_DELETE_FAILED','Nie mo¿na usun±æ u¿ytkownika.');
define('GROUP_UPDATE_SUCCESS','Zmieniono przynale¿no¶æ u¿ytkownika.');
define('GROUP_UPDATE_FAILED','Nie mo¿na zmieniæ przynale¿no¶ci u¿ytkownika.');
define('CHATTER_DISABLED','U¿ytkownik zablokowany');
define('CHATTER_NOT_DISABLED','Nie mo¿na zablokowaæ u¿ytkownika');
define('CHATTER_ENABLED','U¿ytkownik odblokowany');
define('CHATTER_NOT_ENABLED','Nie mo¿na odblokowaæ u¿ytkownika');
define('LAST_CHANNEL','Ostatni kana³');
define('LAST_ACTIVE_TIME','Ostatnio widziany');
define('LAST_HOST','Ostatni host');
define('LAST_IP','Ostatnie IP');
define('LAST_REFERER','last referer');
define('LAST_USER_AGENT','Ostatnio u¿ywany agent');
define('LAST_SESSIONID','Ostatnie ID sesji');
define('REGTIME','Data rejestracji');
define('MOVE_TO_TOP','Przesuñ na górê');
define('SUCCESS_CHANNEL_UPDATE','kana³ poprawnie zaktualizowany.');
define('ERROR_CHANNEL_UPDATE','nie mo¿na zaktualizowaæ kana³u.');

/**
* Confirmation messages
*/
define('CONFIRM_IGNORE','U¿ytkownik poprawnie dodany do listy ignorowanych.');
define('CONFIRM_UNIGNORE','U¿ytkownik poprawnie usuniêty z listy ignorowanych.');
define('CONFIRM_INVITE','U¿ytkownik zaproszony.');
define('CONFIRM_DISINVITE','U¿ytkownik wyproszony.');
define('CONFIRM_FRIEND','U¿ytkownik poprawnie dodany do listy przyjació³.');

/**
* User page
*/
define('USER_PAGE','Tabela u¿ytkownika');
define('USER_SINCE','U¿ytkownik od');//a time statement follows
define('LAST_SEEN','ostatnio widziana(y)');//a time statement follows

/**
* Regulars' table
*/
define('REGULARS',"Tabela statystyczna");
define('REGULARS_HINT','Tu mo¿esz zobaczyæ najbardziej aktywnych u¿ytkowników w danej randze.');
define('SINCE_REGISTRATION','od rejestracji');
define('NOT_FOUND','nie znaleziona(y)');
define('RANK','Ranga');
define('ONLINE_TIME','ilo¶æ dni online');
define('ACCOUNT_DATA','Dane konta');
define('INDIVIDUAL_DATA','Dane osobowe');

/**
* right click menu within the output frame
*/
define('PRIVATE_CHAT_NEW_WINDOW','czat prywatny');

/**
* Who is online window
*/
define('WHO_IS_ONLINE','kto jest online?');
define('CHANGE_CHANNEL','zmieñ kana³');
define('SELECT_NICK','wybierz pseudonim');
define('OPEN_USER_PAGE','otwórz stronê u¿ytkownika');
define('HINT_WHO_IS_ONLINE','Here you find all chatters online in the chat. Use the icons behind every nickname to chat with or to join a channel.');

/**
* Password reminder
*/
define('FORGOT_PASSWD_MAIL_SUBJECT','Twoje has³o do '.TITLE);
define('FORGOT_PASSWD_MAIL_BODY','Ta wiadomo¶c zosta³a do Ciebie wys³ana poniewa¿ poinformowa³e¶ nas o zagubieniu has³a dla '.TITLE);
define('HINT_REG_PASSWORD','Twoje has³o musi mieæ przynajmniej '.PASSWORD_MIN_LENGTH.' znaków.');
define('HINT_REG_NICKNAME','Twój pseudonim mo¿e sk³adaæ siê ze znaków alfanumerycznych jak i spacji.');
define('YOUR_PASSWORD_IS','Twoje has³o to:');//a password follows
define('FORGOT_PASSWD_MAIL_HINT','');
define('RETRIEVE_PASSWORD','Odzyskaj has³o');

/**
* Statistics
*/
define('STATISTICS','Statystyka');
define('ONLINE_COUNT_LAST24h','Online w ostatnich 24h');
define('ONLINE_TIME_AVG','¦redni czas online w minutach na dzieñ');
define('REGISTERED_COUNT','Liczba zarejestrowanych u¿ytkowników');
define('LAST_REGISTERED','Ostatni zarejestrowany u¿ytkownik');
define('MAIL_COUNT','Liczba wiadomo¶ci');
define('UNRED_MAILS','wiadomo¶ci nieprzeczytanych');
define('MAIL_COUNT_LAST_24h','Liczba wiadomo¶ci przez ostatnie 24h');

/**
* context sesitive help
*/
define('HINT_PASSWORD','Wpisz has³o które otrzyma³e¶ e-mailem od nas, ¿eby wej¶æ jako go¶æ pozostaw to pole puste.');
define('HINT_NICKNAME','Musisz siê zarejestrowaæ ¿eby otrzymaæ pseudonim. Zostaw to pole puste ¿ebu wej¶æ jako go¶æ.');
define('HINT_CHANNELS','S± trzy rodzaje kana³ów, <em>moderowane</em>, <em>publiczne</em> i <em>prywatne</em>. Na publicznych kana³ach linie tesktu s± pokazywane bezpo¶rednio, na moderowanych musz± zostaæ zaakceptowane przez moderatora. Prywatne s± pokazywane tylko je¶li siê zalogujesz.');
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
define('GUEST_NICK_PREFIX','Go¶æ');
define('ALL_GUESTS','Go¶cie');
define('SUBMIT','Submit');
define('CANCEL','Cancel');
define('SEARCH','Szukaj');
define('SEARCH_RESULTS','wyniki szukania');
define('ALERT_NEW_LINE','Kto¶ chce z tob± rozmawiaæ');
define('CLOSE_WINDOW','Zamknij okno');
define('GOTO_HOME','Goto home page');
define('CONTACT_HINT','Je¶li masz pytanie, daj nam znaæ!');
define('REALLY_QUESTION','Czy jeste¶ pewien?');
define('CHATTER','U¿ytkownik');
define('OPERATOR','Operator');
define('ADMIN_HINT','To administrate your chat, login as "operator" and click within the input-frame on "'.ADMINISTRATION.'".');
define('IMPORTANT','Wa¿ne');
define('OPERATOR_PASSWORD','Has³o Operatora');
define('MAKE_NOTE','Zapisz has³o operatora');
define('RESTRICT','Szukaj pseudonimów');
define('DENIED_FOR_GUESTS','Nie udostêpnione dla go¶ci!');
define('BANNED_MSG','Your are banned for the chosen channel and so you are kicked into your private channel.');
define('CHATTER_COUNT','u¿ytkowników na czacie');//a digit follows
define('HIDE','ukryj');
define('GENDER','P³eæ');
define('GENDER_NOTE','Mo¿esz wybraæ p³eæ tylko raz!');
define('FEMALE','kobieta');
define('MALE','mê¿czyzna');
define('PAGE_VIEWS','Widoki karty');
define('GRADE','Ranga');
define('GRADE_ROOKIE','¯ó³todziób');
define('GRADE_MEMBER','Cz³onek');
define('GRADE_REGULAR','Zwyk³y');
define('GRADE_ELITE','Elita');
define('GRADE_OPERATOR','Operator/Admin');
define('YOU_ARE_BUSY','Rozmawiasz ju¿ z kim¶ w prywatnym oknie!');
define('CHATTER_IS_BUSY','Niestety u¿ytkownik nie mo¿e z Tob± rozmawiaæ, jest zbyt zajêty.');
define('WANTS_TO_TALK','chce z Tob± rozmawiaæ!');//nickname in front of this
define('DAYS','dni');
define('CHAT','Czat');
define('CHATMAIL','Chat-Mail');
define('NICKNAME_NOT_FOUND','Nie znaleziono pseudonimu.');
define('PASSWORD_HAS_BEEN_SENT','Has³o zosta³o wys³ane');
define('CHOOSE_LANGUAGE','Inny jêzyk');
define('OPTIONAL','opcjonalne');
define('MISCELLANEOUS','pozosta³e');
define('SAVE','Zapisz');
define('DELETE','Usuñ');
define('EDIT','Edycja');
define('CREATE_NEW','utwórz');
define('JS_ALERT','W³±cz JavaScript');
define('HAPPY_BIRTHDAY','Wszystkiego najlepszego w dniu urodzin!');
define('CHOOSEN','wybrany');

/**
 * PostNuke related
 */
define('PN_NOT_LOGGED_IN','B³±d!');
define('PN_HINT_NOT_LOGGED_IN','¯eby wej¶æ na chata musisz siê najpierw zalogowaæ!');
?>
