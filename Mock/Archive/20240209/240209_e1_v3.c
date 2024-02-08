#include <stdio.h>

#define M 3
#define N 3

/*
Si scriva una funzione ricorsiva che, ricevuta come parametro una matrice di interimat, un valore intero, val
e altri parametri eventualmente ritenuti necessari, restituisce 1 se tutte lerighe della matrice hanno somma
degli elementi pari a val,0 altrimenti
*/

int check(int mat[][N], int checkValue);

int main()
{
    int mat[M][N] = {
        {7, 7, 1},
        {4, 5, 6},
        {7, 8, 9}};

    int checkValue = 15;

    printf("%d\n", check(mat, checkValue));

    return 0;
}

int check(int mat[][N], int checkValue)
{
    static int i = 0;
    static int j = 0;
    static int sum = 0;

    if (i == M && j == N)
    {
        return 0;
    }

    if (j < N)
    {
        sum += mat[i][j];
        j++;
        return check(mat, checkValue);
    }
}