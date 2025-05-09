/*
** EPITECH PROJECT, 2021
** Task 03 - my_strlen
** File description:
** This function counts and returns the number of characters found in a string
*/
#include"my.h"

int my_strlen(char const *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++)
        len++;
    return (len);
}
