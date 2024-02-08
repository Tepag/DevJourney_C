/**
 * @file 20231203_e4.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-03
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
    Creare una libreria matematica contenente le funzioni per il:
        - calcolo della potenza
        - massimo comune divisore.
    Scrivere un main() che, ricevuti due valori interi da riga di comando (usando argc e argv[]),
    richiami entrambe le funzioni e stampi il risultato.
*/

#include "matematica.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int n[4];
    int i = 0;
    for (i = 1; i < argc; i++)
    {
        n[i - 1] = *argv[i] - '0';
    }

    printf("\n\n%d\n\n", myPower(n[0], n[1]));

    printf("\n\n%d\n\n", mcd(n[2], n[3]));
}