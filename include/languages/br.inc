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
  $Date: 2004/02/12 13:40:41 $
  $Source: /cvsroot/phpopenchat/chat3/include/languages/br.inc,v $
  $Revision: 1.1.2.3 $
*/

/**
* portuguese language file
* 
* defines constants for an english language interface
* 
* @author Michael Oertel <michael@ortelius.de>
* @version $Id: br.inc,v 1.1.2.3 2004/02/12 13:40:41 letreo Exp $
* @localization author Robespierre Sentelhas <pierresent@mandic.com.br>
* @version $Id: br.inc,v 1.1.2.3 2004/02/12 13:40:41 letreo Exp $
*/

/* * * * * * * * * * CHAT MODULE * * * * * * * * * */
define('CHARACTER_ENCODING','ISO-8859-1');

/**
* title for html header
*/
define('TITLE','Chat - ENERGIA.USP.BR');

/**
* used within index.php
*/
define('WELCOME','Bem vindo a instalação do PHPOpenChat');
define('INTRO','Este é um Chat, você pode ler suas <a href="netiquette.php">regras aqui,</a> antes de juntar-se a nós!');
define('GREETING','É bom vê-lo novamente!');
define('LOGIN_WELCOME','clique no canto superior direito dos participantes para obter mais opções.');
define('NICKNAME','Nickname');
define('PASSWORD','Senha');
define('CHANNEL','Canal');
define('LOGIN','Login');
define('GO','>>>');
define('EXIT_CHAT','Encerrar o Chat');
define('FORGOT_PASSWORD','Esqueceu sua senha?');
define('STORE_ACCOUNT_DATA','Guarde dados do login');

/**
* used within chat output/input interface
*/
define('LEAVES_THE_CHAT','sai do chat.');
define('LEAVES_THIS_CHANNEL','sai deste canal.');
define('IS_TOO_BUSY','está sobrecarregado');//nickname in front
define('IS_NOT_ONLINE','não está online');
define('JOINS_THIS_CHANNEL','junta-se ao canal.');
define('JOINS_THE_CHAT','junta-se ao chat.');
define('SAYS_TO','diz para');
define('WHISPERS_TO','comenta para');
define('SAY_TO','diz para');
define('WHISPER_TO','comenta para');
define('EVERYBODY','todos');
define('INVITATION_MESSAGE','Você está convidado a juntar-se ao canal privado! Por favor vá para o canal:');//a channel name follows
define('SPEAK_TO','fala para');
define('WHISPERED','comentário');
define('OUTPUT_FILTER','Filtro de saída');
define('PRIVATE','Apenas para texto privado');
define('BODIES','Apenas para amigos');
define('SYSTEM_MESSAGES','Não existem mensagens do sistema');
define('IGNORE','Ignora');
define('INVITE','Convida');
define('CONFIGURE','Configura');
define('HELP','Ajuda');
define('INFO','Informação');
define('GUESTS','Convidados');
define('EMAIL_US','Envia Email');
define('NOTE_ABOUT','Nota sobre');
define('ICON_LIST','Lista de Smiley-Icons');
define('CHOOSE_CHANNEL','Muda o canal');
define('CHOOSE_RECIPIENT','Escolhe a troca');
define('ADD_TO_FRIENDLIST','adiciona a lista de amigos');
define('NO_CLICKETY_CLICK','Eu não ficarei clicando no botão de Envio no futuro.');
define('LINE_HAS_BEEN_SENT_TO','Sua linha foi enviada para ');//nickname follows
define('FULL','cheio');
define('UNLOCK_CHANNEL','canal desbloqueado');//channel name follows
define('YOU_HAVE_NEW_MAIL','Você tem novo Email!');
define('LOGOUT_SHORTLY','Você será desconectado de '.CHAT_NAME.', porque está inativo! Reinicia?');

/**
* used within ignore-dialog
*/
define('IGNORED','ignored');
define('IGNORE_CHATTERS','Ignore participantes');
define('IGNORED_CHATTER','Participantes ignorados');
define('IGNORE_CHATTER','ignore participante');
define('UNIGNORE_CHATTER','re-considere o participante');
define('UNIGNORED_CHATTER','re-considere o participante');
define('HINT_IGNORE_CHATTERS','Aqui você pode ignorar os incômodos.');

