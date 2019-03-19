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
  $Source: /cvsroot/phpopenchat/chat3/include/languages/Attic/ru.inc,v $
  $Revision: 1.1.2.2 $
*/

/**
* russian language file
* 
* defines constants for an russian language interface
* 
* @author Michael Oertel <michael@ortelius.de>
* @version $Id: ru.inc,v 1.1.2.2 2004/02/12 13:40:42 letreo Exp $
*/

/* * * * * * * * * * CHAT MODULE * * * * * * * * * */
define('CHARACTER_ENCODING','windows-1251');

/**
* title for html header
*/
define('TITLE','PHPOpenChat');

/**
* used within index.php
*/
define('WELCOME','Добро пожаловать на PHPOpenChat');
define('INTRO','прежде чем присоединиться к нам, прочтите внимательно следующие <a href="netiquette.php">правила</a>');
define('GREETING','Рады увидеть Вас снова!');
define('LOGIN_WELCOME','кликните на чатере, в верхнем правом углу, для вызова сервисного меню');
define('NICKNAME','НИК');
define('PASSWORD','Пароль');
define('CHANNEL','Комната');
define('LOGIN','Вход');
define('GO','Вперед');
define('EXIT_CHAT','Выход');
define('FORGOT_PASSWORD','Забыли свой пароль?');
define('STORE_ACCOUNT_DATA','запомнить мои данные');
//since version 3.1.0

/**
* used within chat output/input interface
*/
define('LEAVES_THE_CHAT','покинул чат.');
define('LEAVES_THIS_CHANNEL','покинул комнату.');
define('GOES_TO_CHANNEL','идет в комнату:'); //channel name follows
define('IS_TOO_BUSY','занят'); //nickname in front
define('IS_NOT_ONLINE','не доступен');
define('JOINS_THIS_CHANNEL','вошел в комнату.');
define('JOINS_THE_CHAT','вошел в чат.');
define('SAYS_TO','говорит');
define('WHISPERS_TO','шепчется с');
define('SAY_TO','говорить с');
define('WHISPER_TO','шептаться с');
define('EVERYBODY','всем');
define('INVITATION_MESSAGE','Вас приглашает в приватную комнату:'); //a channel name follows
define('SPEAK_TO','говорить с');
define('WHISPERED','шептать');
define('OUTPUT_FILTER','Фильтр сообщений');
define('PRIVATE','только частные');
define('BODIES','только друзья');
define('SYSTEM_MESSAGES','без системных');
define('IGNORE','Игнорировать');
define('INVITE','Пригласить');
define('CONFIGURE','Настройки');
define('HELP','Помощь');
define('INFO','Информация');
define('GUESTS','Гости');
define('EMAIL_US','Намылить админу');
define('NOTE_ABOUT','Записка');
define('ICON_LIST','Смайлы');
define('CHOOSE_CHANNEL','Выбери комнату');
define('CHOOSE_RECIPIENT','Выбери получателя');
define('ADD_TO_FRIENDLIST','добавить в список друзей');
define('NO_CLICKETY_CLICK','Перестаньте беспорядочно кликать по кнопке.');
define('LINE_HAS_BEEN_SENT_TO','Ваше сообщение было отправлено '); //nickname follows
define('FULL','полон');
define('UNLOCK_CHANNEL','разблокировать комнату');//channel name follows
define('YOU_HAVE_NEW_MAIL','Поступила почта!');
define('LOGOUT_SHORTLY','Вы были отключены от сайта '.CHAT_NAME.' из-за неактивности! Обновить?');
define('FORBIDDEN_WORD','Было удалено запрещенное слово.');
define('RELOAD_MAKES_NO_SENSE', 'Этот фрейм имеет автоматическую перезагрузку!');
define('FOLLOWING_NOTE_ADDED','Записка успешно добавлена');
define('ADD_SELECTION_TO_NOTES','добавить в записки');
//since version 3.1.0
define('POC_ABOUT','О PHPOpenChat');
define('HINT_RECIPIENT_AMBIGUOUS','Незаполненный НИК! Пожалуйста, укажите получателя.');
define('HINT_CHATTERLIST_NICKNAME','Каждый чатер в списке начинается со своего НИКА, если впереди стоит символ - @ , то этот чатер является оператором, который имеет специальные права во всем чате.');
define('HINT_CHATTERLIST_ACTIVITY','Активность каждого чатера показана столбиком из символов - #. #### - означает - более активный, # - менее активный.');

