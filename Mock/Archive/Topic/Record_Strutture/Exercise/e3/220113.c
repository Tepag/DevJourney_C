/**
 * @file 220113.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-01-13
 *
 * @copyright Copyright (c) 2022
 *
 */

/*Traccia
Creare un programma C che salva un elenco di libri,
ogni libro è identificato da Titolo, Autore, n_pagine.

Il programma deve dare le seguenti possibilità:
1- acquisizione dati di un libro e salvataggio in un file.
2- lista dei libri presenti su file.
3- ricerca di un libro per autore.
4- Cancellazione di un libro identificato per titolo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 21

// creazione della struttura
typedef struct
{
    char title[DIM];
    char author[DIM];
    int nPages[DIM];
} Libro;

void LibroAddNew();

void LibroShowLibrary();

Libro *LibroSrc(char *);

void LibroDeleteBook(char *);

int main()
{
    char *keyword = (char *)malloc(sizeof(char) * DIM);
    Libro *bookPointer = NULL;

    // 1- acquisizione dati di un libro e salvataggio in un file.
    LibroAddNew();

    // 2- lista dei libri presenti su file.
    LibroShowLibrary();

    // 3- ricerca di un libro per autore.
    printf("\ninserire l'autore che si vuole cercare:");
    fflush(stdin);
    fgets(keyword, DIM, stdin);
    fflush(stdin);
    bookPointer = LibroSrc(keyword);
    puts(bookPointer->title);

    // 4- Cancellazione di un libro identificato per titolo.
    printf("\ninserire l'autore che si vuole cancellare:");
    fflush(stdin);
    fgets(keyword, DIM, stdin);
    fflush(stdin);
    LibroDeleteBook(keyword);

    return 0;
}

void LibroAddNew()
{
    Libro *pointer = (Libro *)malloc(sizeof(Libro) * 1);
    FILE *fpOut = NULL;

    // ricavo i dati da inserire
    printf("\ninserire titolo: ");
    fgets(pointer->title, DIM, stdin);
    fflush(stdin);

    printf("\ninserire il titolo: ");
    fgets(pointer->author, DIM, stdin);
    fflush(stdin);

    printf("\ninserire il numero di pagine: ");
    scanf("%d", pointer->nPages);
    fflush(stdin);

    // immettere i dati nel file;
    fpOut = fopen("./libreria.dat", "a+");

    fwrite(pointer, sizeof(Libro), 1, fpOut);
    free(pointer);

    fclose(fpOut);
}

void LibroShowLibrary()
{
    Libro *tmp = (Libro *)malloc(sizeof(Libro) * 1);
    FILE *fpIn = NULL;

    // apro il file e lo leggo
    fpIn = fopen("./libreria.dat", "r+");

    while (1)
    {
        if (fread(tmp, sizeof(Libro), 1, fpIn) == 0)
        {
            break;
        }
        printf("titolo: %sautore: %snumero pagine: %d\n", tmp->title, tmp->title, *(tmp->nPages));
    }

    fclose(fpIn);
    free(tmp);
}

Libro *LibroSrc(char *KeyWord)
{
    Libro *tmp = (Libro *)malloc(sizeof(Libro) * 1);
    FILE *fpIn = NULL;

    // apro il file e leggo per ogni struttura il nome che dovroò confrontare
    fpIn = fopen("./libreria.dat", "r+");

    while (1)
    {
        if (fread(tmp, sizeof(Libro), 1, fpIn) == 0)
        {
            break;
        }
        if (strcmp(tmp->author, KeyWord) == 0)
        {
            fclose(fpIn);
            return tmp;
        }
    }

    fclose(fpIn);
    free(tmp);
    return NULL;
}

void LibroDeleteBook(char *KeyWord)
{
    Libro *tmp = (Libro *)malloc(sizeof(Libro) * 1);
    FILE *fpIn = NULL;
    FILE *fptmp = NULL;
    FILE *fpOut = NULL;

    // apro il file e leggo per ogni struttura il nome che dovroò confrontare
    fpIn = fopen("./libreria.dat", "r+");
    fptmp = fopen("./tmp.dat", "w+");

    // copio tutto tranne quello cercato
    while (1)
    {
        if (fread(tmp, sizeof(Libro), 1, fpIn) == 0)
        {
            break;
        }
        if (strcmp(tmp->author, KeyWord) != 0)
        {
            fwrite(tmp, sizeof(Libro), 1, fptmp);
        }
    }

    fclose(fpIn);

    // copio dalla temporanea nel file dove ho preso i contenuti utilizzando la apertura in write per cancellare il tutto
    rewind(fptmp); // mi retto alla posizione iniziale
    fpOut = fopen("./libreria.dat", "w+");

    while (1)
    {
        if (fread(tmp, sizeof(Libro), 1, fptmp) == 0)
        {
            break;
        }
        fwrite(tmp, sizeof(Libro), 1, fpOut);
    }

    remove("./tmp.dat");
    fclose(fpOut);
    free(tmp);
}