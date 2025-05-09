/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** map
*/

#include "../include/my.h"

/*void print_map_cond(var_t *var, int i, int j)
{
    if (var->map[i][j] >= 65 && var->map[i][j] <= 90)
        print_piece(var, i, j);
    else
        addch(var->map[i][j]);
}*/

void print_map(var_t *var)
{
    clear();
    for (int i = 0; var->map[i]; i++) {
        for (int j = 0; var->map[i][j]; j++)
            addch(var->map[i][j]);
        printw("\n");
    }
    refresh();
}

var_t *fill_map(var_t *var, int i, int j)
{
    if ((i == 0 && j == 0)
    || (i == var->arg->map_size[0] - 1 && j == var->arg->map_size[1] - 1)
    || (i == var->arg->map_size[0] - 1 && j == 0)
    || (i == 0 && j == var->arg->map_size[1] - 1))
        var->map[i][j] = '+';
    else if (i == var->arg->map_size[0] - 1 || i == 0 || j == 0
    || j == var->arg->map_size[1] - 1)
        var->map[i][j] = (i == var->arg->map_size[0] - 1 || i == 0) ? '-'
        : '|';
    else
        var->map[i][j] = ' ';
    return var;
}

var_t *init_map(var_t *var)
{
    var->map = malloc(sizeof(char *) * (var->arg->map_size[0] + 2));
    var->map[var->arg->map_size[0] + 2] = NULL;
    for (int i = 0; i != var->arg->map_size[0]; i++) {
        var->map[i] = malloc(sizeof(char) * (var->arg->map_size[1] + 2));
        var->map[i][var->arg->map_size[1] + 2] = '\0';
    }
    for (int i = 0; i != var->arg->map_size[0]; i++) {
        for (int j = 0; j != var->arg->map_size[1]; j++)
            var = fill_map(var, i, j);
    }
    return var;
}
