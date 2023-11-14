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

#define DIM 10

int main()
{
    int array[DIM] = {1, 3, -1, 85, 65, 112, -64, 12, 4, 6};
    int scambi = -1;
    int dimNotSort = (DIM - 1);
    int tmp = 0;

    for (int i = 0; i < DIM; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n\n\n");

    while (scambi != 0)
    {
        scambi = 0;
        for (int i = 0; i < dimNotSort; i++)
        {
            if (array[i] > array[i + 1])
            {
                tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                scambi++;
            }
        }
        dimNotSort--;
    }

    for (int i = 0; i < DIM; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}