/**
* used within ignore-dialog
*/
define('IGNORED','игнорирован');
define('IGNORE_CHATTERS','Игнорирование чатеров');
define('IGNORED_CHATTER','игнорированные чатеры');
define('IGNORE_CHATTER','игнорировать чатера');
define('UNIGNORE_CHATTER','реабилитировать');
define('UNIGNORED_CHATTER','доступные чатеры');
define('HINT_IGNORE_CHATTERS','Здесь вы можете создать список игнорируемых чатеров.');
//since version 3.1.0

/**
* used within invite-dialog
*/
define('INVITE_CHATTERS','Пригласить чатеров');
define('INVITED_CHATTERS','приглашенные чатеры');
define('INVITE_CHATTER','пригласить чатера');
define('DISINVITE_CHATTER','отказать чатеру');
define('DISINVITED_CHATTERS','отказные чатеры');
define('HINT_INVITE_CHATTERS','Если Вы хотите поговорить в собственной приватной комнате, Вы можете пригласить кого-либо и разрешить ему присоединиться к Вам.');
//since version 3.1.0

/**
* used within friends-dialog
*/
define('FRIENDS','Друзья');
define('ALL_CHATTERS','все чатеры');
define('ADD_TO_FRIENDS','Добавить в друзья');
define('DEL_FRIEND','Удалить из друзей');
define('HINT_ADD_FRIENDS','В этом окне диалога Вы можете добавить друга в список Ваших друзей.');
//since version 3.1.0

/**
* used within mail-dialog
*/
define('MAIL','Личка');
define('INBOX','Входящие');
define('OUTBOX','Исходящие');
define('TRASH','Удаленные');
define('COMPOSE','Сформировать');
define('REPLY','Ответить');
define('FORWARD','Переслать');
define('SUBJECT','Тема');
define('BODY','Текст');
define('SEND','Отправить');
define('MAIL_SEND_HINT','Внимание: кнопка "'.SEND.'" сработает только тогда, когда Вы введете в поле получателя существующий НИК!');
define('RECIPIENT_HINT','Можно ввести несколько получателей, разделив их знаком ";"');
define('MOVE_TO_TRASH','Удалить в корзину');
define('GET_MAIL','Получить новые сообщения');
define('DELETE_MAIL','Удалить сообщение');
define('SENDER','Отправитель');
define('RECIPIENT','Получатель');
define('MAIL_SEND_DATE','Дата отправки');
define('MAIL_RECEIVED','принято');
define('RED_MAIL','прочтено');
define('NEW_MAIL','новая почта');
define('LAST_TOUCH_RECIPIENT','Подтверждение о прочтении');
define('LAST_TOUCH_SENDER','просмотрено');
define('NO_FRIENDS_FOUND','друзей не найдено');
define('NO_SUCH_RECIPIENT_FOUND','Какой-то из получателей не найден.');
define('BODY_TO_SHORT','Содержимое Вашего письма слишком короткое.');
//since version 3.1.0

