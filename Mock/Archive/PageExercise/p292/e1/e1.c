/*
Scrivi una funzione ricorsiva che calcola l'operazione di somma sfruttando la seguente definizione induttiva:
somma (x,y) = x se y=0
somma(x,y) = 1 + (somma(x,y-1))  se y>0

RECORD: 27m 32s
*/
#include <stdio.h>
#include <stdlib.h>

int somma_ricorsiva(int _n1, int _n2);

int main()
{
    int n1 = 0, n2 = 0;
    printf("\ninserisci il primo numero: ");
    scanf("%d", &n1);
    fflush(stdin);

    printf("\ninserisci il secondo numero: ");
    scanf("%d", &n2);
    fflush(stdin);

    printf("\n%d", somma_ricorsiva(n1, n2));

    return (0);
}

/*
void somma_ricorsiva(_n1, _n2)
{
    if (_n2 > 0)
    {
        _n1++;
        somma_ricorsiva(_n1, _n2 - 1);
    }
    else
    {
        printf("\nla somma risulta %d", _n1);
    }
}
*/

int somma_ricorsiva(_n1, _n2)
{
    //caso più semplice con chiusura
    if (_n2 == 0)
    {
        return _n1;
    }
    else
    {
        return _n1 + somma_ricorsiva(_n1, _n2 - 1);
    }

    /*
    if (_n2 > 0)
    {
        _n1++;
        somma_ricorsiva(_n1, _n2 - 1);
    }
    else
    {
        printf("\nla somma risulta %d", _n1);
    }
    */
}