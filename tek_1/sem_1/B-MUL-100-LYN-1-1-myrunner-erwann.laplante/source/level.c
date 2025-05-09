/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** level
*/

#include "../includes/my.h"

var_t first_level_6(var_t var, int i)
{
    if (i == 0) {
        if (var.etat == 6) {
            var = detects_event(var);
            if (var.exit_nbr == 84) {
                var.etat = -1;
                return var;
            }
            var = move_sprites(var);
            var.bird.top = var.choice_bird * 100;
            var = update_window(var);
        }
    } else {
        sfSprite_setTexture(var.sprite_end, var.texture_end, sfTrue);
        sfSprite_setTextureRect(var.sprite_end, var.end);
        var.sprite_end = create_sprite(var.x_end, var.y_end,
        "pictures/end.png", 1);
    }
    return var;
}

var_t first_level_5(var_t var)
{
    var = detects_event(var);
    if (var.exit_nbr == 84 || var.r_nbr == 84) {
        var.etat = -1;
        return var;
    }
    var = move_cloud(var);
    var = move_sun(var);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud2, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_sun, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud3, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud4, NULL);
    sfRenderWindow_drawText(var.window, setup_score(var), NULL);
    sfRenderWindow_drawText(var.window, setup_font(var), NULL);
    sfRenderWindow_drawText(var.window, setup_score_max(var, 1), NULL);
    sfRenderWindow_drawText(var.window, setup_font_max(var, 1), NULL);
    sfRenderWindow_drawText(var.window, setup_win(var), NULL);
    sfRenderWindow_display(var.window);
    var = resize_window(var);
    return var;
}

var_t first_level_4(var_t var)
{
    if (var.x_bat3 <= 0) {
        var.x_bat3 = -400;
    }
    if (var.x_bat4 <= 0) {
        var.x_bat4 = -400;
    }
    if (var.x_bat5 <= 0) {
        var.x_bat5 = -400;
    }
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
    return var;
}

var_t first_level_3(var_t var)
{
    sfSprite_setTextureRect(var.sprite_end, var.end);
    if (var.x_end <= var.x_bird + var.bird.width) {
        var.etat = 7;
    }
    var = detects_event(var);
    if (var.exit_nbr == 84 || var.r_nbr == 84) {
        var.etat = -1;
        return var;
    }
    var = move_sprites(var);
    var = animate_bird(var);
    var = animate_bat(var);
    var = move_bat(var);
    if (var.x_bat <= 0) {
        var.x_bat = -400;
    }
    if (var.x_bat2 <= 0) {
        var.x_bat2 = -400;
    }
    return var;
}

var_t first_level_2(var_t var)
{
    var = first_level_6(var, 1);
    while (sfRenderWindow_isOpen(var.window)) {
        if (var.etat == 5) {
            var = first_level_3(var);
            var = first_level_4(var);
            var.x_end -= 2;
        }
        var = first_level_6(var, 0);
        if (var.etat == 7)
            var = first_level_5(var);
        if (var.etat == 0)
            return var;
        if (var.exit_nbr == 84 || var.r_nbr == 84) {
            var.etat = -1;
            return var;
        }
    }
    return var;
}