/**
* used within help-dialog
*/
define('HELP_TITLE','Чат-помощь');
define('HELP_HINT','Совет: Оставьте это окно открытым, для того, чтобы в дальнейшем воспользоваться в чате предложенными здесь командами');
define('HELP_SUBTITLE1','Руководство');
define('HELP_TEASER1','Здесь представлены базовые возможности чата!');
define('HELP_CHANNEL','Комнаты: Возможен переход между комнатами');
define('HELP_SPEAK','Пункты "говорить с" / "шептаться": Говорить или шептаться непосредственно с чатером.');
define('HELP_IGNORE','Меню Игнорировать: Здесь Вы можете создать список игнорируемых чатеров.');
define('HELP_INVITE','Меню Пригласить: Приглашайте чатеров в Вашу личную приватную комнату.');
define('HELP_FRIENDS','Меню Друзья: Вы можете создать список друзей, система будет показывать Вам, какие из Ваших друзей доступны или нет.');
define('HELP_CONFIGURE','Меню Настройка: В этой области Вы можете изменить Ваши личные настройки в чате, как например цвет сообщений и т.п.');
define('HELP_MAIL','Меню Личка: Пересылка почтовых сообщений другим чатерам и ведение Вашего личного почтового ящика в чате.');
define('HELP_HELP','Меню Помощь: Вы уже здесь ...');
define('HELP_SUBTITLE2','IRC-Команды:');
define('HELP_TEASER2','В процессе разработки ...');
define('HELP_SUBTITLE3','Смайлы:');
define('HELP_TEASER3','В процессе разработки ...');

define('SMILEY_CODE','Код');
define('SMILEY_EXPLANATION','Объяснение');
define('MORE_SMILEY_CODES','еще коды');
define('OWN_PRIVATE_IMAGE','Ваша собственная иконка, загружаемая через Ваш профиль');
define('RECIPIENT_PRIVATE_IMAGE','Иконка Вашего собеседника');
//since version 3.1.0

/**
* Registration
*/
define('REGISTRATION','Регистрация');
define('FILLOUT_TO_REGISTER','Заполните Ваши данные и отправьте их на регистрацию');
define('ERROR_NICKNAME','Выбранный Вами НИК уже существует');
define('ERROR_PASSWORD','Пароль слишком короткий или пустой');
define('ERROR_NAME','Пожалуйста, введите Ваше имя');
define('ERROR_USER','Нет пользователя с данным именем');
define('ERROR_EMAIL','Неверный формат');
define('ERROR_PICTURE_URL','Не могу найти эту картинку');
define('ERROR_COLOR','Неверный формат');
define('ERROR_MAIL_HOST','Не могу доставить почтовое сообщение на указанный хост');
define('NAME','Имя Фамилия');
define('EMAIL','E-Mail');
define('REGISTER','Регистрация');
define('PICTURE_URL','URL картинки');
define('REGISTRATION_SUCCESSFULLY','Вы успешно зарегистрированы!');
define('LOGIN_NOW','Теперь Вы можете выполнить вход. Если Вас автоматически не перебросит на страницу входа, пожалуйста кликните по ссылке ниже');
define('CONFIRMATION','Подтверждение');
define('STATUS_CONFIRMATION','Статус');
define('CONFIRM_SUCCESS','Подтверждение успешно выполнено');
define('CONFIRM_FAILED','Сбой подтверждения');
define('CONFIRMATION_MESSAGE','Вы получили новое сообщение. Для того, чтобы подтвердить регистрацию, пожалуйста, кликните по ссылке приложенной в данном письме!');
define('FORGOT_PASSWORD_HINT','Вы должны ввести ваш НИК, чтобы получить почту, содержащую Ваш забытый пароль.');
//since version 3.1.0

/**
* Configuration
*/
define('CONFIGURATION','Настройки');
define('TEXT_COLOR','цвет текста');
define('ADVICE','извещения');
define('QUIET','без извещений');
define('ALERT','всплывающие окна');
define('SOUND','звуки');
define('SCROLL_SPEED','Скорость прокрутки');
define('CHOOSE_SCROLL_SPEED','выберите скорость прокрутки');
define('SCROLL_SPEED_NORMAL','нормальная');
define('SCROLL_SPEED_FAST','быстро');
define('SCROLL_SPEED_FASTER','очень быстро');
define('SCROLL_SPEED_OFF','выкл');
define('SWITCH_OFF_IE_CLICK','Выключить звук на кликах в Internet Explorer!');
define('CHOOSE_THEME','Выбор темы');
//since version 3.1.0
define('DEFINE_LINE_STYLES','Определить образец стиля для других чатеров.');
define('SELECT_STYLES','Выберите стиль');
define('FONT_COLOR','цвет шрифта');
define('FONT_SIZE',' размер шрифта');
define('FONT_FAMILY','шрифт');
define('FONT_DECORATION','оформление шрифта');
define('LINE_TO_TEST_STYLES','Образец для теста Вашего стиля.');

