/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-dante-guilhem.vinet
** File description:
** maze
*/

#include "../include/my.h"

var_t *make_unperfect(var_t *var)
{
    for (int i = 0; i != var->size_y; i++) {
        for (int j = 0; j != var->size_x; j++) {
            (var->maze[i][j] == 'X' && var->unperfect == 0)
            ? var->maze[i][j] = '*', var->unperfect++ : 0;
        }
        if (var->unperfect != 0)
            return var;
    }
    return var;
}

var_t *create_maze(var_t *var)
{
    while (var->finish == 0) {
        var->random = rand() % 2;
        var = create_path(var);
        var->maze[var->i][var->j] = '*';
    }
    for (int i = 0; i != var->size_y; i++) {
        for (int j = 0; j != var->size_x; j++)
            var = create_fake(var, i, j);
    }
    for (int i = var->size_y - 1; i != 0; i--) {
        for (int j = var->size_x - 1; j != 0; j--)
            var = create_fake(var, i, j);
    }
    if (var->perfect == FALSE)
        var = make_unperfect(var);
    return var;
}
