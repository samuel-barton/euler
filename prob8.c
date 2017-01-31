#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/*=============================================================================
 *
 * Filename: prob8.c
 *
 * Project: Euler
 *
 * Description: This program calculates the greatest product of 13 adjacent 
 *              digits in a 1000-digit number, provided in the text file named
 *              1000_digits. 
 *
 *===========================================================================*/
int main(int ac, char** av)
{
    unsigned long answer = 0;
    char* digits = malloc(1000*sizeof(char) + 2);

    printf("Enter 1000 digit number:\n");

    read(0, digits, 1000);

    digits[1000] = '\0';

    printf("\n");

    int max_index;
    unsigned long product;
    int i = 13;
    while (i < 986)
    {
        product = 1;
        int j = 0;
        while (j < 13)
        {
            /* since we're dealing with characters, we don't check against 0.*/
            if (digits[i+j] == '0')
            {
                i += j;
                break;
            }

            /* type casting a char to an integer value gives the ASCII code for
             * the character, so to get the integer value we just subtract off
             * the value for the character '0' as the ASCII representation of
             * decimal digits places their ASCII codes in ascending order from
             * zero. */
            product *= (unsigned long)(digits[i+j] - '0');
            j++;
        }
        
        if (product > answer)
        {
            answer = product;
            max_index = i;
        }
        i++;
    }

    for (i = 0; i < 12; i++)
        printf("%c, ", digits[max_index+i]);

    printf("%c\n",digits[max_index+12]);

    printf("answer = %lu\n", answer);
}
