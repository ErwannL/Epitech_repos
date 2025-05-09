/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper1-anthony.faure
** File description:
** atoi
*/

#include "../include/my.h"

int my_atoi(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i += 1)
        nb = (10 * nb) + (str[i] - 48);
    return nb;
}
