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
  $Source: /cvsroot/phpopenchat/chat3/include/languages/dk.inc,v $
  $Revision: 1.1.2.2 $
*/

/**
* danish language file
* 
* defines constants for a danish language interface
* 
* @author Michael Oertel <michael@ortelius.de>
* @version $Id: dk.inc,v 1.1.2.2 2004/02/12 13:40:42 letreo Exp $
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
define('WELCOME','Velkommen til PHPOpenChat-Installationen');
define('INTRO','F�r du benytter denne chat, b�r du have l�st f�lgende <a href="netiquette.php">Regeln</a> !');
define('GREETING','Velkommen tilbage!');
define('LOGIN_WELCOME','Klik p� en chatter �verst i h�jre hj�rne for flere oplysninger.');
define('NICKNAME','Kaldenavn');
define('PASSWORD','Password');
define('CHANNEL','Rum');
define('LOGIN','Login');
define('GO','G�');
define('EXIT_CHAT','Forlad chat');
define('FORGOT_PASSWORD','Glemt password?');
define('STORE_ACCOUNT_DATA','Gem login');

/**
* used within chat output/input interface
*/
define('LEAVES_THE_CHAT','forlader chatten.');
define('LEAVES_THIS_CHANNEL','forlader rummet.');
define('IS_TOO_BUSY','Optaget');
define('IS_NOT_ONLINE','er ikke online');
define('JOINS_THIS_CHANNEL','Tr�der in i rummet.');
define('JOINS_THE_CHAT','Deltager i chatten.');
define('SAYS_TO','siger til');
define('WHISPERS_TO','hvisker til');
define('SAY_TO','sig til');
define('WHISPER_TO','hvisk til');
define('EVERYBODY','alle');
define('INVITATION_MESSAGE','Du blev inviteret i et privat rum! V�r venlig at skifte rum');
define('SPEAK_TO','tal til');
define('WHISPERED','hvisket');
define('OUTPUT_FILTER','Udgangsfilter');
define('PRIVATE','Kun privat');
define('BODIES','Kun venner');
define('SYSTEM_MESSAGES','Ingen Systemmelding');
define('IGNORE','Ignorer');
define('INVITE','Inviter');
define('CONFIGURE','Konfigurer');
define('HELP','Hj�lp');
define('INFO','Information');
define('GUESTS','Deltagere');
define('EMAIL_US','E-Mail os');
define('NOTE_ABOUT','Notits vedr�rende');
define('ICON_LIST','Smiley-Liste');
define('CHOOSE_CHANNEL','v�lg rum');
define('CHOOSE_RECIPIENT','v�lg modtager');
define('ADD_TO_FRIENDLIST','tilf�j til venner');
define('NO_CLICKETY_CLICK','I fremtiden vil jeg ikke mere trykke uh�mmet p� send knappen.');
define('LINE_HAS_BEEN_SENT_TO','Din besked blev videresendt til');//nickname follows
define('FULL','voll');
define('UNLOCK_CHANNEL','�bn f�lgende kanal');//channel name follows
define('YOU_HAVE_NEW_MAIL','Du har mail i din indbakke!');
define('LOGOUT_SHORTLY','Du blir snart logget af '.CHAT_NAME.' da du har v�ret inaktiv for l�nge');

/**
* used within ignore-dialog
*/
define('IGNORED','ignoreret');
define('IGNORE_CHATTERS','ignorerede deltagere');
define('IGNORED_CHATTER','ignoreret deltager');
define('IGNORE_CHATTER','ignorer deltager');
define('UNIGNORE_CHATTER','ignorer ikke deltager');
define('UNIGNORED_CHATTER','deltagere der ikke er ignorerede');
define('HINT_IGNORE_CHATTERS','Hvis du f�ler dig generet af en anden deltager, kan du s�tte vedkommende p� ignorer. Du skriver ganske enkelt navnet i tekstboksen  og trykker p� enter . I h�jre tekstboks vises s�gningen med nicknavnet. Ved at dobbeltklikke p� nicknavnet bliver personen registreret p� din ignorer liste.');

