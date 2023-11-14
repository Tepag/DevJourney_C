/**
 * @file HowUseDirent.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-01-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <dirent.h>
#include <stdio.h>

int main(void)
{
    // apro per prima cosa la cartella; puntatore alla strutuura della cartella
    DIR *directory = opendir("./");

    // creo un puntatore ad una struttura verrà passato tramite readdir
    struct dirent *fileInfo;

    // giro per ogni nome dei file
    while (1)
    {
        // tramite la readir, mi va a ricavere un puntatore alla struttura delle informazioni del file
        fileInfo = readdir(directory);

        // se la mia fileinfo è vuota, cioè che sono finiti i file esco
        if (fileInfo == NULL)
        {
            break;
        }

        // stampo il campo dell'info del file interessato
        printf("%s\n", fileInfo->d_name);
    }

    // chiusura della directory
    closedir(directory);

    return (0);
}
