<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="###_LANG###" xmlns="http://www.w3.org/1999/xhtml" xml:lang="###_LANG###">
  <head>
    <meta http-equiv="Content-type" content='text/html; charset="###CHARACTER_ENCODING###"'/>
    <title>###TITLE###</title>
    <link rel="stylesheet" href="@@@THEME_PATH@@@/css/output.css"/>
    <script type="text/javascript">
      /* For comments please only use block comments like this */
      var taggedDiv='';
      var nickname='';
      var myNick='###MY_NICK###';
      var mySelection='';
      var disableContextMenu=###DISABLE_CONTEXT_MENU###;
      
      function tagDiv(givenDiv)
      {
        taggedDiv=givenDiv;
      }
      
      function openWindow ()
      {
        satModeration = window.open("","satModeration","width=700,height=230,left=30,top=50,dependent=yes,scrollbars=yes");
      }

      function showNotice(coordX,coordY,nick)
      {
        if(getNickname(nick)==false)
          return false;
        else{
          /*satNotes = window.open('notes.php?nick='+getNickname(nick)+'&'+parent.php_session_param,'satNotes','width=700,height=350,screenX='+coordX+',screenY='+coordY+',top='+coordY+',left='+coordX+',dependent=yes,scrollbars=no');*/
          satNotes = window.open('notes.php?nick='+getNickname(nick)+'&'+parent.php_session_param,'satNotes','width=700,height=350,dependent=yes,scrollbars=no');
          return false;
        }
      }

      function showUserPage(coordX,coordY,nick)
      {
        if(getNickname(nick)==false)
          return false;
        else{
          /*satUserPage = window.open('userpage.php?nick='+getNickname(nick)+'&'+parent.php_session_param,'satUserPage','width=740,height=350,screenX='+coordX+',screenY='+coordY+',top='+coordY+',left='+coordX+',dependent=yes,scrollbars=yes');*/
          satUserPage = window.open('userpage.php?nick='+getNickname(nick)+'&'+parent.php_session_param,'satUserPage','width=740,height=350,dependent=yes,scrollbars=yes');
          return false;
        }
      }

      function selectNick(nick,wispered)
      {
        parent.input.document.forms[0].recipient.value = getNickname(nick);

        if(wispered == 1 && parent.input.document.forms[0].whispered.checked == false){
          parent.input.document.forms[0].whispered.click();
        }else if(wispered == 0 && parent.input.document.forms[0].whispered.checked == true){
          parent.input.document.forms[0].whispered.click();
        }

        parent.input.document.forms[0].line.focus();
        return false;
      }

      function setNickname(nick)
      {
        nickname = nick;
      }

      function getNickname(nick)
      {
        /*guest nick adaptation*/
        re1 = new RegExp('^'+parent.guestNickPrefix+'.\\d');
        re2 = new RegExp(parent.guestNickPrefix);
        if( nickname.search(re1) != -1 ){
          return nickname.replace(re2, "\#\#\#GUEST_NICK_PREFIX\#\#\#");
        }
        
        if(nick != ''){
          return nick;
        }else if(nickname != ''){
          return nickname;
        }else{
          alert('No nickname given!');
          return false;
        }
      }

      function privateChatWindow(nickname, channel)
      {
         if(nickname == '###STATUS_BOT_NAME###'){
           alert('###CHATTER_IS_BUSY###');
           return false;
         }
         if(  nickname != '###STATUS_BOT_NAME###' 
          && (!window.satPrivateChat 
          || (window.satPrivateChat && window.satPrivateChat.closed))
         ){
           satPrivateChat = window.open('private_frameset.php?dialog_partner='+nickname+'&channel='+channel+'&'+parent.php_session_param,'satPrivateChat','width=500,height=350,screenX=50,screenY=50,top=50,left=50,dependent=yes,scrollbars=no');
         }else if(nickname == '###MY_NICK###'){
           parent.dummy.location.href = 'private_destroy.php?busy=1&'+parent.php_session_param;
           alert(channel+' ###WANTS_TO_TALK###');
         }else{
           alert('###YOU_ARE_BUSY###');
         }
         return false;
      }
	  
  	  function add_selection_to_notices(nick)
  	  {
        if(getNickname(nick)==false)
          return false;
        var today = new Date();
        parent.dummy.location.href='notes.php?silent=1&new_note=['+today.toLocaleString()+']'+mySelection+'&nick='+getNickname('')+'&'+parent.php_session_param;
        alert('###NICKNAME###: '+getNickname('')+'\n ###FOLLOWING_NOTE_ADDED###: "'+mySelection+'"');
  	  }
    </script>
    <style type="text/css">
      @media screen {
        body>div.skin0 {
          position: fixed;
        }
      }
	  body{
		  /* don't display any scrollbars */
		  overflow-x: hidden;
		  overflow-y: auto;
	  }
    </style>
    <!--
      $Id: output.tpl,v 1.27.2.16 2004/08/06 13:01:54 letreo Exp $
    -->
  </head>
  <body id="contentOut" class="background" onmouseover="parent.setPOCsFocus(true)" onmouseout="parent.setPOCsFocus(false)">
    <p class="vendor"><a href="http://phpopenchat.org/" target="_new">PHPOpenChat</a> ###POC_VERSION###</p>
    <div id="ie5menu" class="skin0" onMouseover="highlightie5(event)" onMouseout="lowlightie5(event)" onClick="jumptoie5(event)" style="display: none">
      <div onclick="return false">
        <form action=""><input type="text" value="" readonly="readonly" class="nicknameTextField" style="" /></form>
      </div>
      <div class="menuitems" onclick="return selectNick('',0)">
        ###SAY_TO_ICON### ###SAY_TO###
      </div>
      <div class="menuitems" onclick="return selectNick('',1)">
        ###WHISPER_TO_ICON### ###WHISPER_TO###
      </div>
      <div class="menuitems" onclick="return showUserPage(event.screenX,event.screenY,'')">
        ###USERPAGE_ICON### ###USER_PAGE###
      </div>
      <div class="menuitems" onclick="return privateChatWindow(nickname,'###MY_NICK###')">
        ###PRIVATE_CHAT_ICON### ###PRIVATE_CHAT_NEW_WINDOW###
      </div>
      <div class="menuitems" onclick="return showNotice(event.screenX,event.screenY,'')">
        ###NOTICE_ICON### ###NOTE_ABOUT###
      </div>
      <div class="menuitems" onclick="parent.dummy.location.href='friends.php?silent=1&amp;new_friend='+nickname+'&'+parent.php_session_param">
        ###ADD_FRIEND_ICON### ###ADD_TO_FRIENDLIST###
      </div>
      <div class="menuitems" onclick="parent.dummy.location.href='ignore.php?silent=1&amp;unignored_chatter='+nickname+'&'+parent.php_session_param">
        ###IGNORE_CHATTER_ICON### ###IGNORE_CHATTER###
      </div>
      <!--div class="menuitems" onclick="parent.dummy.location.href='ignore.php?silent=1&amp;ignored_chatter='+nickname+'&'+parent.php_session_param">
        ###UNIGNORE_CHATTER_ICON### ###UNIGNORE_CHATTER###
      </div-->
      <div class="menuitems" onclick="parent.dummy.location.href='invite.php?silent=1&amp;disinvited_chatter='+nickname+'&'+parent.php_session_param">
        ###INVITE_ICON### ###INVITE_CHATTER###
      </div>
      <div class="menuitems" onclick="parent.dummy.location.href='invite.php?silent=1&amp;invited_chatter='+nickname+'&'+parent.php_session_param">
       ###DISINVITE_ICON### ###DISINVITE_CHATTER###
      </div>
      <div id="getSelection" class="menuitems" onclick="add_selection_to_notices()">
       ###TRANSPARENT_ICON### ###ADD_SELECTION_TO_NOTES###
      </div>
      <hr />
      <div class="menuitems"><a class="menuitems" href="mailto:###ADMIN_MAIL_ADDRESS###">###MAIL_ICON### ###EMAIL_US###</a></div>
    </div>

    <script type="text/javascript">
    /*<![CDATA[*/
      /* For comments please only use block comments like this */
      
      var ie5=document.all&&document.getElementById;
      var ns6=document.getElementById&&!document.all;
      if (ie5||ns6)
        var menuobj=document.getElementById("ie5menu");

      function showmenufixed(left,top)
      {
        menuobj.style.left = left;
        menuobj.style.top = top;
        menuobj.style.visibility="visible";
        if(ie5) document.all.getSelection.style.visibility="hidden";
        document.forms[0].elements[0].value = nickname;
        return false;
      }

      function showmenuie5(e){
        if(ns6) mySelection = document.getSelection();/*test*/
        parent.scrollContextMenu = false;

        if(nickname=='') return false;
        var rightedge=ie5? document.body.clientWidth-event.clientX : window.innerWidth-e.clientX;
        var bottomedge=ie5? document.body.clientHeight-event.clientY : window.innerHeight-e.clientY;
          
        if (rightedge < menuobj.offsetWidth)
          menuobj.style.left=ie5? document.body.scrollLeft+event.clientX-menuobj.offsetWidth : window.pageXOffset+e.clientX-menuobj.offsetWidth;
        else
          menuobj.style.left=ie5? document.body.scrollLeft+event.clientX : window.pageXOffset+e.clientX;

        if(ns6){
          if (bottomedge < menuobj.offsetHeight)
            menuobj.style.top = e.clientY-menuobj.offsetHeight;
          else
            menuobj.style.top = e.clientY;
        } else {
          if (bottomedge < menuobj.offsetHeight)
            menuobj.style.top=ie5? document.body.scrollTop+event.clientY-menuobj.offsetHeight : window.pageYOffset+e.clientY-menuobj.offsetHeight;
          else
            menuobj.style.top=ie5? document.body.scrollTop+event.clientY : window.pageYOffset+e.clientY;
        }
        menuobj.style.visibility="visible";
        if(ie5) document.all.getSelection.style.visibility="hidden";
        document.forms[0].elements[0].value = nickname;
        return false;
      }

      function hidemenuie5(e){
        menuobj.style.visibility="hidden";
      }

      function highlightie5(e){
        var firingobj=ie5? event.srcElement : e.target;
        if (firingobj.className=="menuitems"||ns6&&firingobj.parentNode.className=="menuitems"){
          if (ns6&&firingobj.parentNode.className=="menuitems")
            firingobj=firingobj.parentNode;
          firingobj.style.backgroundColor="highlight";
          firingobj.style.color="white";
        }
      }

      function lowlightie5(e){
        var firingobj=ie5? event.srcElement : e.target;
        if (firingobj.className=="menuitems"||ns6&&firingobj.parentNode.className=="menuitems"){
          if (ns6&&firingobj.parentNode.className=="menuitems")
            firingobj=firingobj.parentNode;
          firingobj.style.backgroundColor="";
          firingobj.style.color="white";
          window.status='';
        }
      }

      function jumptoie5(e){
        var firingobj=ie5? event.srcElement : e.target;
        if (firingobj.className=="menuitems"||ns6&&firingobj.parentNode.className=="menuitems"){
          if (ns6&&firingobj.parentNode.className=="menuitems")
            firingobj=firingobj.parentNode;
          if (firingobj.getAttribute("target"))
            window.open(firingobj.getAttribute("url"),firingobj.getAttribute("target"));
          else
          {
            /*window.location=firingobj.getAttribute("url");*/
          }
        }
      }

      if (ie5||ns6){
        menuobj.style.display='';
        if(disableContextMenu==false){
		  document.oncontextmenu=showmenuie5;
		}
        document.onclick=hidemenuie5;
      }
    </script>
    <div class="content">
<!-- Do not add the missing end tags of <html>, <body> or <div> element! -->
<!-- The content will be added automatically -->
