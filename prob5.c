#include <stdio.h>
#include "numbers.h"

/*=============================================================================
 *
 * Filename: prob5.c
 *
 * Project: Project Euler challenges
 *
 * Desciption: find the smallest number easily divisible by all the numbers
 *             from 1 to 20.
 *
 *===========================================================================*/
int test_vals[8] = {20,19,18,17,16,14,13,11};

bool divides(int n)
{
    int i = 0;
    while(i < 8)
    {
        if (n % test_vals[i] != 0)
            return false;
        i++;
    }

    return true;
}

int main(int ac, char** av)
{
    int value = 2520;

    while (!divides(value))
        value++;

    printf("smallest number divisible by all numbers from 1 through 20: %d\n",
           value);
}
