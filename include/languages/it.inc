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
  $Date: 2003/07/24 20:11:24 $
  $Source: /cvsroot/phpopenchat/chat3/include/languages/it.inc,v $
  $Revision: 1.1.2.1 $
*/

/**
* italian language file
*
* definizioni delle costanti per la lingua italiana
*
* @author Davide Lattanzio <danozz@libero.it> 
* @author Davide Lattanzio <davide@mandragola.com>
* @version $Id: it.inc,v 1.1.2.1 2003/07/24 20:11:24 letreo Exp $
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
define('WELCOME','Benvenuto nell\'istallazione di PHPOpenChat');
define('INTRO','Stai per entrare in una chat, daiun occhiata alle <a href="netiquette.php">regole</a> prima di entrare!');
define('GREETING','Bentornato!');
define('LOGIN_WELCOME','clicca un utente in alto a destra per altre opzioni.');
define('NICKNAME','Nickname');
define('PASSWORD','Password');
define('CHANNEL','Stanza');
define('LOGIN','Accedi');
define('GO','Vai!');
define('EXIT_CHAT','Esci dalla stanza');
define('FORGOT_PASSWORD','Password dimenticata?');
define('STORE_ACCOUNT_DATA','salva dati dell\'account');

/**
* used within chat output/input interface
*/
define('LEAVES_THE_CHAT','chiudi la chat.');
define('LEAVES_THIS_CHANNEL','lascia la stanza.');
define('IS_TOO_BUSY','è troppo occupato');//nickname in front
define('IS_NOT_ONLINE','non è connesso');
define('JOINS_THIS_CHANNEL','entra nella stanza.');
define('JOINS_THE_CHAT','entra nella chat.');
define('SAYS_TO','dice a');
define('WHISPERS_TO','sussurra a');
define('SAY_TO','dì a');
define('WHISPER_TO','sussurri a');
define('EVERYBODY','tutti');
define('INVITATION_MESSAGE','Sei stato invitato in una stanza privata! Entra: ');//a channel name follows
define('SPEAK_TO','parla a');
define('WHISPERED','sussurrato');
define('OUTPUT_FILTER','Filtri');
define('PRIVATE','solo msg privati');
define('BODIES','solo amici');
define('SYSTEM_MESSAGES','Nessuna notifica');
define('IGNORE','Ignora');
define('INVITE','Invita');
define('CONFIGURE','Configura');
define('HELP','Aiuto');
define('INFO','Informazioni');
define('GUESTS','Ospiti');
define('EMAIL_US','Scrivici');
define('NOTE_ABOUT','Informazioni su');
define('ICON_LIST','Lista Emoticon');
define('CHOOSE_CHANNEL','Scegli la stanza');
define('CHOOSE_RECIPIENT','Scegli destinataro');
define('ADD_TO_FRIENDLIST','aggiungi alla lista amici');
define('NO_CLICKETY_CLICK','Ooops, Non giocherò più con il tasto INVIA!.');
define('LINE_HAS_BEEN_SENT_TO','La tua frase è stata inviata a');//nickname follows
define('FULL','piena');
define('UNLOCK_CHANNEL','sblocca stanza');//channel name follows
define('YOU_HAVE_NEW_MAIL','Hai nuova posta!');
define('LOGOUT_SHORTLY','Sei stato disconnesso per inattività da '.CHAT_NAME.',! Vuoi rientrare?');

/**
* used within ignore-dialog
*/
define('IGNORED','ignorato');
define('IGNORE_CHATTERS','Ignora utenti');
define('IGNORED_CHATTER','l\'utente è ignorato');
define('IGNORE_CHATTER','ignora utente');
define('UNIGNORE_CHATTER','Annulla ignora utente');
define('UNIGNORED_CHATTER','l\' utente non è più ignorato');
define('HINT_IGNORE_CHATTERS','Ignora gli utenti fastidiosi.');

