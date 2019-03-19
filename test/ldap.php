<?php
$LDAP_NAME[0]           = "PIXELPARK";
$LDAP_SERVER[0]         = "ldap.pixelpark.com";
$LDAP_ROOT_DN[0]        = "o=pixelpark.com";

//If no server chosen set it to 0
if(!$SERVER_ID)
  $SERVER_ID=0;
  
//Create Query
$ldap_query = "cn=$common";

//Connect to LDAP
$connect_id = ldap_connect($LDAP_SERVER[$SERVER_ID]);

if($connect_id)
{
  //Authenticate
  $bind_id = ldap_bind($connect_id);
  
  //Perform Search
  $search_id = ldap_search($connect_id, $LDAP_ROOT_DN[$SERVER_ID], $ldap_query);
  
  //Assign Result Set to an Array
  $result_array = ldap_get_entries($connect_id, $search_id);
}
else
{
  //Echo Connection Error
  echo "Could not connect to LDAP server: $LDAP_SERVER[$SERVER_ID]";
}
  
//Sort results if search was successful
if($result_array)
{
    $result_list = $result_array[$i]["dn"];
}
else
{
  echo "Result set empty for query: $ldap_query";
}
  
//Close Connection
ldap_close($connect_id);

//Make Form
echo "<CENTER><FORM ACTION=\"$PHP_SELF\" METHOD=\"GET\">";
echo "Search in:<SELECT NAME=\"SERVER_ID\">";

//Loop Through and Create SELECT OPTIONs
for($i=0; $i<count($LDAP_NAME); $i++)
  echo "<OPTION VALUE=\"$i\">".$LDAP_NAME[$i]."</OPTION>";

echo "</SELECT><BR>";
echo "Search for:<INPUT TYPE=\"text\" NAME=\"common\" VALUE=\"*\">";
echo "<INPUT TYPE=\"submit\" NAME=\"lookup\" VALUE=\"go\"><BR>";
echo "(You can use * for wildcard searches, ex. * Stanley will find all Stanleys)<BR>";
echo "</FORM></CENTER>";

//Echo Results
if($result_list)
{
  echo "<CENTER><TABLE BORDER=\"1\" CELLSPACING=\"0\" CELLPADDING=\"10\" 
        BGCOLOR=\"#FFFFEA\" WIDTH=\"450\"><TR><TD>$result_list</TD></TR>
        </TABLE></CENTER>";
}
else
  echo "No Results";

?>