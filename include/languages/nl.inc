<?php //-*-php-*-
/*   ********************************************************************   **
**   Copyright notice                                                       **
**                                                                          **
**   (c) 1995-2002 PHPOpenChat Development Team                             **
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
  $Date: 2003/08/04 09:02:35 $
  $Source: /cvsroot/phpopenchat/chat3/include/languages/nl.inc,v $
  $Revision: 1.1.2.1 $
*/

/**
* dutch language file
* 
* defines constants for a dutch language interface
* 
* @author Peter Schwager <pschwager@schwager.demon.nl>
* @version $Id: nl.inc,v 1.1.2.1 2003/08/04 09:02:35 letreo Exp $
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
define('WELCOME','Welkom bij PHPOpenChat');
define('INTRO','Dit is een chat, lees eerst de <a href="netiquette.php">regels</a> voor je deelneemt!');
define('GREETING','Leuk om je weer te zien!');
define('LOGIN_WELCOME','klik een chatter in de rechter-bovenhoek om meer opties te krijgen.');
define('NICKNAME','Schuilnaam');
define('PASSWORD','Wachtwoord');
define('CHANNEL','Kanaal');
define('LOGIN','Login');
define('GO','Zend');
define('EXIT_CHAT','Verlaat chat');
define('FORGOT_PASSWORD','Wachtwoord vergeten?');
define('STORE_ACCOUNT_DATA','account data bewaren');

/**
* used within chat output/input interface
*/
define('LEAVES_THE_CHAT','verlaat de chat.');
define('LEAVES_THIS_CHANNEL','verlaat het kanaal.');
define('IS_TOO_BUSY','is bezig');//nickname in front
define('IS_NOT_ONLINE','is niet online');
define('JOINS_THIS_CHANNEL','betreedt het kanaal.');
define('JOINS_THE_CHAT','betreedt de chat.');
define('SAYS_TO','zegt tegen');
define('WHISPERS_TO','fluistert tegen');
define('SAY_TO','zeg tegen');
define('WHISPER_TO','fluister tegen');
define('EVERYBODY','iedereen');
define('INVITATION_MESSAGE','Je bent uitgenodigd voor een privé kanaal! Ga naar het kanaal:');//a channel name follows
define('SPEAK_TO','spreek tegen');
define('WHISPERED','gefluisterd');
define('OUTPUT_FILTER','Uitvoer filter');
define('PRIVATE','alleen privé tekst');
define('BODIES','alleen vrienden');
define('SYSTEM_MESSAGES','Geen systeem boodschappen');
define('IGNORE','Negeren');
define('INVITE','Uitnodigen');
define('CONFIGURE','Configureren');
define('HELP','Help');
define('INFO','Informatie');
define('GUESTS','Gasten');
define('EMAIL_US','Email ons');
define('NOTE_ABOUT','Notitie over');
define('ICON_LIST','Smiley-Lijst');
define('CHOOSE_CHANNEL','Kies kanaal');
define('CHOOSE_RECIPIENT','Kies ontvanger');
define('ADD_TO_FRIENDLIST','toevoegen aan vriendenlijst');
define('NO_CLICKETY_CLICK','Okee, ik zal niet meer als een gek op de zendknop drukken in de toekomst.');
define('LINE_HAS_BEEN_SENT_TO','Je regel is verzonden naar');//nickname follows
define('FULL','full');
define('UNLOCK_CHANNEL','ontsluit kanaal');//channel name follows
define('YOU_HAVE_NEW_MAIL','Je hebt nieuwe berichten!');
define('LOGOUT_SHORTLY','Je wordt over enkele ogenblikken afgemeld van '.CHAT_NAME.', wegens inactiviteit! Verversen?');

/**
* used within ignore-dialog
*/
define('IGNORED','genegeerd');
define('IGNORE_CHATTERS','Negeer chatters');
define('IGNORED_CHATTER','genegeerde chatter');
define('IGNORE_CHATTER','negeer chatter');
define('UNIGNORE_CHATTER','Chatter niet negeren');
define('UNIGNORED_CHATTER','niet genegeerde chatter');
define('HINT_IGNORE_CHATTERS','Hier kan je vervelende mensen mee negeren.');

