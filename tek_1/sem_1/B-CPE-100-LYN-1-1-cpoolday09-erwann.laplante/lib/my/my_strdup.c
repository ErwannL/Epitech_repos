/*
** EPITECH PROJECT, 2021
** Task 01 - my_strdup
** File description:
** This function allocates memory and copies the string given as argument in it
*/
#include<stdlib.h>
#include"../../include/my.h"

int my_strlen(char const*);

char *my_strdup(char const *src)
{
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (i < my_strlen(src)) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
