/*
** EPITECH PROJECT, 2021
** graphical_programing
** File description:
** csfml_initialisation
*/

#include "../includes/my.h"

variables_t dec_var_8(variables_t var)
{
    var.mode.width = 800;
    var.mode.height = 600;
    var.mode.bitsPerPixel = 32;
    var.position.x = 400;
    var.position.y = 300;
    var.r_val = 0;
    var.size = 0;
    var.color.a = 0;
    return (var);
}

variables_t screen_saver8_4(variables_t var)
{
    var = screen_saver8_5(var);
    if (var.r_val == 84)
        return (var);
    draw_empty_circle(var.framebuffer, var.position, var.size--, var.color);
    var.color.a--;
    sfTexture_updateFromPixels(var.texture, var.framebuffer->pixels,\
    800, 600, 0, 0);
    sfRenderWindow_clear(var.window, sfBlack);
    sfRenderWindow_drawSprite(var.window, var.sprite, NULL);
    sfRenderWindow_display(var.window);
    return (var);
}

variables_t screen_saver8_3(variables_t var)
{
    var = screen_saver8_5(var);
    if (var.r_val == 84)
        return (var);
    draw_empty_circle(var.framebuffer, var.position, var.size++, var.color);
    var.color.a++;
    sfTexture_updateFromPixels(var.texture, var.framebuffer->pixels,\
    800, 600, 0, 0);
    sfRenderWindow_clear(var.window, sfBlack);
    sfRenderWindow_drawSprite(var.window, var.sprite, NULL);
    sfRenderWindow_display(var.window);
    return (var);
}

variables_t screen_saver8_2(variables_t var)
{
    1 == 1 ? var.color.r = rand() % 255, var.color.g = rand() % 255,\
    var.color.b = rand() % 255 : 0;
    while (var.color.a < 255) {
        var = screen_saver8_3(var);
        if (var.r_val == 84)
            return (var);
    }
    1 == 1 ? var.color.r = rand() % 255, var.color.g = rand() % 255,\
    var.color.b = rand() % 255 : 0;
    while (var.color.a > 0) {
        var = screen_saver8_4(var);
        if (var.r_val == 84)
            return (var);
    }
    return (var);
}

int screen_saver8_1(void)
{
    variables_t var;

    var = dec_var_8(screen_saver0_1());
    var.window = sfRenderWindow_create(var.mode, "Screen saver 8", sfClose,\
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
        var = screen_saver8_2(var);
        if (var.r_val == 84)
            return (84);
    }
    return (84);
}
