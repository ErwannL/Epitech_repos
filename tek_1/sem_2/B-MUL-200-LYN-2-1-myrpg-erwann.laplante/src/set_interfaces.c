/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** set_interfaces
*/

#include "my_rpg.h"

void set_interfaces(win_t *win)
{
    if (win->skip_intro_fight == 1)
        sfRenderWindow_drawSprite(win->window, win->fight_interface, NULL);
    if (win->skip_intro_fight == ATK_INTERFACE)
        sfRenderWindow_drawSprite(win->window, win->stat_interface, NULL);
    if (win->skip_intro_fight == BAG_INTERFACE)
        sfRenderWindow_drawSprite(win->window, win->stat_interface, NULL);
    if (win->skip_intro_fight == PKM_INTERFACE)
        sfRenderWindow_drawSprite(win->window, win->stat_interface, NULL);
    if (win->skip_intro_fight == RUN_INTERFACE) {
        win->skip_intro_fight = 1;
        win->action = 0;
        win->step = 10;
    }
}
