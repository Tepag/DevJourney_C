/**
 * @file Tepag_v0.1_220203.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-02-03
 *
 * @copyright Copyright (c) 2022
 *
 */

/*
Implementare le due funzioni lucchetto, come descritto nel file allegato.Poi provate con password a
lunghezza crescente ad "aprirli" tentando tutte le combinazioni possibili di caratteri minuscoli dell'alfabeto
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM 26

/* controlla se password è la password corretta, se si ritorna -1, se no ritorna 0 */
int lucchetto1(char *password);

/* controlla se password è la password corretta, se si ritorna -1, se no ritorna 0, se parzialmente corretta ritorna il numero di caratteri corretti */
int lucchetto2(char *password);

int main()
{

    int currentMaxPos = 1;
    int found = 0;
    int cnt = 0;
    int power = 0;
    int nothing = 0;
    char *try = (char *)malloc(sizeof(char) * (currentMaxPos + 1));

    *try = 'a' - 1;
    *(try + 1) = '\0';

    // 1. Unlock del primo lucchetto
    while (cnt < 1)
    {
        printf("\n\nciclo %d", cnt);

        // 1.1. faccio girare tutti i caratteri della malloc space
        /*
        for (int j = 0; j <= currentMaxPos; j++)
        {
            for (int i = 0; i < DIM; i++)
            {
                *(try + j) = ('a' + i);
                puts(try);

                // testo se è giusto
                if (lucchetto1(try) == -1)
                {
                    found = 1;
                }
            }
        }*/

        // inizio dalla ultima posizione
        /*
        for (int i = (currentMaxPos - 1); i >= 0; i++)
        {
            *(try + i)
            // faccio girare
        }*/

        // devo fare girare il ciclo per tutte le combinazioni esistibili al momento
        for (int j = 0; j < pow(DIM, currentMaxPos + 1); j++) // j serve per i caratteri
        {
            // aumento solo al compiere della condizione e nel resto dei casi aumento il primo, RESETTANDO ogni volta che si va oltre il limite
            for (int internalPos = currentMaxPos; internalPos >= 0; internalPos--)
            {
                power = (int)(pow(DIM, internalPos));

                if (j / power == 1 && j % power == 0)
                {
                    printf("\nsono dentro");
                    *(try + internalPos) += 1;

                    // in caso raggiungessi il limite
                    if (*(try + internalPos) > ('a' + DIM))
                    {
                        *(try + internalPos) = 'a';
                    }
                }
            }
            if (nothing == 1)
            {
                *(try + currentMaxPos) += 1;
                nothing = 0;
            }

            printf("\n%s", try);

            if (lucchetto1(try) == -1)
            {
                found = 1;
            }
        }

        // 1.2. incremento e faccio i posizioni successivi
        try = realloc(try, sizeof(char) * (currentMaxPos + 1));
        currentMaxPos++;
        *(try + currentMaxPos) = 'a' - 1;
        *(try + currentMaxPos + 1) = '\0';

        if (found == 1)
        {
            break;
        }
        cnt++;
    }

    return 0;
}

int lucchetto1(char *password)
{
    // controllo se la password inserita è giusta o meno
    char RealPassword[2] = {"cc"};

    if (strcmp(&RealPassword[0], password) == 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}