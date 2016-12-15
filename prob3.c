#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

static int cur_max_prime;

/* generate the next prime in the sequence of primes. */
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

int is_prime(int n)
{
    int i = 2;

    while (i < n)
    {
        if (n % i == 0)
            return 1;

        i++;
    }

    return 0;
}

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

int main(int ac, char** av)
{
    long value = 600851475143;

    if (ac > 1)
      value = atoi(av[1]);

    int sum = 0;
    int i = 1;

    printf("Largest prime factor = %ld\n", largest_prime_factor(value));
}
