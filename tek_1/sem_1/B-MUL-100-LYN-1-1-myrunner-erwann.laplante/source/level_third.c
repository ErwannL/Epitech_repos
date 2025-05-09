/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** level_third
*/

#include "../includes/my.h"

var_t second_level_4(var_t var, int c)
{
    if (var.x_bat3 <= 0) {
        if (c > 0) {
            var.x_bat3 = 900;
            c--;
        } else
            var.x_bat3 = -400;
    }
    if (var.x_bat4 <= 0) {
        if (c > 0) {
            var.x_bat4 = 950;
            c--;
        } else
            var.x_bat4 = -400;
    }
    return var;
}

var_t second_level_3(var_t var, int c)
{
    sfSprite_setTextureRect(var.sprite_end, var.end);
    if (var.x_bat <= 0) {
        if (c > 0) {
            var.x_bat = 800;
            c--;
        } else
            var.x_bat = -400;
    }
    if (var.x_bat2 <= 0) {
        if (c > 0) {
            var.x_bat2 = 850;
            c--;
        } else
            var.x_bat2 = -400;
    }
    return var;
}

var_t second_level_6(var_t var, int c)
{
    if (var.etat == 8) {
        var = second_level_3(var, c);
        var = second_level_4(var, c);
        var = second_level_5(var, c);
        var = move_cloud(var);
        var = move_sun(var);
        var = collision(var);
        if (var.y_bird <= 600 - 10 - var.bird.height) {
            var.y_bird += 0.50;
            var.sprite_bird = move_sprite(var.x_bird, var.y_bird,
            var.sprite_bird);
        }
        var = resize_window(var);
        var = update_window(var);
        var.x_end -= 2;
    }
    return var;
}

var_t second_level_2(var_t var)
{
    var.etat = 8;
    var.x_bat = 800;
    var.x_bat2 = 850;
    var.x_bat3 = 900;
    var.x_bat4 = 950;
    var.x_bat5 = 1000;
    var.x_end = 2000;
    var.y_end = 0;
    var.end.height = 800;
    var.end.left = 10;
    var.end.top = 10;
    var.end.width = 90;
    var.y_bat = 150;
    var.y_bat2 = 250;
    var.y_bat3 = 350;
    var.y_bat4 = 450;
    var.y_bat5 = 550;
    var.texture_end = sfTexture_create(800, 600);
    var.sprite_end = sfSprite_create();
    return var;
}

var_t second_level(var_t var)
{
    int c = 5;

    var = second_level_2(var);
    sfSprite_setTexture(var.sprite_end, var.texture_end, sfTrue);
    sfSprite_setTextureRect(var.sprite_end, var.end);
    var.sprite_end = create_sprite(var.x_end, var.y_end,
    "pictures/end.png", 1);
    while (sfRenderWindow_isOpen(var.window)) {
        var = second_level_6(var, c);
        var = second_level_7(var, c);
        var = second_level_9(var, c);
        if (var.etat == 0)
            return var;
        if (var.exit_nbr == 84 || var.r_nbr == 84) {
            var.etat = -1;
            return var;
        }
    }
    return var;
}
