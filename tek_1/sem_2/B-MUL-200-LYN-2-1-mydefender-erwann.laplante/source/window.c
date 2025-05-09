/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** window
*/

#include "../include/my.h"

var_t *resize_window(var_t *var)
{
    sfVector2u size = sfRenderWindow_getSize(var->window);

    if (size.y < 600 || size.y > 1080) {
        size.y = size.y < 600 ? 600 : 1080;
        sfRenderWindow_setSize(var->window, size);
    }
    if (size.x < 800 || size.x > 1920) {
        size.x = size.x < 800 ? 800 : 1920;
        sfRenderWindow_setSize(var->window, size);
    }
    var->dif_x = size.x - 800;
    var->dif_y = size.y - 600;
    sfRenderWindow_clear(var->window, sfBlack);
    return var;
}
