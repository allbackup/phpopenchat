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
  $Date: 2003/08/19 18:54:07 $
  $Source: /cvsroot/phpopenchat/chat3/include/languages/es.inc,v $
  $Revision: 1.1.2.1 $
*/

/**
* english language file
* 
* defines constants for an english language interface
* 
* @author Michael Oertel <michael@ortelius.de>
* @version $Id: es.inc,v 1.1.2.1 2003/08/19 18:54:07 letreo Exp $
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
define('WELCOME','Bienvenido al Chat libre de phpopenchat!');
define('INTRO','Esto es un Chat, deberias leer el <a href="netiquette.php">Reglamento</a> antes de Unirte! Para entrar debes ser usuario registrado');
define('GREETING','Gusto en verte !');
define('LOGIN_WELCOME','click en el nick para ver mas opciones del usuario.');
define('NICKNAME','Nickname');
define('PASSWORD','Password');
define('CHANNEL','Canal');
define('LOGIN','Login');
define('GO','Go');
define('EXIT_CHAT','Salir del chat');
define('FORGOT_PASSWORD','Olvidaste tu  password?');
define('STORE_ACCOUNT_DATA','Guardar informacion de la cuenta');

/**
* used within chat output/input interface
*/
define('LEAVES_THE_CHAT','Salio del Chat.');
define('LEAVES_THIS_CHANNEL','Salio del Canal.');
define('IS_TOO_BUSY','esta muy ocupado');//nickname in front
define('IS_NOT_ONLINE','no esta en linea');
define('JOINS_THIS_CHANNEL','ingresa al canal.');
define('JOINS_THE_CHAT','ingresa al chat.');
define('SAYS_TO','les dice a');
define('WHISPERS_TO','les secretea a');
define('SAY_TO','le dice a');
define('WHISPER_TO','le secretea a');
define('EVERYBODY','todos');
define('INVITATION_MESSAGE','Estas invitado a un canal privado ! porfavor ingresa al canal:');//a channel name follows
define('SPEAK_TO','le habla a');
define('WHISPERED','secreteo');
define('OUTPUT_FILTER','Filtro de Salida');
define('PRIVATE','solo texto privado');
define('BODIES','solo amigos');
define('SYSTEM_MESSAGES','No mensjaes del sistema');
define('IGNORE','Ignorar');
define('INVITE','Invitar');
define('CONFIGURE','Configurar');
define('HELP','Ayuda');
define('INFO','Informacion');
define('GUESTS','Invitados');
define('EMAIL_US','Escribenos');
define('NOTE_ABOUT','Note about');
define('ICON_LIST','Lista de Iconos');
define('CHOOSE_CHANNEL','Selecciona Canal');
define('CHOOSE_RECIPIENT','Selecciona recipiente');
define('ADD_TO_FRIENDLIST','agregar a lista de amigos');
define('NO_CLICKETY_CLICK','Seguro, no volvere a dar muchos cicks en el boton de enviar en el futuro.');
define('LINE_HAS_BEEN_SENT_TO','Tu linea fue enviada a');//nickname follows
define('FULL','lleno');
define('UNLOCK_CHANNEL','Abrir Canal');//channel name follows
define('YOU_HAVE_NEW_MAIL','Tienes un Email!');
define('LOGOUT_SHORTLY','Seras expulsado del Chat  '.CHAT_NAME.', por inactividad ! Actualizar ?');

/**
* used within ignore-dialog
*/
define('IGNORED','ignored');
define('IGNORE_CHATTERS','Ignorar usuarios');
define('IGNORED_CHATTER','usuario ignorado');
define('IGNORE_CHATTER','ignorar usuario');
define('UNIGNORE_CHATTER','considerar  chatter');
define('UNIGNORED_CHATTER','chatter considerado');
define('HINT_IGNORE_CHATTERS','Aqui puedes ignorar acosadores.');

/**
* used within invite-dialog
*/
define('INVITE_CHATTERS','Invitar usuarios');
define('INVITED_CHATTERS','usuarios invitados');
define('INVITE_CHATTER','invitar usuario');
define('DISINVITE_CHATTER','desinvitar usuario');
define('DISINVITED_CHATTERS','usuarios desinvitados');
define('HINT_INVITE_CHATTERS','Si usted desea hablar privado dentro de su propio canal, usted tiene que invitar a alguien que dispense los derechos de acceso a su canal .');

