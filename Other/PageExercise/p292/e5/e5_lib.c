#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "e5_lib.h"

int reverse_num = 0;

void num_contrario(num)
{

    if ((num % 10 != 0) || (num != 0))
    {

        reverse_num *= 10;
        reverse_num += (num % 10);

        //printf("%d", (num % 10));
        num_contrario(num / 10);
    }
    else
    {
        printf("%d", reverse_num);
    }
}

int number_lenght(num)
{
    if (num / 10 == 0)
        return 0;
    else
        return 1 + number_lenght(num / 10);
}

int num_contrario_v2(num, lenght)
{
    if (num / 10 == 0)
        return num;
    else
        return ((num % 10 * pow(10, lenght)) + num_contrario_v2(num / 10, lenght - 1));
}

void det_polindromo(num)
{
    if (num / 10 == 0)
        printf("%d", num);
    else
    {
        printf("%d", num % 10);
        det_polindromo(num / 10);
        printf("%d", num % 10);
    }
}