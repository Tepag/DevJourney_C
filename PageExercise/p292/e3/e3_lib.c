#include <stdlib.h>
#include <stdio.h>
#include "e3_lib.h"

// void f_ricorsiva_esponente(int x, int y, int _r)
// {
//     if (y > 0)
//     {
//         _r *= x;
//         f_ricorsiva_esponente(x, y - 1, _r);
//     }
//     else
//     {
//         printf("il risultato e\' %d", _r);
//     }
// }

int f_ricorsiva_esponente_v2(int base, int power)
{
    if (power == 0)
        return 1;
    else
        return base * f_ricorsiva_esponente_v2(base, power - 1);
}
