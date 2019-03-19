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
  $Source: /cvsroot/phpopenchat/chat3/include/languages/tr.inc,v $
  $Revision: 1.1.2.1 $
*/

/**
* turkish language file
*
* defines constants for an english language interface
*
* @author ScriptEvi.com <webmaster@scriptevi.com> http://www.scriptevi.com
* @version $Id: tr.inc,v 1.1.2.1 2003/08/19 18:54:07 letreo Exp $
*/

/* * * * * * * * * * CHAT MODULE * * * * * * * * * */
define('CHARACTER_ENCODING','ISO-8859-9');

/**
* title for html header
*/
define('TITLE','PHPOpenChat');

/**
* used within index.php
*/
define('WELCOME','PHPOpenChat - Oturumuna Hoþ Geldiniz');
define('INTRO','Bu bir chat dýr, katýlmadan önce mutlaka <a href="netiquette.php">kurallarý</a> okumalýsýnýz!');
define('GREETING','Seni tekrar görmek güzel!');
define('LOGIN_WELCOME','daha fazla seçenekler için üst sað köþedeki bir sohbet edene týklayýn.');
define('NICKNAME','Kullanýcý Adý');
define('PASSWORD','Þifre');
define('CHANNEL','Kanal');
define('LOGIN','Giriþ');
define('GO','Git');
define('EXIT_CHAT','Chatdan Çýk');
define('FORGOT_PASSWORD','Þifrenizi mi kaybettiniz?');
define('STORE_ACCOUNT_DATA','hesap bilgisini sakla');

/**
* used within chat output/input interface
*/
define('LEAVES_THE_CHAT','sohbetten ayrýldý.');
define('LEAVES_THIS_CHANNEL','kanaldan ayrýldý.');
define('IS_TOO_BUSY','çok meþgul');//nickname in front
define('IS_NOT_ONLINE','online deðil');
define('JOINS_THIS_CHANNEL','katýldýðý kanal.');
define('JOINS_THE_CHAT','sohbete katýldý.');
define('SAYS_TO','söyledikleri');
define('WHISPERS_TO','fýsýldadýklarý');
define('SAY_TO','söylediði');
define('WHISPER_TO','fýsýldadýðý');
define('EVERYBODY','herkes');
define('INVITATION_MESSAGE','Özel bir kanala davet edildiniz! Lütfen kanala gidin:');//a channel name follows
define('SPEAK_TO','konuþtuðu');
define('WHISPERED','fýsýlda');
define('OUTPUT_FILTER','Çýktý filitresi');
define('PRIVATE','sadece özel metin');
define('BODIES','sadece dostlar');
define('SYSTEM_MESSAGES','Sistem mesajlarý yok');
define('IGNORE','Önemseme');
define('INVITE','Davet');
define('CONFIGURE','Görünüm');
define('HELP','Yardým');
define('INFO','Bilgi');
define('GUESTS','Misafir');
define('EMAIL_US','Email gönder');
define('NOTE_ABOUT','Hakkýndaki Not');
define('ICON_LIST','Smiley-Listesi');
define('CHOOSE_CHANNEL','Kanal seçin');
define('CHOOSE_RECIPIENT','Alýcý seçin');
define('ADD_TO_FRIENDLIST','dost listesine ekle');
define('NO_CLICKETY_CLICK','Gönderme butonuna týklayacaðýnýza emin olun.');
define('LINE_HAS_BEEN_SENT_TO','Hattýnýzn gönderildiði kullanýcý:');//nickname follows
define('FULL','full');
define('UNLOCK_CHANNEL','açýk kanal');//channel name follows
define('YOU_HAVE_NEW_MAIL','Yeni mail aldýnýz!');
define('LOGOUT_SHORTLY','Aktif olmadýðýnýzdan dolayý kýsa bir sonra '.CHAT_NAME.' dan çýkarýlacaksýnýz. Yenilemek istermisiniz?');

