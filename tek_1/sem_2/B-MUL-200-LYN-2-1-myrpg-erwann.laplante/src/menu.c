/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu file
*/

#include "my_rpg.h"

opt_t *create_menu(win_t *win, int sz, char *list[], sfVector2i where)
{
    opt_t *txt = (opt_t *)malloc(sizeof(opt_t) * (sz + 1));

    for (int i = 0, j = 0; i < sz; j += 59, i++) {
        txt[i].count = sz;
        txt[i].where = (sfVector2f){where.x, where.y + j};
        txt[i].txt = create_font(win, 29, txt[i].where, list[i]);
    }
    return txt;
}

void setup_opts(win_t *win, int x)
{
    char *name[] = {"SACHA", "EGGLANTIN", "HUBERT", "PATRICE", "ROBERTO"};
    char *opt_beg[] = {"RESUME", "NEW GAME", "OPTION", "HOW  TO  PLAY"};
    char *opts[] = {"POKEDEX", "TP   YOU", "PLAYER", "SAVE", "OPTION", "BACK"};

    if (x == 0) {
        win->opt_beg = create_menu(win, 4, opt_beg, (sfVector2i){90, 60});
    } else {
        for (int i = 0; i < win->opt_beg[0].count; i++)
            sfText_destroy(win->opt_beg[i].txt);
        free(win->opt_beg);
        win->opt_beg = create_menu(win, ((x == 1) ? 6 : 5)
            , ((x == 1) ? opts : name)
            , (sfVector2i){((x == 1) ? (win->win_size.x - 260) : 75)
            , ((x == 1) ? 60 : 75)});
    }
}

sfVector2f reset_pos(win_t *win)
{
    sfVector2f pos = sfSprite_getPosition(win->cursor);

    if (win->step == -2 && pos.y != 60 && pos.y != 120 && pos.y != 180
    && pos.y != 240 && pos.y != 300 && pos.y != 360)
        sfSprite_setPosition(win->cursor, (sfVector2f){500, 60});
    pos = sfSprite_getPosition(win->cursor);
    return pos;
}

void menu_event(win_t *win, int limit_max)
{
    sfVector2f pos = reset_pos(win);

    (win->event.key.type == sfEvtKeyReleased) ? win->one_time = 0 : 0;
    if ((sfKeyboard_isKeyPressed(sfKeyDown)) && (win->one_time == 0)
                                        && (win->cursor_limit < limit_max)) {
        sfSprite_setPosition(win->cursor, (sfVector2f){pos.x, pos.y + 60});
        win->one_time = 1;
        win->cursor_limit += 1;
    }
    if ((sfKeyboard_isKeyPressed(sfKeyUp)) && (win->one_time == 0)
                                                && (win->cursor_limit > 0)) {
        sfSprite_setPosition(win->cursor, (sfVector2f){pos.x, pos.y - 60});
        win->one_time = 1;
        win->cursor_limit -= 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        sfSound_play(win->hit_btn);
        if (print_pause(win) == 84)
            win->step = win->cursor_limit + 2;
    }
}

void refresh_menu(win_t *win)
{
    sfSprite *list[] = {win->frame->beg, win->frame->beg1, win->frame->ingame
                                , win->frame->options, win->frame->beg1};

    if (((win->step >= STATE_MENU) && (win->step <= 5)) || (win->step == -2)) {
        for (int i = 0, j = 0; i < win->opt_beg[0].count; i++) {
            j = ((win->step == -2) ? 2 : (win->step - 1));
            ((win->step == 2 || win->step == 5)
                ? sfRenderWindow_drawSprite(win->window, list[0], NULL) : 0);
            print_htp(win);
            sfRenderWindow_drawSprite(win->window, list[j], NULL);
            draw_cursor(win);
            sfRenderWindow_drawText(win->window, win->opt_beg[i].txt, NULL);
        }
        if (win->step != 2) {
            (win->step != 5) ? menu_event(win, win->opt_beg[0].count - 1) : 0;
            win->old_step = win->step;
            win->step = ((win->step == 3) ? 6 : win->step);
        } else
            print_player_infos(win);
    }
}
