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

int main(int ac, char** av)
{
    int value = 2520;

    bool success = false;

    int i;
    for (i = 1; i < 20; i++)
    {
        if (value % i != 0)
        {
            value++;
            i = 0;
        }
    }

    printf("smallest number divisible by all numbers from 1 through 20: %d\n",
           value);
}
