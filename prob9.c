#include "numbers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int binarySearch(int** array, int length, int value)
{
    unsigned int low = 1;
    unsigned int high = length-1;
    unsigned int mid = length/2;
    int index = -1;

    while (high > low + 1)
    {
        if ((*array)[mid] < value)
        {
            low = mid;
            mid = (high + mid) / 2;
        }
        else if ((*array)[mid] > value)
        {
            high = mid;
            mid = (mid + low) / 2;
        }
        else
        {
            index = mid;
            break;
        }
    }

    return index;
}

int main(int ac, char** av)
{
    int len = 1000;
    int* squares = malloc(len+1);
    
    int i;

    for (i = 1; i <= len; i++)
        squares[i] = i*i;

    int a = 0;
    int b = len-1;
    int c_squared = squares[a] + squares[b];
    int c = binarySearch(&squares, len+1, c_squared);

    bool found = false;

    while (!found && b > 0)
    {
        a++;

        c_squared = squares[a] + squares[b];
        c = binarySearch(&squares, len+1, c_squared);

        if (c >= 0)
        {
            if (a + b + c == 1000)
                printf("%d + %d + %d = %d, %d*%d*%d = %d\n", 
                       a,b,c,(a+b+c),a,b,c,(a*b*c));
        }

        if (a >= b)
        {
            a = 0;
            b--;
        }
    }

    free(squares);
}
