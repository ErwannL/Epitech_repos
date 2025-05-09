/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-palindrome-erwann.laplante
** File description:
** string_free
*/

#include "lib.h"

int my_strcmp_free(char *str_one, int one, char *str_two, int two)
{
    int r = strcmp(str_one, str_two);

    if (one != 0)
        free(str_one);
    if (two != 0)
        free(str_two);
    return r;
}

char *my_strcpy_free(char *dest, char *src, int n)
{
    int len = 0;

    for (int i = 0; src[i] != '\0'; i++, len++);
    dest = malloc(sizeof(char) * (len + 1));
    dest = strcpy(dest, src);
    if (n != 0)
        free(src);
    return dest;
}
