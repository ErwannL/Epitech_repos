/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper1-anthony.faure
** File description:
** my_strcpy
*/

#include "../include/my.h"

char *my_strcpy(char *dest , char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