/**
* used within invite-dialog
*/
define('INVITE_CHATTERS','Convida participantes');
define('INVITED_CHATTERS','Participantes convidados');
define('INVITE_CHATTER','convida participante');
define('DISINVITE_CHATTER','retira convite para participante');
define('DISINVITED_CHATTERS','retira convite para disinvited participante');
define('HINT_INVITE_CHATTERS','Se desejar conversar particularmente no seu canal, você tem que convidar e dispor de acesso ao seu canal.');

/**
* used within friends-dialog
*/
define('FRIENDS','Amigos');
define('ALL_CHATTERS','Todos participantes');
define('ADD_TO_FRIENDS','Adicionar a amigos');
define('DEL_FRIEND','Remover amigo');
define('HINT_ADD_FRIENDS','Neste diálogo você pode adicionar amigos na sua lista de amigos.');

/**
* used within mail-dialog
*/
define('MAIL','Correspondência');
define('INBOX','Caixa de Entrada');
define('OUTBOX','Caixa de Saída');
define('TRASH','Lixo');
define('COMPOSE','Compor');
define('REPLY','Responder');
define('FORWARD','Encaminhar');
define('SUBJECT','Assunto');
define('BODY','Corpo');
define('SEND','Enviar');
define('MAIL_SEND_HINT','Nota: O botão-"'.SEND.'" trabalhará corretamente apenas se você preencher o nickname de um dos destinatário!');
define('RECIPIENT_HINT','é permitido mais de uma vírgula na separação dos destinatário.');
define('MOVE_TO_TRASH','Mover para o lixo');
define('GET_MAIL','Pegar as novas mensagens');
define('DELETE_MAIL','Excluir correspondência');
define('SENDER','Remetente');
define('RECIPIENT','Destinatário');
define('MAIL_SEND_DATE','Enviar data');
define('MAIL_RECEIVED','recebido');
define('LAST_TOUCH_RECIPIENT','Lendo a confirmação');
define('LAST_TOUCH_SENDER','último toque');
define('NO_FRIENDS_FOUND','nenhum amigo encontrado');
define('NO_SUCH_RECIPIENT_FOUND','Um dos destinatários não pode ser encontrado.');
define('BODY_TO_SHORT','O conteúdo de sua correspondência é muito pequeno.');

/**
* used within help-dialog
*/
define('HELP_TITLE','Ajuda do Chat');
define('HELP_HINT','Dica: Deixe esta janela aberta. bata papo e veja os comandos aqui.');
define('HELP_SUBTITLE1','Manual');
define('HELP_TEASER1','Aqui apresentaremos as funcionalidades básicas do Chat!');
define('HELP_CHANNEL','Canal: Salte entre os canais disponíveis');
define('HELP_SPEAK','Caixa "diz para"/"sussurrou": Fala ou comenta diretamente ao participante.');
define('HELP_IGNORE','Menu Ignore: Aqui você pode ignorar participantes.');
define('HELP_INVITE','Menu Convida: Convida participantes para seu canal privado.');
define('HELP_FRIENDS','Menu Amigos: Você pode marcar outros participantes como seus amigos, o sistema mostrará, que amigos estão online/offline.');
define('HELP_CONFIGURE','Menu Configura: Nesta área você pode mudar suas preferências como cor, etc.');
define('HELP_MAIL','Menu Mail: Envia uma mensagem para um participante e verifica sua caixa de entrada.');
define('HELP_HELP','Menu Ajuda: Você está aqui neste momento ...');
define('HELP_SUBTITLE2','Comandos IRC:');
define('HELP_TEASER2','Trabalho em progresso ...');
define('HELP_SUBTITLE3','Smileys:');
define('HELP_TEASER3','Trabalho em progresso ...');
define('SMILEY_CODE','Código');
define('SMILEY_EXPLANATION','Explicação');
define('MORE_SMILEY_CODES','mais códigos');
define('OWN_PRIVATE_IMAGE','Seu ícone escolhido, foi carregado no seu arquivo de configurações');
define('RECIPIENT_PRIVATE_IMAGE','O ícone do seu parceiro de conversa');

