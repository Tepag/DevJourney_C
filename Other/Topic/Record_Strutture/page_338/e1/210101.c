/**
 * @file 010121_e1.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief esercizio 1 pagina 338
 * @version 0.1
 * @date 2022-01-01
 *
 * @copyright Copyright (c) 2022
 *
 */

/*Traccia:
crea una struttura che contenga informazioni per ogni posto di uno stadio
*/

#include <stdio.h>
#include <stdlib.h>

#define POSTI_PER_ORIENTAMENTO 1000

typedef struct
{
    char anello;
    char zona;
    char settore;
    char orientamento;
    char posto[POSTI_PER_ORIENTAMENTO];
} Seat;

int main()
{
    Seat *p1 = (Seat *)malloc(sizeof(Seat));

    p1->anello = 'a';
    printf("%c", p1->anello);

    return 0;
}