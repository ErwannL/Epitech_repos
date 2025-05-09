/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** my_int_len
*/

#include "../include/my.h"

int my_int_len(int nbr)
{
    int lenght = 0;

    if (nbr == 0)
        return 1;
    while (nbr != 0) {
        nbr /= 10;
        lenght++;
    }
    return lenght + 1;
}
