/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** game_move_four
*/

#include "my_rpg.h"

win_t *up_four(win_t *win)
{
    (win->y_map >= 40 && win->y_player <= 300) ? win->y_map--
    , win->y_collide += 3 : (win->y_player > 0) ? win->y_player-- : 0;
    if (win->y_player <= win->y_collide + (14 * 4)
    && win->y_player + (16 * 5) >= win->y_collide
    && win->x_player + (17 * 5) >= win->x_collide
    && win->x_player <= win->x_collide + (14 * 4)) {
        win->y_collide -= 3;
        win->quest[1].done = win->quest[1].done == 0 ? 1 : -1;
    }
    return win;
}

win_t *down_four(win_t *win)
{
    (win->y_map <= 925 && win->y_player >= 300) ? win->y_map++
    , win->y_collide -= 3 : (win->y_player < win->win_size.y - (16 * 5))
    ? win->y_player++ : 0;
    if (win->y_player + (16 * 5) >= win->y_collide
    && win->y_player <= win->y_collide + (16 * 5)
    && win->x_player + (17 * 5) >= win->x_collide
    && win->x_player <= win->x_collide + (14 * 4)) {
        win->y_collide += 3;
        win->quest[1].done = win->quest[1].done == 0 ? 1 : -1;
    }
    return win;
}

win_t *right_four(win_t *win)
{
    (win->x_map <= 1015 && win->x_player >= 400) ? win->x_map++
    , win->x_collide -= 4 : (win->x_player < win->win_size.x - (14 * 5))
    ? win->x_player++ : 0;
    if (win->x_player <= win->x_collide
    && win->x_player + (17 * 5) >= win->x_collide
    && win->y_player + (16 * 5) >= win->y_collide
    && win->y_player <= win->y_collide + (14 * 4)) {
        win->x_collide += 4;
        win->quest[1].done = win->quest[1].done == 0 ? 1 : -1;
    }
    return win;
}

win_t *left_four(win_t *win)
{
    (win->x_map >= 15 && win->x_player <= 400) ? win->x_map--
    , win->x_collide += 4 : (win->x_player > 0) ? win->x_player-- : 0;
    if (win->x_player >= win->x_collide
    && win->x_player <= win->x_collide + (16 * 4)
    && win->y_player + (16 * 5) >= win->y_collide
    && win->y_player <= win->y_collide + (14 * 4)) {
        win->x_collide -= 4;
        win->quest[1].done = win->quest[1].done == 0 ? 1 : -1;
    }
    return win;
}
