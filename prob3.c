#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numbers.h"

/*=============================================================================
 *
 * Filename: prob3.c
 *
 * Project: Project Euler challenges
 *
 * Desciption: Calculate the prime factors of a number, and return the largest
 *             one.
 *
 *===========================================================================*/

int main(int ac, char** av)
{
    long value = 600851475143;

    if (ac > 1)
      value = atoi(av[1]);

    int sum = 0;
    int i = 1;

    printf("Largest prime factor = %ld\n", largest_prime_factor(value));
}
