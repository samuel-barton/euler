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
bool is_palendrome(int product)
{
    char* a = itoa(product);

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

int palendrome(int num_digits)
{
    int n = (int)pow(10,num_digits);
    n--;

    int m = n;

    int product = n*m;
    int max_product = product;
    int pal = 1;

    while (max_product > pal)
    {
        if (is_palendrome(product))
        {
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
