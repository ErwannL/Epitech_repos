/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** sprite
*/

#include"../includes/my.h"

sfSprite *create_sprite(float x, float y, char *image, int zoom)
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f my_pos = {x, y};
    sfVector2f scale = {zoom, zoom};

    sprite = sfSprite_create();
    sfSprite_setPosition(sprite, my_pos);
    sfSprite_setScale(sprite, scale);
    texture = sfTexture_createFromFile(image, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

var_t set_sprite_second(var_t var)
{
    sfVector2f a = {0.5, 0.5};
    sfVector2f b = {0.1, 0.1};
    sfVector2f c = {0.2, 0.2};

    var.sprite_cloud4 = create_sprite(var.x_cloud4, var.y_cloud4,
    "pictures/cloud2.png", 1);
    var.sprite_sun = create_sprite(var.x_sun, var.y_sun,
    "pictures/sun.png", 1);
    var.sprite_start = create_sprite(var.x_start, var.y_start,
    "pictures/start.png", 1);
    sfSprite_setScale(var.sprite_start, a);
    var.sprite_option = var.etat != 3 && var.etat != 2 ?
    create_sprite(var.x_option, var.y_option, "pictures/option.png", 1)
    : create_sprite(var.x_option, var.y_option,
    "pictures/close.png", 1);
    sfSprite_setScale(var.sprite_option, var.etat != 3 && var.etat != 2 ? b :
    c);
    var.sprite_sound = create_sprite(var.x_sound, var.y_sound,
    "pictures/sound.png", 1);
    return (var);
}

var_t set_sprite(var_t var)
{
    var.sprite_cloud = create_sprite(var.x_cloud, var.y_cloud,
    "pictures/cloud.png", 1);
    var.sprite_cloud2 = sfSprite_copy(var.sprite_cloud);
    sfSprite_setPosition(var.sprite_cloud2, var.pos_cloud2);
    var.sprite_bird = create_sprite(var.x_bird, var.y_bird,
    "pictures/bird.png", 1);
    var.sprite_bat = create_sprite(var.x_bat, var.y_bat,
    "pictures/bat.png", 1);
    var.sprite_bat2 = create_sprite(var.x_bat2, var.y_bat2,
    "pictures/bat.png", 1);
    var.sprite_bat3 = create_sprite(var.x_bat3, var.y_bat3,
    "pictures/bat.png", 1);
    var.sprite_bat4 = create_sprite(var.x_bat4, var.y_bat4,
    "pictures/bat.png", 1);
    var.sprite_bat5 = create_sprite(var.x_bat5, var.y_bat5,
    "pictures/bat.png", 1);
    var.sprite_cloud3 = create_sprite(var.x_cloud3, var.y_cloud3,
    "pictures/cloud2.png", 1);
    return set_sprite_second(var);
}