/**
* used within invite-dialog
*/
define('INVITE_CHATTERS','Chatters uitnodigen');
define('INVITED_CHATTERS','uitgenodigde chatters');
define('INVITE_CHATTER','chatter uitnodigen');
define('DISINVITE_CHATTER','chatter niet uitnodigen');
define('DISINVITED_CHATTERS','chatters niet uitnodigen');
define('HINT_INVITE_CHATTERS','Als je met iemand privé wilt praten op je eigen kanaal, moet je iemand uitnodigen en de juiste rechten verlenen voor je kanaal.');

/**
* used within friends-dialog
*/
define('FRIENDS','Vrienden');
define('ALL_CHATTERS','alle chatters');
define('ADD_TO_FRIENDS','Toevoegen aan vrienden');
define('DEL_FRIEND','Vriend verwijderen');
define('HINT_ADD_FRIENDS','In dit scherm kun je vrienden toevoegen aan je vriendenlijst.');

/**
* used within mail-dialog
*/
define('MAIL','Mail');
define('INBOX','Postvak in');
define('OUTBOX','Postvak uit');
define('TRASH','Prullenbak');
define('COMPOSE','Opstellen');
define('REPLY','Beantwoorden');
define('FORWARD','Doorsturen');
define('RECEPIENT','Aan');
define('SUBJECT','Onderwerp');
define('BODY','Inhoud');
define('SEND','verzend');
define('MAIL_SEND_HINT','Opmerking: De "'.SEND.'"-knop werkt alleen als bestaande schuilnamen zijn ingevoerd als ontvangers!');
define('RECIPIENT_HINT','Meer dan een ontvanger, gescheiden door komma\'s, is toegestaan.');
define('MOVE_TO_TRASH','Verplaats naar prullenbak');
define('GET_MAIL','Haal nieuwe berichten');
define('DELETE_MAIL','Verwijder berichten');
define('SENDER','Afzender');
define('RECIPIENT','Ontvanger');
define('MAIL_SEND_DATE','Verzend datum');
define('MAIL_RECEIVED','ontvangen');
define('LAST_TOUCH_RECIPIENT','Lezen bevestiging');
define('LAST_TOUCH_SENDER','laatst gelezen');
define('NO_FRIENDS_FOUND','geen vrienden gevonden');
define('NO_SUCH_RECIPIENT_FOUND','Eén van de ontvangers kon niet worden gevonden.');
define('BODY_TO_SHORT','De inhoud van je bericht is te kort.');

/**
* used within help-dialog
*/
define('HELP_TITLE','Chat-Help');
define('HELP_HINT','Tip: Laat dit scherm open, chat en kijk hier voor commando\'s');
define('HELP_SUBTITLE1','Handleiding');
define('HELP_TEASER1','Hier presenteren we je de basisfunctionaliteit van de chat!');
define('HELP_CHANNEL','Kanaal: Schakel tussen beschikbare kanalen');
define('HELP_SPEAK','Scherm "zegt tegen"/"gefluisterd": Spreek of fluister direct tegen een chatter.');
define('HELP_IGNORE','Menu Negeren: Hier kan je chatters negeren.');
define('HELP_INVITE','Menu Uitnodigen: Nodig chatters uit voor je privé kanaal.');
define('HELP_FRIENDS','Menu Vrienden: Je kan andere chatters markeren als vrienden, het systeem zal je laten zien welke vriend op dit moment on/offline is.');
define('HELP_CONFIGURE','Menu Configureren: In deze sectie kun je je voorkeursinstellingen voor de chat veranderen, bijv. kleuren en dergelijke.');
define('HELP_MAIL','Menu Mail: Verzend een email naar een chatter en controleer je eigen postvak in.');
define('HELP_HELP','Menu Help: Daar ben je op dit moment ...');
define('HELP_SUBTITLE2','IRC-Commando\'s:');
define('HELP_TEASER2','Werk in uitvoering ...');
define('HELP_SUBTITLE3','Smileys:');
define('HELP_TEASER3','Werk in uitvoering ...');

define('SMILEY_CODE','Code');
define('SMILEY_EXPLANATION','Verklaring');
define('MORE_SMILEY_CODES','meer codes');
define('OWN_PRIVATE_IMAGE','Je eigen pictogram, verzonden naar je profiel');
define('RECIPIENT_PRIVATE_IMAGE','Het pictogram van je conversatiepartner');

