/**
 * @file 20231119_e3.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-19
 *
 * @copyright Copyright (c) 2023
 * @record: 5 min 24 sec
 */

/*
Si scriva un programma che prenda in input una matrice di dimensione fissata (es. 3x3) e ne
calcoli la matrice trasposta.
*/

#include <stdio.h>
#define N 3

int main()
{
    int mat[N][N];
    int matOut[N][N];
    int i = 0, j = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("\ninserisci il valore nella cella (%d, %d):", j, i);
            scanf("%d", &mat[i][j]);
            matOut[j][i] = mat[i][j];
        }
    }

    printf("\n\nMatrice originale \n\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMatrice trasposta \n\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%4d", matOut[i][j]);
        }
        printf("\n");
    }
    return 0;
}