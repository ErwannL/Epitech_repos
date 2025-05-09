/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** Displays the length of a string.
*/

#include "../includes/my.h"

int my_strlen(char const *str)
{
    int length = 0;

    for (int i = 0; str[i] != '\0'; str++) {
        length++;
    }
    return length;
}
