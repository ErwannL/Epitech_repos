/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** free
*/

#include "my_rpg.h"

void free_next(win_t *win)
{
    sfSprite_destroy(win->moving_collide);
    sfSprite_destroy(win->player->player);
    sfSprite_destroy(win->pokemon);
    sfRenderWindow_destroy(win->window);
    free(win);
}
