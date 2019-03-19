<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?=$_SESSION['translator']->get_language()?>" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$_SESSION['translator']->get_language()?>">
  <head>
    <meta http-equiv="Content-type" content='<?=$_SESSION['template']->get_content_type()?>; charset="<?=$_SESSION['translator']->out('CHARACTER_ENCODING')?>"' />
    <title><?=$_SESSION['translator']->out('TITLE')?></title>
    <link rel="stylesheet" href="<?=$_SESSION['template']->get_theme_path()?>/css/default.css" />
    <!--
      $Id: approve.tpl,v 1.14.2.2 2004/02/25 22:08:50 letreo Exp $
    -->
  </head>
  <body>
  	<div class="satContent">
  	<h1 style="margin:0;padding:0"><?=$_SESSION['translator']->out('APPROVE')?></h1>
  	  <div class="satContentBox">
      	<form action="approve.php" method="post">
    	  	<table>
    	  		<tr>
    	  			<td colspan="2" class="label" valign="top">
    	  			  <input name="line" type="hidden" value="<?=$TEMPLATE_OUT['post_line']?>">
    	  			  <?=$TEMPLATE_OUT['chatter']?> <?=$TEMPLATE_OUT['to']?> <?=$TEMPLATE_OUT['recipient']?>:
    	  			</td>
    	  		</tr>
    	  		<tr>
    	  		  <td colspan="2">
    	  		  <textarea style="width:390px" class="textBox" wrap="virtual" name="said" rows="5" cols="100"><?=$TEMPLATE_OUT['said']?></textarea>
    	  		  </td>
    	  		</tr>
    	  		<tr>
    	  			<td>
    	  			  <input style="color:#fff;font-weight:bold;background-color:#0f0" name="approved_line" type="submit" value="<?=$_SESSION['translator']->out('APPROVE')?>!" />
    	  			</td>
    	  			<td align="right">
    	  			  <input style="color:#fff;font-weight:bold;background-color:#f00" value="<?=$_SESSION['translator']->out('CANCEL')?>!" type="button" onclick="window.close()" />
    	  			  <input name="<?=session_name()?>" type="hidden" value="<?=session_id()?>" />
    	  			</td>
    	  		</tr>
    	  	</table>
      	</form>
      </div>
    </div>
    <div class="menu">
    	<ul>
    		<li>
    			<a href="#" onclick="window.close()"><?=$_SESSION['translator']->out('CLOSE_WINDOW')?></a>
    		</li>
    	</ul>
    </div>
  </body>
</html>
