#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define LEN 5
#define DD 0
#define MM 1
#define YY 2
#define HH 3
#define MIN 4

int checkData(int *data);
int cmpData(int *data1, int *data2);

int main()
{
    // DD-MM-YYYY hh:mm
    int data[LEN];
    int finishData[LEN];
    int result[LEN] = {0};
    int errorFlag = 0;
    int tmp = 0;

    for (int i = 0; i < LEN; i++)
    {
        scanf("%d", &data[i]);
        fflush(stdin);
    }

    for (int i = 0; i < LEN; i++)
    {
        scanf("%d", &finishData[i]);
        fflush(stdin);
    }

    if (cmpData(data, finishData) == 1)
    {
        for (int i = 0; i < LEN; i++)
        {

            tmp = data[i];
            data[i] = finishData[i];
            finishData[i] = tmp;
        }
    }

    if (checkData(data) == 1)
    {
        printf("\n\nerrore nell'orario della prima data\n\n");
    }

    if (checkData(finishData) == 1)
    {
        printf("\n\nerrore nell'orario della seconda data\n\n");
    }

    // blocco per fare la differenza
    result[MIN] = finishData[MIN] - data[MIN] + result[MIN];
    if (result[MIN] < 0)
    {
        result[MIN] += 60;
        result[HH] = -1;
    }

    result[HH] = finishData[HH] - data[HH] + result[HH];
    if (result[HH] < 0)
    {
        result[DD] = -1;
        result[HH] += 24;
    }

    result[DD] = finishData[DD] - data[DD] + result[DD];
    if (result[DD] < 0)
    {
        // --------------------------------
        if (data[MM] == 2)
        {
            if (result[YY] % 400 == 0 || (result[YY] % 4 == 0 && result[YY] % 100 == 0))
            {
                result[DD] += 29;
            }
            else
            {
                result[DD] += 28;
            }
        }
        else
        {
            if ((data[MM] == 1 || data[MM] == 3 || data[MM] == 5 || data[MM] == 7 || data[MM] == 8 || data[MM] == 10 || data[MM] == 12) && data[DD] > 31)
            {
                result[DD] += 31;
            }
            else
            {
                result[DD] += 30;
            }
        }
        result[MM] = -1;
    }

    result[MM] = finishData[MM] - data[MM] + result[MM];
    if (result[MM] < 0)
    {
        result[YY] = -1;
        result[MM] += 12;
    }

    result[YY] = finishData[YY] - data[YY] + result[YY];
    if (result[YY] < 0)
    {
        result[YY] = abs(result[YY]) - 1;
    }

    printf("\n\nanno: %02d\nmesi:%02d\ngiorni:%02d\n%02d:%02d", result[YY], result[MM], result[DD], result[HH], result[MIN]);

    return 0;
}

int cmpData(int *data1, int *data2)
{
    for (int i = 2; i >= 0; i--)
    {
        if (data1[i] > data2[i])
        {
            // printf("%d  %d", data1[i], data2[i]);
            return 1;
        }
    }
    for (int i = 3; i < LEN; i++)
    {
        if (data1[i] > data2[i])
        {
            // printf("%d < %d", data1[i], data2[i]);
            return 1;
        }
    }
    // printf("NO problem");
    return 0;
}

int checkData(int *data)
{
    int errorFlag = 0;
    if (data[HH] > 23 || data[MIN] > 59)
    {
        errorFlag = 1;
    }

    if (data[MM] <= 12 && data[MM] > 0)
    {
        if ((data[YY] % 400 == 0 || (data[YY] % 4 == 0 && data[YY] % 100 == 0)) && data[MM] == 2 && data[DD] > 29)
        {
            return 1;
        }
        else
        {
            if (data[MM] == 2 && data[DD] > 28)
            {
                return 1;
            }
        }

        if ((data[MM] == 1 || data[MM] == 3 || data[MM] == 5 || data[MM] == 7 || data[MM] == 8 || data[MM] == 10 || data[MM] == 12) && data[DD] > 31)
        {
            return 1;
        }
        else
        {
            if (data[DD] > 30)
            {
                return 1;
            }
        }
    }
    return 0;
}