/**
* used within invite-dialog
*/
define('INVITE_CHATTERS','Invita utenti');
define('INVITED_CHATTERS','utenti invitati');
define('INVITE_CHATTER','invita utente');
define('DISINVITE_CHATTER','Non invitare più l\'utente');
define('DISINVITED_CHATTERS','Non invitare più gli utenti');
define('HINT_INVITE_CHATTERS','If you want to talk private within your own channel, you have to invite somebody to dispense access rights to your channel.');

/**
* used within friends-dialog
*/
define('FRIENDS','Amici');
define('ALL_CHATTERS','tutti gli utenti');
define('ADD_TO_FRIENDS','Aggiungi agli amici');
define('DEL_FRIEND','Cancella amico');
define('HINT_ADD_FRIENDS','Aggiungi utenti alla tua lista degli amici.');

/**
* used within mail-dialog
*/
define('MAIL','Mail');
define('INBOX','In arrivo');
define('OUTBOX','In uscita');
define('TRASH','Cestino');
define('COMPOSE','Scrivi');
define('REPLY','Rispondi');
define('FORWARD','Inoltra');
define('SUBJECT','Soggetto');
define('BODY','Testo');
define('SEND','Invia');
define('MAIL_SEND_HINT','Nota: Il bottone "'.SEND.'" funzionerà solo se i destinatari sono nickname esistenti!');
define('RECIPIENT_HINT','Per inserire più destinatari usare la virgola come separatore tra un nick e l\'altro.');
define('MOVE_TO_TRASH','Sposta nel cestino');
define('GET_MAIL','Controlla nuova posta');
define('DELETE_MAIL','Cancella mail');
define('SENDER','Mittente');
define('RECIPIENT','Destinatario');
define('MAIL_SEND_DATE','Data invio');
define('MAIL_RECEIVED','Ricevuta');
define('LAST_TOUCH_RECIPIENT','Conferma di lettura');
define('LAST_TOUCH_SENDER','last touch');
define('NO_FRIENDS_FOUND','nessun amico trovato');
define('NO_SUCH_RECIPIENT_FOUND','Uno dei destinatari risulta sconosciuto.');
define('BODY_TO_SHORT','Il contenuto della mail è troppo corto.');

/**
* used within help-dialog
*/
define('HELP_TITLE','Aiuto online');
define('HELP_HINT','Suggerimanto: Lascia questa finestra aperta per consultare i comandi mentre chatti');
define('HELP_SUBTITLE1','Manuale');
define('HELP_TEASER1','Qui ti verrano illustrate le funzioni base della chat!');
define('HELP_CHANNEL','Stanza: per andare da una chat all\'altra');
define('HELP_SPEAK','Box "dì a"/"sussurra": Parla o sussurra direttamente con un utente.');
define('HELP_IGNORE','Menu Ignora: ignora utenti fastidiosi.');
define('HELP_INVITE','Menu Invita: Invita utenti in una tua stanza privata.');
define('HELP_FRIENDS','Menu Amici: Puoi contrassegnare degli utenti come tuoi amici, sarai informato se sono connessi o no.');
define('HELP_CONFIGURE','Menu Configura: Qui puoi cambiare le opzioni come i colori etc. etc.');
define('HELP_MAIL','Menu Mail: Invia mail e controlla la tua casella di posta.');
define('HELP_HELP','Menu Aiuto: Dove sei ora...');
define('HELP_SUBTITLE2','Comandi stile IRC:');
define('HELP_TEASER2','Attendi...');
define('HELP_SUBTITLE3','Emoticon:');
define('HELP_TEASER3','Attendi...');

define('SMILEY_CODE','Codice');
define('SMILEY_EXPLANATION','Significato');
define('MORE_SMILEY_CODES','altri codici');
define('OWN_PRIVATE_IMAGE','Emoticon personali, caricate nel profilo');
define('RECIPIENT_PRIVATE_IMAGE','Avatar del tuo interlocutore');

