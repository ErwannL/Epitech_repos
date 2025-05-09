/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** events file
*/

#include "my_rpg.h"

int ibaction(win_t *win, btn_t *btn)
{
    int hit_x = win->event.mouseButton.x;
    int hit_y = win->event.mouseButton.y;

    if (win->event.type != sfEvtMouseButtonReleased)
        return 0;
    return (((hit_x >= btn->pos.x) && (hit_x <= (btn->pos.x + btn->size.x))
        && (hit_y >= btn->pos.y) && (hit_y <= (btn->pos.y + btn->size.y)))
        ? 1 : 0);
}

win_t *step_ten(win_t *win)
{
    win->prev_step = 10;
    for (int i = 0; i != 5; i++) {
        if (can_player_move(win) == 0) {
            win = get_pos(win);
            win = game(win);
        } else {
            sfMusic_play(win->colide);
            win = save_pos(win);
        }
    }
    return win;
}

void state_game(win_t *win)
{
    if (sfKeyboard_isKeyPressed(sfKeyF))
        win->step = FIGHT_RIVAL;
}

int buttons_events(win_t *win)
{
    if (win->step == 0) {
        if (sfMouse_isButtonPressed(sfMouseLeft)
        || sfMouse_isButtonPressed(sfMouseRight)) {
            win->prev_step = win->step;
            return (win->step = 1);
        }
    } else if (win->step >= 10 && sfKeyboard_isKeyPressed(sfKeyReturn)) {
        setup_opts(win, 1);
        draw_cursor(win);
        win->old_step = win->step;
        return (win->step = -2);
    }
    if (win->step == 10)
        win = step_ten(win);
    state_game(win);
    return 0;
}
