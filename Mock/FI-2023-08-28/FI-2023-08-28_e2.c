/**
 * @file FI-2023-08-28_e2.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-18
 *
 * @copyright Copyright (c) 2024
 *
 */

/*
    Si supponga di avere, già presente in memoria (non è quindi
    necessario crearla), una lista che memorizza una sequenza di interi. I nodi della lista sono definiti in base
    al seguente tipo:
    typedef struct nodo {
    int val;
    struct nodo * next;
    } Nodo;
    Si scriva una funzione ricorsiva in C che, ricevuta come parametro la testa della lista, modifichi i valori
    nella lista sommando a ogni elemento il valore dell’elemento precedente. Il primo elemento resta
    invariato.
    Es. : Data la lista 1-> 2-> 10-> 3-> 6 la funzione la modificherà in 1 -> 3 -> 12 -> 13 -> 9
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int val;
    struct nodo *next;
} Nodo;

void addElement(Nodo *head, int newVal)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = (Nodo *)malloc(sizeof(Nodo));
    head = head->next;
    head->val = newVal;
    head->next = NULL;
}

void printList(Nodo *head)
{
    if (head != NULL)
    {
        printf("%d ", head->val);
        printList(head->next);
    }
}

void modifyList(Nodo *prec, Nodo *curr)
{
    if (curr != NULL)
    {
        modifyList(prec->next, curr->next);
        curr->val += prec->val;
    }
}

int main()
{
    Nodo *head = (Nodo *)malloc(sizeof(Nodo));
    head->val = 1;
    head->next = NULL;

    addElement(head, 2);
    addElement(head, 10);
    addElement(head, 3);
    addElement(head, 6);

    modifyList(head, head->next);

    printList(head);

    return 0;
}
