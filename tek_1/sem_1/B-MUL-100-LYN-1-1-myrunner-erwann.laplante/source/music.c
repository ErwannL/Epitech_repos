/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** music
*/

#include "../includes/my.h"

var_t detects_bat(var_t var, sfVector2i mouse)
{
    if (var.event.key.code == sfKeyF && sfMusic_getVolume(var.music) != 0) {
        sfMusic_setVolume(var.music, 0);
        var.stat_music = 1;
    }
    (mouse.y >= 545 && mouse.y <= 575 && mouse.x >= 755
    && mouse.x <= 790 && (var.event.key.code == sfMouseLeft
    || var.event.key.code == sfMouseRight) && (var.etat == 3
    || var.etat == 2)) ? var.etat = var.etat == 3 ? 0 : 1 : 0;
    if (var.event.key.code == sfKeyN && sfMusic_getVolume(var.music) == 0) {
        sfMusic_setVolume(var.music, var.volume);
        var.stat_music = 0;
    }
    if ((mouse.y >= 300 && mouse.y <= 400 && mouse.x >= 260 && mouse.x <= 510
    && (var.event.key.code == sfMouseLeft
    || var.event.key.code == sfMouseRight) || var.event.key.code == sfKeyP)
    && var.etat == 0) {
        sfRenderWindow_setMouseCursorVisible(var.window, sfTrue);
        var.etat = 11;
    }
    return var;
}

var_t detects_music(var_t var, sfVector2i mouse)
{
    if ((mouse.y >= 15 && mouse.y <= 45 && mouse.x >= 755 && mouse.x <= 785
    && (var.event.key.code == sfMouseLeft
    || var.event.key.code == sfMouseRight) || var.event.key.code == sfKeyP)
    && (var.etat == 0 || var.etat == 11)) {
        sfRenderWindow_setMouseCursorVisible(var.window, sfTrue);
        var.etat = var.etat == 0 ? 3 : 12;
    }
    if (var.event.key.code == sfKeyAdd && var.volume < 100
    && var.stat_music == 0)
        sfMusic_setVolume(var.music, ++var.volume);
    if (var.event.key.code == sfKeySubtract && var.volume > 1
    && var.stat_music == 0)
        sfMusic_setVolume(var.music, --var.volume);
    if (mouse.x >= 270 && mouse.x <= 500 && mouse.y >= 200
    && mouse.y <= 290 && (var.event.key.code == sfMouseLeft
    || var.event.key.code == sfMouseRight) && var.etat == 0) {
        sfRenderWindow_setMouseCursorVisible(var.window, sfFalse);
        var.etat = 1;
    }
    return detects_bat(var, mouse);
}

var_t select_music(var_t var)
{
    if (sfMusic_getVolume(var.music) <= 1) {
        var.sound.top = 108;
        var.sound.left = 108;
    } else {
        var.sound.top = (var.volume >= 33 ? 0 : 108);
        var.sound.left = (var.volume >= 66 || var.volume < 33 ? 0 : 108);
    }
    return var;
}
