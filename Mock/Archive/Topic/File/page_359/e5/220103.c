/**
 * @file 0301.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief exercise on book | Record:00h 52m 03s
 * @version 0.1
 * @date 2022-01-03
 *
 * @copyright Copyright (c) 2022
 *
 */

/*Traccia:
Fusione naturale: scrivi una funzione parametrica in grado di fondere due file di interi ordinati in senso crescente in un nuovo file
leggendo tre nomi da input le eventuali. le ripetizioni devono essere eliminate
quindi visualizza sullo schermo i 20 numeri di valore maggiore in modo decrescente
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Funzione che dato riceve in entrata una stringa e ritorna la prima cella della frase
 * @return char* puntatore alla prima cella della frase inserita
 */
char *input_str();

FILE *forge2File(char *fpn1, char *fpn2, char *fpn3);

/**
 * @brief Funzione che copia pari pari da un file ad un'altro
 * @param FILE* puntatore al file sorgente
 * @param FILE* puntatore al file destinatario
 * @return void
 */
void fcpy(FILE *, FILE *);

int main()
{
    char *fpName1 = NULL;
    char *fpName2 = NULL;
    char *fpName3 = NULL;

    // 1. file name 1
    printf("\ninsert the first file name: ");
    fpName1 = input_str();
    fflush(stdin);

    // 2. file name 2
    printf("\ninsert the second file name: ");
    fpName2 = input_str();
    fflush(stdin);

    // 3. file name 3
    printf("\ninsert the second file name: ");
    fpName3 = input_str();
    fflush(stdin);

    forge2File(fpName1, fpName2, fpName3);

    return 0;
}

FILE *forge2File(char *fpn1, char *fpn2, char *fpn3)
{
    char tmpCharBox;
    char tmpCharBox2;
    int exit_flag = 0;

    // 1. open both files to merge
    FILE *fpIn1 = fopen(fpn1, "r");
    FILE *fpIn2 = fopen(fpn2, "r");

    // 2. create the third file
    FILE *fpOut = fopen(fpn3, "w");

    // 3. copy in the third file all content
    fcpy(fpIn1, fpOut);
    fcpy(fpIn2, fpOut);

    // 4. order content
    fseek(fpOut, 0, SEEK_SET);
    for (int i = 0; exit_flag != 1; i++)
    {
        for (int j = i; 1; j++)
        {
            fseek(fpOut, i, SEEK_SET);
            fread(&tmpCharBox, sizeof(char), 1, fpOut);
            {
                exit_flag = 1;
            }
            fseek(fpOut, j, SEEK_SET);
            if (fread(&tmpCharBox2, sizeof(char), 1, fpOut) == 0)
            {
                break;
            }
            if (((int)tmpCharBox2) < ((int)tmpCharBox))
            {
                fseek(fpOut, i, SEEK_SET);
                fwrite(&tmpCharBox2, sizeof(char), 1, fpOut);
                fseek(fpOut, j, SEEK_SET);
                fwrite(&tmpCharBox, sizeof(char), 1, fpOut);
            }
        }
    }

    // 5. cancel all repetitives element

    // 6.where we found space we can delete it

    return NULL;
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

void fcpy(FILE *fp_source, FILE *fp_destination)
{
    char tmp_box;
    while (1)
    {
        if (fread(&tmp_box, sizeof(char), 1, fp_source) == 0)
        {
            break;
        }
        fwrite(&tmp_box, sizeof(char), 1, fp_destination);
    }
}
