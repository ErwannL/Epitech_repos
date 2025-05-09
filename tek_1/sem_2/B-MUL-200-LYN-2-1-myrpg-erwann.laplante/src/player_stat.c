/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** player_stat
*/

#include "my_rpg.h"

win_t *print_player_stat_bis(win_t *win)
{
    sfRenderWindow_drawText(win->window, create_font(win, 25
    , (sfVector2f){175, 475}, (win->piece == 0) ? "Your bedroom\n"
    : (win->piece == 1) ? "Your living room\n" : (win->piece == 2)
    ? "Your neighborhood\n" : (win->piece == 3) ? "The green path\n"
    : (win->piece == 4) ? "The city\n" : (win->piece == 5)
    ? "The Chen labo\n" : "The nurse labo\n"), NULL);
    sfRenderWindow_drawText(win->window, create_font(win, 25
    , (sfVector2f){175, 525}, "[To        Quit        Press        Q]")
    , NULL);
    sfRenderWindow_drawSprite(win->window, win->frame->options, NULL);
    sfSprite_setPosition(win->player_sprite, (sfVector2f){win->x_player
    , win->y_player});
    return win;
}

win_t *print_player_stat(win_t *win)
{
    sfRenderWindow_drawText(win->window, create_font(win, 25
    , (sfVector2f){175, 50}, "You are : \n"), NULL);
    sfRenderWindow_drawText(win->window, create_font(win, 25
    , (sfVector2f){175, 100}, win->player->name), NULL);
    sfRenderWindow_drawText(win->window, create_font(win, 25
    , (sfVector2f){175, 175}
    , "This  is  your  player, \n\ntry  it  with  the  arrows  !\n"), NULL);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        win->step = -2;
    win->player_sprite = create_sprite("res/spr/char_mini.png"
    , (sfVector2f){win->x_player, win->y_player});
    win = move_player(win);
    sfSprite_setTextureRect(win->player_sprite, win->player_rect);
    sfSprite_setScale(win->player_sprite, (sfVector2f){5, 5});
    sfSprite_setPosition(win->player_sprite, (sfVector2f){320, 300});
    sfRenderWindow_drawSprite(win->window, win->player_sprite, NULL);
    sfRenderWindow_drawText(win->window, create_font(win, 25
    , (sfVector2f){175, 425}, "Your position in the map : \n"), NULL);
    return print_player_stat_bis(win);
}
