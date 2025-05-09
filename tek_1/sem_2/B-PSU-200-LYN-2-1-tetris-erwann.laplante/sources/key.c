/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** key
*/

#include "../include/my.h"

var_t *handle_key(var_t *var)
{
    if (var->ch == var->arg->key_pause)
        var->stat = var->stat == GAME ? PAUSE : GAME;
    if (var->ch == var->arg->key_turn && var->stat == GAME)
        var->cursor = turn_piece(var, var->cursor, var->a, var->b);
    if (var->ch == var->arg->key_drop && var->stat == GAME)
        if (check_down(var->map, var->cursor, var->a, var->b) == 0)
            var = place_piece(var, 1);
    if (var->ch == var->arg->key_left && var->stat == GAME)
        if (check_left(var->map, var->cursor, var->a, var->b) == 0)
            var = place_piece(var, 2);
    if (var->ch == var->arg->key_right && var->stat == GAME)
        if (check_right(var->map, var->cursor, var->a, var->b) == 0)
            var = place_piece(var, 3);
    if (check_down(var->map, var->cursor, var->a, var->b) == 0
    && var->stat == GAME)
        var = place_piece(var, 1);
    return var;
}
