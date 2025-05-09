/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** my_int_to_str
*/

#include "lemin.h"

char *my_int_to_str(int nb)
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
    ((1 == 1) ? (val++) : (0));
    return my_revstr(str);
}
