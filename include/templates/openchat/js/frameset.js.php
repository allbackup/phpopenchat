/*<![CDATA[*/
var currentAgent = navigator.userAgent.toLowerCase();
var is_opera     = (currentAgent.indexOf("opera")   != -1);
var is_opera2    = (currentAgent.indexOf("opera 2") != -1 || currentAgent.indexOf("opera/2") != -1);
var is_opera3    = (currentAgent.indexOf("opera 3") != -1 || currentAgent.indexOf("opera/3") != -1);
var is_opera4    = (currentAgent.indexOf("opera 4") != -1 || currentAgent.indexOf("opera/4") != -1);
var is_opera5    = (currentAgent.indexOf("opera 5") != -1 || currentAgent.indexOf("opera/5") != -1);
var is_opera6    = (currentAgent.indexOf("opera 6") != -1 || currentAgent.indexOf("opera/6") != -1);
var is_opera7    = (currentAgent.indexOf("opera 7") != -1 || currentAgent.indexOf("opera/7") != -1);
var is_opera6up  = (is_opera && !is_opera2 && !is_opera3 && !is_opera4 && !is_opera5);
var is_opera7up  = (is_opera && !is_opera2 && !is_opera3 && !is_opera4 && !is_opera5 && !is_opera6);

var lines = '';

var refresh = <?=$TEMPLATE_OUT['interval']?>;
var refreshChatterList = 1000;
var BufferInt  = window.setInterval("reload_getlines()",refresh);
var BufferChatters  = window.setInterval("reload_chatters()",refreshChatterList);
var serialize_refresh = 0;
var php_session_param = '<?=session_name()?>=<?=session_id()?>';
var guestNickPrefix = '<?=GUEST_NICK_PREFIX?>';
var debug=0;

/*
* scrollContextMenu will be
* set in chatter frame
* unset in output
*/
var scrollContextMenu = 0;
var reload_getlines_tries = 0;
function reload_getlines(){
  if(serialize_refresh == 0 || reload_getlines_tries >= 3) {
    reload_getlines_tries = 0;
    if(frames['getlines']){
      serialize_refresh = 1;
      frames['getlines'].document.location.href = 'getlines.php?login=0&polling=1&'+php_session_param;
    }
  } else {
    reload_getlines_tries++;
  }
}
var debug=0;
var operators = new Array(<?=$TEMPLATE_OUT['members']?>);
var scrollTO;
var timeout_on = false;
var speed = 1;
var contextMenuTop = 0;
var menuTop = 0;
var topScrolledPixel = 0;
var scrollContextMenu = false;

