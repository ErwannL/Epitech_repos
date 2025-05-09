/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** level_bis
*/

#include "../includes/my.h"

var_t first_level(var_t var)
{
    var.etat = 5;
    var.x_bat = 800;
    var.x_bat2 = 850;
    var.x_bat3 = 900;
    var.x_bat4 = 950;
    var.x_bat5 = 1000;
    var.x_end = 1000;
    var.y_end = 0;
    var.end.height = 800;
    var.end.left = 10;
    var.end.top = 10;
    var.end.width = 90;
    var.y_bat = 10;
    var.y_bat2 = 110;
    var.y_bat3 = 210;
    var.y_bat4 = 310;
    var.y_bat5 = 410;
    var.texture_end = sfTexture_create(800, 600);
    var.sprite_end = sfSprite_create();
    return first_level_2(var);
}

var_t second_level_8(var_t var, int c)
{
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

var_t second_level_9(var_t var, int c)
{
    if (var.etat == 10) {
        var = detects_event(var);
        if (var.exit_nbr == 84 || var.r_nbr == 84) {
            var.etat = -1;
            return var;
        }
        var = second_level_8(var, c);
    }
    return var;
}

var_t second_level_7(var_t var, int c)
{
    if (var.etat == 9) {
        var = detects_event(var);
        if (var.exit_nbr == 84) {
            var.etat = -1;
            return var;
        }
        var = move_sprites(var);
        var.bird.top = var.choice_bird * 100;
        var = update_window(var);
    }
    return var;
}

var_t second_level_5(var_t var, int c)
{
    if (var.x_bat5 <= 0) {
        if (c > 0) {
            var.x_bat5 = 1000;
            c--;
        } else
            var.x_bat5 = -400;
    }
    if (var.x_end <= var.x_bird + var.bird.width) {
        var.etat = 10;
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
    return var;
}