/**
* used within friends-dialog
*/
define('FRIENDS','Friends');
define('ALL_CHATTERS','Todos los usuarios');
define('ADD_TO_FRIENDS','Agregar a amigos');
define('DEL_FRIEND','Quitar Amigo');
define('HINT_ADD_FRIENDS','Aqui puedes agregar amigos a tu lista.');

/**
* used within mail-dialog
*/
define('MAIL','Mail');
define('INBOX','Buzon');
define('OUTBOX','Envios');
define('TRASH','Basura');
define('COMPOSE','Escribir');
define('REPLY','Contestar');
define('FORWARD','Reenviar');
define('SUBJECT','Titulo');
define('BODY','Contenido');
define('SEND','Enviar');
define('MAIL_SEND_HINT','Nota: El Boton "'.SEND.'" Funciona unicamente  si el usuario  existe !');
define('RECIPIENT_HINT','Puedes separar destinatarios por comas.');
define('MOVE_TO_TRASH','Mover a basura');
define('GET_MAIL','Checar nuevos mensajes');
define('DELETE_MAIL','Borrar Correo');
define('SENDER','Envia');
define('RECIPIENT','Destinatario');
define('MAIL_SEND_DATE','Fecha de Envio');
define('MAIL_RECEIVED','recivido');
define('LAST_TOUCH_RECIPIENT','Confirmacion de lectura');
define('LAST_TOUCH_SENDER','ultimo contacto');
define('NO_FRIENDS_FOUND','no se encontraron amigos');
define('NO_SUCH_RECIPIENT_FOUND','Uno de los destinatarios no fue encontrado.');
define('BODY_TO_SHORT','El Contenido del mail es muy corto.');

/**
* used within help-dialog
*/
define('HELP_TITLE','Ayuda');
define('HELP_HINT','Hint: Dejar esta ventana abierta, chattear y comandos aqui');
define('HELP_SUBTITLE1','Manual');
define('HELP_TEASER1','Aqui se muestran las funciones basicas del chat!');
define('HELP_CHANNEL','Canales: Cambiar entre canales accesible');
define('HELP_SPEAK','Box "le dice a"/"secreteo": hablar directamente o secretear a un usuario.');
define('HELP_IGNORE','Menu Ignorar: Here you can ignore chatters.');
define('HELP_INVITE','Menu Invitar: Invitar usuarios a tu canal privado.');
define('HELP_FRIENDS','Menu Amigos: Puedes marcar a otros usuarios como amigos, el sistema te indicara, que amigos estan  on/offline.');
define('HELP_CONFIGURE','Menu Configurar: Personaliza tu chat, color , etc.');
define('HELP_MAIL','Menu Mail: Envia correos a los otros usuarios  y checa tu correo.');
define('HELP_HELP','Menu Ayuda: En donde cres que estas ?');
define('HELP_SUBTITLE2','Comandos IRC:');
define('HELP_TEASER2','Procesando solicitud ...');
define('HELP_SUBTITLE3','Caritas:');
define('HELP_TEASER3','Trabajando ...');

define('SMILEY_CODE','Codigo');
define('SMILEY_EXPLANATION','Explicacion');
define('MORE_SMILEY_CODES','mas codigos');
define('OWN_PRIVATE_IMAGE','Sube tu propio Icono');
define('RECIPIENT_PRIVATE_IMAGE','Icono para con quien conversas');

