/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** line
*/

#include "../include/my.h"

int full_line(var_t *var)
{
    int space = 0;

    for (int i = 1; i != var->arg->map_size[0] - 1; i++) {
        space = 0;
        for (int j = 0; j != var->arg->map_size[1]; j++) {
            (var->map[i][j] == ' ') ? space++ : 0;
        }
        if (space == 0)
            return i;
    }
    return -1;
}

var_t *del_full_line(var_t *var)
{
    var->destroy_line++;
    if (var->destroy_line % 10 == 0)
        var->speed = var->speed >= 1 ? 10 - var->destroy_line / 10
        : var->speed;
    for (int j = 0; j != var->arg->map_size[1]; j++)
        if (var->map[var->full][j] == '*')
            var->map[var->full][j] = ' ';
    for (int i = var->full - 1; i != 1; i--)
        for (int j = 1; j != var->arg->map_size[1] - 1; j++)
            var->map[i + 1][j] = var->map[i][j];
    var->full = full_line(var);
    print_map(var);
    return var;
}
