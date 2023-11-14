/*
scrivere un programma che letti tre jumeri , restituice:
0 - se sono orninati in modo crescente
1 - se sono in ordine decrescente 
-1 - negli altri casi

RECORD: 10m 43s
*/

#include <stdio.h>
#include <stdlib.h>

/*Function for input
@param int * variables where you want to storage the numer
@return void
*/
void input_num(int *_n);

/*Function for varifite sort method, it return 0, 1 or -1
@param int fist number
@param int second number
@param int third number
@return int 0-ascending 1-descending -1-other
*/
int verification_sort_three_num(int _n1, int _n2, int _n3);

int main()
{
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;

    input_num(&n1);
    input_num(&n2);
    input_num(&n3);

    printf("\n\n%d", verification_sort_three_num(n1, n2, n3));

    return 0;
}

void input_num(int *_n)
{
    printf("\ninsert the number: ");
    scanf("%d", &*_n);
    fflush(stdin);
}

int verification_sort_three_num(int _n1, int _n2, int _n3)
{
    if (_n1 < _n2 && _n2 < _n3)
    {
        return 1;
    }
    else
    {
        if (_n1 > _n2 && _n2 > _n3)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
}