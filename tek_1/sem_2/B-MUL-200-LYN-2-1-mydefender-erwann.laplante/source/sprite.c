/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** sprite
*/

#include "../include/my.h"

sfVector2f create_vector(int x, int y)
{
    sfVector2f vec = {x, y};

    return vec;
}

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

sfSprite *create_sprite_rec(sfIntRect rec, char *image)
{
    sfSprite *sprite;
    sfTexture *texture;

    sprite = sfSprite_create();
    texture = sfTexture_createFromFile(image, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rec);
    return (sprite);
}

sfSprite *move_sprite(float x, float y, sfSprite *sprite)
{
    sfVector2f my_pos = {x, y};

    sfSprite_setPosition(sprite, my_pos);
    return (sprite);
}

sfSprite *change_scale(sfSprite *sprite, float i, float j)
{
    sfVector2f scale = {i, j};

    sfSprite_setScale(sprite, scale);
    return (sprite);
}
