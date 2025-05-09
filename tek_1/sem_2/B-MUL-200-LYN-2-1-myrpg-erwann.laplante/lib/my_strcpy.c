/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** my_strcpy
*/

#include "my_rpg.h"

char *my_strcpy(char *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    dest[my_strlen(src)] = '\0';
    while (i != my_strlen(src)) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
