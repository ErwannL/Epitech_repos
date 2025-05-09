/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-BSQ-erwann.laplante
** File description:
** my_strcat
*/

#include"../includes/my.h"

char *my_strcat(char *dest , char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    return (dest);
}
