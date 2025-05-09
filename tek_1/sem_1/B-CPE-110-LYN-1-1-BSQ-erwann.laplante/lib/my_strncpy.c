/*
** EPITECH PROJECT, 2021
** Task 02 - my_strncpy
** File description:
** This function copies n characters from a string into another.
*/
#include"../includes/my.h"

char *my_strncpy(char *dest , char *src , int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > my_strlen(src))
        dest[i] = '\0';
    return (dest);
}
