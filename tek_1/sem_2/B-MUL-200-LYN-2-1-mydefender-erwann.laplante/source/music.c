/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** music
*/

#include "../include/my.h"

var_t *set_sprite_volume_end(var_t *var)
{
    if (var->volume > 33 && var->volume < 66) {
        var->sound.top = 0;
        var->sound.left = 90;
    } else {
        var->sound.top = 0;
        var->sound.left = 0;
    }
    return var;
}

var_t *set_sprite_volume_start(var_t *var)
{
    if (var->stat_music == MUSIC_OFF || var->volume == 0) {
        var->sound.top = 90;
        var->sound.left = 90;
    } else if (var->volume < 33) {
        var->sound.top = 90;
        var->sound.left = 00;
    } else {
        var = set_sprite_volume_end(var);
    }
    return var;
}
