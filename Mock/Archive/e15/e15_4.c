#include <stdio.h>

int main()
{
    int sum = 0, cnt = 0, max = 0, min = 0, inputN = 0;
    scanf("%d", &inputN);

    max = inputN;
    min = inputN;

    if (inputN <= 0)
    {
        printf("\nla sequenza inserita è nulla");
    }

    while (inputN > 0)
    {
        cnt++;
        sum += inputN;
        max = (inputN > max) ? inputN : max;
        min = (inputN < min) ? inputN : min;
        printf("\ninserisci un altro num: ");
        scanf("%d", &inputN);
    }
    printf("\n\n%d\n%d\n%.2f", max, min, ((float)sum / (float)cnt));
}