/**
* used within invite-dialog
*/
define('INVITE_CHATTERS','Inviter deltagere');
define('INVITED_CHATTERS','Inviterede deltagere');
define('INVITE_CHATTER','Inviter deltager');
define('DISINVITE_CHATTER','Udeluk deltager');
define('DISINVITED_CHATTERS','Ikke inviterede deltagere');
define('HINT_INVITE_CHATTERS','Hvis du vil chatte i dit eget rum (channel) med uds�gte deltagere , skal du invitere disse ind i dit rum. Du s�ger dem ganske enkelt ud ved at tilf�je deres nick i tekstboksen og trykke p� enter. I h�jre tekstboks kommer s�geresultatet med de udvalgte nicks. Ved at dobbeltklikke p� nicknavn inviterer du vedkommende i dit eget rum.
');

/**
* used within friends-dialog
*/
define('FRIENDS','Venner');
define('ALL_CHATTERS','Alle deltagere');
define('ADD_TO_FRIENDS','F�j til venner');
define('DEL_FRIEND','Slet ven');
define('HINT_ADD_FRIENDS','Her kan du tilf�je deltagere til din venneliste.');

/**
* used within mail-dialog
*/
define('MAIL','Post');
define('INBOX','Indbakke');
define('OUTBOX','Udbakke');
define('TRASH','Papirkurv');
define('COMPOSE','Opret');
define('REPLY','Besvar');
define('FORWARD','Videresend');
define('SUBJECT','Ang�ende');
define('BODY','Indhold');
define('SEND','Send');
define('MAIL_SEND_HINT','Att: "'.SEND.'"-knappen virker kun, hvis du har skrevet et eksisterende nicknacn i tekstboksen "To:"!');
define('RECIPIENT_HINT','Du kan v�lge mere end enmodtager. Du bedes benytte komma mellem navnene.');
define('MOVE_TO_TRASH','Flyt til papirkurv');
define('GET_MAIL','Hent nye meddelelser');
define('DELETE_MAIL','slet mail');
define('SENDER','Afsender');
define('RECIPIENT','Modtager');
define('MAIL_SEND_DATE','Dato');
define('MAIL_RECEIVED','modtaget');
define('LAST_TOUCH_RECIPIENT','Modtagelse bekr�ftet');
define('LAST_TOUCH_SENDER','Seneste l�ste');
define('NO_FRIENDS_FOUND','Ingen venner fundet');
define('NO_SUCH_RECIPIENT_FOUND','En af de valgte modtagere kunne ikke findes.');
define('BODY_TO_SHORT','Indholdet af din mail er for kort.');

/**
* used within help-dialog
*/
define('HELP_TITLE','Chat-Hilfe');
define('HELP_HINT','TIP: Dette vindue skal forblive �ben, forts�t chatten og se efter her!');
define('HELP_SUBTITLE1','Vejledning og forklaring:');
define('HELP_TEASER1','Her blir de generelle ting i chatten forklaret. L�s videre, og bliv klogere!');
define('HELP_CHANNEL','Rum: Skifte Channel');
define('HELP_SPEAK','Box "sig til"/"hvisket": P� denne m�de kan du kontakte en bestemt person. Hvad du hvisker blir kun set af dig og personen du henvender dig til.');
define('HELP_IGNORE','Menupunkt ignorer: "Dobbeltklik p� "ignorer". Der kan du v�lge hvilke deltagere du ikke gider l�se mere');
define('HELP_INVITE','Menupunkt Inviter: Her kan du v�lge hvilke deltagere du vil give adgang til dit private rum');
define('HELP_FRIENDS','Menupunkt Venner: Her kan du v�lge deltagere til din venneliste.');
define('HELP_CONFIGURE','Menupunkt Konfigurer: Her har du muligheden for at �ndre dine chatoptioner, f.eks. tekstfarve m.m.');
define('HELP_MAIL','Menupunkt Post: Her kan du efterlade besked til andre deltagere.');
define('HELP_HELP','Menupunkt hj�lp: Her befinder du dig i �jeblikket.');
define('HELP_SUBTITLE2','IRC-Kommandoer:');
define('HELP_TEASER2','IRC-Kommandoer er under udvikling ...');
define('HELP_SUBTITLE3','Smileys:');
define('HELP_TEASER3','Smileys er under udvikling ...');

define('SMILEY_CODE','Kode');
define('SMILEY_EXPLANATION','Forklaring');
define('MORE_SMILEY_CODES','flere koder');
define('OWN_PRIVATE_IMAGE','Ens eget icon, aktiveret gennem profilen');
define('RECIPIENT_PRIVATE_IMAGE','Det private icon fra samtalepartneren');

/**
* Registration
*/
define('REGISTRATION','Registration');
define('FILLOUT_TO_REGISTER','Registrer dig venligst her');
define('ERROR_NICKNAME','Dette nick eksisterer allerede eller boksen er tom.');
define('ERROR_PASSWORD','Password er for kort eller boksen er tom');
define('ERROR_NAME','Der blev ingen brugernavn angivet');
define('ERROR_EMAIL','Forkert format til e-mail adresse');
define('ERROR_PICTURE_URL','Der blev ingen IMG. fundet');
define('ERROR_COLOR','Forkert format');
define('ERROR_MAIL_HOST','Kunne ikke sende mail til den angivne adresse');
define('NAME','For- og efternavn');
define('EMAIL','E-Mailadresse');
define('REGISTER','Registrer her');
define('PICTURE_URL','URL til billede');
define('REGISTRATION_SUCCESSFULLY','Din registrering er succesfuld gennemf�rt!');
define('LOGIN_NOW','Du kan nu logge p�. Kommer du ikke automatisk videre, bedes du benytte flg. link.');
define('CONFIRMATION','Bekr�ftelse');
define('STATUS_CONFIRMATION','Status');
define('CONFIRM_SUCCESS','Din tilmelding var succesfuld.');
define('CONFIRM_FAILED','Din tilmelding er ikke gennemf�rt.');
define('CONFIRMATION_MESSAGE','Der er sendt en mail til den e-mailadresse du har angivet. For at afslutte registreringen,skal du g� til det link der er blevet sendt til dig pr. mail. !');
define('FORGOT_PASSWORD_HINT','Skriv her det nick du har registreret dig under. Dit password blir tilsendt til den mail du har angivet i registreringen.');

/**
* Configuration
*/
define('CONFIGURATION','Konfiguration');
define('TEXT_COLOR','Tekstfarve');
define('ADVICE','Meddelelse');
define('QUIET','Ingen meddelelse');
define('ALERT','Popup-vindue');
define('SOUND','afspil lyd');
define('SCROLL_SPEED','Scrollhastighed');
define('CHOOSE_SCROLL_SPEED','v�lg Scrollhastighed');
define('SCROLL_SPEED_NORMAL','normal');
define('SCROLL_SPEED_FAST','hurtigere');
define('SCROLL_SPEED_FASTER','meget hurtigt');
define('SCROLL_SPEED_OFF','fra');
define('SWITCH_OFF_IE_CLICK','Klick-lyd fra Internet explorer fra!');
define('CHOOSE_THEME','V�lg et motiv');

/**
* Profile
*/
define('PROFILE','Min profil');
define('PERSONAL_DATA','Personlige data');//a nickname follows
define('CHANGE_PROFILE','�ndre profil');
define('PROFILE_UPDATA_SUCCESSFUL','Din profil blev opdateret');
define('PROFILE_UPDATA_NOT_SUCCESSFUL','Din profil blev ikke opdateret');
define('WRONG_MIME_TYPE','Filen er ingen billedfil');
define('IMG_FILE_TO_BIG','Filen er for stor.');
define('IMG_SIZE_TO_BIG','Billedet er for stort.');
define('SIZE_EXPECTED','Forventet billedst�rrelse i pixels:');//a digit follows
define('PRIVATE_IMAGE','Privat billede');
define('CONFIRMATION_MAIL_SUBJECT','Registrationsbekr�ftelse');
define('CONFIRMATION_MAIL_BODY','For at bekr�fte din registration i vor chat, bedes du dobbeltklikke p� flg. link!');
define('ICQ_NUMBER','ICQ Nummer');
define('ERROR_ICQ_NUMBER','Der blev intet ICQ nummer angivet');
define('AIM_NICKNAME','AIM Nicknavn');
define('ERROR_AIM_NICKNAME',' AIM nicknavnet er for langt.');
define('YIM_NICKNAME','Yahoo! Instant Messenger nicknavn');
define('ERROR_YIM_NICKNAME','YIM nicknavnet er for langt.');
define('HOMEPAGE_URL','HomePage');
define('ERROR_HOMEPAGE_URL','Ingen Homepage fundet');
define('BIRTHDAY','F�dselsdag');
define('ERROR_BIRTHDAY','forkert Format');
define('AGE','Alder');
define('INTERESTS','Interesser');
define('ERROR_INTERESTS','For mange interesser!');
define('MOTTO','Motto');
define('ERROR_MOTTO','For langt Motto');
define('LINES_PER_DAY','Linier pr. dag');
define('LOGINS_PER_DAY','Logins pr. dag');

/**
* Notes
*/
define('CHATTER_NOTES','Besked til deltager');//a nickname follows
define('UPDATE_NOTES','Opdater besked');
define('NOTES_UPDATED_SUCCESSFULLY','Din besked blev succesfuld gemt.');
define('HINT_NOTES','De beskeder du opretter i denne chat kan kun l�ses af dig selv.');
define('NOTES_NOT_UPDATED','Dine beskeder kunne ikke opdateres. Grunden hertil kan v�re at der ikke er mere plads at gemme p�.');

/**
* Moderation
*/
define('APPROVE','Tillad');
define('DISAPPROVE','Afsl�');
define('MESSAGE_FORWARDED_TO_MODERATOR','Beskeden blev videregivet til Moderatoren');
define('MODERATOR','Moderator');
define('VIP','Kendt');

/**
* Error messages
*/
define('ERROR_WRONG_FORMAT','De sendte data har forkert format.');

/**
* Jumper
*/
define('JUMP_FAILED','Videresend mislykket!');
define('JUMP_ERROR_CONTENT','Uakseptabelt indhold fundet p� angivet Website!');
define('JUMP_ERROR_HOST','Serveren kunne ikke findes!');

/**
* IRC-Commands related stuff
*/
define('INLINE_HELP','Hj�lp');
define('IRC_COMMAND','IRC-kommando');
define('IRC_EXPLANATION','Forklaring');
define('IRC_ME','Blir erstattet med dit nicknavn.');
define('IRC_MSG','Sender en besked til angivet deltager, osse hvis vedkommende befinder sig i et andet rum.');
define('IRC_NICK','Sender en besked til angivet deltager.');
define('IRC_JOIN','Skifter rum (channel).');
define('IRC_QUERY','�bner en privat chat i et privat rum og indbyder den angivne deltager.');
define('IRC_LOCATE','S�ger efter en deltager i chatten.');
define('IRC_IGNORE','S�tter den angivne deltager p� ignorerliste.');
define('IRC_UNIGNORE','Sletter den angivne deltager fra ignorerlisten.');
define('IRC_KICK','Udviser den angivne deltager. Kun muligt for "Operator".');
define('IRC_BAN','Udviser den angivne chatter for et bestemt tidsrum (i minutter) fra det aktuelle rum. Man kan �jeblikkelig tillade en udvist deltager at deltage igen ved brug af "/ban <nickname> 0"! Kun muligt for "Operator".');
define('IRC_HELP','Aktiver denne hj�lp.');
define('IRC_QUIT','Afbryd denne chat.');
define('LOCATED_AT','fundet i');//a nickname follows, nickname in front of this sentence
define('UNLOCATED','kunne ikke findes.');//nickname in front of this sentence

/**
* Admin area
*/
define('ADMINISTRATION','Administration');
define('WELCOME_ADMIN','Administrationsomr�de');
define('PUBLIC_CHANNEL','offentlig');
define('MODERATED_CHANNEL','modereret');
define('PRIVATE_CHANNEL','privat');
define('CHANNEL_ADMIN','Channel-administration');
define('CHATTER_ADMIN','Chatter-administration');
define('ADD_CHANNEL','tilf�j Channel ');
define('DEL_CHANNEL','slet Channel ');
define('UPDATE_CHANNEL','opdater Channel ');
define('CHATTER_DELETE_SUCCESS','Deltager slettet med succes.');
define('CHATTER_DELETE_FAILED','Deltager kunne ikke slettes.');
define('GROUP_UPDATE_SUCCESS','Kategorigruppen for denne deltager blev �ndret.');
define('GROUP_UPDATE_FAILED','Kategorigruppen for denne deltager kunne ikke �ndres.');
define('CHATTER_DISABLED','Deltageren blev deaktiveret.');
define('CHATTER_NOT_DISABLED','Deltageren kunne ikke deaktiveres.');
define('CHATTER_ENABLED','Deltageren blev aktiveret');
define('CHATTER_NOT_ENABLED','Deltageren kunne ikke aktiveres.');
define('LAST_CHANNEL','Sidste rum');
define('LAST_ACTIVE_TIME','sidst set');
define('LAST_HOST','Sidste hostnavn');
define('LAST_IP','sidste IP');
define('LAST_REFERER','sidste referent');
define('LAST_USER_AGENT','sidste bruger-Agent');
define('LAST_SESSIONID','sidste Session-Id');
define('REGTIME','Registreret den');
define('MOVE_TO_TOP','Flyt til start');
define('SUCCESS_CHANNEL_UPDATE','Den angivne Channel blev opdateret med succes.');
define('ERROR_CHANNEL_UPDATE','Den angivne Channel kunne ikke opdateres.');

/**
* Confirmation messages
*/
define('CONFIRM_IGNORE','Deltageren blev sat p� ignorerlisten.');
define('CONFIRM_UNIGNORE','Deltageren blev taget af ignorerlisten.');
define('CONFIRM_INVITE','Deltageren blev inviteret.');
define('CONFIRM_DISINVITE','Deltageren blev bedt om at forlade chatten.');
define('CONFIRM_FRIEND','Deltageren blev oprettet som p� vennelisten.');

/**
* User page
*/
define('USER_PAGE','UserPage');
define('USER_SINCE','Registriert am');//a time statement follows
define('LAST_SEEN','zuletzt gesehen am');//a time statement follows

/**
* Regulars' table
*/
define('REGULARS','Stambord');
define('REGULARS_HINT','Her kan du f�lge aktiviteten blandt deltagerne samt se placeringer.');
define('SINCE_REGISTRATION','siden registrering');
define('NOT_FOUND','kunne ikke findes');
define('RANK','Sammenlagt placering');
define('ONLINE_TIME','Online dage total');
define('ACCOUNT_DATA','logon data');
define('INDIVIDUAL_DATA','Personlige data');

/**
* right click menu within the output frame
*/
define('PRIVATE_CHAT_NEW_WINDOW','Privater Chat');

/**
* Who is online window
*/
define('WHO_IS_ONLINE','hvem er online?');
define('CHANGE_CHANNEL','Skift Channel');
define('SELECT_NICK','v�lg nicknavn');
define('OPEN_USER_PAGE','�bn UserPage ');
define('HINT_WHO_IS_ONLINE','Alle deltagere der er i chatten momentan finder du her. Benyt det icon der findes efter nicknavnet, for at chatte med en bestemt deltager eller til at veksle over i det private rum med.');

/**
* Password reminder
*/
define('FORGOT_PASSWD_MAIL_SUBJECT','Dit password ved '.TITLE);
define('FORGOT_PASSWD_MAIL_BODY','Denne meddelelse blev sendt, da du har meddelt os at du har mistet dit password '.TITLE.'.');
define('YOUR_PASSWORD_IS','Dit password lyder:');//a password follows
define('FORGOT_PASSWD_MAIL_HINT','
I TILF�LDE AF AT DENNE ANMODNING IKKE STAMMER FRA DIG:
Enhver kan uden at kende password anmode om at f� dette tilsendt til sin e-mail passende til  nicknavnet. Dette er lavet af den simple grunde af at hvis man glemmer sit password f�r man mulighed for at hente oplysningerne igen. Denne mail betyder IKKE at en trediepart kender dit password. Du er den eneste, der kender paswordet til dit nicknavn og kan f� det tilsendt ved eftersp�rgsel. Hvis det er tilf�ldet at du IKKE har efterspurgt dit password skal du bare ignorere den tilsendte mail og benytte dit password som vanligt. ');
define('RETRIEVE_PASSWORD','Password zusenden lassen');

/**
* Statistics
*/
define('STATISTICS','Statistikker');
define('ONLINE_COUNT_LAST24h','Online de sidste 24 timer');
define('ONLINE_TIME_AVG','Gennemsnitlig online pr. dag');
define('REGISTERED_COUNT','Reiistrerede deltagere');
define('LAST_REGISTERED','Sidst registreret');
define('MAIL_COUNT','Total mails');
define('UNRED_MAILS','ul�ste mails');
define('MAIL_COUNT_LAST_24h','Mails i de sidste 24 timer');

/**
* context sesitive help/info
*/
define('HINT_PASSWORD','Skriv det password,som du fik tilsende ved din registrering her. Du kan osse logge p� som g�st, s� skal du intet skrive.');
define('HINT_NICKNAME','For at f� et nicknavn skal du registrere dig.Du kan osse logge p� som g�st, s� skal du intet skrive.');
define('HINT_REG_PASSWORD','Passwordet skal v�re'.PASSWORD_MIN_LENGTH.' langt.');
define('HINT_REG_NICKNAME','Dit nicknavn kan best� af bogstaver, tal, samt specialtegn.');
define('HINT_CHANNELS','Der findes 3 typer rum (Channels), <em>offentlige</em>, <em>med moderator</em> und <em>private</em>. I de <em>offentlige</em> rum blir teksten vist direkte , I de <em>moderierten</em>, skal teksten godkendes af moderatoren. <em>Private</em> rum ser man kun, hvis mn blev inviteret og er online.');
define('INFO_RANKING','Har man opn�et en vis rang, Blir man flyttet dertil og beholder denne rang osse hvis ens v�rdier igen falder under gr�nsen til denne rang.');
define('HINT_ADVICE_QUIET','Hvis du v�lger denne indstilling, bliver du ikke gjort opm�rksom p�, at du blir talt til, hverken igennem lyd eller popup-vindue.');
define('HINT_ADVICE_ALERT','Hvis du har valgt denne indstilling, blir du igennem en <strong>Popupfenster</strong> gjort opm�rksom p�, at du blev tiltalt direkte.');
define('HINT_ADVICE_SOUND','Hvis du har valgt denne indstilling, blir du igennem en <strong>Soundsignal</strong> gjort opm�rksom p�, at du blev tiltalt direkte.');

/**
* Guestbook
*/
define('GUESTBOOK','G�stebog');
define('GUESTBOOK_NEW_ENTRY','Nyt indl�g i g�stebogen');
define('GUESTBOOK_ENTRY_SAVED','Det nye indl�g i g�stebogen blev gemt');

/**
* Generic
*/
define('GUEST_NICK_PREFIX','G�st');
define('ALL_GUESTS','G�ster');
define('SUBMIT','Ok');
define('CANCEL','Afbryd');
define('SEARCH','S�g');
define('SEARCH_RESULTS','S�ge resultater');
define('ALERT_NEW_LINE','Der blev talt til dig');
define('CLOSE_WINDOW','Luk vindue');
define('GOTO_HOME','Til start');
define('CONTACT_HINT','Hvis du har sp�rgsm�l, skal du v�re velkommen til at sp�rge!');
define('REALLY_QUESTION','Er det virkelig din hensigt?');
define('CHATTER','deltager');
define('OPERATOR','Operator');
define('ADMIN_HINT','For at v�re ordf�rer i din chat skal du logge dig p� som "operator" og derefter klikke p�  "'.ADMINISTRATION.'" i vinduet.');
define('IMPORTANT','vigtig');
define('OPERATOR_PASSWORD','Operator passwordet');
define('MAKE_NOTE','Noter venligst dette Operator password');
define('RESTRICT','S�g efter nicknavne');
define('DENIED_FOR_GUESTS','Denne service er ikke tilg�ngelig for g�ster!');
define('BANNED_MSG','Du blev udelukket af det valgte rum og sendt over i dit private rum.');
define('CHATTER_COUNT','Deltagere online');//a digit follows
define('HIDE','gemme');
define('GENDER','K�n');
define('GENDER_NOTE','Du kan kun angive dette een gang!');
define('FEMALE','kvinde');
define('MALE','mand');
define('PAGE_VIEWS','Side oversigt');
define('GRADE','Rang');
define('GRADE_ROOKIE','Gr�nskolling');
define('GRADE_MEMBER','Medlem');
define('GRADE_REGULAR','Stamg�st');
define('GRADE_ELITE','Eliteg�st');
define('GRADE_OPERATOR','Admin');
define('YOU_ARE_BUSY','Du chatter allerede med en anden i det private vindue!');
define('CHATTER_IS_BUSY','Desv�rre er denne deltager optaget.');
define('WANTS_TO_TALK','vil gerne chatte med dig!');//nickname in front
define('DAYS','Dage');
define('CHAT','Chat');
define('CHATMAIL','Chat-Mail');
define('NICKNAME_NOT_FOUND','Det s�gte nicknavn blev ikke fundet.');
define('PASSWORD_HAS_BEEN_SENT','Pasword er sent til den registrerede mailadresse.');
define('CHOOSE_LANGUAGE','Skift sprog');
define('OPTIONAL','optioner');
define('MISCELLANEOUS','andet');
define('SAVE','Gemme');
define('DELETE','Slette');
define('EDIT','Udarbejde');
define('CREATE_NEW','Tilf�j nyt indl�g');
define('JS_ALERT','Aktiver JavaScript');
define('HAPPY_BIRTHDAY','Hjertelig tillykke med f�dselsdagen!');
define('CHOOSEN','Udvalgt');

/**
 * PostNuke related
 */
define('PN_NOT_LOGGED_IN','Login fejl!');
define('PN_HINT_NOT_LOGGED_IN','For at deltage i chatten skal du logge ind og evt. registrere dig!');
?>