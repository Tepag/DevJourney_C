/*
Argomenti pro verifica di laboratorio del 21.04:
-> Lettura/scrittura su file tramite fwrite/fread.
-> Creazione di lista semplice (nodo con informazioni e *next).
-> Gestione lista: inserimento in testa, inserimento in coda, inserimento interno; estrazione dalla testa, estrazione dalla coda, estrazione interna.
-> Creazione lista strutturata (nodo con struttura di informazioni e *next).
-> Lettura e scrittura su file di una lista strutturata.
-> ricerca di un nodo (valore massimo o minimo, ricerca per valore specifico [int o stringa]).
-> concatenazione tra due liste.
-> split di una lista in due o più liste.
-> merge di due liste secondo un criterio dato (ordine alfabetico o numerico, etc)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct scontent
{
    int c1;
    char c2;
} SContent;

typedef struct item
{
    SContent content;
    struct item *next;
} Item;

/**
 * @brief create and return the new SContent with his fields
 * @param int the first field
 * @param char the second field
 * @return SContent* to new structure
 */
SContent *newContent(int, char);

/**
 * @brief add a new element to the head of my list
 *
 * @param Item** pointer to pointer to the first of my list
 * @param cont what content should I add?
 *
 * @return void
 */
void pushHead(Item **root, SContent cont);

/**
 * @brief function which add an component at the tail of my list
 *
 * @param Item* pointer to the first of my list
 * @param cont what content should I add?
 *
 * @return void
 */
void pushTail(Item *root, SContent cont);

/**
 * @brief pop the head of my list
 *
 * @param Item* pointer to the first of my list
 *
 * @return Item* pointer to the removed component
 */
Item *popHead(Item **root);

/**
 * @brief pop the tail of my list
 *
 * @param Item* pointer to the first of my list
 *
 * @return Item* pointer to the removed component
 */
Item *popTail(Item **root);

/**
 * @brief Function that let you see all list from the root
 *
 * @param Item* root pointer
 *
 * @return void
 */
void viewList(Item *root);

/**
 * @brief Function which save your list into a file
 *
 * @param Item* root
 *
 * @return void;
 */
void saveToFile(Item *root);

/**
 * @brief Function which read list from file
 *
 * @return Item* the readed root
 */
Item *readFromFile();

/**
 * @brief Function that let you search an item by index
 *
 * @param Item* root
 * @param int index
 * @return Item* pointer to the searched component
 */
Item *srcItemByIndex(Item *root, int index);

/**
 * @brief Function that split your list in two pieces
 *
 * @param Item* root
 * @param int index that you want to break the first list and start the second
 * @return Item* pointer which point the start of the second part of the list
 */
Item *splitList(Item *root, int splitPos);

/**
 * @brief Function similiar to strcat, but with lists
 *
 * @param Item* first root
 * @param Item* second root
 *
 * @return void
 */
void listCat(Item *it1, Item *it2);

/**
 * @brief Function that return how long is your list
 *
 * @param Item* root
 * @return int the size of the list
 */
int listGetSize(Item *root);

/**
 * @brief function that let you change two component in the list
 *
 * @param Item* root
 * @param int index of the first element
 * @param int index of the second element
 *
 * @return void
 */
void listChangePos(Item **root, int i1, int i2);

/**
 * @brief Function that sort lists with bubble sort
 *
 * @param Item** pointer to pointer to root
 * @param int if you put one, you can reverse the sort
 *
 * @return void
 */
void listBubbleSort(Item **root, int reverse);

/**
 * @brief function that merge two lists, with order
 *
 * @param Item** pointer to pointer to root 1
 * @param Item** pointer to pointer to root 2
 *
 * @return void
 */
void listGeneralMerge(Item **it1, Item **it2);

int main()
{
    int i = 0;
    Item *root = readFromFile();
    Item *root2 = readFromFile();

    printf("\n\n");
    viewList(root);

    SContent *cPointer = NULL;

    for (i = 0; i < 6; i++)
    {
        cPointer = newContent(i * 3, 'c');
        pushHead(&root, *cPointer);
        free(cPointer);
    }

    // viewList(root);
    // saveToFile(root);

    return 0;
}

SContent *newContent(int c1, char c2)
{
    SContent *newConPointer = (SContent *)malloc(sizeof(SContent));
    newConPointer->c1 = c1;
    newConPointer->c2 = c2;
    return newConPointer;
}

void pushHead(Item **root, SContent cont)
{
    Item *newItem = (Item *)malloc(sizeof(Item));
    newItem->content = cont;
    newItem->next = NULL;

    if (*root == NULL)
    {
        *root = newItem;
    }
    else
    {
        newItem->next = *root;
        *root = newItem;
    }
}

