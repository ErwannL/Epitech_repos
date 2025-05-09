/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** grass
*/

#include "my_rpg.h"

win_t *grass_two(win_t *win)
{
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 450, 505, 590, 820});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 85, 385, 535, 820});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 510, 625, 481, 520});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 745, 925, 595, 700});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 690, 925, 420, 525});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 745, 925, 186, 194});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){4, 0
    , 400, 300, 300, 14, 109, 366, 400});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 96, 390, 61, 460});
    return win;
}

win_t *grass(win_t *win)
{
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){3, 400
    , 400, 300, 300, 61, 605, 930, 1110});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){3, 400
    , 400, 300, 300, 61, 130, 581, 954});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){3, 400
    , 475, 300, 300, 235, 661, 745, 789});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){3, 400
    , 400, 300, 300, 61, 465, 391, 630});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){3, 400
    , 465, 300, 300, 346, 661, 201, 350});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){3, 400
    , 474, 191, 295, 430, 661, 64, 64});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){3, 400
    , 400, 191, 300, 61, 346, 64, 124});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 810, 925, 786, 820});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 450, 505, 590, 820});
    return grass_two(win);
}

win_t *print_grass(win_t *win)
{
    int j = 0;
    int n = 0;
    int y = 0;

    if (win->int_grass >= 1) {
        for (int i = win->x_player; i < (win->x_player +
        (win->player_rect.width * 4)); i += 25) {
            j = rand() % 10;
            n = rand() % 2;
            y = n == 0 ? (win->y_player + (win->player_rect.height * 4) + j) :
            (win->y_player + (win->player_rect.height * 4) - j);
            sfSprite_setPosition(win->grass_sprite, (sfVector2f){i, y});
            sfRenderWindow_drawSprite(win->window, win->grass_sprite, NULL);
        }
        win->int_grass--;
    }
    return win;
}
