/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** mode
*/

#include "../include/my.h"

void start_mode_bis(variable_t var, char *mode)
{
    if (mode[0] == '1')
        my_putstr("mode 1\n");
    else if (mode[0] == '2')
        my_putstr("mode 2\n");
}

int start_mode(variable_t var, char *mode)
{
    if (mode[0] == '1' || mode[0] == '2')
        start_mode_bis(var, mode);
    else if (mode[0] == '3')
        var = mode_3(var);
    else {
        my_putstr("Error\n");
        return 84;
    }
    if (var.error == 84)
        return 84;
    return 0;
}
