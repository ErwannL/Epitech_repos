/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** destroy
*/

#include "../include/my.h"

var_t *destroy_other(var_t *var)
{
    sfFont_destroy(var->font);
    return var;
}

var_t *destroy_clock(var_t *var)
{
    sfClock_destroy(var->clock_cloud);
    sfClock_destroy(var->clock_free_music);
    sfClock_destroy(var->clock_game);
    sfClock_destroy(var->clock_pause);
    return destroy_other(var);
}

var_t *destroy_texture(var_t *var)
{
    sfTexture_destroy(var->texture_background);
    for (int i = 0; i != var->nb_cloud; i++) {
        sfTexture_destroy(var->texture_cloud[i]);
    }
    return destroy_clock(var);
}

var_t *destroy_sprite(var_t *var)
{
    sfSprite_destroy(var->sprite_background);
    sfSprite_destroy(var->sprite_sound);
    for (int i = 0; i != 4; i++) {
        sfSprite_destroy(var->sprite_weapons[i]);
    }
    for (int i = 0; i != var->nb_cloud; i++) {
        sfSprite_destroy(var->sprite_cloud[i]);
    }
    sfSprite_destroy(var->sprite_dark);
    for (int i = 0; i != 8; i++) {
        sfSprite_destroy(var->sprite_play_weapons[i]);
    }
    return destroy_texture(var);
}

var_t *destroy_music(var_t *var)
{
    sfMusic_pause(var->music);
    var->time_game = sfClock_getElapsedTime(var->clock_game);
    var->second_game = var->time_game.microseconds / 10;
    if (var->second_game > 1) {
        sfMusic_stop(var->music);
    }
    var->second_game = 0;
    return destroy_sprite(var);
}
