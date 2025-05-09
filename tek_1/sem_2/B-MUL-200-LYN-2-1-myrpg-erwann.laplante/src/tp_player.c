/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** tp_player
*/

#include "my_rpg.h"

win_t *tp_player_five(win_t *win)
{
    if (win->piece == 2 && win->x_map >= 325 && win->x_map <= 370
    && win->y_map >= 335 && win->y_map <= 350) {
        win->piece = 5;
        win->x_map = 1530;
        win->y_map = 220;
        win->x_player = 400;
        win->y_player = 430;
    }
    if (win->piece == 5 && win->x_map >= 1500 && win->x_map <= 1565
    && win->x_player >= 380 && win->x_player <= 400
    && win->y_player >= 480 && win->y_player <= 520) {
        win->piece = 2;
        win->x_map = 340;
        win->y_map = 375;
        win->x_player = 400;
        win->y_player = 300;
    }
    return tp_player_six(win);
}

win_t *tp_player_four(win_t *win)
{
    if (win->piece == 2 && win->x_map > 55 && win->x_map < 80
    && win->y_map > 90 && win->y_map < 105) {
        win->piece = 1;
        win->x_map = 830;
        win->y_map = 64;
        win->x_player = 275;
        win->y_player = 451;
    }
    if (win->piece == 4 && win->x_map > 500 && win->x_map < 570
    && win->y_player > 340 && win->y_player < 520) {
        win->piece = 3;
        win->path_map = my_strcpy("./res/map/route1.png");
        win->map = create_sprite(win->path_map, (sfVector2f){0, 0});
        sfSprite_setScale(win->map, (sfVector2f){2.52, 1.92});
        win->x_map = 375;
        win->y_map = 64;
        win->x_player = 400;
        win->y_player = 190;
    }
    return tp_player_five(win);
}

win_t *tp_player_three(win_t *win)
{
    if (win->piece == 1 && win->x_player > 190 && win->x_player < 350
    && win->y_player > 500 && win->y_player < 520) {
        win->piece = 2;
        win->x_map = 60;
        win->y_map = 140;
        win->x_player = 400;
        win->y_player = 300;
    }
    if (win->piece == 3 && win->x_map > 320 && win->x_map < 425
    && win->y_player > 0 && win->y_player < 100) {
        win->piece = 4;
        win->path_map = my_strcpy("./res/map/viridian.png");
        win->map = create_sprite(win->path_map, (sfVector2f){0, 0});
        sfSprite_setScale(win->map, (sfVector2f){4, 3});
        win->x_player = 400;
        win->y_player = 320;
        win->x_map = 535;
        win->y_map = 926;
    }
    return tp_player_four(win);
}

win_t *tp_player_two(win_t *win)
{
    if (win->piece == 1 && win->x_player > 670 && win->x_player < 730
    && win->y_player > 30 && win->y_player < 100) {
        win->piece = 0;
        win->x_map = 1168;
        win->y_map = 59;
        win->x_player = 615;
        win->y_player = 85;
    }
    if (win->piece == 3 && win->x_map > 340 && win->x_map < 415
    && win->y_player > 415 && win->y_player < 520) {
        win->piece = 2;
        win->path_map = my_strcpy("./res/map/pallet.png");
        win->map = create_sprite(win->path_map, (sfVector2f){0, 0});
        sfSprite_setScale(win->map, (sfVector2f){2.52, 1.92});
        win->x_player = 400;
        win->y_player = 165;
        win->x_map = 280;
        win->y_map = 52;
    }
    return tp_player_three(win);
}

win_t *tp_player(win_t *win)
{
    if (win->piece == 0 && win->x_player > 655 && win->x_player < 730
    && win->y_player > 15 && win->y_player < 105) {
        win->piece = 1;
        win->x_map = 830;
        win->y_map = 57;
        win->x_player = 610;
        win->y_player = 90;
    }
    if (win->piece == 2 && win->x_map > 240 && win->x_map < 325
    && win->y_player > 0 && win->y_player < 75) {
        win->piece = 3;
        win->path_map = my_strcpy("./res/map/route1.png");
        win->map = create_sprite(win->path_map, (sfVector2f){0, 0});
        sfSprite_setScale(win->map, (sfVector2f){2.52, 1.92});
        win->x_map = 375;
        win->y_map = 1390;
        win->x_player = 400;
        win->y_player = 300;
    }
    return tp_player_two(win);
}
