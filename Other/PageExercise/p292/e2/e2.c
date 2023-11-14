/*
Scrivi una funzione ricorsiva che calcola l'operazione di prodott sfruttando la seguente definizione induttiva:
prodotto (x,y) = 0                                 se y=0
prodotto (x,y) = somma (x,prodotto(x,y-1)))        se y>0

RECORD: 
*/
#include <stdio.h>
#include <stdlib.h>

//void prodotto_con_ricorsiva(int _n1, int _n2, int prod);
int prodotto_con_ricorsiva_v2(int _n1, int _n2);

int main()
{
    int n1 = 0, n2 = 0;
    printf("\ninserisci il primo fattore: ");
    scanf("%d", &n1);
    fflush(stdin);

    printf("\ninserisci il secondo fattore: ");
    scanf("%d", &n2);
    fflush(stdin);

    prodotto_con_ricorsiva(n1, n2, 0);
    printf("\n\nil prodotto risulta di %d", prodotto_con_ricorsiva_v2(n1, n2));

    return (0);
}

// void prodotto_con_ricorsiva(_n1, _n2, prod)
// {

//     if (_n2 > 0)
//     {
//         prod += _n1;
//         prodotto_con_ricorsiva(_n1, _n2 - 1, prod);
//     }
//     else
//     {
//         printf("il prodotto risulta di %d", prod);
//     }
// }

int prodotto_con_ricorsiva_v2(int _n1, int _n2)
{
    //caso più semplice: il secondo numero = 0
    if (_n2 == 0)
        return 0;

    else
        return _n1 + prodotto_con_ricorsiva_v2(_n1, _n2 - 1);
}