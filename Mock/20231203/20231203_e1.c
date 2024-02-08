/**
 * @file 20231203_e1.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-03
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
    Esercizio 1 - Array dinamici
    Creare un programma che, dopo aver chiesto la lunghezza di un array di interi, ne chieda
    l'inserimento e lo visualizzi. N.B.: L'array della dimensione giusta deve essere allocato
    dinamicamente.

    Esempio:
    Inserisci la lunghezza dell'array: 5
    9 6 0 4 2
    Output:
    L'array da te inserito e': [9, 6, 0, 4, 2]
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dim;
    int *ptr;
    int i;

    ptr = NULL;
    dim = 0;

    printf("Inserisci la lunghezza dell'array: ");
    scanf("%d", &dim);
    fflush(stdin);

    ptr = (int *)malloc(sizeof(int) * dim);

    i = 0;
    while (i < dim)
    {
        scanf(" %d", ptr + i);
        i++;
    }

    i = 0;
    printf("\n\n[");
    while (i < dim - 1)
    {
        printf("%d, ", *(ptr + i));
        i++;
    }
    printf("%d]", *(ptr + dim - 1));

    return 0;
}