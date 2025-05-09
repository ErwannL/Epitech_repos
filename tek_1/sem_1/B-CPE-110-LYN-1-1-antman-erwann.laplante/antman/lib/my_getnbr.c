/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** getnbr
*/

#include "../include/my.h"

int my_getnbr(char *str)
{
    int nbr;
    int i;

    for (nbr = 0, i = 0; str[i]; i++) {
        nbr = (nbr * 10) + (str[i] - 48);
    }
    return nbr;
}
