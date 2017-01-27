/*=============================================================================
 *
 * filename: numbers.h
 *
 * project: project euler
 *
 * created by: samuel barton
 *
 * description: this file contains all of the useful number related functions
 *              created to solve the project euler problems.
 *
 *===========================================================================*/

/* define boolean type. */
typedef int bool;
#define true 1
#define false 0

/* return the nth fibonacci term */
int fib(int n);
bool is_prime(int n);
long largest_prime_factor(long factoree);
long next_prime(long n);
bool is_palendrome(int value);
