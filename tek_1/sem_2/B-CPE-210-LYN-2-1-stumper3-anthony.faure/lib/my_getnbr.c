/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper3-anthony.faure
** File description:
** my_getnbr
*/

#include "../include/my.h"

int my_getnbr(char *str)
{
    int nbr = 0;
    int i = 0;

    for (nbr = 0, i = 0; str[i] != '\n'; i++) {
        nbr = (nbr * 10) + (str[i] - 48);
    }
    return nbr;
}
