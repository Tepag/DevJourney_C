/**
 * @file 20231203_e5.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-03
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
Scrivere un programma che, usando argc e argv[], riceva da riga di comando il nome di un file di
testo e un numero compreso tra 1 e 2, e visualizzi il file su terminale:
- carattere per carattere se il secondo argomento è "1"
- riga per riga se il numero inserito è "2" (assumere che la lunghezza della riga non superi i 256
caratteri).
Gestire correttamente con un messaggio il caso in cui non si riesca ad aprire il file, e il caso in cui il
numero di argomenti inserito non e' corretto.

Esempio:

testo.txt:
ciao sono un
file di testo 123!

esempio input da terminale:   ./textReader.exe testo.txt 1
output:
ciao sono un
file di testo 123!
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fpIn;
    char tmp;
    int readNumber = 0;

    fpIn = fopen(argv[1], "r");

    do
    {
        readNumber = fscanf(fpIn, "%c", &tmp);
        printf("%c", tmp);
    } while (readNumber != 0);

    return 0;
}