/**
* Registration
*/
define('REGISTRATION','Registratione');
define('FILLOUT_TO_REGISTER','Per registrati compila i campi con i tuoi tuoi dati e inviali');
define('ERROR_NICKNAME','Il nick scelto esiste già');
define('ERROR_PASSWORD','Password troppo corta o vuota');
define('ERROR_NAME','Inserisci il tuo nome');
define('ERROR_USER','Nessun nome inserito');
define('ERROR_EMAIL','Formato errato');
define('ERROR_PICTURE_URL','Impossibile trovare l\'immagine');
define('ERROR_COLOR','Formato errato');
define('ERROR_MAIL_HOST','Impossibile inviare la mail all\'host soecificato');
define('NAME','Nome e cognome');
define('EMAIL','Indirizzo E-Mail');
define('REGISTER','registra');
define('PICTURE_URL','URL di un\'immagine');
define('REGISTRATION_SUCCESSFULLY','Registrazione andata a buon fine!');
define('LOGIN_NOW','Ora sei pronto per entrare. Se non sei reindirizzato automaticamente alla pagina di accesso clicca qui sotto');
define('CONFIRMATION','Conferma');
define('STATUS_CONFIRMATION','Status');
define('CONFIRM_SUCCESS','Conferma correta');
define('CONFIRM_FAILED','Conferma fallita');
define('CONFIRMATION_MESSAGE','Ti è stata inviata una e-mail. Per completare la registrazione clicca nel link presente nella mail!');
define('FORGOT_PASSWORD_HINT','Devi scegliere un nickname per ricevere la mail con la password di accesso.');

/**
* Configuration
*/
define('CONFIGURATION','Configurazione');
define('TEXT_COLOR','colore testo');
define('ADVICE','avvisi');
define('QUIET','nessun avviso');
define('ALERT','finestre popup');
define('SOUND','riproduci un suono');
define('SCROLL_SPEED','Velocità di scorrimento');
define('CHOOSE_SCROLL_SPEED','scegli la velocità di scorrimento');
define('SCROLL_SPEED_NORMAL','normale');
define('SCROLL_SPEED_FAST','veloce');
define('SCROLL_SPEED_FASTER','velocissimo');
define('SCROLL_SPEED_OFF','nessuno scorrimento');
define('SWITCH_OFF_IE_CLICK','Disattiva il "CLICK" di Internet Explorer!');
define('CHOOSE_THEME','Scegli un tema');

/**
* Profile
*/
define('PROFILE','profilo personale');
define('PERSONAL_DATA','dati personali');//a nickname follows
define('CHANGE_PROFILE','Aggiorna Profilo');
define('PROFILE_UPDATA_SUCCESSFUL','Il tuo profilo è stato aggiornato');
define('PROFILE_UPDATA_NOT_SUCCESSFUL','Non è stato possibile aggiornare il tuo profilo');
define('WRONG_MIME_TYPE','Il file è di un formato non correto (mime)');
define('IMG_FILE_TO_BIG','File troppo grosso');
define('IMG_SIZE_TO_BIG','Le dimensioni sono eccessise');
define('SIZE_EXPECTED','Dimensioni massime accettate in pixel:');//a digit follows
define('PRIVATE_IMAGE','Immagine privata');
define('CONFIRMATION_MAIL_SUBJECT','Conferma registrazione ');
define('CONFIRMATION_MAIL_BODY','Per confermare la tua registrazione a '.TITLE.' clicca il link sottostante!');
define('ICQ_NUMBER','Numero ICQ');
define('ERROR_ICQ_NUMBER','Nessun ICQ number');
define('AIM_NICKNAME','AIM Nickname');
define('ERROR_AIM_NICKNAME','Il nickname AIM è troppo lungo.');
define('YIM_NICKNAME','Yahoo! Instant Messenger nickname');
define('ERROR_YIM_NICKNAME','nickname troppo lungo.');
define('HOMEPAGE_URL','Home Page');
define('ERROR_HOMEPAGE_URL','Nessuna home page trovata.');
define('BIRTHDAY','Compleanno');
define('ERROR_BIRTHDAY','formato errato');
define('AGE','Età');
define('INTERESTS','Interessi');
define('ERROR_INTERESTS','Descrizione degli interessi troppo lunga!');
define('MOTTO','Citazione preferita');
define('ERROR_MOTTO','Citazione preferita troppo lunga!');
define('LINES_PER_DAY','Linee per giorno');
define('LOGINS_PER_DAY','Accessi al giorno');

