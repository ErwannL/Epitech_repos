/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** event
*/

#include "../includes/my.h"

var_t detects_mouse(var_t var)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(var.window);

    (var.event.key.code == sfKeyReturn && var.etat == 0) ?
    sfRenderWindow_setMouseCursorVisible(var.window, sfFalse), var.etat = 1 :
    0;
    (var.event.key.code == sfKeyTab && var.etat == 6) ?
    sfRenderWindow_setMouseCursorVisible(var.window, sfFalse), var.etat = 5 :
    0;
    (var.event.key.code == sfKeyTab && var.etat == 9) ?
    sfRenderWindow_setMouseCursorVisible(var.window, sfFalse), var.etat = 8 :
    0;
    (var.event.key.code == sfKeyTab && var.etat == 11) ?
    sfRenderWindow_setMouseCursorVisible(var.window, sfTrue), var.etat = 0 : 0;
    (var.event.key.code == sfKeySpace && var.etat == 5) ?
    sfRenderWindow_setMouseCursorVisible(var.window, sfTrue), var.etat = 6 : 0;
    (var.event.key.code == sfKeySpace && var.etat == 8) ?
    sfRenderWindow_setMouseCursorVisible(var.window, sfTrue), var.etat = 9 : 0;
    (var.event.key.code == sfKeySpace && (var.etat == 7 || var.etat == 10)) ?
    sfRenderWindow_setMouseCursorVisible(var.window, sfTrue), var.etat = 0 : 0;
    return detects_music(var, mouse);
}

var_t detects_bird(var_t var)
{
    (var.event.key.code == sfKeyTab && (var.etat == 3 || var.etat == 12)) ?
    sfRenderWindow_setMouseCursorVisible(var.window, sfTrue),
    var.etat = var.etat == 3 ? 0 : 11 : 0;
    if ((var.event.key.code == sfKeyNumpad1 || var.event.key.code == sfKeyNum1)
    && (var.etat == 2 || var.etat == 3 || var.etat == 6 || var.etat == 9
    || var.etat == 12))
        var.choice_bird = 0;
    if ((var.event.key.code == sfKeyNumpad2 || var.event.key.code == sfKeyNum2)
    && (var.etat == 2 || var.etat == 3 || var.etat == 6 || var.etat == 9
    || var.etat == 12))
        var.choice_bird = 1;
    if ((var.event.key.code == sfKeyNumpad3 || var.event.key.code == sfKeyNum3)
    && (var.etat == 2 || var.etat == 3 || var.etat == 6 || var.etat == 9
    || var.etat == 12))
        var.choice_bird = 2;
    if ((var.event.key.code == sfKeyNumpad4 || var.event.key.code == sfKeyNum4)
    && (var.etat == 2 || var.etat == 3 || var.etat == 6 || var.etat == 9
    || var.etat == 12))
        var.choice_bird = 3;
    return detects_mouse(var);
}

var_t detects_etat(var_t var)
{
    if ((var.event.key.code == sfKeyNum2
    || var.event.key.code == sfKeyNumpad2) && var.etat == 11) {
        var.etat = 8;
    }
    (var.event.key.code == sfKeyTab && var.etat == 2) ?
    sfRenderWindow_setMouseCursorVisible(var.window, sfFalse), var.etat = 1 :
    0;
    (var.event.key.code == sfKeySpace && var.etat == 1) ?
    sfRenderWindow_setMouseCursorVisible(var.window, sfTrue), var.etat = 2 : 0;
    if (var.event.key.code == sfKeyM && var.etat != 5 && var.etat != 6
    && var.etat != 7 && var.etat != 8 && var.etat != 9 && var.etat != 10) {
        sfRenderWindow_setMouseCursorVisible(var.window, sfTrue);
        var = free_foncion(var);
        sfRenderWindow_destroy(var.window);
        var = replay(var);
        var = dec_var(var);
        var = set_sprite(var);
        var.etat = -1;
    }
    return detects_bird(var);
}

var_t detects_key(var_t var)
{
    if (var.event.key.code == sfKeyUp && var.y_bird >= 10 && (var.etat == 1
    || var.etat == 5 || var.etat == 8)) {
        var.y_bird -= 10;
        var.sprite_bird = move_sprite(var.x_bird, var.y_bird,
        var.sprite_bird);
    }
    if (var.event.key.code == sfKeyReturn && var.y_bird >= 10
    && (var.etat == 1 || var.etat == 5 || var.etat == 8)) {
        var.y_bird -= 50;
        var.sprite_bird = move_sprite(var.x_bird, var.y_bird,
        var.sprite_bird);
    }
    if (var.event.key.code == sfKeyDown &&
    var.y_bird <= 600 - 10 - var.bird.height && (var.etat == 1 || var.etat == 5
    || var.etat == 8)) {
        var.y_bird += 10;
        var.sprite_bird = move_sprite(var.x_bird, var.y_bird,
        var.sprite_bird);
    }
    return detects_etat(var);
}

var_t detects_event(var_t var)
{
    while (sfRenderWindow_pollEvent(var.window, &var.event)) {
        if (var.event.key.code == sfKeyEscape) {
            var.exit_nbr = 84;
            return var;
        }
        if (var.event.type == sfEvtClosed) {
            var.exit_nbr = 84;
            return var;
        }
        if (var.event.key.code == sfKeySpace && var.etat == 4)
            var.nbr = 0;
        if (var.event.key.code == sfKeyN && var.etat == 0)
            var.etat = 11;
        if ((var.event.key.code == sfKeyNum1
        || var.event.key.code == sfKeyNumpad1) && var.etat == 11) {
            var.etat = 5;
        }
        var = detects_key(var);
    }
    return var;
}
