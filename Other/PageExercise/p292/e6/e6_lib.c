#include <stdio.h>
#include <stdlib.h>
#include "e6_lib.h"

int coefficiente_binomiale(int _n, int _k)
{
    //* !n / (!k * !(n-k))
    return (fattoriale(_n) / (fattoriale(_k) * fattoriale(_n - _k)));
}

int fattoriale(int a)
{
    //uscita quando arriva a 1
    if (a == 1)
    {
        return a;
    }
    else
    {
        return a * fattoriale(a - 1);
    }
}
