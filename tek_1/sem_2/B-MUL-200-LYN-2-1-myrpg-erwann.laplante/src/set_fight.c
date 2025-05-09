/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** set_fight
*/

#include "my_rpg.h"

void reset_data(win_t *win, trainer_t ally, trainer_t enemy)
{
    win->skip_intro_fight = 0;
    win->cursorx_limit = 0;
    win->cursor_limit = 0;
    sfSprite_setPosition(win->cursor, (sfVector2f){390, 450});
    sfSprite_setPosition(ally.sprite, (sfVector2f){-100, 150});
    sfSprite_setPosition(enemy.sprite, (sfVector2f){700, 50});
}

void display_intro_fight(trainer_t ally, trainer_t enemy, win_t *win)
{
    sfVector2f pos_ally = sfSprite_getPosition(ally.sprite);
    sfVector2f pos_enemy = sfSprite_getPosition(enemy.sprite);
    sfTime time_anim = sfClock_getElapsedTime(win->clock_fight);
    float seconds_anim = time_anim.microseconds / 10000.0;

    reset_data(win, ally, enemy);
    if (seconds_anim > 0.5) {
        pos_ally.x += ((pos_ally.x <= 60) ? 10 : 0);
        pos_enemy.x -= ((pos_enemy.x >= 550) ? 9 : 0);
        sfSprite_setPosition(ally.sprite, pos_ally);
        sfSprite_setPosition(enemy.sprite, pos_enemy);
        sfClock_restart(win->clock_fight);
    }
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        win->skip_intro_fight = 1;
        win->one_time = 1;
    }
    sfRenderWindow_drawSprite(win->window, win->introf_interface, NULL);
    sfRenderWindow_drawSprite(win->window, ally.sprite, NULL);
    sfRenderWindow_drawSprite(win->window, enemy.sprite, NULL);
}

void display_fight(win_t *win, poke_t ally, poke_t enemy)
{
    if (win->action == 0)
        sfRenderWindow_drawSprite(win->window, win->fight_interface, NULL);
    sfRenderWindow_drawSprite(win->window, ally.sprite_back, NULL);
    sfRenderWindow_drawSprite(win->window, enemy.sprite_front, NULL);
    handle_keys(win);
    select_action(win);
    draw_cursor(win);
    set_interfaces(win);
    draw_stat(win, ally, enemy);
}

poke_t set_fight(win_t *win, trainer_t you, trainer_t trainer)
{
    if (win->skip_intro_fight == 0 && win->int_grass != 5)
        display_intro_fight(win->you, trainer, win);
    else {
        display_fight(win, win->you.poke, trainer.poke);
        if (win->skip_intro_fight == ATK_INTERFACE)
            trainer.poke.hp = do_dmg(win, win->you.poke, trainer.poke);
        win->you.poke.hp = take_dmg(win, win->you.poke, trainer.poke);
    }
    return (trainer.poke);
}
