/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** my_str_to_int
*/

#include "../include/my.h"

int my_str_to_int(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb = (10 * nb) + (str[i] - 48);
    }
    return nb;
}

int my_str_to_int_coma(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != ','; i++) {
        nb = (10 * nb) + (str[i] - 48);
    }
    return nb;
}
