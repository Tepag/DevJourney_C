#include <stdio.h>

int main()
{
    int n1 = 0, n2 = 0, d1 = 0, d2 = 0;
    scanf("%d", &n1);
    scanf("%d", &d1);
    scanf("%d", &n2);
    scanf("%d", &d2);

    int i = 1, j = 1;
    int tmpDen1 = d1, tmpDen2 = d2, tmpNum1 = n1, tmpNum2 = n2;
    while (d1 != d2)
    {
        if (d1 > d2)
        {
            tmpDen2 = d2 * i;
            tmpNum2 = n2 * i;
            i++;
        }
        else
        {
            tmpDen1 = d1 * i;
            tmpNum1 = n1 * i;
            j++;
        }
    }
    printf("\n%d/%d", tmpNum1 + tmpNum2, tmpDen1);
}