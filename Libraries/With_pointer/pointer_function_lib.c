#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//#include <conio.h>
#include "pointer_function_lib.h"

//---------//
// CALCOLI //
//---------//

void numeri_perfetti(int num, int qnt)
{
    int sumd = 0, divisori = 1, cnt = 0;
    for (cnt = 0; cnt < qnt; num++)
    {
        while (num > divisori)
        {
            if (num % divisori == 0)
                sumd += divisori;
            divisori++;
        }
        if (num == sumd)
        {
            printf("TROVATO, e\' il numero %d\n", num);
            cnt++;
        }
        else
            divisori = 1, sumd = 0;
    }
}

int numeri_primi(int num)
{
    int divisore = 1, cnt = 0;
    for (divisore = 1; divisore < num; divisore++)
    {
        if (num % divisore == 0)
            cnt++;
    }
    return cnt < 2 ? 1 : 0;
}

int fattoriale(int num)
{
    return num > 0 ? num * fattoriale(num - 1) : 1;
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

//----------------//
// ARRAY | MATRIX //
//----------------//

void random_array_or_matrix(int *_p, int _d, int _start, int _end)
{
    for (int i = 0; i < _d; i++)
        *(_p + i) = rand() % (_end - _start + 1) + _start;
}

void view_array_or_matrix(int *_p, int _d, int _elxcol)
{
    for (int i = 0; i < _d; i++)
    {
        printf("%3d ", *(_p + i));
        if ((i + 1) % _elxcol == 0)
            printf("\n");
    }
}

void input_array_or_matrix(int *_p, int _d)
{
    for (int i = 0; i < _d; i++)
    {
        printf("inserire numero: ");
        scanf("%d", _p + i);
        fflush(stdin);
    }
}

void init_array_or_matrix_to_value(int *_p, int _d, int _value)
{
    for (int i = 0; i < _d; i++)
        *(_p + i) = _value;
}

void sort_array_or_matrix(int *_p, int _d, int _reverse)
{
    int tmp = 0, j = 0, i = 0;
    for (i = 0; i < _d; i++)
    {
        for (j = i; j < _d; j++)
        {
            if (_reverse == 1)
            {
                if (*(_p + i) < *(_p + j))
                {
                    tmp = *(_p + j);
                    *(_p + j) = *(_p + i);
                    *(_p + i) = tmp;
                }
            }
            else
            {
                if (*(_p + i) > *(_p + j))
                {
                    tmp = *(_p + j);
                    *(_p + j) = *(_p + i);
                    *(_p + i) = tmp;
                }
            }
        }
    }
}

float avarage_value_array_or_matrix(int *_p, int _d)
{
    int i = 0, sum = 0;
    for (i = 0; i < _d; i++)
        sum += *(_p + i);
    return (float)sum / _d;
}

int sum_array_or_matrix(int *_p, int _d)
{
    int i = 0, sum = 0;
    for (i = 0; i < _d; i++)
        sum += *(_p + i);
    return sum;
}

float variance_array_or_matrix(int *_p, int _d)
{
    int sum_square_root = 0, i = 0;
    for (i = 0; i < _d; i++)
        sum_square_root = sum_square_root + pow(*(_p + i) - avarage_value_array_or_matrix(_p, _d), 2);
    return (float)sum_square_root / _d;
}

void reverse_array_or_matrix(int *_p, int _d)
{
    int tmp = 0, i = 0;
    for (i = 0; i < _d / 2; i++)
    {
        tmp = *(_p + i);
        *(_p + i) = *(_p + _d - i - 1);
        *(_p + _d - i - 1) = tmp;
    }
}

int search_value_array_or_matrix(int *_p, int _d, int _src)
{
    for (int i = 0; i < _d; i++)
    {
        if (*(_p + i) == _src)
            return i;
    }
    return -1;
}

//----------//
// STRINGHE //
//----------//

void print_str(char *text_peek)
{
    if (*text_peek != '\0')
    {
        printf("%c", *text_peek);
        print_str(text_peek + 1);
    }
}

int str_len_tail(char *text_peek, int _acc)
{
    return *text_peek != '\0' ? str_len_tail(++text_peek, ++_acc) : _acc;
}

void reverse_to_another_str(char *text_peek, char *text_peek2)
{
    text_peek2 += str_len_tail(text_peek, 0);
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
    int len = str_len_tail(text_peek, 0);
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

void order_str(char *pointer)
{
    int i = 0, j = 0;
    char tmp;
    for (i = 0; *(pointer + i) != '\0'; i++)
    {
        for (j = i; *(pointer + j) != '\0'; j++)
        {
            if (*(pointer + i) > *(pointer + j))
            {
                tmp = *(pointer + i);
                *(pointer + i) = *(pointer + j);
                *(pointer + j) = tmp;
            }
        }
    }
}

int str_in_str_tail(char *text_peek, char *text_peek2, int j)
{
    if (*text_peek != '\0')
        *text_peek == *(text_peek2 + j) ? str_in_str_tail(++text_peek, text_peek2, ++j) : str_in_str_tail(++text_peek, text_peek2, 0);
    else
        return *(text_peek2 + j) == '\0' ? 1 : 0;
}

char *input_str()
{
    char *str = (char *)malloc(sizeof(char));
    int i = 0, flag = 0;
    for (; flag == 0; i++)
    {
        str = (char *)realloc(str, (sizeof(char) * (i + 2)));
        *(str + i) = getchar();
        if (*(str + i) == '\n')
        {
            *(str + i) = '\0';
            flag++;
        }
    }
    return str;
}

char *my_strcat(char *des, char *src)
{
    des = (char *)realloc(des, (sizeof(char) * (my_strlen(des) + my_strlen(src) + 2)));
    printf("\n%d", my_strlen(des));
    my_strcpy((des + my_strlen(des)), src);
    printf("\n%d", my_strlen(des));
    return des;
}

char *my_strchr(char *pointer, char sep)
{
    for (; *pointer != '\0'; pointer++)
    {
        if (*pointer == sep)
            return pointer;
    }
    return NULL;
}

int my_strcmp(char *p1, char *p2)
{
    // compare all letter
    for (int i = 0; *(p1 + i) != '\0'; i++)
    {
        if (*(p1 + i) != *(p2 + i))
        {
            // if greater return 1
            if (*(p1 + i) > *(p2 + i))
                return 1;
            else // else return -1
                return -1;
        }
    }
    // if str1 is finished, the another one is longer
    return -1;
}

void my_strcpy(char *des, char *src)
{
    for (; *src != '\0'; des++, src++)
        *des = *src;
    *des = '\0';
}

int my_strlen(char *p)
{
    int cnt = 0;
    for (; *p != '\0'; p++)
        cnt++;
    return cnt;
}

char *my_strrchr(char *pointer, char sep)
{
    while (my_strchr(pointer, sep) != NULL)
    {
        pointer = my_strchr(pointer, sep) + 1;
    }
    return pointer - 1;
}

char *my_strstr(char *big, char *small)
{
    int j = 0;
    for (; *big != '\0'; big++)
    {
        if (*big == *(small + j))
        {
            j++;
            if (j == my_strlen(small))
                return (big - my_strlen(small) + 1);
        }
        else
            j = 0;
    }
    return NULL;
}

char *my_strtok(char *str, char *sep)
{
    static char *current = NULL;
    static int flag = 0;
    int j = 0;

    char *pointer = NULL;
    // utente mi pasa una stringa?
    if (str == NULL) // no: gli passo l'indirizzo del prossimo e gli mando il puntatore
    {
        // cerco e sostituisco
        current = current + my_strlen(current) + my_strlen(sep);
        if (my_strstr(current, sep) != NULL)
        {
            *(my_strstr(current, sep)) = '\0';
            return current;
        }

        if (flag == 0)
        {
            flag = 1;
            return current;
        }
        else
            return NULL;
    }
    else // sì: lo memorizzo nella corrente e gli ripasso il punatore alla prima cella
    {
        flag = 0, current = str;

        // sostituisco separatore con il terminatore;
        *(my_strstr(current, sep)) = '\0';
        return str;
    }
}