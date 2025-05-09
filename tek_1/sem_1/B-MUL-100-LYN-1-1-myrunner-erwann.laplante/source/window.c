/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** window
*/

#include "../includes/my.h"

var_t resize_window(var_t var)
{
    sfVector2u a = sfRenderWindow_getSize(var.window);
    sfVector2i b = {0, 0};

    a = sfRenderWindow_getSize(var.window);
    if (a.x < 800 || a.x > 1920) {
        a.x = a.x < 800 ? 800 : 1920;
        sfRenderWindow_clear(var.window, sfBlack);
    }
    if (a.y < 600 || a.y > 1080) {
        a.y = a.y < 600 ? 600 : 1080;
        sfRenderWindow_clear(var.window, sfBlack);
    }
    sfRenderWindow_setSize(var.window, a);
    sfRenderWindow_setPosition(var.window, b);
    sfRenderWindow_clear(var.window, sfBlack);
    return var;
}

var_t update_window_third(var_t var, int y)
{
    var.etat == 2 ? var.y_option = 550 - var.y_option, var =
    set_sprite(var), sfRenderWindow_drawSprite(var.window, var.sprite_option,
    NULL), var.y_option = y : 0;
    sfRenderWindow_display(var.window);
    var.etat == 1 || var.etat == 5 || var.etat == 8 ? var.score++ : 0;
    return var;
}

var_t update_window_second(var_t var)
{
    int x = var.x_option;
    int y = var.y_option;

    sfRenderWindow_drawSprite(var.window, var.sprite_bat3, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_bat4, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_bat5, NULL);
    var.etat == 5 || var.etat == 6 || var.etat == 8 || var.etat == 9
    ? sfRenderWindow_drawSprite(var.window, var.sprite_end, NULL) : 0;
    sfRenderWindow_drawText(var.window, setup_font(var), NULL);
    sfRenderWindow_drawText(var.window, setup_score(var), NULL);
    if (var.etat == 2 || var.etat == 6 || var.etat == 9) {
        var = select_music(var);
        sfSprite_setTextureRect(var.sprite_sound, var.sound);
        sfRenderWindow_drawSprite(var.window, var.sprite_sound, NULL);
        sfRenderWindow_drawText(var.window, setup_font_max(var, 1), NULL);
        sfRenderWindow_drawText(var.window, setup_score_max(var, 1), NULL);
    }
    var = update_window_third(var, y);
    return var;
}

var_t update_window(var_t var)
{
    var.pos_cloud2.x = var.x_cloud2;
    var.pos_cloud2.y = var.y_cloud2;
    var.pos_cloud4.x = var.x_cloud4;
    var.pos_cloud4.y = var.y_cloud4;
    sfSprite_setTextureRect(var.sprite_bird, var.bird);
    sfSprite_setTextureRect(var.sprite_bat, var.bat);
    sfSprite_setTextureRect(var.sprite_bat2, var.bat2);
    sfSprite_setTextureRect(var.sprite_bat3, var.bat3);
    sfSprite_setTextureRect(var.sprite_bat4, var.bat4);
    sfSprite_setTextureRect(var.sprite_bat5, var.bat5);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud2, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_sun, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud3, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud4, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_bird, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_bat, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_bat2, NULL);
    return update_window_second(var);
}
