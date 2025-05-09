/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** update_xp
*/

#include "my_rpg.h"

void reset_stat(win_t *win)
{
    if (win->rival.poke.hp <= 0) {
        win->step = 10;
        win->rival.poke.hp = 20;
        win->you.poke.xp += 10;
        win->wild.poke.hp = win->wild.poke.hp_max;
        sfText_setString(win->wild.poke.t_hp, my_getstr(win->wild.poke.hp));
    }
}

void level_up(win_t *win)
{
    if (win->you.poke.lvl > 6) {
        if (win->you.poke.xp >= 30) {
            win->you.poke.lvl += 1;
            win->you.poke.atk += 1;
            win->you.poke.hp_max += 2;
            win->you.poke.hp = win->you.poke.hp_max;
            sfText_setString(win->you.poke.t_lvl
                                        , my_getstr(win->you.poke.lvl));
            sfText_setString(win->you.poke.t_hp_max
                                        , my_getstr(win->you.poke.hp_max));
            win->you.poke.xp = 0;
        }
    }
}

void update_xp(win_t *win)
{
    if (win->you.poke.xp >= 10 && win->you.poke.lvl <= 6) {
        win->you.poke.lvl += 1;
        win->you.poke.hp_max += 2;
        win->you.poke.hp = win->you.poke.hp_max;
        sfText_setString(win->you.poke.t_lvl
                                    , my_getstr(win->you.poke.lvl));
        sfText_setString(win->you.poke.t_hp_max
                                        , my_getstr(win->you.poke.hp_max));
        win->you.poke.xp = 0;
    }
    level_up(win);
}
