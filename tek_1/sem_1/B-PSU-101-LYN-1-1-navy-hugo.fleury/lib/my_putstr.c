/*
** EPITECH PROJECT, 2021
** my_pustr
** File description:
** Displays the characters of a string one-by-one.
*/

#include "my.h"

int my_putstr(char const *str, int x)
{
    for (; *str != '\0'; str++) {
        my_putchar(*str, x);
    }
    return 0;
}
