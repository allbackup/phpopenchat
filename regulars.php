<?php //-*-php-*-
/*   ********************************************************************   **
**   Copyright notice                                                       **
**                                                                          **
**   (c) 1995-2004 PHPOpenChat Development Team                             **
**   http://phpopenchat.sourceforge.net/                                    **
**                                                                          **
**   All rights reserved                                                    **
**                                                                          **
**   This script is part of the PHPOpenChat project. The PHPOpenChat        **
**   project is free software; you can redistribute it and/or modify        **
**   it under the terms of the GNU General Public License as published by   **
**   the Free Software Foundation; either version 2 of the License, or      **
**   (at your option) any later version.                                    **
**                                                                          **
**   The GNU General Public License can be found at                         **
**   http://www.gnu.org/copyleft/gpl.html.                                  **
**   A copy is found in the textfile GPL and important notices to the       **
**   license from the team is found in the textfile LICENSE distributed     **
**   with these scripts.                                                    **
**                                                                          **
**   This script is distributed in the hope that it will be useful,         **
**   but WITHOUT ANY WARRANTY; without even the implied warranty of         **
**   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          **
**   GNU General Public License for more details.                           **
**                                                                          **
**   This copyright notice MUST APPEAR in all copies of the script!         **
**   ********************************************************************   */

/*
  $Author: letreo $
  $Date: 2004/02/24 17:05:18 $
  $Source: /cvsroot/phpopenchat/chat3/regulars.php,v $
  $Revision: 1.11.2.4 $
*/

//Get default values
require_once('config.inc.php');

require_once(POC_INCLUDE_PATH.'/adodb/adodb.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Chat.inc');
require_once(POC_INCLUDE_PATH.'/class.Chatter.inc');
require_once(POC_INCLUDE_PATH.'/class.Translator.inc');
require_once(POC_INCLUDE_PATH.'/class.Template.inc');

session_start();

//check if chatter is authorized to get this page
if( !isset($_SESSION['chat']) )
{
  header('Status: 302');
  header('Location: index.php');
  exit;
}
if ( !isset($_SESSION['template']) )
{
	$template = &new POC_Template();
	$_SESSION['template'] = $template;
}

//if( count($_POST) < 1 )
//  $_SESSION['template']->get_cached_content( 60*60*24 );//get cached content with a max age of one day

function check_private_icon( $nick )
{
  global $ACCEPTED_MIME_TYPES;
  $smiley_dir  = '/images/icons/chatter';
  for ($i=0;$i<count($ACCEPTED_MIME_TYPES);$i++)
  {
    preg_match('#image/[x\-]?(.*)#',$ACCEPTED_MIME_TYPES[$i], $parts);
    $file_extension = $parts[1];
    $smiley_path = $smiley_dir.'/'.strtolower($nick).'.'.$file_extension;
    if( file_exists($_SESSION['template']->get_tmpl_sys_path().$smiley_path) )
      return '<img title="'.$_SESSION['translator']->out('PRIVATE_IMAGE').'" src="'.$_SESSION['template']->get_tmpl_web_path().$smiley_path.'" align="middle" alt="'.$_SESSION['translator']->out('PRIVATE_IMAGE').'" />';
  }
  
  return '&nbsp;';
}

function make_table_rows( $grade )

{
  if( count($grade) > 0 )
  {
    $opt_string = '';
    reset( $grade );

    do{
      $current = current( $grade );
      $opt_string .= TAB.'<tr>'.NL;
      $opt_string .= TAB.TAB.'<td width="'.PRIVATE_IMG_SIZE_X.'">'.NL;
      $opt_string .= check_private_icon( $current[0] );
      $opt_string .= TAB.TAB.'</td>'.NL;
      $opt_string .= TAB.TAB.'<td>&nbsp;'.NL;
      $opt_string .= '<a href="#" onclick="showUserPage(\''.$current[0].'\');return false" target="satUserPage">'.$current[0].'</a>';
      $opt_string .= TAB.TAB.'</td>'.NL;
      $opt_string .= TAB.TAB.'<td align="center">'.NL;
      $opt_string .= TAB.TAB.round($current[1],2).'</td>'.NL;
      $opt_string .= TAB.TAB.'<td align="center">'.NL;
      $opt_string .= TAB.TAB.round($current[2],2).'</td>'.NL;
      $opt_string .= TAB.TAB.'<td align="center">'.NL;
      $opt_string .= TAB.TAB.round($current[3]/(60*60),2).'</td>'.NL;
      $opt_string .= TAB.'</tr>'.NL;
    }while( next($grade) );
    return $opt_string;
  }
  else
    return '<tr><td /></tr>';
}
$TEMPLATE_OUT['search_results'] = array();
$TEMPLATE_OUT['search_results']['not_found'] = '';

