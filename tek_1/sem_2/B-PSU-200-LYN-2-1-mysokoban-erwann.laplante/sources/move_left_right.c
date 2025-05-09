/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-erwann.laplante
** File description:
** move_left_right
*/

#include "../include/my.h"

var_t *move_left_bis(var_t *var, int i)
{
    while (var->map[var->y][i - 1] == 'X') {
        if (var->map[var->y][i - 2] == '#' || var->map[var->y][i - 2] == 'X')
            return var;
        i--;
    }
    while (var->map[var->y][i] != 'P') {
        var->map[var->y][i - 1] = 'X';
        var->map[var->y][i] = ' ';
        i++;
    }
    var->map[var->y][var->x] = ' ';
    var->map[var->y][var->x - 1] = 'P';
    var->x--;
    return var;
}

var_t *move_left(var_t *var)
{
    int i = var->x;

    if (var->map[var->y][var->x - 1] != '#')
        var = move_left_bis(var, i);
    print_map(var->map, var);
    return var;
}

var_t *move_right_bis(var_t *var, int i)
{
    while (var->map[var->y][i + 1] == 'X') {
        if (var->map[var->y][i + 2] == '#' || var->map[var->y][i + 2] == 'X')
            return var;
        i++;
    }
    while (var->map[var->y][i] != 'P') {
        var->map[var->y][i + 1] = 'X';
        var->map[var->y][i] = ' ';
        i--;
    }
    var->map[var->y][var->x] = ' ';
    var->map[var->y][var->x + 1] = 'P';
    var->x++;
    return var;
}

var_t *move_right(var_t *var)
{
    int i = var->x;

    if (var->map[var->y][var->x + 1] != '#')
        var = move_right_bis(var, i);
    print_map(var->map, var);
    return var;
}
