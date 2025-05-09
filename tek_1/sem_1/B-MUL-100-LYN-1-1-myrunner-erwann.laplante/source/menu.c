/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** menu
*/

#include "../includes/my.h"

var_t update_main_menu_third(var_t var, int y)
{
    var.y_option = 550 - var.y_option;
    var = set_sprite(var);
    sfRenderWindow_drawSprite(var.window, var.sprite_option, NULL);
    var.y_option = y;
    var = select_music(var);
    sfSprite_setTextureRect(var.sprite_bird, var.bird);
    sfRenderWindow_drawSprite(var.window, var.sprite_bird, NULL);
    sfSprite_setTextureRect(var.sprite_sound, var.sound);
    sfRenderWindow_drawSprite(var.window, var.sprite_sound, NULL);
    return var;
}

var_t update_main_menu_second(var_t var)
{
    int x = var.x_option;
    int y = var.y_option;

    if (var.etat == 0) {
        sfRenderWindow_drawSprite(var.window, var.sprite_start, NULL);
        sfRenderWindow_drawSprite(var.window, var.sprite_option, NULL);
        sfRenderWindow_drawSprite(var.window, var.sprite_select, NULL);
    } else if (var.etat == 11) {
        sfSprite_setTextureRect(var.sprite_level, var.level);
        sfRenderWindow_drawSprite(var.window, var.sprite_level, NULL);
        sfRenderWindow_drawSprite(var.window, var.sprite_option, NULL);
        sfRenderWindow_drawText(var.window, setup_level(var), NULL);
    } else {
        var = update_main_menu_third(var, y);
    }
    return var;
}

var_t update_main_menu(var_t var)
{
    var.pos_cloud2.x = var.x_cloud2;
    var.pos_cloud2.y = var.y_cloud2;
    var.pos_cloud4.x = var.x_cloud4;
    var.pos_cloud4.y = var.y_cloud4;
    sfRenderWindow_clear(var.window, sfWhite);
    var = move_sprites(var);
    var = animate_bird(var);
    var = animate_bat(var);
    var = move_bat(var);
    var = move_cloud(var);
    var = move_sun(var);
    var = collision(var);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud2, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_sun, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud3, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud4, NULL);
    sfRenderWindow_drawText(var.window, setup_font_max(var, 0), NULL);
    sfRenderWindow_drawText(var.window, setup_score_max(var, 0), NULL);
    var = update_main_menu_second(var);
    sfRenderWindow_display(var.window);
    return var;
}