/**
* used within ignore-dialog
*/
define('IGNORED','önemsenmedi');
define('IGNORE_CHATTERS','Sohbetçileri önemseme');
define('IGNORED_CHATTER','önemsenmeyen sohbetçi');
define('IGNORE_CHATTER','sohbetçiyi önemseme');
define('UNIGNORE_CHATTER','sohbetçiyi önemse');
define('UNIGNORED_CHATTER','önemsenen sohbetçi');
define('HINT_IGNORE_CHATTERS','Rahatsýz edenleri buradan önemsemeyebilirsiniz.');

/**
* used within invite-dialog
*/
define('INVITE_CHATTERS','Sohbetçileri davet et');
define('INVITED_CHATTERS','davet edilen sohbetçi');
define('INVITE_CHATTER','sohbetçi davet et');
define('DISINVITE_CHATTER','sohbetçi davetini reddet');
define('DISINVITED_CHATTERS','davet edilmeyen sohbetçi');
define('HINT_INVITE_CHATTERS','Þayet kendi kanalýn ile özel görüþmek istersen, davet ettiðin birisine kanalýna giriþ yetkisi vermelisin.');

/**
* used within friends-dialog
*/
define('FRIENDS','Dostlar');
define('ALL_CHATTERS','bütün sohbetçiler');
define('ADD_TO_FRIENDS','Dostlara ekle');
define('DEL_FRIEND','Dost kaldýr');
define('HINT_ADD_FRIENDS','Bu diyalog için arkadaþlarýný dostlar listene eklemelisin.');

/**
* used within mail-dialog
*/
define('MAIL','Mail');
define('INBOX','Gelen Kutusu');
define('OUTBOX','Giden Kutusu');
define('TRASH','Çöp');
define('COMPOSE','Yaz');
define('REPLY','Yanýtla');
define('FORWARD','Ýlet');
define('SUBJECT','Konu');
define('BODY','Mesaj');
define('SEND','Gönder');
define('MAIL_SEND_HINT','Not: "'.SEND.'" butonu sadece Alýcý alanýný mevcut kullanýcý adlarýyla doldurduðunuzda çalýþýr.!');
define('RECIPIENT_HINT','Birden fazla alýcýlar varsa virgül ile ayýrýnýz.');
define('MOVE_TO_TRASH','Çöpe taþý');
define('GET_MAIL','Yeni mesajlarý al');
define('DELETE_MAIL','Mail Sil');
define('SENDER','Gönderen');
define('RECIPIENT','Alýcý');
define('MAIL_SEND_DATE','Gönderme tarihi');
define('MAIL_RECEIVED','alýnma');
define('LAST_TOUCH_RECIPIENT','Okunma doðrulamasý');
define('LAST_TOUCH_SENDER','son baðlantý');
define('NO_FRIENDS_FOUND','dostlar bulunamadý');
define('NO_SUCH_RECIPIENT_FOUND','Bir alýcý bulunamadý.');
define('BODY_TO_SHORT','The content of your mail is to short.');

/**
* used within help-dialog
*/
define('HELP_TITLE','Chat-Yardým');
define('HELP_HINT','Öneri: Bu pencereden ayrýlýn, chat ve komutlar için buraya bakýn');
define('HELP_SUBTITLE1','Manual');
define('HELP_TEASER1','Biz burada size chat\'ýn basit iþlevlerini göstermek istiyoruz!');
define('HELP_CHANNEL','Kanal: Mevcut kanallar arasýndaki deðiþiklik');
define('HELP_SPEAK','Bu kutu /"fýsýldadý": Sohbetçiye doðrudan konuþma yada fýsýldamayý saðlar.');
define('HELP_IGNORE','Önemseme Menüsü:Buradan sohbetçileri önemsemeyebilirsiniz.');
define('HELP_INVITE','Davet Menüsü: Sohbetçileri özel kanalýnýza davet edebilirsiniz..');
define('HELP_FRIENDS','Dostlar Menüsü: Diðer sohbetçileri arkadaþ listenize almanýzý saðlar. Sistem hangi arkadaþýnýzýn aktif olup olmadýðýný size bildirir.');
define('HELP_CONFIGURE','Görünüm Menüsü: Bu alanda tercih ettiðiniz chat ayaralrýný deðiþtirebilirsiniz. Örn: renk vb. gibi.');
define('HELP_MAIL','Mail Menüsü : Diðer üyelere mail mesajý göndeip, gelen kutunuzu kontrol edebilirsiniz.');
define('HELP_HELP','Yardým Menüsü: Þu anda ona bakýyorsunuz ...');
define('HELP_SUBTITLE2','IRC-Komutlarý:');
define('HELP_TEASER2','Ýþlemde ...');
define('HELP_SUBTITLE3','Smileys:');
define('HELP_TEASER3','Ýþlemde ...');

