/*
** EPITECH PROJECT, 2021
** Task 03 - my_strlen
** File description:
** This function counts and returns the number of characters found in a string
*/
#include"../../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
