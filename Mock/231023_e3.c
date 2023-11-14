#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define DIM 3
#define N 10

int main()
{
    float inputMatrix[N][N];
    float outMatrix[N][N] = {0};
    int i = 0, j = 0;
    int x = 0, y = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            inputMatrix[i][j] = rand() % 10;
        }
    }

    printf("vettore iniziale : \n\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%.2f  ", inputMatrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            outMatrix[i][j] = 0;
            for (y = i - 1; y <= i + 1; y++)
            {
                for (x = j - 1; x <= j + 1; x++)
                {
                    if (!(y < 0 || y >= N || x < 0 || x >= N))
                    {
                        outMatrix[i][j] += inputMatrix[y][x];
                    }
                }
            }
            outMatrix[i][j] /= (DIM * DIM);
        }
    }

    printf("vettore finale : \n\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%.2f  ", outMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}