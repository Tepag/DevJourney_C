#include <stdio.h>

int main()
{
    int n1 = 0, n2 = 0, prod = 0;
    scanf("%d", &n1);
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++)
    {
        prod += n1;
    }
    printf("\n%d", prod);
}