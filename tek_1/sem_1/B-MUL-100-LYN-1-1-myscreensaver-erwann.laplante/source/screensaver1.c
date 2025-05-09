/*
** EPITECH PROJECT, 2021
** graphical_programing
** File description:
** csfml_initialisation
*/

#include "../includes/my.h"

variables_t dec_var_1(variables_t var)
{
    1 == 1 ? var.mode.width = 800, var.mode.height = 600 : 0;
    var.mode.bitsPerPixel = 32;
    var.position2.x = 0;
    var.position2.y = 0;
    var.position3.x = 200;
    var.position3.y = 0;
    var.point_a.x = 0;
    var.point_a.y = 0;
    var.point_b.x  = 800;
    var.point_b.y = 600;
    var.color = sfBlue;
    var.dx = var.point_b.x - var.point_a.x;
    var.dy = var.point_b.y - var.point_a.y;
    var.r = 0;
    var.position.x = var.point_a.x;
    var.position.y = var.point_a.y;
    var.r_val = 0;
    var.window = sfRenderWindow_create(var.mode, "Screen saver 1", sfClose,\
    NULL);
    return (var);
}

variables_t screen_saver_1_2(variables_t var)
{
    while (sfRenderWindow_pollEvent(var.window, &var.event)) {
        if (var.event.type == sfEvtClosed || var.r_val == 84) {
            var = detroy_all(var);
            var.r_val = 84;
            return (var);
        }
        if (var.event.key.code == sfKeyRight) {
            var = detroy_all(var);
            var.r_val = 84;
            screen_saver2_1();
            return (var);
        }
    }
    return (var);
}

variables_t screen_saver_1_3(variables_t var)
{
    var = screen_saver_1_2(var);
    if (var.r_val == 84)
        return (var);
    if (var.position.x >= 800 || var.position.y >= 600) {
        var.position.x = 0;
        var.position.y = 0;
        my_draw_square(var.framebuffer, var.position2, 600, sfBlack);
        my_draw_square(var.framebuffer, var.position3, 600, sfBlack);
        var.n += 1;
        ((var.n % 2 == 1) ? (var.color = sfRed) : (var.color = sfBlue));
    }
    1 == 1 ? var.position.x++, var.r += var.dy : 0;
    ((var.r >= var.dx) ? (var.r -= var.dx, var.position.y += 1) : (0));
    my_draw_square(var.framebuffer, var.position, 10, var.color);
    sfTexture_updateFromPixels(var.texture, var.framebuffer->pixels, 800,\
    600, 0, 0);
    sfRenderWindow_clear(var.window, sfBlack);
    sfRenderWindow_drawSprite(var.window, var.sprite, NULL);
    sfRenderWindow_display(var.window);
    return (var);
}

int screen_saver1_1(void)
{
    variables_t var;

    var = dec_var_1(screen_saver0_1());
    sfRenderWindow_setFramerateLimit(var.window, 144);
    var.framebuffer = framebuffer_create(800, 600);
    var.texture = sfTexture_create(800, 600);
    if (!var.texture || !var.window)
        return (84);
    var.sprite = sfSprite_create();
    sfSprite_setTexture(var.sprite, var.texture, sfTrue);
    sfRenderWindow_setFramerateLimit(var.window, 30);
    while (sfRenderWindow_isOpen(var.window)) {
        for (int i = 0; i < var.dx; i++) {
            var = screen_saver_1_3(var);
            if (var.r_val == 84) {
                return (0);
            }
        }
    }
    return (84);
}
