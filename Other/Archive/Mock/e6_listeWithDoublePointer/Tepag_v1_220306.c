/**
 * @file Tepag_v1_220305.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief funzionce che vada a creare un albero attravverso una struttura componente con doppio puntatore
 * @version 0.1
 * @date 2022-03-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct component
{
    int content;
    struct component *lPtr;
    struct component *rPtr;

} tComp;

void addToRoot(tComp *);
void showTree(tComp *);

int main()
{
    tComp *head = (tComp *)malloc(sizeof(tComp));
    /*
    head->lPtr = (tComp *)malloc(sizeof(tComp));
    head->rPtr = (tComp *)malloc(sizeof(tComp));
    head->lPtr->lPtr = (tComp *)malloc(sizeof(tComp));
    head->content = 1;
    head->lPtr->content = 2;
    head->lPtr->lPtr->content = 5;
    head->lPtr->lPtr->rPtr = NULL;
    head->lPtr->lPtr->lPtr = NULL;
    head->rPtr->content = 3;
    head->rPtr->lPtr = NULL;
    head->rPtr->rPtr = NULL;

    head->lPtr->rPtr = (tComp *)malloc(sizeof(tComp));
    head->lPtr->rPtr->content = 7;
    head->lPtr->rPtr->lPtr = NULL;
    head->lPtr->rPtr->rPtr = NULL;*/
    addToRoot(head);
    showTree(head);

    return 0;
}

void addToRoot(tComp *head)
{
    // la scelta di aggiungere o meno
    int choose = 0;
    printf("\ncontinue (1/0): >_");
    scanf("%d", &choose);
    fflush(stdin);

    if (choose == 1)
    {
        tComp *toAdd = (tComp *)malloc(sizeof(tComp));
        addToRoot(head->lPtr);
        printf("\ninsert content: >_");
        scanf("%d", &(head->content));
        fflush(stdin);
        addToRoot(head->rPtr);
    }
    else
    {
        head->lPtr = NULL;
        head->rPtr = NULL;
    }
}

void showTree(tComp *head)
{
    if (head != NULL)
    {
        showTree(head->lPtr);
        printf("%d ", head->content);
        showTree(head->rPtr);
    }
}