/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** print_stat_bis
*/

#include "../include/my.h"

var_t *print_game_bis(var_t *var)
{
    sfRenderWindow_drawText(var->window, setup_game(var, 550, 100
    , var->life > 0 ? int_to_str(var->life) : "0"), NULL);
    var = game(var);
    if (var->round == 1) {
        var = move(var);
        var = damage(var);
        var = entity_death(var);
        var = death(var);
        var = check_round(var);
    }
    sfRenderWindow_display(var->window);
    sfText_destroy(var->text);
    return var;
}

var_t *print_loose(var_t *var)
{
    var = print_background(var);
    sfRenderWindow_drawText(var->window, setup_game(var, 350, 50,
    "You loose !"), NULL);
    sfRenderWindow_drawText(var->window, setup_text(var, 350, 150, "Restart")
    , NULL);
    sfRenderWindow_drawText(var->window, setup_text(var, 350, 350, "Quit")
    , NULL);sfText_destroy(var->text);
    sfRenderWindow_display(var->window);
    sfText_destroy(var->text);
    return var;
}
