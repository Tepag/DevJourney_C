/**
 * @file Tepag_220127_V1.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-01-27
 *
 * @copyright Copyright (c) 2022
 *
 */

// Traccia:
/* Creare un programma con due funzioni:
1) aggiunge un elemento in testa alla lista
2) stampa la lista
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct component
{
    int value;
    struct component *next;
} Component;

void addComponent(Component *head, int);
void stmpComponent(Component *pos);
void changeComponentPos(Component *pos, int, int);
void exchangeComponentPos(Component *pos1, Component *pos2);

int main()
{
    Component *header = (Component *)malloc(sizeof(Component));
    header->value = 8;
    header->next = NULL;

    for (int i = 0; i < 10; i++)
    {
        addComponent(header, i);
    }

    stmpComponent(header);
    changeComponentPos(header, 1, 8);
    printf("\n\nafterchage:\n\n");
    stmpComponent(header);

    return 0;
}

void addComponent(Component *head, int val)
{
    Component *pos = head;
    while (pos->next != NULL)
    {
        pos = pos->next;
    }
    // esco e aggiungo il mio elemento
    pos->next = (Component *)malloc(sizeof(Component));
    pos = pos->next;
    pos->value = val;
    pos->next = NULL;
}

void stmpComponent(Component *head)
{
    Component *pos = head;
    while (pos->next != NULL)
    {
        printf("%d", pos->value);
        pos = pos->next;
    }
}

// ! Non funzionante
void changeComponentPos(Component *head, int index1, int index2)
{
    Component *tmpPindex1 = NULL, *tmpPindex1_1 = NULL;
    Component *tmpPindex2 = NULL, *tmpPindex2_1 = NULL;
    Component *pos = head;
    Component *tmp = NULL;
    int cnt = 0;

    // cerco i quattro puntatori che sono rispettivamente alle posizioni index1 index2 e -1
    while (pos->next != NULL)
    {
        if (index1 - index2 == 1)
        {
        }
        if (cnt == (index1 - 1))
        {
            tmpPindex1_1 = pos;
            tmpPindex1 = pos->next;
        }
        if (cnt == (index2 - 1))
        {
            tmpPindex2_1 = pos;
            tmpPindex2 = pos->next;
        }
        pos = pos->next;
        cnt++;
    }

    // sostituisco i due puntatori
    exchangeComponentPos(tmpPindex1_1->next, tmpPindex2_1->next);
    exchangeComponentPos(tmpPindex1->next, tmpPindex2->next);
}

void exchangeComponentPos(Component *pos1, Component *pos2)
{
    Component *tmp;
    tmp = pos1;
    pos1 = pos2;
    pos2 = tmp;
}