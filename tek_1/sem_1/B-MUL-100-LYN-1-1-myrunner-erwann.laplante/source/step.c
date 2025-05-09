/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** step
*/

#include"../includes/my.h"

var_t print_end_bis(var_t var)
{
    var.pos_cloud2.x = var.x_cloud2;
    var.pos_cloud2.y = var.y_cloud2;
    var.pos_cloud4.x = var.x_cloud4;
    var.pos_cloud4.y = var.y_cloud4;
    var = move_cloud(var);
    var = move_sun(var);
    sfRenderWindow_clear(var.window, sfWhite);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud2, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_sun, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud3, NULL);
    sfRenderWindow_drawSprite(var.window, var.sprite_cloud4, NULL);
    sfRenderWindow_drawText(var.window, setup_score(var), NULL);
    sfRenderWindow_drawText(var.window, setup_font(var), NULL);
    sfRenderWindow_drawText(var.window, setup_score_max(var, 1), NULL);
    sfRenderWindow_drawText(var.window, setup_font_max(var, 1), NULL);
    sfRenderWindow_drawText(var.window, setup_lose(var), NULL);
    sfRenderWindow_display(var.window);
    var = detects_event(var);
    return var;
}

var_t print_end(var_t var)
{
    var.nbr = 1;
    var.etat = 4;
    sfRenderWindow_setMouseCursorVisible(var.window, sfTrue);
    var.music2 = sfMusic_createFromFile("music/death.ogg");
    sfMusic_stop(var.music);
    sfMusic_play(var.music2);
    var.exit_nbr = 0;
    var.r_nbr == 0;
    while (var.nbr == 1) {
        var = print_end_bis(var);
        if (var.exit_nbr == 84) {
            var.etat = -1;
            return var;
        }
    }
    sfRenderWindow_setMouseCursorVisible(var.window, sfFalse);
    sfMusic_play(var.music);
    sfMusic_stop(var.music2);
    return var;
}

var_t print_game(var_t var)
{
    var = detects_event(var);
    if (var.exit_nbr == 84 || var.r_nbr == 84) {
        var.etat = -1;
        return var;
    }
    var = move_sprites(var);
    var = animate_bird(var);
    var = animate_bat(var);
    var = move_bat(var);
    var = move_cloud(var);
    var = move_sun(var);
    var = collision(var);
    var = update_window(var);
    if (var.y_bird <= 600 - 10 - var.bird.height) {
        var.y_bird += 0.50;
        var.sprite_bird = move_sprite(var.x_bird, var.y_bird,
        var.sprite_bird);
    }
    return var;
}

var_t print_pause(var_t var)
{
    var = detects_event(var);
    if (var.exit_nbr == 84) {
        var.etat = -1;
        return var;
    }
    var = move_sprites(var);
    var.bird.top = var.choice_bird * 100;
    var = update_window(var);
    return var;
}
