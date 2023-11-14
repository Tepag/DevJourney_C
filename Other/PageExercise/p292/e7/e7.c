/*
calcola le disposizioni semplici di n elementi, ottenuti dalla formula n!/(n-k)!, dove n = numero degli oggetti  e k il numero dei posti


RECORD: 22m 09s
*/

#include <stdio.h>
#include <stdlib.h>
#include "e7_lib.c"

int main()
{
    float n = 0;
    float k = 0;

    printf("\ninserire il numero dei posti: ");
    scanf("%f", &k);
    fflush(stdin);

    printf("\ninserire il numero degli oggetti: ");
    scanf("%f", &n);
    fflush(stdin);

    printf("\n\nle posizioni possibili sono: %.2f", disposizioni_poss(n, k));
    return 0;
}