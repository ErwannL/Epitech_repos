/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper3-anthony.faure
** File description:
** my_strcat
*/

#include "../include/my.h"

char *my_strcat(char *dest, char *src)
{
    int len1 = my_strlen(dest);
    int len2 = my_strlen(src);
    char *str = malloc(sizeof(char) * (len1 + len2 + 1));
    int ctr = 0;
    int ctr2 = 0;

    while (dest[ctr] != '\0') {
        str[ctr] = dest[ctr];
        ctr = ctr + 1;
    }
    while (src[ctr2] != '\0') {
        str[ctr + ctr2] = src[ctr2];
        ctr2 = ctr2 + 1;
    }
    str[len1 + len2] = '\0';
    return str;
}
