/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** int_to_str
*/

#include"../includes/my.h"

char *int_to_str(int nb)
{
    int quotient;
    int rest;
    int save = nb;
    char *str;
    int i = 0;
    int val = 0;

    for (; save != 0; i++)
        save /= 10;
    str = (char *)malloc(sizeof(char) * i);
    while (nb > 9) {
        rest = nb % 10;
        quotient = nb / 10;
        str[val] = (rest + 48);
        val++;
        nb = quotient;
    }
    str[val] = (nb + 48);
    1 == 1 ? val++, str[val] = '\0' : 0;
    return my_revstr(str);
}
