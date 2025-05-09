/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** move_player
*/

#include "my_rpg.h"

void move_player_bis(win_t *win)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        ((win->player_rect.left > 60 && win->player_rect.left < 95) ?
        (win->player_rect.left -= win->player_rect.width) :
        (win->player_rect.left = 94));
        win->last_key = sfKeyUp;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        ((win->player_rect.left > 9 && win->player_rect.left < 44) ?
        (win->player_rect.left -= win->player_rect.width) :
        (win->player_rect.left = 43));
        win->last_key = sfKeyDown;
    }
    if (!sfKeyboard_isKeyPressed(sfKeyLeft)
    && !sfKeyboard_isKeyPressed(sfKeyUp) && !sfKeyboard_isKeyPressed(sfKeyDown)
    && !sfKeyboard_isKeyPressed(sfKeyRight)) {
        (win->last_key == sfKeyDown) ? win->player_rect.left = 25 : 0;
        (win->last_key == sfKeyUp) ? win->player_rect.left = 76 : 0;
        (win->last_key == sfKeyRight) ? win->player_rect.left = 145 : 0;
        (win->last_key == sfKeyLeft) ? win->player_rect.left = 111 : 0;
    }
}

win_t *move_player(win_t *win)
{
    if (sfClock_getElapsedTime(win->move_player).microseconds > 100000) {
        if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
            ((win->player_rect.left > 111 && win->player_rect.left < 129) ?
            (win->player_rect.left -= win->player_rect.width) :
            (win->player_rect.left = 128));
            win->last_key = sfKeyLeft;
        }
        if (sfKeyboard_isKeyPressed(sfKeyRight)) {
            ((win->player_rect.left > 145 && win->player_rect.left < 163) ?
            (win->player_rect.left -= win->player_rect.width) :
            (win->player_rect.left = 162));
            win->last_key = sfKeyRight;
        }
        move_player_bis(win);
        sfClock_restart(win->move_player);
    }
    return win;
}
