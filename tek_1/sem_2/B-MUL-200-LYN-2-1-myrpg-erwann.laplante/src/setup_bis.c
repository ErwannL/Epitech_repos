/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** setup_bis
*/

#include "my_rpg.h"

void setup_sprites_five(win_t *win)
{
    win->rain = 0;
    sfSprite_setScale(win->moving_chen, (sfVector2f){5, 5});
    win->x_labo = 930;
    win->y_labo = -35;
    win->moving_labo = create_sprite("res/spr/char_mini.png",
                                (sfVector2f){win->x_labo, win->y_labo});
    sfSprite_setTextureRect(win->moving_labo,
                                            (sfIntRect){26, 323, 17, 16});
    sfSprite_setScale(win->moving_labo, (sfVector2f){5, 5});
    win->quest = malloc(sizeof(quest_t) * 3);
    for (int i = 0; i != 3; i++) {
        win->quest[i].done = i == 0 ? 0 : -1;
        win->quest[i].name = i == 0 ? "find Chen\n" : i == 1
        ? "find Ronflex\n" : "find the nurse\n";
    }
    win->step = 0;
    win->prev_step = 0;
}
