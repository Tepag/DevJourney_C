/**
 * @file test.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-01-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    FILE *fp = fopen("./t.txt", "w+");
    char box;

    fputs("aiccasbcas scayscasc ascascuyasc", fp);
    fclose(fp);

    truncate("./t.txt", 2);

    fp = fopen("./t.txt", "r+");
    while (fread(&box, sizeof(char), 1, fp) > 0)
    {
        printf("%c", box);
    }

    fclose(fp);
    return 0;
}