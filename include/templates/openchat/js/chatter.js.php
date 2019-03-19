/*<![CDATA[*/
  var ie5=document.all&&document.getElementById;
  function showContextMenu(nickname,index)
  {if(nickname=='')alert('debug: nick is empty!');
    if(nickname=='' || nickname=='<?=$_SESSION['chatter']->get_nick()?>') return false;
    parent.output.setNickname(nickname);
    var left=ie5? parent.output.document.body.clientWidth : parent.output.window.innerWidth;
    left -= parent.output.menuobj.offsetWidth + 3;
    /*alert('Top: '+parent.contextMenuTop+' Left: '+left);*/
    /*alert('debug_: '+ (parent.output.document.all.contentOut.offsetHeight - parent.output.document.body.clientHeight));*/
    parent.scrollContextMenu = true;
    parent.output.showmenufixed(left,parent.menuTop+20);
  }
  document.oncontextmenu = disableRightClick;
  function disableRightClick()
  {
	alert('<?=$_SESSION['translator']->out('RELOAD_MAKES_NO_SENSE')?>');
    return false;
  }

function getNick(index)
{
  var nick = parent.oldChatters[index].value;
  if( nick.match(/\#{3}[^#]*\#{3}/) ) {
  return parent.oldChatters[index].text;
} else {
  return nick;
}
}
/*]]>*/
