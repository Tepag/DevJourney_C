/**
 * @file e6.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-18
 *
 * @copyright Copyright (c) 2024
 *
 */

/*
Siano dati due file che memorizzano ognuno una sequenza
ordinata di interi positivi con possibili ripetizioni, s1 e s2. Il numero di valori nelle due sequenze non è
noto a priori. A partire da s1 ed s2, si vuole creare una nuova sequenza che fonda i valori di s1 e s2 in
modo ordinato e senza ripetizioni.
Per esempio, se s1= {0 1 3 4 5 5 6 7 7 7 7 8 8} ed s2 = {3 3 3 3 3 3 3 4 5 9},
allora la nuova sequenza sarà
s3 = {0 1 3 4 5 6 7 8 9}.
La nuova sequenza s3 deve essere memorizzata su un nuovo file.

Si scriva una funzione che riceve come parametri i puntatori a tre file distinti: i primi
due memorizzano le due sequenze s1 e s2, sul terzo dovrà essere slavata la nuova funzione.
La funzione dovrà calcolare e scrivere nel terzo file la nuova sequenza s3.
Restituirà all’ambiente chiamante: 1 se il salvataggio della nuova sequenza va a buon fine, 0 altrimenti.


Punto 2 (2 punti). Si definisca il main di un programma (completo di opportune dichiarazioni a livello
globale e locale), che:
- riceva da riga di comando (parametro del main) il nome dei tre file
- invochi la funzione definita al punto precedente
- stampi un messaggio che indichi se il salvataggio della nuova sequenza è andato a buon fin
*/

#include <stdio.h>
#include <stdlib.h>

int merge(FILE *f1, FILE *f2, FILE *fOut)
{
    int box1;
    int box2;
    int written;

    fscanf(f1, "%d", &box1);
    fgetc(f1);

    fscanf(f2, "%d", &box2);
    fgetc(f2);

    if (box1 > box2)
    {
        fprintf(fOut, "%d ", box2);
        written = box2;
    }
    else
    {
        fprintf(fOut, "%d ", box1);
        written = box1;
    }

    while (!feof(f1) && !feof(f2))
    {
        while (box1 <= written)
        {
            fscanf(f1, "%d", &box1);
            fgetc(f1);
        }

        while (box2 <= written)
        {
            fscanf(f2, "%d", &box2);
            fgetc(f2);
        }

        if (box1 > box2)
        {
            if (fprintf(fOut, "%d ", box2) == 0)
            {
                return 0;
            }
            written = box2;
        }
        else
        {
            if (fprintf(fOut, "%d ", box1) == 0)
            {
                return 0;
            }
            written = box1;
        }
    }

    if (box1 > written)
    {
        if (fprintf(fOut, "%d ", box1) == 0)
        {
            return 0;
        }
        written = box1;
    }
    while (!feof(f1))
    {
        fscanf(f1, "%d", &box1);
        fgetc(f1);
        if (box1 > written)
        {
            if (fprintf(fOut, "%d ", box1) == 0)
            {
                return 0;
            }
            written = box1;
        }
    }

    if (box2 > written)
    {
        if (fprintf(fOut, "%d ", box2) == 0)
        {
            return 0;
        }
        written = box2;
    }
    while (!feof(f2))
    {
        fscanf(f2, "%d", &box2);
        fgetc(f2);

        if (box2 > written)
        {
            if (fprintf(fOut, "%d ", box2) == 0)
            {
                return 0;
            }
            written = box2;
        }
    }

    return 1;
}

int main(int argc, char *argv[])
{
    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "r");
    FILE *fOut = fopen(argv[3], "w");

    if (merge(f1, f2, fOut) == 1)
    {
        printf("salvato correttamente");
    }
    else
    {
        printf("errore durante il salvataggio");
    }
}