/**
 * @file FI-2024-02-01_e4.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-16
 *
 * @copyright Copyright (c) 2024
 *
 */

/*
Data  una  lista  dinamica,  una  sua  rotazione  a  destra  fa in modo che l’ultimo valore a destra venga spostato in
testa.
Dopo aver definito un tipo di dato opportuno per rappresentare gli elementi di una lista di interi, si definisca una
funzione che, ricevuta in ingresso una lista con nodi del tipo definito e un valore intero k >= 0, effettui k rotazioni
a destra, per effetto delle quali gli ultimi k elementi della lista sono spostati in testa. Per esempio, data la lista
6 → 8 → 3 → 1 → 10
- Se k = 2 la funzione modificherà la lista spostando in testa gli ultimi due elementi: 1→ 10 → 6 → 8 → 3
- Se k = 1, la funzione sposterà in testa solo l’ultimo elemento: 10 →  6 → 8 → 3 → 1

Nel  caso  in  cui  la  lista  sia  vuota  o  k  sia  maggiore  o  uguale  al  numero  di  nodi  in  essa  contenuti,  la  funzione
restituisce la lista ricevuta in ingresso senza apportare alcuna modifica.
NOTA: verranno premiate soluzioni che prevedano una sola scansione della lista.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} node;

node *rotate(int k, node *head)
{
    node *newHead;
    node *newTail;
    node *curr = head;
    node *prec;
    int cnt = 0;

    if (k == 0 || head == NULL)
    {
        return head;
    }

    while (curr != NULL)
    {
        if (cnt == k)
        {
            newTail = head;
        }

        prec = curr;
        curr = curr->next;
        if (newTail != NULL)
        {
            newTail = newTail->next;
        }

        cnt++;
    }
    printf("\n\n%d\n\n", newTail->value);

    if (newTail == NULL)
    {
        return head;
    }

    prec->next = head;
    newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void printList(node *curr)
{
    if (curr != NULL)
    {
        printf("%d ", curr->value);
        printList(curr->next);
    }
}
int main()
{
    node *head = (node *)malloc(sizeof(node));
    head->value = 1;
    head->next = (node *)malloc(sizeof(node));
    head->next->value = 2;
    head->next->next = (node *)malloc(sizeof(node));
    head->next->next->next = NULL;
    head->next->next->value = 3;

    head = rotate(1, head);

    printList(head);

    return 0;
}