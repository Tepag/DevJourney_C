#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Libri
{
    char Titolo[30];
    char Autore[30];
    int n_pagine;
};

typedef struct Libri LIBRI;

LIBRI prova;
LIBRI a[5];

int main()
{
    FILE *f = fopen("prova.txt", "w");
    strcpy(a[0].Autore, "stella");
    strcpy(a[0].Titolo, "prova");
    a[0].n_pagine = 33;

    strcpy(a[1].Autore, "prova");
    strcpy(a[1].Titolo, "prova");
    a[1].n_pagine = 33;

    fwrite(a, sizeof(LIBRI), 2, f);
    fclose(f); // ti sei dimenticato di chiudere il file prima di riaprirlo

    f = fopen("prova.txt", "r+");
    FILE *g = fopen("stella.txt", "w+");

    if (f != NULL)
    {
        if (g != NULL)
        {
            fseek(f, 0, SEEK_SET);
            while (fread(&prova, sizeof(LIBRI), 1, f) > 0) // leggo da f
            {
                printf("\nsono dentro il while");
                if (strcmp(prova.Autore, "prova") == 0) // se sono uguali
                {
                    printf("\nnon scrivo su file");
                }
                else
                {
                    printf("\nscrivo su file");
                    fwrite(&prova, sizeof(LIBRI), 1, g); // scrivo su g
                }
            }
        }
        else
            printf("\nerrore apertura g");
    }
    else
        printf("\nerrore apertura f");
    fclose(f);
    fclose(g);

    f = fopen("prova.txt", "w");  // apro e azzero prova.txt
    g = fopen("stella.txt", "r"); // apro in lettura stella.txt
    if (f)
    {
        if (g)
        {
            if (fread(f, sizeof(LIBRI), 1000, g) == 0)
            {
                printf("ciao");
            }
        }
        else
            printf("\nerrore apertura g");
    }
    else
        printf("\nerrore apertura f");
    fclose(f);
    fclose(g);
}