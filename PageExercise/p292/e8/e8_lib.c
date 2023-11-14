#include <stdlib.h>
#include <stdio.h>
#include "e8_lib.h"

/*Hahahahha Lucky!*/
int power_num(int _n1, int _n2)
{
    //esco dalla ricorsiva quando deve moltiplicare per uno
    if (_n2 == 1)
        return _n1;

    //fin quando la potenza (_n2) non arriva a uno continuo a moltiplicare _n1 con se stesso
    else
        return _n1 *= power_num(_n1, _n2 - 1);
}