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
define('INTRO','To jest czat, powinienie� przeczyta� <a href="netiquette.php">zasady</a> zanim do��czysz!');
define('GREETING','Mi�o Ci� ponownie widzie�!');
define('LOGIN_WELCOME','w celu uzyskania wi�kszej liczby opcji kliknij na u�ytkownika w prawym g�rnym rogu.');
define('NICKNAME','Pseudonim');
define('PASSWORD','Has�o');
define('CHANNEL','Kana�');
define('LOGIN','Login');
define('GO','Wejd�');
define('EXIT_CHAT','Wyj�cie z czata');
define('FORGOT_PASSWORD','Zapomnia�e� has�o?');
define('STORE_ACCOUNT_DATA','zapami�taj dane');

/**
* used within chat output/input interface
*/
define('LEAVES_THE_CHAT','opuszcza czat.');
define('LEAVES_THIS_CHANNEL','opuszcza kana�.');
define('IS_TOO_BUSY','jest zbyt zaj�ty');//nickname in front
define('IS_NOT_ONLINE','jest nieobecny');
define('JOINS_THIS_CHANNEL','do��cza do kana�u.');
define('JOINS_THE_CHAT','do��cza do czata.');
define('SAYS_TO','m�wi do');
define('WHISPERS_TO','szepcze do');
define('SAY_TO','m�wi do');
define('WHISPER_TO','szepcz� do');
define('EVERYBODY','wszystkich');
define('INVITATION_MESSAGE','Zosta�a�(�e�) zaproszona(y) na prywatny kana�! Prosz� wejd� na kana�:');//a channel name follows
define('SPEAK_TO','m�w do');
define('WHISPERED','szeptanie');
define('OUTPUT_FILTER','Filtr wyj�ciowy');
define('PRIVATE','tylko prywatny tekst');
define('BODIES','tylko przyjaciele');
define('SYSTEM_MESSAGES','bez komunikat�w systemowych');
define('IGNORE','Ignoruj');
define('INVITE','Zapro�');
define('CONFIGURE','Konfiguracja');
define('HELP','Pomoc');
define('INFO','Informacja');
define('GUESTS','Go�cie');
define('EMAIL_US','Napisz do nas');
define('NOTE_ABOUT','Note about');
define('ICON_LIST','Lista u�miech�w');
define('CHOOSE_CHANNEL','Wybierz kana�');
define('CHOOSE_RECIPIENT','Wybierz odbiorc�');
define('ADD_TO_FRIENDLIST','dodaj do listy przyjaci�');
define('NO_CLICKETY_CLICK','Sure, I will not clickety click on the send button in the future.');
define('LINE_HAS_BEEN_SENT_TO','tw�j tekst zosta� wys�any do');//nickname follows
define('FULL','pe�ny');
define('UNLOCK_CHANNEL','odblokuj kana�');//channel name follows
define('YOU_HAVE_NEW_MAIL','Masz nowego maila!');
define('LOGOUT_SHORTLY','Zostaniesz wkr�tce wylogowany z '.CHAT_NAME.' z powodu nieaktywno�ci! Od�wie�y�?');

/**
* used within ignore-dialog
*/
define('IGNORED','ignorowany');
define('IGNORE_CHATTERS','Ignoruj u�ytkownik�w');
define('IGNORED_CHATTER','ignorowany u�ytkownik');
define('IGNORE_CHATTER','ignoruj u�ytkownika');
define('UNIGNORE_CHATTER','nie ignoruj u�ytkownika');
define('UNIGNORED_CHATTER','nie ignorowani u�ytkownicy');
define('HINT_IGNORE_CHATTERS','Tu mo�esz ignorowa� u�ytkownik�w.');

