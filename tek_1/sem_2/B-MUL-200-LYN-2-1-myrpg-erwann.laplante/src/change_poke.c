/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** change_poke
*/

#include "my_rpg.h"

void change_poke(win_t *win)
{
    if (win->change == 4)
        win->change = 0;
    win->change += 1;
    if (win->change == 0)
        win->wild.poke = win->bulbizare;
    if (win->change == 1)
        win->wild.poke = win->salameche;
    if (win->change == 3)
        win->wild.poke = win->salameche;
    if (win->change == 4)
        win->wild.poke = win->bulbizare;
}
