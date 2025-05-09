/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** my_str_cat
*/

#include "lemin.h"

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

char *my_strncat(char *dest, char *src, int n)
{
    char *dest2;
    int len_1 = my_strlen(dest);
    int len = my_strlen(src);
    int len_2 = len > n ? n : len;
    int i = 0;

    dest2 = malloc(sizeof(char) * (len_1 + len_2));
    dest2 = my_strcpy(dest2, dest);
    while (i <= len_2) {
        dest2[len_1 + i] = src[i];
        i++;
    }
    dest2[len_1 + i - 1] = '\0';
    return (dest2);
}