/**
* Notes
*/
define('CHATTER_NOTES','Info per l\'utente');//a nickname follows
define('UPDATE_NOTES','Aggiorna informazioni');
define('NOTES_UPDATED_SUCCESSFULLY','Le tue infromazioni sono state aggiornate.');
define('HINT_NOTES','Your notes are unreadable for any other chatter.');
define('NOTES_NOT_UPDATED','Could not update your notes, may there is no space left for your notes.');

/**
* Moderation
*/
define('APPROVE','approva');
define('DISAPPROVE','disapprova');
define('MESSAGE_FORWARDED_TO_MODERATOR','Messaggio inoltrato al moderatore');
define('MODERATOR','Moderatore');
define('VIP','VIP');

/**
* Error messages
*/
define('ERROR_WRONG_FORMAT','I dati inviati sono in un formato errato.');

/**
* Jumper
*/
define('JUMP_FAILED','Cambio fallito!!');
define('JUMP_ERROR_CONTENT','Contenuto non accetabile nel sito!');
define('JUMP_ERROR_HOST','Host non trovato!');

/**
* IRC-Commands related stuff
*/
define('INLINE_HELP','Aito');
define('IRC_COMMAND','Comandi stile IRC');
define('IRC_EXPLANATION','Spiegazione');
define('IRC_ME','Sarà sotituito con il tuo nickname.');
define('IRC_MSG','Invia un msg sussurrato ad uno specifico utente anche se si triov in un\'altra stanza.');
define('IRC_NICK','invia un msg ad uno specifico utente.');
define('IRC_JOIN','Cambia stanza.');
define('IRC_QUERY','Chiedi di chattare in privato ad un utente che sarà inviato automaticamente nella tua stanza personale.');
define('IRC_LOCATE','Cerca un utente in chat.');
define('IRC_IGNORE','Aggiungi un utenti alla lista degli ignorati.');
define('IRC_UNIGNORE','Rimuovo un utente dalla lista degli ignorati.');
define('IRC_KICK','Caccia un utente. (Solo per operatori).');
define('IRC_BAN','Caccia a tempo untente dalla stanza. Per riammeterlo usa "/ban nickname 0"! (Solo per utenti).');
define('IRC_HELP','Stampa questo aiuto.');
define('IRC_QUIT','Esci dalla chat.');
define('LOCATED_AT','localizzato in');//a nickname follows, nickname in front of this sentence
define('UNLOCATED','non è stato trovato.');//nickname in front of this sentence

/**
* Admin area
*/
define('ADMINISTRATION','Amministrazione');
define('WELCOME_ADMIN','Area di ammonistrazione');
define('PUBLIC_CHANNEL','pubblico');
define('MODERATED_CHANNEL','moderato');
define('PRIVATE_CHANNEL','privato');
define('CHANNEL_ADMIN','Amministrazione Stanze');
define('CHATTER_ADMIN','amministrazione Utenti');
define('ADD_CHANNEL','Crea stanza');
define('DEL_CHANNEL','Elimina stanza');
define('UPDATE_CHANNEL','Aggiorna stanza');
define('CHATTER_DELETE_SUCCESS','Utente rimosso.');
define('CHATTER_DELETE_FAILED','Impossibile rimuovere l\'utente.');
define('GROUP_UPDATE_SUCCESS','Il grado è stato cambiato.');
define('GROUP_UPDATE_FAILED','Cambio di grado fallito.');
define('CHATTER_DISABLED','L\'utente è stato disabilitato');
define('CHATTER_NOT_DISABLED','Could not disable this chatter');
define('CHATTER_ENABLED','Chatter enabled');
define('CHATTER_NOT_ENABLED','Could not enable this chatter');
define('LAST_CHANNEL','Ultima stanza');
define('LAST_ACTIVE_TIME','Ultima attività');
define('LAST_HOST','ultimo host');
define('LAST_IP','ultimo IP');
define('LAST_REFERER','ultimo referer');
define('LAST_USER_AGENT','ultimo user agent');
define('LAST_SESSIONID','ultima sessionId');
define('REGTIME','Ora di registrazione');
define('MOVE_TO_TOP','Sposta in alto');
define('SUCCESS_CHANNEL_UPDATE','stanza aggiornata con successo.');
define('ERROR_CHANNEL_UPDATE','impossibile aggiornare la stanza.');

