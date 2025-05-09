/*
** EPITECH PROJECT, 2021
** B-CPE-101-LYN-1-1-bistromatic-erwann.laplante
** File description:
** sous2
*/

#include "include/my.h"

char *sous2(char *str)
{
    while (str[0] == '0' && str[1] != '\0')
        str++;
    return (str);
}
