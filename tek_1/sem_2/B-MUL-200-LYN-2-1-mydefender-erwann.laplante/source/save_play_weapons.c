/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** save_play_weapons
*/

#include "../include/my.h"

var_t *save_play_weapons_five(var_t *var, sfVector2i mouse)
{
    if (mouse.x >= 574 + var->dif_x / 2 + var->dif_x / 16
    && mouse.x <= 671 + var->dif_x / 2 + var->dif_x / 4 - var->dif_x / 16
    && mouse.y >= 315 + var->dif_y / 2 + var->dif_y / 8 + var->dif_y / 32
    && mouse.y <= 412 + var->dif_y / 2 + var->dif_y / 4 + var->dif_y / 32
    && detect_key_one_to_four(var) == 0) {
        if (var->x_weapons[var->event.key.code - 76] - 50 <= var->score) {
            move_sprite(574 + var->dif_x / 32, 315 + var->dif_y / 32
            , var->sprite_weapons[var->event.key.code - 76]);
            sfRenderWindow_drawSprite(var->window
            , var->sprite_weapons[var->event.key.code - 76], NULL);
            var->sprite_play_weapons[4] =
            sfSprite_copy(var->sprite_weapons[var->event.key.code - 76]);
            var->score -= var->x_weapons[var->event.key.code - 76] - 50;
            var->turret[4] = var->event.key.code - 75;
            var = reset_pos(var);
        }
    } else {
        var = save_play_weapons_six(var, mouse);
    }
    return var;
}

var_t *save_play_weapons_four(var_t *var, sfVector2i mouse)
{
    if (mouse.x >= 458 + var->dif_x / 2 + var->dif_x / 16
    && mouse.x <= 553 + var->dif_x / 2 + var->dif_x / 4 - var->dif_x / 16
    && mouse.y >= 430 + var->dif_y / 2 + var->dif_y / 8 + var->dif_y / 32
    && mouse.y <= 527 + var->dif_y / 2 + var->dif_y / 4 + var->dif_y / 32
    && detect_key_one_to_four(var) == 0) {
        if (var->x_weapons[var->event.key.code - 76] - 50 <= var->score) {
            move_sprite(458 + var->dif_x / 32, 430 + var->dif_y / 32
            , var->sprite_weapons[var->event.key.code - 76]);
            sfRenderWindow_drawSprite(var->window
            , var->sprite_weapons[var->event.key.code - 76], NULL);
            var->sprite_play_weapons[3] =
            sfSprite_copy(var->sprite_weapons[var->event.key.code - 76]);
            var->score -= var->x_weapons[var->event.key.code - 76] - 50;
            var->turret[3] = var->event.key.code - 75;
            var = reset_pos(var);
        }
    } else {
        var = save_play_weapons_five(var, mouse);
    }
    return var;
}

var_t *save_play_weapons_three(var_t *var, sfVector2i mouse)
{
    if (mouse.x >= 291 + var->dif_x / 5 && mouse.x <= 387 + var->dif_x / 3
    && mouse.y >= 435 + var->dif_y / 5 && mouse.y <= 526 + var->dif_y / 2
    && detect_key_one_to_four(var) == 0) {
        if (var->x_weapons[var->event.key.code - 76] - 50 <= var->score) {
            move_sprite(291 + var->dif_x / 70, 435 + var->dif_y / 50
            , var->sprite_weapons[var->event.key.code - 76]);
            sfRenderWindow_drawSprite(var->window
            , var->sprite_weapons[var->event.key.code - 76], NULL);
            var->sprite_play_weapons[2] =
            sfSprite_copy(var->sprite_weapons[var->event.key.code - 76]);
            var->score -= var->x_weapons[var->event.key.code - 76] - 50;
            var->turret[2] = var->event.key.code - 75;
            var = reset_pos(var);
        }
    } else {
        var = save_play_weapons_four(var, mouse);
    }
    return var;
}

var_t *save_play_weapons_two(var_t *var, sfVector2i mouse)
{
    if (mouse.x >= 177 + var->dif_x / 5 && mouse.x <= 269 + var->dif_x / 3
    && mouse.y >= 301 + var->dif_y / 5 && mouse.y <= 393 + var->dif_y / 2
    && detect_key_one_to_four(var) == 0) {
        if (var->x_weapons[var->event.key.code - 76] - 50 <= var->score) {
            move_sprite(177 + var->dif_x / 70, 301 + var->dif_y / 50
            , var->sprite_weapons[var->event.key.code - 76]);
            sfRenderWindow_drawSprite(var->window
            , var->sprite_weapons[var->event.key.code - 76], NULL);
            var->sprite_play_weapons[1] =
            sfSprite_copy(var->sprite_weapons[var->event.key.code - 76]);
            var->score -= var->x_weapons[var->event.key.code - 76] - 50;
            var->turret[1] = var->event.key.code - 75;
            var = reset_pos(var);
        }
    } else {
        var = save_play_weapons_three(var, mouse);
    }
    return var;
}

var_t *save_play_weapons_one(var_t *var, sfVector2i mouse)
{
    if (mouse.x >= 176 + var->dif_x / 5 && mouse.x <= 269 + var->dif_x / 3
    && mouse.y >= 187 + var->dif_y / 5 && mouse.y <= 279 + var->dif_y / 2
    && detect_key_one_to_four(var) == 0) {
        if (var->x_weapons[var->event.key.code - 76] - 50 <= var->score) {
            move_sprite(176 + var->dif_x / 70, 187 + var->dif_y / 50
            , var->sprite_weapons[var->event.key.code - 76]);
            sfRenderWindow_drawSprite(var->window
            , var->sprite_weapons[var->event.key.code - 76], NULL);
            var->sprite_play_weapons[0] =
            sfSprite_copy(var->sprite_weapons[var->event.key.code - 76]);
            var->score -= var->x_weapons[var->event.key.code - 76] - 50;
            var->turret[0] = var->event.key.code - 75;
            var = reset_pos(var);
        }
    } else {
        var = save_play_weapons_two(var, mouse);
    }
    return var;
}
