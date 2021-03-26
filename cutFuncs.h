/* cutFuncs.h */

#ifndef __CUTFUNCS_H__
#define __CUTFUNCS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define arg_limit 100          // maximum positions at which we print data

/* Name         : isDigit
 * Purpose      : To check if a string contains only digit or not
 * Parameters   : const char *s
 *                
 * Return       : 1 if there is a non-digit character, 0 if all characters are digit
 */
int isDigit(const char *s);


/* Name         : fieldCheck
 * Purpose      : To check the error of the input field (3 cases)
 * Parameters   : int argc, char *argv[]
 *                
 * Return       : 1 if there is an error, 0 if there is no error
 */
int fieldCheck (int argc, char *argv[]);


/* Name         : inputError
 * Purpose      : To check for all possible input errors (6 cases in total)
 * Parameters   : int argc, char *argv[]
 *                
 * Return       : 1 if there is an error, 0 if there is no error
 */
int inputError (int argc, char *argv[]);


/* Name         : cutCommand
 * Purpose      : Read the input file. Cut the fields of each line in the file like the cut command in Linux
 * Parameters   : int argc, char *argv[]

 *                
 * Return       : cut the line and after reach the end of the file, exit with exit code 0
 */
int cutCommand (int argc, char *argv[]);

#endif // __CUTFUNCS_H__