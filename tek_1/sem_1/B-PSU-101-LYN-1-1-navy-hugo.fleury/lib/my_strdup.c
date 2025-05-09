/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** copy a R/O string by allocating memory to it.
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int length = 0;
    char *dest = 0;

    if (src == 0) {
        return NULL;
    }
    for (; src[length] != '\0'; length++);
    dest = (char *)malloc(length + 1);
    my_strcpy(dest, src);
    return dest;
}
