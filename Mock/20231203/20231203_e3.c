/**
 * @file 20231203_e3.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-03
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
Realizzare le seguenti funzioni:

ListaNodi inserisci_in_coda(ListaNodi L, int elem);
void printaLista(ListaNodi L);
ListaNodi raddoppia(ListaNodi L);
per, rispettivamente: inserire un elemento in coda alla lista, visualizzare la lista, e raddoppiare ogni
elemento di una data lista.

Esempio:
Lista originale: 5 -> 0 -> 4 -> 2 -> -1
Lista raddoppiata: 5 -> 5 -> 0 -> 0 -> 4 -> 4 -> 2 -> 2 -> -1 -> -1

Suggerimento:
definire il tipo per il nodo e per la lista nel modo seguente:
typedef struct ElemNodo{
    int dato;
    struct ElemNodo * next;
} Nodo;
typedef Nodo * ListaNodi;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} node;

node *inserisci_in_coda(node *ptr, int value);
void printaLista(node *ptr);
node *raddoppia(node *ptr);

int main()
{
    node *ptr;

    ptr = NULL;
    ptr = inserisci_in_coda(ptr, 12);
    inserisci_in_coda(ptr, 11);
    inserisci_in_coda(ptr, 10);
    inserisci_in_coda(ptr, 9);

    raddoppia(ptr);

    printf("\n\n");
    printaLista(ptr);
}

node *inserisci_in_coda(node *ptr, int value)
{
    if (ptr == NULL)
    {
        ptr = (node *)malloc(sizeof(node));
        ptr->value = value;
        ptr->next = NULL;
        return ptr;
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = (node *)malloc(sizeof(node));
    ptr->next->value = value;
    ptr->next->next = NULL;
    return ptr->next;
}

void printaLista(node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->value);
        printaLista(ptr->next);
    }
}

node *raddoppia(node *ptr)
{
    node *first;
    first = ptr;
    node *copy = NULL;
    while (ptr != NULL)
    {
        copy = (node *)malloc(sizeof(node));
        copy->next = ptr->next;
        copy->value = ptr->value;
        ptr->next = copy;
        ptr = ptr->next->next;
    }
    return first;
}