define('SMILEY_CODE','Kod');
define('SMILEY_EXPLANATION','Açýklama');
define('MORE_SMILEY_CODES','daha çok kod');
define('OWN_PRIVATE_IMAGE','Profilinize kendi ikonlarýnýzý yükleyebilirsiniz');
define('RECIPIENT_PRIVATE_IMAGE','Partnerinizin ikonu');

/**
* Registration
*/
define('REGISTRATION','Kayýt');
define('FILLOUT_TO_REGISTER','Kayýt için verilerinizi doldurun ve gönderin');
define('ERROR_NICKNAME','Seçilen kullanýcý adý zaten mevcut');
define('ERROR_PASSWORD','Þifre çok kýsa yada boþ býrakýldý');
define('ERROR_NAME','Lütfen adýnýzý girin');
define('ERROR_USER','Verilen kullanýcý adý yok');
define('ERROR_EMAIL','Yanlýþ format');
define('ERROR_PICTURE_URL','Bu resim bulunamadý');
define('ERROR_COLOR','Yanlýþ format');
define('ERROR_MAIL_HOST','Özel hosta bir mail gönderemezsiniz');
define('NAME','Ad Soyad');
define('EMAIL','E-Mail adresi');
define('REGISTER','Kayýt');
define('PICTURE_URL','Resmin URL si');
define('REGISTRATION_SUCCESSFULLY','Kayýt iþleminiz baþarýyla gerçekleþti!');
define('LOGIN_NOW','Þimdi giriþ yapmaya hazýrsýnýz. Þayet giriþ sayfasýna yönlendirilmediyseniz lütfen aþaðýdaki linke týklayýn');
define('CONFIRMATION','Onaylama');
define('STATUS_CONFIRMATION','Status');
define('CONFIRM_SUCCESS','Onaylamanýz baþarýlý');
define('CONFIRM_FAILED','Onaylamanýz baþarýsýz');
define('CONFIRMATION_MESSAGE','Bizden bir e-mail alacaksýnýz. Kayýt iþleminizin tamamlanmasý için lütfen, bu e-maildeki linke týklayýnýz!');
define('FORGOT_PASSWORD_HINT','Kullanýcý adýnýzý doldurun, þifrenizi içeren bir email alacaksýnýz.');

/**
* Configuration
*/
define('CONFIGURATION','Görünüm');
define('TEXT_COLOR','metin rengi');
define('ADVICE','öneri');
define('QUIET','önerme');
define('ALERT','popup pencere');
define('SOUND','bir müzik çal');
define('SCROLL_SPEED','Kaydýrma hýzý');
define('CHOOSE_SCROLL_SPEED','kaydýrma hýzý seç');
define('SCROLL_SPEED_NORMAL','normal');
define('SCROLL_SPEED_FAST','hýzlý');
define('SCROLL_SPEED_FASTER','daha hýzlý');
define('SCROLL_SPEED_OFF','off');
define('SWITCH_OFF_IE_CLICK','Internet Explorer ýn ses özelliðini kapatýn!');
define('CHOOSE_THEME','Bir theme seç');