if( isset($_POST['chatter']) ) {
    $_chatter = &new POC_Chatter(STATUS_BOT_NAME);
    $_chatter->set_nick($_POST['chatter']);
    if ( $_chatter->get_regTime() != '' ) {
        $rank = $_chatter->get_regulars_table_rank();
        $grade   = $_chatter->get_grade();
        $lines_per_day  = $_chatter->get_lines_per_day();
        $logins_per_day = $_chatter->get_logins_per_day();
        $online_time    = round($_chatter->get_online_time()/(60*60),2);
        $TEMPLATE_OUT['search_results'] = array();
        $TEMPLATE_OUT['search_results']['chatter'] = $_POST['chatter'];
        $TEMPLATE_OUT['search_results']['rank'] = $rank;
        $TEMPLATE_OUT['search_results']['grade'] = $_SESSION['translator']->out($grade);
        $TEMPLATE_OUT['search_results']['lines_per_day'] = $lines_per_day;
        $TEMPLATE_OUT['search_results']['logins_per_day'] = $logins_per_day;
        $TEMPLATE_OUT['search_results']['online_time'] = $online_time;
    } else {
        $TEMPLATE_OUT['search_results']['not_found'] = '<strong>'.$_POST['chatter'].'</strong> '.$_SESSION['translator']->out('NOT_FOUND');
    }
}

$_SESSION['chat']->connect();
 $elite    = $_SESSION['chat']->get_best_chatter('GRADE_ELITE',20);
 $regulars = $_SESSION['chat']->get_best_chatter('GRADE_REGULAR',20);
 $members  = $_SESSION['chat']->get_best_chatter('GRADE_MEMBER',20);
 $rookies  = $_SESSION['chat']->get_best_chatter('GRADE_ROOKIE',20);
$_SESSION['chat']->disconnect();

$TEMPLATE_OUT['elite_table_rows']   = make_table_rows( $elite );
$TEMPLATE_OUT['regular_table_rows'] = make_table_rows( $regulars );
$TEMPLATE_OUT['member_table_rows']  = make_table_rows( $members );
$TEMPLATE_OUT['rookie_table_rows']  = make_table_rows( $rookies );

$TEMPLATE_OUT['min_lines_per_day_elite']  = $GRADES['GRADE_ELITE'][0];
$TEMPLATE_OUT['min_logins_per_day_elite'] = $GRADES['GRADE_ELITE'][1];
$TEMPLATE_OUT['min_online_time_elite']    = $GRADES['GRADE_ELITE'][2];

$TEMPLATE_OUT['min_lines_per_day_regular']  = $GRADES['GRADE_REGULAR'][0];
$TEMPLATE_OUT['min_logins_per_day_regular'] = $GRADES['GRADE_REGULAR'][1];
$TEMPLATE_OUT['min_online_time_regular']    = $GRADES['GRADE_REGULAR'][2];

$TEMPLATE_OUT['min_lines_per_day_member']  = $GRADES['GRADE_MEMBER'][0];
$TEMPLATE_OUT['min_logins_per_day_member'] = $GRADES['GRADE_MEMBER'][1];
$TEMPLATE_OUT['min_online_time_member']    = $GRADES['GRADE_MEMBER'][2];

header('Content-type: text/html; charset='.$_SESSION['translator']->out('CHARACTER_ENCODING'));
$_SESSION['template']->get_template('regulars');
?>