/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** position
*/

#include "my_rpg.h"

win_t *save_pos(win_t *win)
{
    win->x_map = win->old_pos->x_map;
    win->x_player = win->old_pos->x_player;
    win->y_map = win->old_pos->y_map;
    win->y_player = win->old_pos->y_player;
    win->x_collide = win->old_pos->x_collide;
    win->y_collide = win->old_pos->y_collide;
    win->x_chen = win->old_pos->x_chen;
    win->y_chen = win->old_pos->y_chen;
    win->x_labo = win->old_pos->x_labo;
    win->y_labo = win->old_pos->y_labo;
    return win;
}

win_t *get_pos(win_t *win)
{
    win->old_pos->x_map = win->x_map;
    win->old_pos->x_player = win->x_player;
    win->old_pos->y_map = win->y_map;
    win->old_pos->y_player = win->y_player;
    win->old_pos->x_collide = win->x_collide;
    win->old_pos->y_collide = win->y_collide;
    win->old_pos->x_chen = win->x_chen;
    win->old_pos->y_chen = win->y_chen;
    win->old_pos->x_labo = win->x_labo;
    win->old_pos->y_labo = win->y_labo;
    return win;
}
