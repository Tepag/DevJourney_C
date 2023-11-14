#include <stdio.h>
#include <stdlib.h>

/**
 * @brief funzione che mi va a scalare lasciando i spazi alla fine
 * @param FILE* puntatore al file
 * @param int posizioniDaScalare
 * @return void
 */
void scale(FILE *, int);

/**
 * @brief funzione che mi va a copiare il contenuto da un file in un altro
 * @param FILE* puntatore al file destinatario
 * @param FILE* puntatore al file sorgente
 * @return void
 */
void fcpy(FILE *, FILE *);

int main()
{

    return 0;
}

void scale(FILE *fp, int posizioniDaScalare)
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

void fcpy(FILE *destination, FILE *source)
{
    char box;
    while (fread(&box, sizeof(char), 1, source) > 0)
    {
        fwrite(&box, sizeof(char), 1, destination);
    }
}
