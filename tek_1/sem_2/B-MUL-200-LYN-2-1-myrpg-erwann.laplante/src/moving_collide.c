/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** moving_collide
*/

#include "my_rpg.h"

win_t *print_moving_collide(win_t *win)
{
    if (win->piece == 4) {
        sfSprite_setPosition(win->moving_collide,
        (sfVector2f){win->x_collide, win->y_collide});
        sfRenderWindow_drawSprite(win->window, win->moving_collide, NULL);
    }
    if (win->piece == 5) {
        sfSprite_setPosition(win->moving_chen,
        (sfVector2f){win->x_chen, win->y_chen});
        sfRenderWindow_drawSprite(win->window, win->moving_chen, NULL);
    }
    if (win->piece == 6) {
        sfSprite_setPosition(win->moving_labo,
        (sfVector2f){win->x_labo, win->y_labo});
        sfRenderWindow_drawSprite(win->window, win->moving_labo, NULL);
    }
    return win;
}
