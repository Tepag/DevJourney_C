/**
 * @file 0107.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-01-07
 *
 * @copyright Copyright (c) 2022
 *
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

Animale *initAnimale(Animale *, char *, char *, float);

void initAnimaleV2(Animale **, char *, char *, float);

int main()
{
    Animale *a;

    // a = initAnimale(a, "criceto", "Gino", 2.5);
    initAnimaleV2(&a, "criceto", "Gino", 2.5);

    puts(a->razza);
    puts(a->nome);
    printf("%.2f", a->peso);

    return 0;
}

Animale *initAnimale(Animale *pointer, char *razza, char *nome, float weight)
{
    pointer = (Animale *)malloc(sizeof(Animale));
    strcpy(pointer->nome, nome);
    strcpy(pointer->razza, razza);
    pointer->peso = weight;

    return pointer;
}

void initAnimaleV2(Animale **ppointer, char *razza, char *nome, float weight)
{
    ppointer = (Animale **)malloc(sizeof(Animale));
    strcpy(*ppointer->nome, nome);
    // strcpy(ppointer->razza, razza);
}
