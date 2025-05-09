/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** pokedex
*/

#include "my_rpg.h"

sfIntRect *fill_rect(int *pos)
{
    sfIntRect *where_sprite = malloc(sizeof(sfIntRect) * 30);

    for (int i = 0, j = 0; i != 120; i += 4, j++) {
        where_sprite[j] = (sfIntRect){pos[i], pos[i + 1], pos[i + 2]
        , pos[i + 3]};
    }
    return where_sprite;
}

win_t *print_pokedex_bis(win_t *win, sfIntRect *where_sprite)
{
    for (int i = 0, x = 50, y = 50; i != 30; i++) {
        if (sfKeyboard_isKeyPressed(sfKeyQ)) {
            win->step = win->prev_step;
            sfSprite_setPosition(win->cursor, (sfVector2f){500, 60});
        }
        win->pokemon = create_sprite("res/spr/pokemon_face.png"
        , (sfVector2f){x, y});
        sfSprite_setTextureRect(win->pokemon, where_sprite[i]);
        sfSprite_setScale(win->pokemon, (sfVector2f){0.75, 0.75});
        sfRenderWindow_drawSprite(win->window, win->pokemon, NULL);
        x += 150;
        if (x > 650) {
            x = 50;
            y += 85;
        }
        sfSprite_destroy(win->pokemon);
    }
    return win;
}

win_t *print_pokedex(win_t *win)
{
    sfIntRect *where_sprite = fill_rect((int[120]){24, 52, 73, 72, 403, 37, 87
    , 91, 783, 46, 91, 78, 1173, 64, 88, 65, 1563, 54, 65, 74, 24, 178, 80
    , 78, 399, 166, 87, 83, 663, 174, 62, 82, 921, 174, 76, 82, 1170, 166
    , 88, 90, 1422, 174, 89, 73, 1682, 174, 87, 82, 529, 302, 83, 77, 789, 282
    , 103, 93, 1047, 302, 82, 82, 1294, 305, 91, 62, 1559, 293, 82, 91, 15
    , 436, 91, 76, 278, 421, 78, 91, 529, 436, 78, 62, 782, 421, 92, 91, 1044
    , 423, 79, 89, 1296, 405, 107, 107, 1550, 421, 91, 91, 1805, 440, 92, 72
    , 271, 554, 90, 85, 659, 549, 87, 91, 1046, 551, 84, 81, 1426, 551, 76
    , 88, 1677, 548, 92, 91});

    sfRenderWindow_drawSprite(win->window, win->frame->options, NULL);
    sfRenderWindow_drawText(win->window, create_font(win, 10
    , (sfVector2f){60, 30}, "These are all the pokemon in our world, you may\
    have already seen some!"), NULL);
    sfRenderWindow_drawText(win->window, create_font(win, 10
    , (sfVector2f){60, 550}, "[To    Quit    Press    Q]\n"), NULL);
    win = print_pokedex_bis(win, where_sprite);
    free(where_sprite);
    return win;
}