/**
* Registration
*/
define('REGISTRATION','Registro');
define('FILLOUT_TO_REGISTER','Complete os seus dados e envie o registro');
define('ERROR_NICKNAME','O nickname escolhido já existe');
define('ERROR_PASSWORD','A senha é muito curta ou foi deixada em branco');
define('ERROR_NAME','Por favor entre com seu nome');
define('ERROR_USER','Nenhum nome de usuário foi dado');
define('ERROR_EMAIL','Formato errado');
define('ERROR_PICTURE_URL','Não foi possível achar a imagem');
define('ERROR_COLOR','Formato errado');
define('ERROR_MAIL_HOST','Não pode ser enviado uma correspondência para o servidor especificado');
define('NAME','Primeiro nome e último nome');
define('EMAIL','Endereço de E-Mail');
define('REGISTER','registro');
define('PICTURE_URL','Endereço URL da imagem');
define('REGISTRATION_SUCCESSFULLY','Seu registro foi feito com sucesso!');
define('LOGIN_NOW','Você está pronto para o login. Se você não retornar a tela de login, clique no link abaixo.');
define('CONFIRMATION','Confirmação');
define('STATUS_CONFIRMATION','Status');
define('CONFIRM_SUCCESS','Sua confirmação ocorreu satisfatóriamente');
define('CONFIRM_FAILED','Sua confirmação falhou');
define('CONFIRMATION_MESSAGE','Você recebeu um Email nosso. Para completar seu registro, por favor clique no link que aparece dentro do Email!');
define('FORGOT_PASSWORD_HINT','Você precisa completar seu nickname para poder receber sua senha por Email.');

/**
* Configuration
*/
define('CONFIGURATION','Configuração');
define('TEXT_COLOR','Cor do texto');
define('ADVICE','recomendação');
define('QUIET','nenhuma recomendação');
define('ALERT','janela popup');
define('SOUND','tocar um som');
define('SCROLL_SPEED','Velocidade da barra de rolagem');
define('CHOOSE_SCROLL_SPEED','escolha a velocidade da barra de rolagem');
define('SWITCH_OFF_IE_CLICK','Desativa o som do click no Internet Explorer!');
define('CHOOSE_THEME','Escolha um tema');

/**
* Profile
*/
define('PROFILE','meus dados.');
define('PERSONAL_DATA','dados pessoais');//a nickname follows
define('CHANGE_PROFILE','Atualiza minhas escolhas/configurações');
define('PROFILE_UPDATA_SUCCESSFUL','Suas escolhas/configurações foram atualizadas com sucesso');
define('PROFILE_UPDATA_NOT_SUCCESSFUL','Suas escolhas/configurações não foram atualizadas');
define('WRONG_MIME_TYPE','O arquivo tem um tipo MIME errado');
define('IMG_FILE_TO_BIG','O arquivo é muito grande');
define('IMG_SIZE_TO_BIG','As dimensões são muito grandes');
define('SIZE_EXPECTED','Tamanho esperado em pixels:');//a digit follows
define('PRIVATE_IMAGE','Imagem privada');
define('CONFIRMATION_MAIL_SUBJECT','Confirmação do registro');
define('CONFIRMATION_MAIL_BODY','Para confirmar seu registro no nosso Chat, clique no link abaixo!');
define('ICQ_NUMBER','Número ICQ');
define('ERROR_ICQ_NUMBER','Nenhum número ICQ');
define('AIM_NICKNAME','AIM Nickname');
define('ERROR_AIM_NICKNAME','O AIM nickname é muito longo.');
define('YIM_NICKNAME','Yahoo! Instant Messenger nick name');
define('ERROR_YIM_NICKNAME','nickname é muito longo.');
define('HOMEPAGE_URL','Página Web');
define('ERROR_HOMEPAGE_URL','Nenhuma página Web encontrada.');
define('BIRTHDAY','Aniversário');
define('ERROR_BIRTHDAY','formato errado');
define('AGE','Idade');
define('INTERESTS','Interesses');
define('ERROR_INTERESTS','Frase com interesses é muito longa!');
define('MOTTO','Motto');
define('ERROR_MOTTO','Motto muito longo!');
define('LINES_PER_DAY','Linhas por dia');
define('LOGINS_PER_DAY','Logins por dia');

