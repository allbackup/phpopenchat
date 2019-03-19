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
  $Source: /cvsroot/phpopenchat/chat3/include/languages/fr.inc,v $
  $Revision: 1.1.2.4 $
*/

/**
* french language file
* 
* defines constants for an english language interface
* 
* @author Marc ARNAERT <marnaert@organic.fr>
* @version $Id: fr.inc,v 1.1.2.4 2004/02/12 13:40:42 letreo Exp $
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
define('WELCOME','Bienvenue dans notre salon de discussion PHPOpenChat ');
define('INTRO','C est un salon de discussion, Vous devez lire la <a href="netiquette.php">charte d utilisation</a> avant de nous rejoindre!<BR> Utilisez votre pseudo et le mot de passe du site pour vous connecter !');
define('GREETING','C est bon de vous revoir à nouveau!');
define('LOGIN_WELCOME','click sur un chatteur dans le coin supérieur droit pour découvrir les options avancées.');
define('NICKNAME','Pseudonyme');
define('PASSWORD','Mot de passe');
define('CHANNEL','Salon');
define('LOGIN','Connexion');
define('GO','Go');
define('EXIT_CHAT','Quitter le chat');
define('FORGOT_PASSWORD','Vous avez oublié votre mot de passe?');
define('STORE_ACCOUNT_DATA','Garder vos paramétres de connexion');

/**
* used within chat output/input interface
*/
define('LEAVES_THE_CHAT','a quitté le chat.');
define('LEAVES_THIS_CHANNEL','a quitté ce salon.');
define('IS_TOO_BUSY','est occupé(e)');//nickname in front
define('IS_NOT_ONLINE','n est pas en ligne');
define('JOINS_THIS_CHANNEL','nous a rejoint sur le salon :');
define('JOINS_THE_CHAT','viens d arriver.');
define('SAYS_TO','dit');
define('WHISPERS_TO','chuchote à');
define('SAY_TO','lui dire');
define('WHISPER_TO','lui chuchoter');
define('EVERYBODY','à tout le monde');
define('INVITATION_MESSAGE','Vous êtes invité à rejoindre un salon privé ! Merci de vous rendre dans le salon:');//a channel name follows
define('SPEAK_TO','parle à');
define('WHISPERED','chuchote');
define('OUTPUT_FILTER','Filtre de dialogue');
define('PRIVATE','en privé seulement');
define('BODIES','amis seulement');
define('SYSTEM_MESSAGES','Pas de messages systèmes');
define('IGNORE','Ignorer');
define('INVITE','Inviter');
define('CONFIGURE','Configurer');
define('HELP','Aide');
define('INFO','Information');
define('GUESTS','Invité(e)s');
define('EMAIL_US','Ecrivez-nous');
define('NOTE_ABOUT','Information au sujet de');
define('ICON_LIST','Liste de Smiley');
define('CHOOSE_CHANNEL','Choisi ton salon');
define('CHOOSE_RECIPIENT','Choisi ton destinataire');
define('ADD_TO_FRIENDLIST','add to friends list');
define('NO_CLICKETY_CLICK','Merci de ne plus cliquer de trop sur ce bouton dans le futur.');
define('LINE_HAS_BEEN_SENT_TO','Votre message viens d\'etre envoyé à');//nickname follows
define('FULL','plein');
define('UNLOCK_CHANNEL','unlock channel');//channel name follows
define('YOU_HAVE_NEW_MAIL','Vous avez un nouveau message!');
define('LOGOUT_SHORTLY','Vous venez d être déconnecté du salon '.CHAT_NAME.', à cause de votre inactivité ?');

/**
* used within ignore-dialog
*/
define('IGNORED','ignored');
define('IGNORE_CHATTERS','Ignorer les chatteurs');
define('IGNORED_CHATTER','chatteur ignoré');
define('IGNORE_CHATTER','ignorer un chatteur');
define('UNIGNORE_CHATTER','Ne pas ignorer les chatteurs');
define('UNIGNORED_CHATTER','chatteur non ignoré');
define('HINT_IGNORE_CHATTERS','Ici vous pouvez ignorer les imbéciles.');

/**
* used within invite-dialog
*/
define('INVITE_CHATTERS','Inviter les chatteurs');
define('INVITED_CHATTERS','chatteur(s) invité(s)');
define('INVITE_CHATTER','inviter chatteur');
define('DISINVITE_CHATTER','chatteur non invité');
define('DISINVITED_CHATTERS','chatteur(s) non invité(s)');
define('HINT_INVITE_CHATTERS','Si vous désirez parler en privé en utilisant votre propre salon, vous devez inviter cette personne afin de lui donner les droits d acces à votre salon.');

