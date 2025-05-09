/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-dante-guilhem.vinet
** File description:
** fake_bis
*/

#include "../include/my.h"

var_t *create_fake_neine(var_t *var, int i, int j)
{
    if (var->maze[i][j] != '*') {
        if (var->maze[i - 1][j] == '*'
        && var->maze[i + 1][j] != '*' && var->maze[i][j + 1] != '*'
        && var->maze[i][j - 1] != '*') {
            var->maze[i][j] = '*';
        } else
            var = check_condition(var, i, j, 4);
    }
    return var;
}

var_t *create_fake_eight(var_t *var, int i, int j)
{
    if (j == var->size_x - 1) {
        if (var->maze[i - 1][j] == '*'
        && var->maze[i + 1][j] != '*'
        && var->maze[i][j - 1] != '*' && var->maze[i][j] != '*') {
            var->maze[i][j] = '*';
        } else
            var = check_condition(var, i, j, 3);
    } else {
        var = create_fake_neine(var, i, j);
    }
    return var;
}

var_t *create_fake_seven(var_t *var, int i, int j)
{
    if (i == var->size_y - 1) {
        if (var->maze[i - 1][j] == '*'
        && var->maze[i][j + 1] != '*'
        && var->maze[i][j - 1] != '*' && var->maze[i][j] != '*') {
            var->maze[i][j] = '*';
        } else
            var = check_condition(var, i, j, 2);
    } else {
        var = create_fake_eight(var, i, j);
    }
    return var;
}

var_t *create_fake_six(var_t *var, int i, int j)
{
    if (j == 0) {
        if (var->maze[i - 1][j] == '*'
        && var->maze[i + 1][j] != '*'
        && var->maze[i][j + 1] != '*' && var->maze[i][j] != '*') {
            var->maze[i][j] = '*';
        } else
            var = check_condition(var, i, j, 1);
    } else {
        var = create_fake_seven(var, i, j);
    }
    return var;
}
