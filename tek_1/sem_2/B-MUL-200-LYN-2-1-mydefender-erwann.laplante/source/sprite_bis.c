/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** sprite
*/

#include "../include/my.h"

sfSprite *change_image(sfSprite *sprite, char *image)
{
    sfTexture *texture = sfTexture_createFromFile(image, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}
