/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** pause_menu
*/

#include "my_rpg.h"

int detect_click_pause(win_t *win)
{
    if ((int)sfSprite_getPosition(win->cursor).x == 500
    && (int)sfSprite_getPosition(win->cursor).y == 60
    && win->step == -2) {
        win->prev_step = -2;
        win->old_step = win->step;
        win->step = 12;
        return 0;
    }
    if ((int)sfSprite_getPosition(win->cursor).x == 500
    && (int)sfSprite_getPosition(win->cursor).y == 120
    && win->step == -2) {
        win->prev_step = -2;
        win->old_step = win->step;
        win->step = 13;
        return 0;
    }
    return 84;
}
