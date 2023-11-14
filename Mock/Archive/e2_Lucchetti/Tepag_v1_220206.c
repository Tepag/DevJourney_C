/**
 * @file Tepag_v1_220204.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-02-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM 26
#define PASSLEN 4

/* controlla se password è la password corretta, se si ritorna -1, se no ritorna 0 */
int lucchetto1(char *password);

/* controlla se password è la password corretta, se si ritorna -1, se no ritorna 0, se parzialmente corretta ritorna il numero di caratteri corretti */
int lucchetto2(char *password);

int main()
{
    char pass[PASSLEN] = {"aaaa"};
    int index = 0;
    int CurrentCorrect = 0;

    // 1. funzione che mi vada a sbloccare lucchetto1

    // 1.1. funzione che mi sblocchi la prima con una stringa lunga 4
    /*
    for (int i = 0; i < DIM; i++)
    {
        pass[0] = 'a' + i;
        for (int o = 0; o < DIM; o++)
        {
            pass[1] = 'a' + o;
            for (int p = 0; p < DIM; p++)
            {
                pass[2] = 'a' + p;
                for (int l = 0; l < DIM; l++)
                {
                    pass[3] = 'a' + l;
                    puts(&pass[0]);
                    if (lucchetto1(&pass[0]) == -1)
                    {
                        printf("found");
                        exit(1);
                    }
                }
            }
        }
    }*/

    // 2. funzione che mi vada a sbloccare il secondo lucchetto
    for (index = 0; index < PASSLEN; index++)
    {
        for (int i = 0; i < DIM; i++)
        {
            pass[index] = 'a' + i;

            if (lucchetto2(&pass[0]) == -1)
            {
                printf("found");
                exit(1);
            }
            else
            {
                if (lucchetto2(&pass[0]) > CurrentCorrect)
                {
                    CurrentCorrect += 1;
                    break;
                }
            }
        }
    }

    puts(&pass[0]);

    return 0;
}

int lucchetto1(char *password)
{
    // controllo se la password inserita è giusta o meno
    char RealPassword[PASSLEN + 1] = {"bzad"};
    RealPassword[PASSLEN] = '\0';

    if (strcmp(&RealPassword[0], password) == 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int lucchetto2(char *password)
{
    // controllo se la password inserita è giusta o meno
    char RealPassword[PASSLEN + 1] = {"abcd"};
    RealPassword[PASSLEN] = '\0';
    int index = 0;
    char *tmpP = NULL;
    int cnt = 0;

    if (strcmp(&RealPassword[0], password) == 0)
    {
        return -1;
    }
    else
    {
        // scrivo quanti caratteri all'interno sono giusti:
        for (int i = 0; i < PASSLEN; i++)
        {
            printf("\n%c == %c", RealPassword[i], password[i]);
            if (RealPassword[i] == password[i])
            {
                cnt++;
            }
        }
        printf("\n\n--- count: %d ---\n\n", cnt);
        return cnt;
    }
}