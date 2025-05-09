/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper2-anthony.faure
** File description:
** my_putstr
*/

#include "../include/my.h"

int my_putstr(char const *str, int fd)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i], fd);
        i++;
    }
    return (0);
}