/**
* used within invite-dialog
*/
define('INVITE_CHATTERS','Zapro� u�ytkownik�w');
define('INVITED_CHATTERS','zaproszeni u�ytkownicy');
define('INVITE_CHATTER','zapro� u�ytkownika');
define('DISINVITE_CHATTER','wypro� u�ytkownika');
define('DISINVITED_CHATTERS','wyproszeni u�ytkownicy');
define('HINT_INVITE_CHATTERS','Je�li chcesz porozmawia� prywatnie na twoim kanale, you have to invite somebody to dispense access rights to your channel.');

/**
* used within friends-dialog
*/
define('FRIENDS','Przyjaciele');
define('ALL_CHATTERS','wszyscy u�ytkownicy');
define('ADD_TO_FRIENDS','Dodaj do przyjaci�');
define('DEL_FRIEND','Usu� przyjaciela');
define('HINT_ADD_FRIENDS','W tym oknie dialogowym mo�esz dodawa� u�ytkownik�w do listy przyjaci�.');

/**
* used within mail-dialog
*/
define('MAIL','Poczta');
define('INBOX','Skrzynka odbiorcza');
define('OUTBOX','Skrzynka nadawcza');
define('TRASH','Kosz');
define('COMPOSE','Nowa wiadomo��');
define('REPLY','Odpowiedz');
define('FORWARD','Prze�lij dalej');
define('SUBJECT','Temat');
define('BODY','Tre��');
define('SEND','Wy�lij');
define('MAIL_SEND_HINT','Note: The "'.SEND.'"-Button will work only, if you filled in existent nicknames as recipients!');
define('RECIPIENT_HINT','More than one comma separated recipients are allowed.');
define('MOVE_TO_TRASH','Do kosza');
define('GET_MAIL','Pobierz nowe wiadomo�ci');
define('DELETE_MAIL','Usu� wiadomo��');
define('SENDER','Nadawca');
define('RECIPIENT','Odbiorca');
define('MAIL_SEND_DATE','Data wys�ania');
define('MAIL_RECEIVED','otrzymane');
define('LAST_TOUCH_RECIPIENT','Potwierdzenie przeczytania');
define('LAST_TOUCH_SENDER','ostatnio otwarte');
define('NO_FRIENDS_FOUND','nie znaleziono przyjaci�');
define('NO_SUCH_RECIPIENT_FOUND','Nie znaleziono jednego z odbiorc�w.');
define('BODY_TO_SHORT','Zawarto�� wiadomo�ci za ma�a.');

/**
* used within help-dialog
*/
define('HELP_TITLE','Pomoc');
define('HELP_HINT','Podpowied�: zostaw to okno otwarte, czatuj i szukaj komend tutaj');
define('HELP_SUBTITLE1','Instrukcja');
define('HELP_TEASER1','Podstawowe fukcje czata!');
define('HELP_CHANNEL','Kana�: prze��cza mi�dzy kana�ami');
define('HELP_SPEAK','Pole "m�w do"/"szeptanie": m�w lub szeptaj bezpo�rednio do u�ytkownika.');
define('HELP_IGNORE','Menu Ignoruj: Tu mo�esz ignorowa� u�ytkownik�w.');
define('HELP_INVITE','Menu Zapro�: Zapro� u�ytkownik�w na sw�j prywatny kana�.');
define('HELP_FRIENDS','Menu Przyjaciele: Mo�esz dodawa� u�ytkownik�w do listy przyjaci�, system poka�e Ci kt�rzy z nich s� aktualnie na czacie.');
define('HELP_CONFIGURE','Menu Konfiguracja: Tu mo�esz zmienia� ustawienia czata, np. kolor.');
define('HELP_MAIL','Menu Poczta: wy�lij wiadomo�� do u�ytkownika lub sprawd� w�asn� skrzynk�.');
define('HELP_HELP','Menu Pomoc: Tu w�a�nie jeste� ...');
define('HELP_SUBTITLE2','Komendy IRC:');
define('HELP_TEASER2','Work in progress ...');
define('HELP_SUBTITLE3','Miny:');
define('HELP_TEASER3','Work in progress ...');

