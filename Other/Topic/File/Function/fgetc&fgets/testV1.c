/**
 * @file testV1.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-01-10
 *
 * @copyright Copyright (c) 2022
 *
 */

// Traccia: apro la directory e vado a cercare se vi sono present file txt, dopodiché vado a fare un fgetc e un un fputc

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void fcpy(FILE *destination, FILE *source);

int main()
{
    DIR *directory = opendir("./");
    struct dirent *fileInfo = NULL;
    FILE *fp = NULL;
    FILE *fpDest = fopen("./testV1_textTot.txt", "w+");
    int box;

    // scorro tutta la directory
    while ((fileInfo = readdir(directory)) != NULL)
    {
        puts(fileInfo->d_name);

        // solo nel caso contenga .txt vado a modificare
        if (strstr(fileInfo->d_name, ".txt") != NULL)
        {
            fp = fopen(fileInfo->d_name, "r+");
            // fputc(6, fp);
            // fseek(fp, -1, SEEK_CUR);
            // box = fgetc(fp);
            // printf("%d", sizeof(int));
            // fseek(fp, 0, SEEK_SET);

            fcpy(fpDest, fp);
            fclose(fp);
        }
    }

    return 0;
}

void fcpy(FILE *destination, FILE *source)
{
    int box;

    /*
    while (1)
    {
        box = fgetc(source);
        if (feof(source) == 1)
        {
            break;
        }
        fputc(box, destination);
    }*/

    while ((box = fgetc(source)) != EOF)
    {
        fputc(box, destination);
    }
}
