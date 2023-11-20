/**
 * @file 20231119_e5V3.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 * @record: 9 min 52 sec
 *
 */

/*
Si realizzi un programma che verifichi la corre^a soluzione della griglia di un Sudoku. Un
Sudoku è una griglia 9x9 che rispetta queste caratteristiche:

§ tuN i valori devono essere singoli numeri tra 1 e 9
§ su ciascuna delle 9 righe non devono esserci valori ripetu?
§ su ciascuna delle 9 colonne non devono esserci valori ripetu?
§ in ciascuno dei 9 blocchi 3x3 che compongono la griglia non devono esserci valori
ripetu?

L'esercizio è da risolvere svolgendo un livello dopo l'altro, secondo questa sequenza:

Livello 1 – U?lizzare il file sudoku_template.c fornito assieme a questo testo come punto di
partenza: il file con?ene la dichiarazione di due matrici Sudoku da verificare (una corre^a e
l'altra sbagliata). Il programma deve verificare la validità di queste due matrici e stampare a
video il risultato del controllo. In questo livello il programma va scri^o usando le funzioni
(quindi completando solo il main() già esistente) e dividendo il problema assegnato in
so^oproblemi.

Livello 2 – Modificare il programma già scri^o in modo che la matrice da verificare venga
acquisita numero per numero, e che venga eseguito il controllo di validità già in fase di
inserimento.

(Bonus) Livello 3 – Modificare il programma già scri^o in modo che la matrice da verificare
venga le^a dal file di testo sudoku.txt fornito assieme a questo testo.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 9

int checkUntilLast(int mat[][N], int last, int i, int j);

int main()
{
    int mat[N][N];
    int i = 0, j = 0;
    int errorFlag = 0;
    char readValue;

    FILE *fpIn = fopen("./sudoku.txt", "r");

    for (i = 0; i < N && errorFlag != 1; i++)
    {
        for (j = 0; j < N && errorFlag != 1; j++)
        {
            fread(&readValue, sizeof(char), 1, fpIn);
            if (checkUntilLast(mat, (readValue - '0'), i, j) == -1)
            {
                errorFlag = 1;
                printf("errore nel %d %d", i, j);
            }
            else
            {
                mat[i][j] = (readValue - '0');
            }
            fseek(fpIn, sizeof(char), SEEK_CUR);
        }
    }

    printf("\n\n");
    for (i = 0; i < N && errorFlag != 1; i++)
    {
        for (j = 0; j < N && errorFlag != 1; j++)
        {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }

    if (errorFlag)
    {
        printf("\n\nnon è valido");
    }
    else
    {
        printf("\n\nvalido");
    }
    return 0;
}

int checkUntilLast(int mat[][N], int last, int i, int j)
{
    int q = 0;
    int w = 0;

    // controllo riga
    for (q = 0; q < j; q++)
    {
        if (mat[i][q] == last)
        {
            return -1;
        }
    }

    // controllo colonna
    for (w = 0; w < i; w++)
    {
        if (mat[w][j] == last)
        {
            return -1;
        }
    }

    // controllo sotto matrice
    for (w = i - (i % 3); w < i; w++)
    {
        for (q = j - (j % 3); q < j; q++)
        {
            if (mat[w][q] == last)
            {
                return -1;
            }
        }
    }

    return 0;
}
