/**
 * @file 220109.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief Richiamando consecutivamente tre volte la funzione InitAnimale
 * inizializzare altri tre animali quindi ottenendo un vettore di animali.
 * Visualizzare con un ciclo iterativo tutti e 4 gli animali presenti
 * Record 00h 17m 15s
 *
 * @version 0.1
 * @date 2022-01-09
 * @copyright Copyright(c) 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 20

typedef struct
{
    char razza[DIM];
    char nome[DIM];
    float peso;
} Animale;

void initAnimaleV1(Animale **, char *, char *, float);

int main()
{
    Animale *a;
    Animale **animali;

    animali = (Animale **)malloc(sizeof(Animale *));

    for (int i = 0; i < 3; i++)
    {
        animali = (Animale **)realloc(animali, sizeof(Animale *) * i + 1);
        initAnimaleV1((animali + i), "criceto", "Gino", 2.5);
    }

    for (int i = 0; i < 3; i++)
    {
        puts((*(animali + i))->razza);
        puts((*(animali + i))->nome);
        printf("%.2f\n", (*(animali + i))->peso);
    }

    return 0;
}

void initAnimaleV1(Animale **ppointer, char *razza, char *nome, float weight)
{
    *ppointer = (Animale *)malloc(sizeof(Animale));
    strcpy((*ppointer)->nome, nome);
    strcpy((*ppointer)->razza, razza);
    (*ppointer)->peso = weight;
}