/**
* Confirmation messages
*/
define('CONFIRM_IGNORE','Utente aggiunto dalla lista IGNORA.');
define('CONFIRM_UNIGNORE','Utente rimosso dalla lista IGNORA.');
define('CONFIRM_INVITE','Utente invitato.');
define('CONFIRM_DISINVITE','Utente non più invitato.');
define('CONFIRM_FRIEND','Utente aggiunto alla lista degli amici.');

/**
* User page
*/
define('USER_PAGE','Pagina utente');
define('USER_SINCE','Utente dal');//a time statement follows
define('LAST_SEEN','Ultimo accesso');//a time statement follows

/**
* Regulars' table
*/
define('REGULARS',"Tabella dei abituali");
define('REGULARS_HINT','Qui puoi vedere gli utenti più attivi.');
define('SINCE_REGISTRATION','dala registrazione');
define('NOT_FOUND','non può essere trovato');
define('RANK','grado complessivo');
define('ONLINE_TIME','tempo online complessivo in giorni');
define('ACCOUNT_DATA','Dati account');
define('INDIVIDUAL_DATA','Dati personali');

/**
* right click menu within the output frame
*/
define('PRIVATE_CHAT_NEW_WINDOW','privato');

/**
* Who is online window
*/
define('WHO_IS_ONLINE','Chi c\'è online?');
define('CHANGE_CHANNEL','cambia stanza');
define('SELECT_NICK','scegli nick');
define('OPEN_USER_PAGE','Profilo utente');
define('HINT_WHO_IS_ONLINE','Tutti gli utenti online al momento. Usa le icone dietro ogni nickname è per chattare con lui o raggiungere la sua stanza.');

