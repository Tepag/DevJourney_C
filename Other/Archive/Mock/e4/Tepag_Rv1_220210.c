/**
 * @file Tepag_v1_220210.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-02-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arrBubbleSort(int *p, int dim);

int main()
{
    int len = 0;
    int box = 0;
    FILE *fpIn = fopen("./numbers.dat", "r+");
    int *readedNum = NULL;

    fseek(fpIn, 0, SEEK_END);
    len = (int)ftell(fpIn) / sizeof(int);
    rewind(fpIn);

    readedNum = (int *)malloc(sizeof(int) * len);

    fread(readedNum, sizeof(int), len, fpIn);

    printf("%d ", arrBubbleSort(readedNum, len));

    /*
    for (int i = 0; i < len; i++)
    {
        printf("%d ", *(readedNum + i));
    }*/

    fclose(fpIn);
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