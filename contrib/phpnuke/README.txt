Integration of the PHPOpenChat (POC) into phpnuke

What I have to do to integrade the POC into my phpnuke-installation?

1) Upload the image file 'button_poc.gif' to -> /path_to_nuke/images/
2) Setup the following properties within the file 'poc.php'

$poc_doc_root  = '/phpopenchat'; // directory name of your POC installation
$poc_root_path = './../phpopenchat'; // the relative path from nuke installation to POC installation

Your Chat is in the directory called chatb7
nuke & chat are in the same root-directory.

The paths would be:

$poc_doc_root  = '/chatb7';
$poc_root_path = '../chatb7/';

If phpnuke & Chat are not located in the same root-folder, you have
to edit this lines.. 




Database Options:

$dbhost = "localhost";         // 'localhost' or 'www.yoursiteurl.com' if on a remote site
$dbuser = "root";           // username
$dbpwd = "";            // password
$dbname = "";       // the name of your database



Scriptoptions:

$deftheme = 'openchat'; // POC default Theme
$siteurl = 'http://www.yourdomain.tld'; // Your Domain URL -- without ending  "/"
$nuke_prefix = 'nuke_'; // Prefix of phpnuke tables // Most likely "nuke_"
$nukeordner = '/'; 

 The Foldername of phpnuke; 
 If php nuke is not in a seperate folder, for example in the webroot, delete the "/".



ATTENTION!

Guests will receive a message to register them selves or to use a link to
the Login formular..

If you do not want to let guests have access to the chat, do this:



If you want to have NO Guest Login, please do:

=====================================
Find 
=====================================

echo"<table class='fonts' width='100%' border='0' cellspacing='0' cellpadding='0'>
  <tr>
    <td><p><font size='2' face='Georgia, Times New Roman, Times, serif'><strong><font face='Verdana, Arial, Helvetica, sans-serif'>Hello Guest!</font></strong> </font></p>
        <p><font size='2' face='Verdana, Arial, Helvetica, sans-serif'> If you want to chat as guest, please click the \"Guest-Chat\" button. <br>
        To enter the chat without any username/password dialogue, it would be better so registrate yourself with our portal. <br>
       </font><br>

</p>
        <center>

<form action='".$siteurl.$poc_doc_root."/index.php' method='get'>
  <div align=\'center\'>
    <input type='submit' name='Submit' value='Guest-Chat'>
  </div>
</form>
<form action='".$siteurl.$nukeordner."/modules.php' method='get'>
  <div align=\'center\'>
    <input type='submit' name='Submit' value='registration'>
	<input type='hidden' value='profile' name='file'>
	<input type='hidden' value='register' name='mode'>
  		<input type='hidden' value='Forums' name='name'>
</div>
</form>

</center>
          <br>
    </td>
  </tr>
</table>";


exit;

=====================================
Replace with:
=====================================

echo"<table class='fonts' width='100%' border='0' cellspacing='0' cellpadding='0'>
  <tr>
    <td><p><font size='2' face='Georgia, Times New Roman, Times, serif'><strong><font face='Verdana, Arial, Helvetica, sans-serif'>

Sorry, no guest Login!!

    </td>
  </tr>
</table>";


exit;

=====================================

=====================================



The registration in my example is handled by phpbb in nuke. If you want to 
let your users register themselves via "Your_Account", please do the following:



=====================================
Find
=====================================

<form action='".$siteurl.$nukeordner."/modules.php' method='get'>
  <div align=\'center\'>
    <input type='submit' name='Submit' value='registration'>
	<input type='hidden' value='profile' name='file'>
	<input type='hidden' value='register' name='mode'>
  		<input type='hidden' value='Forums' name='name'>
</div>
</form>

=====================================
Replace with
=====================================

<form action='".$siteurl.$nukeordner."/modules.php' method='get'>
  <div align=\'center\'>
    <input type='submit' name='Submit' value='registration'>
	<input type='hidden' value='new_user' name='op'>
  		<input type='hidden' value='Your_Account' name='name'>
</div>
</form>

=====================================

=====================================


Upload the file 'ENGLISH_poc.php' as "poc.php" into the phpnuke root directory



3) Insert the Link to the Chat into phpnuke

Goto to the administration menu and create a new block, visible to all or only members, 
what ever you want to ;) 


The Blockbody should be:

<a href=\"poc.php\"><img src=\"images/button_poc.gif\" alt=\"Visit Our Chat\" width=\"45\" height=\"22\" border=\"0\"></a>";

If a guest clicks the link, he will get displayed the predefined message (see above).




Some relevant properties of POC's 'config.inc.php':
Example 1: You want that only registered users of yabbse can access the chat.
Guests must register to be able to chat.

define('ALLOW_GUEST_LOGIN',false);
define('SEND_CONFIRMATION_MAIL', false);
define('AUTOLOGIN_DIRECTLY', true);

okay, users can login to the chat only if they are registered user of yabbse.

Beispiel 2: You want that
            - yabbse's registered users are able to chat,
            - users are able to register for the chat only
            - guests can access the chat without a yabbse membership.

define('ALLOW_GUEST_LOGIN',true);
define('SEND_CONFIRMATION_MAIL', true); //switch to false if you don't like registration mails.
define('AUTOLOGIN_DIRECTLY', false);

With this setup, the POC is successfully integrated into yabbse. 
Users are able to use the chat without registring to the yabbse forum.
Also guest-access is anabled.

For more informations see the support-forum at http://www.phpopenchat.de/

HTH
POC-Support-Team