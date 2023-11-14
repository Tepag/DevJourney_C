/*
calcola le disposizioni  con ripetizione di n elementi in tre posizioni, quindi con ripetizione dello stesso carattere nelle deverse posizioni
le possibili combinazioni sono 27, ottenuto dalla formula n(oggetti) elevato a k(posti)

RECORD: 17m 31s
*/

#include <stdlib.h>
#include <stdio.h>
#include "e8_lib.c"

int main()
{
    int n1 = 0, n2 = 0;

    printf("\ninserire il numero dei oggetti disponibili per le combinazioni:");
    scanf("%d", &n1);
    fflush(stdin);

    printf("\ninserire il numero dei posti disponibili per le combinazioni:");
    scanf("%d", &n2);
    fflush(stdin);

    printf("\n\nil numero di posizioni disponibili sono: %d", power_num(n1, n2));

    return 0;
}