function scroll_it() {
  to=20;
  if(speed != 0){
    if(speed==3){
     to = 5;
     down=3;
    }else if(speed == 2){
     to = 10;
     down=2;
    }else{
     to = 20;
     down=1;
    }

    if (document.all 
    && frames['output'].document
    && scrollContextMenu == true
    && (frames['output'].document.all.contentOut.offsetHeight < frames['output'].document.body.scrollHeight)){
      //body is greater than the frame around
      if(menuTop < (frames['output'].document.body.scrollHeight - frames['output'].document.all.contentOut.offsetHeight)){
        menuTop = (frames['output'].document.body.scrollHeight - frames['output'].document.all.contentOut.offsetHeight);
      }
      if(topScrolledPixel < menuTop){
        topScrolledPixel = topScrolledPixel + down;
        frames['output'].menuobj.style.top = topScrolledPixel + 20;
      }
    }

    window.output.scrollBy(-1,down);
    if (timeout_on == true) clearTimeout(scrollTO);
    timeout_on = true;
    scrollTO = setTimeout('scroll_it()',to);
  }
 }

 function delay(gap){ /* gap is in millisecs */
   var then,now;
   then = new Date().getTime();
   now  = then;
   while( (now-then) < gap ) {
     now = new Date().getTime();
   }
 }

 function in_array(needle,haystack) {
   for (var i=0; i<haystack.length; i++) {
     if (haystack[i]==needle) {
       return true;
     }
   }
   return false;
 }

 function closeWindows() {
    if( frames['input'].satInput ) frames['input'].satInput.close();
    if( frames['input'].satModules ) frames['input'].satModules.close();
    if( frames['output'].satModeration ) frames['output'].satModeration.close();
    if( frames['output'].satNotes ) frames['output'].satNotes.close();
    if( frames['output'].satUserPage ) frames['output'].satUserPage.close();
    if( frames['output'].satPrivateChat ) frames['output'].satPrivateChat.close();
    if( frames['input'].satIcons ) frames['input'].satIcons.close();
 }

 //save the size of output frame
 var sizeOfOutput = '';
 var satIsOpen = false;
 var oldChatters;
 var newChatters = new Array();
 var currentChannel = '';
 var maxChatter = <?=MAX_CONCURRENT_CHATTER?>;
 var labelChatterCount = '<?=$_SESSION['translator']->out('CHATTER_COUNT')?>: ';
 function getOptionIndex( chatter )
 {
   currentChatter = frames['input'].document.forms[0].elements['recipient'].options;
   currentChatterLength = currentChatter.length;
   
   for(var i = 0; i < currentChatterLength; i++){
     if(currentChatter[i].value == chatter) return i;
   }
   return false;
 }

 function setChannel(newChannel)
 {
   currentChannel = newChannel.value;
 }
 
 function updateChannelOption(count)
 {
   channels = frames['input'].document.forms[0].elements['channel'].options;
   for(var i = 0; i < channels.length; i++){
     if(channels[i].value == currentChannel)
     {
       channels[i].text = currentChannel+' ('+count+'/'+maxChatter+')';
       return true;
     }
   } 
 }

 function addNewChatter( chatter )
 {
   if(chatter == '<?=$_SESSION['chatter']->get_nick(true)?>')return;
   chatterText = chatter.replace(/\#{3}([^#]*)\#{3}/, guestNickPrefix);
   if( typeof(frames['input'].document.forms[0]) == 'undefined' ){
     delay(2000);
     /*alert('debug: race condition');*/
   }
   recipients = frames['input'].document.forms[0].elements['recipient'].options;
   recipients[recipients.length] = new Option( chatterText, chatter );
   updateChannelOption(recipients.length);
   if(frames['input'])frames['input'].label_operators();
 }

 function delChatter( chatter )
 {
   //chatter = chatter.replace(/\#{3}([^#]*)\#{3}/, guestNickPrefix);
   recipients = frames['input'].document.forms[0].elements['recipient'].options;
   index = getOptionIndex( chatter );
   if( index==false ) return false;
   recipients[index] = null;
   updateChannelOption(recipients.length);
 }

 var lineHasFocus = false;
 var operator_label = '<?=$TEMPLATE_OUT['operator_label']?>';
 function reload_chatters() {
  if( frames['input'] && frames['input'].document && frames['chatter'].document 
   && frames['input'].document.forms[0]
   && frames['chatter']
   && frames['chatter'].document.forms[0]
   && frames['input'].document.forms[0].elements['recipient'] 
   && frames['chatter'].document.forms[0].elements['chatters'])
  {
    newChatters = frames['input'].document.forms[0].elements['recipient'].options;
    newChattersLength = newChatters.length;
    oldChatters = frames['chatter'].document.forms[0].elements['chatters'].options;
    oldChattersLength = oldChatters.length;

    //unset chatters list
    for(var i = 0; i < oldChattersLength; i++){
      oldChatters[i] = null;
    }
    //set chatters list
    for(var i = 0; i < newChattersLength; i++){
      oldChatters[i] = new Option(newChatters[i].text, newChatters[i].value);
    }
    oldChatters[0] = new Option(operator_label + '<?=$_SESSION['chatter']->get_nick()?>','<?=$_SESSION['chatter']->get_nick()?>');
    //chatter.document.forms[0].elements['chatters'].blur();
    frames['chatter'].document.forms[0].elements['chatterCount'].value = labelChatterCount + oldChatters.length;
    if(frames['input']
    && frames['input'].document.forms[0].elements['line']
    && frames['input'].document.forms[0].elements['line'].value == ''
    && lineHasFocus == false){
      frames['input'].document.forms[0].elements['line'].focus();
      lineHasFocus = true;
    }
   }
 }
 
 function autoLogoutNotice()
 {
   if(confirm('<?=$_SESSION['translator']->out('LOGOUT_SHORTLY')?>'))
     frames['input'].document.location.href='input.php?<?=$_SESSION['session_get']?>';
 }
 
 var exitLinkClicked = 0;
 var satLogout;
 function logout()
 {
   if(exitLinkClicked == 1) return true;
   satLogout = window.open("","satLogout","width=1,height=1,left=0,top=0,toolbar=no,location=no,directories=no,status=no,menubar=no,resizable=no,copyhistory=no,scrollbars=no");
   satLogout.blur();
   satLogout.location.href = "input.php?<?=$_SESSION['session_get']?>&exit=1";
   satLogout.close();
 }
 
 var POCHasFocus=true;//will be set or unset by onmouseover or -out within the frames (output, chatter, input)
 var defaultTitle = "<?=$_SESSION['translator']->out('TITLE')?>";
 var newLineTitle      = new Array();
 /* here you can put in your own 'one line ascii art'*/
     newLineTitle[1]   = ">___________/__\\_________________";
     newLineTitle[2]   = "^>__________/__\\_________________";
     newLineTitle[3]   = "_^>_________/__\\_________________";
     newLineTitle[4]   = "__^>________/__\\_________________";
     newLineTitle[5]   = "(__^>_______/__\\_________________";
     newLineTitle[6]   = "~(__^>______/__\\_________________";
     newLineTitle[7]   = "_~(__^>_____/__\\_________________";
     newLineTitle[8]   = "__~(__^>____/__\\_________________";
     newLineTitle[9]   = "___~(__^>___/__\\_________________";
     newLineTitle[10]  = "____~(__^>__/__\\_________________";
     newLineTitle[11]  = "_____~(__^>_/__\\_________________";
     newLineTitle[12]  = "______~(__^>/__\\_________________";
     newLineTitle[13]  = "_______~(__^>__\\_________________";
     newLineTitle[14]  = "________~(__^>_\\_________________";
     newLineTitle[15]  = "_________~(__^>\\_________________";
     newLineTitle[16]  = "__________~(__^\\_________________";
     newLineTitle[17]  = "___________~(__\\_________________";
     newLineTitle[18]  = "____________~(_\\_________________";
     newLineTitle[19]  = "____________/~(\\_________________";
     newLineTitle[20]  = "____________/_~\\_________________";
     newLineTitle[21]  = "____________/__\\_________________";
     newLineTitle[22]  = "____________/__\\_________________";
     newLineTitle[23]  = "____________/__\\_________________";
     newLineTitle[24]  = "____________/_<\\_________________";
     newLineTitle[25]  = "____________/<^\\_________________";
     newLineTitle[26]  = "____________<^_\\_________________";
     newLineTitle[27]  = "___________<^__\\_________________";
     newLineTitle[28]  = "__________<^__)\\_________________";
     newLineTitle[29]  = "_________<^__)~\\_________________";
     newLineTitle[30]  = "________<^__)~_\\_________________";
     newLineTitle[31]  = "_______<^__)~__\\_________________";
     newLineTitle[32]  = "______<^__)~/__\\_________________";
     newLineTitle[33]  = "_____<^__)~_/__\\_________________";
     newLineTitle[34]  = "____<^__)~__/__\\_________________";
     newLineTitle[35]  = "___<^__)~___/__\\_________________";
     newLineTitle[36]  = "__<^__)~____/__\\_________________";
     newLineTitle[37]  = "_<^__)~_____/__\\_________________";
     newLineTitle[38]  = "<^__)~______/__\\_________________";
     newLineTitle[39]  = "^__)~_______/__\\_________________";
     newLineTitle[40]  = "__)~________/__\\_________________";
     newLineTitle[41]  = "_)~_________/__\\_________________";
     newLineTitle[42]  = ")~__________/__\\_________________";
     newLineTitle[43]  = "~___________/__\\_________________";
     newLineTitle[44]  = "____________/__\\_________________";
     newLineTitle[45]  = "____________/__\\_________________";
     newLineTitle[46]  = "____________/__\\_________________";
     
 var currNewLineTitle  = 1;
 var blinkerID         = null;
 var titleBlinkerDelay = 50;
 var blinkerRunning    = false; 
 function setPOCsFocus(bool){
   if(bool==true) resetTitle();
   POCHasFocus = bool;
 }
 function setTitle()
 { 
   if (POCHasFocus==true) return;
   //document.title = '***';
   titleBlinker();
 }
 function resetTitle()
 {
   document.title = defaultTitle;
   if (blinkerRunning)
     clearTimeout(blinkerID);
   blinkerRunning = false;
 }
 function titleBlinker() {
   if(POCHasFocus){
     resetTitle();
     return;
   }
   document.title   = (newLineTitle[currNewLineTitle++]);
   blinkerID        = setTimeout("titleBlinker()",titleBlinkerDelay);
   blinkerRunning   = true;
   //currNewLineTitle = ((currNewLineTitle % newLineTitle.length)==0)? 1:currNewLineTitle++;
   if((currNewLineTitle % newLineTitle.length)==0)currNewLineTitle = 1;
 }
/*]]>*/