/**
* Notes
*/
define('CHATTER_NOTES','Notas para o participante');//a nickname follows
define('UPDATE_NOTES','Atualiza notas');
define('NOTES_UPDATED_SUCCESSFULLY','Suas notas foram atualizadas com sucesso.');
define('HINT_NOTES','Suas notas estão invisíveis para qualquer outro participante.');
define('NOTES_NOT_UPDATED','As notas não puderam ser atualizadas, pode não haver mais espaço para suas notas.');

/**
* Moderation
*/
define('APPROVE','aprova');
define('DISAPPROVE','desaprova');
define('MESSAGE_FORWARDED_TO_MODERATOR','Mensagem foi encaminhada ao Moderador');
define('MODERATOR','Moderador');
define('VIP','VIP');

/**
* Error messages
*/
define('ERROR_WRONG_FORMAT','O dado que você postou está com o formato incorreto.');

/**
* Jumper
*/
define('JUMP_FAILED','O salgo falhou!');
define('JUMP_ERROR_CONTENT','Conteúdo inaceitável pelo site alvo!');
define('JUMP_ERROR_HOST','Servidor não pode ser encontrado!');

/**
* IRC-Commands related stuff
*/
define('INLINE_HELP','Ajuda');
define('IRC_COMMAND','Comando IRC');
define('IRC_EXPLANATION','Explanação');
define('IRC_ME','Será substituído por seu nickname.');
define('IRC_MSG','Envia uma mensagem tipo sussurro para um participante especificado, mesmo que esteja em outro canal.');
define('IRC_NICK','Envia uma mensagem para um participante especificado.');
define('IRC_JOIN','Muda de canal.');
define('IRC_QUERY','Requesita uma conversa privativa com participantes especificados, que são convidados automaticamente, dentro do seu próprio canal.');
define('IRC_LOCATE','Procura um participante dentro de um determinado chat.');
define('IRC_IGNORE','Adiciona um participante especificado na sua lista de ignorados.');
define('IRC_UNIGNORE','Remove um participante especificado na sua lista de ignorados.');
define('IRC_KICK','Exclue um determinado participante. Pode ser usado apenas por operadores.');
define('IRC_BAN','Bane um determinado participante por um período do canal atual. Para admitir use "/ban nickname 0"! Pode ser usado apenas por operadores.');
define('IRC_HELP','Imprime esta ajuda.');
define('IRC_QUIT','Encerra a sessão de Chat.');
define('LOCATED_AT','localizado em ');//a nickname follows, nickname in front of this sentence
define('UNLOCATED','naõ pode ser encontrado.');//nickname in front of this sentence

/**
* Admin area
*/
define('ADMINISTRATION','Administração');
define('WELCOME_ADMIN','Área administrativa');
define('PUBLIC_CHANNEL','público');
define('MODERATED_CHANNEL','moderado');
define('PRIVATE_CHANNEL','privado');
define('CHANNEL_ADMIN','Canal-Administrativo');
define('CHATTER_ADMIN','Participante-Administração');
define('ADD_CHANNEL','Criar canal');
define('DEL_CHANNEL','Excluir canal');
define('UPDATE_CHANNEL','Atualizar canal');
define('CHATTER_DELETE_SUCCESS','Participante removido com sucesso.');
define('CHATTER_DELETE_FAILED','Não é possível remover o participante.');
define('GROUP_UPDATE_SUCCESS','O grupo de membros foi alterado com sucesso.');
define('GROUP_UPDATE_FAILED','A atualização do grupo de membros falhou.');
define('CHATTER_DISABLED','Participante está desabilitado');
define('CHATTER_NOT_DISABLED','Não é possível desabilitar o participante');
define('CHATTER_ENABLED','Participante habilitado');
define('CHATTER_NOT_ENABLED','Não é possível habilitar o participante');
define('LAST_CHANNEL','Último canal');
define('LAST_ACTIVE_TIME','Último visto');
define('LAST_HOST','último servidor');
define('LAST_IP','último IP');
define('LAST_REFERER','última referência');
define('LAST_USER_AGENT','último user agent');
define('LAST_SESSIONID','última sessionId');
define('REGTIME','Horário de registro');
define('MOVE_TO_TOP','Mover para o topo');
define('SUCCESS_CHANNEL_UPDATE','canal atualizado com sucesso.');
define('ERROR_CHANNEL_UPDATE','não é possível atualizar o canal.');

