<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['translator']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <title></title>
    <script type="text/javascript">
    /*<![CDATA[*/
      function insert_icon_code(code)
      {
        line_value = opener.document.forms[0].elements['line'].value + ' :' + code + ':';
        opener.document.forms[0].elements['line'].value = line_value;
        window.close();
      }
    /*]]>*/
    </script>
    <!--
      $Id: insert_icon.tpl,v 1.2.2.4 2004/02/29 19:57:11 letreo Exp $
    -->
  </head>
  <body class="background">
    <map name="map1">
      <area shape="rect" coords="120,121,145,137" href="#" onclick="insert_icon_code('help')" target="_self" title=":help:" alt=":help:" />
      <area shape="rect" coords="104,121,120,136" href="#" onclick="insert_icon_code('hehe')" target="_self" title=":hehe:" alt=":hehe:" />
      <area shape="rect" coords="87,120,102,136" href="#" onclick="insert_icon_code('evillaugh')" target="_self" title=":evillaugh:" alt=":evillaugh:" />
      <area shape="rect" coords="58,119,82,135" href="#" onclick="insert_icon_code('stoned')" target="_self" title=":stoned:" alt=":stoned:" />
      <area shape="rect" coords="41,119,58,135" href="#" onclick="insert_icon_code('wow')" target="_self" title=":wow:" alt=":wow:" />
      <area shape="rect" coords="19,119,41,136" href="#" onclick="insert_icon_code('sun')" target="_self" title=":sun:" alt=":sun:" />
      <area shape="rect" coords="0,119,19,136" href="#" onclick="insert_icon_code('yawn')" target="_self" title=":yawn:" alt=":yawn:" />
      <area shape="rect" coords="126,103,141,120" href="#" onclick="insert_icon_code('trash')" target="_self" title=":trash:" alt=":trash:" />
      <area shape="rect" coords="104,103,126,121" href="#" onclick="insert_icon_code('thumbsup')" target="_self" title=":thumbsup:" alt=":thumbsup:" />
      <area shape="rect" coords="87,104,102,120" href="#" onclick="insert_icon_code('rolleyes')" target="_self" title=":rolleyes:" alt=":rolleyes:" />
      <area shape="rect" coords="40,102,87,119" href="#" onclick="insert_icon_code('repuke')" target="_self" title=":repuke:" alt=":repuke:" />
      <area shape="rect" coords="0,102,40,119" href="#" onclick="insert_icon_code('rambo')" target="_self" title=":rambo:" alt=":rambo:" />
      <area shape="rect" coords="120,88,138,103" href="#" onclick="insert_icon_code('tongue')" target="_self" title=":tongue:" alt=":tongue:" />
      <area shape="rect" coords="104,88,120,102" href="#" onclick="insert_icon_code('question')" target="_self" title=":question:" alt=":question:" />
      <area shape="rect" coords="86,88,103,103" href="#" onclick="insert_icon_code('poc')" target="_self" title=":poc:" alt=":poc:" />
      <area shape="rect" coords="64,88,86,104" href="#" onclick="insert_icon_code('phoneme')" target="_self" title=":phoneme:" alt=":phoneme:" />
      <area shape="rect" coords="37,88,63,102" href="#" onclick="insert_icon_code('lol')" target="_self" title=":lol:" alt=":lol:" />
      <area shape="rect" coords="0,87,37,102" href="#" onclick="insert_icon_code('lovestory')" target="_self" title=":lovestory:" alt=":lovestory:" />
      <area shape="rect" coords="120,71,144,87" href="#" onclick="insert_icon_code('tombstone')" target="_self" title=":tombstone:" alt=":tombstone:" />
      <area shape="rect" coords="104,71,120,88" href="#" onclick="insert_icon_code('rose')" target="_self" title=":rose:" alt=":rose:" />
      <area shape="rect" coords="85,71,104,87" href="#" onclick="insert_icon_code('nono')" target="_self" title=":nono:" alt=":nono:" />
      <area shape="rect" coords="64,71,85,87" href="#" onclick="insert_icon_code('male')" target="_self" title=":male:" alt=":male:" />
      <area shape="rect" coords="37,71,64,88" href="#" onclick="insert_icon_code('fairy')" target="_self" title=":fairy:" alt=":fairy:" />
      <area shape="rect" coords="0,71,37,87" href="#" onclick="insert_icon_code('finger')" target="_self" title=":finger:" alt=":finger:" />
      <area shape="rect" coords="87,53,102,69" href="#" onclick="insert_icon_code('love')" target="_self" title=":love:" alt=":love:" />
      <area shape="rect" coords="34,54,70,70" href="#" onclick="insert_icon_code('director')" target="_self" title=":director:" alt=":director:" />
      <area shape="rect" coords="16,52,34,70" href="#" onclick="insert_icon_code('denied')" target="_self" title=":denied:" alt=":denied:" />
      <area shape="rect" coords="102,52,119,69" href="#" onclick="insert_icon_code('verysad')" target="_self" title=":verysad:" alt=":verysad:" />
      <area shape="rect" coords="0,52,16,71" href="#" onclick="insert_icon_code('dynamite')" target="_self" title=":dynamite:" alt=":dynamite:" />
      <area shape="rect" coords="119,37,139,69" href="#" onclick="insert_icon_code('toilet')" target="_self" title=":toilet:" alt=":toilet:" />
      <area shape="rect" coords="102,35,119,52" href="#" onclick="insert_icon_code('sail')" target="_self" title=":sail:" alt=":sail:" />
      <area shape="rect" coords="87,35,102,52" href="#" onclick="insert_icon_code('kiss')" target="_self" title=":kiss:" alt=":kiss:" />
      <area shape="rect" coords="70,35,87,53" href="#" onclick="insert_icon_code('female')" target="_self" title=":female:" alt=":female:" />
      <area shape="rect" coords="53,35,70,52" href="#" onclick="insert_icon_code('eating')" target="_self" title=":eating:" alt=":eating:" />
      <area shape="rect" coords="37,35,53,54" href="#" onclick="insert_icon_code('crying')" target="_self" title=":crying:" alt=":crying:" />
      <area shape="rect" coords="15,35,34,52" href="#" onclick="insert_icon_code('cool')" target="_self" title=":cool:" alt=":cool:" />
      <area shape="rect" coords="0,35,15,52" href="#" onclick="insert_icon_code('confused')" target="_self" title=":confused:" alt=":confused:" />
      <area shape="rect" coords="119,19,135,37" href="#" onclick="insert_icon_code('toffline')" target="_self" title=":toffline:" alt=":toffline:" />
      <area shape="rect" coords="102,18,119,35" href="#" onclick="insert_icon_code('rain')" target="_self" title=":rain:" alt=":rain:" />
      <area shape="rect" coords="86,17,102,35" href="#" onclick="insert_icon_code('massa')" target="_self" title=":massa:" alt=":massa:" />
      <area shape="rect" coords="68,17,86,35" href="#" onclick="insert_icon_code('ghost')" target="_self" title=":ghost:" alt=":ghost:" />
      <area shape="rect" coords="51,17,68,35" href="#" onclick="insert_icon_code('flower')" target="_self" title=":flower:" alt=":flower:" />
      <area shape="rect" coords="37,17,51,35" href="#" onclick="insert_icon_code('cloud')" target="_self" title=":cloud:" alt=":cloud:" />
      <area shape="rect" coords="15,17,37,35" href="#" onclick="insert_icon_code('borg')" target="_self" title=":borg:" alt=":borg:" />
      <area shape="rect" coords="0,17,15,35" href="#" onclick="insert_icon_code('biggrin')" target="_self" title=":biggrin:" alt=":biggrin:" />
      <area shape="rect" coords="121,1,141,19" href="#" onclick="insert_icon_code('smoky')" target="_self" title=":smoky:" alt=":smoky:" />
      <area shape="rect" coords="101,0,118,18" href="#" onclick="insert_icon_code('smoke')" target="_self" title=":smoke:" alt=":smoke:" />
      <area shape="rect" coords="88,0,101,16" href="#" onclick="insert_icon_code('punk')" target="_self" title=":punk:" alt=":punk:" />
      <area shape="rect" coords="68,1,85,17" href="#" onclick="insert_icon_code('frown')" target="_self" title=":frown:" alt=":frown:" />
      <area shape="rect" coords="51,1,68,17" href="#" onclick="insert_icon_code('frog')" target="_self" title=":frog:" alt=":frog:" />
      <area shape="rect" coords="37,1,48,16" href="#" onclick="insert_icon_code('candle')" target="_self" title=":candle:" alt=":candle:" />
      <area shape="rect" coords="17,1,34,15" href="#" onclick="insert_icon_code('bomb')" target="_self" title=":bomb:" alt=":bomb:" />
      <area shape="rect" coords="2,1,14,13" href="#" onclick="insert_icon_code('beard')" target="_self" title=":beard:" alt=":beard:" />
    </map>
    <img src="<?=$_SESSION['template']->get_theme_path()?>/images/icon_list.png" width="150" height="150" border="0" usemap="#map1" alt="smiley icons" />
  </body>
</html>