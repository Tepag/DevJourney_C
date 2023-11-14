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

#define DIM 10

int main()
{
    int box = 0;
    FILE *fpOut = fopen("./numbers.dat", "w");
    srand(time(NULL));
    for (int i = 0; i < DIM; i++)
    {
        box = rand() % 1000;
        fwrite(&box, sizeof(int), 1, fpOut);
    }
    fclose(fpOut);
}