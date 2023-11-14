/**
 * @file 0801.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-01-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

typedef struct
{
    InfoFile *array_InfoFile[20];
    int i = 0;

    // per ogni puntatore all'interno dell'array vado a creare un struttura Info file
    /*
    while(readFromSystem!=NULL){
        arrayInfoFile[i] = (Infofile*)malloc(sizeof(InfoFile));
        arrayInfoFile[i].info = readfrom(system)
    }
     */

} Cartella;

typedef struct
{
    char nome[20];
    char dimensione[20];
} InfoFile;

/**
 * @brief dato in entrata il path del file mi crea una struttura composta da più strutture con le informazioni di file
 *
 * @param path
 * @return DIR* puntatore alla struttura formata
 */
DIR *opendir(char *path);

/**
 * @brief dato il puntatore alla dirctory, andrò a fare uno free di tutti i vari campi
 *
 * @param directory
 * @return int
 */
int closedir(DIR *directory);

/**
 * @brief dato in entrata la struttura mi ritorna il puntatore alla struttura scritta nella struttura della directory
 *
 * @param directory
 * @return struct dirent*
 */
struct dirent *readdir(DIR *directory);

// all'interno della struttura directory -> struttura informazioni file -> informazioni file ---tramite la fopen---> struct file

int main()
{

    return 0;
}