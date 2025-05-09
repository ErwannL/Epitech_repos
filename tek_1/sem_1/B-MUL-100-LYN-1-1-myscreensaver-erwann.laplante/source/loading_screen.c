/*
** EPITECH PROJECT, 2021
** graphical_programing
** File description:
** csfml_initialisation
*/

#include "../includes/my.h"

variables_t dec_var_0(variables_t var)
{
    var.mode.width = 800;
    var.mode.height = 600;
    var.mode.bitsPerPixel = 32;
    var.position.x = 0;
    var.position.y = 0;
    var.position2.x = 100;
    var.position2.y = 300;
    var.r_val = 0;
    var.position3.x = 0;
    var.position3.y = 0;
    var.position4.x = 200;
    var.position4.y = 0;
    return (var);
}

variables_t screen_saver0_2(variables_t var)
{
    while (sfRenderWindow_pollEvent(var.window, &var.event)) {
        if (var.event.type == sfEvtClosed) {
            framebuffer_destroy(var.framebuffer);
            sfSprite_destroy(var.sprite);
            sfTexture_destroy(var.texture);
            sfRenderWindow_destroy(var.window);
            var.r_val = 84;
            return (var);
        }
    }
    return (var);
}

variables_t screen_saver0_3(variables_t var)
{
    var = letters1(var);
    for (int i = 0; i != 2; i++, my_draw_square(var.framebuffer,\
    var.position2, 30, sfBlue), var.position2.x += 30);
    return (var);
}

variables_t screen_saver0_1(void)
{
    variables_t var;

    1 == 1 ? var = dec_var_0(var), var.window =\
    sfRenderWindow_create(var.mode, "Loading screen", sfClose, NULL),\
    var.framebuffer = framebuffer_create(800, 600),\
    my_draw_square(var.framebuffer, var.position3, 600, sfBlack),\
    my_draw_square(var.framebuffer, var.position4, 600, sfBlack), var.texture\
    = sfTexture_create(800, 600), var.sprite = sfSprite_create(),\
    sfSprite_setTexture(var.sprite, var.texture, sfTrue),\
    sfRenderWindow_setFramerateLimit(var.window, 30) : 0;
    while (sfRenderWindow_isOpen(var.window) && var.position2.x < 730) {
        var = screen_saver0_3(var);
        var.n = rand() % 50000;
        for (int j = 0; j != var.n; j++) {
            var = screen_saver0_2(var);
            if (var.r_val == 84)
                return (var);
        }
    }
    sfRenderWindow_close(var.window);
}
