/* SMARTINPUT.H
 *
 * This file is an interface to the 'smartinput' library.
 * The library is written in c programming.
 * by @venudayyam (binary_10)
 *
 * The library contain two sets of subroutines one of which operate on the
 * stream passed as an argument 'stream' and the other set operate directly
 * on standard input stream (stdin).
 *
 * Each of the subroutines read a line (which is then stored as a string)
 * from input stream ('stream' or stdin), converts it into corresponding
 * built-in data type and stores the result in the location pointed to by
 * 'value'. An 'int' type value is returned by the subroutines.
 *
 * The key motivation behind this implementation is that the standard
 * input functions leave the unmatched/redundant characters untouched in
 * the buffer. These characters serve as input to the subsequent reads
 * which is not a reliable behavior
 *
 *
 *  KEY FEATURES:
 *
 * - data overflow and underflow check on input
 *
 * - input buffer is flushed(empty) after each call to the set of functions
 *   which operate on standard input stream (stdin)
 *
 * - input value is said to be valid only when the input string (excluding
 *   initial white spaces and sign) contains only digits and if the converted
 *   value can be stored in the specified data type.
 *
 */

#ifndef SMARTINPUT_H
#define SMARTINPUT_H

#include <stdio.h>

#define SUCCESS 0
#define FAILURE 1

/*
 * int fget_int (int *value, FILE *stream);
 *
 * DESCRIPTION  :
 *
 * fget_int() reads a line (which is then stored as a string) from the stream
 * 'stream', converts it into an integer and stores result in the location
 * pointed to by 'value'
 *
 * String may begin with arbitrary amount of white spaces (except new line
 * character ('\n') which determines 'end of line'), a sign (+,-) followed by
 * a sequence of digits (0-9) that constitute the number.
 *
 * RETURN VALUE
 *
 * The value of 'EOF' is returned if 'end of file' is reached before no characters
 * have been read from the stream or if an input failure occurs.
 *
 * If the converted value exceeds the range (overflow or underflow) of the type
 * or If conversion cannot be performed because of invalid format of the string
 * (other than leading arbitrary white spaces except '\n', sign and sequence of
 * digits) or If the string is empty 'fget_int()' returns 'FAILURE'.
 *
 * In which case the the location pointed to by 'value' (*value) is untouched.
 *
 * other wise it returns 'SUCCESS' to indicate a successful conversion.
 *
 *
 * The rest of functions work same as this but they differ either in stream on which
 * they operate (stdin) or resulting data type.
 */




/*
 * int fget_line(char *s, int len, FILE *stream);
 *
 * DESCRIPTION
 *
 * fget_line() reads a line from the 'stream' and stores at most len-l characters
 * into the array pointed to by 's'. reading stops after '\n' (which is also
 * copied) or at EOF. buffer is terminated with '\0' null character.
 *
 * RETURN VALUE
 *
 * fget_line() returns EOF if EOF occurs before no characters have been read
 * or if 'len' is less than 1 or if a read error occurs
 *
 * else 'SUCCESS' on success.
 *
 *
 * get_line() works same as this but operates on standard input stream(stdin).
 *
 */


int get_short(short *value);
int get_ushort(unsigned short *value);

int get_int(int *value);
int get_uint(unsigned int *value);

int get_long(long *value);
int get_ulong(unsigned long *value);

int get_llong(long long *value);
int get_ullong(unsigned long long *value);

int get_line(char *s, int len);



int fget_short(short *value, FILE *stream);
int fget_ushort(unsigned short *value, FILE *stream);

int fget_int(int *value, FILE *stream);
int fget_uint(unsigned int *value, FILE *stream);

int fget_long(long *value, FILE *stream);
int fget_ulong(unsigned long *value, FILE *Istream);

int fget_llong(long long *value, FILE *stream);
int fget_ullong(unsigned long long *value, FILE *stream);

int fget_line(char *s, int len, FILE *stream);



#endif

