/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-dante-guilhem.vinet
** File description:
** fake
*/

#include "../include/my.h"

var_t *create_fake_five(var_t *var, int i, int j)
{
    if (i == 0) {
        if (var->maze[i + 1][j] == '*'
        && var->maze[i][j + 1] != '*'
        && var->maze[i][j - 1] != '*' && var->maze[i][j] != '*') {
            var->maze[i][j] = '*';
        } else
            var = check_condition(var, i, j, 0);
    } else {
        var = create_fake_six(var, i, j);
    }
    return var;
}

var_t *create_fake_four(var_t *var, int i, int j)
{
    if (i == var->size_y - 1 && j == var->size_x - 1) {
        if (var->maze[i - 1][j] == '*'
        && var->maze[i][j - 1] != '*' && var->maze[i][j] != '*') {
            var->maze[i][j] = '*';
        } else if (var->maze[i][j - 1] == '*'
        && var->maze[i - 1][j] != '*' && var->maze[i][j] != '*') {
            var->maze[i][j] = '*';
        }
    } else {
        var = create_fake_five(var, i, j);
    }
    return var;
}

var_t *create_fake_three(var_t *var, int i, int j)
{
    if (i == var->size_y - 1 && j == 0) {
        if (var->maze[i - 1][j] == '*'
        && var->maze[i][j + 1] != '*' && var->maze[i][j] != '*') {
            var->maze[i][j] = '*';
        } else if (var->maze[i][j + 1] == '*'
        && var->maze[i - 1][j] != '*' && var->maze[i][j] != '*') {
            var->maze[i][j] = '*';
        }
    } else {
        var = create_fake_four(var, i, j);
    }
    return var;
}

var_t *create_fake_two(var_t *var, int i, int j)
{
    if (i == 0 && j == var->size_x - 1) {
        if (var->maze[i + 1][j] == '*'
        && var->maze[i][j - 1] != '*' && var->maze[i][j] != '*') {
            var->maze[i][j] = '*';
        } else if (var->maze[i][j - 1] == '*'
        && var->maze[i + 1][j] != '*' && var->maze[i][j] != '*') {
            var->maze[i][j] = '*';
        }
    } else {
        var = create_fake_three(var, i, j);
    }
    return var;
}

var_t *create_fake(var_t *var, int i, int j)
{
    if (i == 0 && j == 0) {
        return var;
    } else {
        var = create_fake_two(var, i, j);
    }
    return var;
}
