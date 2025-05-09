/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** game_move_five
*/

#include "my_rpg.h"

win_t *up_five(win_t *win)
{
    (win->y_map >= 55 && win->y_player <= 300) ? win->y_map--
    , win->y_chen += 2 : (win->y_player > 0) ? win->y_player-- : 0;
    if (win->y_player <= win->y_chen + (16 * 5)
    && win->y_player + (16 * 5) >= win->y_chen
    && win->x_player + (17 * 5) >= win->x_chen
    && win->x_player <= win->x_chen + (17 * 5)) {
        (win->y_map >= 55 && win->y_player <= 300) ? win->y_map++
        , win->y_chen -= 2 : (win->y_player > 0) ? win->y_player++ : 0;
        win->quest[0].done = win->quest[1].done == 0 ? 1 : -1;
        win->quest[1].done = 0;
        win->quest[2].done = 0;
    }
    return win;
}

win_t *down_five(win_t *win)
{
    (win->y_map <= 220 && win->y_player >= 300) ? win->y_map++
    , win->y_chen -= 2 : (win->y_player < win->win_size.y - (16 * 5))
    ? win->y_player++ : 0;
    if (win->y_player + (16 * 5) >= win->y_chen
    && win->y_player <= win->y_chen + (16 * 5)
    && win->x_player + (17 * 5) >= win->x_chen
    && win->x_player <= win->x_chen + (17 * 5)) {
        (win->y_map <= 220 && win->y_player >= 300) ? win->y_map--
        , win->y_chen += 2 : (win->y_player < win->win_size.y - (16 * 5))
        ? win->y_player-- : 0;
        win->quest[0].done = win->quest[1].done == 0 ? 1 : -1;
        win->quest[1].done = 0;
        win->quest[2].done = 0;
    }
    return win;
}

win_t *right_five(win_t *win)
{
    (win->x_map <= 1585 && win->x_player >= 400) ? win->x_map++
    , win->x_chen -= 2 : (win->x_player < win->win_size.x - (14 * 5))
    ? win->x_player++ : 0;
    if (win->x_player <= win->x_chen
    && win->x_player + (17 * 5) >= win->x_chen
    && win->y_player + (16 * 5) >= win->y_chen
    && win->y_player <= win->y_chen + (16 * 5)) {
        (win->x_map <= 1585 && win->x_player >= 400) ? win->x_map--
        , win->x_chen += 2 : (win->x_player < win->win_size.x - (14 * 5))
        ? win->x_player-- : 0;
        win->quest[0].done = win->quest[1].done == 0 ? 1 : -1;
        win->quest[1].done = 0;
        win->quest[2].done = 0;
    }
    return win;
}

win_t *left_five(win_t *win)
{
    (win->x_map >= 1500 && win->x_player <= 400) ? win->x_map--
    , win->x_chen += 2 : (win->x_player > 0) ? win->x_player-- : 0;
    if (win->x_player >= win->x_chen
    && win->x_player <= win->x_chen + (17 * 5)
    && win->y_player + (16 * 5) >= win->y_chen
    && win->y_player <= win->y_chen + (16 * 5)) {
        (win->x_map >= 1500 && win->x_player <= 400) ? win->x_map++
        , win->x_chen -= 2 : (win->x_player > 0) ? win->x_player++ : 0;
        win->quest[0].done = win->quest[1].done == 0 ? 1 : -1;
        win->quest[1].done = 0;
        win->quest[2].done = 0;
    }
    return win;
}
