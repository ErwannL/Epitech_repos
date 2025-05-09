/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-dante-guilhem.vinet
** File description:
** path
*/

#include "../include/my.h"

var_t *create_path_three(var_t *var)
{
    if (var->j == var->size_x - 1)
        var->i++;
    else if (var->random == 0)
        var->j++;
    else
        var->i++;
    return var;
}

var_t *create_path_two(var_t *var)
{
    if (var->i == 0 && var->j == 0 && var->random == 1)
        var->j++;
    else if (var->i == var->size_y - 1)
        var->j++;
    else
        var = create_path_three(var);
    return var;
}

var_t *create_path(var_t *var)
{
    if (var->i == var->size_y - 1 && var->j == var->size_x - 1)
        var->finish = 1;
    else if (var->i == 0 && var->j == 0 && var->random == 0)
        var->i++;
    else
        var = create_path_two(var);
    return var;
}
