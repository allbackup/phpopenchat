<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['translator']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <title><?=$_SESSION['translator']->out('ICON_LIST')?></title>
    <script type="text/javascript">
    /*<![CDATA[*/
      function insert_icon_code(code)
      {
        line_value = opener.document.forms[0].elements['line'].value + ' :' + code + ':';
        opener.document.forms[0].elements['line'].value = line_value;
        window.close();
      }
      function insert_theme_icon_code(code, theme)
      {
        code = code + '@' + theme;
        line_value = opener.document.forms[0].elements['line'].value + ' :' + code + ':';
        opener.document.forms[0].elements['line'].value = line_value;
        window.close();
      }
    /*]]>*/
    </script>
    <!--
      Template adapted from "more-icons-mod" of Matthias Ohmann (Rettungsbär) <Retter2000@hotmail.com>
      $Id: insert_more_icons.tpl,v 1.1.2.4 2004/03/01 19:39:36 letreo Exp $
    -->
  </head>
  <body class="background">
    <table class="moreIcons" border="0">
      <tr>
        <td colspan="5"><strong>Emoticons</strong></td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM023')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM023.gif" border="0" alt=":SM023:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM006')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM006.gif" border="0" alt=":SM006:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM022')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM022.gif" border="0" alt=":SM022:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM005')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM005.gif" border="0" alt=":SM005:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM144')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM144.gif" border="0" alt=":SM144:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM033')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM033.gif" border="0" alt=":SM033:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM015')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM015.gif" border="0" alt=":SM015:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM028')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM028.gif" border="0" alt=":SM028:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM003')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM003.gif" border="0" alt=":SM003:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM032')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM032.gif" border="0" alt=":SM032:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM001')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM001.gif" border="0" alt=":SM001:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM037')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM037.gif" border="0" alt=":SM037:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM029')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM029.gif" border="0" alt=":SM029:" /></a>
        </td>
        <td colspan="2">
          <a href="#" onclick="insert_icon_code('smiley11')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/smiley11.gif" border="0" alt=":smiley11:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM074')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM074.gif" border="0" alt=":SM074:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM053')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM053.gif" border="0" alt=":SM053:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM044')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM044.gif" border="0" alt=":SM044:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM131')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM131.gif" border="0" alt=":SM131:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM113')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM113.gif" border="0" alt=":SM113:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM066')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM066.gif" border="0" alt=":SM066:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM014')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM014.gif" border="0" alt=":SM014:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM090')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM090.gif" border="0" alt=":SM090:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM030')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM030.gif" border="0" alt=":SM030:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM031')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM031.gif" border="0" alt=":SM031:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM099')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM099.gif" border="0" alt=":SM099:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM097')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM097.gif" border="0" alt=":SM097:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM093')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM093.gif" border="0" alt=":SM093:" /></a>
        </td>
        <td>
         <a href="#" onclick="insert_icon_code('SM092')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM092.gif" border="0" alt=":SM092:" /></a>
        </td>
        <td>
         <a href="#" onclick="insert_icon_code('SM120')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM120.gif" border="0" alt=":SM120:" /></a>
        </td>
      </tr>
      <tr>
        <td>
         <a href="#" onclick="insert_icon_code('SM094')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM094.gif" border="0" alt=":SM094:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM070')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM070.gif" border="0" alt=":SM070:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM101')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM101.gif" border="0" alt=":SM101:" /></a>
        </td>
        <td>
         <a href="#" onclick="insert_icon_code('SM105')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM105.gif" border="0" alt=":SM105:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM065')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM065.gif" border="0" alt=":SM065:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM068')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM068.gif" border="0" alt=":SM068:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM077')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM077.gif" border="0" alt=":SM077:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM069')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM069.gif" border="0" alt=":SM069:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM082')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM082.gif" border="0" alt=":SM082:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM051')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM051.gif" border="0" alt=":SM051:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM089')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM089.gif" border="0" alt=":SM089:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM038')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM038.gif" border="0" alt=":SM038:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM084')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM084.gif" border="0" alt=":SM084:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM114')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM114.gif" border="0" alt=":SM114:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM108')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM108.gif" border="0" alt=":SM108:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM143')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM143.gif" border="0" alt=":SM143:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM118')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM118.gif" border="0" alt=":SM118:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM050')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM050.gif" border="0" alt=":SM050:" /></a>
        </td>
        <td colspan="2">
          <a href="#" onclick="insert_icon_code('SM129')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM129.gif" border="0" alt=":SM129:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM112')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM112.gif" border="0" alt=":SM112:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM119')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM119.gif" border="0" alt=":SM119:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM013')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM013.gif" border="0" alt=":SM013:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM145')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM145.gif" border="0" alt=":SM145:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM100')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM100.gif" border="0" alt=":SM100:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM002')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM002.gif" border="0" alt=":SM002:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM134')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM134.gif" border="0" alt=":SM134:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM137')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM137.gif" border="0" alt=":SM137:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM138')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM138.gif" border="0" alt=":SM138:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM141')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM141.gif" border="0" alt=":SM141:" /></a>
        </td>
      </tr>
      <tr>
        <td colspan="5"><strong>Greetings and Messages</strong></td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM080')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM080.gif" border="0" alt=":SM080:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM058')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM058.gif" border="0" alt=":SM058:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM096')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM096.gif" border="0" alt=":SM096:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM016')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM016.gif" border="0" alt=":SM016:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM025')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM025.gif" border="0" alt=":SM025:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM075')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM075.gif" border="0" alt=":SM075:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM072')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM072.gif" border="0" alt=":SM072:" /></a>
        </td>
        <td colspan="3">
          <a href="#" onclick="insert_icon_code('SM079')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM079.gif" border="0" alt=":SM079:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM024')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM024.gif" border="0" alt=":SM024:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM127')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM127.gif" border="0" alt=":SM127:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM009')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM009.gif" border="0" alt=":SM009:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM064')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM064.gif" border="0" alt=":SM064:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM116')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM116.gif" border="0" alt=":SM116:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM071')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM071.gif" border="0" alt=":SM071:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM036')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM036.gif" border="0" alt=":SM036:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM115')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM115.gif" border="0" alt=":SM115:" /></a>
        </td>
        <td colspan="2">
          <a href="#" onclick="insert_icon_code('SM054')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM054.gif" border="0" alt=":SM054:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM081')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM081.gif" border="0" alt=":SM081:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM104')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM104.gif" border="0" alt=":SM104:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM017')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM017.gif" border="0" alt=":SM017:" /></a>
        </td>
        <td colspan="2">
          <a href="#" onclick="insert_icon_code('SM010')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM010.gif" border="0" alt=":SM010:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM056')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM056.gif" border="0" alt=":SM056:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM046')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM046.gif" border="0" alt=":SM046:" /></a>
        </td>
        <td colspan="3">
          <a href="#" onclick="insert_icon_code('SM128')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM128.gif" border="0" alt=":SM128:" /></a>
        </td>
      </tr>
      <tr>
        <td colspan="5"><strong>Miscellaneous</strong></td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM102')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM102.gif" border="0" alt=":SM102:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM073')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM073.gif" border="0" alt=":SM073:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM132')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM132.gif" border="0" alt=":SM132:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM135')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM135.gif" border="0" alt=":SM135:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM061')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM061.gif" border="0" alt=":SM061:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM142')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM142.gif" border="0" alt=":SM142:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM027')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM027.gif" border="0" alt=":SM027:" /></a>
        </td>
        <td colspan="3">
          <a href="#" onclick="insert_icon_code('SM063')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM063.gif" border="0" alt=":SM063:" /></a>
        </td>
      </tr>
      <tr>
        <td colspan="5">
          <a href="#" onclick="insert_icon_code('SM026')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM026.gif" border="0" alt=":SM026:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM040')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM040.gif" border="0" alt=":SM040:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM018')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM018.gif" border="0" alt=":SM018:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM086')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM086.gif" border="0" alt=":SM086:" /></a>
        </td>
        <td colspan="2">
          <a href="#" onclick="insert_icon_code('SM039')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM039.gif" border="0" alt=":SM039:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM067')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM067.gif" border="0" alt=":SM067:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM055')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM055.gif" border="0" alt=":SM055:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM059')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM059.gif" border="0" alt=":SM059:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM043')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM043.gif" border="0" alt=":SM043:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM011')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM011.gif" border="0" alt=":SM011:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM103')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM103.gif" border="0" alt=":SM103:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM052')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM052.gif" border="0" alt=":SM052:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM106')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM106.gif" border="0" alt=":SM106:" /></a>
        </td>
        <td colspan="2">
          <a href="#" onclick="insert_icon_code('SM021')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM021.gif" border="0" alt=":SM021:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM088')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM088.gif" border="0" alt=":SM088:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM008')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM008.gif" border="0" alt=":SM008:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM095')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM095.gif" border="0" alt=":SM095:" /></a>
        </td>
        <td colspan="2">
          <a href="#" onclick="insert_icon_code('SM019')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM019.gif" border="0" alt=":SM019:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM109')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM109.gif" border="0" alt=":SM109:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM041')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM041.gif" border="0" alt=":SM041:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM117')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM117.gif" border="0" alt=":SM117:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM045')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM045.gif" border="0" alt=":SM045:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM110')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM110.gif" border="0" alt=":SM110:" /></a>
        </td>
      </tr>
      <tr>
        <td>
          <a href="#" onclick="insert_icon_code('SM004')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM004.gif" border="0" alt=":SM004:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM136')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM136.gif" border="0" alt=":SM136:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM140')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM140.gif" border="0" alt=":SM140:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM048')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM048.gif" border="0" alt=":SM048:" /></a>
        </td>
        <td>
          <a href="#" onclick="insert_icon_code('SM133')"><img src="<?=$_SESSION['template']->get_theme_path()?>/images/icons/smileys/SM133.gif" border="0" alt=":SM133:" /></a>
        </td>
      </tr>
    </table>
    <?=$TEMPLATE_OUT['more_icons']?>
  </body>
</html>