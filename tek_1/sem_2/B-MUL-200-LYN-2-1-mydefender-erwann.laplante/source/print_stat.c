/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** print_stat
*/

#include "../include/my.h"

var_t *else_print_menu(var_t *var)
{
    for (int i = 0; i != var->nb_cloud; i++) {
        var->x_cloud[i] = 0;
        var->y_cloud[i] = 0;
    }
    var->sprite_background = change_scale(var->sprite_background, 2, 2);
    sfRenderWindow_drawSprite(var->window, change_image(var->sprite_background
    , "pictures/menu.png"), NULL);
    sfRenderWindow_drawText(var->window, setup_text(var, 350, 150, "Start")
    , NULL);
    sfRenderWindow_drawText(var->window, setup_text(var, 350, 250
    , "Settings"), NULL);
    sfRenderWindow_drawText(var->window, setup_text(var, 350, 350, "Quit")
    , NULL);
    sfRenderWindow_display(var->window);
    sfText_destroy(var->text);
    var->sprite_background = change_scale(var->sprite_background, 1.4, 1.5);
    var->sprite_background = change_image(var->sprite_background
    , "pictures/background.png");
    return var;
}

var_t *print_menu(var_t *var)
{
    if (var->previous_stat == STAT_PAUSE) {
        var->time_pause = sfClock_getElapsedTime(var->clock_pause);
        var->second_pause = var->time_pause.microseconds / 100000;
        if (var->second_pause > 1) {
            var->previous_stat = STAT_GAME;
            sfClock_restart(var->clock_pause);
        }
        var->second_pause = 0;
    } else {
        var = else_print_menu(var);
    }
    return var;
}

var_t *print_how_play(var_t *var)
{
    int x = 10;
    int y = 50;

    var = print_background(var);
    sfRenderWindow_drawText(var->window, setup_how_play(var, x, y
    , var->how_play[0]), NULL);
    y += 50;
    for (int i = 1; i != 11; y += 40, i++) {
        sfRenderWindow_drawText(var->window, setup_how_play(var, x, y
        , var->how_play[i]), NULL);
    }
    x = 400;
    y = 50;
    for (int i = 11; i != 22; y += 40, i++) {
        sfRenderWindow_drawText(var->window, setup_how_play(var, x, y
        , var->how_play[i]), NULL);
    }
    sfRenderWindow_display(var->window);
    sfText_destroy(var->text);
    return var;
}

var_t *print_intro(var_t *var)
{
    var = print_background(var);
    for (int i = 0; i != var->nb_cloud; i++) {
        var->sprite_cloud[i] = move_sprite(var->x_cloud[i], var->y_cloud[i]
        , var->sprite_cloud[i]);
        sfRenderWindow_drawSprite(var->window, var->sprite_cloud[i], NULL);
    }
    var->time_cloud = sfClock_getElapsedTime(var->clock_cloud);
    var->second_cloud = var->time_cloud.microseconds / 10;
    if (var->second_cloud > 1) {
        var->x_cloud[0] += 3;
        var->x_cloud[1] -= 3;
        var->y_cloud[2] += 3;
        var->y_cloud[3] -= 3;
        sfClock_restart(var->clock_cloud);
    }
    var->second_cloud = 0;
    if (var->x_cloud[0] > 800)
        var->etat = STAT_GAME;
    sfRenderWindow_display(var->window);
    return var;
}

var_t *print_pause(var_t *var)
{
    var = print_background(var);
    sfRenderWindow_drawText(var->window, setup_pause(var, 350, 150, "Resume")
    , NULL);
    sfRenderWindow_drawText(var->window, setup_pause(var, 350, 250
    , "Menu"), NULL);
    sfRenderWindow_drawText(var->window, setup_pause(var, 350, 350, "Quit")
    , NULL);
    sfRenderWindow_display(var->window);
    sfText_destroy(var->text);
    return var;
}
