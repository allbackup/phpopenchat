<?php // -*-PHP-*-
/** channel line buffer using shared memory
 *
 * a channel line buffer implementation using shared memory
 * instead of a mysql table used by all apache php daemons
 * shared memory is only available on Unix systems so this
 * won't work on Windows.
 *
 * @module channel buffer access
 * @author frerk frerk@meychern.de
 * @bugs semaphores can not be deleted due to a php bug, freaks out if channel name is empty, sem_ needs variable_key which is int
 * @todo catch empty channel name, refactor to OO implementation
 */

$channel = "schulhof";
$debug=TRUE;
// shared memory stores variables only under integer keys
define("CB_MAX_LINE_IDX",0); //channel buffer maximum line number shm index
define("CB_CUR_LINE_IDX",1); //channel buffer current line number shm index
define("CB_LINE_OFFSET",2);  //channel buffer line array index offset
define("CB_LINE_MEMORY",1024); //channel buffer shared memory per line in bytes

// lock channel buffer access
// create semaphore is necessary
function lock_channel_buffer($channel_id) {
  // only 1 at a time and read/write for owner only
  if (!($sem_id = sem_get($channel_id,1,0600))) die ("can't get semaphore id");
  if (!sem_acquire($sem_id)) die ("can't aquire semaphore");
  return $sem_id;
}

// unlock channel buffer access
function unlock_channel_buffer($sem_id) {
  if (!sem_release($sem_id)) die ("can't release semaphore");
}

function remove_channel_buffer_lock($sem_id) {
  if (!sem_remove($sem_id)) die ("can't remove semaphore");
}

// initialize channel buffer in shared memory
function init_channel_buffer($channel,$max_line){
  $channel_id=crc32($channel);
  $sem_id=lock_channel_buffer($channel_id);
  // read and write channel memory
  if (!($shm_id = shm_attach($channel_id,CB_LINE_MEMORY*$max_line,0600))) die ("can't attach to channel memory");
  if (!shm_put_var($shm_id,CB_MAX_LINE_IDX,$max_line)) die ("can't write max_line to channel memory");
  if (!shm_put_var($shm_id,CB_CUR_LINE_IDX,0)) die ("can't write cur_line to channel memory");
  for ($i=0; $i<$max_line; $i++) {
    if (!shm_put_var($shm_id,$i+CB_LINE_OFFSET,"$i")) die ("can't write line $i to channel memory");
  }
  // detach from channel memory and preserve data for other processes
  if (!shm_detach($shm_id)) die ("can't detach from channel memory");
  unlock_channel_buffer($sem_id);
  return TRUE;
}

// read current line from channel buffer
function read_channel_buffer_line($channel) {
  $line = "";
  $channel_id = crc32($channel);
  $sem_id = lock_channel_buffer($channel_id);
  // read channel buffer
  if (!($shm_id = shm_attach($channel_id))) die ("can't attach channel memory");
  $i = shm_get_var($shm_id,CB_CUR_LINE_IDX);
  $line = shm_get_var($shm_id,$i+CB_LINE_OFFSET);

  // detach from channel memory and leave data
  if (!shm_detach($shm_id)) die ("can't detach from channel memory");  
  unlock_channel_buffer($sem_id);

  return $line;
}

// read all lines since line number
function read_channel_buffer_since($channel,$since_line) {
  $channel_id = crc32($channel);
  $sem_id = lock_channel_buffer($channel_id);
  // read channel buffer
  if (!($shm_id = shm_attach($channel_id))) die ("can't attach channel memory");
  $max_line = shm_get_var($shm_id,CB_MAX_LINE_IDX);
  $cur_line = shm_get_var($shm_id,CB_CUR_LINE_IDX);
  // read all lines from since to current with wrap around
  $i = $since_line;
  while ($i <> $cur_line) {
    $i = ++$i % $max_line;
    $lines[] = shm_get_var($shm_id,$i+CB_LINE_OFFSET);
  }
  // if array $lines[] is empty, nothing was written in since last time

  // detach from channel memory and leave data
  if (!shm_detach($shm_id)) die ("can't detach from channel memory");  
  unlock_channel_buffer($sem_id);

  return $lines; // array of strings, may be empty
}

// write line into channel buffer and make it the current line
function write_channel_buffer($channel,$line) {
  $channel_id=crc32($channel);
  $sem_id = lock_channel_buffer($channel_id);
  // read then write channel buffer
  if (!($shm_id = shm_attach($channel_id))) die ("can't attach channel memory");
  $cur_line = shm_get_var($shm_id,CB_CUR_LINE_IDX);
  $max_line = shm_get_var($shm_id,CB_MAX_LINE_IDX);
  $i = ++$cur_line % $max_line; //circular buffer index division modulus
  shm_put_var($shm_id,$i+CB_LINE_OFFSET,$line);
  shm_put_var($shm_id,CB_CUR_LINE_IDX,$i);
  
  // detach from channel memory and leave data
  if (!shm_detach($shm_id)) die ("can't detach channel memory");
  
  unlock_channel_buffer($sem_id);
  
  return $i; //current line
}

// remove channel buffer and lock from shared memory and semaphores
function remove_channel_buffer($channel){
  $channel_id=crc32($channel);
  $sem_id=lock_channel_buffer($channel_id);
  if (!($shm_id = shm_attach($channel_id))) die ("can't attach channel memory");
  // remove channel memory and destroy data
  if (!shm_remove($shm_id)) die ("can't remove channel memory");
  unlock_channel_buffer($sem_id);
  remove_channel_buffer_lock($sem_id); //dumps core in standalone php!?
  return TRUE;
}

function test_buffer($channel) {
  global $debug;
  $cur_line = 0;
  $nl="<br>\n";

  if ($debug) system ("ipcs -s | wc -l; ipcs -m |wc -l");
  init_channel_buffer($channel,3); // channel with 3 lines for testing ring
  if ($debug) print "Channel_id: 0x".dechex(crc32($channel)).$nl;
  if ($debug) print "$channel buffer initialized$nl";
  write_channel_buffer($channel,"Zeile 1");
  if ($debug) print "$channel buffer written$nl";
  $cur_line = write_channel_buffer($channel,"Zeile 2");
  write_channel_buffer($channel,"Zeile 3");
  write_channel_buffer($channel,"Zeile 4"); // has to be wrapped around
  $line = read_channel_buffer_line($channel);
  if ($debug) print "$channel buffer read current line: $line $nl";
  $lines = read_channel_buffer_since($channel,$cur_line);
  foreach ($lines as $l) {
    if ($debug) print "$channel buffer read since line: $l $nl";
  }
  remove_channel_buffer($channel);
  if ($debug) print "$channel buffer removed$nl";
  if ($debug) system ("ipcs -s | wc -l; ipcs -m | wc -l;");
  return TRUE;
}

test_buffer($channel);

?>
