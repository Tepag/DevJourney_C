/**
 * @file 20231119_e5V2.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 * @record: 31 min 54 sec
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

#define N 9

int sudoku_corretto[N][N] = {{5, 8, 6, 4, 2, 1, 3, 7, 9}, {3, 2, 7, 9, 6, 5, 4, 8, 1}, {9, 1, 4, 3, 7, 8, 6, 2, 5}, {1, 6, 3, 5, 8, 4, 7, 9, 2}, {2, 4, 5, 1, 9, 7, 8, 6, 3}, {8, 7, 9, 6, 3, 2, 5, 1, 4}, {7, 5, 8, 2, 1, 3, 9, 4, 6}, {6, 3, 1, 7, 4, 9, 2, 5, 8}, {4, 9, 2, 8, 5, 6, 1, 3, 7}};

int sudoku_sbagliato[N][N] = {{5, 8, 6, 4, 2, 1, 3, 7, 9}, {3, 2, 7, 9, 1, 5, 4, 8, 1}, {9, 1, 4, 3, 7, 8, 6, 2, 5}, {1, 6, 3, 5, 8, 4, 7, 9, 2}, {2, 4, 5, 1, 9, 7, 8, 6, 3}, {8, 7, 4, 6, 3, 2, 5, 1, 4}, {7, 5, 8, 2, 1, 3, 9, 4, 6}, {6, 8, 1, 7, 4, 9, 2, 5, 8}, {4, 9, 2, 8, 5, 2, 1, 3, 7}};

int checkUntilLast(int mat[][N], int last, int i, int j);

int main()
{
    int mat[N][N];
    int i = 0, j = 0;
    int errorFlag = 0;
    int value = 0;

    for (i = 0; i < N && errorFlag != 1; i++)
    {
        for (j = 0; j < N && errorFlag != 1; j++)
        {
            if (checkUntilLast(mat, sudoku_sbagliato[i][j], i, j) == -1)
            {
                errorFlag = 1;
                printf("errore nel %d %d", i, j);
            }
            else
            {
                mat[i][j] = sudoku_sbagliato[i][j];
            }
        }
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
