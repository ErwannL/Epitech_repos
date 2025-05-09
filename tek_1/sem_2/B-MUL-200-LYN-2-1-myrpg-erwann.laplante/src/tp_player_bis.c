/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** tp_player_bis
*/

#include "my_rpg.h"

win_t *tp_player_six(win_t *win)
{
    if (win->piece == 4 && win->x_map >= 601 && win->x_map <= 619
    && win->y_map >= 691 && win->y_map <= 701) {
        win->piece = 6;
        win->x_map = 1240;
        win->y_map = 86;
        win->x_player = 400;
        win->y_player = 400;
    }
    if (win->piece == 6 && win->x_player >= 325 && win->x_player <= 480
    && win->y_player >= 480 && win->y_player <= 520 && win->x_map >= 1229
    && win->x_map <= 1270) {
        win->piece = 4;
        win->x_map = 610;
        win->y_map = 730;
        win->x_player = 400;
        win->y_player = 300;
    }
    return win;
}