/**
* Profile
*/
define('PROFILE','Мой профиль');
define('PERSONAL_DATA','Персональные данные');//a nickname follows
define('CHANGE_PROFILE','Обновить профиль');
define('PROFILE_UPDATA_SUCCESSFUL','Ваш профиль успешно обновлен');
define('PROFILE_UPDATA_NOT_SUCCESSFUL','Ошибка при обновлении профиля');
define('WRONG_MIME_TYPE','Неправильный тип файла');
define('IMG_FILE_TO_BIG','Файл слишком большой');
define('IMG_SIZE_TO_BIG','Размер картинки слишком большой');
define('SIZE_EXPECTED','Размер картинки в пикселах:');//a digit follows
define('PRIVATE_IMAGE','Приватное фото');
define('CONFIRMATION_MAIL_SUBJECT','Подтверждение регистрации');
define('CONFIRMATION_MAIL_BODY','Для подтверждения регистрации на нашем чате, кликните по ссылке ниже!');
define('ICQ_NUMBER','ICQ номер');
define('ERROR_ICQ_NUMBER','Нет ICQ номера');
define('AIM_NICKNAME','AIM НИК');
define('ERROR_AIM_NICKNAME','AIM НИК слишком длинный.');
define('YIM_NICKNAME','Yahoo! Пейджер НИК');
define('ERROR_YIM_NICKNAME','НИК слишком длинный.');
define('HOMEPAGE_URL','Домой');
define('ERROR_HOMEPAGE_URL','Личная страничка не найдена.');
define('BIRTHDAY','День рождения');
define('ERROR_BIRTHDAY','неверный формат');
define('AGE','Возраст');
define('INTERESTS','Интересы');
define('ERROR_INTERESTS','Строка "Интересы" слишком длинная!');
define('MOTTO','Девиз');
define('ERROR_MOTTO','Девиз слишком длинный!');
define('LINES_PER_DAY','Сообщений в день');
define('LOGINS_PER_DAY','Посещений в день');
//since version 3.1.0
define('PRIVATE_ICON','личная картинка');

/**
* Notes
*/
define('CHATTER_NOTES','Записки о чатере');//a nickname follows
define('UPDATE_NOTES','Обновить записки');
define('NOTES_UPDATED_SUCCESSFULLY','Ваши записки успешно обновлены.');
define('HINT_NOTES','Ваши записки никто не прочтет, кроме Вас.');
define('NOTES_NOT_UPDATED','Не могу обновить записки, вероятно не достаточно места для их сохранения.');

/**
* Moderation
*/
define('APPROVE','одобрить');
define('DISAPPROVE','отказать');
define('MESSAGE_FORWARDED_TO_MODERATOR','Сообщение было передано Модератору');
define('MODERATOR','Модератор');
define('VIP','VIP');
//since version 3.1.0

/**
* Error messages
*/
define('ERROR_WRONG_FORMAT','Данные, которые Вы отправляете, имеют неверный формат.');
//since version 3.1.0

/**
* Jumper
*/
define('JUMP_FAILED','Ошибка перехода!');
define('JUMP_ERROR_CONTENT','Недопустимое содержимое на удаленном сайте!');
define('JUMP_ERROR_HOST','Хост не найден!');
//since version 3.1.0

