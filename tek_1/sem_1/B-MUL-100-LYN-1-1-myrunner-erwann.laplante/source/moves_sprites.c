/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** moves_sprites
*/

#include "../includes/my.h"

sfSprite *move_sprite(float x, float y, sfSprite *sprite)
{
    sfVector2f my_pos = {x, y};

    sfSprite_setPosition(sprite, my_pos);
    return (sprite);
}

var_t move_sprites2(var_t var, sfVector2f b, sfVector2f c)
{
    move_sprite(var.x_option, var.y_option, var.sprite_option);
    move_sprite(var.x_sound, var.y_sound, var.sprite_sound);
    sfSprite_setScale(var.sprite_option, var.etat != 3 && var.etat != 2 ? b :
    c);
    return var;
}

var_t move_sprites(var_t var)
{
    sfVector2f a = {0.5, 0.5};
    sfVector2f b = {0.1, 0.1};
    sfVector2f c = {0.2, 0.2};

    move_sprite(var.x_cloud, var.y_cloud,var.sprite_cloud);
    sfSprite_setPosition(var.sprite_cloud2, var.pos_cloud2);
    move_sprite(var.x_bird, var.y_bird, var.sprite_bird);
    move_sprite(var.x_bat, var.y_bat, var.sprite_bat);
    move_sprite(var.x_bat2, var.y_bat2, var.sprite_bat2);
    move_sprite(var.x_bat3, var.y_bat3, var.sprite_bat3);
    move_sprite(var.x_bat4, var.y_bat4, var.sprite_bat4);
    move_sprite(var.x_bat5, var.y_bat5, var.sprite_bat5);
    move_sprite(var.x_cloud3, var.y_cloud3, var.sprite_cloud3);
    move_sprite(var.x_cloud4, var.y_cloud4, var.sprite_cloud4);
    move_sprite(var.x_sun, var.y_sun, var.sprite_sun);
    move_sprite(var.x_start, var.y_start, var.sprite_start);
    var.etat == 5 || var.etat == 8 ? move_sprite(var.x_end,
    var.y_end,var.sprite_end) : 0;
    sfSprite_setScale(var.sprite_start, a);
    return move_sprites2(var, b, c);
}
