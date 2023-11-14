/**
 * @file e1.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief es. 1 pag. 359 | Record: 00h 44m 04s
 * @version 0.1
 * @date 2022-01-01
 *
 * @copyright Copyright (c) 2022
 *
 */

/*Traccia:
progetta un algoritmo per la sostituzione, in un file di interi, di ogni valore pari con l'intero di valore uguale alla sua metà
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 0. variables
    FILE *fpInOut = fopen("text1", "r+");
    char valor;
    int int_val;

    // 1. open file in read+

    // 2. read
    while (1)
    {
        if (feof(fpInOut) == 1)
        {
            break;
        }

        // 2.1 when i found an even number, replace with his half valor
        fread(&valor, sizeof(char), 1, fpInOut);
        int_val = valor - '0';

        if (int_val % 2 == 0)
        {
            valor = (int_val / 2) + '0';
            fseek(fpInOut, -1, SEEK_CUR);
            fwrite(&valor, sizeof(char), 1, fpInOut);
        }
    }

    fclose(fpInOut);
    return 0;
}
