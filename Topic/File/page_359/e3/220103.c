/**
 * @file 020121.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief Exercise | Record: 00h 54m 59s
 * @version 0.1
 * @date 2022-01-02
 *
 * @copyright Copyright (c) 2022
 *
 */

/*Traccia
scrivi un programma che prende in input il nome del file e una parola chiave e produce in output un file composto dalle sole righe che contengolo la parola chiave
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Funzione che dato riceve in entrata una stringa e ritorna la prima cella della frase
 * @return char* puntatore alla prima cella della frase inserita
 */
char *input_str();

char *readUntilFromFile(FILE *fp);

int main()
{
    // 0. variables
    char charBox;
    char *fileNameP = NULL;
    char *keyP = NULL;
    FILE *fpIn = NULL;
    FILE *fpOut = NULL;
    int line_len = 0;
    char *readedLineP = NULL;

    // 1. input del nome del file e parola chiave
    printf("\ninsert your file name: ");
    fileNameP = input_str();
    fflush(stdin);

    // 2. input della parola chiave da ricercare
    printf("\ninsert key to search: ");
    keyP = input_str();
    fflush(stdin);

    // 3. aprire il file richiesto
    fpIn = fopen(fileNameP, "r");

    // 4. generare un nuovo file composta solo dalle righe che hanno la parola chiave
    fpOut = fopen("result.txt", "w");

    // 4.2 read all file
    while (1)
    {
        if (!fread(&charBox, sizeof(char), 1, fpIn))
        {
            break;
        }
        fseek(fpIn, -1, SEEK_CUR);

        readedLineP = readUntilFromFile(fpIn);
        if (strstr(readedLineP, keyP) != NULL)
        {
            fwrite(readedLineP, sizeof(char), strlen(readedLineP), fpOut);
            fwrite("\n", sizeof(char), 1, fpOut);
        }
    }

    // 4.2 if i found the key to research i write it on the new file

    // 5. chiusura di tutto
    fclose(fpIn);
    fclose(fpOut);

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

char *readUntilFromFile(FILE *fp)
{
    char *str = (char *)malloc(sizeof(char));
    int i = 0, flag = 0;
    for (; flag == 0; i++)
    {
        if (feof(fp) == 1)
        {
            *(str + i) = '\0';
            break;
        }
        str = (char *)realloc(str, (sizeof(char) * (i + 2)));
        fread(str + i, sizeof(char), 1, fp);
        if (*(str + i) == '\n')
        {
            *(str + i) = '\0';
            flag++;
        }
    }
    return str;
}