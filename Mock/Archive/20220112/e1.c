#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

/*
Creare la funzione "readMyLink" che simula il funzionamento di un "collegamento". Ovvero legge un file che contiene il
percorso su disco di un altro file e rende disponibile al chiamante il contenuto del file di destinazione
*/

FILE *readMyLink();

void *readMyLink_V2();

int main()
{
    FILE *fp = readMyLink();
    fclose(fp);
    return 0;
}

FILE *readMyLink()
{
    char *path = (char *)malloc(sizeof(char));
    FILE *fpIn = NULL, *fp = NULL;

    // apro il file contenente il mio path e lo leggo
    fpIn = fopen("percorsoFile", "r+");
    int i = 0, flag = 0;
    while (1)
    {
        path = (char *)realloc(path, (sizeof(char) * (i + 2)));
        if (fread((path + i), sizeof(char), 1, fpIn) == 0)
        {
            break;
        }
    }
    fclose(fpIn);

    // apro il secondo file puntato dal link all'interno del mio file
    fp = fopen(path, "w");
    free(path);
    //! ricordati di chiudere la path

    //! lui richiedede i contenuti e non il file

    //! ricorda di scrivere un commento su cosa vuoi ritornare
    return fp;
}

void *readMyLink_V2()
{
    char *path = (char *)malloc(sizeof(char));
    FILE *fpIn = NULL, *fp = NULL;
    void *datap = (void *)malloc(1);

    // apro il file contenente il mio path e lo leggo
    fpIn = fopen("percorsoFile", "r+");
    int i = 0, flag = 0;
    while (1)
    {
        path = (char *)realloc(path, (sizeof(char) * (i + 2)));
        if (fread((path + i), sizeof(char), 1, fpIn) == 0)
        {
            break;
        }
    }
    fclose(fpIn);

    // apro il secondo file puntato dal link all'interno del mio file
    fp = fopen(path, "w");
    free(path);
    while (1)
    {
        datap = (void *)realloc(path, (i + 2));
        if (fread((datap + i), 1, 1, fpIn) == 0)
        {
            break;
        }
    }
    fclose(fp);

    return datap;
}

/*
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
}*/