/**
* IRC-Commands related stuff
*/
define('INLINE_HELP','Помощь');
define('IRC_COMMAND','IRC-Команда');
define('IRC_EXPLANATION','Действие');
define('IRC_ME','Вставить Ваш НИК.');
define('IRC_MSG','Отправить шепотом сообщение указанному чатеру, даже если он находится в другой комнате.');
define('IRC_NICK','Послать сообщение указанному чатеру.');
define('IRC_JOIN','Сменить комнату.');
define('IRC_QUERY','Запрос на приватный чат указанному чатеру, который будет автоматически приглашен в Вашу собственную приватную комнату.');
define('IRC_LOCATE','Искать чатера по всему чату.');
define('IRC_IGNORE','Добавить указанного чатера в Ваш список игнорируемых.');
define('IRC_UNIGNORE','Удалить указанного чатера из Вашего списка игнорируемых.');
define('IRC_KICK','Выпнуть указанного чатера. Может быть использовано только модераторами.');
define('IRC_BAN','Выгнать чатера на определенный период из текущей комнаты. Для реабилитации используйте "/ban nickname 0"! Может быть использовано только модераторами.');
define('IRC_HELP','Показать помощь.');
define('IRC_QUIT','Выйти из чата.');
define('LOCATED_AT','находится в');//a nickname follows, nickname in front of this sentence
define('UNLOCATED','не найден.');//nickname in front of this sentence
//since version 3.1.0
define('CHATTER_IS_AWAY','Этот чатер на данный момент покинул keybord!');
define('CHATTERS_AWAY_MSG','Он оставил следующее сообщение:');
define('AFK_MODE_IS_SET','AFK-режим установлен.');
define('AFK_MODE_IS_UNSET','AFK-режим снят.');
define('HINT_YOU_ARE_AFK','Вы в AFK-режиме. Используйте "/back" для возврата.');
define('DIE','Убить');
define('YOUR_BODDIES','Ваши boddies');
define('IRC_SHOWBODY','Показать список Ваших друзей.');
define('IRC_ROLL','Убить игру. Для завершения используйте "/roll &lt;die count&gt;"');

/**
* Admin area
*/
define('ADMINISTRATION','Администрирование');
define('WELCOME_ADMIN','Зона администрирования');
define('PUBLIC_CHANNEL','публичная');
define('MODERATED_CHANNEL','модерируемая');
define('PRIVATE_CHANNEL','частная');
define('CHANNEL_ADMIN','Администрирование комнат');
define('CHATTER_ADMIN','Администрирование чатеров');
define('ADD_CHANNEL','Создать комнату');
define('DEL_CHANNEL','Удалить комнату');
define('UPDATE_CHANNEL','Обновить комнату');
define('CHATTER_DELETE_SUCCESS','Чатер успешно удален.');
define('CHATTER_DELETE_FAILED','Не могу удалить чатера.');
define('GROUP_UPDATE_SUCCESS','Членство в группе изменено.');
define('GROUP_UPDATE_FAILED','Ошибка изменения членства в группе.');
define('CHATTER_DISABLED','Чатер выключен');
define('CHATTER_NOT_DISABLED','Не могу выключить этого чатера');
define('CHATTER_ENABLED','Чатер включен');
define('CHATTER_NOT_ENABLED','Не могу включить этого чатера');
define('LAST_CHANNEL','Последняя комната');
define('LAST_ACTIVE_TIME','Последняя активность');
define('LAST_HOST','последний хост');
define('LAST_IP','послений IP');
define('LAST_REFERER','последний реферер');
define('LAST_USER_AGENT','последний браузер');
define('LAST_SESSIONID','последнее Id сессии');
define('REGTIME','Время регистрации');
define('MOVE_TO_TOP','Сдвинуть вверх');
define('SUCCESS_CHANNEL_UPDATE','комната успешно обновлена.');
define('ERROR_CHANNEL_UPDATE','не могу обновить комнату.');
//since version 3.1.0
define('TRAFFIC_STATISTICS','Статистика по трафику');
define('LAST_SEVEN_DAYS','последние 7 дней');
define('LAST_SEVEN_WEEKS','последние 7 недель');
define('LAST_SEVEN_MONTH','последние 7 месяцев');
define('GROUP_MEMBERSHIP_FOR_CHANNEL','член группы в комнате');//channel name follows

