/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** damage
*/

#include "../include/my.h"

var_t *kill_ennemy(var_t *var, int j, int check)
{
    for (int i = 0; var->number_ennemy != i; i++) {
        if (var->life_ennemy[i] > 0) {
            check = check_range(var->sprite_play_weapons[j]
            , var->ennemy[i], var, j);
            (check > 0) ? damage_ennemy(var, i, check) : 0;
        }
    }
    return var;
}

var_t *kill_heavy(var_t *var, int j, int check)
{
    for (int i = 0; i != var->heavy; i++) {
        if (var->life_heavy[i] > 0) {
            check = check_range(var->sprite_play_weapons[j]
            , var->heavy_ennemy[i], var, j);
            (check > 0) ? damage_heavy(var, i, check) : 0;
        }
    }
    return var;
}

var_t *kill_flying(var_t *var, int j, int check)
{
    for (int i = 0; i != var->flying; i++) {
        if (var->life_flying[i] > 0) {
            check = check_range(var->sprite_play_weapons[j]
            , var->flying_ennemy[i], var, j);
            (check > 0) ? damage_flying(var, i, check) : 0;
        }
    }
    return var;
}

var_t *damage_bis(var_t *var, int j)
{
    int check = 0;

    var = kill_ennemy(var, j, check);
    var = kill_heavy(var, j, check);
    var = kill_flying(var, j, check);
    return var;
}
