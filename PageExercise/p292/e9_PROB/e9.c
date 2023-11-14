/*
Visualizza le combinazioni semplici, per esempio di cinque colori, in tre posizioni: il numero di allineamento
è ottenuto dalla formula del coefficiente binomiale

RECORD: 41m 02s
*/

#include <stdio.h>
#include <stdlib.h>
#include "e9_lib.c"

int main()
{
    int n = 0;

    //1
    int i, j, k;
    int arr[5];
    //2
    printf("Enter the first number : ");
    scanf("%d", &arr[0]);
    printf("Enter the second number : ");
    scanf("%d", &arr[1]);
    printf("Enter the third number : ");
    scanf("%d", &arr[2]);
    printf("Enter the third number : ");
    scanf("%d", &arr[3]);
    printf("Enter the third number : ");
    scanf("%d", &arr[4]);
    //3
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            for (k = 0; k < 5; k++)
            {
                if (i != j && j != k && k != i)
                {
                    //4
                    printf("[%d %d %d]\n", arr[i], arr[j], arr[k]);
                }
            }
        }
    }

    /*
    printf("questo prgramma fa il calcolo delle combinazioni ");

    printf("inserire il numero delle posizioni: ");
    scanf("%d", &k);
    fflush(stdin);

    printf("\ninserire il numero di oggetti: ");
    scanf("%d", &n);
    fflush(stdin);

    printf("\nil coefficiente binomiale di n=%d e k=%d e\' pari a: %d", n, k, coefficiente_binomiale(n, k));
    */
    return 0;
}