/**
* used within friends-dialog
*/
define('FRIENDS','Ami(e)s');
define('ALL_CHATTERS','Tout les chatteurs');
define('ADD_TO_FRIENDS','Rajouter en ami(e)s');
define('DEL_FRIEND','Enlever en ami(e)s');
define('HINT_ADD_FRIENDS','Ici vous pouvez rajouter des personnes dans votre liste d ami(e)s.');

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
define('REGISTRATION','Enregistrement');
define('FILLOUT_TO_REGISTER','Remplissez ces champs pour vous enregistrer');
define('ERROR_NICKNAME','Le Pseudonyme choisi existe déja');
define('ERROR_PASSWORD','Le mot de passe est trop court ou vide');
define('ERROR_NAME','Merci de complêter par votre nom ou prénom');
define('ERROR_USER','Pas de pseudonyme donné');
define('ERROR_EMAIL','Format non valide');
define('ERROR_PICTURE_URL','Can\'t find this picture');
define('ERROR_COLOR','Wrong format');
define('ERROR_MAIL_HOST','Could not send a mail to the specified host');
define('NAME','Prénom puis Nom');
define('EMAIL','Adresse E-Mail');
define('REGISTER','S\'enregistrer');
define('PICTURE_URL','URL de votre image');
define('REGISTRATION_SUCCESSFULLY','Votre enregistrement viens de s\'effectuer avec succés!');
define('LOGIN_NOW','Vous allez vous connecter maintenant. Si vous n\'êtes pas redirigé automatiquement sur la page de connexion, merci de cliquer sur le lien ci-dessous');
define('CONFIRMATION','Confirmation');
define('STATUS_CONFIRMATION','Status');
define('CONFIRM_SUCCESS','Votre confirmation viens d\'être acceptée avec succés!');
define('CONFIRM_FAILED','Your confirmation failed');
define('CONFIRMATION_MESSAGE','Nous venons de vous envoyer un e-mail. Pour compléter votre enregistrement, cliquez sur le lien dans votre email!');
define('FORGOT_PASSWORD_HINT','Vous devez remplir votre pseudonyme, afin de recevoir un mail contenant votre mot de passe.');

/**
* Configuration
*/
define('CONFIGURATION','Configuration');
define('TEXT_COLOR','Couleur du texte');
define('ADVICE','Avertissements ');
define('QUIET','pas d\'avertissement');
define('ALERT','Fenêtre popup');
define('SOUND','Jouer une musique');
define('SCROLL_SPEED','Vitesse d\'affichage');
define('CHOOSE_SCROLL_SPEED','choisissez votre vitesse');
define('SWITCH_OFF_IE_CLICK','Desactiver le beep de Internet Explorer!');
define('CHOOSE_THEME','Choisissez le thème et la couleur de votre chat');

/**
* Profile
*/
define('PROFILE','mon profil');
define('PERSONAL_DATA','personal data');//a nickname follows
define('CHANGE_PROFILE','Mettre à jour');
define('PROFILE_UPDATA_SUCCESSFUL','Your profile was successfully updated');
define('PROFILE_UPDATA_NOT_SUCCESSFUL','Your profile was not updated');
define('WRONG_MIME_TYPE','The file has a wrong mime type');
define('IMG_FILE_TO_BIG','The file is too big');
define('IMG_SIZE_TO_BIG','The dimensions are too big');
define('SIZE_EXPECTED','Expected image size in pixels:');//a digit follows
define('PRIVATE_IMAGE','Image personnelle');
define('CONFIRMATION_MAIL_SUBJECT','Registration confirmation');
define('CONFIRMATION_MAIL_BODY','To confirm your registration at our chat, click the link below!');
define('ICQ_NUMBER','ICQ Nummer');
define('ERROR_ICQ_NUMBER','No ICQ number');
define('AIM_NICKNAME','AIM Nickname');
define('ERROR_AIM_NICKNAME','The AIM nickname is to long.');
define('YIM_NICKNAME','Yahoo! Instant Messenger nick name');
define('ERROR_YIM_NICKNAME','nickname is to long.');
define('HOMEPAGE_URL','Adresse de votre Page Web');
define('ERROR_HOMEPAGE_URL','No home page found.');
define('BIRTHDAY','Jour de naissance');
define('ERROR_BIRTHDAY','wrong format');
define('AGE','Age');
define('INTERESTS','Centres d\'Interêts');
define('ERROR_INTERESTS','String of interests to long!');
define('MOTTO','Devise');
define('ERROR_MOTTO','Motto to long!');
define('LINES_PER_DAY','Lignes par jour');
define('LOGINS_PER_DAY','Logins par jour');

/**
* Notes
*/
define('CHATTER_NOTES','Notification pour le chatteur');//a nickname follows
define('UPDATE_NOTES','Notification de mises à jour');
define('NOTES_UPDATED_SUCCESSFULLY','Your notes has been updated successfully.');
define('HINT_NOTES','Your notes are unreadable for any other chatter.');
define('NOTES_NOT_UPDATED','Could not update your notes, may there is no space left for your notes.');

