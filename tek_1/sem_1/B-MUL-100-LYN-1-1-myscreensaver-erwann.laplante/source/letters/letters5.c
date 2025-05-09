/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myscreensaver-erwann.laplante
** File description:
** letters4
*/

#include "../../includes/my.h"

variables_t letters22(variables_t var)
{
    for (int i = 0; i != 121; i++, var.position.x += 5)
        my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y = 295;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    for (int i = 0; i != 7; i++, var.position.y += 5)
        my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x = 95;
    var.position.y = 295;
    for (int i = 0; i != 121; i++, var.position.x += 5)
        my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    sfTexture_updateFromPixels(var.texture, var.framebuffer->pixels, \
    800, 600, 0, 0);
    sfRenderWindow_clear(var.window, sfBlack);
    sfRenderWindow_drawSprite(var.window, var.sprite, NULL);
    sfRenderWindow_display(var.window);
    return (var);
}

variables_t letters21(variables_t var)
{
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    for (int i = 0; i != 4; i++, my_draw_square(var.framebuffer, \
    var.position, 5, sfWhite), var.position.y += 5);
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    var.position.y = 120;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x = 95;
    var.position.y = 295;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    for (int i = 0; i != 7; i++, my_draw_square(var.framebuffer, \
    var.position, 5, sfWhite), var.position.y += 5);
    return (letters22(var));
}
