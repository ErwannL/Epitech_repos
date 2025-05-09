/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** events
*/

#include "../include/my.h"

var_t *events_music_bis(var_t *var)
{
    if (var->event.key.code == sfKeyAdd && var->volume < 100
    && var->stat_music == MUSIC_ON) {
        var->volume++;
        sfMusic_setVolume(var->music, var->volume);
        sfMusic_setVolume(var->music, var->volume);
        sfMusic_setVolume(var->gold, var->volume);
    }
    if (var->event.key.code == sfKeySubtract && var->volume > 1
    && var->stat_music == MUSIC_ON) {
        var->volume--;
        sfMusic_setVolume(var->music, var->volume);
        sfMusic_setVolume(var->music, var->volume);
        sfMusic_setVolume(var->gold, var->volume);
    }
    return var;
}

var_t *events_music(var_t *var)
{
    if (var->event.key.code == sfKeyF
    && sfMusic_getVolume(var->music) != 0) {
        sfMusic_setVolume(var->music, 0);
        sfMusic_setVolume(var->click_mouse, 0);
        sfMusic_setVolume(var->gold, 0);
        var->stat_music = MUSIC_OFF;
    }
    if (var->event.key.code == sfKeyN && sfMusic_getVolume(var->music) == 0) {
        sfMusic_setVolume(var->music, var->volume);
        sfMusic_setVolume(var->click_mouse, var->volume);
        sfMusic_setVolume(var->gold, var->volume);
        var->stat_music = MUSIC_ON;
    }
    return events_music_bis(var);
}

var_t *events_key_bis(var_t *var)
{
    if (var->event.key.code == sfKeyReturn && var->etat == STAT_BUILDING)
        var->etat = var->previous_stat;
    if (var->event.key.code == sfKeyReturn && var->etat == STAT_HOW_PLAY)
        var->etat = var->previous_stat;
    if (var->event.key.code == sfKeyB && var->etat == STAT_GAME
    && var->life > 0)
        var->etat = STAT_BUY;
    if (var->event.key.code == sfKeyReturn && var->etat == STAT_BUY)
        var->etat = STAT_GAME;
    return var;
}

var_t *events_key(var_t *var)
{
    if (var->event.key.code == sfKeyP && var->etat == STAT_GAME)
        var->etat = STAT_PAUSE;
    if (var->event.key.code == sfKeyTab && var->etat == STAT_INTRO)
        var->etat = STAT_GAME;
    if (var->event.key.code == sfKeyM && var->etat == STAT_GAME)
        var->etat = STAT_MENU;
    if (var->event.key.code == sfKeyB && (var->etat == STAT_SETTINGS
    || var->etat == STAT_PAUSE)) {
        var->previous_stat = var->etat;
        var->etat = STAT_BUILDING;
    }
    if (var->event.key.code == sfKeyH && (var->etat == STAT_SETTINGS
    || var->etat == STAT_PAUSE)) {
        var->previous_stat = var->etat;
        var->etat = STAT_HOW_PLAY;
    }
    if (var->event.key.code == sfKeySpace && var->etat == STAT_SETTINGS)
        var->etat = STAT_MENU;
    var = events_key_bis(var);
    return var;
}

var_t *detect_events(var_t *var)
{
    while (sfRenderWindow_pollEvent(var->window, &var->event)) {
        if (var->event.key.code == sfKeyEscape
        || var->event.type == sfEvtClosed) {
            var->e_nbr = 84;
            var->etat = STAT_QUIT;
            return var;
        }
        var = events_key(var);
        var = events_music(var);
    }
    return var;
}
