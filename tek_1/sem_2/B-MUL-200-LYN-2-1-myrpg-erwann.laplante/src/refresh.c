/*
** EPITECH PROJECT, 2022
** refresh
** File description:
** refresh file.
*/

#include "my_rpg.h"

void state_fight(win_t *win)
{
    if (win->step == FIGHT_RIVAL) {
        reset_stat(win);
        win->rival.poke = set_fight(win, win->you, win->rival);
    }
    if (win->step == STATE_FIGHT) {
        if (win->wild.poke.hp <= 0) {
            win->step = 10;
            win->wild.poke.hp = 20;
            win->you.poke.xp += 10;
            win->wild.poke.hp = win->wild.poke.hp_max;
            sfText_setString(win->wild.poke.t_hp
            , my_getstr(win->wild.poke.hp));
            change_poke(win);
        }
        win->wild.poke = set_fight(win, win->you, win->wild);
    }
}

void refresh_sprites_bis(win_t *win)
{
    ((win->step == 9) ? win = accept_name(win) : 0);
    ((win->step == 12) ? win = print_pokedex(win) : 0);
    ((win->step == 13) ? win = tp_player_in_pause(win) : 0);
}

void refresh_sprites(win_t *win)
{
    if (win->step == 0)
        sfRenderWindow_drawSprite(win->window, win->start, NULL);
    if (win->step == 10) {
        win = move_player(win);
        sfSprite_setTextureRect(win->player_sprite, win->player_rect);
        sfSprite_setTextureRect(win->map, (sfIntRect){win->x_map, win->y_map
        , 2000, 900});
        sfSprite_setPosition(win->player_sprite
        , (sfVector2f){win->x_player, win->y_player});
        sfRenderWindow_drawSprite(win->window, win->map, NULL);
        sfRenderWindow_drawSprite(win->window, win->player_sprite, NULL);
        win = print_grass(print_moving_collide(win));
        win = print_rain(win);
        win = tp_player(win);
    }
    state_fight(win);
    update_xp(win);
    ((win->step == 6) ? intro_scene(win) : 0);
    ((win->step == 7) ? (setup_opts(win, 2), name_scene(win)) : 0);
    refresh_sprites_bis(win);
}

void refresh_sound(win_t *win)
{
    if ((win->step == 0) || (win->step == 1)) {
        sfMusic_destroy(win->bgm);
        create_sounds(win, "res/snd/open.ogg");
    }
    if ((win->step >= 6) && (win->step <= 9)) {
        sfMusic_destroy(win->bgm);
        create_sounds(win, "res/snd/prof.ogg");
    }
    if (win->step >= 10) {
        sfMusic_destroy(win->bgm);
        create_sounds(win, "res/snd/tututu.ogg");
    }
    if (win->step == STATE_FIGHT) {
        sfMusic_destroy(win->bgm);
        create_sounds(win, "res/snd/battle.ogg");
    }
    if (win->step == 4) {
        sfMusic_destroy(win->bgm);
        create_sounds(win, "res/snd/open.ogg");
    }
}

void refresh_all(win_t *win)
{
    int j = 0;

    sfRenderWindow_clear(win->window, sfWhite);
    refresh_sprites(win);
    if (win->step == 4)
        win = print_option(win);
    else
        refresh_menu(win);
    if (win->old_step != win->step) {
        refresh_sound(win);
        win->old_step = win->step;
    }
    if (win->step == -2) {
        j = print_done(win, j);
        j = print_to_do(win, j);
        j = custome(win, j);
    }
    (win->step == 11) ? win = print_player_stat(win) : 0;
    sfRenderWindow_display(win->window);
    sfClock_restart(win->time);
}
