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

/**
* Get default values
*/
require_once(POC_BASE.'/config.inc.php');
require_once(POC_INCLUDE_PATH.'/class.Line.inc');
require_once(POC_INCLUDE_PATH.'/class.Logger.inc');

/**
* channel buffer current line number shm index
*/
define('CB_CUR_LINE',1);

/**
* channel buffer maximum tries to lock
*/
define('CB_MAX_LOCK_TRIES',10);

/**
* Channel buffer based on a database
*
* @author  Michael Oertel <michael@ortelius.de>
* @access  public
* @version $Id: class.Channel_Buffer_DB.inc,v 1.46.2.8 2004/03/03 21:31:05 letreo Exp $
*/
class POC_Channel_Buffer {

  /**
  * @var    string
  * @access public
  * @see    POC_Channel_Buffer()
  */
  var $channel;

  /**
  * @var    int
  * @access public
  * @see    Channel_Buffer()
  * @see    get_lines_since()
  */
  var $max_line_idx;

  /**
  * @var    int
  * @access public
  * @see    Channel_Buffer()
  * @see    get_lines_since()
  */
  var $cur_line_idx;

  /**
  * @var    object
  * @access private
  * @see    connect()
  */
  var $db;

  /**
  * @var    dbRecordSet
  * @access private
  * @see    connect()
  */
  var $rs_line_buffer;

  /**
  * @var    dbRecordSet
  * @access private
  * @see    connect()
  */
  var $rs_channels;

  /**
  * @var    integer
  * @see    connect()
  * @see    disconnect()
  */
  var $connection_count = 0;

  /**
  * @var    file pointer
  * @access private
  * @see    lock()
  * @see    unlock()
  */
  var $_fp = null;
  
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
  var $locked = false;

  /**
  * Constructor.
  *
  * create a new channel buffer object with name 'channel'
  *
  * @param  string channel name
  * @access public
  */
  function POC_Channel_Buffer ($channel)
  {
    $this->channel      = $channel;
    $this->max_line_idx = CB_MAX_LINE;
    $this->cur_line_idx = 0;
    $this->channel_id   = crc32($channel);
    $this->init();
  }

  /**
  * Get var max_line_idx.
  *
  * @access public
  * @return int $max_line_idx of buffer
  */
  function get_max_line_idx()
  {
    //get current line index from database
    $rs = $this->db->Execute( 'SELECT max_line_number FROM '.DATABASE_TABLE_PREFIX.'channels WHERE NAME=\''.$this->channel.'\'' );

    return $rs->fields[ 0 ];
  }

  /**
  * Set var max_line_idx.
  *
  * It is only a dummy. To change the size of the line buffer,
  * simply add another column like 'line_27'
  *
  * @access public
  * @param  int $max_line_idx
  */
  function set_max_line_idx( $max_line_idx )
  {
    //check if the required fields in database exist
    $rs = $this->db->Execute( 'SELECT LINE_'.( $max_line_idx - 1 ).' FROM '.DATABASE_TABLE_PREFIX.'channels WHERE NAME=\''.$this->channel.'\'' );
    if ( !$rs )
      die ('POC: The required fields does not exists in database!');

    $record = array();
    $record[ 'MAX_LINE_NUMBER' ] = $max_line_idx;
    $update_sql = $this->db->GetUpdateSQL( $this->rs_channels, $record );

    //Insert the records into the database
    if ( !$this->db->Execute( $update_sql ) )
      die ( 'POC: Can\'t write into table \''.$this->channel.'\'' );

    unset($record);
    unset($update_sql);

    return true;
  }

  /**
  * Get var cur_line_idx.
  *
  * @access public
  */
  function get_cur_line_idx()
  {
    //get current line index from database
    $rs = $this->db->Execute( 'SELECT cur_line_number FROM '.DATABASE_TABLE_PREFIX.'channels WHERE NAME=\''.$this->channel.'\'' );
    $cur_line = $rs->fields[ 0 ];

    return $cur_line;
  }

  /**
  * Get channel name.
  *
  * @access public
  */
  function get_name()
  {
    return $this->channel;
  }

