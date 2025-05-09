/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** draw_cursor
*/

#include "my_rpg.h"

void handle_left(win_t *win)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && (win->one_time == 0)
                                                && win->cursorx_limit > 0) {
        sfSprite_setPosition(win->cursor, (sfVector2f){win->pos_cursor.x - 180,
        win->pos_cursor.y});
        win->one_time = 1;
        win->cursorx_limit = 0;
    }
}

void handle_arrow(win_t *win)
{
    if ((sfKeyboard_isKeyPressed(sfKeyDown)) && (win->one_time == 0)
                                            && (win->cursor_limit < 1)) {
        sfSprite_setPosition(win->cursor, (sfVector2f){win->pos_cursor.x
        , win->pos_cursor.y + 70});
        win->one_time = 1;
        win->cursor_limit = 1;
    }
    if ((sfKeyboard_isKeyPressed(sfKeyUp)) && (win->one_time == 0)
                                                && (win->cursor_limit > 0)) {
        sfSprite_setPosition(win->cursor, (sfVector2f){win->pos_cursor.x
        , win->pos_cursor.y - 70});
        win->one_time = 1;
        win->cursor_limit = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyA))
        win->action = 1;
    handle_left(win);
}

void handle_keys(win_t *win)
{
    sfVector2f pos = sfSprite_getPosition(win->cursor);

    if (pos.x < 390 || pos.y < 420)
        sfSprite_setPosition(win->cursor, (sfVector2f){390, 450});
    handle_arrow(win);
    if (sfKeyboard_isKeyPressed(sfKeyRight) && (win->one_time == 0)
    && win->cursorx_limit < 1) {
        sfSprite_setPosition(win->cursor, (sfVector2f){win->pos_cursor.x + 180,
        win->pos_cursor.y});
        win->one_time = 1;
        win->cursorx_limit = 1;
    }
    if ((sfKeyboard_isKeyPressed(sfKeyDown)) && (win->one_time == 0)
                                        && (win->cursor_limit < 1)) {
        sfSprite_setPosition(win->cursor, (sfVector2f){win->pos_cursor.x,
        win->pos_cursor.y + 60});
        win->one_time = 1;
        win->cursor_limit += 1;
    }
}

void select_action(win_t *win)
{
    win->pos_cursor = sfSprite_getPosition(win->cursor);
    if (win->event.key.type == sfEvtKeyReleased)
        win->one_time = 0;
    if (sfKeyboard_isKeyPressed(sfKeyA) && win->one_time == 0
    && win->skip_intro_fight == 1) {
        if (win->cursor_limit == 0 && win->cursorx_limit == 0)
            win->skip_intro_fight = ATK_INTERFACE;
        if (win->cursor_limit == 0 && win->cursorx_limit == 1)
            win->skip_intro_fight = PKM_INTERFACE;
        if (win->cursor_limit == 1 && win->cursorx_limit == 1)
            win->skip_intro_fight = RUN_INTERFACE;
        if (win->cursor_limit == 1 && win->cursorx_limit == 0)
            win->skip_intro_fight = BAG_INTERFACE;
        sfSound_play(win->hit_btn);
        win->one_time = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyB)) {
        sfSound_play(win->hit_btn);
        win->skip_intro_fight = 1;
    }
}

void draw_cursor(win_t *win)
{
    sfVector2f pos = sfSprite_getPosition(win->cursor);

    if (win->step == -2) {
        pos.x = 500;
        sfSprite_setPosition(win->cursor, pos);
    }
    if (win->step == 8) {
        select_action(win);
    }
    sfRenderWindow_drawSprite(win->window, win->cursor, NULL);
}
