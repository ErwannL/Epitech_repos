/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** struct_bis
*/

#include "../include/my.h"

var_t *init_struct_eight(var_t *var)
{
    var->clock_free_music = sfClock_create();
    var->sprite_play_weapons = malloc(sizeof(sfSprite *) * 9);
    for (int i = 0; i != 8; i++) {
        var->sprite_play_weapons[i] = sfSprite_copy(var->sprite_weapons[0]);
        move_sprite(2000, 2000, var->sprite_play_weapons[i]);
    }
    var->sprite_castle = create_sprite(740, 75, "pictures/sprite.png", 1);
    var->castle.height = 300;
    var->castle.width = 60;
    var->castle.top = 8;
    var->castle.left = 246;
    var->number_ennemy = 0;
    sfSprite_setTextureRect(var->sprite_castle, var->castle);
    var->turret = malloc(sizeof(int) * 9);
    var->life = 100;
    var->clock_kill = sfClock_create();
    var->clock_deg_en = sfClock_create();
    return var;
}

var_t *init_struct_seven(var_t *var)
{
    var->sprite_dark = create_sprite(0, 0, "pictures/dark_filter.png", 1);
    var->sprite_dark = change_scale(var->sprite_dark, 10, 10);
    var->previous_stat = STAT_MENU;
    var->clock_unbug_menu = sfClock_create();
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
        var->price_weapons[i] = malloc(sizeof(char) * 5);
        var->price_weapons[i] = int_to_str(var->x_weapons[i] - 50);
    }
    var->how_play[20] = "NUMBER 1 TO 4      Select what building place in";
    var->how_play[21] = " build menu";
    return init_struct_eight(var);
}

var_t *init_struct_six(var_t *var)
{
    var->gold = sfMusic_createFromFile("music/gold.ogg");
    sfMusic_setVolume(var->gold, var->volume);
    var->clock_pause = sfClock_create();
    var->x_sound = 700;
    var->y_sound = 100;
    var->sprite_sound = create_sprite(var->x_sound, var->y_sound
    , "pictures/sound.png", 1);
    var->sound.height = 90;
    var->sound.width = 90;
    var->sound.top = 0;
    var->sound.left = 0;
    sfSprite_setTextureRect(var->sprite_sound, var->sound);
    var->score = 0;
    var->clock_game = sfClock_create();
    var->sprite_weapons = malloc(sizeof(sfSprite *) * 5);
    var->weapons = malloc(sizeof(sfIntRect *) * 5);
    var->x_weapons = malloc(sizeof(float) * 5);
    var->y_weapons = malloc(sizeof(float) * 5);
    var->price_weapons = malloc(sizeof(char *) * 5);
    return init_struct_seven(var);
}
