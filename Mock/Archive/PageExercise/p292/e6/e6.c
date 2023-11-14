/*
scrivi una funzione ricorsiva per effettuare il calcolo del coefficiente binomiale e rappreentalo per n=10
fattoriale == !
formula = !n / (!k * !(n-k))

RECORD: 35m 15s
*/

#include <stdio.h>
#include <stdlib.h>
#include "e6_lib.c"

int main()
{
    int k = 0;
    int n = 10;

    printf("inserire la k per cercare il coefficiente binomiale (n,default 10):");
    scanf("%d", &k);
    fflush(stdin);

    /*
    printf("\ninserire la n per cercare il coefficiente binomiale:");
    scanf("%d", &n);
    fflush(stdin);
    */

    printf("\nil coefficiente binomiale di n=%d e k=%d e\' pari a: %d", n, k, coefficiente_binomiale(n, k));

    return 0;
}
