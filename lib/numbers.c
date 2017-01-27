#include "numbers.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

/*=============================================================================
 *
 * filename: numbers.c
 *
 * project: project euler
 *
 * created by: samuel barton
 *
 * description: this file contains all of the useful number related functions
 *              created to solve the project euler problems.
 *
 *===========================================================================*/


/*=============================================================================
 *
 * Function name: is_palendrome
 *
 * Parameters: int value - the value to test for palendromeness.
 *
 * Returns: boolean - true if product is a palendrome, false otherwise.
 *
 * Desciption: find the largest palendrome product of two three digit numbers.
 *
 *===========================================================================*/
bool is_palendrome(int value)
{
    char* a = itoa(value);

    int len = strlen(a);

    if (len == 1)
    {
        free(a);
        return true;
    }

    int i = 0;
    int last = len-1;
    int stop = ((len % 2 == 0) ? len/2 : len/2 - 1);

    while (i < stop)
    {
        if (a[i] != a[last-i])
             return false;
        i++;
    }

    free(a);

    return true;
}

/*=============================================================================
 *
 * Function: fib
 *
 * Parameters: int n - the number whose Fibonacci number is being found
 *
 * Returns: int - the nth number in the  Fibonacci Sequence
 *
 * description: this function calculates the nth number in the Fibonacci series
 *              using the convergence value for the nth term. 
 *
 *===========================================================================*/
int fib(int n)
{
    double root_5 = sqrt(5);
    double phi_1 = (1 + root_5)/2;
    double phi_2 = 1 - phi_1;
    
    return round((pow(phi_1, n) - pow(phi_2, n))/root_5);
}

/*=============================================================================
 *
 * Function: is_prime
 *
 * Parameters: int n - the number to check for primality
 *
 * Returns: bool - whether or not the number is prime
 *
 * description: This function determines whether or not n is prime. 
 *
 *===========================================================================*/
bool is_prime(int n)
{
    int i = 2;

    while (i < sqrt(n))
    {
        if (n % i == 0)
            return 0;

        i = next_prime(i);
    }

    return 1;
}

/*=============================================================================
 *
 * Function: largest_prime_factor
 *
 * Parameters: long factoree - the number to factor
 *
 * Returns: long - the largest prime factor of the parameter
 *
 * description: This function recursively calculates the largest prime factor
 *              of the factoree. 
 *
 *===========================================================================*/
long largest_prime_factor(long factoree)
{
    long cur_prime = 2;
    while (factoree % cur_prime != 0)
        cur_prime = next_prime(cur_prime);

    if (cur_prime >= factoree)
      return cur_prime;

    long factor = largest_prime_factor(factoree/cur_prime);
    if (factor > cur_prime)
        return factor;
    else
        return cur_prime;
}

/*=============================================================================
 *
 * Function: next_prime
 *
 * Parameters: long n - the number after which the next prime must be found
 *
 * Returns: long - the next prime
 *
 * description: This function finds the next prime greater than n.
 *
 *===========================================================================*/
long next_prime(long n)
{
    int i = 2;
   
    long new_prime = n + 1;

    while (i < new_prime)
    {
        if (new_prime % i == 0)
        {
            new_prime++;
            i = 2;
        }
        i++;
    }

    return new_prime;
}
