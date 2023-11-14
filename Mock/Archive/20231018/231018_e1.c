#include <stdio.h>

int main()
{
    int dim = 0;
    scanf("%d", &dim);

    int arr[dim];

    for (int i = 0; i < dim; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < dim; i++)
    {
        printf("%d", arr[i]);
    }
}
