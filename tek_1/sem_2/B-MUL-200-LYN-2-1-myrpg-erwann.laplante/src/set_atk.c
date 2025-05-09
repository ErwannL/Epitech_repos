/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** set_atk
*/

#include "my_rpg.h"

int get_type(poke_t ally, poke_t enemy, capa_t capa)
{
    if (enemy.type == WATER && capa.type == ELECK)
        return (2);
    if (enemy.type == FIRE && capa.type == ELECK)
        return (0);
    return (1);
}

int get_action(win_t *win, poke_t ally, poke_t enemy)
{
    if (win->event.key.type == sfEvtKeyReleased)
        win->one_time = 0;
    if (sfKeyboard_isKeyPressed(sfKeyA) && win->one_time == 0) {
        if (win->cursor_limit == 0 && win->cursorx_limit == 0)
            enemy.hp -= ally.capa1.dmg - enemy.def + ally.atk * get_type(ally
            , enemy, ally.capa1);
        if (win->cursor_limit == 0 && win->cursorx_limit == 1)
            enemy.hp -= ally.capa2.dmg - enemy.def + ally.atk * get_type(ally
            , enemy, ally.capa1);
        if (win->cursor_limit == 1 && win->cursorx_limit == 1)
            enemy.hp -= ally.capa3.dmg - enemy.def + ally.atk * get_type(ally
            , enemy, ally.capa1);
        sfSound_play(win->hit_btn);
        sfText_setString(enemy.t_hp, my_getstr(enemy.hp));
        win->skip_intro_fight = 1;
        win->turn = TURN_B;
        win->one_time = 1;
    }
    return (enemy.hp);
}

int take_dmg(win_t *win, poke_t ally, poke_t enemy)
{
    if (win->turn == TURN_B) {
        ally.hp -= ally.def - enemy.capa1.dmg + enemy.atk;
        sfText_setString(ally.t_hp, my_getstr(ally.hp));
        win->turn = TURN_A;
    }
    return (ally.hp);
}

int do_dmg(win_t *win, poke_t ally, poke_t enemy)
{
    if (win->turn == TURN_A)
        enemy.hp = get_action(win, ally, enemy);
    return (enemy.hp);
}
