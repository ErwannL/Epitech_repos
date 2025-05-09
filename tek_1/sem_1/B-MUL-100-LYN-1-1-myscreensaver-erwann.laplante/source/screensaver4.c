/*
** EPITECH PROJECT, 2021
** graphical_programing
** File description:
** csfml_initialisation
*/

#include "../includes/my.h"

variables_t dec_var_4(variables_t var)
{
    var.mode.width = 800;
    var.mode.height = 600;
    var.mode.bitsPerPixel = 32;
    var.position.x = 0;
    var.position.y = 0;
    var.position2.x = 0;
    var.position2.y = 0;
    var.position3.x = 200;
    var.position3.y = 0;
    var.r_val = 0;
    var.window = sfRenderWindow_create(var.mode, "Screen saver 4", sfClose,\
    NULL);
    return (var);
}

variables_t screen_saver4_2(variables_t var)
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
            screen_saver3_1();
            return (var);
        }
        if (var.event.key.code == sfKeyRight) {
            var = detroy_all(var);
            var.r_val = 84;
            screen_saver5_1();
            return (var);
        }
    }
    return (var);
}

variables_t screen_saver4_3(variables_t var)
{
    sfColor col[8] = {sfRed, sfBlack, sfGreen, sfBlue, sfMagenta, sfYellow,\
    sfCyan, sfWhite};

    for (var.position.x = 0; var.position.x < 800; var.position.x += 50) {
        for (var.position.y = 0; var.position.y < 600; var.position.y += 50) {
            var = screen_saver4_2(var);
            if (var.r_val == 84)
                return (var);
            var.random = rand() % 8;
            my_draw_square(var.framebuffer, var.position, 50, col[var.random]);
            sfTexture_updateFromPixels(var.texture, var.framebuffer->pixels,\
            800, 600, 0, 0);
            sfRenderWindow_clear(var.window, sfBlack);
            sfRenderWindow_drawSprite(var.window, var.sprite, NULL);
            sfRenderWindow_display(var.window);
        }
    }
    return (var);
}

int screen_saver4_1(void)
{
    variables_t var;

    var = dec_var_4(screen_saver0_1());
    sfRenderWindow_setFramerateLimit(var.window, 144);
    var.framebuffer = framebuffer_create(800, 600);
    var.texture = sfTexture_create(800, 600);
    if (!var.texture || !var.window)
        return (84);
    var.sprite = sfSprite_create();
    sfSprite_setTexture(var.sprite, var.texture, sfTrue);
    sfRenderWindow_setFramerateLimit(var.window, 30);
    while (sfRenderWindow_isOpen(var.window)) {
        var = screen_saver4_3(var);
        if (var.r_val == 84)
            return (84);
        my_draw_square(var.framebuffer, var.position2, 600, sfBlack);
        my_draw_square(var.framebuffer, var.position3, 600, sfBlack);
    }
    return (84);
}
