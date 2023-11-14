//----------//
// LIBRERIE //
//----------//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <conio.h>

//----------//
// COSTANTI //
//----------//

#define C 4
#define R 5
#define DIM 8

//----------------//
// FUNCTION_LIB.C //
//----------------//

#include "pointer_function_lib.c"

//----------------------//
// ARRAY BIDIMENSIONALI //
//----------------------//

/*funzione che determina le coordinate del valor minimo.
@param int[][] matrice
@param int numero di righe
@param int numero di colonne
@param int* variabile per l'indici di riga trovato
@param int* variabile per l'indici di colonna trovato
@return void*/
void ricercaMinimoMatrice(int _m[][C], int _r, int _c, int *x, int *y);

//-------------------//
// CODICE PRINCIPALE //
//-------------------//

int main()
{
    int vet[R][C];
    // input_array_or_matrix(&vet[0][0], R * C);
    random_array_or_matrix(&vet[0][0], R * C, 1, 2);
    sort_array_or_matrix(&vet[0][0], R * C, 0);
    view_array_or_matrix(&vet[0][0], R * C, C);

    return 0;
}

//----------------------//
// ARRAY BIDIMENSIONALI //
//----------------------//

void ricercaMinimoMatrice(int _m[][C], int _r, int _c, int *x, int *y)
{
    int i = 0, j = 0;
    int min = 0, min_i = 0, min_j = 0;
    min = _m[0][0];
    for (i = 0; i < _r; i++)
    {
        for (j = 0; j < _c; j++)
        {
            if (_m[i][j] < min)
            {
                min = _m[i][j];
                min_i = i;
                min_j = j;
            }
        }
    }
    *x = min_i;
    *y = min_j;
}
