/**
 * @file 0108.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-01-08
 *
 * @copyright Copyright (c) 2022
 *
 */

// Traccia: andare a simulare la funzione di dirent.h, open, read e close

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

typedef struct()
{
    int v1 = 1;
}
Hellow;

int main()
{
    DIR *directory1;
    struct dirent *fileInfo;
    directory1 = opendir("./");

    while ((fileInfo = readdir(directory1)) != NULL)
    {
        puts(fileInfo->d_name);
    }

    closedir(directory1);
    return 0;
}

// DIR apro praticamente le informazioni del directory
// struct dirent è una struttura che contiene le informazioni del file
//