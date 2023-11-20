/**
 * @file 20231119_e2.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-19
 *
 * @copyright Copyright (c) 2023
 * @record: 24 min 00 sec
 * @errors: la stringa che va a contare anche '\0' nei while
 *
 */

/*
Si scriva un programma che prenda in input da tas?era una stringa numerica e la converta
nel corrispeNvo valore intero. Usare le funzioni!
Controllare che la stringa inserita sia un numero valido.
*/

#include <stdio.h>

#define MAX 20

int check(char str[]);    // funziona che mi controlli che il numero sia valido o meno
int strToInt(char str[]); // funzione che mi converte la stringa ritonrnandomi il valore interno del numero

int main()
{
    char str[MAX];
    printf("inserisci il numero: ");
    fgets(str, MAX - 1, stdin);
    printf("\n%d", strToInt(str));
}

int check(char str[])
{
    int i = 0;
    while (str[i + 1] != '\0')
    {
        if (i == 0 && str[i] == '-')
        {
            i++;
        }
        if (!((int)str[i] - '0' <= 9 && (int)str[i] - '0' >= 0))
        {
            return -1;
        }
        i++;
    }
    return 0;
}

int strToInt(char str[])
{
    int num = 0;
    int negativeFlag = 0;
    int i = 0;

    if (check(str) == -1)
    {
        printf("la stringa inserita è errata");
        return 0;
    }

    if (str[0] == '-')
    {
        negativeFlag = 1;
        i++;
    }
    do
    {
        num *= 10;
        num = num + str[i] - '0';
        i++;
    } while (str[i + 1] != '\0');

    if (negativeFlag)
    {
        num *= -1;
    }
    return num;
}