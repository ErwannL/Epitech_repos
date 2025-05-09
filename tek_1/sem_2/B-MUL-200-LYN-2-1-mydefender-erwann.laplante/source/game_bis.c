/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** game_bis
*/

#include "../include/my.h"

var_t *check_round(var_t *var)
{
    if (var->life_ennemy[0] == 0 && var->flying == 0 && var->heavy == 0)
        var->round = 0;
    return var;
}

var_t *round_on_bis(var_t *var)
{
    for (int i = 0; var->number_ennemy != i; i++) {
        sfSprite_setTextureRect(var->ennemy[i], var->rec_ennemy);
        sfRenderWindow_drawSprite(var->window, var->ennemy[i], NULL);
    }
    for (int i = 0; var->heavy != i; i++) {
        sfSprite_setTextureRect(var->heavy_ennemy[i], var->heavy_rec);
        sfRenderWindow_drawSprite(var->window, var->heavy_ennemy[i], NULL);
    }
    for (int i = 0; var->flying != i; i++) {
        sfSprite_setTextureRect(var->flying_ennemy[i], var->flying_rec);
        sfRenderWindow_drawSprite(var->window, var->flying_ennemy[i], NULL);
    }
    return var;
}

var_t *round_on(var_t *var)
{
    int i = 0;

    var = round_on_bis(var);
    var->time = sfClock_getElapsedTime(var->clock);
    var->seconds = var->time.microseconds / 100000;
    if (var->seconds >= 2) {
        sfClock_restart(var->clock);
        move_ennemy(var);
    }
    var->seconds = 0;
    return var;
}

var_t *round_off(var_t *var)
{
    if (var->event.key.code == sfKeySpace) {
        var->round = 2;
        var->number_round = var->number_round + 1;
    }
    return var;
}

var_t *move_ennemy_new(var_t *var)
{
    for (int i = 0; var->flying != i; i++) {
        if (var->life_flying > 0) {
            move_path_flying(var, i);
            sfRenderWindow_drawSprite(var->window, var->flying_ennemy[i]
            , NULL);
        } else {
            var->flying_ennemy[i] = move_sprite(1000, 1000
            , var->flying_ennemy[i]);
        }
    }
    return var;
}
