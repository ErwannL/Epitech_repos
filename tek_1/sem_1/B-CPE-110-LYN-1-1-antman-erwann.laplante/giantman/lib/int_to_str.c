/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** int_to_str
*/

#include "../include/my.h"

char *int_to_str(int nb)
{
    char *str;
    int i = 0;
    int val = 0;

    for (int save = nb; save != 0; i++)
        save /= 10;
    str = (char *)malloc(sizeof(char) * i);
    for (int quotient, rest; nb > 9; val++) {
        rest = nb % 10;
        quotient = nb / 10;
        str[val] = (rest + 48);
        nb = quotient;
    }
    str[val] = (nb + 48);
    val++;
    str[val] = '\0';
    return my_revstr(str);
}