/**
* Registration
*/
define('REGISTRATION','Registratie');
define('FILLOUT_TO_REGISTER','Vul je gegevens in en verzend ze om je te registreren');
define('ERROR_NICKNAME','De gekozen schuilnaam bestaat reeds');
define('ERROR_PASSWORD','Het gekozen wachtwoord is te kort of leeg');
define('ERROR_NAME','Geef je naam op');
define('ERROR_USER','Geen gebruikersnaam opgegeven');
define('ERROR_EMAIL','Verkeerde formaat');
define('ERROR_PICTURE_URL','Kan dit plaatje niet vinden');
define('ERROR_COLOR','Verkeerde formaat');
define('ERROR_MAIL_HOST','Kon geen mail verzenden naar de gespecificeerde host');
define('NAME','Voornaam Achternaam');
define('EMAIL','E-Mail adres');
define('REGISTER','Registreer');
define('PICTURE_URL','URL van een plaatje');
define('REGISTRATION_SUCCESSFULLY','Je hebt jezelf met succes geregistreerd!');
define('LOGIN_NOW','Je bent nu klaar om jezelf aan te melden. Als je niet automatisch naar de aanmeldpagina wordt gestuurd, druk dan op de link hieronder.');
define('CONFIRMATION','Bevestiging');
define('STATUS_CONFIRMATION','Status');
define('CONFIRM_SUCCESS','Je bevestiging is met succes verwerkt');
define('CONFIRM_FAILED','Je bevestiging is niet goed verwerkt');
define('CONFIRMATION_MESSAGE','Je hebt een e-mail van ons gekregen. Om de registratie te voltooien, druk op de link in deze mail!');
define('FORGOT_PASSWORD_HINT','Je moet je schuilnaam opgeven om een email te krijgen met het correcte wachtwoord..');

/**
* Configuration
*/
define('CONFIGURATION','Configuratie');
define('TEXT_COLOR','tekst kleur');
define('ADVICE','advies');
define('QUIET','geen advies');
define('ALERT','popup scherm');
define('SOUND','maak geluid');
define('SCROLL_SPEED','Scroll snelheid');
define('CHOOSE_SCROLL_SPEED','kies scroll sneldheid');
define('SCROLL_SPEED_NORMAL','normaal');
define('SCROLL_SPEED_FAST','snel');
define('SCROLL_SPEED_FASTER','sneller');
define('SCROLL_SPEED_OFF','uit');
define('SWITCH_OFF_IE_CLICK','Schakel het klikgeluid van Internet Explorer uit!');
define('CHOOSE_THEME','Kies een thema');

/**
* Profile
*/
define('PROFILE','Mijn profiel');
define('PERSONAL_DATA','persoonlijke gegevens');//a nickname follows
define('CHANGE_PROFILE','Bijwerken profiel');
define('PROFILE_UPDATA_SUCCESSFUL','Je profiel is met succes bijgewerkt');
define('PROFILE_UPDATA_NOT_SUCCESSFUL','Je profiel is niet bijgewerkt');
define('WRONG_MIME_TYPE','Het bestand heeft het verkeerde mime type');
define('IMG_FILE_TO_BIG','Het bestand is te groot');
define('IMG_SIZE_TO_BIG','De afmetingen zijn te groot');
define('SIZE_EXPECTED','Verwachtte grootte van afbeelding in pixels:');//a digit follows
define('PRIVATE_IMAGE','Privé afbeelding');
define('CONFIRMATION_MAIL_SUBJECT','Registratie bevestiging');
define('CONFIRMATION_MAIL_BODY','Om je registratie te bevestigen bij onze chat, klik op de link hieronder!');
define('ICQ_NUMBER','ICQ Nummer');
define('ERROR_ICQ_NUMBER','Geen ICQ nummer');
define('AIM_NICKNAME','AIM Schuilnaam');
define('ERROR_AIM_NICKNAME','De AIM schuilnaam is te lang.');
define('YIM_NICKNAME','Yahoo! Instant Messenger schuilnaam');
define('ERROR_YIM_NICKNAME','schuilnaam is te lang.');
define('HOMEPAGE_URL','Home pagina');
define('ERROR_HOMEPAGE_URL','Geen home pagina gevonden.');
define('BIRTHDAY','Verjaardag');
define('ERROR_BIRTHDAY','verkeerde formaat');
define('AGE','Leeftijd');
define('INTERESTS','Interesses');
define('ERROR_INTERESTS','Regel van interesses is te lang!');
define('MOTTO','Motto');
define('ERROR_MOTTO','Motto is te lang!');
define('LINES_PER_DAY','Regels per dag');
define('LOGINS_PER_DAY','Aanmeldingen per dag');

