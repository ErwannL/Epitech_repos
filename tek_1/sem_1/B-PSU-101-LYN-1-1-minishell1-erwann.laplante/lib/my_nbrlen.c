/*
** EPITECH PROJECT, 2022
** B-PSU-101-LYN-1-1-minishell1-erwann.laplante
** File description:
** my_nbrlen
*/

#include "../include/my.h"

int my_intlen(int nbr)
{
    int lenght = 0;

    if (nbr == 0)
        return 1;
    while (nbr != 0) {
        nbr /= 10;
        lenght++;
    }
    return lenght;
}
