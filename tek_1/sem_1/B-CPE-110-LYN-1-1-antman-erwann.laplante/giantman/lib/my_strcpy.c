/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
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
