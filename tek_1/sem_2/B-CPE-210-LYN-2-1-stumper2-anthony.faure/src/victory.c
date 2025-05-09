/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper2-anthony.faure
** File description:
** victory
*/

#include "../include/my.h"

int check_victory_cond_fou(var_t *var, int i, int j)
{
    if (i + 3 <= var->height + 1 && j + 3 <= var->width + 1
    && var->map[i][j] == var->p2 && var->map[i + 1][j + 1] == var->p2
    && var->map[i + 2][j + 2] == var->p2
    && var->map[i + 3][j + 3] == var->p2) {
        var->map[i][j] = var->ref;
        var->map[i + 1][j + 1] = var->ref;
        var->map[i + 2][j + 2] = var->ref;
        var->map[i + 3][j + 3] = var->ref;
        return 2;
    } else if (j >= 4 && var->map[i][j] == var->p2
    && var->map[i + 1][j - 1] == var->p2 && var->map[i + 2][j - 2] == var->p2
    && var->map[i + 3][j - 3] == var->p2) {
        var->map[i][j] = var->ref;
        var->map[i + 1][j - 1] = var->ref;
        var->map[i + 2][j - 2] = var->ref;
        var->map[i + 3][j - 3] = var->ref;
        return 2;
    }
    return 84;
}

int check_victory_cond_thr(var_t *var, int i, int j)
{
    if (j + 3 <= var->width + 1 && var->map[i][j] == var->p2
    && var->map[i][j + 1] == var->p2 && var->map[i][j + 2] == var->p2
    && var->map[i][j + 3] == var->p2) {
        var->map[i][j] = var->ref;
        var->map[i][j + 1] = var->ref;
        var->map[i][j + 2] = var->ref;
        var->map[i][j + 3] = var->ref;
        return 2;
    } else if (i + 3 <= var->height + 1 && var->map[i][j] == var->p2
    && var->map[i + 1][j] == var->p2 && var->map[i + 1][j] == var->p2
    && var->map[i + 3][j] == var->p2) {
        var->map[i][j] = var->ref;
        var->map[i + 1][j] = var->ref;
        var->map[i + 2][j] = var->ref;
        var->map[i + 3][j] = var->ref;
        return 2;
    } else {
        return check_victory_cond_fou(var, i, j);
    }
}

int check_victory_cond_scd(var_t *var, int i, int j)
{
    if (i + 3 <= var->height + 1 && j + 3 <= var->width + 1
    && var->map[i][j] == var->p1 && var->map[i + 1][j + 1] == var->p1
    && var->map[i + 2][j + 2] == var->p1
    && var->map[i + 3][j + 3] == var->p1) {
        var->map[i][j] = var->ref;
        var->map[i + 1][j + 1] = var->ref;
        var->map[i + 2][j + 2] = var->ref;
        var->map[i + 3][j + 3] = var->ref;
        return 1;
    } else if (j >= 4 && var->map[i][j] == var->p1
    && var->map[i + 1][j - 1] == var->p1 && var->map[i + 2][j - 2] == var->p1
    && var->map[i + 3][j - 3] == var->p1) {
        var->map[i][j] = var->ref;
        var->map[i + 1][j - 1] = var->ref;
        var->map[i + 2][j - 2] = var->ref;
        var->map[i + 3][j - 3] = var->ref;
        return 1;
    } else {
        return check_victory_cond_thr(var, i, j);
    }
}

int check_victory_cond_one(var_t *var, int i, int j)
{
    if (j + 3 <= var->width + 1 && var->map[i][j] == var->p1
    && var->map[i][j + 1] == var->p1 && var->map[i][j + 2] == var->p1
    && var->map[i][j + 3] == var->p1) {
        var->map[i][j] = var->ref;
        var->map[i][j + 1] = var->ref;
        var->map[i][j + 2] = var->ref;
        var->map[i][j + 3] = var->ref;
        return 1;
    } else if (i + 3 <= var->height + 1 && var->map[i][j] == var->p1
    && var->map[i + 1][j] == var->p1 && var->map[i + 1][j] == var->p1
    && var->map[i + 3][j] == var->p1) {
        var->map[i][j] = var->ref;
        var->map[i + 1][j] = var->ref;
        var->map[i + 2][j] = var->ref;
        var->map[i + 3][j] = var->ref;
        return 1;
    } else {
        return check_victory_cond_scd(var, i, j);
    }
}

int check_victory(var_t *var)
{
    int val = 84;

    for (int i = 1; i != var->height + 1; i++) {
        for (int j = 1; j != var->width + 1; j++) {
            val = val != 84 ? val : check_victory_cond_one(var, i, j);
        }
        if (val != 84)
            return val;
    }
    return 84;
}