define('SMILEY_CODE','Kod');
define('SMILEY_EXPLANATION','Wyja�nienie');
define('MORE_SMILEY_CODES','wi�cej kod�w');
define('OWN_PRIVATE_IMAGE','Twoja ikonka, za�adowana w profilu');
define('RECIPIENT_PRIVATE_IMAGE','Ikonka twojego rozm�wcy');

/**
* Registration
*/
define('REGISTRATION','Rejestracja');
define('FILLOUT_TO_REGISTER','Wype�nij pola');
define('ERROR_NICKNAME','Wybrany pseudonim ju� zarejestrowano');
define('ERROR_PASSWORD','Has�o za kr�tkie lub puste');
define('ERROR_NAME','Wpisz imi�');
define('ERROR_USER','Nie podale� imienia!');
define('ERROR_EMAIL','Z�y format');
define('ERROR_PICTURE_URL','Nie mog� znale�� obrazka!');
define('ERROR_COLOR','Z�y format');
define('ERROR_MAIL_HOST','Nie mog� wys�a� poczty!');
define('NAME','Imi� i Nazwisko');
define('EMAIL','adres e-mail');
define('REGISTER','zarejestruj si�');
define('PICTURE_URL','URL do obrazka');
define('REGISTRATION_SUCCESSFULLY','Zarejestrowa�e� si� poprawnie!');
define('LOGIN_NOW','Jeste� gotowy do wej�cia. Je�li nie zosta�e� przekierowany na stron� wej�ciow� naci�nij link poni�ej');
define('CONFIRMATION','Potwierdzenie');
define('STATUS_CONFIRMATION','Status');
define('CONFIRM_SUCCESS','Potwierdzenie ok!');
define('CONFIRM_FAILED','B��d potwierdzenia');
define('CONFIRMATION_MESSAGE','Dosta�e� od nas wiadomo��. Kliknij na link w wiadomo�ci, �eby doko�czy� proces rejestracji.');
define('FORGOT_PASSWORD_HINT','Musisz poda� pseudonim, �eby otrzyma� wiadomo�� z has�em.');

/**
* Configuration
*/
define('CONFIGURATION','Konfiguracja');
define('TEXT_COLOR','kolor tekstu');
define('ADVICE','advice');
define('QUIET','no advice');
define('ALERT','window popup');
define('SOUND','zagraj d�wi�k');
define('SCROLL_SPEED','Pr�dko�� przesuwania');
define('CHOOSE_SCROLL_SPEED','wybierz pr�dko�� przesuwania');
define('SWITCH_OFF_IE_CLICK','wy��cz d�wi�k klikania w Internet Explorerze!');
define('CHOOSE_THEME','Wybierz schemat');

/**
* Profile
*/
define('PROFILE','m�j profil');
define('PERSONAL_DATA','dane osobowe');//a nickname follows
define('CHANGE_PROFILE','Aktualizacja profilu');
define('PROFILE_UPDATA_SUCCESSFUL','Tw�j profil zosta� zaktualizowany');
define('PROFILE_UPDATA_NOT_SUCCESSFUL','Tw�j profil nie zosta� zaktualizowany');
define('WRONG_MIME_TYPE','Z�y typ pliku');
define('IMG_FILE_TO_BIG','Za du�y plik');
define('IMG_SIZE_TO_BIG','Za du�e rozmiary');
define('SIZE_EXPECTED','Oczekiwana wielko�� obrazka w pixelach:');//a digit follows
define('PRIVATE_IMAGE','Twoja ikonka');
define('CONFIRMATION_MAIL_SUBJECT','Potwierdzenie rejestracji');
define('CONFIRMATION_MAIL_BODY','To confirm your registration at our chat, click the link below!');
define('ICQ_NUMBER','Numer ICQ');
define('ERROR_ICQ_NUMBER','No ICQ number');
define('AIM_NICKNAME','AIM Nickname');
define('ERROR_AIM_NICKNAME','The AIM nickname is to long.');
define('YIM_NICKNAME','Yahoo! Instant Messenger nick name');
define('ERROR_YIM_NICKNAME','za d�ugi pseudonim.');
define('HOMEPAGE_URL','Strona domowa');
define('ERROR_HOMEPAGE_URL','Nie znaleziono strony domowej.');
define('BIRTHDAY','Data urodzin');
define('ERROR_BIRTHDAY','z�y format');
define('AGE','Wiek');
define('INTERESTS','Zainteresowania');
define('ERROR_INTERESTS','Za d�uga lista zainteresowa�!');
define('MOTTO','Motto');
define('ERROR_MOTTO','Motto za d�ugie!');
define('LINES_PER_DAY','Linii na dzie�');
define('LOGINS_PER_DAY','Wej�� na dzie�');

