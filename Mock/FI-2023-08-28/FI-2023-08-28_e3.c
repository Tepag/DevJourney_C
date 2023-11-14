/*
Si consideri una matrice di dimensioni MxN che contiene valori binari 0 e 1. La matrice rappresenta una griglia
di possibili percorsi, in cui 0 indica un varco attraversabile e 1 rappresenta un muro invalicabile. I movimenti
all'interno di questa griglia avvengono in orizzontale e verticale, e possono essere rappresentati da coppie di
valori (±i, 0), per gli spostamenti verticali (verso l'alto o il basso), e (0, ±j) per gli spostamenti orizzontali (a destra
o a sinistra). i e j rappresentano cioè scostamenti di riga e di colonna, rispettivamente.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define M 3
#define N 3
#define MAXMOVES 2

typedef struct Xy
{
    int x;
    int y;
} xy;

xy getMove(); // funzione che prende in entrata le mosse del mio giocatore
int move(int mat[][N], xy action, xy *curr);
void showMap(int *mat, xy curr, int m, int n);

int main()
{
    int i = 0;
    int j = 0;
    xy actionSet[MAXMOVES];
    xy curr;
    int errorFlag = 0;
    int mat[M][N] = {
        {0, 1, 0},
        {0, 1, 0},
        {0, 0, 0}};

    for (i = 0; i < MAXMOVES; i++)
    {
        actionSet[i] = getMove();
    }

    // parte del movimento
    // suppongo che se il movimento è così strutturato (2, 3), prima si muove sulle x, poi sulle y
    curr.x = 0;
    curr.y = 0;
    for (i = 0; i < MAXMOVES && errorFlag != 1; i++)
    {
        errorFlag = move(mat, actionSet[i], &curr);
    }
    showMap(&mat[0][0], curr, M, N);

    return 0;
}

xy getMove()
{
    xy input;
    printf("\ninserisci di quanto vuoi muoverti in verticale: (<0 per andare in su e >0 per andare giù): ");
    scanf("%d", &input.y);
    printf("\ninserisci di quanto vuoi muoverti in orizzontale: (>0 per andare a destra e <0 per andare a sinistra): ");
    scanf("%d", &input.x);
    return input;
}

int move(int mat[][N], xy action, xy *curr)
{
    // per le x
    int j = 0;
    for (j = 0; j < abs(action.x); j++)
    {
        if (action.x > 0)
        {
            action.x--;
            curr->x++;
        }
        if (action.x < 0)
        {
            action.x++;
            curr->x--;
        }
        if (mat[curr->y][curr->x] == 1)
        {
            printf("sei andato contro il muro %d %d", curr->x, curr->y);
            return 1;
        }
    }

    // per le y
    for (j = 0; j < abs(action.y); j++)
    {
        if (action.y > 0)
        {
            action.y--;
            curr->y++;
        }
        if (action.y < 0)
        {
            action.y++;
            curr->y--;
        }
        if (curr->x < 0 || curr->y < 0 || curr->x >= N || curr->x >= M)
        {
            printf("sei fuori dalla mappa!");
            return 1;
        }
        if (mat[curr->y][curr->x] == 1)
        {
            printf("sei andato contro il muro %d %d", curr->x, curr->y);
            return 1;
        }
    }
    return 0;
}

void showMap(int *mat, xy curr, int m, int n)
{
    printf("\n\n");
    int i = 0;
    for (i = 0; i < m * n; i++)
    {
        if (i == ((curr.y) * n) + curr.x)
        {
            printf("  x");
        }
        else
        {
            printf("%3d", *(mat + i));
        }
        if ((i + 1) % n == 0)
        {
            printf("\n");
        }
    }
}