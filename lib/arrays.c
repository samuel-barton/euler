/*=============================================================================
 *
 * Function name: binarySearch
 * 
 * Parameters: int** array - the sorted array to search through
 *             int length  - the length of the array being searched through
 *             int value   - the value being searched for
 *
 * Returns: int - the location of the value in the array, or -1
 *
 * Description: This method runs the binary search algorithm on some sorted 
 *              array which has been put into the heap by calling malloc(...).
 *
 *===========================================================================*/
int binarySearch(int** array, int length, int value)
{
    unsigned int low = 0;
    unsigned int high = length -1;
    unsigned int mid = length/2;
    int index = -1;

    while (high - low > 1)
    {
        if ((*array)[mid] < value)
        {
            low = mid;
            mid += (high - mid)/2;
        }
        else if ((*array)[mid] > value)
        {
            high = mid;
            mid -= (mid - low)/2;
        }
        else
        {
            index = mid;
            break;
        }
    }

    return index;
}
