/**
 * @file 231213_e1.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

#define DIM 9

int main()
{
    int i = 0;
    int j = 0;

    // triangolo superiore
    for (i = 0; i < DIM / 2; i++)
    {
        // spazi
        for (j = 0; j < (DIM / 2) - i; j++)
        {
            printf("- ");
        }

        // triangolo
        for (j = 0; j < (1 + i * 2); j++)
        {
            printf("+ ");
        }

        // spazi
        for (j = 0; j < (DIM / 2) - i; j++)
        {
            printf("- ");
        }

        printf("\n");
    }

    // riga intermedia
    for (j = 0; j < DIM; j++)
    {
        printf("+ ");
    }
    printf("\n");

    // triangolo inferiore
    for (i = (DIM / 2) - 1; i >= 0; i--)
    {
        // spazi
        for (j = (DIM / 2) - 1 - i; j >= 0; j--)
        {
            printf("- ");
        }

        // triangolo
        for (j = 0; j < (1 + i * 2); j++)
        {
            printf("+ ");
        }

        // spazi
        for (j = (DIM / 2) - 1 - i; j >= 0; j--)
        {
            printf("- ");
        }

        printf("\n");
    }
}