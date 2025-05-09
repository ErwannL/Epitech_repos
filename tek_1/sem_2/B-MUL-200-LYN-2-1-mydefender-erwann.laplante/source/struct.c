/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** struct
*/

#include "../include/my.h"

var_t *init_struct_five(var_t *var)
{
    var->how_play[4] = "F                  Cute the music sound.\n";
    var->how_play[5] = "N                  Restart the music sound.\n";
    var->how_play[6] = "+                  Increase volume sound.\n";
    var->how_play[7] = "-                  Decrease volume sound.\n";
    var->how_play[8] = "P                  Go to pause menu in game.\n";
    var->how_play[9] = "SPACE              In pause menu, quit pause menu and";
    var->how_play[10] = "return to game & in settings menu, quit settings and";
    var->how_play[11] = " return to menu.\n";
    var->how_play[12] = "TAB                Skip the intro.\n";
    var->how_play[13] = "M                  Go to menu from game.\n";
    var->how_play[14] = "B                  Go to building menu from settings";
    var->how_play[15] = " menu or pause menu or go to byu menu in game.\n";
    var->how_play[16] = "H                  Go to How to play menu from setti";
    var->how_play[17] = "ngs menu or pause menu.\n";
    var->how_play[18] = "ENTER              Return to settings menu or pause ";
    var->how_play[19] = "menu from building menu or how to play menu.\n";
    var->font = sfFont_createFromFile("font/Astral_Sisters.ttf");
    var->click_mouse = sfMusic_createFromFile("music/mouse.ogg");
    sfMusic_setVolume(var->click_mouse, var->volume);
    return init_struct_six(var);
}

var_t *init_struct_four(var_t *var)
{
    var->cloud = malloc(sizeof(sfIntRect *) * (var->nb_cloud + 1));
    var->x_cloud = malloc(sizeof(float) * (var->nb_cloud + 1));
    var->y_cloud = malloc(sizeof(float) * (var->nb_cloud + 1));
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
    var->how_play = malloc(sizeof(char *) * 22);
    var->how_play[0] = "|    H O W    P L A Y    !    |";
    var->how_play[1] = "MOUSE CLICK        In main menu, select start button,";
    var->how_play[2] = " setting button or quit button.\n";
    var->how_play[3] = "ESCAPE             Quit the game from anywhere.\n";
    return init_struct_five(var);
}

var_t *init_struct_three(var_t *var, sfVector2f scale)
{
    sfSprite_setTexture(var->sprite_background, var->texture_background
    , sfTrue);
    var->background.left = 0;
    var->background.top = 0;
    var->background.width = 800;
    sfSprite_setTextureRect(var->sprite_background, var->background);
    var->texture_background = sfTexture_create(800, 600);
    var->x_background = 0;
    var->y_background = 0;
    var->sprite_background = create_sprite(var->x_background
    , var->y_background, "pictures/background.png", 1);
    var->volume = 50;
    sfMusic_setVolume(var->music, var->volume);
    var->stat_music = MUSIC_ON;
    sfSprite_scale(var->sprite_background, scale);
    var->clock_cloud = sfClock_create();
    var->nb_cloud = 4;
    var->texture_cloud = malloc(sizeof(sfTexture *) * (var->nb_cloud + 1));
    var->sprite_cloud = malloc(sizeof(sfSprite *) * (var->nb_cloud + 1));
    return init_struct_four(var);
}

var_t *init_struct_two(var_t *var, sfVector2f scale)
{
    var->flying_rec.left = 335;
    var->flying_rec.height = 45;
    var->flying_rec.width = 50;
    var->mode.width = 800;
    var->mode.height = 600;
    var->mode.bitsPerPixel = 32;
    var->heavy = 0;
    var->flying = 0;
    var->r_val = 0;
    var->window = sfRenderWindow_create(var->mode, "My Defender", sfClose
    | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(var->window, 144);
    var->e_nbr = 0;
    var->etat = STAT_MENU;
    var->music = sfMusic_createFromFile("music/background.ogg");
    sfMusic_setLoop(var->music, sfTrue);
    sfMusic_play(var->music);
    var->sprite_background = sfSprite_create();
    var->background.height = 600;
    return init_struct_three(var, scale);
}

var_t *init_struct(var_t *var)
{
    sfVector2f scale = {1.4, 1.5};

    var->clock_walk_ennemy = sfClock_create();
    var->clock = sfClock_create();
    var->clock_spawn = sfClock_create();
    var->round = 0;
    var->path = malloc(sizeof(int) * 10);
    var->path_heavy = malloc(sizeof(int) * 10);
    var->path_flying = malloc(sizeof(int) * 10);
    var->number_round = 0;
    var->rec_ennemy.top = 8;
    var->rec_ennemy.left = 340;
    var->rec_ennemy.height = 37;
    var->rec_ennemy.width = 35;
    var->heavy_rec.top = 255;
    var->heavy_rec.left = 332;
    var->heavy_rec.height = 50;
    var->heavy_rec.width = 50;
    var->flying_rec.top = 110;
    return init_struct_two(var, scale);
}
