/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** print_stat_bis
*/

#include "../include/my.h"

var_t *print_settings(var_t *var)
{
    sfVector2u size = sfRenderWindow_getSize(var->window);

    var = print_background(var);
    var = set_sprite_volume_start(var),
    sfSprite_setTextureRect(var->sprite_sound, var->sound);
    sfRenderWindow_drawSprite(var->window, var->sprite_sound, NULL);
    sfRenderWindow_drawText(var->window, setup_settings(var, 350, 100
    ,"size x = ") , NULL);
    sfRenderWindow_drawText(var->window, setup_settings(var, 450, 100
    , int_to_str(size.x)) , NULL);
    sfRenderWindow_drawText(var->window, setup_settings(var, 540, 100
    ,"size y = ") , NULL);
    sfRenderWindow_drawText(var->window, setup_settings(var, 640, 100
    , int_to_str(size.y)) , NULL);
    sfRenderWindow_display(var->window);
    free(var->text);
    return var;
}

var_t *print_building(var_t *var)
{
    var = print_background(var);
    for (int i = 0; i != 4; i++) {
        sfRenderWindow_drawSprite(var->window, var->sprite_weapons[i], NULL);
        if (var->score < var->x_weapons[i] - 50) {
            move_sprite(var->x_weapons[i], var->y_weapons[i]
            , var->sprite_dark);
            sfRenderWindow_drawSprite(var->window, var->sprite_dark, NULL);
        }
        sfRenderWindow_drawText(var->window, setup_game(var
        , sfSprite_getPosition(var->sprite_weapons[i]).x, 500
        , var->price_weapons[i]) , NULL);
    }
    sfRenderWindow_drawText(var->window, setup_game(var, 350, 50
    , "Your score = ") , NULL);
    sfRenderWindow_drawText(var->window, setup_game(var, 550, 50
    , var->score != INT_MAX ? int_to_str(var->score) : "MAX") , NULL);
    sfRenderWindow_display(var->window);
    sfText_destroy(var->text);
    return var;
}

var_t *print_game(var_t *var)
{
    var = print_background(var);
    var->time_game = sfClock_getElapsedTime(var->clock_game);
    var->second_game = var->time_game.microseconds / 10000;
    if (var->second_game > 1) {
        var->score != INT_MAX ? var->score++ : 0;
        sfClock_restart(var->clock_game);
    }
    var->second_game = 0;
    for (int i = 0; i != 8; i++)
        sfRenderWindow_drawSprite(var->window, var->sprite_play_weapons[i]
        , NULL);
    sfRenderWindow_drawText(var->window, setup_game(var, 350, 50
    , "Your score = ") , NULL);
    sfRenderWindow_drawText(var->window, setup_game(var, 550, 50
    , var->score != INT_MAX ? int_to_str(var->score) : "MAX") , NULL);
    sfRenderWindow_drawText(var->window, setup_game(var, 350, 100
    , "Your life = ") , NULL);
    var = print_game_bis(var);
    return var;
}

var_t *print_buy(var_t *var)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(var->window);

    sfRenderWindow_drawSprite(var->window, change_image(var->sprite_background
    , "pictures/buy_background.png"), NULL);
    sfRenderWindow_drawSprite(var->window, var->sprite_castle, NULL);
    var = save_play_weapons_one(var, mouse);
    for (int i = 0; i != 8; i++) {
        sfRenderWindow_drawSprite(var->window, var->sprite_play_weapons[i]
        , NULL);
    }
    sfRenderWindow_drawText(var->window, setup_game(var, 350, 50
    , "Your score = ") , NULL);
    sfRenderWindow_drawText(var->window, setup_game(var, 550, 50
    , var->score != INT_MAX ? int_to_str(var->score) : "MAX") , NULL);
    sfRenderWindow_display(var->window);
    sfText_destroy(var->text);
    var->sprite_background = change_image(var->sprite_background
    , "pictures/background.png");
    return var;
}

var_t *print_background(var_t *var)
{
    sfRenderWindow_drawSprite(var->window, var->sprite_background, NULL);
    sfRenderWindow_drawSprite(var->window, var->sprite_castle, NULL);
    return var;
}
