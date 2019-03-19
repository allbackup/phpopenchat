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

// Class Channel_Buffer based on Shared Memory (Unix only)

//Get default values
require_once(POC_BASE.'/config.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Logger.inc');

// TODO: move remove_lock() to disconnect()
// TODO: get_cur_idx() should read shared memory?
// shared memory stores variables only under integer keys
// therefore we need some constants

define("CB_INIT_FLAG",0); // channel buffer init flag
define("CB_MAX_LINE_IDX",1); // channel buffer maximum line number shm index
define("CB_CUR_LINE_IDX",2); // channel buffer current line number shm index
define("CB_LINE_OFFSET",3);  // channel buffer line array index offset
// CB_LINE_MEMORY = strlen(serialize($maximum_length_line_object))
define("CB_LINE_MEMORY",2048); // channel buffer shared memory per line in bytes

/**
 * Channel buffer based on shared memory
 *
 * @author Frerk Meyer <frerk@sourceforge.net>
 * @access public
 * @version $Id: class.Channel_Buffer_Mem.inc,v 1.23.2.4 2004/03/02 21:05:17 letreo Exp $
 */

class POC_Channel_Buffer {

  /**
   * channel name
   *
   * @var    string
   * @access public
   * @see    Channel_Buffer()
   */
  var $channel;
  
  /**
   * channel id 32-bit based on channel name
   * needed for shared memory and semaphores
   *
   * @var    string
   * @access private
   * @see    Channel_Buffer()
   */
  var $channel_id;

  /**
   * Semaphore Id for channel buffer locking
   * 
   * @var    int
   * @access private
   * @see    Channel_Buffer()
   * @see    lock()
   * @see    unlock()
   */
  var $sem_id;

  /**
   * Shared memory Id for channel buffer storage
   *
   * @var    int
   * @access private
   * @see    Channel_Buffer()
   */
  var $shm_id;

  /**
   * Maximum line index of channel buffer
   *
   * @var    int
   * @access private
   * @see    Channel_Buffer()
   */
  var $max_line_idx;

  /**
   * Current line index of channel buffer
   *
   * @var    int
   * @access private
   * @see    Channel_Buffer()
   */
  var $cur_line_idx;

  var $locked;

  var $connected;

  /**
  * Constructor
  *
  * create a new channel buffer object with name 'channel'
  *
  * @param  string $channel
  * @access public
  */
  function POC_Channel_Buffer ($channel) {
    $this->channel = $channel;
    $this->channel_id = crc32($channel);
    $this->max_line_idx = CB_MAX_LINE;
    $this->cur_line_idx = 0;
    $this->sem_id = 0;
    $this->shm_id = 0;
    $this->locked = 0;
    $this->connected = 0;
  }

  /**
  * Get maximum line index
  *
  * @access public
  * @return int max_line_idx
  */
  function get_max_line_idx() {
    if (!$this->connected) $this->connect();
    $this->lock();
    $this->cur_line_idx = shm_get_var($this->shm_id,CB_CUR_LINE_IDX);    
    return $this->max_line_idx;
    $this->unlock();
  }

  /**
  * Get current line index
  *
  * @access public
  * @return int cur_line_idx
  */
  function get_cur_line_idx() {
    if (!$this->connected) $this->connect();
    $this->lock();
    $this->cur_line_idx = shm_get_var($this->shm_id,CB_CUR_LINE_IDX);
    return $this->cur_line_idx;
    $this->unlock();
  }

  /**
  * Get channel name
  *
  * @access public
  * @return string channel
  */
  function get_name() {
    return $this->channel;
  }

  /**
   * Lock access to shared memory with a semaphore
   *
   * Semaphore is created by connect()
   *
   * @access private
   * @return int semaphore id
   * @see    connect()
   */
  function lock() {
    if (!$this->locked) { // lock only if unlocked
      // lock for only one process and read/write for owner only
      if (!sem_acquire($this->sem_id)) die ("can't aquire channel buffer semaphore");
      $this->locked = true;
    }
    return true;
  }

  /**
   * Unlock access to shared memory with a semaphore
   *
   * To remove sempahore use remove_lock()
   *
   * @access private
   * @return int semaphore id
   * @see    remove_lock()
   */
  function unlock() {
    if ($this->locked) { // unlock only if locked
      if (!sem_release($this->sem_id)) die ("can't release channel buffer semaphore");
      $this->locked = false; // status unlocked
    }
    return true;
  }