/**
* Confirmation messages
*/
define('CONFIRM_IGNORE','Participante adicionado com sucesso a lista de ignorados.');
define('CONFIRM_UNIGNORE','Participante removido com sucesso a lista de ignorados.');
define('CONFIRM_INVITE','Participante convidado com sucesso.');
define('CONFIRM_DISINVITE','Participante desconvidado com sucesso..');
define('CONFIRM_FRIEND','Participante adicionado a lista de amigos com sucesso.');

/**
* User page
*/
define('USER_PAGE','Página do usuário');
define('USER_SINCE','Usuário desde');//a time statement follows
define('LAST_SEEN','última participação');//a time statement follows

/**
* Regulars' table
*/
define('REGULARS','Ranking');
define('REGULARS_HINT','Aqui você consulta o rank dos participantes mais ativos.');
define('SINCE_REGISTRATION','desde o registro');
define('NOT_FOUND','não pode ser encontrado');
define('RANK','acima de todo rank');
define('ONLINE_TIME','acima de todos os dias online');
define('ACCOUNT_DATA','Dados da conta');
define('INDIVIDUAL_DATA','Dados pessoais');

/**
* right click menu within the output frame
*/
define('PRIVATE_CHAT_NEW_WINDOW','Chat privado');

/**
* Who is online window
*/
define('WHO_IS_ONLINE','Quem está online?');
define('CHANGE_CHANNEL','Muda canal');
define('SELECT_NICK','seleciona nick');
define('OPEN_USER_PAGE','abre página do usuário');
define('HINT_WHO_IS_ONLINE','Aqui você encontra todos os participantes online no chat. Use os ícones abaixo de cada nickname para convidar ao chat ou juntar-se a um canal.');

