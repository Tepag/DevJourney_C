#include <stdio.h>
#include <stdlib.h>

void toOct(int dec);

int main()
{
    int dec = 0;
    scanf("%d", &dec);
    toOct(dec);

    return 0;
}

void toOct(int dec)
{
    if (dec != 0)
    {
        toOct(dec / 8);
        printf("%d", dec % 8);
    }
}