/*<![CDATA[*/
function openHelpWindow(helpText,coordX,coordY)
{
  coordY -= 210;
  satHelp = window.open('','satHelp','width=140,height=170,screenX='+coordX+',screenY='+coordY+',top='+coordY+',left='+coordX+',dependent=yes,scrollbars=yes');
  
  satHelp.document.write('<html><head><title><?=$_SESSION['translator']->out('HELP')?><\/title>');
  satHelp.document.write('<link rel="stylesheet" title="Default" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />');
  satHelp.document.write('<\/head>');
  satHelp.document.write('<body>');
  satHelp.document.write('<dl class="help"><dt><?=$_SESSION['translator']->out('HELP')?><\/dt><dd>');
  satHelp.document.write(helpText);
  satHelp.document.write('<\/dd><\/dl>');
  satHelp.document.write('<div style="text-align:right;padding-right:3px"><a href="#" onclick="window.close()" style="font-size: .7em"><?=$_SESSION['translator']->out('CLOSE_WINDOW')?><\/a><\/div>');
  satHelp.document.write('<\/body><\/html>');
}

function setSpeed() {
  var scrollspeed = document.speed.options;
  var index = scrollspeed.selectedIndex;
  var newSpeed = scrollspeed.options[index].value;

  if( opener.parent.speed == 0 )
    var scroll = true;
  else
    var scroll = false;

  if ( newSpeed >= 0 )
    opener.parent.speed = newSpeed;

  if( scroll )
    opener.parent.scroll_it();
}

/*Flash calls this function*/
function send_me(givenColor){
  cl(givenColor.replace(/#/,""));
}

function cl(col){
  document.forms[0].color.value = col;
  document.forms[0].submit();
}

function logout(){
  if(opener){
    opener.document.location.href='input.php?<?=$_SESSION['session_get']?>&exit=1';
    window.close();
  }
}

function showColorPickerHTML(coordX,coordY){
  satColorPicker = window.open('','satColorPicker','width=112,height=162,screenX='+coordX+',screenY='+coordY+',top='+coordY+',left='+coordX+',dependent=yes,scrollbars=no');
  var d="0369CF";
  var x=y=z=0;
  var i=1;
  var c,s1,s2;
  satColorPicker.document.writeln('<html><head><title>ColorPicker<\/title><\/head><body><table cellpadding="0" cellspacing="0"><tbody><tr>');
  while (i<216) {
    c=d.substring(x,x+1)+d.substring(x,x+1)+d.substring(y,y+1)+d.substring(y,y+1)+d.substring(z,z+1)+d.substring(z,z+1);
    if(i %12 == 0 && i!=0){
      s1="<td bgcolor=\"#"+c+"\"><a style=\"background:none\" class=\"imageLink\" href=\"#\" onclick=\"opener.cl('"+c+"');window.close()\" title=\"#"+c+"\"><img src=\"<?=$_SESSION['template']->get_theme_path()?>/images/dot_clear.gif\" border=\"0\" width=\"8\" height=\"8\" alt=\"#"+c+"\"><\/a><\/td>";
      s2="<\/tr><tr>";
    }else{
      s1="<td bgcolor=\"#"+c+"\"><a style=\"background:none\" class=\"imageLink\" href=\"#\" onclick=\"opener.cl('"+c+"');window.close()\" title=\"#"+c+"\"><img src=\"<?=$_SESSION['template']->get_theme_path()?>/images/dot_clear.gif\" border=\"0\" width=\"8\" height=\"8\" alt=\"#"+c+"\"><\/a><\/td>";
      s2="<\/td>";
    }
    satColorPicker.document.writeln(s1+s2);
    x++;
    i++;
    if(x==6){
      x=0;
      y++;
    }  
    if(y==6){
      y=0;
      z++;
    }
  }
  satColorPicker.document.writeln('<\/tr><\/tbody><\/table><\/body><\/html>');
}

function closeColPickWin(){
  if(satColorPicker)satColorPicker.close();
}
/*]]>*/