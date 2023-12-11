/**
 * @file FI-2023-08-28_e4.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 * @record: 39m 15s
 */

/*
Si definisca una funzione che, ricevuti come parametri di ingresso un array a di n numeri
interi positivi, {x1, x2, ..., xn}, un intero y, (y>= xi, ∀ i = 1, ..., n), e qualsiasi altro parametro ritenuto necessario,
individui le partizioni dell’array costituite da elementi adiacenti con somma minore o uguale a y.
Per esempio, sia a = {2, 8, 0, 3, 9, 6, 1, 3} e sia y = 10. Allora:
{2, 8, 0} {3} {9} {6, 1, 3} sono le possibili partizioni individuabili in base al criterio sopra definito.

La funzione dovrà costruire e restituire al chiamante una lista dinamica i cui elementi memorizzano, per ogni
partizione individuata, gli indici nell’array del primo e dell’ultimo elemento della partizione. Per esempio, per
le partizioni individuate al punto precedente, la lista sarà così costituita:
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int first;
    int last;
    struct Nodo *next;
} nodo;

nodo *refactor(int[], int, int dim);

int main()
{
    int arr[8] = {2, 8, 0, 3, 9, 6, 1, 3};
    int y = 10;
    int dim = 8;
    nodo *first = refactor(arr, y, dim);

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