/**
* Password reminder
*/
define('FORGOT_PASSWD_MAIL_SUBJECT','Sua senha de login para '.TITLE);
define('FORGOT_PASSWD_MAIL_BODY','Esta mensagem está sendo enviada porque você nos informou que perdeu sua senha da '.TITLE);
define('HINT_REG_PASSWORD','Sua senha deve ter '.PASSWORD_MIN_LENGTH.' caracteres.');
define('HINT_REG_NICKNAME','Seu nickname pode conter caracteres numéricos e alfanuméricos como também espaços em branco.');
define('YOUR_PASSWORD_IS','Sua password é:');//a password follows
define('FORGOT_PASSWD_MAIL_HINT','
');
define('RETRIEVE_PASSWORD','Recuperar senha');

/**
* Statistics
*/
define('STATISTICS','Estatísticas');
define('ONLINE_COUNT_LAST24h','Online nas últimas 24h');
define('ONLINE_TIME_AVG','Média de tempo online em minutos por dia');
define('REGISTERED_COUNT','Contador de participantes registrados');
define('LAST_REGISTERED','Último participante registrado');
define('MAIL_COUNT','Conta de EMail');
define('UNRED_MAILS','unred Emails');
define('MAIL_COUNT_LAST_24h','Contador de Emails enviados nas últimas 24h');

/**
* context sesitive help
*/
define('HINT_PASSWORD','Entre com a senha enviada por Email por nós. Se quiser entrar como convidado não preencha os campos de entrada.');
define('HINT_NICKNAME','Você deve registrar-se para ter seu próprio nickname. Para acessar como convidado deixe os campos de entrada em branco.');
define('HINT_CHANNELS','Existem três tipos de canal, <em>moderado</em>, <em>público</em> and <em>privado</em>. No canal público, linhas são mostradas diretamente, no canal moderado, as linhas devem ser aprovadas por um moderador. No canal privado são mostradas apenas as linhas se você estiver logado no canal.');
define('INFO_RANKING','Se os valores para o rank for detectado, você estará pronto para uma melhoria e para acessar seu rank.');
define('HINT_ADVICE_QUIET','Se você escolher esta opção, você não será notificado se o Chat tentar falar com você.');
define('HINT_ADVICE_ALERT','Se você escolher esta opção, você receberá um alerta com um pequeno <strong>popup window</strong>, se algum participante tentar falar com você.');
define('HINT_ADVICE_SOUND','Se você escolher esta opção, você receberá um  <strong>som</strong> de alerta, se algum participante tentar falar com você.');

/**
* Guestbook
*/
define('GUESTBOOK','Livro de Visitas');
define('GUESTBOOK_NEW_ENTRY','Adicione uma entrada no nosso livro de visitas');
define('GUESTBOOK_ENTRY_SAVED','A nova entrada no livro de visitas foi adicionada com sucesso');

/**
* Generic
*/
define('GUEST_NICK_PREFIX','Visitante');
define('ALL_GUESTS','Visitantes');
define('SUBMIT','Submeter');
define('CANCEL','Cancelar');
define('SEARCH','Buscar');
define('SEARCH_RESULTS','Buscar resultados');
define('ALERT_NEW_LINE','Alguém deseja conversar com você');
define('CLOSE_WINDOW','Fechar janela');
define('GOTO_HOME','Vá para a página principal');
define('CONTACT_HINT','Se você tiver questões, deixe-nos conhecê-las!');
define('REALLY_QUESTION','Você está certo?');
define('CHATTER','Participante');
define('OPERATOR','Operador');
define('ADMIN_HINT','Para administrar seu Chat, faça seu login como "operator" e clicando dentro da caixa de "'.ADMINISTRATION.'".');
define('IMPORTANT','Importante');
define('OPERATOR_PASSWORD','Senha do operador');
define('MAKE_NOTE','Por favor anote sua senha de operador');
define('RESTRICT','Busca nicknames');
define('DENIED_FOR_GUESTS','Este serviço não está disponível para visitantes!');
define('BANNED_MSG','Você foi banido deste canal e só pode participar através de seu canal privado.');
define('CHATTER_COUNT','Online');//a digit follows
define('HIDE','escondido');
define('GENDER','Sexo');
define('GENDER_NOTE','Você pode escolher o sexo apenas uma vez!');
define('FEMALE','feminino');
define('MALE','masculino');
define('PAGE_VIEWS','Visualização de páginas');
define('GRADE','Grade');
define('GRADE_ROOKIE','Rookie');
define('GRADE_MEMBER','Membro');
define('GRADE_REGULAR','Regular');
define('GRADE_ELITE','Elite');
define('GRADE_OPERATOR','Operador/Admin');
define('YOU_ARE_BUSY','Você pode falar com qualquer um na janela privada!');
define('CHATTER_IS_BUSY','Infelizmente este participante não pode conversar com você pois está ocupado.');
define('WANTS_TO_TALK','deseja falar com você!');//nickname in front of this
define('DAYS','Tage');
define('CHAT','Chat');
define('CHATMAIL','Chat-Mail');
define('NICKNAME_NOT_FOUND','O nickname dado não pode ser encontrado.');
define('PASSWORD_HAS_BEEN_SENT','A senha já foi enviada');
define('CHOOSE_LANGUAGE','Outra linguagem');
define('OPTIONAL','opcional');
define('MISCELLANEOUS','miscelânea');
define('SAVE','Salvar');
define('DELETE','Deletar');
define('EDIT','Editar');
define('CREATE_NEW','criar novo');
define('JS_ALERT','Por favor ative o Javascript');
define('HAPPY_BIRTHDAY','Feliz aniversário!');
define('CHOOSEN','mudado');

/**
 * PostNuke related
 */
define('PN_NOT_LOGGED_IN','Login no Chat falhou!');
define('PN_HINT_NOT_LOGGED_IN','Para juntar-se ao chat, você deve fazer o login primeiro!');
?>