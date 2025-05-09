/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** intro file
*/

#include "my_rpg.h"

void intro_scene(win_t *win)
{
    static int i = 0;

    sfRenderWindow_drawSprite(win->window, win->frame->speak, NULL);
    sfRenderWindow_drawSprite(win->window, win->chen, NULL);
    ((i < 6) ? chen_intro(win, &i) : 0);
    win->step = ((i >= 6) ? 7 : win->step);
    win->old_step = ((i >= 6) ? 7 : win->old_step);
}

void chen_intro(win_t *win, int *i)
{
    char *intro[] = {CHEN1, CHEN2, CHEN3, CHEN4, CHEN5, CHEN6};
    sfText *txt = create_font(win, 34, (sfVector2f){55
                                        , win->win_size.y - 180}, intro[*i]);

    sfRenderWindow_drawText(win->window, txt, NULL);
    *i += (sfKeyboard_isKeyPressed(sfKeyB) ? 1 : 0);
    (sfKeyboard_isKeyPressed(sfKeyB) ? sfSound_play(win->hit_btn) : 0);
    sfText_destroy(txt);
}

void name_scene(win_t *win)
{
    static int i = 8;
    sfText *txt = create_font(win
                    , 29, (sfVector2f){95, 450}, ":  choose  his  name.");

    i = ((i > 40) ? 8 : i);
    sfSprite_setTextureRect(win->player->player
                                            , (sfIntRect){i, 34, 18, 16});
    sfSprite_setPosition(win->player->player, (sfVector2f){18, 430});
    sfRenderWindow_drawSprite(win->window, win->player->player, NULL);
    i += 17;
    sfRenderWindow_drawSprite(win->window, win->frame->name, NULL);
    for (int i = 0; i < win->opt_beg[0].count; i++) {
        sfRenderWindow_drawText(win->window, win->opt_beg[i].txt, NULL);
    }
    sfRenderWindow_drawText(win->window, txt, NULL);
    if (win->step == 7) {
        win = choose_name(win);
    }
}
