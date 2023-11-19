/**
 * @file 20231119_e5.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-19
 *
 * @copyright Copyright (c) 2023
 * @record: 44 min 02 sec
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

int check(int mat[][N]);
int checkRow(int mat[][N]);
int checkCol(int mat[][N]);
int checkMiniMat(int mat[][N]);
int srcInArr(int arr[], int val, int dim);

int main()
{
    printf("\n\n%d", check(sudoku_corretto));
    printf("\n\n%d", check(sudoku_sbagliato));
    return 0;
}

int check(int mat[][N])
{
    // check delle riche che contengano da 1 a 9;
    if (checkRow(mat) == -1)
    {
        return -1;
    }

    // check delle colonne che contanga da 1 a 9;
    if (checkCol(mat) == -1)
    {
        return -1;
    }

    // check che le sottomatrici contenga da 1 a 9
    if (checkMiniMat(mat) == -1)
    {
        return -1;
    }

    return 0;
}

int srcInArr(int arr[], int val, int dim)
{
    int i = 0;

    for (i = 0; i < N; i++)
    {
        if (arr[i] == val)
        {
            return 1;
        }
    }
    return -1;
}

int checkRow(int mat[][N])
{
    int i = 0, j = 0;
    int arr[N];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            arr[j] = mat[i][j];
        }

        for (j = 1; j <= 9; j++)
        {
            if (srcInArr(arr, j, N) == -1)
            {
                return -1;
            }
        }
    }
    return 0;
}

int checkCol(int mat[][N])
{
    int i = 0, j = 0;
    int arr[N];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            arr[j] = mat[j][i];
        }

        for (j = 1; j <= 9; j++)
        {
            if (srcInArr(arr, j, N) == -1)
            {
                return -1;
            }
        }
    }
    return 0;
}

int checkMiniMat(int mat[][N])
{
    int i = 0, j = 0;
    int e = 0, k = 0;
    int p = 0;
    int arr[N];
    int cnt = 0;

    for (j = 0; j < 3; j++)
    {
        for (e = 0; e < 3; e++)
        {
            cnt = 0;
            for (i = j * 3; i < (j + 1) * 3; i++)
            {
                for (k = e * 3; k < (e + 1) * 3; k++)
                {
                    arr[cnt] = mat[i][k];
                    cnt++;
                }
            }
            for (p = 1; p <= 9; p++)
            {
                if (srcInArr(arr, p, N) == -1)
                {
                    return -1;
                }
            }
        }
    }

    return 0;
}