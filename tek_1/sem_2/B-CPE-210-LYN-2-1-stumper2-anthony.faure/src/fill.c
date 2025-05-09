/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper2-anthony.faure
** File description:
** fill
*/

#include "../include/my.h"

int print_error(void)
{
    my_putstr("input error\n", 2);
    return 84;
}

void fill_vars(var_t *vars)
{
    vars->width = 7;
    vars->height = 6;
    vars->p1 = 'X';
    vars->p2 = 'O';
    vars->ref = '#';
    vars->player = 1;
    vars->nb = 0;
    return;
}