/**
* Notes
*/
define('CHATTER_NOTES','Notities voor chatter');//a nickname follows
define('UPDATE_NOTES','Bijwerken notities');
define('NOTES_UPDATED_SUCCESSFULLY','Je notities zijn met succes bijgewerkt.');
define('HINT_NOTES','Je notities zijn onleesbaar voor elke andere chatter.');
define('NOTES_NOT_UPDATED','Kon je notities niet bijwerken, misschien is er geen ruimte meer voor je notities.');

/**
* Moderation
*/
define('APPROVE','goedkeuren');
define('DISAPPROVE','afkeuren');
define('MESSAGE_FORWARDED_TO_MODERATOR','Boodschap is verzonden naar de moderator');
define('MODERATOR','Moderator');
define('VIP','VIP');

/**
* Error messages
*/
define('ERROR_WRONG_FORMAT','De data die je hebt gepost heeft het verkeerde formaat.');

/**
* Jumper
*/
define('JUMP_FAILED','Sprong gefaald!');
define('JUMP_ERROR_CONTENT','Niet geaccepteerde inhoud op doelsite gevonden!');
define('JUMP_ERROR_HOST','Host kon niet worden gevonden!');

/**
* IRC-Commands related stuff
*/
define('INLINE_HELP','Help');
define('IRC_COMMAND','IRC-Commando');
define('IRC_EXPLANATION','Uitleg');
define('IRC_ME','Wordt vervangen met je schuilnaam.');
define('IRC_MSG','Verzend een gefluisterd bericht naar gespecificeerde chatter, ook als zijn lokatie een ander kanaal is.');
define('IRC_NICK','Verzend een bericht naar gespecificeerde chatter.');
define('IRC_JOIN','Het kanaal wijzigen.');
define('IRC_QUERY','Verzoek voor een privé chat met gespecificeerde chatter, welke automatisch uitgenodigd worden voor je eigen privé kanaal.');
define('IRC_LOCATE','Zoekt naar een chatter binnen de gehele chat.');
define('IRC_IGNORE','Voegt een gespecificeerde chatter toe aan je negeerlijst.');
define('IRC_UNIGNORE','Verwijderd gespecificeerde chatter van je negeerlijst.');
define('IRC_KICK','Kicks gespecificeerde chatter. Kan alleen worden gebruikt door operators.');
define('IRC_BAN','Verwerpt een chatter voor een specifieke periode van het huidige kanaal Om dit terug te draaien, gebruik "/ban nickname 0"! Kan alleen door operators gebruikt worden.');
define('IRC_HELP','Drukt deze help af.');
define('IRC_QUIT','Verlaat deze chatsessie.');
define('LOCATED_AT','gevonden bij');//a nickname follows, nickname in front of this sentence
define('UNLOCATED','kon niet worden gevonden.');//nickname in front of this sentence

/**
* Admin area
*/
define('ADMINISTRATION','Administratie');
define('WELCOME_ADMIN','Administratie sectie');
define('PUBLIC_CHANNEL','publiek');
define('MODERATED_CHANNEL','gemodereerd');
define('PRIVATE_CHANNEL','privé');
define('CHANNEL_ADMIN','Kanaal-Administratie');
define('CHATTER_ADMIN','Chatter-Administratie');
define('ADD_CHANNEL','Kanaal aanmaken');
define('DEL_CHANNEL','Kanaal verwijderen');
define('UPDATE_CHANNEL','Kanaal bijwerken');
define('CHATTER_DELETE_SUCCESS','Chatter met succes verwijderd.');
define('CHATTER_DELETE_FAILED','Kon chatter niet verwijderen.');
define('GROUP_UPDATE_SUCCESS','De groepslidmaatschap is veranderd.');
define('GROUP_UPDATE_FAILED','Veranderen van groepslidmaatschap faalde.');
define('CHATTER_DISABLED','Chatter is uitgeschakeld');
define('CHATTER_NOT_DISABLED','Kon deze chatter niet uitschakelen');
define('CHATTER_ENABLED','Chatter ingeschakeld');
define('CHATTER_NOT_ENABLED','Kon deze chatter niet inschakelen');
define('LAST_CHANNEL','Laatste kanaal');
define('LAST_ACTIVE_TIME','Laatst gezien');
define('LAST_HOST','laatste host');
define('LAST_IP','laatste IP');
define('LAST_REFERER','laatste referer');
define('LAST_USER_AGENT','laatste user agent');
define('LAST_SESSIONID','laatste sessionId');
define('REGTIME','Registratietijd');
define('MOVE_TO_TOP','Verplaats naar boven');
define('SUCCESS_CHANNEL_UPDATE','kanaal met succes bijgewerkt.');
define('ERROR_CHANNEL_UPDATE','kon kanaal niet bijwerken.');