/**
* Registration
*/
define('REGISTRATION','Registro');
define('FILLOUT_TO_REGISTER','Llena tus datos y envialos para registro');
define('ERROR_NICKNAME','El Nick que quieres ya esta ocupado');
define('ERROR_PASSWORD','Password muy corto o nulo');
define('ERROR_NAME','Escribe tu nombre');
define('ERROR_USER','No escribiste tu nombre');
define('ERROR_EMAIL','Formato Incorrecto');
define('ERROR_PICTURE_URL','No se encuentra la imagen');
define('ERROR_COLOR','formato incorrecto');
define('ERROR_MAIL_HOST','No se pudo enviar el Email');
define('NAME','Nombre y apellido');
define('EMAIL','Direccion de E-Mail');
define('REGISTER','Registrate !! es gratis');
define('PICTURE_URL','URL de una foto que quieras agrerar ?');
define('REGISTRATION_SUCCESSFULLY','Registro completado!');
define('LOGIN_NOW','Ya puedes ingresar. Si la pagina no cambia sola da click en el link de abajo');
define('CONFIRMATION','Confirmacion');
define('STATUS_CONFIRMATION','Estado');
define('CONFIRM_SUCCESS','Tu confirmacion a tenido exito');
define('CONFIRM_FAILED','Tu confirmacion fallo');
define('CONFIRMATION_MESSAGE','Te hemos enviado un mail de confirmacion. No seras dado de alta hasta que leas las instrucciones posteriores de este Email, verificalo ahora !');
define('FORGOT_PASSWORD_HINT','Debes poner tu  nickname, para recibir un  mail con el password.');

/**
* Configuracion
*/
define('CONFIGURATION','Configuracion');
define('TEXT_COLOR','color de texto');
define('ADVICE','Consejo');
define('QUIET','No consejos');
define('ALERT','Ventana popup');
define('SOUND','tocar sonido');
define('SCROLL_SPEED','Velocidad del Scroll');
define('CHOOSE_SCROLL_SPEED','choose scroll speed');
define('SCROLL_SPEED_NORMAL','normal');
define('SCROLL_SPEED_FAST','rapido');
define('SCROLL_SPEED_FASTER','mas rapido');
define('SCROLL_SPEED_OFF','off');
define('SWITCH_OFF_IE_CLICK','Apagar el sonido de click del Internet Explorer!');
define('CHOOSE_THEME','Escoger un Tema de Escritorio');

/**
* Profile
*/
define('PROFILE','mi perfil');
define('PERSONAL_DATA','informacion personal');//a nickname follows
define('CHANGE_PROFILE','Actualizar Perfil');
define('PROFILE_UPDATA_SUCCESSFUL','Se actualizo tu perfil con exito');
define('PROFILE_UPDATA_NOT_SUCCESSFUL','Tu perfil no fue actualizado');
define('WRONG_MIME_TYPE','El Archivo en de un tipo incorrecto');
define('IMG_FILE_TO_BIG','El archivo es muy grande');
define('IMG_SIZE_TO_BIG','Las medidas son muy grandes');
define('SIZE_EXPECTED','Tamano en pixels :');//a digit follows
define('PRIVATE_IMAGE','Imagen Privada');
define('CONFIRMATION_MAIL_SUBJECT','Confrimacion de Registro');
define('ICQ_NUMBER','Nummero de ICQ');
define('ERROR_ICQ_NUMBER','No tengo ICQ');
define('AIM_NICKNAME','AIM Nick?');
define('ERROR_AIM_NICKNAME','El nick de  AIM es muy largo.');
define('YIM_NICKNAME','servicio messenger de Yahoo!, pon tu nick si tienes');
define('ERROR_YIM_NICKNAME','el nick es muy largo.');
define('HOMEPAGE_URL','Pagina Web');
define('ERROR_HOMEPAGE_URL','No se encontro pagina web.');
define('BIRTHDAY','Cumpleanos');
define('ERROR_BIRTHDAY','Formato incorrecto');
define('AGE','Edad');
define('INTERESTS','Intereses personales');
define('ERROR_INTERESTS','texto de intereses muy largo!');
define('MOTTO','Lema');
define('ERROR_MOTTO','Lema muy largo!');
define('LINES_PER_DAY','Lineas por dia');
define('LOGINS_PER_DAY','Logins por dia');

/**
* Notes
*/
define('CHATTER_NOTES','Notas para el usuario');//a nickname follows
define('UPDATE_NOTES','Actualizar notas');
define('NOTES_UPDATED_SUCCESSFULLY','Tus notas se actualizaron con exito.');
define('HINT_NOTES','Tus notas no pueden ser leidas por otros usuarios.');
define('NOTES_NOT_UPDATED','No se puede actualizar tus notas, ya notienes espacio.');

