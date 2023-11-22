/**
 * @file FI-2023-08-28_e4.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int *values;
    struct Nodo *next;
} nodo;

nodo *getList();                             // funzione che mi ritorna la lista dinamica in entrata
nodo *getOutList(int *ptr, int y, int *dim); // funzione che mi elabora la lista

int main()
{
    nodo *list;
    int y = 10;
    int dim = 0;

    list = getList();
    list = getOutList(list, y, dim);
}

nodo *getList(int *dim)
{
    int cnt;
    int input;
    int *ptr;

    cnt = 1;
    ptr = (int *)malloc(sizeof(int));
    printf("\ninserisci un valore: ");
    scanf("%d", ptr);

    do
    {
        cnt++;
        ptr = realloc(ptr, sizeof(int) * cnt);
        printf("\ninserisci un valore: ");
        scanf("%d", ptr + cnt - 1);
    } while (*(ptr + cnt - 1) != 0);
    *dim = cnt - 1;

    return ptr;
}

nodo *getOutList(int *ptr, int y, int *dim)
{
    int sum = 0;
    int i = 0;

    do
    {
    } while (i < *dim);
}