/**
* Notes
*/
define('CHATTER_NOTES','Notatki dla u�ytkownika');//a nickname follows
define('UPDATE_NOTES','Zaktualizuj notatki');
define('NOTES_UPDATED_SUCCESSFULLY','Notatki poprawnie zaktualizowane.');
define('HINT_NOTES','Inni u�ytkownicy nie mog� odczytywa� twoich notatek.');
define('NOTES_NOT_UPDATED','Nie mo�na zaktualizowa� notatek, prawdopodobnie brak miejsca na twoje notatki.');

/**
* Moderation
*/
define('APPROVE','zatwierd�');
define('DISAPPROVE','nie zatwierdzaj');
define('MESSAGE_FORWARDED_TO_MODERATOR','wiadomo�� zosta�a przes�ana do Moderatora');
define('MODERATOR','Moderator');
define('VIP','VIP');

/**
* Error messages
*/
define('ERROR_WRONG_FORMAT','Dane kt�re przes�a�e� s� w z�ym formacie.');

/**
* Jumper
*/
define('JUMP_FAILED','Skok nieudany!');
define('JUMP_ERROR_CONTENT','Unacceptable content on target site found!');
define('JUMP_ERROR_HOST','Nie mog� znale�� hosta!');

/**
* IRC-Commands related stuff
*/
define('INLINE_HELP','Pomoc');
define('IRC_COMMAND','Komenda IRC');
define('IRC_EXPLANATION','Wyja�nienie');
define('IRC_ME','Wy�wietla tw�j pseudonim.');
define('IRC_MSG','Wysy�a prywatn� wiadomo�� do wybranego u�ytkownika, tak�e wtedy gdy jest on na innym kanale.');
define('IRC_NICK','Wysy�a wiadomo�� do u�ytkownika.');
define('IRC_JOIN','Zmienia kana�.');
define('IRC_QUERY','Requests a private chat with specified chatter, who are invited automatically, within your own private channel.');
define('IRC_LOCATE','Szuka u�ytkownika na czacie.');
define('IRC_IGNORE','Dodaje u�ytkownika do listy ignorowanych.');
define('IRC_UNIGNORE','Usuwa u�ytkownika z listy ignorowanych.');
define('IRC_KICK','Wyrzuca u�ytkownika. Mo�e by� u�ywane tylko przez operator�w.');
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
define('CHANNEL_ADMIN','Administracja Kana�ami');
define('CHATTER_ADMIN','Administracja U�ytkownikami');
define('ADD_CHANNEL','Utw�rz kana�');
define('DEL_CHANNEL','Usu� kana�');
define('UPDATE_CHANNEL','Zaktualizuj kana�');
define('CHATTER_DELETE_SUCCESS','U�ytkownik poprawnie usuni�ty.');
define('CHATTER_DELETE_FAILED','Nie mo�na usun�� u�ytkownika.');
define('GROUP_UPDATE_SUCCESS','Zmieniono przynale�no�� u�ytkownika.');
define('GROUP_UPDATE_FAILED','Nie mo�na zmieni� przynale�no�ci u�ytkownika.');
define('CHATTER_DISABLED','U�ytkownik zablokowany');
define('CHATTER_NOT_DISABLED','Nie mo�na zablokowa� u�ytkownika');
define('CHATTER_ENABLED','U�ytkownik odblokowany');
define('CHATTER_NOT_ENABLED','Nie mo�na odblokowa� u�ytkownika');
define('LAST_CHANNEL','Ostatni kana�');
define('LAST_ACTIVE_TIME','Ostatnio widziany');
define('LAST_HOST','Ostatni host');
define('LAST_IP','Ostatnie IP');
define('LAST_REFERER','last referer');
define('LAST_USER_AGENT','Ostatnio u�ywany agent');
define('LAST_SESSIONID','Ostatnie ID sesji');
define('REGTIME','Data rejestracji');
define('MOVE_TO_TOP','Przesu� na g�r�');
define('SUCCESS_CHANNEL_UPDATE','kana� poprawnie zaktualizowany.');
define('ERROR_CHANNEL_UPDATE','nie mo�na zaktualizowa� kana�u.');