  /**
   * Remove lock semaphore
   * TODO: Test if really needed and working, fm
   * @access private
   * @return int semaphore id
   */
  function remove_lock() {
    if (!$this->sem_id) {
      if (!sem_remove($this->sem_id)) die ("can't remove semaphore");
      $this->sem_id = 0;
    }
    return true;
  }

  /**
  * Connect to the shared memory segment
  *
  * Create semaphore and shared memory segment if non-existant
  * Init if created
  *
  * @param string
  * @access public
  */
  function connect() {  // connect and init
    // get semaphore id, create one if none exists
    if (!($this->sem_id = sem_get($this->channel_id,1,0600))) die ("can't get semaphore id");
    // get shared mem id, create one if none exists
    if (!($this->shm_id = shm_attach($this->channel_id,CB_LINE_MEMORY*$this->max_line_idx,0600)))
      die ("can't attach to channel buffer shared memory");
    if (!$this->connected)
    { // shm already attached?
      $this->connected=true;
      $this->lock();
      if (!@shm_remove_var($this->shm_id,CB_INIT_FLAG))
      { // init if created
        shm_put_var($this->shm_id,CB_INIT_FLAG,1);
        shm_put_var($this->shm_id,CB_MAX_LINE_IDX,$this->max_line_idx);
        shm_put_var($this->shm_id,CB_CUR_LINE_IDX,$this->cur_line_idx);
        for ($i=0; $i<$this->max_line_idx; $i++)
        {
          if (!shm_put_var($this->shm_id,$i+CB_LINE_OFFSET,"$i"))
            die ("can't write line $i to channel memory");
        }
        // TODO else get values from channel!!!
        $this->max_line_idx = shm_get_var($this->shm_id,CB_MAX_LINE_IDX);
        $this->cur_line_idx = shm_get_var($this->shm_id,CB_CUR_LINE_IDX);
      }
      else
        shm_put_var($this->shm_id,CB_INIT_FLAG,1);
      
      $this->unlock();
    }
    return true;
  }

  function disconnect() {
    if ($this->connected) {
      $this->lock();
      
      
      // detach from channel memory and preserve data for other processes
      if (!shm_detach($this->shm_id)) die ("can't detach from channel buffer shared memory");
      $this->connected=false;
      $this->unlock();
    }
  }


  // initialize the channel buffer shared memory
  // creating a new one if necessary and
  // overwriting an existing one

  function init() {    
    return true; // TODO: delete init() calls in main
    // get shared mem id, create one if none exists
    if (!($this->shm_id = shm_attach($this->channel_id,CB_LINE_MEMORY*$this->max_line_idx,0600))) die ("can't attach to channel buffer shared memory");
    shm_put_var($this->shm_id,CB_INIT_FLAG,1);
    shm_put_var($this->shm_id,CB_MAX_LINE_IDX,$this->max_line_idx);
    shm_put_var($this->shm_id,CB_CUR_LINE_IDX,$this->cur_line_idx);
    for ($i=0; $i<$this->max_line_idx; $i++) {
      if (!shm_put_var($this->shm_id,$i+CB_LINE_OFFSET,"$i")) die ("can't write line $i to channel memory");
    }
    return true;
  }

  /**
  * Cleans up the channel buffer in database.
  *
  * @access public
  */
  function mkclean()
  {
    return;
  }
  
  function destroy() {
    $this->lock();
    // remove channel memory and destroy data
      if (!($this->shm_id = shm_attach($this->channel_id))) die ("can't attach to channel buffer shared memory");
      if (!shm_remove($this->shm_id)) die ("can't remove channel buffer shared memory");
    $this->unlock();
  }

  /**
  * Get current chat line object
  *
  * @access public
  * @return object Line
  */
  function get_cur_line() {
    $this->lock();
    // get current line
    $this->cur_line_idx = shm_get_var($this->shm_id,CB_CUR_LINE_IDX);
    $cur_line = shm_get_var($this->shm_id,$this->cur_line_idx+CB_LINE_OFFSET);
    $this->unlock();
    return $cur_line;
  }

