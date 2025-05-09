/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** quest
*/

#include "my_rpg.h"

int print_done(win_t *win, int j)
{
    int a = 0;

    for (int i = 0; i != 3; i++) {
        if (win->quest[i].done == 1) {
            (a == 0) ? sfRenderWindow_drawText(win->window, create_font(win
            , 40, (sfVector2f){30, 10 + j++ * 100}, "    Quest Done :\n")
            , NULL), a++ : 0;
            sfRenderWindow_drawText(win->window, create_font(win
            , 40, (sfVector2f){30, 10 + j++ * 100}, win->quest[i].name)
            , NULL);
        }
    }
    return j;
}

int print_to_do(win_t *win, int j)
{
    int b = 0;

    for (int i = 0; i != 3; i++) {
        if (win->quest[i].done == 0) {
            (b == 0) ? sfRenderWindow_drawText(win->window, create_font(win
            , 40, (sfVector2f){30, 10 + j++ * 100}, "    To Do Quest :\n")
            , NULL), b++ : 0;
            sfRenderWindow_drawText(win->window, create_font(win
            , 40, (sfVector2f){30, 10 + j++ * 100}, win->quest[i].name)
            , NULL);
        }
    }
    return j;
}
