/**
 * @file 220108.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief Esercizio 10 pag 338 | Record: 00h 22m 11s
 * @version 0.1
 * @date 2022-01-08
 *
 * @copyright Copyright (c) 2022
 *
 */

/*Traccia:
scrivi un programma che effettui le operazioni di somma e prodotto tra i numeri complessi.
Leggi i valori e visualizza a video i risultato. Per esempio si inserisca 23,5 + 3,4j e 13,5 - 1,2j
*/

#include <stdio.h>
#include <stdlib.h>

#define DIM 3

typedef struct
{
    int reale;
    char immaginaria[DIM];
} NumeroComplesso;

void NumeroComplesso_init(NumeroComplesso **);

int main()
{
    NumeroComplesso *n1;
    NumeroComplesso *n2;

    // 1. inserimento dei due numeri
    NumeroComplesso_init(&n1);
    printf("%d", n1->reale);

    // 2. scelta se somma o prodotto

    // 3. visualizzazione a video

    return 0;
}

void NumeroComplesso_init(NumeroComplesso **pps)
{
    *pps = (NumeroComplesso *)malloc(sizeof(NumeroComplesso));
    (*pps)->reale = 6;
}