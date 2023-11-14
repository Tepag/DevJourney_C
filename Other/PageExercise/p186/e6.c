/*
leggere quattro numeri e indicare il minore e maggiore

RECORD: 4m 22s
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 4

int main()
{
    int vet[DIM];
    int i = 0;
    int major = 0, minor = 0;

    for (i = 0; i < DIM; i++)
    {
        printf("\ninsert the number: ");
        scanf("%d", &vet[i]);
        fflush(stdin);
    }
    major = vet[0];
    minor = vet[0];

    for (i = 0; i < DIM; i++)
    {
        if (vet[i] > major)
        {
            major = vet[i];
        }
        else
        {
            if (vet[i] < minor)
            {
                minor = vet[i];
            }
        }
    }

    printf("\nMinor: %d\nMajor: %d", minor, major);

    return 0;
}