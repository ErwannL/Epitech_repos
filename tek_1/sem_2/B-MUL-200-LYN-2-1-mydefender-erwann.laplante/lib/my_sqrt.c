/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** my_sqrt
*/

#include "../include/my.h"

int my_sqrt(int n)
{
    int i = 1;
    int found = 0;
    int res = 0;

    while (found == 0) {
        if (i * i == n) {
            found = 1;
        } else if (i * i > n) {
            res = i;
            found = 1;
        }
        i += 1;
    }
    return res;
}
