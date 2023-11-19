/**
 * @file 20231119_e1.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-19
 *
 * @copyright Copyright (c) 2023
 * @record: 55 min 17 sec (facendolo completo, non avevo l'esercizio precedente)
 */

/*
Modificare il programma del laboratorio precedente (Esercizio 2 - Esami 2.0).
Presentare a schermo il seguente menú:
§ 1 - Calcolare media pesata dei voti
§ 2 - Stampare i dati
§ 3 - Ordinare i dati in ordine alfabetico per nome del professore e stampare
§ 4 - Ordinare i dati per voto crescente e stampare
§ 5 - Uscire

Completare il programma implementando le funzioni richieste dal menú.
NB: le opzioni 3 e 4 possono u?lizzare bubble sort;
l'opzione 3 può utilizzare la funzione strcmp della libreria string.h
*/

#include <stdio.h>
#include <string.h>

#define MAX 20
#define EXAMMAXNUM 4
typedef struct Esame
{
    char nome[MAX];
    char cognomeDoc[MAX];
    int cfu;
    int voto;
} esame;

int getMode();                       // funzione che dato un menu mi ritorna il numero pari a cosa deve fare l'utente
float avarage(esame *ptr, int dim);  // funzione che dato l'array dei voti, mi ritorni i la media dei voti
void nameSort(esame *ptr, int dim);  // funzione che mi ordina l'array per cognome dei prof crescente
void gradeSort(esame *ptr, int dim); // funzione che mi ordina l'array per voto crescente
void printStruct(esame *ptr, int dim);

int main()
{
    int choose;
    int i, j;
    esame examSet[EXAMMAXNUM];

    // blocco di inserimento
    for (i = 0; i < EXAMMAXNUM; i++)
    {
        getchar();
        printf("\ninserisci nome: ");
        fgets(examSet[i].nome, MAX, stdin);
        printf("\ninserisci cognome: ");
        fgets(examSet[i].cognomeDoc, MAX, stdin);
        printf("\ninserisci cfu: ");
        scanf(" %d", &(examSet[i].cfu));
        printf("\ninserisci voto: ");
        scanf(" %d", &(examSet[i].voto));
    }

    // inizio col menu
    do
    {
        choose = getMode();
        switch (choose)
        {
        case 1:
            printf("\nla media è %2f", avarage(&examSet[0], EXAMMAXNUM));
            break;
        case 2:
            printStruct(&examSet[0], EXAMMAXNUM);
            break;
        case 3:
            nameSort(&examSet[0], EXAMMAXNUM);
            break;
        case 4:
            gradeSort(&examSet[0], EXAMMAXNUM);
            break;
        case 5:
            printf("\nuscita in corso");
            break;
        default:
            printf("\nscelta non valida");
        }

    } while (choose != 5);
}
void printStruct(esame *ptr, int dim)
{
    int i = 0;
    for (i = 0; i < dim; i++)
    {
        printf("\nnome: %s", (ptr + i)->nome);
        printf("cognome docente: %s", (ptr + i)->cognomeDoc);
        printf("cfu: %d", (ptr + i)->cfu);
        printf("\nvoto: %d", (ptr + i)->voto);
    }
}

int getMode()
{
    int choose;
    printf("\n\n");
    printf("inserire che si vuole fare usando i numeri:");
    printf("\n1 - Calcolare media pesata dei voti");
    printf("\n2 - Stampare i dati");
    printf("\n3 - Ordinare i dati in ordine alfabetico per nome del professore e stampare");
    printf("\n4 - Ordinare i dati per voto crescente e stampare");
    printf("\n5 - Uscire");
    printf("\n\nscelta: ");

    scanf(" %d", &choose);
    return choose;
}

float avarage(esame *ptr, int dim)
{
    float avarage = 0;
    int i = 0;
    for (i = 0; i < dim; i++)
    {
        avarage += (ptr + i)->voto;
    }
    return avarage / dim;
}

void nameSort(esame *ptr, int dim)
{
    int i = 0;
    int swap = 0;
    char box[MAX];
    do
    {
        swap = 0;
        for (i = 0; i < dim - 1; i++)
        {
            if (strcmp((ptr + i)->cognomeDoc, (ptr + i + 1)->cognomeDoc) > 0)
            {
                strcpy(box, (ptr + i)->cognomeDoc);
                strcpy((ptr + i)->cognomeDoc, (ptr + i + 1)->cognomeDoc);
                strcpy((ptr + i + 1)->cognomeDoc, box);
                swap++;
            }
        }
    } while (swap != 0);
    printStruct(ptr, dim);
}

void gradeSort(esame *ptr, int dim)
{
    int i = 0;
    int j = 0;
    int swap = 0;
    int box = 0;
    do
    {
        swap = 0;
        for (i = 0; i < dim - 1; i++)
        {
            if ((ptr + i)->voto > (ptr + i + 1)->voto)
            {
                box = (ptr + i)->voto;
                (ptr + i)->voto = (ptr + i + 1)->voto;
                (ptr + i + 1)->voto = box;
                swap++;
            }
        }
    } while (swap != 0);
    printStruct(ptr, dim);
}
