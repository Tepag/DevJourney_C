#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5

typedef struct RGB
{
    int r;
    int g;
    int b;
} rgb;

int main()
{
    rgb matrix[DIM][DIM];
    float grayscale[DIM][DIM];
    int i = 0, j = 0;

    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            matrix[i][j].r = rand() % 256;
            matrix[i][j].g = rand() % 256;
            matrix[i][j].b = rand() % 256;
        }
    }

    printf("vettore iniziale : \n\n");
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            printf("(%3d, %3d, %3d)   ", matrix[i][j].r, matrix[i][j].g, matrix[i][j].b);
        }
        printf("\n");
    }

    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            grayscale[i][j] = 0.2989 * (float)matrix[i][j].r + 0.5870 * (float)matrix[i][j].g + 0.1140 * (float)matrix[i][j].b;
        }
    }

    printf("vettore finale : \n\n");
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            printf("%12.4f", grayscale[i][j]);
        }
        printf("\n");
    }

    return 0;
}
