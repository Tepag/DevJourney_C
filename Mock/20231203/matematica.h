#include <stdio.h>

int myPower(int base, int power)
{
    int i;
    int prod;

    prod = 1;

    for (i = 0; i < power; i++)
    {
        prod *= base;
    }
    return prod;
}

int mcd(int n1, int n2)
{
    int i = 1;

    i = n1 > n2 ? n2 : n1;

    while (n2 % i != 0 || n1 % i != 0)
    {
        i--;
    }

    return i;
}