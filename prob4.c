#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "numbers.h"
#include "strings.h"

/*=============================================================================
 *
 * Filename: prob4.c
 *
 * Project: Project Euler challenges
 *
 * Desciption: find the largest palendrome product of two three digit numbers.
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
 * Function: palendrome
 *
 * Parameters: int num_digits - the number of digits to run the algorithm for
 *
 * Returns: int - the largest palendrome in num_digits
 *
 * description: This function calculates the largest palendrome created by 
 *              the product of two n digit numbers where n is num_digits.
 *
 *              The algorithm to solve this runs as follows: 
 *                  1 Calculate the largest n digit number and square it to get
 *                    the largest product of two n digit numbers
 *
 *                  2 if the product is a palendrome or we've iterated n times
 *                      - calculate (n - 1)^2
 * 
 *                  3 Otherwise, calculate the next smallest product of two n
 *                    digit numbers
 *
 *                  4 Repeat 2,3 until the product generated by (n-k)^2 is 
 *                    smaller than the largest palendrome found
 *
 *===========================================================================*/
int palendrome(int num_digits)
{
    int n = (int)pow(10,num_digits);
    n--;

    int m = n;

    int product = n*m;
    int max_product = product;
    int pal = 1;

    /* loop until we cannot create a product that is the size of our largest
     * palendrome. */
    while (max_product > pal)
    {
        if (is_palendrome(product))
        {
            if (product > pal)
                pal = product;
            printf("%d = %d * %d\n", pal, n, m);
            n--;
            m = n;
            max_product = n*n;
        }
        else
        {
            if (m > 0)
                m--;
            else
            {
                n--;
                m = n;
            }
        }
        
        if (product < pal)
        {
            n--;
            m = n;
            max_product = n*n;
        }
         
        product = n*m;
    }

    return pal;
}

int main(int ac, char** av)
{
    int num_digits = 3;

    if (ac > 1)
      num_digits = atoi(av[1]);

    int sum = 0;
    int i = 1;

    int pal = palendrome(num_digits);
    printf("Largest palendrome product of %d digits  = %d\n", num_digits, pal);
}
