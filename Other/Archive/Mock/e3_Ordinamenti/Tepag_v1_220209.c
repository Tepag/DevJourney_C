/**
 * @file Tepag_v1_220208.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief provo il bubble sort
 * @version 1.1
 * @date 2022-02-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

void printArray(int *, int);
void bubbleSort(int *, int);

int main()
{
    int array[DIM] = {1, 3, -1, 85, 65, 112, -64, 12, 4, 6};

    // bubbleSort
    printArray(array, DIM);
    bubbleSort(array, DIM);
    printArray(array, DIM);

    // insertionSort

    // quickSort

    return 0;
}

void printArray(int *p, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");
}

void bubbleSort(int *p, int dimNotSort)
{
    int scambi = -1, tmp = 0;
    dimNotSort--;
    while (scambi != 0)
    {
        scambi = 0;
        for (int i = 0; i < dimNotSort; i++)
        {
            if (*(p + i) > *(p + i + 1))
            {
                tmp = *(p + i);
                *(p + i) = *(p + i + 1);
                *(p + i + 1) = tmp;
                scambi++;
            }
        }
        dimNotSort--;
    }
}

void quickSort(int *p, int dim)
{
    int pivot = 0;
    // scegli ogni volta il pivot e si va creare i gruppi più piccoli e gruppi più grandi
    // complessità minore
}