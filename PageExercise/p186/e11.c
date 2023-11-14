/*
fai un programma che dati due punti/coordinate in entrata, calcoli la distanza fra i due punti

RECORD: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Function for input
@param int * variables where you want to storage the numer
@return void
*/
void input_num(int *_n);

int main()
{
    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;
    int distance = 0;

    // set of input
    printf("insert x1: ");
    input_num(&x1);
    printf("insert y1: ");
    input_num(&y1);
    printf("insert x2: ");
    input_num(&x2);
    printf("insert y2: ");
    input_num(&y2);

    // ? la formula per il calcolo della distanza sqrt((x1-x2)ˆ2 + (y1-y2)ˆ2)
    distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    printf("distance: %d", distance);

    return 0;
}

void input_num(int *_n)
{
    scanf("%d", &*_n);
    fflush(stdin);
}