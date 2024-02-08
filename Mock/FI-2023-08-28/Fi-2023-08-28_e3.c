/**
 * @file Fi-2023-08-28_e3.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-18
 *
 * @copyright Copyright (c) 2024
 *
 */

/*
Si supponga di avere, già presente in memoria, l’array
iniziale di dimensione massima predefinita N, che memorizza una sequenza di caratteri. Tale
sequenza può includere sotto-sequenze delimitate da parentesi tonde.
Esempio di sequenza memorizzata dall’array iniziale[N]:
A X ( c d c d c g c ) b e ( b a b a d e a f a k a) F ( x x ) j
Si scriva una funzione in C che, ricevuto come parametro l’array iniziale, crei e restituisca
all’ambiente chiamante un secondo array, finale, in cui a ogni sotto-sequenza delimitata da parentesi
tonde si sostituisca il carattere che nella sotto-sequenza compare più frequentemente.
Il nuovo array deve avere una dimensione strettamente necessaria a contenere i suoi elementi.
Esempio: dato l’array iniziale riportato sopra, il nuovo array creato dalla funzione memorizzerà la
sequenza
A X ( c ) b e ( a ) F ( x ) j
e la sua dimensione sarà 15.
Si può supporre che la sequenza di caratteri memorizzata nella lista sia ben formata e cioè che: i) per
ogni parentesi che apre una sotto-sequenza ce ne sia una successiva che la chiude; ii) non ci siano
intersezioni tra coppie di parentesi.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 40

char *zip(char str[])
{
    char *newOne = (char *)malloc(sizeof(char));
    char maxChar = str[0];
    int maxCount = 1;
    int localCount = 0;
    char localChar;
    int k = 0;
    int j = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        j = 0;
        if (str[i] == '(')
        {
            maxCount = 0;
            maxChar = str[i + 1];
            j = i + 1;

            while (str[j] != ')')
            {
                k = j;
                localChar = str[j];
                localCount = 0;
                while (str[k] != ')')
                {
                    if (str[k] == localChar)
                    {
                        localCount++;
                    }
                }

                if (localCount > maxCount)
                {
                    maxChar = localChar;
                    maxCount = localCount
                }
            }
        }
    }
}

int main()
{
    char arr[N] = {'A', 'X', '(', 'c', 'd', 'c', 'd', 'c', 'g', 'c', ')', 'b', 'e', '(', 'b', 'a', 'b', 'a', 'd', 'e', 'a', 'f', 'a', 'k', 'a', ')', 'F', '(', 'x', 'x', ')', 'j', '\n'};
    for (int i = 0; i < N; i++)
    {
        printf("%c ", arr[i]);
    }
}
