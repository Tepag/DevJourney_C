/**
 * @file Tepag_v1_220303.c
 * @author Tepag (z190tpg@gmail.com)
 *
 * @version 0.1
 * @date 2022-03-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    struct list *next;
    int content;
} stList;

/**
 * @brief dato la testa, visualizzare tutta la lista
 *
 */
void listShowAll(stList *);

/**
 * @brief funzione che va a aggiungere in testa
 *
 */
void listPushHead(stList **, int);

/**
 * @brief funzione che va a aggiungere in coda
 *
 */
void listPushTail(stList *, int);

/**
 * @brief funzione che va a cercare il puntatore del compknente cercato
 *
 * @return stList del componente cercato
 */
stList *listSearchIndex(stList *, int);

/**
 * @brief funzione che va a aggiungere un elemento ad un certo index all'interno di una lista
 *
 */
void listPushAtIndex(stList **, int, int);

/**
 * @brief dato la testa, ritorna la dimensione della lista
 *
 * @return int numero della lunghezza della lista
 */
int listLenght(stList *);

/**
 * @brief funzione che mi va a rimuovere un elemento dalla lista
 *
 */
stList *listRemoveAtIndex(stList **, int);

/**
 * @brief funzione che mi va estrarre un elemento dalla testa
 *
 * @return int
 */
int listExtractFromHead(stList **);

/**
 * @brief funzione che mi va a estrarre dalla coda
 *
 * @return int
 */
int listExtractFromTail(stList *);

/**
 * @brief funzione che mi ritorna il numero di in dice di dove si trova il primo numero uguale a quella da ricercare
 *
 * @return int
 */
stList *listSearchContent(stList *, int);

/**
 * @brief funzione che mi ritorna il puntatore che punterà alla struttura alla posizione cercata
 *
 * @return int
 */
stList *listGetAtIndex(stList *, int);

void listChangePosition(stList *, int, int);

/**
 * @brief funzione che mi va a riordinare una lista
 *
 */
void listBubbleSort(stList **, int);

int main()
{
    stList *listHead = (stList *)malloc(sizeof(stList));

    listHead->next = NULL;
    listHead->content = 12;

    listPushHead(&listHead, 32);

    for (int i = 0; i < 7; i++)
    {
        listPushTail(listHead, i);
    }
    listShowAll(listHead);

    printf("\n\n%d ", listExtractFromHead(&listHead));
    printf("%d\n\n", listExtractFromTail(listHead));

    printf("\n\n%d\n\n", listSearchContent(listHead, 1)->content);
    listShowAll(listHead);

    listBubbleSort(&listHead, 1);
    listShowAll(listHead);
}

void listShowAll(stList *head)
{
    if (head != NULL)
    {
        printf("%d ", head->content);
        listShowAll(head->next);
    }
}

void listPushHead(stList **head, int content)
{
    // dato indireizzo della testa vado a ggiornare la nuova testa e vado a inserire il nuovo
    stList *compToAdd = (stList *)malloc(sizeof(stList));
    if (head == NULL)
    {
        compToAdd->content = content;
        compToAdd->next = *head;
        *head = compToAdd;
    }
    else
    {
        compToAdd->content = content;
        compToAdd->next = NULL;
        *head = compToAdd;
    }
}

void listPushTail(stList *head, int content)
{
    stList *currPos = head;
    stList *compToAdd = (stList *)malloc(sizeof(stList));
    compToAdd->content = content;
    compToAdd->next = NULL;

    while (currPos->next != NULL)
    {
        currPos = currPos->next;
    }
    currPos->next = compToAdd;
}

stList *listSearchIndex(stList *head, int index)
{
    int localI = 0;
    for (localI = 0; localI != index; localI++)
    {
        head = head->next;
    }
    return head;
}

void listPushAtIndex(stList **head, int content, int index)
{
    if (index != 0)
    {
        stList *previous = listSearchIndex(*head, index - 1);
        stList *next = listSearchIndex(*head, index);
        stList *compToAdd = (stList *)malloc(sizeof(stList));

        compToAdd->content = content;
        compToAdd->next = next;
        previous->next = compToAdd;
    }
    else
    {
        listPushHead(head, content);
    }
}

int listLenght(stList *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}

stList *listRemoveAtIndex(stList **head, int index)
{
    stList *compToRemove = listSearchIndex(*head, index);
    if (index == 0)
    {
        *head = (*head)->next;
    }
    else
    {
        stList *compToRemovePrev = listSearchIndex(*head, index - 1);
        if (compToRemove->next == NULL)
        {
            compToRemovePrev->next = NULL;
        }
        else
        {
            compToRemovePrev->next = compToRemovePrev->next->next;
        }
    }
    return compToRemove;
}

int listExtractFromHead(stList **head)
{
    int box = (*head)->content;
    (*head) = (*head)->next;
    return box;
}

int listExtractFromTail(stList *head)
{
    int box = 0;
    while (head->next->next != NULL)
    {
        head = head->next;
    }
    box = head->next->content;
    free(head->next->next);
    head->next = NULL;
    return box;
}

stList *listSearchContent(stList *head, int key)
{
    while (head->next->content != key)
    {
        head = head->next;
    }
    return head->next;
}

stList *listGetAtIndex(stList *head, int index)
{
    int cnt = 0;
    while (cnt != index || head != NULL)
    {
        head = head->next;
        cnt++;
    }
    return head;
}

void listChangePosition(stList *head, int index1, int index2)
{
    stList *i1prec = listGetAtIndex(head, index1 - 1);
    stList *i1 = listGetAtIndex(head, index1);
    stList *i2prec = listGetAtIndex(head, index2 - 1);
    stList *i2 = listGetAtIndex(head, index2);
}

void listBubbleSort(stList **head, int choose)
{
    stList *currPos = *head;
    int box;
    int actualLenght;
    int changes = 0;
    int index = 0;

    // lo scorro tutto fino alla dimensione di quelli ordinati
    do
    {
        changes = 0;
        index = 0;
        while (currPos != NULL)
        {
            index++;
            // ogni volta che trovo uno maggiore o minore faccio cambio di posizione
            if (currPos->content > currPos->next->content)
            {
                listPushAtIndex(head, listRemoveAtIndex(head, index)->content);
                changes++;
            }
        }
    } while (changes != 0);
}
