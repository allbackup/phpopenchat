<?php
  require_once('config.inc.php');
    
  require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
  require_once(POC_INCLUDE_PATH.'/class.Installer.inc');
  $installer = &new POC_Installer(realpath('.'));
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="en" xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
  <head>
    <meta http-equiv="Content-type" content='text/html; charset="ISO-8859-1"' />
    <meta name="generator" content="PHPOpenChat v3 (http://phpopenchat.org/)" />
    <title>PHPOpenChat (POC) - Installer</title>
    <script type="text/javascript">
    function selectDB(selectBox){
      if(selectBox.options[0].selected == false){
        document.forms[0].elements['create_db'].checked=false;
        document.forms[0].elements['create_db'].disabled=true;        
      }
    }
    </script>
    <style type="text/css">
    .input[type="submit"]{
      border: 2px dashed #f00
    }
    table#breadcrumbs td{
      padding-right:15px;
    }
    </style>
  <body style="background-color: #fff">
  <?php
    $installer->set_current_step($_REQUEST['step']);
    print $installer->breadcrumb();
    switch( $installer->get_current_step() ){
      case 1: print $installer->check_write_permissions();
        break;
      case 2: print $installer->database_setup();
        break;
      case 3: print $installer->init_database();
        break;
      case 4: print $installer->install_complete();
        break;
      //default: print $installer->check_write_permissions();
    }
  ?>
    
    <hr style="border:1px dashed green;" />
    <img alt="POC Logo" src="include/templates/openchat/images/buttons/poc_button.gif" height="33" width="90" border="0" />
  </body>
</html>