  /**
  * Get content of current chat line.
  *
  * @access public
  */
  function get_cur_line()
  {
    $this->lock();

    //get current line content from database
    $rs = $this->db->Execute( 'SELECT LINE_'.$this->get_cur_line_idx().' FROM '.DATABASE_TABLE_PREFIX.'line_buffer WHERE NAME=\''.$this->channel.'\'' );

    $this->unlock();

    return unserialize($rs->fields[ 0 ]);
  }

  /**
  * Initialize the channel buffer in database.
  *
  * @access public
  */
  function init()
  {
    $this->connect();
    $this->lock();
    //check if channel buffer exists
    $rs = $this->db->Execute( 'SELECT * FROM '.DATABASE_TABLE_PREFIX.'line_buffer WHERE NAME=\''.$this->channel.'\'' );
    if ($rs->RecordCount() <= 0)
    {
      $sql  = 'INSERT INTO '.DATABASE_TABLE_PREFIX.'line_buffer (NAME)';
      $sql .= "VALUES ('".$this->channel."')";
       
      //Insert the records into the database
      if ( !$this->db->Execute( $sql ) )
        die ( 'POC: Can\'t write channel.' );
      unset( $sql );
    }
    $rs->Close();
    $this->unlock();
    $this->disconnect();
  }

  /**
  * Cleans up the channel buffer in database.
  *
  * @access public
  */
  function mkclean()
  {
    $this->connect();
    $this->lock();
    //check if channel buffer exists
    $record = array();
    $tmp    = '';
    for ($i=0; $i<=CB_MAX_LINE-1; $i++){
      $record['LINE_'.$i] = 'null';
      $tmp .= 'LINE_'.$i.',';
    }
    $tmp = substr($tmp,0,-1);
    $rs = $this->db->Execute( 'SELECT '.$tmp.' FROM '.DATABASE_TABLE_PREFIX.'line_buffer WHERE NAME=\''.$this->channel.'\'' );print_r($rs);
    unset($tmp);
    
    $update_sql = $this->db->GetUpdateSQL( $rs, $record );
    if ( !$this->db->Execute( $update_sql ) )
      die ( 'POC: Can\'t clean-up channel buffer.' );

    $rs->Close();
    $this->unlock();
    $this->disconnect();
  }

  /**
  * Set a lock to block all other threads.
  *
  * Creates and sets a lock on a dummy file
  * to perform a simple reader/writer model
  *
  * @access public
  * @see unlock()
  */
  function lock()
  {
    if(!$this->sem_id)
    {
      //try to open a file
      //if no file exists, fopen() tries to create a file with the name of the channel.
      if( POC_OS == 'win' )
        $lock_path = str_replace( '/', '\\',TMPDIR.'/poc_'.$this->channel.'_lockfile');
      else
        $lock_path = TMPDIR.'/poc_'.$this->channel.'_lockfile';
        
      $this->_fp = @fopen( $lock_path, 'w' );
      if ( !$this->_fp )
      {
        header('Status: 301');
        header('Location: test.php?error='.urlencode('Can\'t create or write file \''.$lock_path.'\'. May the webserver has no permissions to create or write files in \''.$lock_path.'\'.<br>If you have enabled <em>safe_mode</em>, or <em>open_basedir</em> further restrictions may apply.'));
        exit;
      }
  
      $i = 0;
      while ( !flock( $this->_fp,LOCK_EX ) )
      {
        //The thread waits until the other unlocks the file.
        //so, this loop is not needed in ordinary cases, but who knows.
  
        //Lock could not be acquired
        sleep( 1 );
  
        //Count the number of tries
        $i++;
        if ( $i >= CB_MAX_LOCK_TRIES ) die ( 'POC: Can\'t get lock, giving up.' );
      }

      return true;
    }
    else
    {
      if (!$this->locked) { // lock only if unlocked
        // lock for only one process and read/write for owner only
        if (!sem_acquire($this->sem_id)) die ("can't aquire channel buffer semaphore");
        $this->locked = true;
      }
      return true;
    }
  }

  /**
  * Unlock the dummy file.
  *
  * @access public
  * @see lock()
  */
  function unlock()
  {
    if(!$this->sem_id)
    {
      if( !flock( $this->_fp,LOCK_UN ) ) die ( 'POC: Can\'t unlock lock-file' );
  
      return true;
    }
    else
    {
      if ($this->locked) { // unlock only if locked
        if (!sem_release($this->sem_id)) die ("can't release channel buffer semaphore");
        $this->locked = false; // status unlocked
      }
      return true;
    }
  }

