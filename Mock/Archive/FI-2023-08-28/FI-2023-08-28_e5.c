/**
 * @file FI-2023-08-28_e5.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-24
 *
 * @copyright Copyright (c) 2023
 * @record: 12m 31s
 */

/*
Si scriva un programma in C, completo delle sue parti dichiarative che, dopo aver letto i
valori dell’array a  da  un  file,  e  letto  in  input  il valore di  y,  invochi  in modo opportuno  la  funzione  definita  al
punto precedente e utilizzi la lista restituita dalla funzione per stampare a video le partizioni.
Per la lettura della matrice dal file, si consideri che:
1. Il  nome  del  file  deve  essere  fornito  in  input  da  riga  di  comando  (deve  cioè  essere  gestito  come
parametro del main).
2. Il file è organizzato in modo che i valori siano memorizzati in sequenza e siano separati da uno spazio.
Per l’array nell’esempio precedente, il file è così organizzato:
2 8 0 3 9 6 1 3
Si può assumere che il numero dei valori memorizzati nel file sia minore o al più uguale alla dimensione
massima dell’array, definita dalla costante predefinita N
*/

/*
per compilare usare i seguenti comandi
gcc ./FI-2023-08-28.c -o ./out.exe
./out.exe ./test.txt
*/

#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef struct Nodo
{
    int first;
    int last;
    struct Nodo *next;
} nodo;

nodo *refactor(int[], int, int dim);

int main(int argc, char *argv[])
{
    FILE *fpIn = fopen(argv[1], "r");
    int i = 0;
    int arr[N];
    int y = 0;
    nodo *first;

    printf("\ninserisci il valore di y:");
    scanf("%d", &y);

    for (i = 0; i < N; i++)
    {
        fscanf(fpIn, "%d", &arr[i]);
        fseek(fpIn, sizeof(char), SEEK_CUR);
    }

    first = refactor(arr, y, N);

    while (first != NULL)
    {
        printf("\n%d %d", first->first, first->last);
        first = first->next;
    }
}

nodo *refactor(int arr[], int y, int dim)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    nodo *first;
    nodo *ptr;
    first = (nodo *)malloc(sizeof(nodo) * 1);
    ptr = first;
    for (i = 0; i < dim; i++)
    {
        sum += arr[i];
        if (sum > y)
        {
            ptr->next = (nodo *)malloc(sizeof(nodo) * 1);
            ptr = ptr->next;
            ptr->first = j;
            ptr->last = i - 1;
            j = i;
            i--;
            sum = 0;
        }
    }
    if (j != dim - 1)
    {
        ptr->next = (nodo *)malloc(sizeof(nodo) * 1);
        ptr = ptr->next;
        ptr->first = j;
        ptr->last = dim - 1;
    }

    ptr->next = NULL;
    ptr = first->next;
    free(first);
    return ptr;
}