#include "numbers.h"
#include <stdio.h>
#include <stdlib.h>

/*============================================================================
 *
 * Function: seive
 *
 * Parameters: int** values - the values to run the seive on
 *
 * Returns: void
 * 
 * Description: This function executes the seive of erothsenese on an array 
 *              of n numbers. All non-primes will be replaced with 0.
 *
 *===========================================================================*/
void seive(int** values, int length)
{
    int i = 2;
    int nth = 2;
    
    while (nth < length)
    {
        do
        {
            i += nth;
            (*values)[i] = 0;
        }
        while (i < length);

        nth++;
        while (nth < length && (*values)[nth] == 0)
            nth++;

        i = nth;
    }
}

int main(int ac, char** av)
{
    int target = 1e5;

    int* primes = malloc(sizeof(int)*target);

    int i;
    for (i = 2; i < target; i++)
        primes[i] = i;

    seive(&primes, target);
    printf("%d\n", primes[target-1]);

    long sum = 0;
    for (i = 0; i < target; i++)
        sum += (long)primes[i];

    printf("sum of primes below %d = %ld\n", target, sum);
    free(primes);
}