/**
* Moderation
*/
define('APPROVE','approuvé');
define('DISAPPROVE','desapprouvé');
define('MESSAGE_FORWARDED_TO_MODERATOR','Ce Message a été envoyé au Modérateur');
define('MODERATOR','Modérateur');
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
define('REGULARS',"Tableau de fréquentation");
define('REGULARS_HINT','Voici la liste des chatteurs les plus actifs.');
define('SINCE_REGISTRATION','depuis l enregistrement');
define('NOT_FOUND','could not be found');
define('RANK','over all rank');
define('ONLINE_TIME','Somme de tous les jours');
define('ACCOUNT_DATA','Données de connexion');
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
define('STATISTICS','Statistiques');
define('ONLINE_COUNT_LAST24h','En ligne ces dernières 24h');
define('ONLINE_TIME_AVG','Moyenne journaliére de minutes de chat ');
define('REGISTERED_COUNT','Nombre de chatteurs enregistrés');
define('LAST_REGISTERED','Le dernier chatteur enregistré');
define('MAIL_COUNT','Nombre de Mails');
define('UNRED_MAILS','Mails non lu');
define('MAIL_COUNT_LAST_24h','Nombre de Mail ces dernières 24h');

/**
* context sesitive help
*/
define('HINT_PASSWORD','Enter the password what you got by a mail from us. For a guest login leave this input field empty.');
define('HINT_NICKNAME','You must register to get your own nickname. For a guest login leave this input field empty.');
define('HINT_CHANNELS','There are three kinds of channels, <em>moderated</em>, <em>public</em> and <em>private</em>. In public channels, lines are shown directly, in moderated channels, lines must be approved by a moderator. Private channels are shown only, if you are logged in.');
define('INFO_RANKING','If the necessary values for a rank are reached, you are ready for an advancement and you keeps the rank, even if the values fall under the necessary borders in the future.');
define('HINT_ADVICE_QUIET','Si vous choisissez cette option, vous ne serez pas averti si un chatteur désire vous parler en particulier.');
define('HINT_ADVICE_ALERT','Si vous choisissez cette option, vous recevrez un petit <strong>popup en fenétre</strong>, si un chatteur désire vous parler en particulier.');
define('HINT_ADVICE_SOUND','Si vous choisissez cette option, vous entendrez une <strong>musique</strong>, si un chatteur désire vous parler en particulier.');

/**
* Guestbook
*/
define('GUESTBOOK','Guestbook');
define('GUESTBOOK_NEW_ENTRY','Add a new guestbook entry');
define('GUESTBOOK_ENTRY_SAVED','The new guestbook entry has been saved successfully');

/**
* Generic
*/
define('GUEST_NICK_PREFIX','Invité');
define('ALL_GUESTS','Invité(s)');
define('SUBMIT','Envoyer');
define('CANCEL','Abandonner');
define('SEARCH','Rechercher');
define('SEARCH_RESULTS','search results');
define('ALERT_NEW_LINE','Quelqu\'un veut chatter avec vous');
define('CLOSE_WINDOW','Fermer la fenêtre');
define('GOTO_HOME','Goto home page');
define('CONTACT_HINT','IF you have question, please let us know!');
define('REALLY_QUESTION','You are sure?');
define('CHATTER','Chatteur');
define('OPERATOR','Operator');
define('ADMIN_HINT','Pour administrer ce chat, connectez vous en "operator" et cliquez dans la fenêtre en bas à droite sur "'.ADMINISTRATION.'".');
define('IMPORTANT','Important');
define('OPERATOR_PASSWORD','The Operator-Password');
define('MAKE_NOTE','Please make a note of your operator-password');
define('RESTRICT','Chercher un pseudo');
define('DENIED_FOR_GUESTS','This service is not available for guests!');
define('BANNED_MSG','Your are banned for the chosen channel and so you are kicked into your private channel.');
define('CHATTER_COUNT','Connecté(e)s');//a digit follows
define('HIDE','cacher');
define('GENDER','Genre');
define('GENDER_NOTE','You can choose a gender only one time!');
define('FEMALE','femme');
define('MALE','homme');
define('PAGE_VIEWS','Page Vus');
define('GRADE','Grade');
define('GRADE_ROOKIE','Les Meilleurs');
define('GRADE_MEMBER','Membre');
define('GRADE_REGULAR','Regulier');
define('GRADE_ELITE','Elite');
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
define('OPTIONAL','optionel');
define('MISCELLANEOUS','miscellaneous');
define('SAVE','Save');
define('DELETE','Delete');
define('EDIT','Edit');
define('CREATE_NEW','create new');
define('JS_ALERT','Please activate JavaScript');
define('HAPPY_BIRTHDAY','Happy Birthday!');
define('CHOOSEN','choisir');

/**
 * PostNuke related
 */
define('PN_NOT_LOGGED_IN','Chat-Login failed!');
define('PN_HINT_NOT_LOGGED_IN','To join the chat, you have to login first!');
?>