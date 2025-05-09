/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** name
*/

#include "my_rpg.h"

win_t *choose_name(win_t *win)
{
    sfVector2f pos = sfSprite_getPosition(win->cursor);

    if (pos.x != 40 && pos.y != 75 && pos.y != 135 && pos.y != 195
    && pos.y != 255 && pos.y != 315)
        sfSprite_setPosition(win->cursor, (sfVector2f){40, 75});
    pos = sfSprite_getPosition(win->cursor);
    (sfKeyboard_isKeyPressed(sfKeyDown) && pos.y <= 255) ? pos.y += 60 : 0;
    (sfKeyboard_isKeyPressed(sfKeyUp) && pos.y >= 135) ? pos.y -= 60 : 0;
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        win->player->name = pos.y == 75 ? "SACHA" : pos.y == 135
        ? "EGGLANTIN" : pos.y == 195 ? "HUBERT" : pos.y == 255 ? "PATRICE"
        : "ROBERTO";
        sfSprite_setPosition(win->cursor, (sfVector2f){55, 120});
        win->step = 9;
        win->old_step = win->step;
        return win;
    }
    sfSprite_setPosition(win->cursor, (sfVector2f){40, pos.y});
    sfRenderWindow_drawSprite(win->window, win->cursor, NULL);
    return win;
}

win_t *accept_name(win_t *win)
{
    sfRenderWindow_drawSprite(win->window, win->frame->speak, NULL);
    sfRenderWindow_drawSprite(win->window, win->chen, NULL);
    sfRenderWindow_drawText(win->window, create_font(win, 30
    , (sfVector2f){50, 400}, "Well"), NULL);
    sfRenderWindow_drawText(win->window, create_font(win, 30
    , (sfVector2f){150, 400}, win->player->name), NULL);
    sfRenderWindow_drawText(win->window, create_font(win, 30
    , (sfVector2f){50, 470}, "Your quest is about to begin \
    \n\nCome   see   me   in   my   lab!"), NULL);
    if (sfKeyboard_isKeyPressed(sfKeyB))
        win->step = 10;
    return win;
}
