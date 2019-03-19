<?php
//test arrays as return values in functions
function get_lines() {
  $line[]="1. Zeile";
  $line[]="2. Zeile";
  $line[]="3. Zeile";

  return $line;
}
$since_line=1;
$cur_line=2;
$max_line=3;

$a = get_lines();
$i = $since_line;
while ($i <> $cur_line) {
  $i = ++$i % $max_line;
  print $a[$i];
  print "<br>\n";
}
?>
