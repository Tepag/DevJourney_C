#include <stdio.h>

#define M 3
#define N 3

/*
Si scriva una funzione ricorsiva che, ricevuta come parametro una matrice di interimat, un valore intero, val
e altri parametri eventualmente ritenuti necessari, restituisce 1 se tutte lerighe della matrice hanno somma
degli elementi pari a val,0 altrimenti
*/

int check(int mat[][N], int checkValue, int i, int j, int sum, int flagCounter);

int main()
{
    int mat[M][N] = {{7, 7, 1}, {15, 0, 0}, {9, 6, 0}};
    int checkValue = 15;

    // blocco stampa della matrice
    /*
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n", check(mat, checkValue, 0, 0, 0, 0));

    return 0;
}

int check(int mat[][N], int checkValue, int i, int j, int sum, int flagCounter)
{
    /*
        il modo in cui ragiono è la seguente:
        1. le i, o meglio quello che mi tiene fisso le righe sono la condizione di stop della mia ricorsione, infatti, arriva solo a M-1, quindi se i >= M allora vuol dire che non ho trovato nulla
        2. più o meno con lo stesso ragionamento di prima, la j arriva a N, quindi ha finito di scorrere, e quindi ho in mano un sum che posso confrontare, se questa coincide return 1
        3. se non sono entrato né nel blocco del "fine riga" né in quello di "fine colonna", allora sommo il contenuto corrente e mando avanti
    */

    if (i >= M)
    {
        // printf("flag= %d", flagCounter);
        if (flagCounter == M)
            return 1;
        else
        {
            return 0;
        }
    }

    if (j >= N)
    {
        printf("sum: %d\n", sum);
        if (sum == checkValue)
        {
            return check(mat, checkValue, i + 1, 0, 0, flagCounter + 1);
        }
        else
        {
            return check(mat, checkValue, i + 1, 0, 0, flagCounter);
        }
    }

    if (j < N)
    {
        sum += mat[i][j];
        return check(mat, checkValue, i, j + 1, sum, flagCounter);
    }

    return 0;
}