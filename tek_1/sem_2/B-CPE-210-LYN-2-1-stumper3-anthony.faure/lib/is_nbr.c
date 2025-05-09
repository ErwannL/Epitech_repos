/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper3-anthony.faure
** File description:
** is_nbr
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
