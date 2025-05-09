/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** my_strlen
*/

#include "my_rpg.h"

int my_strlen(char const *str)
{
    int length = 0;

    for (int i = 0; str[i] != '\0'; str++) {
        length++;
    }
    return length;
}