void pushTail(Item *root, SContent cont)
{
    Item *newItem = (Item *)malloc(sizeof(Item));
    newItem->content = cont;
    newItem->next = NULL;

    while (root->next != NULL)
    {
        root = root->next;
    }

    root->next = newItem;
}

Item *popHead(Item **root)
{
    Item *returnValue = *root;
    *root = (*root)->next;

    returnValue->next = NULL;
    return returnValue;
}

Item *popTail(Item **root)
{
    Item *internalPos = *root;
    Item *returnValue = NULL;

    while (internalPos->next->next != NULL)
    {
        internalPos = internalPos->next;
    }
    returnValue = internalPos->next;
    internalPos->next = NULL;

    returnValue->next = NULL;
    return returnValue;
}

void viewList(Item *root)
{
    if (root != NULL)
    {
        printf("%d\n", root->content.c1);
        viewList(root = root->next);
    }
}

void saveToFile(Item *root)
{
    FILE *fpOut = fopen("./archive.dat", "w+");

    while (root != NULL)
    {
        fwrite(&(root->content), sizeof(SContent), 1, fpOut);
        root = root->next;
    }

    fclose(fpOut);
}

Item *readFromFile()
{
    FILE *fpIn = fopen("./archive.dat", "r+");
    Item *root = (Item *)malloc(sizeof(Item));
    Item *currentPos = root;
    Item *currentPosPrec;

    while (1)
    {
        if (fread(&(currentPos->content), sizeof(SContent), 1, fpIn) == 0)
        {
            break;
        }
        currentPos->next = (Item *)malloc(sizeof(Item));
        currentPosPrec = currentPos;
        currentPos = currentPos->next;
        currentPos->next = NULL;
    }
    free(currentPosPrec->next);
    currentPosPrec->next = NULL;

    fclose(fpIn);
    return root;
}

Item *srcItemByIndex(Item *root, int index)
{
    int cnt = 0;
    while (cnt != index)
    {
        if (root == NULL)
        {
            return 0;
        }
        root = root->next;
        cnt++;
    }
    return root;
}

Item *splitList(Item *root, int splitPos)
{
    Item *splitterPrec = srcItemByIndex(root, splitPos - 1);
    Item *splitter = splitterPrec->next;
    splitterPrec->next = NULL;

    return splitter;
}

void listCat(Item *it1, Item *it2)
{
    while (it1->next != NULL)
    {
        it1 = it1->next;
    }
    it1->next = it2;
}

int listGetSize(Item *root)
{
    int cnt = 0;
    while (root != NULL)
    {
        root = root->next;
        cnt++;
    }
    return cnt;
}

void listChangePos(Item **root, int i1, int i2)
{
    Item *precItem1 = srcItemByIndex(*root, i1 - 1);
    Item *item1 = srcItemByIndex(*root, i1);
    Item *precItem2 = srcItemByIndex(*root, i2 - 1);
    Item *item2 = srcItemByIndex(*root, i2);
    Item *tmpBox = NULL;

    if (item1 != NULL && item2 != NULL)
    {
        if (precItem2 != NULL)
        {
            precItem2->next = item1;
        }
        else
        {
            *root = item1;
        }

        if (precItem1 != NULL)
        {
            precItem1->next = item2;
        }
        else
        {
            *root = item2;
        }

        Item *tmp = item1->next;
        item1->next = item2->next;
        item2->next = tmp;
    }
}

void listBubbleSort(Item **root, int reverse)
{
    // controllo se ci sono scambi dispobili
    Item *currentPos = *root;
    int scambi = 0;
    int index = 0;
    int notSortedDim = listGetSize(*root);

    do
    {
        currentPos = *root;
        scambi = 0;
        // ciclo interno che mi vada a conforntare se sono dispobinnili scambi con quello successivo
        for (index = 0; index < (notSortedDim - 1); index++)
        {
            currentPos = srcItemByIndex(*root, index);

            // ! modifica qua per il criterio di ordinamento
            if (reverse == 1)
            {
                if (currentPos->content.c1 < currentPos->next->content.c1)
                {
                    listChangePos(root, index, index + 1);
                    scambi++;
                }
            }
            else
            {
                if (currentPos->content.c1 > currentPos->next->content.c1)
                {
                    listChangePos(root, index, index + 1);
                    scambi++;
                }
            }
        }

        notSortedDim--;
    } while (scambi != 0);
}

void listGeneralMerge(Item **it1, Item **it2)
{
    listCat(*it1, *it2);
    listBubbleSort(it1, 1);
}

// simple try