/**
* Moderation
*/
define('APPROVE','aprovar');
define('DISAPPROVE','desaprovar');
define('MESSAGE_FORWARDED_TO_MODERATOR','El mensaje fue reenviado al moderador');
define('MODERATOR','Moderador');
define('VIP','VIP');

/**
* Error messages
*/
define('ERROR_WRONG_FORMAT','La informacion que enviaste esta en mal formato.');

/**
* Jumper
*/
define('JUMP_FAILED','Examinacion fallo!');
define('JUMP_ERROR_CONTENT','Contenido inaceptable en el sitio que enviaste!');
define('JUMP_ERROR_HOST','No se encontro el servidor!');

/**
* IRC-Commands related stuff
*/
define('INLINE_HELP','Ayuda');
define('IRC_COMMAND','Comandos IRC');
define('IRC_EXPLANATION','Explicacion');
define('IRC_ME','Sera reemplazado con tu Nick.');
define('IRC_MSG','Enviar un mensaje en susurro a un usuario aunque este en otro canal.');
define('IRC_NICK','Envia un mensaje a un usuario especifico.');
define('IRC_JOIN','Cambia de canal.');
define('IRC_QUERY','Solicitar chat privado con un usuario especifico.');
define('IRC_LOCATE','Busca un usuario en todo el chat.');
define('IRC_IGNORE','Agrega al usuario a  la lista de Ignorados.');
define('IRC_UNIGNORE','Sacar de la lista de Ignorados al usuario especifico.');
define('IRC_KICK','Expulsa al usuario , solo para adminsitradores.');
define('IRC_BAN','Bloquear a un usuario por el tiempo especificado. Para desbloquear "/ban nickname 0"! Solo para administradores.');
define('IRC_HELP','Imprime esta Ayuda.');
define('IRC_QUIT','Salir de esta secion.');
define('LOCATED_AT','ubicado en');//a nickname follows, nickname in front of this sentence
define('UNLOCATED','no se pudo encontrar.');//nickname in front of this sentence

/**
* Admin area
*/
define('ADMINISTRATION','Administracion');
define('WELCOME_ADMIN','Area de Administracion');
define('PUBLIC_CHANNEL','publico');
define('MODERATED_CHANNEL','moderado');
define('PRIVATE_CHANNEL','privado');
define('CHANNEL_ADMIN','Administracion el Canal');
define('CHATTER_ADMIN','Administracion de usuarios');
define('ADD_CHANNEL','Crear Canal');
define('DEL_CHANNEL','Borrar Canal');
define('UPDATE_CHANNEL','Actualizar Canal');
define('CHATTER_DELETE_SUCCESS','Usuario removido con exito.');
define('CHATTER_DELETE_FAILED','No se pudo  remover al usuario.');
define('GROUP_UPDATE_SUCCESS','La membresia de grupo a cambiado.');
define('GROUP_UPDATE_FAILED','La membresia de grupo no se pudo cambiar.');
define('CHATTER_DISABLED','Usuario desabilitado');
define('CHATTER_NOT_DISABLED','No se pudo desabilitar al  usuario');
define('CHATTER_ENABLED','Usuario Activado');
define('CHATTER_NOT_ENABLED','No se pudo activar al usuario');
define('LAST_CHANNEL','Ultimo Canal');
define('LAST_ACTIVE_TIME','Ultimo visitado');
define('LAST_HOST','Ultimo servidor');
define('LAST_IP','ultima IP');
define('LAST_REFERER','Ultima referencia');
define('LAST_USER_AGENT','ultimo agente de usuario');
define('LAST_SESSIONID','ultima sesion de ID');
define('REGTIME','Tiempo de registro');
define('MOVE_TO_TOP','Mover hasta arriba');
define('SUCCESS_CHANNEL_UPDATE','Actualizacion de Canal exitosa.');
define('ERROR_CHANNEL_UPDATE','No se pudo actualizar el canal.');

/**
* Confirmation messages
*/
define('CONFIRM_IGNORE','Usuario agregado a la lista de Ignorados.');
define('CONFIRM_UNIGNORE','Usuario ha sido removido de la lista de Ignorados.');
define('CONFIRM_INVITE','Usuario ha sido invitado.');
define('CONFIRM_DISINVITE','Chatter ha sido desinvitado.');
define('CONFIRM_FRIEND','El Usuario ha sido agregado a la lista de amigos.');

