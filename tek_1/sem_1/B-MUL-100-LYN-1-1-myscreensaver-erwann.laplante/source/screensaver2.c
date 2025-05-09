/*
** EPITECH PROJECT, 2021
** graphical_programing
** File description:
** csfml_initialisation
*/

#include "../includes/my.h"

variables_t dec_var_2(variables_t var)
{
    var.mode.width = 800;
    var.mode.height = 600;
    var.mode.bitsPerPixel = 32;
    var.position.x = 0;
    var.position.y = 600;
    var.size = 0;
    var.r_val = 0;
    return (var);
}

variables_t screen_saver2_2(variables_t var)
{
    while (sfRenderWindow_pollEvent(var.window, &var.event)) {
        if (var.event.key.code == sfKeyLeft) {
            var = detroy_all(var);
            var.r_val = 84;
            screen_saver1_1();
            return (var);
        }
        if (var.event.key.code == sfKeyRight) {
            var = detroy_all(var);
            var.r_val = 84;
            screen_saver3_1();
            return (var);
        }
        if (var.event.type == sfEvtClosed || var.r_val == 84) {
            var = detroy_all(var);
            var.r_val = 84;
            return (var);
        }
    }
}

variables_t screen_saver2_4(variables_t var)
{
    while ((var.position.x != 0) && (var.position.y != 600)) {
        var = screen_saver2_2(var);
        if (var.r_val == 84)
            return (var);
        var.position.x -= var.size;
        var.position.y += var.size;
        my_draw_square(var.framebuffer, var.position, var.size, sfRed);
        var.size -= 1;
        sfTexture_updateFromPixels(var.texture, var.framebuffer->pixels, 800,\
        600, 0, 0);
        sfRenderWindow_clear(var.window, sfBlack);
        sfRenderWindow_drawSprite(var.window, var.sprite, NULL);
        sfRenderWindow_display(var.window);
    }
    return (var);
}

variables_t screen_saver2_3(variables_t var)
{
    while ((var.position.x <= 600) && (var.position.y >= 0)) {
        var = screen_saver2_2(var);
        if (var.r_val == 84)
            return (var);
        var.size += 1;
        my_draw_square(var.framebuffer, var.position, var.size, sfBlue);
        var.position.x += var.size;
        var.position.y -= var.size;
        sfTexture_updateFromPixels(var.texture, var.framebuffer->pixels, 800,\
        600, 0, 0);
        sfRenderWindow_clear(var.window, sfBlack);
        sfRenderWindow_drawSprite(var.window, var.sprite, NULL);
        sfRenderWindow_display(var.window);
    }
    var = screen_saver2_4(var);
    return (var);
}

int screen_saver2_1(void)
{
    variables_t var;

    var = dec_var_2(screen_saver0_1());
    var.window = sfRenderWindow_create(var.mode, "Screen saver 2", sfClose,\
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
        var = screen_saver2_3(var);
        if (var.r_val == 84)
            return (84);
    }
    return (0);
}
