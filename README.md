# SMART-INPUT-LIBRARY

C Library to perform operations on input streams with data validation and robust error check.<br>
 

The library contains two sets of subroutines one of which operate on the stream passed as an argument 'stream' and the other set operate  directly on standard input stream (stdin).
<br><br>Each of the subroutines read a line (which is then stored as a string) from input stream ('stream' or stdin), converts it into corresponding built-in data type and stores the result in the location pointed to by 'value'. An 'int' type value is returned by the subroutines.


The key motivation behind this implementation is that the standard input functions leave the unmatched/redundant characters untouched in  the buffer. These characters serve as input to the subsequent reads which is not a reliable behavior.



<br><br>KEY FEATURES:

- Robust error check on the Input data.

- Input buffer is flushed after each call to the set of functions which operate on
  standard input stream (stdin)

<br>

~~~~ 
  /* sample inputs and outputs of `get_int()` (note. sizeof(int) = 4) */

  "2147483647\n"    -- SUCCESS  (INT_MAX)
  "2147483648\n"    -- FAILURE
  "-2147483648\n"   -- SUCCESS  (INT_MIN)
  "-2147483649\n"   -- FAILURE
  "25ds\n"          -- FAILURE
  "asdjkljasdf\n"   -- FAILURE 
  "25 256\n"        -- FAILURE
  "+1\n"            -- SUCCESS
  "-1\n"            -- SUCCESS
  EOF               -- EOF
  " 1\n"            -- SUCCESS 
~~~~ 


~~~~ 
  > gcc -Wall -std=c11 sample.c smartinput.c -o sample
  > sample
~~~~






