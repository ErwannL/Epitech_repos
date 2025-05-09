/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** declaration
*/

#include"../includes/my.h"

var_t dec_var8(var_t var)
{
    sfSprite_setTexture(var.sprite_sound, var.texture_sound, sfTrue);
    var.sound.height = 108;
    var.sound.width = 108;
    sfSprite_setTextureRect(var.sprite_sound, var.sound);
    var.x_sound = 650;
    var.y_sound = 10;
    var.bat.left = 0;
    return var;
}

var_t dec_var7(var_t var)
{
    sfSprite_setTextureRect(var.sprite_start, var.start);
    var.x_start = 266;
    var.y_start = 200;
    var.texture_option = sfTexture_create(800, 600);
    var.sprite_option = sfSprite_create();
    sfSprite_setTexture(var.sprite_option, var.texture_option, sfTrue);
    sfSprite_setTextureRect(var.sprite_option, var.option);
    var.x_option = 750;
    var.y_option = 10;
    var.x_sun = 800;
    var.score = 0;
    var.vec.x = 10;
    var.vec.y = 10;
    var.text = setup_font(var);
    var.volume = 50;
    sfMusic_setVolume(var.music, var.volume);
    var.stat_music = 0;
    var.texture_sound = sfTexture_create(800, 600);
    var.sprite_sound = sfSprite_create();
    return dec_var8(var);
}

var_t dec_var6(var_t var)
{
    sfSprite_setTexture(var.sprite_cloud3, var.texture_cloud3, sfTrue);
    sfSprite_setTextureRect(var.sprite_cloud3, var.cloud3);
    var.x_cloud3 = 0;
    var.y_cloud3 = 0;
    var.texture_cloud4 = sfTexture_create(800, 600);
    var.sprite_cloud4 = sfSprite_create();
    sfSprite_setTexture(var.sprite_cloud4, var.texture_cloud4, sfTrue);
    sfSprite_setTextureRect(var.sprite_cloud4, var.cloud4);
    var.x_cloud4 = 800;
    var.y_cloud4 = 0;
    var.texture_sun = sfTexture_create(800, 600);
    var.sprite_sun = sfSprite_create();
    sfSprite_setTexture(var.sprite_sun, var.texture_sun, sfTrue);
    var.music = sfMusic_createFromFile("music/star.ogg");
    sfMusic_setLoop(var.music, sfTrue);
    sfMusic_play(var.music);
    var.texture_start = sfTexture_create(800, 600);
    var.sprite_start = sfSprite_create();
    sfSprite_setTexture(var.sprite_start, var.texture_start, sfTrue);
    return dec_var7(var);
}
