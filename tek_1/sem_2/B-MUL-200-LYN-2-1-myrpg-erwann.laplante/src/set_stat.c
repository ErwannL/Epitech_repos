/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** set_stat
*/

#include "my_rpg.h"

poke_t set_statbulbi(poke_t poke, win_t *win)
{
    poke.lvl = 5;
    poke.hp_max = 20;
    poke.atk = 1;
    poke.hp = 20;
    poke.def = 2;
    poke.type = GRASS;
    poke.xp = 0;
    poke.t_hp = create_text(win, 20, (sfVector2f){507, 340}
    , my_getstr(poke.hp));
    poke.t_hp_max = create_text(win, 20, (sfVector2f){577, 340}
    , my_getstr(poke.hp_max));
    poke.t_lvl = create_text(win, 20, (sfVector2f){580, 277}
    , my_getstr(poke.lvl));
    return (poke);
}

poke_t set_statpika(poke_t poke, win_t *win)
{
    poke.lvl = 5;
    poke.hp_max = 20;
    poke.atk = 100;
    poke.hp = 20;
    poke.def = 2;
    poke.type = FIRE;
    poke.xp = 0;
    poke.t_hp = create_text(win, 20, (sfVector2f){507, 340}
    , my_getstr(poke.hp));
    poke.t_hp_max = create_text(win, 20, (sfVector2f){577, 340}
    , my_getstr(poke.hp_max));
    poke.t_lvl = create_text(win, 20, (sfVector2f){580, 277}
    , my_getstr(poke.lvl));
    return (poke);
}
