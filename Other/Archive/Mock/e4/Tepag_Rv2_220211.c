/**
 * @file Tepag_v1_220210.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief introduzione del quick sort
 * @version 0.2
 * @date 2022-02-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *readAllIntFromFile(char *, int *);
int arrBubbleSort(int *p, int dim);
int *arrQuickSort(int *p, int dim);

int main()
{
    int *readedNum = NULL;
    int len = 0;

    readedNum = readAllIntFromFile("./numbers.dat", &len);
    arrQuickSort(readedNum, len);
    // printf("%d ", arrBubbleSort(readedNum, len));

    for (int i = 0; i < len; i++)
    {
        printf("%d ", *(readedNum + i));
    }
}

int *readAllIntFromFile(char *path, int *len)
{
    int *readedNum = NULL;
    FILE *fpIn = fopen(path, "r+");
    fseek(fpIn, 0, SEEK_END);
    *len = (int)ftell(fpIn) / sizeof(int);
    rewind(fpIn);
    readedNum = (int *)malloc(sizeof(int) * *len);
    fread(readedNum, sizeof(int), *len, fpIn);
    fclose(fpIn);
    return readedNum;
}

int arrBubbleSort(int *p, int dim)
{
    int change = -1;
    int tmp = 0;
    int cnt = 0;
    dim--;
    while (change != 0)
    {
        change = 0;
        for (int i = 0; i < dim; i++)
        {
            cnt++;
            if (*(p + i) > *(p + i + 1))
            {
                tmp = *(p + i);
                *(p + i) = *(p + i + 1);
                *(p + i + 1) = tmp;
                change++;
            }
        }
        dim--;
    }
    return cnt;
}

int *arrQuickSort(int *p, int dim)
{
    FILE *fpOut = fopen("./tmp.dat", "w+");

    srand(time(NULL));

    // generazione del pivot;
    int pivotIndex = rand() % (dim - 1);
    printf("%d ", *(p + pivotIndex));
    int pivot = *(p + pivotIndex);
    int tmp = 0;

    printf("\n\npivot: %d\n\n", pivot);

    // printf("%d", *(p + pivotIndex));

    // ricorsione solo se contiene ancora numeri

    for (int i = 0; i <= pivotIndex; i++)
    {
        for (int j = (dim - 1); j > pivotIndex; j--)
        {
            if (*(p + i) > *(p + j))
            {
                tmp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = tmp;
            }
        }
    }

    /**
    for (int i = 0; i < dim; i++)
    {
        if (i != pivotIndex)
        {
            if (*(p + i) < *(p + pivotIndex))
            {
                major = (int *)realloc(major, majorDim);
                *(major + majorDim - 1) = *(p + i);
                majorDim++;
            }
            else
            {
                minor = (int *)realloc(major, minorDim);
                *(minor + minorDim - 1) = *(p + i);
                minorDim++;
            }
        }
    }
    */
    // gruppo dei numeri minori

    // gruppo dei numeri maggiori
    return NULL;
}