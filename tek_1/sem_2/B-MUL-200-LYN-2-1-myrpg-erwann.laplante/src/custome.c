/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** custome
*/

#include "my_rpg.h"

int key_bis(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum6)
    || sfKeyboard_isKeyPressed(sfKeyNumpad6))
        return 6;
    if (sfKeyboard_isKeyPressed(sfKeyNum7)
    || sfKeyboard_isKeyPressed(sfKeyNumpad7))
        return 7;
    if (sfKeyboard_isKeyPressed(sfKeyNum8)
    || sfKeyboard_isKeyPressed(sfKeyNumpad8))
        return 8;
    if (sfKeyboard_isKeyPressed(sfKeyNum9)
    || sfKeyboard_isKeyPressed(sfKeyNumpad9))
        return 9;
    return -1;
}

int key(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum0)
    || sfKeyboard_isKeyPressed(sfKeyNumpad0))
        return 0;
    if (sfKeyboard_isKeyPressed(sfKeyNum1)
    || sfKeyboard_isKeyPressed(sfKeyNumpad1))
        return 1;
    if (sfKeyboard_isKeyPressed(sfKeyNum2)
    || sfKeyboard_isKeyPressed(sfKeyNumpad2))
        return 2;
    if (sfKeyboard_isKeyPressed(sfKeyNum3)
    || sfKeyboard_isKeyPressed(sfKeyNumpad3))
        return 3;
    if (sfKeyboard_isKeyPressed(sfKeyNum4)
    || sfKeyboard_isKeyPressed(sfKeyNumpad4))
        return 4;
    if (sfKeyboard_isKeyPressed(sfKeyNum5)
    || sfKeyboard_isKeyPressed(sfKeyNumpad5))
        return 5;
    return key_bis();
}

int custome(win_t *win, int j)
{
    int a = key();

    sfRenderWindow_drawText(win->window, create_font(win, 40
    , (sfVector2f){30, 525}, "    Your Player :\n"), NULL);
    sfSprite_setScale(win->player_sprite, (sfVector2f){3, 3});
    if (a != -1) {
        win->player_sprite = create_sprite("res/spr/char_mini.png"
        , (sfVector2f){win->x_player, win->y_player});
        win->what_custo = a;
    }
    win->player_rect = (sfIntRect){25, win->customise[win->what_custo], 17
    , 16};
    sfSprite_setTextureRect(win->player_sprite, win->player_rect);
    sfSprite_setScale(win->player_sprite, (sfVector2f){3, 3});
    sfSprite_setPosition(win->player_sprite, (sfVector2f){500, 525});
    sfRenderWindow_drawSprite(win->window, win->player_sprite, NULL);
    sfSprite_setPosition(win->player_sprite, (sfVector2f){win->x_player
    , win->y_player});
    sfSprite_setScale(win->player_sprite, (sfVector2f){5, 5});
    return j;
}
