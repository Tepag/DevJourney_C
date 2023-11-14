#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//#include <conio.h>
#include "function_lib.h"

//---------//
// CALCOLI //
//---------//

void numeri_perfetti(int num, int qnt)
{
    int sommad = 0, divisori = 1, cnt = 0;
    for (cnt = 0; cnt < qnt;)
    {
        // solo quando la somma dei divisori sono pari a numero
        while (num > divisori)
        {
            if (num % divisori == 0)
            {
                sommad += divisori;
            }
            divisori++;
            // printf("%d\n",divisori);
        }

        // verifica se è un numero perfetto
        if (num == sommad)
        {
            printf("TROVATO, e\' il numero %d\n", num);
            cnt++;
        }
        else
        {
            divisori = 1;
            sommad = 0;
        }
        num++;
    }
}

int numeri_primi(int num)
{
    int divisore = 1, cnt = 0;
    for (divisore = 1; divisore < num; divisore++)
    {
        if (num % divisore == 0)
            cnt = cnt + 1;
    }
    return cnt < 2 ? 1 : 0;
}

int fattoriale(int num)
{
    return num > 0 ? num * fattoriale(num - 1) : 1;
}

//------------------------//
// ARRAY MONODIMENSIONALI //
//------------------------//

void random_array(int _v[], int _d, int _start, int _end)
{
    for (int i = 0; i < _d; i++)
    {
        _v[i] = rand() % (_end - _start + 1) + _start;
    }
}

void input_array(int _v[], int _d)
{
    for (int i = 0; i < _d; i++)
    {
        printf("\ninserire numero nel vettore %d:", i);
        scanf("%d", &_v[i]);
        fflush(stdin);
    }
}

void init_a_zero(int _v[], int _d)
{
    for (int i = 0; i < _d; i++)
    {
        _v[i] = 0;
    }
}

void stampaVettore(int _v[], int _d)
{
    for (int i = 0; i < _d; i++)
    {
        printf("%d ", _v[i]);
    }
}

void orderarr(int _v[], int _d)
{
    int tmp = 0, j = 0, i = 0;
    for (i = 0; i < _d; i++)
    {
        for (j = i; j < _d; j++)
        {
            if (_v[i] < _v[j])
            {
                tmp = _v[j];
                _v[j] = _v[i];
                _v[i] = tmp;
            }
        }
    }
}

float mediaVet(int _v[], int _d)
{
    int somma = 0, i = 0;
    float media;
    for (i = 0; i < _d; i++)
    {
        somma = somma + _v[i];
    }
    media = (float)somma / _d;
    return media;
}

float varianzaVet(int _v[], int _d)
{
    float varianza;
    int somma_quadrati = 0, i = 0;
    for (i = 0; i < _d; i++)
    {
        somma_quadrati = somma_quadrati + pow(_v[i] - mediaVet(_v, _d), 2);
    }
    varianza = (float)somma_quadrati / _d;
    return (varianza);
}

void dec_to_(int num, int base, int _d)
{
    int i = 0, ris[_d];
    for (i = 0; i < _d; i++)
    {
        ris[i] = 0;
    }
    for (i = 0; i < _d; i++)
    {
        ris[i] = num % base;
        num /= base;
    }
    if (base > 10)
    {
        for (i = _d - 1; i >= 0; i--)
        {
            ris[i] >= 10 ? printf("%c", ('A' + ris[i] - 10)) : printf("%d", ris[i]);
            if (i % 4 == 0)
                printf(" ");
        }
    }
    else
    {
        for (i = _d - 1; i >= 0; i--)
        {
            printf("%d", ris[i]);
            if (i % 4 == 0)
                printf(" ");
        }
    }
}

void sum(int _a1[], int _a2[], int _a3[], int _d, int _b)
{
    for (int i = 0; i < _d; i++)
    {
        _a3[i] = _a1[i] + _a2[i] + _a3[i];
        _a3[i + 1] = _a3[i] / _b;
        _a3[i] = _a3[i] % _b;
    }
    for (int i = _d - 1; i >= 0; i--)
    {
        printf("%d", _a3[i]);
        if (i % 4 == 0)
        {
            printf(" ");
        }
    }
}

