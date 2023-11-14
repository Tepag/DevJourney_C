/**
 * @file 0401.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief exercise on book | Record:00h 46m 24s
 * @version 0.2
 * @date 2022-01-04
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

int flen(FILE *fp);

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
    int exitFlagi = 0;
    int exitFlagj = 0;
    int dim = 0;

    // 1. open both files to merge
    FILE *fpIn1 = fopen(fpn1, "r+");
    FILE *fpIn2 = fopen(fpn2, "r+");

    // 2. create the third file
    //! NOTA BENE: solo in apertura in scrittura puoi utilizzare la fseek, in altri casi non te lo fa fare
    FILE *fpOut = fopen(fpn3, "w+");

    // 3. copy in the third file all content
    fcpy(fpIn1, fpOut);
    fcpy(fpIn2, fpOut);

    // 4. order content
    fseek(fpOut, 0, SEEK_SET);
    dim = flen(fpOut);

    for (int i = 0; i < dim; i++)
    {
        for (int j = i; j < dim; j++)
        {

            fseek(fpOut, i, SEEK_SET);
            fread(&tmpCharBox, sizeof(char), 1, fpOut);

            fseek(fpOut, j, SEEK_SET);
            fread(&tmpCharBox2, sizeof(char), 1, fpOut);

            if (strcmp(&tmpCharBox2, &tmpCharBox) < 0)
            {
                fseek(fpOut, i, SEEK_SET);
                fwrite(&tmpCharBox2, sizeof(char), 1, fpOut);
                fseek(fpOut, j, SEEK_SET);
                fwrite(&tmpCharBox, sizeof(char), 1, fpOut);
            }
        }
    }

    // 5. cancel all repetitives element
    fseek(fpOut, 0, SEEK_SET);
    for (int i = 0; i < dim; i++)
    {
        fseek(fpOut, i, SEEK_SET);
        fread(&tmpCharBox, sizeof(char), 1, fpOut);
        fread(&tmpCharBox2, sizeof(char), 1, fpOut);
        if (strcmp(&tmpCharBox2, &tmpCharBox) == 0)
        {
            fseek(fpOut, -1, SEEK_CUR);
            fwrite(" ", sizeof(char), 1, fpOut);
        }
    }

    // 6.where we found space we can delete it
    fclose(fpIn1);
    fclose(fpIn2);
    fclose(fpOut);
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

int flen(FILE *fp)
{
    int cnt = 0;
    char box;
    while (fread(&box, sizeof(char), 1, fp) != 0)
    {
        cnt++;
    }
    return cnt;
}
