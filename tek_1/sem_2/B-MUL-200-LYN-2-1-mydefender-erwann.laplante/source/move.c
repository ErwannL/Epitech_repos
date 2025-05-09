/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** move
*/

#include "../include/my.h"

var_t *change_rec(var_t *var)
{
    var->rec_ennemy.left = var->rec_ennemy.left + 42;
    if (var->rec_ennemy.left >= 580) {
        var->rec_ennemy.left = 340;
    }
    if (var->number_round >= 5) {
        var->heavy_rec.left = var->heavy_rec.left + 60;
        if (var->heavy_rec.left >= 566)
            var->heavy_rec.left = 332;
    }
    if (var->number_round >= 2) {
        var->flying_rec.left = var->flying_rec.left + 50;
        if (var->flying_rec.left >= 566)
            var->flying_rec.left = 335;
    }
    return var;
}

var_t *move(var_t *var)
{
    var->time_walk = sfClock_getElapsedTime(var->clock_walk_ennemy);
    var->seconds_walk = var->time_walk.microseconds / 50000;
    if (var->seconds_walk >= 2) {
        var = change_rec(var);
        sfClock_restart(var->clock_walk_ennemy);
    }
    var->seconds_walk = 0;
    return var;
}

var_t *move_path_heavy(var_t *var, int i)
{
    sfVector2f vec = sfSprite_getPosition(var->heavy_ennemy[i]);

    if (var->path_heavy[i] == 0) {
        if (vec.x >= 110)
            var->path_heavy[i] = 1;
        vec.x = vec.x + 5;
        sfSprite_setPosition(var->heavy_ennemy[i], vec);
    }
    more_path_heavy(var, i, vec);
    return var;
}
