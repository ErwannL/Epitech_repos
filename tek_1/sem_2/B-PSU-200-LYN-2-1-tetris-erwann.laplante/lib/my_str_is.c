/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** my_str_is
*/

#include "../include/my.h"

int my_str_is_int(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 84;
        }
    }
    return 0;
}

int my_str_is_int_coma(char *str)
{
    for (int i = 0; str[i] != ','; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 84;
        }
    }
    return 0;
}

int my_str_is_char(char *str)
{
    if (my_strlen(str) == 1)
        return 0;
    return 0;
}
