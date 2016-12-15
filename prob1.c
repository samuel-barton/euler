#include <stdio.h>
#include <stdlib.h>

/*======================================================================================================
 *
 * Filename: prob1.c
 *
 * Project: Project Euler challenges
 *
 * Desciption: find the sum of the multiples of three and five below 1000.
 *
 *=====================================================================================================*/
int main(int ac, char** av)
{
    int limit = 1000;

    if (ac > 1)
      limit = atoi(av[1]);

    int sum = 0;
    int i;

    for (i = 0; i < limit; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }

    printf("sum of multiples of 3 or 5 less than %d = %d\n", limit, sum);
}
