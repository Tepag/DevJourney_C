#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <conio.h>
#include "function_lib.c"

// COSTANTI
#define C 4
#define R 5
#define DIM 8

//----------------------//
// ARRAY BIDIMENSIONALI //
//----------------------//

/*Funzione che randomizza una matrice di interi
@param int[][] Matrice da inizializzare
@param int righe della matrice.
@param int colonne della matrice.
@param int range minimo
@param int range massimo
@return void
*/
void random_mat(int _m[][C], int _r, int _c, int _start, int _end);

/*Funzione che stampa una matrice di interi
@param int[][] Matrice da inizializzare
@param int Numero di righe della matrice. 
@param int NUmero di colonne della matrice.
@return void
*/
void stampaMat(int _m[][C], int _r, int _c);

/*funzione che ritorna la media dei numeri in una matrice numerica
@param int[][] matrice
@param int numero di righe
@param int numero di colonne
@return float media calcolata*/
float mediaMatrice(int _m[][C], int _r, int _c);

/*funzione che determina le coordinate del valor minimo.
@param int[][] matrice 
@param int numero di righe
@param int numero di colonne
@param int* variabile per l'indici di riga trovato
@param int* variabile per l'indici di colonna trovato
@return void*/
void ricercaMinimoMatrice(int _m[][C], int _r, int _c, int *x, int *y);

/*funzione che ordina una matrice
@param int[][] matrice da ordinare
@param int numero righe
@param int numero colonne
@return void*/
void ordermat(int _m[][C], int _r, int _c);

/*funzione che fa il reverse di una matrice
@param int[][] matrice
@param int numero righe
@param int numero colonne
@return void*/
void reverse_mat(int _m[][C], int _r, int _c);

//-------------------//
// CODICE PRINCIPALE //
//-------------------//

int main()
{
    int mat[R][C];
    random_mat(mat, R, C, 0, 20);
    ordermat(mat, R, C);
    stampaMat(mat, R, C);
    char text[8] = {'c', 'i', 'a', 'o', '\0'};
    char *text_allias = text;
    printf("\n\n");
    stampa_str(text_allias);
    char text2[8];
    char *text_allias2 = text2;
    reverse_to_another_str(text_allias, text_allias2);
    printf("\n\n");
    stampa_str(text_allias2);

    printf("\n\n\n\ntest: %d", fattoriale(3));
    return 0;
}

//----------------------//
// ARRAY BIDIMENSIONALI //
//----------------------//

void random_mat(int _m[][C], int _r, int _c, int _start, int _end)
{
    int i, j;
    for (i = 0; i < _r; i++)
    {
        for (j = 0; j < _c; j++)
        {
            _m[i][j] = rand() % (_end - _start + 1) + _start;
        }
    }
}

void stampaMat(int _m[][C], int _r, int _c)
{
    int i, j;
    for (i = 0; i < _r; i++)
    {
        for (j = 0; j < _c; j++)
        {
            printf("%3d", _m[i][j]);
        }
        printf("\n");
    }
}

float mediaMatrice(int _m[][C], int _r, int _c)
{
    int i = 0, j = 0;
    int somma = 0;
    for (i = 0; i < _r; i++)
    {
        for (j = 0; j < _c; j++)
        {
            somma += _m[i][j];
        }
    }
    return ((float)somma / (_r * _c));
}

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

void ordermat(int _m[][C], int _r, int _c)
{
    int i, j, h, k, box, colonna_iniziale;
    for (i = 0; i < _r; i++)
    {
        for (j = 0; j < _c; j++)
        {
            for (h = i; h < _r; h++)
            {
                colonna_iniziale = (h == i ? j : 0);
                for (k = colonna_iniziale; k < _c; k++)
                {
                    if (_m[i][j] > _m[h][k])
                    {
                        box = _m[i][j];
                        _m[i][j] = _m[h][k];
                        _m[h][k] = box;
                    }
                }
            }
        }
    }
}

void reverse_mat(int _m[][C], int _r, int _c)
{
    int i = 0, j = 0, tmp = 0;
    for (i = 0; i < _r / 2; i++)
    {
        for (j = 0; j < _c; j++)
        {
            tmp = _m[i][j];
            _m[i][j] = _m[_r - i - 1][j]; //[_r - i -1][_c - j -1]
            _m[_r - i - 1][j] = tmp;
        }
    }
}
