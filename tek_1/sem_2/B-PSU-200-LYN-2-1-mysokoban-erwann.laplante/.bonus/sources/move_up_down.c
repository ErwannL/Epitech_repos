/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-erwann.laplante
** File description:
** move_up_down
*/

#include "../include/my.h"

var_t *move_up_bis(var_t *var, int i)
{
    while (var->map[i - 1][var->x] == 'X') {
        if (var->map[i - 2][var->x] == '#')
            return var;
        i--;
    }
    while (var->map[i][var->x] != 'P') {
        var->map[i - 1][var->x] = 'X';
        var->map[i][var->x] = ' ';
        i++;
    }
    var->map[var->y][var->x] = ' ';
    var->map[var->y - 1][var->x] = 'P';
    var->y--;
    return var;
}

var_t *move_up(var_t *var)
{
    int i = var->y;

    if (var->map[var->y - 1][var->x] != '#')
        var = move_up_bis(var, i);
    print_map(var->map, var);
    return var;
}

var_t *move_down_bis(var_t *var, int i)
{
    while (var->map[i + 1][var->x] == 'X') {
        if (var->map[i + 2][var->x] == '#')
            return var;
        i++;
    }
    while (var->map[i][var->x] != 'P') {
        var->map[i + 1][var->x] = 'X';
        var->map[i][var->x] = ' ';
        i--;
    }
    var->map[var->y][var->x] = ' ';
    var->map[var->y + 1][var->x] = 'P';
    var->y++;
    return var;
}

var_t *move_down(var_t *var)
{
    int i = var->y;

    if (var->map[var->y + 1][var->x] != '#')
        var = move_down_bis(var, i);
    print_map(var->map, var);
    return var;
}
