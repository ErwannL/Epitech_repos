/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** create_fights
*/

#include "my_rpg.h"

opt_t *create_actions(win_t *win, int sz, char *list[], sfVector2i where)
{
    opt_t *txt = (opt_t *)malloc(sizeof(opt_t) * (sz + 1));

    for (int i = 0, x = 0, y = 0; i < sz; x += 120, i++) {
        if (x >= 121) {
            x = 0;
            y = 59;
        }
        txt[i].count = sz;
        txt[i].where = (sfVector2f){where.x + x, where.y + y};
        txt[i].txt = create_font(win, 20, txt[i].where, list[i]);
    }
    return txt;
}

void create_fights(win_t *win)
{
    char *action[] = {"ATK", "PKM", "BAG", "RUN!"};
    win->select_action = create_actions(win, 4, action
                                                , (sfVector2i){450, 430});
    win->skip_intro_fight = 0;
    0 == 0 ? win->cursorx_limit = 0, win->turn = 1 : 0;
    win->fight_interface = create_sprite("res/spr/batlle_interface.png",
                                                    (sfVector2f){100, 50});
    win->stat_interface = create_sprite("res/spr/batlle_interface.png",
                                                    (sfVector2f){100, 0});
    win->introf_interface = create_sprite("res/spr/batlle_interface.png",
                                                    (sfVector2f){100, 0});
    sfSprite_setTextureRect(win->fight_interface, (sfIntRect){177, 169, 160
                                                                , 145});
    sfSprite_setTextureRect(win->stat_interface, (sfIntRect){177, 311, 160
                                                                , 145});
    sfSprite_setTextureRect(win->introf_interface, (sfIntRect){177, 7, 160
                                                                , 145});
    sfSprite_setScale(win->fight_interface, (sfVector2f){4, 4});
    sfSprite_setScale(win->introf_interface, (sfVector2f){4, 4});
    sfSprite_setScale(win->stat_interface, (sfVector2f){4, 4});
}
