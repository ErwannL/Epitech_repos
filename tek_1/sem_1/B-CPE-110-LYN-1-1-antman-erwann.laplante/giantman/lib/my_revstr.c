/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** my_revstr
*/

#include "../include/my.h"

char *my_revstr(char *str)
{
    char substitute;
    int length = 0;

    if (str == 0) {
        return 0;
    }
    for (; str[length] != '\0'; length++);
    length -= 1;
    for (int i = 0; i < length; i++, length--) {
        substitute = str[i];
        str[i] = str[length];
        str[length] = substitute;
    }
    return str;
}
