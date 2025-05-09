/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** text
*/

#include "../include/my.h"

var_t *click_button(var_t *var, int y)
{
    if ((y == 150 || y == 250 || y == 350)
    && (var->event.key.code == sfMouseLeft
    || var->event.key.code == sfMouseRight)) {
        sfText_setColor(var->text, sfRed);
        if (y == 150) {
            sfMusic_play(var->click_mouse);
            var->etat == STAT_LOOSE ? var->previous_stat = STAT_LOOSE : 0;
            ((var->etat == STAT_MENU) ? (var->etat = STAT_INTRO)
            : (var->etat = STAT_MENU));
        } else if (y == 250) {
            sfMusic_play(var->click_mouse);
            var->etat = STAT_SETTINGS;
        } else {
            var->etat = STAT_QUIT;
        }
    }
    return var;
}

sfText *setup_text(var_t *var, int x, int y, char *text)
{
    sfVector2f position = {x, y};
    sfVector2i mouse = sfMouse_getPositionRenderWindow(var->window);

    var->text = sfText_create();
    sfText_setFont(var->text, var->font);
    if (mouse.x > position.x + var->dif_x / 2
    && mouse.x < position.x + my_strlen(text) * 18 + var->dif_x / 2
    && mouse.y > position.y + var->dif_y / 2
    && mouse.y < position.y + 70 + var->dif_y / 2) {
        sfText_setColor(var->text, sfBlue);
        var = click_button(var, y);
    } else {
        sfText_setColor(var->text, sfBlack);
    }
    sfText_setCharacterSize(var->text, 50);
    sfText_setString(var->text, text);
    sfText_setPosition(var->text, position);
    return var->text;
}

sfText *setup_how_play(var_t *var, int x, int y, char *text)
{
    sfVector2f position = {x, y};

    var->text = sfText_create();
    sfText_setFont(var->text, var->font);
    sfText_setColor(var->text, sfBlack);
    sfText_setCharacterSize(var->text, 22);
    sfText_setString(var->text, text);
    sfText_setPosition(var->text, position);
    return var->text;
}

var_t *click_button_pause(var_t *var, int y)
{
    if ((y == 150 || y == 250 || y == 350)
    && (var->event.key.code == sfMouseLeft
    || var->event.key.code == sfMouseRight)) {
        sfText_setColor(var->text, sfRed);
        if (y == 150) {
            sfMusic_play(var->click_mouse);
            var->etat = STAT_GAME;
        } else if (y == 250) {
            sfMusic_play(var->click_mouse);
            var->etat = STAT_MENU;
            var->previous_stat = STAT_PAUSE;
            sfClock_restart(var->clock_pause);
        } else {
            sfMusic_play(var->click_mouse);
            var->etat = STAT_QUIT;
        }
    }
    return var;
}

sfText *setup_pause(var_t *var, int x, int y, char *text)
{
    sfVector2f position = {x, y};
    sfVector2i mouse = sfMouse_getPositionRenderWindow(var->window);

    var->text = sfText_create();
    sfText_setFont(var->text, var->font);
    if (mouse.x > position.x + var->dif_x / 2
    && mouse.x < position.x + my_strlen(text) * 18 + var->dif_x / 2
    && mouse.y > position.y + var->dif_y / 2
    && mouse.y < position.y + 70 + var->dif_y / 2) {
        sfText_setColor(var->text, sfBlue);
        var = click_button_pause(var, y);
    } else {
        sfText_setColor(var->text, sfBlack);
    }
    sfText_setCharacterSize(var->text, 50);
    sfText_setString(var->text, text);
    sfText_setPosition(var->text, position);
    return var->text;
}
