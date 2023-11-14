#include <stdio.h>

int main()
{
    int r = 0, q = 0;
    float y = 0;
    scanf("%d", &r);
    scanf("%d", &q);

    if (r < q)
    {
        puts("i numeri inseriti non sono interi positivi o r<q");
        return 0;
    }

    for (int i = q; i <= r; i++)
    {
        y += 1.0 / (float)i;
    }

    printf("%f", y);

    return 0;
}