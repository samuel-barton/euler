#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int ac, char** av)
{
    unsigned long answer = 0;
    char* digits = malloc(1000*sizeof(char) + 2);

    printf("Enter 1000 digit number:\n");

    read(0, digits, 1000);

    digits[1000] = '\0';

    printf("\n");

    unsigned long product;
    int i = 0;
    while (i < 987)
    {
        product = 1;
        int j = 0;
        while (j < 13)
        {
            product *= (unsigned long)digits[i+j];
            j++;
        }
        
        if (product > answer)
            answer = product;

        i++;
    }

    printf("answer = %lu\n", answer);
}
