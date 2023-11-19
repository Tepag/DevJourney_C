#include <stdio.h>
#define DIM 25
#define MOVES 5

typedef struct Xy
{
    int x;
    int y
} xy;

xy getMove();

int main()
{
    xy curr;
    int flag = 1;
    int l = 0, k = 0;

    int cnt = 1;
    xy movesSet[MOVES];

    int mat[3][3]{
        {0, 1, 0},
        {0, 1, 0},
        {0, 0, 0}};

    for (i = 0; i < MOVES; i++)
    {
        printf("\ninserisci ti quando vuoi spostare in x nella mossa n.%d: ", i + 1);
        scanf("%d", &movesSet[i].x);
        printf("\ninserisci ti quando vuoi spostare in y nella mossa n.%d: ", i + 1);
        scanf("%d", &movesSet[i].y);
    }

    curr.x = 0;
    curr.y = 0;
    // suppongo che l'utente sia santo e mi dia (0, n) o (n,0)
    for (l = 0; l < MOVES; l++)
    {
        if (movesSet[l].x > 0)
        {
        }
        if (movesSet[l].x < 0)
        {
        }
        if (movesSet[l].y > 0)
        {
        }
        if (movesSet[l].y < 0)
        {
        }
    }
}