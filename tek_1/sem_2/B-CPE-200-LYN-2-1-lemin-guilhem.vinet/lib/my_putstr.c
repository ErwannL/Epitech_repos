/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** affiche des nombres
*/

#include "lemin.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
         my_putchar(str[i]);
         i = i + 1;
    }
    return (0);
}
