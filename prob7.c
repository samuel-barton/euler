#include <stdio.h>
#include "numbers.h"
#include <stdlib.h>

int main(int ac, char** av)
{
    int count = 10001;

    if (ac > 1)
        count = atoi(av[1]);

    int i;
    int nth = 1;
    for (i = 0; i < 10001; i++)
        nth = next_prime(nth);

    printf("the 10001st prime is %d\n", nth);
}
