/**
 * @file Tepag_v0.4_220130.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.4
 * @date 2022-01-30
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct component
{
    int value;
    struct component *next;
} Component;

/**
 * @brief funzione che aggiunge un elemento in testa alla lista
 *
 * @param {Component*} puntatore del componente da utilizzare come base per aggiungere un componente
 * @param {int} valore da aggiungere nel nuovo componente
 *
 * @return void
 */
void addComponentToTail(Component *, int);

/**
 * @brief funzione che aggiunge un elemento in coda alla lista
 *
 * @param {Component*} puntatore a un componente qualsiasi della lista
 * @param {int} valore da aggiungere nel nuovo componente
 *
 * @return Component* nuova testa
 */
Component *addComponentToHead(Component *, int);

/**
 * @brief funzione che stampa i valori di una lista
 *
 * @param {Component*} la testa da cui iniziare a leggere
 *
 * @return void
 */
void stmpComponent(Component *);

/**
 * @brief Funzione che scambia due elementi di una lista
 *
 * @param {Component*} puntatore alla struttura componente della list; RICORDA che il componente è riconosciuto come primo
 * @param {int} indice del primo elemento
 * @param {int} indice del secondo elemento
 *
 * @return void
 */
void changeComponentPos(Component **, int, int);

/**
 * @brief funzione che dati due componenti scabia i loro indirizzi next
 *
 * @param {Component*} componente da scambiare 1
 * @param {Component*} componente da scambiare 2
 *
 * @return void
 */
void exchangeComponentNext(Component *, Component *);

int main()
{
    Component *header = (Component *)malloc(sizeof(Component));

    header = addComponentToHead(NULL, 7);

    for (int i = 0; i < 10; i++)
    {
        addComponentToTail(header, i);
    }

    stmpComponent(header);
    // changeComponentPos(&header, 0, 1);
    changeComponentPos(&header, 2, 5);

    printf("\n\nafterchage:\n\n");
    stmpComponent(header);

    return 0;
}

void addComponentToTail(Component *head, int val)
{
    Component *pos = head;

    // vado avanti fino a trovare la coda
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

Component *addComponentToHead(Component *head, int val)
{
    Component *newComponentToAdd = (Component *)malloc(sizeof(Component)); // creazione del componente da aggiungere

    /*introduzione della nuova testa, attaccandolo alla vecchia testa*/
    newComponentToAdd->next = head;
    newComponentToAdd->value = val;

    return newComponentToAdd; // ritorno della testa aggiornata
}

void stmpComponent(Component *head)
{
    Component *pos = head; // crazione di un puntatore interno

    /*stampo il valore della struttura fino alla fine della lista*/
    while (pos->next != NULL)
    {
        printf("%d", pos->value);
        pos = pos->next;
    }
}

// ! NON FUNZIONANTE CON CERTI INDIRIZZI
// con testa e coda
void changeComponentPos(Component **head, int index1, int index2)
{
    Component *tmpPindex1 = NULL, *tmpPindex1_1 = NULL; // puntatore al componente e il componente che lo procede
    Component *tmpPindex2 = NULL, *tmpPindex2_1 = NULL; // puntatore al componente e il componente che lo procede
    Component *pos = *head;                             // puntatore interno
    int cnt = 0;                                        // contatore che mi tiene conto a che posizione sono

    // cerco i quattro puntatori che sono rispettivamente alle posizioni index1 index2 e -1
    while (pos != NULL)
    {
        if (cnt == (index1 - 1))
        {
            tmpPindex1_1 = pos;
            tmpPindex1 = (pos->next);
        }
        if (cnt == (index2 - 1))
        {
            tmpPindex2_1 = pos;
            tmpPindex2 = (pos->next);
        }
        pos = pos->next;
        cnt++;
    }

    exchangeComponentNext(tmpPindex1_1, tmpPindex2_1);
    if (tmpPindex1_1 == NULL)
    {
        *head = tmpPindex1;
    }
    if (tmpPindex2_1 == NULL)
    {
        *head = tmpPindex2;
    }
    exchangeComponentNext(tmpPindex1, tmpPindex2);
}

void exchangeComponentNext(Component *pos1, Component *pos2)
{
    Component *tmp = NULL;
    tmp = pos1->next;
    pos1->next = pos2->next;
    pos2->next = tmp;
}