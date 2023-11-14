/**
 * @file 220109.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief Richiamando consecutivamente tre volte la funzione InitAnimale
 * inizializzare altri tre animali quindi ottenendo un vettore di animali.
 * Visualizzare con un ciclo iterativo tutti e 4 gli animali presenti
 * Record 00h 48m 55s
 *
 * @version 0.1
 * @date 2022 - 01 - 09
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

void initAnimaleV2(Animale **, char *, char *, float, int);

int main()
{
    Animale array[3];
    Animale *animali;

    animali = (Animale *)malloc(1);

    for (int i = 0; i < 3; i++)
    {
        initAnimaleV2(&animali, "criceto", "Gino", 2.5, i);
    }

    for (int i = 0; i < 3; i++)
    {
        puts((animali + i)->razza);
        puts((animali + i)->nome);
        printf("%.2f\n", ((animali + i)->peso));
    }

    return 0;
}

void initAnimaleV2(Animale **pointer, char *razza, char *nome, float weight, int cnt)
{
    *pointer = (Animale *)realloc(*pointer, sizeof(Animale) * (cnt + 1));
    strcpy((*pointer + cnt)->nome, nome);
    strcpy((*pointer + cnt)->razza, razza);
    (*pointer + cnt)->peso = weight;
}
