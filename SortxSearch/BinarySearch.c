/**
 * @file BinarySearch.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief binary search
 * @version 0.1
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>

int binarySearch(int[], int, int, int);

int binarySearchRec(int[], int, int, int);

int main()
{
    int arr[10] = {1, 3, 6, 7, 9, 10, 11, 24, 66, 99};
    printf("%d", binarySearchRec(arr, 0, 9, 99));
    return 0;
}

int binarySearch(int arr[], int startIndex, int endIndex, int key)
{
    int middleIndex;
    int found = -1;

    // gira finchè lo trova o termina
    while (endIndex <= startIndex)
    {
        // trova il punto medio
        middleIndex = (startIndex + endIndex) / 2;

        // vedere se è maggiore o minore, nessuno dei due , trovato
        if (key > arr[middleIndex])
        {
            startIndex = middleIndex + 1;
        }
        else
        {
            if (key < arr[middleIndex])
            {
                endIndex = middleIndex - 1;
            }
            else
            {
                found = middleIndex;
            }
        }
    }

    return found;
}

int binarySearchRec(int arr[], int startIndex, int endIndex, int key)
{
    int middleIndex;

    // gira finchè lo trova o termina
    if (endIndex < startIndex)
    {
        return -1;
    }
    else
    {
        // trova il punto medio
        middleIndex = (startIndex + endIndex) / 2;

        // vedere se è maggiore o minore, nessuno dei due , trovato
        if (key > arr[middleIndex])
        {
            return binarySearchRec(arr, middleIndex + 1, endIndex, key);
        }
        else
        {
            if (key < arr[middleIndex])
            {
                return binarySearch(arr, startIndex, middleIndex - 1, key);
            }
            else
            {
                return middleIndex;
            }
        }
    }
    return -1;
}
