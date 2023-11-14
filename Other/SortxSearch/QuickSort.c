/**
 * @file QuickSort.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief QuickSort
 * @version 0.1
 *
 * @copyright Copyright (c) 2022
 *
 */

//#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int[], int, int);

int main()
{
    int arr[10] = {1, 3, 6, 7, 9, 10, 11, 24, 66, 99};

    quickSort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void quickSort(int arr[], int left, int right)
{
    srand(time(NULL));
    int leftIndex = left;
    int rightIndex = right;
    int tmp = 0;

    // calcolo il pivot randomico
    int pivot = arr[(rand() % (right - left + 1) + left)];

    while (leftIndex <= rightIndex)
    {
        while (arr[leftIndex] < pivot)
        {
            leftIndex++; // sinistra -> destra
        }
        while (arr[rightIndex] > pivot)
        {
            rightIndex--; // sinistra <- destra
        }

        // nel caso dalle due parti trovo maggiore o minore vado a eseguire lo scambio
        if (leftIndex < rightIndex)
        {
            tmp = arr[leftIndex];
            arr[leftIndex] = arr[rightIndex];
            arr[rightIndex] = tmp;
        }

        // se indicatore destro supera l'indicatore a sinistra, vado a spostare i due cursori per le operazioni successive
        if (leftIndex <= rightIndex)
        {
            leftIndex++;
            rightIndex--;
        }
    }

    // faccio la stessa cosa nella parte sinistra o parte destra
    if (left < rightIndex)
    {
        quickSort(arr, left, rightIndex);
    }
    if (leftIndex < right)
    {
        quickSort(arr, leftIndex, right);
    }
}