void reverseVettore(int _v[], int _d)
{
    int tmp = 0, i = 0;
    for (i = 0; i < _d / 2; i++)
    {
        tmp = _v[i];
        _v[i] = _v[_d - i - 1];
        _v[_d - i - 1] = tmp;
    }
}

int ricercaValore(int _v[], int _d, int _src)
{
    int i = 0, cnt = 0;
    for (i = 0; i < _d; i++)
    {
        if (_v[i] == _src)
            cnt++;
    }
    return (cnt);
}

int swapValori(int _v[], int _d, int _index1, int _index2)
{
    int tmp = 0;
    if (_index1 <= 0 || _index1 > _d)
    {
        return (0);
    }
    if (_index2 <= 0 || _index2 > _d)
    {
        return (0);
    }
    tmp = _v[_index1];
    _v[_index1] = _v[_index2];
    _v[_index2] = tmp;
    return (1);
}

//----------//
// STRINGHE //
//----------//

void stampa_str(char *text_peek)
{
    if (*text_peek != '\0')
    {
        printf("%c", *text_peek);
        stampa_str(text_peek + 1);
    }
}

int len_str_tail_fun(char *text_peek)
{
    return len_str_tail(text_peek, 0);
}

int len_str_tail(char *text_peek, int _acc)
{
    return *text_peek != '\0' ? len_str_tail(++text_peek, ++_acc) : _acc;
}

void reverse_to_another_str(char *text_peek, char *text_peek2)
{
    text_peek2 += len_str_tail_fun(text_peek);
    *text_peek2 = '\0';
    --text_peek2;
    while (*text_peek != '\0')
    {
        *text_peek2 = *text_peek;
        ++text_peek, --text_peek2;
    }
}

int cnt_vocali_str(char *text_start)
{
    int cnt = 0;
    while (*text_start != '\0')
    {
        if (*text_start == 'a' || *text_start == 'e' || *text_start == 'i' || *text_start == 'o' || *text_start == 'u' || *text_start == 'A' || *text_start == 'E' || *text_start == 'I' || *text_start == 'O' || *text_start == 'U')
            cnt++;
        text_start++;
    }
    return cnt;
}

void cnt_alfabeto_str(char *text_peek)
{
    int cnt[25] = {0}, i = 0;
    while (*text_peek != '\0')
    {
        for (i = 0; i < 25; i++)
        {
            if (*text_peek == ('a' + i) || *text_peek == ('A' + i))
                cnt[i]++;
        }
        text_peek++;
    }
    printf("hai inserito:\n");
    for (i = 0; i < 25; i++)
    {
        printf("%c/%c: %d   ", ('a' + i), ('A' + i), cnt[i]);
        if ((i + 1) % 4 == 0)
            printf("\n");
    }
}

int palindrome_verification(char *text_peek, char *text_peek2)
{
    int len = len_str_tail_fun(text_peek);
    text_peek2 += (len - 1);

    while (*text_peek != '\0')
    {
        if (*text_peek2 != *text_peek)
            return 0;
        text_peek++, text_peek2--;
    }
    return 1;
}

int anagram_verification(char *text_peek, char *text_peek2)
{
    int cnt[25] = {0}, i = 0;

    for (; *text_peek != '\0'; text_peek++)
    {
        for (i = 0; i < 25; i++)
        {
            if (*text_peek == 'a' + i || *text_peek == 'A' + i)
                cnt[i]++;
        }
    }

    for (; *text_peek2 != '\0'; text_peek2++)
    {
        for (i = 0; i < 25; i++)
        {
            if (*text_peek2 == 'a' + i || *text_peek2 == 'A' + i)
                cnt[i]--;
        }
    }

    for (i = 0; i < 25; i++)
    {
        if (cnt[i] != 0)
            return 1;
    }

    return 0;
}

/*
void order_str(char *)
{
}*/

int str_in_str_tail(char *text_peek, char *text_peek2, int j)
{
    if (*text_peek != '\0')
        *text_peek == *(text_peek2 + j) ? str_in_str_tail(++text_peek, text_peek2, ++j) : str_in_str_tail(++text_peek, text_peek2, 0);
    else
        return *(text_peek2 + j) == '\0' ? 1 : 0;
}
