/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** game
*/

#include "my_rpg.h"

win_t *game_four(win_t *win)
{
    if (win->piece == 4)
        (sfKeyboard_isKeyPressed(sfKeyLeft)) ? win = left_four(win) :
        (sfKeyboard_isKeyPressed(sfKeyRight)) ? win = right_four(win) :
        (sfKeyboard_isKeyPressed(sfKeyUp)) ? win = up_four(win) :
        (sfKeyboard_isKeyPressed(sfKeyDown)) ? win = down_four(win) : 0;
    if (win->piece == 5)
        (sfKeyboard_isKeyPressed(sfKeyLeft)) ? win = left_five(win) :
        (sfKeyboard_isKeyPressed(sfKeyRight)) ? win = right_five(win) :
        (sfKeyboard_isKeyPressed(sfKeyUp)) ? win = up_five(win) :
        (sfKeyboard_isKeyPressed(sfKeyDown)) ? win = down_five(win) : 0;
    if (win->piece == 6)
        (sfKeyboard_isKeyPressed(sfKeyLeft)) ? win = left_six(win) :
        (sfKeyboard_isKeyPressed(sfKeyRight)) ? win = right_six(win) :
        (sfKeyboard_isKeyPressed(sfKeyUp)) ? win = up_six(win) :
        (sfKeyboard_isKeyPressed(sfKeyDown)) ? win = down_six(win) : 0;
    return win;
}

win_t *game_three(win_t *win)
{
    if (win->piece == 3) {
        if (sfKeyboard_isKeyPressed(sfKeyLeft))
            (win->x_map >= 20 && win->x_player <= 400) ? win->x_map-- :
            (win->x_player > 0) ? win->x_player-- : 0;
        if (sfKeyboard_isKeyPressed(sfKeyRight))
            (win->x_map <= 660 && win->x_player >= 400) ? win->x_map++ :
            (win->x_player < win->win_size.x - (14 * 5)) ? win->x_player++ : 0;
        if (sfKeyboard_isKeyPressed(sfKeyUp))
            (win->y_map >= 65 && win->y_player <= 300) ? win->y_map-- :
            (win->y_player > 0) ? win->y_player-- : 0;
        if (sfKeyboard_isKeyPressed(sfKeyDown))
            (win->y_map <= 1465 && win->y_player >= 300) ? win->y_map++ :
            (win->y_player < win->win_size.y - (16 * 5)) ? win->y_player++ : 0;
    }
    return game_four(win);
}

win_t *game_two(win_t *win)
{
    if (win->piece == 2) {
        if (sfKeyboard_isKeyPressed(sfKeyLeft))
            (win->x_map >= 15 && win->x_player <= 400) ? win->x_map-- :
            (win->x_player > 0) ? win->x_player-- : 0;
        if (sfKeyboard_isKeyPressed(sfKeyRight))
            (win->x_map <= 495 && win->x_player >= 400) ? win->x_map++ :
            (win->x_player < win->win_size.x - (14 * 5)) ? win->x_player++ : 0;
        if (sfKeyboard_isKeyPressed(sfKeyUp))
            (win->y_map >= 55 && win->y_player <= 300) ? win->y_map-- :
            (win->y_player > 0) ? win->y_player-- : 0;
        if (sfKeyboard_isKeyPressed(sfKeyDown))
            (win->y_map <= 460 && win->y_player >= 300) ? win->y_map++ :
            (win->y_player < win->win_size.y - (16 * 5)) ? win->y_player++ : 0;
    }
    return game_three(win);
}

win_t *game_one(win_t *win)
{
    if (win->piece == 1) {
        if (sfKeyboard_isKeyPressed(sfKeyLeft))
            (win->x_map >= 830 && win->x_player <= 400) ? win->x_map-- :
            (win->x_player > 0) ? win->x_player-- : 0;
        if (sfKeyboard_isKeyPressed(sfKeyRight))
            (win->x_map <= 830 && win->x_player >= 400) ? win->x_map++ :
            (win->x_player < win->win_size.x - (14 * 5)) ? win->x_player++ : 0;
        if (sfKeyboard_isKeyPressed(sfKeyUp))
            (win->y_map >= 57 && win->y_player <= 300) ? win->y_map-- :
            (win->y_player > 0) ? win->y_player-- : 0;
        if (sfKeyboard_isKeyPressed(sfKeyDown))
            (win->y_map <= 63 && win->y_player >= 300) ? win->y_map++ :
            (win->y_player < win->win_size.y - (16 * 5)) ? win->y_player++ : 0;
    }
    return game_two(win);
}

win_t *game(win_t *win)
{
    player_is_in_grass(win);
    if (win->piece == 0) {
        if (sfKeyboard_isKeyPressed(sfKeyLeft))
            (win->x_map >= 1168 && win->x_player <= 400) ? win->x_map-- :
            (win->x_player > 0) ? win->x_player-- : 0;
        if (sfKeyboard_isKeyPressed(sfKeyRight))
            (win->x_map <= 1168 && win->x_player >= 400) ? win->x_map++ :
            (win->x_player < win->win_size.x - (14 * 5)) ? win->x_player++ : 0;
        if (sfKeyboard_isKeyPressed(sfKeyUp))
            (win->y_map >= 58 && win->y_player <= 300) ? win->y_map-- :
            (win->y_player > 0) ? win->y_player-- : 0;
        if (sfKeyboard_isKeyPressed(sfKeyDown))
            (win->y_map <= 61 && win->y_player >= 300) ? win->y_map++ :
            (win->y_player < win->win_size.y - (16 * 5)) ? win->y_player++ : 0;
    }
    return game_one(win);
}
