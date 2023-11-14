/*
scrivi una funzione ricorsiva che calcola l'operazione di elevamento a potenza sfruttando la seguente sequenza induttiva:
-esponente (x,y)                                    if y == 0
-esponente (x,y) = prodotto(x,esponente(x,y-1))     if y > 0
RECORD: 35m 11s
*/

#include <stdio.h>
#include <stdlib.h>
#include "e3_lib.c"

int main()
{
    int n1 = 0;
    int n2 = 0;

    printf("\ninserisci il numero: ");
    scanf("%d", &n1);
    fflush(stdin);

    printf("\ninserisci l\'esponente: ");
    scanf("%d", &n2);
    fflush(stdin);

    //f_ricorsiva_esponente(n1, n2, 1);
    printf("\n\nil risultato e\' %d", f_ricorsiva_esponente_v2(n1, n2));

    return 0;
}