  /**
  * Destroys the channel buffer in database.
  *
  * @access public
  * @see init()
  */
  function destroy()
  {
    if( !unlink ( $this->channel ) ) die ( 'POC: Can\'t delete lock-file' );

    //delete line buffer for the channel
    $rs = $this->db->Execute( 'DELETE FROM '.DATABASE_TABLE_PREFIX.'line_buffer WHERE NAME = \''.$this->channel.'\'' );
    if ( !$rs )
      die ( 'POC: Can\'t destroy line buffer for channel \''.$this->channel.'\'!' );

  }

  /**
  * Connect to the database
  *
  * Establish a database connection
  *
  * @access public
  */
  function connect()
  {
    // get semaphore id, create one if none exists
    //$this->sem_id = sem_get($this->channel_id,1,0600);
    $this->sem_id = false;
    
    if( ++$this->connection_count > 1 )
      return null;

    //create a database object
    $this->db = &NewADOConnection( DATABASE_DRIVER );
    if( USE_PCONNECT )
      $this->db->PConnect( DATABASE_HOST, DATABASE_USER, DATABASE_PASSWORD, DATABASE_TABLESPACE );
    else
      $this->db->Connect( DATABASE_HOST, DATABASE_USER, DATABASE_PASSWORD, DATABASE_TABLESPACE );

    $this->rs_channels = $this->db->Execute( 'SELECT * FROM '.DATABASE_TABLE_PREFIX.'channels WHERE NAME = NULL' );
    //$this->rs_line_buffer = $this->db->Execute( 'SELECT * FROM '.DATABASE_TABLE_PREFIX.'line_buffer WHERE NAME = NULL' );

    return true;
  }

  /**
  * Disconnect the database
  *
  * @access public
  * @see connect()
  */
  function disconnect()
  {
    if( --$this->connection_count == 0 )
    {
      $this->db->Close();
      return true;
    }
    
    return null;
  }


  /**
  * Get all chat lines since given index
  *
  * Idea is get all lines that were written by others
  * since the last line you have written
  *
  * @param integer $since_idx
  * @access public
  * @return array of instances of class Chat_Line
  */
  function get_lines_since( $since_idx )
  {
    if( $this->connection_count == 0 )
      die ( 'POC: Not connected!' );

    $i = 0;
    $rs = null;
    $all_lines  = array();
    $lines      = array();

    $this->lock();

    // get max and current line index
    $max_line_idx = $this->get_max_line_idx();
    $cur_line_idx = $this->get_cur_line_idx();

    if ( ( $since_idx < 0 ) || ( $since_idx >= $max_line_idx ) )
      die ( 'POC: Line index ('.$max_line_idx.') out of bounds exception' );

    //if there no new lines, return null
    if ( $since_idx == $cur_line_idx)
      return false;

    // read all lines
    $rs = $this->db->Execute( 'SELECT * FROM '.DATABASE_TABLE_PREFIX.'line_buffer WHERE NAME = \''.$this->channel.'\'' );

    $since_idx = ++$since_idx % $max_line_idx;
    do {
      if( !is_null($rs->fields[ ($since_idx+1) ]) )
        $lines[] = unserialize($rs->fields[ ($since_idx+1) ]);
      $since_idx = ++$since_idx % $max_line_idx;
    }while ( $since_idx != (($cur_line_idx+1) % $max_line_idx) );
    
    $this->unlock();
    return $lines;
  }
  

