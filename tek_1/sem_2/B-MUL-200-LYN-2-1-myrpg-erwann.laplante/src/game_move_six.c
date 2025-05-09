/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** game_move_six
*/

#include "my_rpg.h"

win_t *up_six(win_t *win)
{
    (win->y_map >= 40 && win->y_player <= 300) ? win->y_map--
    , win->y_labo += 3 : (win->y_player > 0) ? win->y_player-- : 0;
    if (win->y_player <= win->y_labo + (16 * 5)
    && win->y_player + (16 * 5) >= win->y_labo
    && win->x_player + (17 * 5) >= win->x_labo
    && win->x_player <= win->x_labo + (17 * 5)) {
        (win->y_map >= 55 && win->y_player <= 300) ? win->y_map++
        , win->y_labo -= 3 : (win->y_player > 0) ? win->y_player++ : 0;
        win->quest[2].done = win->quest[2].done == 0 ? 1 : -1;
    }
    return win;
}

win_t *down_six(win_t *win)
{
    (win->y_map <= 85 && win->y_player >= 300) ? win->y_map++
    , win->y_labo -= 3 : (win->y_player < win->win_size.y - (16 * 5))
    ? win->y_player++ : 0;
    if (win->y_player + (16 * 5) >= win->y_labo
    && win->y_player <= win->y_labo + (16 * 5)
    && win->x_player + (17 * 5) >= win->x_labo
    && win->x_player <= win->x_labo + (17 * 5)) {
        (win->y_map <= 220 && win->y_player >= 300) ? win->y_map--
        , win->y_labo += 3 : (win->y_player < win->win_size.y - (16 * 5))
        ? win->y_player-- : 0;
        win->quest[2].done = win->quest[2].done == 0 ? 1 : -1;
    }
    return win;
}

win_t *right_six(win_t *win)
{
    (win->x_map <= 1450 && win->x_player >= 400) ? win->x_map++
    , win->x_labo -= 4 : (win->x_player < win->win_size.x - (14 * 5))
    ? win->x_player++ : 0;
    if (win->x_player <= win->x_labo
    && win->x_player + (17 * 5) >= win->x_labo
    && win->y_player + (16 * 5) >= win->y_labo
    && win->y_player <= win->y_labo + (16 * 5)) {
        (win->x_map <= 1585 && win->x_player >= 400) ? win->x_map--
        , win->x_labo += 4 : (win->x_player < win->win_size.x - (14 * 5))
        ? win->x_player-- : 0;
        win->quest[2].done = win->quest[2].done == 0 ? 1 : -1;
    }
    return win;
}

win_t *left_six(win_t *win)
{
    (win->x_map >= 1230 && win->x_player <= 400) ? win->x_map--
    , win->x_labo += 4 : (win->x_player > 0) ? win->x_player-- : 0;
    if (win->x_player >= win->x_labo
    && win->x_player <= win->x_labo + (17 * 5)
    && win->y_player + (16 * 5) >= win->y_labo
    && win->y_player <= win->y_labo + (16 * 5)) {
        (win->x_map >= 1500 && win->x_player <= 400) ? win->x_map++
        , win->x_labo -= 4 : (win->x_player > 0) ? win->x_player++ : 0;
        win->quest[2].done = win->quest[2].done == 0 ? 1 : -1;
    }
    return win;
}
