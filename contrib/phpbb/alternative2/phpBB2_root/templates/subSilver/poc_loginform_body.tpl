<script language="JavaScript">
function redirection (raumwahl) {
document.f.redirect.value="poc_loginform.php?channel="+raumwahl;
}
</script>

	<!-- BEGIN notlogged_switch -->
<form action="login.php" name="f" method="POST" >	
	<!-- END notlogged_switch -->	
	<!-- BEGIN logged_switch -->
<form action="poc.php" name="f" method="POST" >	
	<!-- END logged_switch -->	


<input type="hidden" name="redirect" value="poc_loginform.php" >
<input type="hidden" name="login" value="Login" >


<table width="600" cellpadding="4" cellspacing="1" border="0" align="center" class="forumline">
		<tr>
	  <th class="thHead" colspan="2">{L_POC_TITLE}</th>
	</tr>
	<tr>
		<td class="row1">&nbsp;</td>
		<td class="row2">&nbsp;</td>
	</tr>
	<tr>
		<td class="row1">&nbsp;</td>
		<td class="row2">&nbsp;</td>
	</tr>
	<!-- BEGIN notlogged_switch -->
	<tr>
		<td class="row1"><span class="genmed">{L_USERNAME}:</span></td>
		<td class="row2"><input type="text" size="25" maxlength="100" name="username" /></td>
	</tr>
	<tr>
		<td class="row1"><span class="genmed">{L_PASSWORD}:</span></td>
		<td class="row2"><input type="text" size="25" maxlength="100" name="password" /></td>
	</tr>
	<tr>
		<td class="row1"><span class="genmed">{L_AUTO_LOGIN}:</span></td>
		<td class="row2"><span class="gen"> 
            <input type="checkbox" name="autologin" value="ON" /></span> </td>
	</tr>
	<!-- END notlogged_switch -->
	<!-- BEGIN logged_switch -->
	<tr>
		<td class="row1"><span class="genmed">{L_USERNAME}:</span></td>
		<td class="row2">{POC_USERNAME}</td>
	</tr>	
	<!-- END logged_switch -->
	<tr>
		<td class="row1"><span class="genmed">{L_POC_CHANNEL}:</span></td>
		<td class="row2">
		<select name='channel' onChange='redirection(this.form.channel.options[this.form.channel.options.selectedIndex].value);' >
        {POC_CHANNEL}
        </select>
        </td>
	</tr>
	<tr>
		<td class="row1">&nbsp;</td>
		<td class="row2">&nbsp;</td>
	</tr>

	<tr>
		<td class="row1">&nbsp;</td>
		<td class="row2"><input type="submit" name="submit" value="{L_SUBMIT}" class="mainoption" /></td>
	</tr>
</form>	
<form action="{POC_GUEST_ACTION}" name="g" method="post">
  <input type="hidden" name="nick" value="guest">
  <input type="hidden" name="account_data" value="Los">
	<tr>
		<td class="row1">&nbsp;</td>
		<td class="row2"><span class="genmed">{POC_GUEST}</span></td>
	</tr>
</form		
	<tr>
		<td class="catBottom" colspan="2" align="center">&nbsp;</td>
	</tr>
		<tr>
		<td class="catBottom" colspan="2" align="left"><span class="genmed"><b>{L_POC_USERSONLINE}</b></span></td>
	</tr>
			<tr>
		<td class="catBottom" colspan="2" align="left"><span class="genmed">{POC_SHOWUSERSONLINE}</span></td>
	</tr>
</table>
<br clear="all">