/**
* Profile
*/
define('PROFILE','Profilim');
define('PERSONAL_DATA','Kiþisel bilgi');//a nickname follows
define('CHANGE_PROFILE','Profili Güncelle');
define('PROFILE_UPDATA_SUCCESSFUL','Profiliniz baþarýyla güncellendi');
define('PROFILE_UPDATA_NOT_SUCCESSFUL','Profiliniz güncellenmedi');
define('WRONG_MIME_TYPE','Dosya tipi hatalý');
define('IMG_FILE_TO_BIG','Dosya çok büyük');
define('IMG_SIZE_TO_BIG','Boyutlar çok büyük');
define('SIZE_EXPECTED','Beklenen dosya pixel olarak büyüklüðü:');//a digit follows
define('PRIVATE_IMAGE','Özel Resim');
define('CONFIRMATION_MAIL_SUBJECT','CHAT KAYIT ONAYI');
define('CONFIRMATION_MAIL_BODY','Chat servisimize kayýt olma iþleminizi onaylýyorsanýz aþaðýdaki linki týklayýnýz!');
define('ICQ_NUMBER','ICQ Numarasý');
define('ERROR_ICQ_NUMBER','ICQ Numarasý yok');
define('AIM_NICKNAME','AIM Kullanýcý adý');
define('ERROR_AIM_NICKNAME','AIM Kullanýcý adý çok uzun.');
define('YIM_NICKNAME','Yahoo! Instant Messenger kullanýcý adý');
define('ERROR_YIM_NICKNAME','kullanýcý adý çok uzun.');
define('HOMEPAGE_URL','Web Sitesi');
define('ERROR_HOMEPAGE_URL','Web sitesi bulunmadý.');
define('BIRTHDAY','Doðum günü');
define('ERROR_BIRTHDAY','yanlýþ format');
define('AGE','Yaþ');
define('INTERESTS','Ýlgi alanlarý');
define('ERROR_INTERESTS','Ýlgi alanlarý dizisi çok uzun!');
define('MOTTO','Slogan');
define('ERROR_MOTTO','Slogan çok uzun!');
define('LINES_PER_DAY','Günlük satýr');
define('LOGINS_PER_DAY','Günlük giriþ');

/**
* Notes
*/
define('CHATTER_NOTES','Notlarýn ait olduðu sohbetçi');//a nickname follows
define('UPDATE_NOTES','Notlarý güncelle');
define('NOTES_UPDATED_SUCCESSFULLY','Notlarýnýz baþarýyla güncellendi.');
define('HINT_NOTES','Hiçbir diðer sohbetçi notlarýnýzý okuyamaz.');
define('NOTES_NOT_UPDATED','Notlarýnýz güncelleyemiyorsunuz, notlarýnýzýn solunda boþluk olmamýþ olabilir.');

/**
* Moderation
*/
define('APPROVE','onayla');
define('DISAPPROVE','onaylama');
define('MESSAGE_FORWARDED_TO_MODERATOR','Mesaj Moderator a iletildi');
define('MODERATOR','Moderator');
define('VIP','VIP');

/**
* Error messages
*/
define('ERROR_WRONG_FORMAT','Yanlýþ formatta veri gönderdiniz.');

/**
* Jumper
*/
define('JUMP_FAILED','Atlama baþarýsýz!');
define('JUMP_ERROR_CONTENT','Sitede kabul edilmeyen içerik bulundu!');
define('JUMP_ERROR_HOST','Host bulunmadý!');

