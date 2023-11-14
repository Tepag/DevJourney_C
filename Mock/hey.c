#include <stdio.h>

int yoo(int);

int main()
{
    mat[2][2] = {(1, 2), (3, 4)};

    printf("%d", yoo(3));
}

int yoo(int cobblestone)
{
    if (cobblestone > 1)
    {
        return cobblestone * yoo(cobblestone - 1);
    }
    else
    {
        return 1;
    }
}