/**
* Confirmation messages
*/
define('CONFIRM_IGNORE','Чатер успешно добавлен в список игнорируемых.');
define('CONFIRM_IGNORE_FAILED','Этот чатер не может быть добавлен в список игнорируемых.');
define('CONFIRM_UNIGNORE','Чатер успешно удален из списка игнорируемых.');
define('CONFIRM_INVITE','Чатер приглашен.');
define('CONFIRM_DISINVITE','Чатеру отказано.');
define('CONFIRM_FRIEND','Чатер успешно добавлен в список друзей.');
//since version 3.1.0

/**
* User page
*/
define('USER_PAGE','Страничка пользователя');
define('USER_SINCE','Дата регистрации');//a time statement follows
define('LAST_SEEN','Последний вход');//a time statement follows
//since version 3.1.0

/**
* Regulars' table
*/
define('REGULARS',"Активисты");
define('REGULARS_HINT','Наиболее активные чатеры, в порядке их рангов.');
define('SINCE_REGISTRATION','с начала регистрации');
define('NOT_FOUND','не найден');
define('RANK','ранг');
define('ONLINE_TIME','всего дней в онлайне');
define('ACCOUNT_DATA','Системные данные');
define('INDIVIDUAL_DATA','Личные данные');
//since version 3.1.0

/**
* right click menu within the output frame
*/
define('PRIVATE_CHAT_NEW_WINDOW','приват');
//since version 3.1.0

/**
* Who is online window
*/
define('WHO_IS_ONLINE','кто в онлайне?');
define('CHANGE_CHANNEL','сменить комнату');
define('SELECT_NICK','выбрать НИК');
define('OPEN_USER_PAGE','открыть страницу пользователя');
define('HINT_WHO_IS_ONLINE','Здесь Вы можете найти всех чатеров находящихся сейчас в онлайне. Используйте иконки возле НИКов для того, чтобы пообщаться или перейти в комнату с выбранным чатером.');
//since version 3.1.0

/**
* Password reminder
*/
define('FORGOT_PASSWD_MAIL_SUBJECT','Ваш пароль для '.TITLE);
define('FORGOT_PASSWD_MAIL_BODY','Напоминание Вашего забытого пароля с сайта "'.TITLE.'"');
define('HINT_REG_PASSWORD','Ваш пароль должен быть не менее '.PASSWORD_MIN_LENGTH.' символов.');
define('HINT_REG_NICKNAME','Ваш НИК должен содержать буквы алфавита или цифры.');
define('YOUR_PASSWORD_IS','Ваш пароль:');//a password follows
define('FORGOT_PASSWD_MAIL_HINT','');
define('RETRIEVE_PASSWORD','Напомнить пароль');
//since version 3.1.0

/**
* Statistics
*/
define('STATISTICS','Статистика');
define('ONLINE_COUNT_LAST24h','В онлайне за последние 24ч');
define('ONLINE_TIME_AVG','Среднее время в онлайне (минут в день)');
define('REGISTERED_COUNT','Всего зарегистрированно чатеров');
define('LAST_REGISTERED','Последний зарегистрированный чатер');
define('MAIL_COUNT','Всего отправлено сообщений');
define('UNRED_MAILS','непрочитанных сообщений');
define('MAIL_COUNT_LAST_24h','Сообщений за последние 24ч');
//since version 3.1.0

/**
* context sesitive help
*/
define('HINT_PASSWORD','Введите Ваш пароль. Для гостевого входа, с ограниченными функциями, поле пароля должно быть пустым.');
define('HINT_NICKNAME','Вы должны зарегистрироваться, чтобы иметь собственный НИК.  Для гостевого входа, с ограниченными функциями, поле НИК может быть пустым.');
define('HINT_CHANNELS','Существует три вида комнат, <em>модерируемая</em>, <em>публичная</em> и <em>приватная</em>. В публичной комнате Ваши сообщения отправляются непосредственно в чат, в модерируемой они появляются только после одобрения модератором. Приватные комнаты доступны только тем, кто имеет к ним доступ.');
define('INFO_RANKING','Если необходимое значение для ранга достигнуто, то у Вас оно сохраниться навсегда, даже если в будущем будут изменены параметры данного ранжирования.');
define('HINT_ADVICE_QUIET','Если Вы выберете эту опцию, Вас не будут извещать, если чатер будет пытаться заговорить с вами.');
define('HINT_ADVICE_ALERT','Если Вы выберете эту опцию, Вы будете получать оповещение ввиде <strong>всплывающего окна</strong>, если чатер будет пытаться заговорить с вами.');
define('HINT_ADVICE_SOUND','Если Вы выберете эту опцию, Вы будете получать <strong>звуковое</strong> оповещение, если чатер будет пытаться заговорить с вами.');
//since version 3.1.0

