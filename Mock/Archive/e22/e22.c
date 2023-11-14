/*
Scrivete un programma che legga da input due array, A da 10 elementi e B da 5 elementi.
Il programma deve stampare "B è contenuto in A" se A contiene la sequenza contigua dei numeri di B, altrimenti stampa "B non è contenuto in A".

*/
#include <stdio.h>

int main()
{
    int arrA[10] = {0};
    int arrB[5] = {0};
    int fflag = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("inserisci il valori di A: ");
        scanf("%d", &arrA[i]);
        fflush(stdin);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("inserisci il valori di B: ");
        scanf("%d", &arrB[i]);
        fflush(stdin);
    }

    int j = 0;
    for (int i = 0; i < 5; i++)
    {
        fflag = 0;
        j = 0;
        do
        {
            if (arrB[i] == arrA[j])
            {
                fflag++;
            }
            j++;
        } while (fflag == 0 && j < 10);
        if (fflag == 0)
        {
            printf("B non è contenuto in A");
            return 1;
        }
    }

    printf("B è contenuto in A");
    return 0;
}