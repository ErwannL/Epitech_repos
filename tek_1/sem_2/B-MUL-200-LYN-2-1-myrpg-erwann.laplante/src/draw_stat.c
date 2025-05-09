/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** draw_stat
*/

#include "my_rpg.h"

void draw_capa(win_t *win, poke_t ally, poke_t enemy)
{
    sfRenderWindow_drawText(win->window, ally.capa1.name, NULL);
    sfRenderWindow_drawText(win->window, ally.capa2.name, NULL);
    sfRenderWindow_drawText(win->window, ally.capa3.name, NULL);
}

void display_info(win_t *win, poke_t ally, poke_t enemy)
{
    sfText_setPosition(ally.name, (sfVector2f){425, 280});
    sfText_setPosition(enemy.name, (sfVector2f){165, 60});
    sfText_setPosition(enemy.t_hp, (sfVector2f){275, 116});
    sfRenderWindow_drawText(win->window, ally.t_hp_max, NULL);
    sfRenderWindow_drawText(win->window, ally.t_hp, NULL);
    sfRenderWindow_drawText(win->window, ally.name, NULL);
    sfRenderWindow_drawText(win->window, enemy.name, NULL);
    sfRenderWindow_drawText(win->window, enemy.t_hp, NULL);
    sfRenderWindow_drawText(win->window, ally.t_lvl, NULL);
}

void draw_stat(win_t *win, poke_t ally, poke_t enemy)
{
    display_info(win, ally, enemy);
    if (win->skip_intro_fight == ATK_INTERFACE)
        draw_capa(win, ally, enemy);
}
