/*
** EPITECH PROJECT, 2021
** my_strchr
** File description:
** description
*/

#include <stddef.h>

int my_strchr(char *str, int what)
{
    int i = 0;

    for (; str[i] && str[i] != (char)what; i++);
    if (str[i] == (char)what) {
        return i;
    }
    return -1;
}
