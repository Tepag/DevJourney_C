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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp = NULL;
    char string[40];
    fp = fopen("./testV1Text.txt", "r+");

    // fscanf(fp, "%s", &string[0]);
    fprintf(fp, "%c", ' ');
    // puts(&string[0]);

    fclose(fp);

    return 0;
}