/**
* IRC-Commands related stuff
*/
define('INLINE_HELP','Yardým');
define('IRC_COMMAND','IRC-Komutlarý');
define('IRC_EXPLANATION','Açýklama');
define('IRC_ME','Nickinin yerine geçsin mi.');
define('IRC_MSG','Özel karakterle bir fýsýltý mesajý yolluyor, birde eðer diðer kanaldaysa.');
define('IRC_NICK','Özel karaktele bir mesaj yolla.');
define('IRC_JOIN','Kanal deðiþtir.');
define('IRC_QUERY','Özel karakterle özel sohbet talebinde bulun, özel kanalýnýza otomatik davet edebilirsiniz.');
define('IRC_LOCATE','Tüm chat da bir sohbetçi ara.');
define('IRC_IGNORE','Önemsenmeyen listenize sohbetçi ekleme.');
define('IRC_UNIGNORE','Önemsenmeyen listenizden sohbetçi çýkarma.');
define('IRC_KICK','Belirli sohbetçi atma. Sadece operator tarafýndan kullanýlýr.');
define('IRC_BAN','Þimdiki kanaldan belirli periyot için bir sohbetçi Yasakla. Yasaðý kaldýrmak için "/ban nickname 0"! Sadece oprerator tarafýndan kullanýlabilir.');
define('IRC_HELP','Bu yardýmý yazdýr.');
define('IRC_QUIT','Bu chat oturumunu terket.');
define('LOCATED_AT','yerleþtirilmiþ');//a nickname follows, nickname in front of this sentence
define('UNLOCATED','bulunamadý.');//nickname in front of this sentence

/**
* Admin area
*/
define('ADMINISTRATION','Administration');
define('WELCOME_ADMIN','Yönetim Alaný');
define('PUBLIC_CHANNEL','genel');
define('MODERATED_CHANNEL','moderated');
define('PRIVATE_CHANNEL','özel');
define('CHANNEL_ADMIN','Kanal-Yönetimi');
define('CHATTER_ADMIN','Sohbetçi-Yönetimi');
define('ADD_CHANNEL','Kanalý Yarat');
define('DEL_CHANNEL','Kanalý Sil');
define('UPDATE_CHANNEL','Kanalý Güncelle');
define('CHATTER_DELETE_SUCCESS','Sohbetçi baþarýyla kaldýrýldý.');
define('CHATTER_DELETE_FAILED','Sohbetçi kaldýrýlamadý.');
define('GROUP_UPDATE_SUCCESS','Grup-üye deðiþtirildi.');
define('GROUP_UPDATE_FAILED','Grup-üye deðiþikliði baþarýsýz oldu.');
define('CHATTER_DISABLED','Sohbetçi devre dýþý kaldý');
define('CHATTER_NOT_DISABLED','Bu sohbetçi devre dýþý yapýlamadý');
define('CHATTER_ENABLED','Sohbetçi devreye alýndý');
define('CHATTER_NOT_ENABLED','Bu sohbetçi devreye alýnamadý');
define('LAST_CHANNEL','Son kanal');
define('LAST_ACTIVE_TIME','Son görünme');
define('LAST_HOST','son host');
define('LAST_IP','son IP');
define('LAST_REFERER','son referer');
define('LAST_USER_AGENT','last user agent');
define('LAST_SESSIONID','son oturumId');
define('REGTIME','Kayýt zamaný');
define('MOVE_TO_TOP','Baþa taþý');
define('SUCCESS_CHANNEL_UPDATE','kanal baþarýyla güncellendi.');
define('ERROR_CHANNEL_UPDATE','kanal güncellenemedi.');

/**
* Confirmation messages
*/
define('CONFIRM_IGNORE','Sohbetçi baþarýyla önemsizler listesine eklendi.');
define('CONFIRM_UNIGNORE','Sohbetçi baþarýyla önemsizler listesinden kaldýrýldý.');
define('CONFIRM_INVITE','Sohbetçi baþarýyla davet edilidi.');
define('CONFIRM_DISINVITE','Sohbetçi baþarýyla reddedildi.');
define('CONFIRM_FRIEND','Sohbetçi baþarýyla dostlar listesine eklendi.');

/**
* User page
*/
define('USER_PAGE','Üye sayfasý');
define('USER_SINCE','Üyelik baþlangýcý');//a time statement follows
define('LAST_SEEN','son görünmesi');//a time statement follows

