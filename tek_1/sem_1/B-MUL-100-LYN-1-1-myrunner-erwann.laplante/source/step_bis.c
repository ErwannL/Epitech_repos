/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** step_bis
*/

#include "../includes/my.h"

var_t print_menu_bis(var_t var)
{
    var = move_sprites(var);
    var.bird.top = var.choice_bird * 100;
    var = move_cloud(var);
    var = move_sun(var);
    return var;
}

var_t print_menu(var_t var)
{
    print_menu_bis(var);
    var.x_select = 250;
    var.y_select = 300;
    var.select.height = 256;
    var.select.left = 52;
    var.select.top = 52;
    var.select.width = 584;
    var.texture_select = sfTexture_create(800, 600);
    var.sprite_select = sfSprite_create();
    sfSprite_setTexture(var.sprite_select, var.texture_select, sfTrue);
    sfSprite_setTextureRect(var.sprite_select, var.select);
    var.sprite_select = create_sprite(var.x_select, var.y_select,
    "pictures/select.png", 1);
    var = update_main_menu(var);
    var = detects_event(var);
    if (var.exit_nbr == 84) {
        var.etat = -1;
        return var;
    }
    return var;
}

var_t print_level_bis(var_t var)
{
    var = move_sprites(var);
    var.bird.top = var.choice_bird * 100;
    var = move_cloud(var);
    var = move_sun(var);
    var.x_level = 216;
    var.y_level = 258;
    var.level.height = 256;
    return var;
}

var_t print_level(var_t var)
{
    sfVector2f a = {0.5, 0.5};

    var = print_level_bis(var);
    var.level.left = 52;
    var.level.top = 52;
    var.level.width = 584;
    var.texture_level = sfTexture_create(800, 600);
    var.sprite_level = sfSprite_create();
    sfSprite_setTexture(var.sprite_level, var.texture_level, sfTrue);
    sfSprite_setTextureRect(var.sprite_level, var.level);
    var.sprite_level = create_sprite(var.x_level, var.y_level,
    "pictures/level.png", 1);
    sfSprite_setScale(var.sprite_level, a);
    var = update_main_menu(var);
    var = detects_event(var);
    if (var.exit_nbr == 84) {
        var.etat = -1;
        return var;
    }
    return var;
}
