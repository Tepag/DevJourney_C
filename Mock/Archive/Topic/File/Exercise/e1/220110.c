/**
 * @file 220110.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief funzione che mi camcelli tutte le "ata" contenute nel file e li scala tutte di posizione
 * @version 0.1
 * @date 2022-01-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief funzione che mi va a scalare lasciando i spazi alla fine
 * @param FILE* puntatore al file
 * @param posizioniDaScalare
 * @return void
 */
void scalo(FILE *, int posizioniDaScalare);

int main()
{
    FILE *fp = NULL;
    char *str = (char *)malloc(sizeof(char) * 40);
    fp = fopen("./220110Text.txt", "r+");

    while (1)
    {
        fscanf(fp, "%s", str);
        fseek(fp, 0, SEEK_CUR); // lo riposiziono per evitare errori
        if (feof(fp) == 1)
        {
            break;
        }
        if (strstr(str, ".exe") != NULL)
        {
            fputc('<', fp);
        }
    }

    // scalo(fp, 3);
    fclose(fp);

    return 0;
}

void scalo(FILE *fp, int posizioniDaScalare)
{
    char box;
    while (1)
    {
        fseek(fp, +posizioniDaScalare, SEEK_CUR); // vado alla lettera successiva
        if (fread(&box, sizeof(char), 1, fp) == 0)
        {
            break;
        }
        fseek(fp, -(posizioniDaScalare + 1), SEEK_CUR);
        fwrite(&box, sizeof(char), 1, fp);
    }
    fseek(fp, -posizioniDaScalare, SEEK_CUR);

    for (int i = 0; i < posizioniDaScalare; i++)
    {
        fputc(' ', fp);
    }
}