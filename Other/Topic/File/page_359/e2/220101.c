/**
 * @file 010121.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief es. 2 pagina 359 | 00h 14m 47s
 * @version 0.1
 * @date 2022-01-01
 *
 * @copyright Copyright (c) 2022
 *
 */

/*traccia:
scrivi una funzione parametrica in grado di modificare un file di testo di nome miofile letto da disco
in modo tale che, se l'ultimo elemento della linea è una virgola, la linea successiva viene eliminata
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp_InOut = NULL;
    char tmpCharBox;

    // 1. open file in r+
    fp_InOut = fopen("./miofile.txt", "r+");

    // 2.1. read the line
    while (1)
    {
        if (feof(fp_InOut) == 1)
        {
            break;
        }

        // 2.2. if i found ',' at the last character of the line, i cancel the next the next line
        fread(&tmpCharBox, sizeof(char), 1, fp_InOut);
        if (tmpCharBox == '\n')
        {
            fseek(fp_InOut, -2, SEEK_CUR);
            fread(&tmpCharBox, sizeof(char), 1, fp_InOut);
            if (tmpCharBox == ',')
            {
                fseek(fp_InOut, +1, SEEK_CUR);
                while (1)
                {
                    fread(&tmpCharBox, sizeof(char), 1, fp_InOut);
                    if (tmpCharBox == '\n' || feof(fp_InOut) == 1)
                    {
                        break;
                    }
                    else
                    {
                        fseek(fp_InOut, -1, SEEK_CUR);
                        fwrite(" ", sizeof(char), 1, fp_InOut);
                    }
                }
            }
        }
    }

    fclose(fp_InOut);
    return 0;
}