/**
* User page
*/
define('USER_PAGE','Pagina del usuario');
define('USER_SINCE','Usuario desde');//a time statement follows
define('LAST_SEEN','ultima ves que se le vio');//a time statement follows

/**
* Regulars' table
*/
define('REGULARS',"Tabla de recurrentes");
define('REGULARS_HINT','Estos son los usuarios mas activos por grados.');
define('SINCE_REGISTRATION','desde el registro');
define('NOT_FOUND','no se pudo encontrar');
define('RANK','sobre todos los rangos');
define('ONLINE_TIME','sobre todos los dias en linea');
define('ACCOUNT_DATA','Datos de la Cuenta');
define('INDIVIDUAL_DATA','Informacion personal');

/**
* right click menu within the output frame
*/
define('PRIVATE_CHAT_NEW_WINDOW','chat privado');

/**
* Who is online window
*/
define('WHO_IS_ONLINE','quien esta en linea?');
define('CHANGE_CHANNEL','cambiar canal');
define('SELECT_NICK','seleccionar nick');
define('OPEN_USER_PAGE','abrir pagina de usuario');
define('HINT_WHO_IS_ONLINE','Quien esta en linea. Usa los iconos de al lado para chatear con el o unirte a su canal.');

/**
* Password reminder
*/
define('FORGOT_PASSWD_MAIL_SUBJECT','Tu password para '.TITLE);
define('FORGOT_PASSWD_MAIL_BODY','Este mail te esta llegando por que nos informaste que perdiste tu password '.TITLE);
define('HINT_REG_PASSWORD','Tu password debe ser al menos de  '.PASSWORD_MIN_LENGTH.' caracteres.');
define('HINT_REG_NICKNAME','Tu nick puede contener numeros o espacios en blanco.');
define('YOUR_PASSWORD_IS','Tu password es:');//a password follows
define('FORGOT_PASSWD_MAIL_HINT','
');
define('RETRIEVE_PASSWORD','Devuelve tu password');

/**
* Statistics
*/
define('STATISTICS','Estadisticas');
define('ONLINE_COUNT_LAST24h','En linea en las ultimas 24h');
define('ONLINE_TIME_AVG','Promedio de horas en linea');
define('REGISTERED_COUNT','Usuarios del chat registrados');
define('LAST_REGISTERED','Ultimo usuario registrado');
define('MAIL_COUNT','Cuenta de mail');
define('UNRED_MAILS','Mail no leidos');
define('MAIL_COUNT_LAST_24h','Cuenta de mails en las ultimas 24h');

/**
* context sesitive help
*/
define('HINT_PASSWORD','Coloca el password que te enviamos , para entrar como invitado ( si es perimitido) dejalo en blanco.');
define('HINT_NICKNAME','Debes registrarte como usuario para obtner un nickname, si esta permitido puedes ingresar como invitado dejando estos espacios en blanco.');
define('HINT_CHANNELS','Hay tres tipos de canales, <em>moderado</em>, <em>publico</em> y <em>privado</em>. En canales publicoslas lineas se muestran directo, en canales moderados las lineas deben ser aprovadas por el operador para ser mostradas y en canales privados las lineas se muestran solo si ingresaste debidamente en el canal.');
define('INFO_RANKING','Si los valores necesarios para una fila se alcanzan, usted esta listo para un adelanto y usted liderea la fila, incluso si los valores bajan bajo fronteras necesarias en el futuro.');
define('HINT_ADVICE_QUIET','Si marcas estas opcion seras avisado cuando un usuario desee hablar contigo.');
define('HINT_ADVICE_ALERT','Si marcas estas opcion seras avisado cuando un usuario desee hablar contigo con un<strong>popup window</strong>.');
define('HINT_ADVICE_SOUND','Si marcas estas opcion seras avisado con un sonido cuando un usuario desee hablar contigo <strong>sound</strong>.');

/**
* Guestbook
*/
define('GUESTBOOK','Libro de visitas');
define('GUESTBOOK_NEW_ENTRY','Agregar firma al libro de visitas');
define('GUESTBOOK_ENTRY_SAVED','La firma a sido agregada');

/**
* Generic
*/
define('GUEST_NICK_PREFIX','Invitado');
define('ALL_GUESTS','Invitados');
define('SUBMIT','Enviar');
define('CANCEL','Cancelar');
define('SEARCH','Buscar');
define('SEARCH_RESULTS','buscar resultados');
define('ALERT_NEW_LINE','Alguien quiere chatear contigo');
define('CLOSE_WINDOW','Cerrar ventana');
define('GOTO_HOME','Ir a inicio');
define('CONTACT_HINT','Si tiene alguna duda por favor indiquenoslo !');
define('REALLY_QUESTION','Esta seguro?');
define('CHATTER','Usuario');
define('OPERATOR','Operador');
define('ADMIN_HINT','Para utilizar el chat por primera ves entra como operator el password esta en la base de datos que instalaste "'.ADMINISTRATION.'".');
define('IMPORTANT','Importante');
define('OPERATOR_PASSWORD','Password del operador');
define('MAKE_NOTE','Por favor anote su password de operador !');
define('RESTRICT','Buscar  nicknames');
define('DENIED_FOR_GUESTS','Este servicio no esta disponible para invitados!');
define('BANNED_MSG','Estas bloqueado del canal seleccionado , asi que seras regresado a tu canal.');
define('CHATTER_COUNT','Usuarios en linea');//a digit follows
define('HIDE','ocultar');
define('GENDER','Sexo');
define('GENDER_NOTE','Puedes escoger solo una vez!');
define('FEMALE','Femenino');
define('MALE','Masculino');
define('PAGE_VIEWS','Vista de paginas');
define('GRADE','Grado');
define('GRADE_ROOKIE','Rookie');
define('GRADE_MEMBER','Member');
define('GRADE_REGULAR','Regular');
define('GRADE_ELITE','Elite-Chatter');
define('GRADE_OPERATOR','Operator/Admin');
define('YOU_ARE_BUSY','Ya hablaste con alguien en la ventana rpivada!');
define('CHATTER_IS_BUSY','Este usuario esta muy ocupado y no podra chater contigo.');
define('WANTS_TO_TALK','quiere hablar contigo!');//nickname in front of this
define('DAYS','Tage');
define('CHAT','Chat');
define('CHATMAIL','Chat-Mail');
define('NICKNAME_NOT_FOUND','No se encontro el nickname.');
define('PASSWORD_HAS_BEEN_SENT','El password ha sido enviado');
define('CHOOSE_LANGUAGE','Otro Idioma');
define('OPTIONAL','optcional');
define('MISCELLANEOUS','miscelaneo');
define('SAVE','Guardar');
define('DELETE','Borrar');
define('EDIT','Editar');
define('CREATE_NEW','crear nuevo');
define('JS_ALERT','Por favor active JavaScript');
define('HAPPY_BIRTHDAY','Feliz Cumple !!');
define('CHOOSEN','escogido');

/**
 * PostNuke related
 */
define('PN_NOT_LOGGED_IN','Error de Login!');
define('PN_HINT_NOT_LOGGED_IN','Para entrar al chat debes logear primero!');




define('CONFIRMATION_MAIL_BODY','Reglamento del Chat de phpopenchat
GENERALES

  CASTIGOS Y AMONESTACIONES
 A) Quienes infrinjan alguna de las reglas de conducta de este reglamento se le enviará un primera llamada de atención a su dirección de correo electrónico, misma que será notificada a todos los usuarios. Si vuelve a reincidir será dado de baja de forma definitiva del Chat de Discusión.
 B) En el caso de que la transgresión al Reglamento se haya hecho con premeditación, alevosía y ventaja, así como en pleno prejuicio de alguna persona o institución, se procederá a dar de baja al usuario sin aviso alguno y sin posibilidades de que vuelva a ser aceptado en el Chat de Discusión.
 C) Dependiendo de la gravedad de la falta cometida por el usuario, el Editor, el Web Master, la revista phpopenchat o quien resulte afectado, se reservan el derecho de ejecutar una acción legal en contra de la(s) persona(s) o grupo(s) que resulten responsables con base a las leyes establecidas en los Códigos Penales respectivos del país en cuestión así como de INTERNIC.

Para aceptar estos terminos y activar tu cuenta  da click en  la siguiente liga

');


?>
