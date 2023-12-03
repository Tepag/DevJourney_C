/**
 * @file 20231203_e2.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-03
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
Modificare il programma dell'esercizio precedente affinche' non chieda preventivamente la
dimensione dell'array, ma che aumenti la dimensione dell'array dinamicamente con l'inserimento di
ulteriori dati. L'inserimento termina quando viene inserito da tastiera il numero sentinella 42.
Suggerimento: usate la funzione void *realloc(void *ptr, size_t dim);
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dim;
    int *ptr;
    int i;
    int stopFlag;

    ptr = NULL;
    dim = 0;
    i = 0;
    stopFlag = 0;
    do
    {
        dim++;
        ptr = (int *)realloc(ptr, sizeof(int) * dim);
        printf("\ninserisci un numero: ");
        scanf(" %d", ptr + i);
        fflush(stdin);
        i++;

        printf("\nvuoi inserire un'altro numero? (0 per uscire / 1 per continuare): ");
        scanf(" %d", &stopFlag);
        fflush(stdin);
    } while (stopFlag == 1);

    i = 0;
    printf("\n\n[");
    while (i < (dim - 1))
    {
        printf("%d, ", *(ptr + i));
        i++;
    }
    printf("%d]", *(ptr + dim - 1));

    return 0;
}