/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** my_strcmp
*/

#include "../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int var_one = 0;
    int var_second = 0;
    int n = (my_strlen(s1) > my_strlen(s2) ? my_strlen(s1) : my_strlen(s2));

    for (int i = 0; i < n; i++) {
        var_one += s1[i];
        var_second += s2[i];
    }
    if (var_one > var_second)
        return (1);
    if (var_one < var_second)
        return (-1);
    if (var_one == var_second)
        return (0);
}
