/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** utilities
*/

#include "../include/my.h"

int *my_intncat(int *list, int n, int lenght)
{
    int i = 0;

    for (; i != lenght; i++) {
        if (i > n) {
            list[i - 1] = list[i];
        }
    }
    return list;
}

sfSprite **my_spritencat(sfSprite **list, int n, int lenght)
{
    int i = 0;

    for (; i != lenght; i++) {
        if (i > n) {
            list[i - 1] = list[i];
        }
    }
    return list;
}
