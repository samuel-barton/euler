#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*=============================================================================
 *
 * Filename: prob2.c
 *
 * Project: Project Euler challenges
 *
 * Desciption: By considering the terms in the Fibonacci sequence whose values 
 *             do not exceed four  million, find the sum of the even-valued 
 *             terms.
 *
 *===========================================================================*/

/* return the nth value in the Fibonacci sequence. */
int fib(int n)
{
    double root_5 = sqrt(5);
    double phi_1 = (1 + root_5)/2;
    double phi_2 = 1 - phi_1;
    
    return round((pow(phi_1, n) - pow(phi_2, n))/root_5);
}

int main(int ac, char** av)
{
    int limit = 4e6;

    if (ac > 1)
      limit = atoi(av[1]);

    int sum = 0;
    int i = 1;

    int value = fib(i++);

    while (value < limit)
    {
       value = fib(i++);

       if (value % 2 == 0)
           sum += value;
    }

    printf("sum = %d\n", sum);
}
