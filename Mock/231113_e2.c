#include <stdio.h>

void inseriscinum(int[][2]);
void inseriscinumV2(int *);

int main()
{
    int mat[2][2];
    int i = 0, j = 0;

    inseriscinumV2(&mat[0][0]);

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%2d", mat[i][j]);
        }
        printf("\n");
    }
}

void inseriscinum(int mat[][2])
{
    int i = 0, j = 0;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("inserisci un numero");
            scanf(" %d", &mat[i][j]);
            fflush(stdin);
        }
    }
}

void inseriscinumV2(int *ptr)
{
    int i = 0, j = 0;
    for (i = 0; i < (2 * 2); i++) // DIM * DIM2
    {
        printf("inserisci un numero");
        scanf(" %d", ptr + i);
        fflush(stdin);
    }
}