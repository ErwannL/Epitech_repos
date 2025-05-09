/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** rush3
*/
#include "../include/rush3.h"

int only_one(char *buff, char side, int end)
{
    int i;
    int res;

    i = 1;
    while (i < end &&( buff[i] == side || buff[i] == '\n'))
        i++;
    res = i - end;
    if ((res == 0 )||(res = end - 1))
        return (0);
    else
        return (1);
}

void rush3_3(char *buff, int i, int n_c)
{
    if (buff[0] == 'o' && only_one(buff, '-', n_c) == 0 &&
     buff[n_c - 1] == 'o') {
        my_putstr("[rush1-1]");
    }
    if (buff[0] == '*' && only_one(buff, '*', n_c) == 0 &&
     buff[n_c - 1] == '*') {
        my_putstr("[rush1-2]");
    }
    if (buff[0] == 'B' && only_one(buff, 'B', n_c) == 0 &&
     buff[n_c - 1] == 'B') {
        my_putstr("[rush1-3] || [rush1-4] || [rush1-5]");
    }
}

void rush3_2(char *buff, int i, int n_l)
{
    if (buff[0] == 'o' && only_one(buff, '|', n_l) == 0 &&
     buff[(n_l * 2) - 2] == 'o') {
        my_putstr("[rush1-1]");
    }
    if (buff[0] == '*' && only_one(buff, '*', n_l) == 0 &&
     buff[(n_l * 2) - 2] == '*') {
        my_putstr("[rush1-2]");
    }
    if (buff[0] == 'B' && only_one(buff, 'B', n_l) == 0 &&
     buff[(n_l * 2) - 2] == 'B') {
        my_putstr("[rush1-3] || [rush1-4] || [rush1-5]");
    }
}

void rush3_1(char *buff, int i)
{
    if (buff[i - 2] == 'o') {
        my_putstr("[rush1-1]");
    } else if (buff[i - 2] == '*') {
        my_putstr("[rush1-2]");
    } else if (buff[i - 2] == 'B') {
        my_putstr("[rush1-3] || [rush1-4] || [rush1-5]");
    } else {
        my_putstr("none");
    }
}

void rush3(char *buff)
{
    int n_c = 0;
    int n_l = 0;
    int i = 0;

    for (; buff[i] != '\0'; i++) {
        ((buff[i] == '\n') ? (n_l++) : 0);
        ((n_l == 0) ? (n_c++) : 0);
    }
    ((n_c == 1 && n_l == 1) ? (rush3_1(buff, i)) : ((n_c == 1) ?
    (rush3_2(buff, i, n_l)) : ((n_l == 1) ? (rush3_3(buff, i, n_c)) :
    my_putstr("none"))));
    my_putchar(' ');
    my_put_nbr(n_c);
    my_putchar(' ');
    my_put_nbr(n_l);
    my_putchar('\n');
}
