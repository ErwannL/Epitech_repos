/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-dante-guilhem.vinet
** File description:
** condition
*/

#include "../include/my.h"

var_t *check_condition_two(var_t *var, int i, int j, int n)
{
    if (n == 3 && var->maze[i + 1][j] == '*' && var->maze[i - 1][j] != '*'
    && var->maze[i][j - 1] != '*' && var->maze[i][j] != '*')
        var->maze[i][j] = '*';
    if (n == 3 && var->maze[i][j - 1] == '*' && var->maze[i - 1][j] != '*'
    && var->maze[i + 1][j] != '*' && var->maze[i][j] != '*')
        var->maze[i][j] = '*';
    if (n == 4 && var->maze[i + 1][j] == '*' && var->maze[i - 1][j] != '*'
    && var->maze[i][j + 1] != '*' && var->maze[i][j - 1] != '*')
        var->maze[i][j] = '*';
    if (n == 4 && var->maze[i][j + 1] == '*' && var->maze[i - 1][j] != '*'
    && var->maze[i + 1][j] != '*' && var->maze[i][j - 1] != '*')
        var->maze[i][j] = '*';
    if (n == 4 && var->maze[i][j - 1] == '*' && var->maze[i - 1][j] != '*'
    && var->maze[i + 1][j] != '*' && var->maze[i][j + 1] != '*')
        var->maze[i][j] = '*';
    return var;
}

var_t *check_condition(var_t *var, int i, int j, int n)
{
    if (n == 0 && var->maze[i][j - 1] == '*' && var->maze[i + 1][j] != '*'
    && var->maze[i][j + 1] != '*' && var->maze[i][j] != '*')
        var->maze[i][j] = '*';
    if (n == 0 && var->maze[i][j + 1] == '*' && var->maze[i + 1][j] != '*'
    && var->maze[i][j - 1] != '*' && var->maze[i][j] != '*')
        var->maze[i][j] = '*';
    if (n == 1 && var->maze[i][j + 1] == '*' && var->maze[i - 1][j] != '*'
    && var->maze[i + 1][j] != '*' && var->maze[i][j] != '*')
        var->maze[i][j] = '*';
    if (n == 1 && var->maze[i + 1][j] == '*' && var->maze[i - 1][j] != '*'
    && var->maze[i][j + 1] != '*' && var->maze[i][j] != '*')
        var->maze[i][j] = '*';
    if (n == 2 && var->maze[i][j + 1] == '*' && var->maze[i - 1][j] != '*'
    && var->maze[i][j - 1] != '*' && var->maze[i][j] != '*')
        var->maze[i][j] = '*';
    if (n == 2 && var->maze[i][j - 1] == '*' && var->maze[i - 1][j] != '*'
    && var->maze[i][j + 1] != '*' && var->maze[i][j] != '*')
        var->maze[i][j] = '*';
    var = check_condition_two(var, i, j, n);
    return var;
}
