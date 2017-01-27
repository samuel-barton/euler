#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/*=============================================================================
 *
 * filename: strings.c
 *
 * project: project euler
 *
 * created by: Samuel Barton
 *
 * description: this file contains all of the useful String related functions
 *              created to solve the project euler problems.
 *
 *===========================================================================*/

/*=============================================================================
 *
 * Function: reverse
 *
 * Parameters: char* s
 *
 * Returns: char* - the reversal of the string passed in
 *
 * description: this function reverses the string it is passed in as an 
 *              arguments.
 *
 *===========================================================================*/
char* reverse(char* s)
{
    int i = strlen(s);
    char* result = malloc(i + 1);;
    strcpy(result, s);
    i--;
    int lim = ((i % 2 == 0) ? i/2 : i/2 + 1);
    int j = 0;

    while (i >= lim)
    {
        result[j++] = s[i--];
    }
    
    return result;
}

/*=============================================================================
 *
 * Function: itoa
 *
 * Parameters: int n
 *
 * Returns: char* - the string representation of the integer i passed in.
 *
 * description: this function generates the string representation of the int
 *              it is passed.
 *
 *===========================================================================*/
char* itoa(int n)
{
    int num_chars = ceil(log(n));
    char* result = malloc(num_chars + 1);

    sprintf(result, "%d", n);

    return result;
}
