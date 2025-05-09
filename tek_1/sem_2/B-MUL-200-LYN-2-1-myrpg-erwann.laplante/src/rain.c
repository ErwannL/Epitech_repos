/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** rain
*/

#include "my_rpg.h"

win_t *print_rain(win_t *win)
{
    if (win->piece == 3 && win->rain == 0) {
        for (int i = 0; i != 2; i++) {
            sfRenderWindow_drawSprite(win->window, win->rain_sprite[i], NULL);
            sfSprite_setPosition(win->rain_sprite[i], (sfVector2f)
            {0, sfSprite_getPosition(win->rain_sprite[i]).y + 50});
            (sfSprite_getPosition(win->rain_sprite[i]).y >= 600) ?
            sfSprite_setPosition(win->rain_sprite[i], (sfVector2f){0, -600}) :
            sfSprite_setPosition(win->rain_sprite[i], (sfVector2f){0
            , sfSprite_getPosition(win->rain_sprite[i]).y});
        }
    }
    if ((win->piece == 4 && win->x_map > 500 && win->x_map < 570
    && win->y_player > 340 && win->y_player < 520) || (win->piece == 2
    && win->x_map > 240 && win->x_map < 325 && win->y_player > 0
    && win->y_player < 75))
        win->rain = rand() % 2;
    return win;
}
