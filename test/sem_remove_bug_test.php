<?php
// semaphore remove bug in standalone php only
// reported on 18.3.2002 as #16144
$channel="schulhof";
$channel_id=crc32($channel);
print dechex($channel_id);
print "<br>\n";
$sem_id = sem_get($channel_id,1,0600);
print "$sem_id got<br>\n";
sem_acquire($sem_id);
print "$sem_id acquired<br>\n";
sem_release($sem_id);
print "$sem_id released<br>\n";
sem_remove($sem_id);
print "$sem_id removed<br>\n";
//request cleanup dumps core if semaphore is removed
?>