  /**
  * Get all chat lines since given index
  *
  * Idea is get all lines that were written by others
  * since the last line you have written
  *
  * @param int $since_idx
  * @access public
  * @return array of instances of class Chat_Line
  */
  function get_lines_since($since_idx) {

    $i = 0;

    $this->lock();
    // get max and current line index
    $this->max_line_idx = shm_get_var($this->shm_id,CB_MAX_LINE_IDX);
    $this->cur_line_idx = shm_get_var($this->shm_id,CB_CUR_LINE_IDX);
    
    if (($since_idx < 0) || ($since_idx >= $this->max_line_idx))
      $_SESSION['logger']->error('Line index '.$line_idx.' out of bounds exception',__FILE__,__LINE__);
    // read all lines from since to current
    $i = $since_idx;
    $lines = array();
    while ($i <> $this->cur_line_idx) {
      $i = ++$i % $this->max_line_idx;  // modulo calculation for wrap around
      $lines[] = shm_get_var($this->shm_id,$i+CB_LINE_OFFSET);
    }
    // if array $lines[] is empty, nothing was put into buffer since last time
    $this->unlock();
    return $lines;
  }
  
  /**
  * Provides all lines within the buffer
  *
  * @param int $since_idx
  * @access public
  * @return array of instances of class Chat_Line
  */
  function get_all_lines_in_buffer()
  {
    // get max and current line index
    $max_line_idx = $this->get_max_line_idx();
    $cur_line_idx = $this->get_cur_line_idx();
    $since_idx = ++$cur_line_idx % $max_line_idx;
    
    return $this->get_lines_since($since_idx);
  }

  function put_line($line) {
    /*
    if( is_object($_SESSION['logger']) )
    {
      print_r($line);exit;
      $sender = $line->get_sender();
      //$recipient = $line->get_recipient()
      $_SESSION['logger']->line($sender->get_nick().': '.$line->get_said());
    }
    */
    $this->lock();
    // put line as current into channel buffer
    $this->cur_line_idx = shm_get_var($this->shm_id,CB_CUR_LINE_IDX);
    $this->max_line = shm_get_var($this->shm_id,CB_MAX_LINE_IDX);
    $this->cur_line_idx = ++$this->cur_line_idx % $this->max_line_idx;
    shm_put_var($this->shm_id,$this->cur_line_idx+CB_LINE_OFFSET,$line);
    shm_put_var($this->shm_id,CB_CUR_LINE_IDX,$this->cur_line_idx);
    $this->unlock();
    return $this->cur_line_idx; // return index of current line
  }

  /**
   * test method for class Channel_Buffer
   *
   * call like: POC_Channel_Buffer::test();
   * initialize 2 channel buffers, write some lines
   * read them, disconnect and reconnect,
   * and verify the lines again
   * test function must work identical in Mem and DB version
  **/
  function test() {
    $nl="<br>\n";
    // create 2 new channel buffers
    $cb1 = new POC_Channel_Buffer("schulhof");
    $cb2 = new POC_Channel_Buffer("lehrerzimmer");
    // connect (and create if non existent)
    $cb1->connect();
    $cb2->connect();
    // fill with test lines in mixed order
    $cb1_idx = $cb1->put_line("1:1");
    $cb1->put_line("1:2");
    $cb2->put_line("2:1");
    $cb2_idx = $cb2->put_line("2:2");
    $cb1->put_line("1:3");
    $cb2->put_line("2:3");
    // get test lines and print them
    // first channel buffer
    // expect "1:2","1:3"
    $lines = $cb1->get_lines_since($cb1_idx);
    foreach ($lines as $l) {
      print $cb1->get_name().": $l $nl";
    }
    // second channel buffer
    // expect "2:3"
    $lines = $cb2->get_lines_since($cb2_idx);
    foreach ($lines as $l) {
      print $cb2->get_name().": $l $nl";
    }
    // disconnect from channel buffer, don't remove them
    $cb1->disconnect();
    $cb2->disconnect();
    unset($cb1);
    unset($cb1_idx);
    unset($cb2);
    unset($cb2_idx);
    // reconnect to channel buffers
    $cb1 = new POC_Channel_Buffer("schulhof");
    $cb2 = new POC_Channel_Buffer("lehrerzimmer");
    $cb1->connect();
    $cb2->connect();
    // write some extra lines
    $cb1_idx = $cb1->get_cur_line_idx();
    $cb2_idx = $cb2->get_cur_line_idx();
    $cb1->put_line("1:4");
    $cb2->put_line("2:4");
    // get test lines and print them
    // first channel buffer
    // expect "1:4"
    $lines = $cb1->get_lines_since($cb1_idx);
    foreach ($lines as $l) {
      print $cb1->get_name().": $l $nl";
    }
    // second channel buffer
    // expect "2:4"
    $lines = $cb2->get_lines_since($cb2_idx);
    foreach ($lines as $l) {
      print $cb2->get_name().": $l $nl";
    }
    // destroy channel buffers (channel is removed)
    $cb1->destroy();
    $cb2->destroy();
  }
}
?>