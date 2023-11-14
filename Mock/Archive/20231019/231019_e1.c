#include <stdio.h>

#define DIM 5
int main()
{
    int arr[DIM];
    int flag = 0;

    for (int i = 0; i < DIM; i++)
    {
        scanf("%d", &arr[i]);
        i = (arr[i] < 10 || arr[i] > 100) ? i - 1 : i;
    }

    flag = 0;
    for (int i = 0; i < DIM; i++)
    {
        flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("%d", arr[i]);
        }
    }
    return 0;
}