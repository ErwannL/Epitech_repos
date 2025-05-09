/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player file
*/

#include "my_rpg.h"

void print_player_infos(win_t *win)
{
    char *infos[] = {"PLAYER", "BADGES", "POKEDEX", "[PRESS   B   BUTTON]"};
    opt_t *opt = create_menu(win, 4, infos, (sfVector2i){230, 330});
    char *buf = open_file();

    if (buf != NULL) {
        for (int i = 0; i < opt[0].count; i++) {
            sfRenderWindow_drawText(win->window, opt[i].txt, NULL);
        }
        if (sfKeyboard_isKeyPressed(sfKeyB)) {
            sfSound_play(win->hit_btn);
            win->step = 10;
            sfClock_restart(win->move_player);
            sfClock_restart(win->time_grass);
        }
    } else {
        win->step = 6;
    }
    free(opt);
}