  /**
  * Get all chat lines in the buffer
  *
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
  
  /**
  * Writes chat lines into the buffer
  *
  * @param object
  * @access public
  */
  function put_line( $line )
  {
    if( $this->connection_count == 0 )
      die ( 'POC: Not connected! use connect() first.' );

    if(!is_object($line)) die('Object expected');
    $this->lock();
    $cur_line_idx = $this->get_cur_line_idx();
    $max_line_idx = $this->get_max_line_idx();
    //calculate new line index
    $cur_line_idx = ++$cur_line_idx % $max_line_idx;

    //Initialize an array to hold the record data to insert and get the insert sql-statement
    $record = array();
    $record[ 'LINE_'.$cur_line_idx ] = serialize($line);
    //Execute a query to select the recordset
    $rs = $this->db->Execute( 'SELECT LINE_'.$cur_line_idx.' FROM '.DATABASE_TABLE_PREFIX.'line_buffer WHERE NAME = \''.$this->channel.'\'' );
    $update_sql_line = $this->db->GetUpdateSQL( $rs, $record, true );
    unset($rs);
    unset($record);

    $record = array();
    $record[ 'CUR_LINE_NUMBER' ] = $cur_line_idx;
    //Execute a query to select the recordset
    $rs = $this->db->Execute( 'SELECT CUR_LINE_NUMBER FROM '.DATABASE_TABLE_PREFIX.'channels WHERE NAME = \''.$this->channel.'\'' );
    $update_sql_index = $this->db->GetUpdateSQL( $rs, $record, true );


    //Insert the records into the database
    if ( !$this->db->Execute( $update_sql_line ) )
      $_SESSION['logger']->error('put_line() Couldn\'t write a new line into DB! SQL: '.$update_sql_line, __LINE__, __FILE__);

    //Insert the records into the database
    if ( !$this->db->Execute( $update_sql_index ) )
      $_SESSION['logger']->error('put_line() Couldn\'t write a new index into DB! SQL: '.$update_sql_index, __LINE__, __FILE__);

    $this->unlock();
    return $cur_line_idx; // return index of current line
  }

  /**
  * test class Channel_Buffer
  *
  * call like: POC_Channel_Buffer::test();
  */
  function test()
  {
    $start = microtime();

    $nl='<br>';
    $cb = new POC_Channel_Buffer( 'schulhof' );
    $cb->connect(); // connect to buffer
    //$cb->init(); //only if it is the first process, be careful
    print 'Channel buffer put line: 1. Zeile'.$nl;
    $since_line_idx = $cb->put_line( '1. Zeile' );
    print 'Channel buffer put line: 2. Zeile'.$nl;
    $cb->put_line( '2. Zeile' );
    print 'Channel buffer put line: 3. Zeile'.$nl;
    $cb->put_line( '3. Zeile' );
    print 'Channel buffer get current line: ';
    print $cb->get_cur_line();
    print $nl;
    $lines = $cb->get_lines_since( $since_line_idx );
    foreach ( $lines as $l )
    {
      print 'Channel buffer get since line '.$since_line_idx.': '.$l.' '.$nl;
    }
    $end = microtime();
    $array_s = explode(' ',$start);
    $array_e = explode(' ',$end);
    print '<br>time in sec. needed by this part of script: ';
    $time1 = round($array_e[ 1 ] + $array_e[ 0 ] - ( $array_s[1] + $array_s[0] ),2);
    print $time1.'<br>';

    $start = microtime();
    print '<p>---</p>Lines in database, current line in database is marked red.';

    //create a database object
    $db = &NewADOConnection( DATABASE_DRIVER );
    $db->Connect( DATABASE_HOST, DATABASE_USER, DATABASE_PASSWORD, DATABASE_TABLESPACE );
    $cur_ln = $cb->get_cur_line_idx();
    for ( $i = 0; $i < CB_MAX_LINE; $i++)
    {
      print '<br><span';
      if( $i == $cur_ln )
        print ' style=\'background: #ffaaaa\'';

      print '>db-field \'LINE_'.$i.'\': ';

      //get current line index from database
      $rs = $db->Execute( 'SELECT LINE_'.$i.' FROM '.DATABASE_TABLE_PREFIX.'line_buffer WHERE NAME=\''.$cb->get_name().'\'' );
      print $rs->fields[ 0 ].'</span>';
    }
    $rs->Close();
    $cb->disconnect();
    // $cb->destroy(); // only if last process, core dump or warning due to PHP BU
    $end = microtime();
    $array_s = explode(' ',$start);
    $array_e = explode(' ',$end);
    print '<br>time in sec. needed by this part of script: ';
    $time2 = round($array_e[ 1 ] + $array_e[ 0 ] - ( $array_s[1] + $array_s[0] ),2);
    print $time2.'<br>';
    print 'time needed by the whole script: '.($time1 + $time2).'<br>';
  }
}
?>