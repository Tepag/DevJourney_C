/**
 * @file e7.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-03-18
 *
 * @copyright Copyright (c) 2022
 *
 */

/*
Realizzare un programma che gestisca una lista dove ogni nodo è composto da una struttura persona
identificata da nome, cognome, età.
Il programma deve prevedere l'inserimento in coda di nuovi nodi con input da tastiera,
prima di uscire dal programma tutti i nodi devono essere salvati su di un file, successivamente deve essere
possibile caricare i nodi da un file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 30

typedef struct person
{
    char name[DIM];
    char surname[DIM];
    int age;
} Person;

typedef struct item
{
    Person content;
    struct item *next;
} Item;

Person *newPerson();
void addItem(Item **head, Person toAddPerson);
void showItem(Item *head);
void saveAll(Item *head);

Item *loadFromFile();

int main()
{
    int choose = 0;
    Item *head = loadFromFile();
    Person *toAddPerson = NULL;

    while (choose != -1)
    {
        printf("\n1. add");
        printf("\n2. show");
        printf("\n3. saveAll");
        printf("\n0. exit");
        printf("\nchoose:> ");
        scanf("%d", &choose);
        fflush(stdin);

        switch (choose)
        {
        case 0:
            choose = -1;
            saveAll(head);
            break;

        case 1:
            toAddPerson = newPerson();
            addItem(&head, *toAddPerson);
            break;

        case 2:
            showItem(head);
            break;

        case 3:
            saveAll(head);
            break;

        default:
        {
            printf("\nInvalid option");
        }
        }
    }

    return 0;
}

Person *newPerson()
{
    Person *newP = (Person *)malloc(sizeof(Person));

    fflush(stdin);
    printf("\nname:> ");
    scanf("%s", (newP->name));
    fflush(stdin);

    printf("\nsurname:> ");
    scanf("%s", (newP->surname));
    fflush(stdin);

    printf("\nage:> ");
    scanf("%d", &(newP->age));
    fflush(stdin);

    return newP;
}

void addItem(Item **head, Person toAddPerson)
{
    Item *newItem = (Item *)malloc(sizeof(Item));
    newItem->content = toAddPerson;

    if (*head == NULL)
    {
        *head = newItem;
    }
    else
    {
        Item *localPos = *head;
        while (localPos->next != NULL)
        {
            localPos = localPos->next;
        }
        localPos->next = newItem;
    }
}

void showItem(Item *head)
{
    while (head != NULL)
    {
        puts(head->content.name);
        puts(head->content.surname);
        printf("%d\n\n", head->content.age);
        head = head->next;
    }
}

void saveAll(Item *head)
{
    // apro file
    FILE *fpOut = fopen("./save.dat", "wr+");
    rewind(fpOut);

    while (head != NULL)
    {
        // vado a inserire persona
        fwrite(&(head->content), sizeof(Person), 1, fpOut);

        // dopo aver finito continuo col prossimo
        head = head->next;
    }

    fclose(fpOut);
}

Item *loadFromFile()
{
    // apro file
    FILE *fpIn = fopen("./save.dat", "rw+");

    // in caso non esistesse, ritorno null
    if (fpIn == NULL)
    {
        return NULL;
    }

    Item *head = (Item *)malloc(sizeof(Item));
    Item *localPos = head;
    Item *precPos = NULL;

    while (1)
    {
        if (fread(&(localPos->content), sizeof(Person), 1, fpIn) == 0)
        {
            precPos->next = NULL;
            break;
        }
        else
        {
            localPos->next = (Item *)malloc(sizeof(Item));
            precPos = localPos;
            localPos = localPos->next;
        }
    }

    fclose(fpIn);

    return head;
}