/**
* Guestbook
*/
define('GUESTBOOK','Гостевая');
define('GUESTBOOK_NEW_ENTRY','Добавление записи в гостевую');
define('GUESTBOOK_ENTRY_SAVED','Новая запись была успешно добавлена в гостевую книгу');
//since version 3.1.0

/**
* Generic
*/
define('GUEST_NICK_PREFIX','Гость');
define('ALL_GUESTS','Гости');
define('SUBMIT','Подтвердить');
define('CANCEL','Отменить');
define('SEARCH','Поиск');
define('SEARCH_RESULTS','результат поиска');
define('ALERT_NEW_LINE','Кто-то хочет поговорить с Вами');
define('CLOSE_WINDOW','Закрыть окно');
define('GOTO_HOME','В начало');
define('CONTACT_HINT','Если у Вас есть вопросы, пожалуйста дайте нам знать!');
define('REALLY_QUESTION','Вы уверены?');
define('CHATTER','Чатер');
define('OPERATOR','Оператор');
define('ADMIN_HINT','Для администрирования этого чата, войдите как "оператор" и зайдите в меню  "'.ADMINISTRATION.'".');
define('IMPORTANT','Важно');
define('OPERATOR_PASSWORD','Пароль оператора');
define('MAKE_NOTE','Пожалуйста, запомните Ваш пароль оператора');
define('RESTRICT','Искать НИК');
define('DENIED_FOR_GUESTS','Этот сервис недоступен для гостей!');
define('BANNED_MSG','У Вас нет доступа к данной комнате и so you are kicked into your private channel.');
define('CHATTER_COUNT','Чатеров в онлайне');//a digit follows
define('HIDE','спрятать');
define('GENDER','Пол');
define('GENDER_NOTE','Вы можете изменить пол только один раз!');
define('FEMALE','Ж');
define('MALE','М');
define('PAGE_VIEWS','Просмотров страницы');
define('GRADE','Звание');
define('GRADE_ROOKIE','Новичок');
define('GRADE_MEMBER','Бывалый');
define('GRADE_REGULAR','Завсегдатай');
define('GRADE_ELITE','Элита');
define('GRADE_OPERATOR','Оператор/Админ');
define('YOU_ARE_BUSY','Вы хотите разговаривать с кем-то еще в приватной комнате!');
define('CHATTER_IS_BUSY','К сожалению, этот чатер не может поговорить с Вами, он слишком занят.');
define('WANTS_TO_TALK','хочу поговорить с тобой!');//nickname in front of this
define('DAYS','Дней');
define('CHAT','Чат');
define('CHATMAIL','Личка');
define('NICKNAME_NOT_FOUND','Запрашиваемый НИК не найден.');
define('PASSWORD_HAS_BEEN_SENT','Пароль был успешно отправлен');
define('CHOOSE_LANGUAGE','Другие языки');
define('OPTIONAL','опционально');
define('MISCELLANEOUS','Разное');
define('SAVE','Записать');
define('DELETE','Удалить');
define('EDIT','Редактировать');
define('CREATE_NEW','create new');
define('JS_ALERT','Пожалуйста, активизируйте JavaScript');
define('HAPPY_BIRTHDAY','С Днем Рождения!');
define('CHOOSEN','выбран');
//since version 3.1.0

/**
 * PostNuke related
 */
define('PN_NOT_LOGGED_IN','Ошибка при входе в чат!');
define('PN_HINT_NOT_LOGGED_IN','Чтобы присоединиться к чату, сперва Вы должны выполнить вход!');
//since version 3.1.0
?>