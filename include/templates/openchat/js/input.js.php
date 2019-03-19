/*<![CDATA[*/
  var ln='<?=$TEMPLATE_OUT['show_message_locally']?>';
  var undocked=0;
  var formPost=0;
  if( (window.opener != null) && (typeof(window.opener) != 'undefined') ){
    opener.parent.inputFormPost=0;
    undocked=1;
  }
  if( parent && parent.output )
  {
    //if(parent.is_opera6up) {
    if(parent.is_opera && !parent.is_opera7up) {
      parent.lines += ln;
      parent.output.document.writeln(parent.lines);
    } else {
      parent.output.document.writeln(ln);
    }
  }
  if( opener && opener.parent && opener.parent.output )
  {
    //if(opener.parent.is_opera6up) {
    if(opener.parent.is_opera && !opener.parent.is_opera7up) {
      opener.parent.lines += ln;
      opener.parent.output.document.writeln(opener.parent.lines);
    } else {
      opener.parent.output.document.writeln(ln);
    }
  }
  
  function logout()
  {
    if(undocked==0 || formPost==1) return true;
    opener.parent.logout();
    opener.parent.dummy.location.href='index.php?forceOnTop=1';
  }
  
  var satInput;
  var clickCount = 0;
  var last_sent_line = '<?=$_POST['line']?>';
  var last_recipient = '<?=$_POST['recipient']?>';
  var operator_label = '<?=OPERATOR_LABEL?>';

  function openIconList ()
  {
    <?php if(defined('OFFER_MORE_ICONS') && OFFER_MORE_ICONS){?>
      satIcons = window.open("","satIcons","width=450,height=350,left=20,top=400,dependent=yes,scrollbars=yes");
    <?php }else{?>
      satIcons = window.open("","satIcons","width=170,height=170,left=20,top=400,dependent=yes,scrollbars=yes");
    <?php }?>
    window.satIcons.focus();
  }

  var satModules;
  function openWindow ()
  {
    satModules = window.open("","satModules","width=720,height=430,left=30,top=50,dependent=yes,scrollbars=yes");
    window.satModules.focus();
  }

  function inputWindow ()
  {
    if( parent.satIsOpen == false )
    {
      satInput = window.open("","satInput","width=790,height=150,left=0,top=350,dependent=yes");
      var _rows = parent.document.body.rows.split(",");
      parent.defaultSizeOfOutput = _rows[0];
      parent.document.body.rows = "100%" + "," + _rows[1] + "," + _rows[2];
      parent.satIsOpen = true;
    }
    else
    {
      var _rows = opener.parent.document.body.rows.split(",");
      opener.parent.document.body.rows = opener.parent.defaultSizeOfOutput + "," + _rows[1] + "," + _rows[2];
      opener.parent.satIsOpen = false;
      window.close();
    }
  }

  function checkValue()
  {
    line = document.forms[0].elements['line'].value;
    recipient = document.forms[0].elements['recipient'].value;
    channel = document.forms[0].elements['channel'].value;
    if(clickCount>=4 && confirm('<?=$_SESSION['translator']->out('NO_CLICKETY_CLICK')?>')) clickCount = 0;
    if(line == '' || clickCount > 2) return false;
    if(line == last_sent_line && recipient == last_recipient) return false;
    //if(channel == '') return false;
    return true;
  }
  
  function checkChannel(channel)
  {
    if(channel.value == '')
    { 
      channel.value = '<?=$_SESSION['channel']->get_name()?>';
      return false;
    }
    return true;
  }
  
  function countClick()
  {
    if(document.forms[0].elements['line']!='')
      clickCount += 1;
  }

  function do_focus()
  {
    document.forms[0].elements[3].focus();
    if(parent.output.satPrivateChat)
    {
      parent.output.satPrivateChat.focus();
    }
  }
  
  function label_operators() {
    recipients = document.forms[0].elements['recipient'];
    for (var i=0; i<recipients.length; i++) {
      if( parent && parent.operators
      &&  parent.in_array(recipients[i].value,parent.operators) ) {
        recipients[i].text  = operator_label+recipients[i].value;
  //recipients[i].value = recipients[i].value;
      }
      if( opener && opener.parent.operators
      &&  opener.parent.in_array(recipients[i].value,opener.parent.operators) ) {
        recipients[i].text  = operator_label+recipients[i].value;
  //recipients[i].value = recipients[i].value;
      }
    }
  }
  
  function setPOCsFocus(bool){
    if (parent) parent.setPOCsFocus(bool);
    else if (opener && opener.parent) opener.parent.setPOCsFocus(bool);
  }
/*]]>*/