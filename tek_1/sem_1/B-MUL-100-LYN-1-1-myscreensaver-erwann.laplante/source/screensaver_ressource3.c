/*
** EPITECH PROJECT, 2021
** graphical_programing
** File description:
** csfml_initialisation
*/

#include "../includes/my.h"

initialisation_t help_main(initialisation_t i, char **av)
{
    for (; i.s[i.i] != '\0'; ((i.s[i.i] == av[1][0] && av[1][1] == '\0') ?\
    (*i.sc[i.i])(), i.r = 0 : 0), i.i++);
    return (i);
}

variables_t detroy_all(variables_t var)
{
    framebuffer_destroy(var.framebuffer);
    sfSprite_destroy(var.sprite);
    sfTexture_destroy(var.texture);
    sfRenderWindow_destroy(var.window);
    return (var);
}

variables_t screen_saver8_5(variables_t var)
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
            screen_saver7_1();
            return (var);
        }
        if (var.event.key.code == sfKeyRight) {
            var = detroy_all(var);
            var.r_val = 84;
            screen_saver9_1();
            return (var);
        }
    }
    return (var);
}