/**
* Password reminder
*/
define('FORGOT_PASSWD_MAIL_SUBJECT','La tua password di accesso per '.TITLE);
define('FORGOT_PASSWD_MAIL_BODY','Questo messaggio ti è stato inviato poiché ci hai informato di aver perso la password
 per '.TITLE);
define('HINT_REG_PASSWORD','La password deve essere almeno di '.PASSWORD_MIN_LENGTH.' caratteri.');
define('HINT_REG_NICKNAME','Il nickname può contenere numeri, caratteri alfanumerici e spazi.');
define('YOUR_PASSWORD_IS','La tua password è:');//a password follows
define('FORGOT_PASSWD_MAIL_HINT','
');
define('RETRIEVE_PASSWORD','Ottieni la tua password');

/**
* Statistics
*/
define('STATISTICS','Statistiche');
define('ONLINE_COUNT_LAST24h','Online nelle ultime 24h');
define('ONLINE_TIME_AVG','Tempo Online Medio in minuti al giorni');
define('REGISTERED_COUNT','Numeri di utenti registrati');
define('LAST_REGISTERED','Ultimo utente registrato');
define('MAIL_COUNT','Numero mail');
define('UNRED_MAILS','unred mails');
define('MAIL_COUNT_LAST_24h','Numero mail nelle ultime 24h');

/**
* context sesitive help
*/
define('HINT_PASSWORD','Inserisci la password cheti è stata recapitata via mail. Per l\'accesso come ospite lascia il campo vuoto.');
define('HINT_NICKNAME','Devi registrarti per ottenre un nickname personale. Per l\'accesso come ospite lascia il campo vuoto.');
define('HINT_CHANNELS','Ci sono 3 tipi di stanza, <em>moderata</em>, <em>pubblica</em> e <em>privata</em>. nei canali pubblici i msg sono visualizzati direttamente, in quelli moderati hanno bisogno dell\'aprovazione dei moderatori. Le stanze private sono leggibili sono se ne fai parte.');
define('INFO_RANKING','Se raggiungi punti necassari per passare di livello manterrai il livello raggiunto anche se in futuro saranno necessari più punti per quel livello di quelli che attualmente possiedi.');
define('HINT_ADVICE_QUIET','Se scegli questa opzione non sarai informato degli utenti che desiderano parlare con te.');
define('HINT_ADVICE_ALERT','Se scegli questa opzione sarai informato con un piccolo <strong>popup</strong> che qualche utente desidera parlare con te.');
define('HINT_ADVICE_SOUND','Se scegli questa opzione sarai informato tramite un <strong>suono</strong> che qualcuno vuole parlare con te.');

/**
* Guestbook
*/
define('GUESTBOOK','Guestbook');
define('GUESTBOOK_NEW_ENTRY','Aggiungi un msg al guestbook');
define('GUESTBOOK_ENTRY_SAVED','Il nuovo msg è stato salvato');

/**
* Generic
*/
define('GUEST_NICK_PREFIX','Ospite');
define('ALL_GUESTS','Ospiti');
define('SUBMIT','Invia');
define('CANCEL','Annulla');
define('SEARCH','Cerca');
define('SEARCH_RESULTS','risultati della ricerca');
define('ALERT_NEW_LINE','Qualcuno desidera chattare con te');
define('CLOSE_WINDOW','Chiudi');
define('GOTO_HOME','Vai alla home page');
define('CONTACT_HINT','Se hai proposte faccelo sapere!');
define('REALLY_QUESTION','Sei sicuro?');
define('CHATTER','Utente');
define('OPERATOR','Operatore');
define('ADMIN_HINT','Per amministrare la tua chat entra come "operator" e clicca nella finestra di input su "'.ADMINISTRATION.'".');
define('IMPORTANT','Importante');
define('OPERATOR_PASSWORD','La password Operatore');
define('MAKE_NOTE','Si prega di prendere nota della password Operatore');
define('RESTRICT','Cerca i nickname');
define('DENIED_FOR_GUESTS','Siamo spiacenti, questo servizio non è disponibile agli ospiti!');
define('BANNED_MSG','Sei stato escluso dalla stanza scelta così sei stato cacciato nella tua stanza privata.');
define('CHATTER_COUNT','utenti online');//a digit follows
define('HIDE','nascondi');
define('GENDER','Sesso');
define('GENDER_NOTE','Puoi scegliere il sesso solo una volta!');
define('FEMALE','donna');
define('MALE','uomo');
define('PAGE_VIEWS','Pagine viste');
define('GRADE','Livello');
define('GRADE_ROOKIE','Novizio');
define('GRADE_MEMBER','Chatter');
define('GRADE_REGULAR','Abituè');
define('GRADE_ELITE','Elìte');
define('GRADE_OPERATOR','SysOp/Admin');
define('YOU_ARE_BUSY','Stai parlando già con qualcun altro nella tua stanza privata!');
define('CHATTER_IS_BUSY','Sfortunatamente questo utente è troppo impegnato per parlare con te.');
define('WANTS_TO_TALK','desidera chattere con te!');//nickname in front of this
define('DAYS','Giorni');
define('CHAT','Chat');
define('CHATMAIL','Chat-Mail');
define('NICKNAME_NOT_FOUND','Il nickname inserito non è stato trovato.');
define('PASSWORD_HAS_BEEN_SENT','Password inviata');
define('CHOOSE_LANGUAGE','Altra lingua');
define('OPTIONAL','opzionale');
define('MISCELLANEOUS','varie');
define('SAVE','Salva');
define('DELETE','Cancella');
define('EDIT','Edita');
define('CREATE_NEW','crea nuova');
define('JS_ALERT','Si prega di attivare JavaScript dal browser');
define('HAPPY_BIRTHDAY','Buon compleano! ;)');
define('CHOOSEN','scelto');

/**
 * PostNuke related
 */
define('PN_NOT_LOGGED_IN','Accesso alla chat fallito!');
define('PN_HINT_NOT_LOGGED_IN','Per entrare in chat devi prima acedere con nome e password!');
?>