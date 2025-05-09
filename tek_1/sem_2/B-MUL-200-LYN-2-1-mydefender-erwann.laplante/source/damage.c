/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** damage
*/

#include "../include/my.h"

int check_range(sfSprite *weapons, sfSprite *ennemy, var_t *var, int pos)
{
    int x_weap = sfSprite_getPosition(weapons).x + var->weapons->width / 2;
    int y_weap = sfSprite_getPosition(weapons).y + var->weapons->height / 2;
    int x_enne = sfSprite_getPosition(ennemy).x + var->weapons->width / 2;
    int y_enne = sfSprite_getPosition(ennemy).y + var->weapons->height / 2;
    int dist = my_sqrt((x_enne - x_weap) * (x_enne - x_weap)
    + (y_enne - y_weap) * (y_enne - y_weap));

    if (dist <= 200) {
        return var->turret[pos];
    }
    return 0;
}

var_t *damage_ennemy(var_t *var, int i, int check)
{
    if (check == 1) {
        var->life_ennemy[i] = var->life_ennemy[i] - 10;
    }
    if (check == 2) {
        var->life_ennemy[i] = var->life_ennemy[i] - 10;
    }
    if (check == 3) {
        return var;
    }
    if (check == 4) {
        var->life_ennemy[i] = var->life_ennemy[i] - 10;
    }
    return var;
}

var_t *damage_heavy(var_t *var, int i, int check)
{
    if (check == 1) {
        var->life_heavy[i] = var->life_heavy[i] - 10;
    }
    if (check == 2) {
        var->life_heavy[i] = var->life_heavy[i] - 10;
    }
    if (check == 3) {
        return var;
    }
    if (check == 4) {
        var->life_heavy[i] = var->life_heavy[i] - 10;
    }
    return var;
}

var_t *damage_flying(var_t *var, int i, int check)
{
    if (check == 3) {
        var->life_flying[i] = var->life_flying[i] - 10;
    }
    if (check == 4) {
        var->life_flying[i] = var->life_flying[i] - 10;
    }
    return var;
}

var_t *damage(var_t *var)
{
    var->time_deg_en = sfClock_getElapsedTime(var->clock_deg_en);
    var->second_deg_en = var->time_deg_en.microseconds / 500000;
    if (var->second_deg_en > 1) {
        for (int j = 0; j != 8; j++) {
            var = damage_bis(var, j);
        }
        sfClock_restart(var->clock_deg_en);
    }
    var->second_deg_en = 0;
    return var;
}
