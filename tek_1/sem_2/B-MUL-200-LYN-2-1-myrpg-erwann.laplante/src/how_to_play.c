/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** how_to_play
*/

#include "my_rpg.h"

void print_htp(win_t *win)
{
    if (win->step == 5) {
        sfRenderWindow_drawText(win->window, create_font(win, 14
        , (sfVector2f){250, 315}, "MOUSE CLICK\
        Quit the homepage menu\n\nESCAPE\
        Quit the game from anywhere.\n\nA        Click button in menu.\n\nB\
        Click on some button when it's written\n\nNUMBER 1 TO 9\
        Customize the player\n\nARROW\
        Move in menu & move the player\n\nENTER\
        Go from game to pause menu\n\nQ\
        Quit Some Menu or page\n"), NULL);
        if (sfKeyboard_isKeyPressed(sfKeyQ)) {
            win->old_step = win->step;
            win->step = 1;
        }
    }
    if (win->step == 1) {
        sfRenderWindow_drawText(win->window, create_font(win, 18
        , (sfVector2f){585, 50}, "[To   Quit\nThe   Game\nPress   Escape]")
        , NULL);
    }
}

win_t *print_option_bis(win_t *win, sfVector2f pos)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) && pos.x == 60 && pos.y == 250) {
        win->volume = 1;
        refresh_sound(win);
    }
    if (sfKeyboard_isKeyPressed(sfKeyA) && pos.x == 380 && pos.y == 250) {
        win->volume = 0;
        refresh_sound(win);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        win->step = win->prev_step;
        sfSprite_setPosition(win->cursor, win->prev_step == 1 ?
        (sfVector2f){55, 180} : (sfVector2f){500, 300});
    }
    sfRenderWindow_drawSprite(win->window, win->frame->options, NULL);
    sfRenderWindow_drawText(win->window, create_font(win, 25
    , (sfVector2f){99, 50}, "800x600 pxs          1920x1080 pxs\n\n\n\n\n\
    \n\nSound on                        Sound off\n\n\n\n\n\n\n[To\
    Quit        Press        Q]\n"), NULL);
    sfRenderWindow_drawSprite(win->window, win->cursor, NULL);
    return win;
}

win_t *print_option(win_t *win)
{
    sfVector2f pos = sfSprite_getPosition(win->cursor);

    if (pos.x != 60 && pos.x != 385 && pos.y != 50 && pos.y != 250)
        sfSprite_setPosition(win->cursor, (sfVector2f){60, 50});
    pos = sfSprite_getPosition(win->cursor);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        sfSprite_setPosition(win->cursor, (sfVector2f){60, pos.y});
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        sfSprite_setPosition(win->cursor, (sfVector2f){380, pos.y});
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        sfSprite_setPosition(win->cursor, (sfVector2f){pos.x, 50});
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        sfSprite_setPosition(win->cursor, (sfVector2f){pos.x, 250});
    if (sfKeyboard_isKeyPressed(sfKeyA) && pos.x == 60 && pos.y == 50)
        sfRenderWindow_setSize(win->window, (sfVector2u){800, 600});
    if (sfKeyboard_isKeyPressed(sfKeyA) && pos.x == 380 && pos.y == 50)
        sfRenderWindow_setSize(win->window, (sfVector2u){1920, 1080});
    return print_option_bis(win, pos);
}

int print_pause_bis(win_t *win)
{
    if ((int)sfSprite_getPosition(win->cursor).x == 500
    && (int)sfSprite_getPosition(win->cursor).y == 180
    && win->step == -2) {
        win->prev_step = -2;
        win->old_step = win->step;
        win->step = 11;
        win->player_rect = (sfIntRect){25, win->customise[win->what_custo], 17
        , 16};
        return 0;
    }
    if ((int)sfSprite_getPosition(win->cursor).x == 55
    && (int)sfSprite_getPosition(win->cursor).y == 180
    && win->step == 1) {
        win->prev_step = 1;
        win->old_step = win->step;
        win->step = 4;
        return 0;
    }
    return detect_click_pause(win);
}

int print_pause(win_t *win)
{
    if ((int)sfSprite_getPosition(win->cursor).x == 500
    && (int)sfSprite_getPosition(win->cursor).y == 360) {
        win->old_step = win->step;
        win->step = 10;
        return 0;
    }
    if ((int)sfSprite_getPosition(win->cursor).x == 500
    && (int)sfSprite_getPosition(win->cursor).y == 300
    && win->step == -2) {
        win->prev_step = -2;
        win->old_step = win->step;
        win->step = 4;
        return 0;
    }
    return print_pause_bis(win);
}
