/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** game
*/

#include "../include/my.h"

var_t *round_starting_follow_bis(var_t *var)
{
    if (var->number_round >= 5) {
        var->life_heavy = malloc(sizeof(int) * var->number_round);
        for (int y = 1; var->number_round >= y * 5; y++) {
            var->heavy = var->heavy + 1;
            var->life_heavy[y - 1] = 100;
            var->heavy_ennemy[y - 1] = create_sprite_rec(var->heavy_rec
            , "pictures/sprite.png");
            var->path_heavy[y - 1] = 0;
            sfSprite_setPosition(var->heavy_ennemy[y - 1]
            , create_vector(0 - rand() % 600, 300));
            sfRenderWindow_drawSprite(var->window, var->heavy_ennemy[y - 1]
            , NULL);
        }
    }
    return var;
}

var_t *round_starting_follow(var_t *var)
{
    var->flying_ennemy = malloc(sizeof(sfSprite *) * var->number_round);
    var->life_flying = malloc(sizeof(int) * var->number_round);
    if (var->number_round >= 2) {
        for (int y = 1; var->number_round >= y * 2; y++) {
            var->life_flying[y - 1] = 20;
            var->flying = var->flying + 1;
            var->life_flying[y - 1] = 20;
            var->flying_ennemy[y - 1] = create_sprite_rec(var->flying_rec
            , "pictures/sprite.png");
            var->path_flying[y - 1] = 0;
            sfSprite_setPosition(var->flying_ennemy[y - 1]
            , create_vector(0 - rand() % 600, 300));
            sfRenderWindow_drawSprite(var->window, var->flying_ennemy[y - 1]
            , NULL);
        }
    }
    var = round_starting_follow_bis(var);
    return var;
}

var_t *round_starting(var_t *var)
{
    var->ennemy = malloc(sizeof(sfSprite *) * var->number_round);
    var->life_ennemy = malloc(sizeof(int) * var->number_round);
    var->heavy_ennemy = malloc(sizeof(sfSprite *) * var->number_round);
    var->life_ennemy = malloc(sizeof(int) * var->number_round);
    var->number_ennemy = var->number_round;
    var->flying = 0;
    var->heavy = 0;
    for (int i = 0; var->number_round != i; i++) {
        var->life_ennemy[i] = 50;
        var->ennemy[i] = create_sprite_rec(var->rec_ennemy
        , "pictures/sprite.png");
        var->life_ennemy[i] = 50;
        var->path[i] = 0;
        sfSprite_setPosition(var->ennemy[i], create_vector(0 - rand() % 600
        , 300));
        sfRenderWindow_drawSprite(var->window, var->ennemy[i], NULL);
    }
    round_starting_follow(var);
    var->round = 1;
    return var;
}

var_t *move_ennemy(var_t *var)
{
    for (int i = 0; var->number_ennemy != i && var->ennemy != NULL; i++) {
        if (var->life_ennemy > 0) {
            move_path(var, i);
            sfRenderWindow_drawSprite(var->window, var->ennemy[i], NULL);
        } else {
            var->ennemy[i] = move_sprite(1000, 1000, var->ennemy[i]);
        }
    }
    for (int i = 0; var->heavy != i; i++) {
        if (var->life_heavy > 0) {
            move_path_heavy(var, i);
            sfRenderWindow_drawSprite(var->window, var->heavy_ennemy[i], NULL);
        } else {
            var->heavy_ennemy[i] = move_sprite(1000, 1000
            , var->heavy_ennemy[i]);
        }
    }
    var = move_ennemy_new(var);
    return var;
}

var_t *game(var_t *var)
{
    if (var->round == 2)
        round_starting(var);
    else if (var->round == 1)
        round_on(var);
    else
        round_off(var);
    return var;
}
