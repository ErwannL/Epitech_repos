/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** path
*/

#include "../include/my.h"

var_t *more_path(var_t *var, int i, sfVector2f vec)
{
    if (var->path[i] == 1) {
        if (vec.y <= 130)
            var->path[i] = 2;
        vec.y = vec.y - 10;
        sfSprite_setPosition(var->ennemy[i], vec);
    }
    if (var->path[i] == 2) {
        if (vec.x >= 280)
            var->path[i] = 3;
        vec.x = vec.x + 10;
        sfSprite_setPosition(var->ennemy[i], vec);
    }
    if (var->path[i] == 3) {
        if (vec.y >= 350)
            var->path[i] = 4;
        vec.y = vec.y + 10;
        sfSprite_setPosition(var->ennemy[i], vec);
    }
    more_more_path(var, i, vec);
    return var;
}

var_t *more_more_path(var_t *var, int i, sfVector2f vec)
{
    if (var->path[i] == 4) {
        if (vec.x >= 500)
            var->path[i] = 5;
        vec.x = vec.x + 10;
        sfSprite_setPosition(var->ennemy[i], vec);
    }
    if (var->path[i] == 5) {
        if (vec.y <= 260)
            var->path[i] = 6;
        vec.y = vec.y - 10;
        sfSprite_setPosition(var->ennemy[i], vec);
    }
    if (var->path[i] == 6) {
        if (vec.x >= 700)
            var->path[i] = 7;
        vec.x = vec.x + 10;
        sfSprite_setPosition(var->ennemy[i], vec);
    }
    return var;
}

var_t *more_more_path_heavy(var_t *var, int i, sfVector2f vec)
{
    if (var->path_heavy[i] == 4) {
        if (vec.x >= 500)
            var->path_heavy[i] = 5;
        vec.x = vec.x + 5;
        sfSprite_setPosition(var->heavy_ennemy[i], vec);
    }
    if (var->path_heavy[i] == 5) {
        if (vec.y <= 260)
            var->path_heavy[i] = 6;
        vec.y = vec.y - 5;
        sfSprite_setPosition(var->heavy_ennemy[i], vec);
    }
    if (var->path_heavy[i] == 6) {
        if (vec.x >= 700)
            var->path_heavy[i] = 7;
        vec.x = vec.x + 5;
        sfSprite_setPosition(var->heavy_ennemy[i], vec);
    }
    return var;
}

var_t *more_path_heavy(var_t *var, int i, sfVector2f vec)
{
    if (var->path_heavy[i] == 1) {
        if (vec.y <= 130)
            var->path_heavy[i] = 2;
        vec.y = vec.y - 5;
        sfSprite_setPosition(var->heavy_ennemy[i], vec);
    }
    if (var->path_heavy[i] == 2) {
        if (vec.x >= 280)
            var->path_heavy[i] = 3;
        vec.x = vec.x + 5;
        sfSprite_setPosition(var->heavy_ennemy[i], vec);
    }
    if (var->path_heavy[i] == 3) {
        if (vec.y >= 350)
            var->path_heavy[i] = 4;
        vec.y = vec.y + 5;
        sfSprite_setPosition(var->heavy_ennemy[i], vec);
    }
    more_more_path_heavy(var, i, vec);
    return var;
}

var_t *move_path(var_t *var, int i)
{
    int y = 0;

    sfVector2f vec = sfSprite_getPosition(var->ennemy[i]);
    if (var->path[i] == 0) {
        if (vec.x >= 110)
            var->path[i] = 1;
        vec.x = vec.x + 10;
        sfSprite_setPosition(var->ennemy[i], vec);
    }
    more_path(var, i, vec);
    return var;
}
