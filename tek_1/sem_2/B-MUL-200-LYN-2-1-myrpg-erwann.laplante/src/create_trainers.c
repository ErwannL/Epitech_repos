/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** create_trainers
*/

#include "my_rpg.h"

void create_trainers(win_t *win)
{
    win->rival.sprite = create_sprite("res/spr/perso.png",
                                                    (sfVector2f){700, 50});
    sfSprite_setTextureRect(win->rival.sprite, (sfIntRect){0, 143, 26, 58});
    sfSprite_setScale(win->rival.sprite, (sfVector2f){4, 4});
    win->rival.poke = win->bulbizare;
    win->wild.poke = win->bulbizare;
    win->you.sprite = create_sprite("res/spr/perso.png",
                                                    (sfVector2f){-100, 150});
    sfSprite_setTextureRect(win->you.sprite, (sfIntRect){0, 0, 40, 52});
    sfSprite_setScale(win->you.sprite, (sfVector2f){4, 4});
    win->you.poke = win->pikachu;
}