/**
* Confirmation messages
*/
define('CONFIRM_IGNORE','Chatter met succes toegevoegd aan de negeerlijst.');
define('CONFIRM_UNIGNORE','Chatter met success verwijderd van de negeerlijst.');
define('CONFIRM_INVITE','Chatter met success uitgenodigd.');
define('CONFIRM_DISINVITE','Chatter met success niet uitgenodigd.');
define('CONFIRM_FRIEND','Chatter met success toegevoegd aan de vriendenlijst.');


/**
* User page
*/
define('USER_PAGE','Gebruikerspagina');
define('USER_SINCE','Gebruiker sinds');//a time statement follows
define('LAST_SEEN','laatste keer gezien');//a time statement follows

/**
* Regulars' table
*/
define('REGULARS',"Regulieren tabel");
define('REGULARS_HINT','Hier zie je de meest actieve chatters per rang.');
define('SINCE_REGISTRATION','sinds registratie');
define('NOT_FOUND','kon niet worden gevonden');
define('RANK','over alle rangen');
define('ONLINE_TIME','over alle online dagen');
define('ACCOUNT_DATA','Account gegevens');
define('INDIVIDUAL_DATA','Persoonlijke gegevens');

/**
* right click menu within the output frame
*/
define('PRIVATE_CHAT_NEW_WINDOW','privé chat');

/**
* Who is online window
*/
define('WHO_IS_ONLINE','wie is online?');
define('CHANGE_CHANNEL','verander kanaal');
define('SELECT_NICK','selecteer schuilnaam');
define('OPEN_USER_PAGE','open gebruikerspagina');
define('HINT_WHO_IS_ONLINE','Hier vind je alle chatters die online zijn in de chat. Gebruik de pictogrammen achter elke schuilnaam om mee te chatten, of om met een kanaal mee te doen.');

