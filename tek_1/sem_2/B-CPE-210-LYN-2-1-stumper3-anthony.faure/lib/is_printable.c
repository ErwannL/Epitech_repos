/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper3-anthony.faure
** File description:
** char_is_printable
*/

#include "../include/my.h"

int my_char_is_printable(char c)
{
    if (c < 127 && c > 31) {
        return 0;
    }
    return 84;
}

int my_str_is_printable(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (my_char_is_printable(str[i]) == 84)
            return 84;
    }
    return 0;
}
