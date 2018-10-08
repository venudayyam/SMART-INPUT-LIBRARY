# SMART-INPUT-LIBRARY

C Library to perform operations on input streams with data validation and robust error check <br>
The library is written in c programming by @venudayyam (binary_10) reviewed on [code-review - stackexchange.com] (https://codereview.stackexchange.com/questions/162349/c-library-for-standard-input-operations-with-data-validation-and-error-check)
 

The library contain two sets of subroutines one of which operate on the stream passed as an argument 'stream' and the other set operate  directly on standard input stream (stdin).
<br><br>Each of the subroutines read a line (which is then stored as a string) from input stream ('stream' or stdin), converts it into corresponding built-in data type and stores the result in the location pointed to by 'value'. An 'int' type value is returned by the subroutines.


The key motivation behind this implementation is that the standard input functions leave the unmatched/redundant characters untouched in  the buffer. These characters serve as input to the subsequent reads which is not a reliable behavior.



<br><br>KEY FEATURES:

- data overflow and underflow check on input

- input buffer is flushed(empty) after each call to the set of functions which operate on
  standard input stream (stdin)

- input value is said to be valid only when the input string (excluding initial white spaces and sign)
  contains only digits and if the converted value can be stored in the specified data type.


<br>

~~~~ 
     > gcc -Wall -std=c11 sample.c smartinput.c -o sample
     > sample
~~~~
