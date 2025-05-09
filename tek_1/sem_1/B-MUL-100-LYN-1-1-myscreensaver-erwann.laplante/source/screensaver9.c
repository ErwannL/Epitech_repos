/*
** EPITECH PROJECT, 2021
** graphical_programing
** File description:
** csfml_initialisation
*/

#include "../includes/my.h"

variables_t dec_var_9(variables_t var)
{
    1 == 1 ? var.color.r = 0, var.color.g = 0, var.color.b = 0, var.color.a =\
    0, var.r_val = 0, var.mode.width = 800, var.mode.height = 600,\
    var.mode.bitsPerPixel = 32, var.size = 20, var.n = rand() % 4 : 0;
    var.n == 0 ? var.r = rand() % (800 - var.size), var.position.x = var.r >\
    var.size ? var.r : var.size, var.position.y = var.size, var.position2.x =\
    800 - var.size, var.r = rand() % (600 - var.size), var.position2.y = var.r\
    > var.size ? var.r : var.size : 0;
    var.n == 1 ? var.position.x = 800 - var.size, var.r = rand() % (600 -\
    var.size), var.position.y = var.r > var.size ? var.r : var.size, var.r =\
    rand() % (800 - var.size), var.position2.x = var.r > var.size ? var.r :\
    var.size, var.position2.y = 600 - var.size : 0;
    var.n == 2 ? var.r = rand() % (800 - var.size), var.position.x = var.r >\
    var.size ? var.r : var.size, var.position.y = 600 - var.size,\
    var.position2.x = var.size, var.r = rand() % (600 - var.size),\
    var.position2.y = var.r > var.size ? var.r : var.size : 0;
    var.n == 3 ? var.position.x = var.size, var.r = rand() % (600 - var.size),\
    var.position.y = var.r > var.size ? var.r : var.size, var.r = rand() %\
    (800 - var.size), var.position2.x = var.r > var.size ? var.r : var.size,\
    var.position2.y = var.size : 0;
    return (var);
}

variables_t screen_saver9_2(variables_t var)
{
    while (sfRenderWindow_pollEvent(var.window, &var.event)) {
        if (var.event.type == sfEvtClosed) {
            var = detroy_all(var);
            var.r_val = 84;
            return (var);
        }
        if (var.event.key.code == sfKeyLeft) {
            var = detroy_all(var);
            var.r_val = 84;
            screen_saver8_1();
            return (var);
        }
    }
    return (var);
}

variables_t screen_saver9_4(variables_t var)
{
    while (var.color.a > 0) {
        1 == 1 ? var.color.r--, var.color.g--, var.color.b--, var.color.a--,\
        var.size -= 10, draw_line(var), var.size += 10, var.position.x =\
        var.position2.x, var.position.y = var.position2.y, var.n = (var.n + 1)\
        % 4, update(var) : 0;
        var = screen_saver9_2(var);
        if (var.r_val == 84)
            return (var);
        var.n == 0 ? var.position2.x = 800 - var.size, var.r = rand() % (600 -\
        var.size), var.position2.y = var.r > var.size ? var.r : var.size : 0;
        var.n == 1 ? var.r = rand() % (800 - var.size), var.position2.x =\
        var.r > var.size ? var.r : var.size, var.position2.y = 600 - var.size\
        : 0;
        var.n == 2 ? var.position2.x = var.size, var.r = rand() % (600 -\
        var.size), var.position2.y = var.r > var.size ? var.r : var.size : 0;
        var.n == 3 ? var.r = rand() % (800 - var.size), var.position2.x =\
        var.r > var.size ? var.r : var.size, var.position2.y = var.size : 0;
    }
    return (var);
}

variables_t screen_saver9_3(variables_t var)
{
    while (var.color.a < 255) {
        1 == 1 ? var.color.r++, var.color.g++, var.color.b++, var.color.a++,\
        var.size -= 10, draw_line(var), var.size += 10, var.position.x =\
        var.position2.x, var.position.y = var.position2.y, var.n = (var.n + 1)\
        % 4, update(var) : 0;
        var = screen_saver9_2(var);
        if (var.r_val == 84)
            return (var);
        var.n == 0 ? var.position2.x = 800 - var.size, var.r = rand() % (600 -\
        var.size), var.position2.y = var.r > var.size ? var.r : var.size : 0;
        var.n == 1 ? var.r = rand() % (800 - var.size), var.position2.x =\
        var.r > var.size ? var.r : var.size, var.position2.y = 600 - var.size\
        : 0;
        var.n == 2 ? var.position2.x = var.size, var.r = rand() % (600 -\
        var.size), var.position2.y = var.r > var.size ? var.r : var.size : 0;
        var.n == 3 ? var.r = rand() % (800 - var.size), var.position2.x =\
        var.r > var.size ? var.r : var.size, var.position2.y = var.size : 0;
    }
    return (var);
}

int screen_saver9_1(void)
{
    variables_t var;

    1 == 1 ? var = dec_var_9(screen_saver0_1()), var.window =\
    sfRenderWindow_create(var.mode, "Screen saver 9", sfClose, NULL),\
    sfRenderWindow_setFramerateLimit(var.window, 144), var.framebuffer =\
    framebuffer_create(800, 600), var.texture = sfTexture_create(800, 600),\
    var.sprite = sfSprite_create() : 0;
    if (!var.texture || !var.window)
        return (84);
    sfSprite_setTexture(var.sprite, var.texture, sfTrue);
    sfRenderWindow_setFramerateLimit(var.window, 30);
    while (sfRenderWindow_isOpen(var.window)) {
        var = screen_saver9_3(var);
        if (var.r_val == 84)
            return (84);
        var = screen_saver9_4(var);
        if (var.r_val == 84)
            return (84);
    }
    return (84);
}
