/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** death
*/

#include "../include/my.h"

var_t *entity_death_ter(var_t *var)
{
    if (var->heavy == 0) {
        sfSprite_setPosition(var->heavy_ennemy[0]
        , create_vector(-1000, -1000));
    }
    for (int i = 0; i != var->heavy; i++) {
        if (var->life_heavy[i] == 0) {
            var->path_heavy = my_intncat(var->path_heavy, i, var->heavy);
            var->life_heavy = my_intncat(var->life_heavy, i, var->heavy);
            var->heavy_ennemy = my_spritencat(var->heavy_ennemy, i
            , var->heavy);
            var->heavy = var->heavy - 1;
            i--;
        }
    }
    return var;
}

var_t *entity_death_bis(var_t *var)
{
    if (var->flying == 0) {
        sfSprite_setPosition(var->flying_ennemy[0]
        , create_vector(-1000, -1000));
    }
    for (int i = 0; i != var->flying; i++) {
        if (var->life_flying[i] == 0) {
            var->path_flying = my_intncat(var->path_flying, i, var->flying);
            var->life_flying = my_intncat(var->life_flying, i, var->flying);
            var->flying_ennemy = my_spritencat(var->flying_ennemy, i
            , var->flying);
            var->flying = var->flying - 1;
            i--;
        }
    }
    if (var->number_round >= 5)
        var = entity_death_ter(var);
    return var;
}

var_t *entity_death(var_t *var)
{
    if (var->number_ennemy == 0) {
        sfSprite_setPosition(var->ennemy[0], create_vector(-1000, -1000));
    }
    for (int i = 0; i != var->number_ennemy; i++) {
        if (var->life_ennemy[i] == 0) {
            var->path = my_intncat(var->path, i, var->number_ennemy);
            var->life_ennemy = my_intncat(var->life_ennemy, i
            , var->number_ennemy);
            var->ennemy = my_spritencat(var->ennemy, i, var->number_ennemy);
            var->number_ennemy = var->number_ennemy - 1;
            i--;
        }
    }
    if (var->number_round >= 2)
        entity_death_bis(var);
    return var;
}

var_t *death(var_t *var)
{
    var->time_kill = sfClock_getElapsedTime(var->clock_kill);
    var->second_kill = var->time_kill.microseconds / 500000;
    if (var->second_kill > 1) {
        for (int i = 0; var->number_round != i; i++)
            sfSprite_getPosition(var->ennemy[i]).x >= 700 ? var->life -= 1 : 0;
        for (int i = 0; var->heavy != i; i++)
            sfSprite_getPosition(var->heavy_ennemy[i]).x >= 700
            ? var->life -= 5 : 0;
        for (int i = 0; var->flying != i; i++)
            sfSprite_getPosition(var->flying_ennemy[i]).x >= 700
            ? var->life -= 3 : 0;
        sfClock_restart(var->clock_kill);
    }
    var->second_kill = 0;
    if (var->life <= 0) {
        var->etat = STAT_LOOSE;
    }
    return var;
}
