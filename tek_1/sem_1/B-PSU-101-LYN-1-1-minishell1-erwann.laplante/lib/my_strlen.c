/*
** EPITECH PROJECT, 2022
** B-PSU-101-LYN-1-1-minishell1-erwann.laplante
** File description:
** my_strlen
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int length = 0;

    for (int i = 0; str[i] != '\0'; str++) {
        length++;
    }
    return length;
}
