/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** pause_tp_player
*/

#include "my_rpg.h"

void tp_player_in_pause_five(win_t *win, sfVector2f pos)
{
    if (pos.y == 466 && sfKeyboard_isKeyPressed(sfKeyA)) {
        win->piece = 6;
        win->x_map = 1240;
        win->y_map = 86;
        win->x_player = 400;
        win->y_player = 400;
        win->path_map = my_strcpy("./res/map/viridian.png");
        win->map = create_sprite(win->path_map, (sfVector2f){0, 0});
        sfSprite_setScale(win->map, (sfVector2f){4, 3});
    }
    sfRenderWindow_drawSprite(win->window, win->frame->options, NULL);
    sfRenderWindow_drawText(win->window, create_font(win, 25
    , (sfVector2f){75, 50}, "You can move the cursor to\nteleport anywhere.\
    \n\n        - To your bedroom\n\n        - To your living room\n\n    \
    - To your neighborhood\n\n        - To the green path\n\n    \
    - To the city\n\n        - To the chen labo\n\n        - To the nurselabo\
    \n\n[To    Quit        Press        Q]\n"), NULL);
    sfRenderWindow_drawSprite(win->window, win->cursor, NULL);
}

void tp_player_in_pause_four(win_t *win, sfVector2f pos)
{
    if (pos.y == 354 && sfKeyboard_isKeyPressed(sfKeyA)) {
        win->piece = 4;
        win->x_player = 400;
        win->y_player = 320;
        win->x_map = 535;
        win->y_map = 926;
        win->path_map = my_strcpy("./res/map/viridian.png");
        win->map = create_sprite(win->path_map, (sfVector2f){0, 0});
        sfSprite_setScale(win->map, (sfVector2f){4, 3});
    }
    if (pos.y == 410 && sfKeyboard_isKeyPressed(sfKeyA)) {
        win->piece = 5;
        win->x_map = 1530;
        win->y_map = 220;
        win->x_player = 400;
        win->y_player = 430;
        win->path_map = my_strcpy("./res/map/pallet.png");
        win->map = create_sprite(win->path_map, (sfVector2f){0, 0});
        sfSprite_setScale(win->map, (sfVector2f){2.52, 1.92});
    }
}

void tp_player_in_pause_three(win_t *win, sfVector2f pos)
{
    if (pos.y == 242 && sfKeyboard_isKeyPressed(sfKeyA)) {
        win->piece = 2;
        win->x_player = 400;
        win->y_player = 165;
        win->x_map = 280;
        win->y_map = 52;
        win->path_map = my_strcpy("./res/map/pallet.png");
        win->map = create_sprite(win->path_map, (sfVector2f){0, 0});
        sfSprite_setScale(win->map, (sfVector2f){2.52, 1.92});
    }
    if (pos.y == 298 && sfKeyboard_isKeyPressed(sfKeyA)) {
        win->piece = 3;
        win->x_map = 375;
        win->y_map = 1390;
        win->x_player = 400;
        win->y_player = 300;
        win->path_map = my_strcpy("./res/map/route1.png");
        win->map = create_sprite(win->path_map, (sfVector2f){0, 0});
        sfSprite_setScale(win->map, (sfVector2f){2.52, 1.92});
    }
}

void tp_player_in_pause_two(win_t *win, sfVector2f pos)
{
    if (pos.y == 130 && sfKeyboard_isKeyPressed(sfKeyA)) {
        win->piece = 0;
        win->x_map = 1168;
        win->y_map = 59;
        win->x_player = 615;
        win->y_player = 85;
        win->path_map = my_strcpy("./res/map/pallet.png");
        win->map = create_sprite(win->path_map, (sfVector2f){0, 0});
        sfSprite_setScale(win->map, (sfVector2f){2.52, 1.92});
    }
    if (pos.y == 186 && sfKeyboard_isKeyPressed(sfKeyA)) {
        win->piece = 1;
        win->x_map = 830;
        win->y_map = 64;
        win->x_player = 275;
        win->y_player = 451;
        win->path_map = my_strcpy("./res/map/pallet.png");
        win->map = create_sprite(win->path_map, (sfVector2f){0, 0});
        sfSprite_setScale(win->map, (sfVector2f){2.52, 1.92});
    }
}

win_t *tp_player_in_pause(win_t *win)
{
    sfVector2f pos = sfSprite_getPosition(win->cursor);

    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        win->step = win->prev_step;
        sfSprite_setPosition(win->cursor, (sfVector2f){500, 120});
    }
    if (pos.x != 70 && pos.y != 130 && pos.y != 186 && pos.y != 242
    && pos.y != 298 && pos.y != 354 && pos.y != 410 && pos.y != 466)
        sfSprite_setPosition(win->cursor, (sfVector2f){70, 130});
    pos = sfSprite_getPosition(win->cursor);
    if (pos.y >= 186 && sfKeyboard_isKeyPressed(sfKeyUp))
        pos.y -= 56;
    if (pos.y <= 410 && sfKeyboard_isKeyPressed(sfKeyDown))
        pos.y += 56;
    sfSprite_setPosition(win->cursor, (sfVector2f){pos.x, pos.y});
    tp_player_in_pause_two(win, pos);
    tp_player_in_pause_three(win, pos);
    tp_player_in_pause_four(win, pos);
    tp_player_in_pause_five(win, pos);
    return win;
}
