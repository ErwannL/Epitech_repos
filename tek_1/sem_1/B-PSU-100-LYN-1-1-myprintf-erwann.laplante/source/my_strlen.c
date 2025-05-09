/*
** EPITECH PROJECT, 2021
** CPool
** File description:
** my_strlen
*/

#include"../includes/my.h"

int my_strlen(char const *str)
{
    int count = 0;

    for (; str[count] != '\0'; count += 1);
    return (count);
}
