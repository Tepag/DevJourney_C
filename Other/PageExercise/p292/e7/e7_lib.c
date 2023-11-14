#include <stdio.h>
#include <stdlib.h>
#include "e7_lib.h"

float fattoriale(float a)
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

float disposizioni_poss(float _n, float _k)
{
    return (fattoriale(_n) / fattoriale((_n - _k)));
}