/**
* Confirmation messages
*/
define('CONFIRM_IGNORE','U�ytkownik poprawnie dodany do listy ignorowanych.');
define('CONFIRM_UNIGNORE','U�ytkownik poprawnie usuni�ty z listy ignorowanych.');
define('CONFIRM_INVITE','U�ytkownik zaproszony.');
define('CONFIRM_DISINVITE','U�ytkownik wyproszony.');
define('CONFIRM_FRIEND','U�ytkownik poprawnie dodany do listy przyjaci�.');

/**
* User page
*/
define('USER_PAGE','Tabela u�ytkownika');
define('USER_SINCE','U�ytkownik od');//a time statement follows
define('LAST_SEEN','ostatnio widziana(y)');//a time statement follows

/**
* Regulars' table
*/
define('REGULARS',"Tabela statystyczna");
define('REGULARS_HINT','Tu mo�esz zobaczy� najbardziej aktywnych u�ytkownik�w w danej randze.');
define('SINCE_REGISTRATION','od rejestracji');
define('NOT_FOUND','nie znaleziona(y)');
define('RANK','Ranga');
define('ONLINE_TIME','ilo�� dni online');
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
define('CHANGE_CHANNEL','zmie� kana�');
define('SELECT_NICK','wybierz pseudonim');
define('OPEN_USER_PAGE','otw�rz stron� u�ytkownika');
define('HINT_WHO_IS_ONLINE','Here you find all chatters online in the chat. Use the icons behind every nickname to chat with or to join a channel.');

/**
* Password reminder
*/
define('FORGOT_PASSWD_MAIL_SUBJECT','Twoje has�o do '.TITLE);
define('FORGOT_PASSWD_MAIL_BODY','Ta wiadomo�c zosta�a do Ciebie wys�ana poniewa� poinformowa�e� nas o zagubieniu has�a dla '.TITLE);
define('HINT_REG_PASSWORD','Twoje has�o musi mie� przynajmniej '.PASSWORD_MIN_LENGTH.' znak�w.');
define('HINT_REG_NICKNAME','Tw�j pseudonim mo�e sk�ada� si� ze znak�w alfanumerycznych jak i spacji.');
define('YOUR_PASSWORD_IS','Twoje has�o to:');//a password follows
define('FORGOT_PASSWD_MAIL_HINT','');
define('RETRIEVE_PASSWORD','Odzyskaj has�o');

/**
* Statistics
*/
define('STATISTICS','Statystyka');
define('ONLINE_COUNT_LAST24h','Online w ostatnich 24h');
define('ONLINE_TIME_AVG','�redni czas online w minutach na dzie�');
define('REGISTERED_COUNT','Liczba zarejestrowanych u�ytkownik�w');
define('LAST_REGISTERED','Ostatni zarejestrowany u�ytkownik');
define('MAIL_COUNT','Liczba wiadomo�ci');
define('UNRED_MAILS','wiadomo�ci nieprzeczytanych');
define('MAIL_COUNT_LAST_24h','Liczba wiadomo�ci przez ostatnie 24h');

