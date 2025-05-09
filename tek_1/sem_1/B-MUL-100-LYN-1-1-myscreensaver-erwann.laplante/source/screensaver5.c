/*
** EPITECH PROJECT, 2021
** graphical_programing
** File description:
** csfml_initialisation
*/

#include "../includes/my.h"

variables_t dec_var_5(variables_t var)
{
    var.mode.width = 800;
    var.mode.height = 600;
    var.mode.bitsPerPixel = 32;
    var.r_val = 0;
    return (var);
}

variables_t screen_saver5_2(variables_t var)
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
            screen_saver4_1();
            return (var);
        }
        if (var.event.key.code == sfKeyRight) {
            var = detroy_all(var);
            var.r_val = 84;
            screen_saver6_1();
            return (var);
        }
    }
    return (var);
}

variables_t screen_saver5_3(variables_t var)
{
    sfColor col[8] = {sfRed, sfBlack, sfGreen, sfBlue, sfMagenta, sfYellow,\
    sfCyan, sfWhite};

    var = screen_saver5_2(var);
    if (var.r_val == 84)
        return (var);
    var.random = rand() % 8;
    my_put_pixel(var.framebuffer, rand() % 800, rand() % 600,col[var.random]);
    sfTexture_updateFromPixels(var.texture, var.framebuffer->pixels,\
    800, 600, 0, 0);
    sfRenderWindow_clear(var.window, sfBlack);
    sfRenderWindow_drawSprite(var.window, var.sprite, NULL);
    sfRenderWindow_display(var.window);
    return (var);
}

int screen_saver5_1(void)
{
    variables_t var;

    var = dec_var_5(screen_saver0_1());
    var.window = sfRenderWindow_create(var.mode, "Screen saver 5", sfClose,\
    NULL);
    sfRenderWindow_setFramerateLimit(var.window, 144);
    var.framebuffer = framebuffer_create(800, 600);
    var.texture = sfTexture_create(800, 600);
    if (!var.texture || !var.window)
        return (84);
    var.sprite = sfSprite_create();
    sfSprite_setTexture(var.sprite, var.texture, sfTrue);
    sfRenderWindow_setFramerateLimit(var.window, 30);
    while (sfRenderWindow_isOpen(var.window)) {
        var = screen_saver5_3(var);
        if (var.r_val == 84)
            return (84);
    }
    return (84);
}
