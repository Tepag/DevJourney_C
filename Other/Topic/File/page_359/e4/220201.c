/**
 * @file 0201.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief Esercise | Record 00h 15m 12s
 * @version 0.1
 * @date 2022-01-02
 *
 * @copyright Copyright (c) 2022
 *
 */

/*Traccia:
Scrivi un programma che prende in input il nome del file ed effetua la copia dello stesso in un secondo file, in cui i nomi dei due file sono lettin in input
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Funzione che dato riceve in entrata una stringa e ritorna la prima cella della frase
 * @return char* puntatore alla prima cella della frase inserita
 */
char *input_str();

int main()
{
    char *SourcefileName = NULL;
    char *DestinationFileName = NULL;
    FILE *fpS = NULL;
    FILE *fpD = NULL;
    char charBox;

    // 1. input name file to open
    // 1.1 file name to open
    printf("insert the name of file which you want to copy: ");
    SourcefileName = input_str();
    fflush(stdin);

    // 1.2 file name to create for destination
    printf("insert the name of file which you want to copy: ");
    DestinationFileName = input_str();
    fflush(stdin);

    // 2. open both files and copy the origin file content to destination file
    // 2.1 open original file in read
    fpS = fopen(SourcefileName, "r");
    free(SourcefileName);

    // 2.2 open/create the file in w
    fpD = fopen(DestinationFileName, "w");
    free(DestinationFileName);

    // 2.3 copy content
    while (1)
    {
        if (feof(fpS))
        {
            break;
        }
        fread(&charBox, sizeof(char), 1, fpS);
        fwrite(&charBox, sizeof(char), 1, fpD);
    }

    // close all
    fclose(fpD);
    fclose(fpS);
    return 0;
}

char *input_str()
{
    char *str = (char *)malloc(sizeof(char));
    int i = 0, flag = 0;
    for (; flag == 0; i++)
    {
        str = (char *)realloc(str, (sizeof(char) * (i + 2)));
        *(str + i) = getchar();
        if (*(str + i) == '\n')
        {
            *(str + i) = '\0';
            flag++;
        }
    }
    return str;
}