/**
* context sesitive help
*/
define('HINT_PASSWORD','Wpisz has�o kt�re otrzyma�e� e-mailem od nas, �eby wej�� jako go�� pozostaw to pole puste.');
define('HINT_NICKNAME','Musisz si� zarejestrowa� �eby otrzyma� pseudonim. Zostaw to pole puste �ebu wej�� jako go��.');
define('HINT_CHANNELS','S� trzy rodzaje kana��w, <em>moderowane</em>, <em>publiczne</em> i <em>prywatne</em>. Na publicznych kana�ach linie tesktu s� pokazywane bezpo�rednio, na moderowanych musz� zosta� zaakceptowane przez moderatora. Prywatne s� pokazywane tylko je�li si� zalogujesz.');
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
define('GUEST_NICK_PREFIX','Go��');
define('ALL_GUESTS','Go�cie');
define('SUBMIT','Submit');
define('CANCEL','Cancel');
define('SEARCH','Szukaj');
define('SEARCH_RESULTS','wyniki szukania');
define('ALERT_NEW_LINE','Kto� chce z tob� rozmawia�');
define('CLOSE_WINDOW','Zamknij okno');
define('GOTO_HOME','Goto home page');
define('CONTACT_HINT','Je�li masz pytanie, daj nam zna�!');
define('REALLY_QUESTION','Czy jeste� pewien?');
define('CHATTER','U�ytkownik');
define('OPERATOR','Operator');
define('ADMIN_HINT','To administrate your chat, login as "operator" and click within the input-frame on "'.ADMINISTRATION.'".');
define('IMPORTANT','Wa�ne');
define('OPERATOR_PASSWORD','Has�o Operatora');
define('MAKE_NOTE','Zapisz has�o operatora');
define('RESTRICT','Szukaj pseudonim�w');
define('DENIED_FOR_GUESTS','Nie udost�pnione dla go�ci!');
define('BANNED_MSG','Your are banned for the chosen channel and so you are kicked into your private channel.');
define('CHATTER_COUNT','u�ytkownik�w na czacie');//a digit follows
define('HIDE','ukryj');
define('GENDER','P�e�');
define('GENDER_NOTE','Mo�esz wybra� p�e� tylko raz!');
define('FEMALE','kobieta');
define('MALE','m�czyzna');
define('PAGE_VIEWS','Widoki karty');
define('GRADE','Ranga');
define('GRADE_ROOKIE','��todzi�b');
define('GRADE_MEMBER','Cz�onek');
define('GRADE_REGULAR','Zwyk�y');
define('GRADE_ELITE','Elita');
define('GRADE_OPERATOR','Operator/Admin');
define('YOU_ARE_BUSY','Rozmawiasz ju� z kim� w prywatnym oknie!');
define('CHATTER_IS_BUSY','Niestety u�ytkownik nie mo�e z Tob� rozmawia�, jest zbyt zaj�ty.');
define('WANTS_TO_TALK','chce z Tob� rozmawia�!');//nickname in front of this
define('DAYS','dni');
define('CHAT','Czat');
define('CHATMAIL','Chat-Mail');
define('NICKNAME_NOT_FOUND','Nie znaleziono pseudonimu.');
define('PASSWORD_HAS_BEEN_SENT','Has�o zosta�o wys�ane');
define('CHOOSE_LANGUAGE','Inny j�zyk');
define('OPTIONAL','opcjonalne');
define('MISCELLANEOUS','pozosta�e');
define('SAVE','Zapisz');
define('DELETE','Usu�');
define('EDIT','Edycja');
define('CREATE_NEW','utw�rz');
define('JS_ALERT','W��cz JavaScript');
define('HAPPY_BIRTHDAY','Wszystkiego najlepszego w dniu urodzin!');
define('CHOOSEN','wybrany');

/**
 * PostNuke related
 */
define('PN_NOT_LOGGED_IN','B��d!');
define('PN_HINT_NOT_LOGGED_IN','�eby wej�� na chata musisz si� najpierw zalogowa�!');
?>
