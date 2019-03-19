<?php
// shared memory test

$channel="schulhof";
$channel_id=crc32($channel);
print dechex($channel_id);
print "<br>\n";
$shm_id = shm_attach($channel_id,10000,0600);
print "$shm_id attached<br>\n";
$i=1;
shm_put_var($shm_id,crc32("test_var_$i"),"test_data$i");
print "$shm_id put_var<br>\n";
$i++;
shm_put_var($shm_id,crc32("test_var_$i"),"test_data$i");
print "$shm_id put_var<br>\n";
$i=1;
$shm_var = shm_get_var($shm_id,crc32("test_var_$i"));
print "$shm_id get_var: $shm_var<br>\n";
$i++;
$shm_var = shm_get_var($shm_id,crc32("test_var_$i"));
print "$shm_id get_var: $shm_var<br>\n";
shm_remove($shm_id);
print "$shm_id removed<br>\n";
?>