/**
* Regulars' table
*/
define('REGULARS',"Düzenli liste");
define('REGULARS_HINT','Burada her derecede en çok aktif olan sohbetçileri görüyorsunuz.');
define('SINCE_REGISTRATION','kayýttan sonra');
define('NOT_FOUND','bulunamadý');
define('RANK','üstündeki derece');
define('ONLINE_TIME','üstündeki online günler');
define('ACCOUNT_DATA','Hesap verisi');
define('INDIVIDUAL_DATA','Kiþisel veri');

/**
* right click menu within the output frame
*/
define('PRIVATE_CHAT_NEW_WINDOW','özel sohbet');

/**
* Who is online window
*/
define('WHO_IS_ONLINE','Kim online?');
define('CHANGE_CHANNEL','kanal deðiþtir');
define('SELECT_NICK','kullanýcý adýný seç');
define('OPEN_USER_PAGE','üye sayfasýný aç');
define('HINT_WHO_IS_ONLINE','Bu chat daki tüm sohbetçileri buradan bulabilirsiniz. Chat yapmak yada kanala baðlanmak için ikonlarý kullanýnýz.');

/**
* Password reminder
*/
define('FORGOT_PASSWD_MAIL_SUBJECT',' '.TITLE.' Giriþ þifreniz');
define('FORGOT_PASSWD_MAIL_BODY','Bu mesajýn size gönderilme nedeni
bize '.TITLE.' þifrenizi kaybettiðinizi bildirdiniz içindir.');
define('HINT_REG_PASSWORD','Þifreniz en az '.PASSWORD_MIN_LENGTH.' karakter uzunluðunda olmalýdýr.');
define('HINT_REG_NICKNAME','Nickiniz harf ve rakamlardan oluþmalýdýr.');
define('YOUR_PASSWORD_IS','Þifreniz:');//a password follows
define('FORGOT_PASSWD_MAIL_HINT','
');
define('RETRIEVE_PASSWORD','Þifrenizi geri alýn');

/**
* Statistics
*/
define('STATISTICS','Ýstatistikler');
define('ONLINE_COUNT_LAST24h','Son 24 sa. de online olanlar');
define('ONLINE_TIME_AVG','Dakika cinsinden Online günlük ortalama');
define('REGISTERED_COUNT','Kayýtlý sohbet eden sayýsý');
define('LAST_REGISTERED','Son kayýt olan sohbet eden');
define('MAIL_COUNT','Mail sayýsý');
define('UNRED_MAILS','okunmamýþ mailler');
define('MAIL_COUNT_LAST_24h','Son 24 sa. deki Mail sayýsý');

/**
* context sesitive help
*/
define('HINT_PASSWORD','BIZDEN MAIL ALMAK IÇIN SIFRENIZI GIRINIZ. MISAFIRLER IÇIN BU ALAN BOS BIRAKILMALIDIR.');
define('HINT_NICKNAME','KENDINIZE AIT KULLANICI ADI ILE KAYIT OLMALISINIZ. ZIYARETÇI GIRISI IÇIN BU ALANI BOS BIRAKABILIRSINIZ.');
define('HINT_CHANNELS','ÜÇ ÇESIT KANAL VARDIR, <em>moderated</em>, <em>genel</em> VE <em>özel</em>. GENEL KANALLARDA SATIRLAR DIREKT OLARAK GÖRÜNÜR, MODERATED KANALLARDA MODERATÖR TARAFINDAN BELIRLENIR, ÖZEL KANALLAR SADECE GIRIS YAPILINCA GÖRÜNÜR.');
define('INFO_RANKING','Eðer kullaným oranýnýz belli bir düzeye ulaþmýþ ise gelecekte kullaným oranýnýz belli sýnýrlarýn altýna düþmediði sürece önerilebilirsiniz.');
define('HINT_ADVICE_QUIET','Bu opsiyon seçildiðinde yorgun olduðunuz belirtir.');
define('HINT_ADVICE_ALERT','Bu özellik seçilirse yorgun olduðunuzu belirtmek için küçük <strong>pop up pencere</strong> açýlýr.');
define('HINT_ADVICE_SOUND','Bu özellik seçilirse yorgun olduðunuzu belirtmek için sesli uyarý verir.');

/**
* Guestbook
*/
define('GUESTBOOK','Ziyaretçi Defteri');
define('GUESTBOOK_NEW_ENTRY','Ziyaretçi Defterine yaz');
define('GUESTBOOK_ENTRY_SAVED','Ziyaretçi Defterine yazdýðýnýz baþarýyla kaydedildi');

/**
* Generic
*/
define('GUEST_NICK_PREFIX','Misafir');
define('ALL_GUESTS','Misafirler');
define('SUBMIT','Tamam');
define('CANCEL','Vazgeç');
define('SEARCH','Ara');
define('SEARCH_RESULTS','arama sonuçlarý');
define('ALERT_NEW_LINE','Birisi sizinle sohbet etmek istiyor');
define('CLOSE_WINDOW','Pencereyi kapat');
define('GOTO_HOME','Ana Sayfaya git');
define('CONTACT_HINT','EÐER sorularýnýz varsa, lütfen bize yöneltin!');
define('REALLY_QUESTION','Eminmisiniz?');
define('CHATTER','Sohbet eden');
define('OPERATOR','Operatör');
define('ADMIN_HINT','Chat ýnýzý yönetmek için "operator" olarak giriþ yapýn ve menüleri gösteren input-frame deki "'.ADMINISTRATION.'" linkine týklayýn.');
define('IMPORTANT','Önemli');
define('OPERATOR_PASSWORD','Operatör-Þifresi');
define('MAKE_NOTE','Lütfen operatör þifrenizi not edin');
define('RESTRICT','Kullanýcý adlarý ara');
define('DENIED_FOR_GUESTS','Misafirler bu servisten yararlanamaz!');
define('BANNED_MSG','Kanala giriþiniz yasaklandý ve özel kalandanda atýldýnýz.');
define('CHATTER_COUNT','Online sohbet eden');//a digit follows
define('HIDE','gizle');
define('GENDER','Cinsiyet');
define('GENDER_NOTE','Bir cinsiyeti sadece bir defa seçmelisiniz!');
define('FEMALE','bayan');
define('MALE','erkek');
define('PAGE_VIEWS','Sayfa Görüntülenmesi');
define('GRADE','Derece');
define('GRADE_ROOKIE','Acemi');
define('GRADE_MEMBER','Üye');
define('GRADE_REGULAR','Devamlý');
define('GRADE_ELITE','Seçkin-Sohbetçi');
define('GRADE_OPERATOR','Operator/Admin');
define('YOU_ARE_BUSY','Özel pencerede zaten baþka birisiyle konuþuyorsunuz!');
define('CHATTER_IS_BUSY','Ne yazýkki bu sohbetçi sizinle sohbet edemiyor, kendisi çok meþgul.');
define('WANTS_TO_TALK','seninle görüþmek istiyor!');//nickname in front of this
define('DAYS','Tage');
define('CHAT','Sohbet');
define('CHATMAIL','Sohbet-Mail');
define('NICKNAME_NOT_FOUND','Belirtilen kullanýcý adý bulunamadý.');
define('PASSWORD_HAS_BEEN_SENT','Þifre gönderildi');
define('CHOOSE_LANGUAGE','Diðer lisan');
define('OPTIONAL','opsiyonel');
define('MISCELLANEOUS','çeþitli');
define('SAVE','Kaydet');
define('DELETE','Sil');
define('EDIT','Düzenle');
define('CREATE_NEW','yeni yarat');
define('JS_ALERT','Lütfen JavaScript\'i aktif edin');
define('HAPPY_BIRTHDAY','Mutlu Yýllar!');
define('CHOOSEN','seçim');

/**
 * PostNuke related
 */
define('PN_NOT_LOGGED_IN','Chat-Giriþi baþarýsýz!');
define('PN_HINT_NOT_LOGGED_IN','Önce giriþ yapýp, chata katýlýn!');
?>