/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** restart
*/

#include "../include/my.h"

var_t *restart_four(var_t *var, sfVector2f scale)
{
    for (int i = 0; i != 8; i++) {
        var->sprite_play_weapons[i] = sfSprite_copy(var->sprite_weapons[0]);
        move_sprite(2000, 2000, var->sprite_play_weapons[i]);
    }
    var->life = 100;
    var->score = 1;
    var->clock_kill = sfClock_create();
    return var;
}

var_t *restart_three(var_t *var, sfVector2f scale)
{
    var->clock_game = sfClock_create();
    var->sprite_dark = create_sprite(0, 0, "pictures/dark_filter.png", 1);
    var->sprite_dark = change_scale(var->sprite_dark, 10, 10);
    var->previous_stat = STAT_MENU;
    for (int i = 0; i != 4; i++) {
        var->x_weapons[i] = i * 200 + 50;
        var->y_weapons[i] = 400;
        var->sprite_weapons[i] = create_sprite(var->x_weapons[i]
        , var->y_weapons[i],"pictures/weapons.png", 1);
        var->weapons[i].height = 100;
        var->weapons[i].width = 100;
        var->weapons[i].left = i * var->weapons[i].width;
        var->weapons[i].top = 0;
        sfSprite_setTextureRect(var->sprite_weapons[i], var->weapons[i]);
    }
    var->clock_free_music = sfClock_create();
    var->sprite_castle = create_sprite(740, 75, "pictures/sprite.png", 1);
    sfSprite_setTextureRect(var->sprite_castle, var->castle);
    return restart_four(var, scale);
}

var_t *restart_two(var_t *var, sfVector2f scale)
{
    for (int i = 0; i != var->nb_cloud; i++) {
        var->x_cloud[i] = 0;
        var->y_cloud[i] = 0;
        var->sprite_cloud[i] = sfSprite_create();
        var->texture_cloud[i] = sfTexture_create(800, 600);
        sfSprite_setTexture(var->sprite_cloud[i], var->texture_cloud[i]
        , sfTrue);
        sfSprite_setTextureRect(var->sprite_cloud[i], var->cloud[i]);
        var->sprite_cloud[i] = create_sprite(var->x_cloud[i], var->y_cloud[i]
        ,"pictures/cloud.png", 1);
    }
    var->click_mouse = sfMusic_createFromFile("music/mouse.ogg");
    sfMusic_setVolume(var->click_mouse, var->volume);
    var->gold = sfMusic_createFromFile("music/gold.ogg");
    sfMusic_setVolume(var->gold, var->volume);
    var->clock_pause = sfClock_create();
    var->sprite_sound = create_sprite(var->x_sound, var->y_sound
    , "pictures/sound.png", 1);
    sfSprite_setTextureRect(var->sprite_sound, var->sound);
    return restart_three(var, scale);
}

var_t *restart(var_t *var)
{
    sfVector2f scale = {1.4, 1.5};

    var->clock_walk_ennemy = sfClock_create();
    var->clock = sfClock_create();
    var->clock_spawn = sfClock_create();
    var->round = 2;
    var->etat = STAT_MENU;
    sfMusic_play(var->music);
    var->sprite_background = sfSprite_create();
    sfSprite_setTexture(var->sprite_background, var->texture_background
    , sfTrue);
    sfSprite_setTextureRect(var->sprite_background, var->background);
    var->texture_background = sfTexture_create(800, 600);
    var->sprite_background = create_sprite(var->x_background
    , var->y_background, "pictures/background.png", 1);
    sfMusic_setVolume(var->music, var->volume);
    sfSprite_scale(var->sprite_background, scale);
    var->clock_cloud = sfClock_create();
    var->font = sfFont_createFromFile("font/Astral_Sisters.ttf");
    return restart_two(var, scale);
}
