/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** save_play_weapons_bis
*/

#include "../include/my.h"

var_t *save_play_weapons_eight(var_t *var, sfVector2i mouse)
{
    if (mouse.x >= 345 + var->dif_x / 2 + var->dif_x / 16
    && mouse.x <= 441 + var->dif_x / 2 + var->dif_x / 4 - var->dif_x / 16
    && mouse.y >= 134 + var->dif_y / 2 + var->dif_y / 8 + var->dif_y / 32
    && mouse.y <= 228 + var->dif_y / 2 + var->dif_y / 4 + var->dif_y / 32
    && detect_key_one_to_four(var) == 0) {
        if (var->x_weapons[var->event.key.code - 76] - 50 <= var->score) {
            move_sprite(345 + var->dif_x / 32, 134 + var->dif_y / 32
            , var->sprite_weapons[var->event.key.code - 76]);
            sfRenderWindow_drawSprite(var->window
            , var->sprite_weapons[var->event.key.code - 76], NULL);
            var->sprite_play_weapons[7] =
            sfSprite_copy(var->sprite_weapons[var->event.key.code - 76]);
            var->score -= var->x_weapons[var->event.key.code - 76] - 50;
            var->turret[7] = var->event.key.code - 75;
            var = reset_pos(var);
        }
    }
    return var;
}

var_t *save_play_weapons_seven(var_t *var, sfVector2i mouse)
{
    if (mouse.x >= 372 + var->dif_x / 2 + var->dif_x / 16
    && mouse.x <= 469 + var->dif_x / 2 + var->dif_x / 4 - var->dif_x / 16
    && mouse.y >= 259 + var->dif_y / 2 + var->dif_y / 8 + var->dif_y / 32
    && mouse.y <= 354 + var->dif_y / 2 + var->dif_y / 4 + var->dif_y / 32
    && detect_key_one_to_four(var) == 0) {
        if (var->x_weapons[var->event.key.code - 76] - 50 <= var->score) {
            move_sprite(372 + var->dif_x / 32, 259 + var->dif_y / 32
            , var->sprite_weapons[var->event.key.code - 76]);
            sfRenderWindow_drawSprite(var->window
            , var->sprite_weapons[var->event.key.code - 76], NULL);
            var->sprite_play_weapons[6] =
            sfSprite_copy(var->sprite_weapons[var->event.key.code - 76]);
            var->score -= var->x_weapons[var->event.key.code - 76] - 50;
            var->turret[6] = var->event.key.code - 75;
            var = reset_pos(var);
        }
    } else {
        var = save_play_weapons_eight(var, mouse);
    }
    return var;
}

var_t *save_play_weapons_six(var_t *var, sfVector2i mouse)
{
    if (mouse.x >= 575 + var->dif_x / 2 + var->dif_x / 16
    && mouse.x <= 673 + var->dif_x / 2 + var->dif_x / 4 - var->dif_x / 16
    && mouse.y >= 134 + var->dif_y / 2 + var->dif_y / 8 + var->dif_y / 32
    && mouse.y <= 230 + var->dif_y / 2 + var->dif_y / 4 + var->dif_y / 32
    && detect_key_one_to_four(var) == 0) {
        if (var->x_weapons[var->event.key.code - 76] - 50 <= var->score) {
            move_sprite(575 + var->dif_x / 32, 134 + var->dif_y / 32
            , var->sprite_weapons[var->event.key.code - 76]);
            sfRenderWindow_drawSprite(var->window
            , var->sprite_weapons[var->event.key.code - 76], NULL);
            var->sprite_play_weapons[5] =
            sfSprite_copy(var->sprite_weapons[var->event.key.code - 76]);
            var->score -= var->x_weapons[var->event.key.code - 76] - 50;
            var->turret[5] = var->event.key.code - 75;
            var = reset_pos(var);
        }
    } else {
        var = save_play_weapons_seven(var, mouse);
    }
    return var;
}

int detect_key_one_to_four(var_t *var)
{
    if (var->event.key.code == sfKeyNumpad1
    || var->event.key.code == sfKeyNumpad2
    || var->event.key.code == sfKeyNumpad3
    || var->event.key.code == sfKeyNumpad4)
        return 0;
    return 1;
}

var_t *reset_pos(var_t *var)
{
    sfMusic_pause(var->gold);
    move_sprite(var->x_weapons[var->event.key.code - 76]
    , var->y_weapons[var->event.key.code - 76]
    , var->sprite_weapons[var->event.key.code - 76]);
    sfMusic_play(var->gold);
    return var;
}
