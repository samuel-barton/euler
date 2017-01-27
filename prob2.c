#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numbers.h"

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
int main(int ac, char** av) { int limit = 4e6;

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
