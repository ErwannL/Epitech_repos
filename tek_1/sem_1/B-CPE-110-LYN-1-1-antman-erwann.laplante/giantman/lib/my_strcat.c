/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** my_strcat
*/

#include "../include/my.h"

char *my_strcat(char *dest, char *src)
{
    char *dest2;
    int len_1 = my_strlen(dest);
    int len_2 = my_strlen(src);
    int i = 0;

    dest2 = malloc(sizeof(char) * (len_1 + len_2));
    dest2 = my_strcpy(dest2, dest);
    while (i <= len_2) {
        dest2[len_1 + i] = src[i];
        i++;
    }
    return (dest2);
}