/**
* Password reminder
*/
define('FORGOT_PASSWD_MAIL_SUBJECT','Je login wachtwoord voor '.TITLE);
define('FORGOT_PASSWD_MAIL_BODY','Deze boodschap is naar je verzonden omdat je aangegeven hebt dat
je je wachtwoord verloren bent voor '.TITLE);
define('HINT_REG_PASSWORD','Je wachtwoord moet op z\'n minst '.PASSWORD_MIN_LENGTH.' karakters lang zijn.');
define('HINT_REG_NICKNAME','Je schuilnaam mag numerieke en alfanumerieke karakters bevatten, tevens ook spaties.');
define('YOUR_PASSWORD_IS','Je wachtwoord is:');//a password follows
define('FORGOT_PASSWD_MAIL_HINT','
');
define('RETRIEVE_PASSWORD','Haal je wachtwoord op');

/**
* Statistics
*/
define('STATISTICS','Statistieken');
define('ONLINE_COUNT_LAST24h','Online in de laatste 24 uur');
define('ONLINE_TIME_AVG','Gemiddelde tijd online in minuten per dag');
define('REGISTERED_COUNT','Aantal geregistreerde chatters');
define('LAST_REGISTERED','Laatst geregistreerde chatter');
define('MAIL_COUNT','Mail aantal');
define('UNRED_MAILS','ongelezen mails');
define('MAIL_COUNT_LAST_24h','Aantal mails over de laatste 24 uur');

/**
* context sesitive help
*/
define('HINT_PASSWORD','Voer het wachtwoord in dat je via email van ons gekregen hebt. Laat dit veld leeg voor een gast login.');
define('HINT_NICKNAME','Je moet geregistreerd zijn voor een eigen schuilnaam. Laat dit veld leeg voor een gast login.');
define('HINT_CHANNELS','Er zijn drie soorten kanalen, <em>gemodereerd</em>, <em>publiek</em> en <em>privé</em>. Bij publieke kanalen zijn regels direct zichtbaar, bij gemodereerde kanalen moeten regels goedgekeurd worden door een moderator. Privé kanalen zijn alleen zichtbaar als je aangemeld bent.');
define('INFO_RANKING','Als de noodzakelijke waardes voor een rang zijn bereikt, ben je klaar voor een verbetering, en hou je de rang, zelfs als de waardes onder de grenswaarde uitkomen.');
define('HINT_ADVICE_QUIET','Als je deze optie kiest, krijg je geen melding als iemand met je probeert te praten.');
define('HINT_ADVICE_ALERT','Als je deze optie kiest, krijg je een melding in een klein <strong>popupscherm</strong>, als een chatter met je probeert te praten.');
define('HINT_ADVICE_SOUND','Als je deze optie kiest, krijg je een melding met <strong>geluid</strong>, als een chatter met je probeert te praten.');

/**
* Guestbook
*/
define('GUESTBOOK','Gastenboek');
define('GUESTBOOK_NEW_ENTRY','Voeg een nieuw gastboek item in');
define('GUESTBOOK_ENTRY_SAVED','Het nieuwe gastboek item is met succes toegevoegd');

/**
* Generic
*/
define('GUEST_NICK_PREFIX','Gast');
define('ALL_GUESTS','Gasten');
define('SUBMIT','Submit');
define('CANCEL','Annuleren');
define('SEARCH','Zoeken');
define('SEARCH_RESULTS','zoek resultaten');
define('ALERT_NEW_LINE','Iemand wil met je chatten');
define('CLOSE_WINDOW','Sluit scherm');
define('GOTO_HOME','Ga naar home pagina');
define('CONTACT_HINT','ALS je een vraag hebt, laat het ons weten!');
define('REALLY_QUESTION','Weet je het zeker?');
define('CHATTER','Chatter');
define('OPERATOR','Operator');
define('ADMIN_HINT','Voor de administratie van je chat, meldt jezelf aan als "operator" en klik binnen het invoer-scherm op "'.ADMINISTRATION.'".');
define('IMPORTANT','Belangrijk');
define('OPERATOR_PASSWORD','Het operator-wachtwoord');
define('MAKE_NOTE','Maak SVP een aantekening van je operator-wachtwoord');
define('RESTRICT','Zoek schuilnamen');
define('DENIED_FOR_GUESTS','Deze service is niet beschikbaar voor gasten!');
define('BANNED_MSG','Je bent verbannen voor het gekozen kanaal en daarom wordt je gekickt naar je eigen privé kanaal.');
define('CHATTER_COUNT','chatters online');//a digit follows
define('HIDE','verbergen');
define('GENDER','Sexe');
define('GENDER_NOTE','Je kan maar één keer een sexe kiezen!');
define('FEMALE','vrouw');
define('MALE','man');
define('PAGE_VIEWS','Pagina\'s weergegeven');
define('GRADE','Grade');
define('GRADE_ROOKIE','Rookie');
define('GRADE_MEMBER','Lid');
define('GRADE_REGULAR','Regulier');
define('GRADE_ELITE','Elite-Chatter');
define('GRADE_OPERATOR','Operator/Admin');
define('YOU_ARE_BUSY','Je praat reeds met iemand anders in het privé scherm!');
define('CHATTER_IS_BUSY','Helaas kan deze chatter niet met je praten, hij heeft het veel te druk.');
define('WANTS_TO_TALK','wil met je praten!');//nickname in front of this
define('DAYS','Dagen');
define('CHAT','Chat');
define('CHATMAIL','Chat-Mail');
define('NICKNAME_NOT_FOUND','De opgegeven schuilnaam kon niet gevonden worden.');
define('PASSWORD_HAS_BEEN_SENT','Het wachtwoord is verzonden');
define('CHOOSE_LANGUAGE','Andere taal');
define('OPTIONAL','optioneel');
define('MISCELLANEOUS','diversen');
define('SAVE','Bewaren');
define('DELETE','Verwijderen');
define('EDIT','Bewerk');
define('CREATE_NEW','maak nieuw');
define('JS_ALERT','SVP JavaScript activeren');
define('HAPPY_BIRTHDAY','Van harte gefeliciteerd!');
define('CHOOSEN','gekozen');

/**
 * PostNuke related
 */
define('PN_NOT_LOGGED_IN','Chat-Login gefaald!');
define('PN_HINT_NOT_LOGGED_IN','Om met de chat mee te doen, moet je eerst aangemeld zijn!');
?>