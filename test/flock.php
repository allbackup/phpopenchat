<?php //-*- php -*-
// test of blocking versus non-blocking flock, fm
// create file handle for locking
$_fp = @fopen("flock_test","w");
$_locked = flock($_fp,LOCK_EX); //v Blocking
// $_locked = flock($_fp,LOCK_EX+LOCK_NB); // Non-Blocking
echo "locked<br>\n";
flush();
sleep(10);
$_unlocked = flock($_fp,LOCK_UN);
echo "unlocked<br>\n";
@fclose($_fp);
?>