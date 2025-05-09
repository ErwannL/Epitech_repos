/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myscreensaver-erwann.laplante
** File description:
** letters3
*/

#include "../../includes/my.h"

variables_t letters15(variables_t var)
{
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x -= 5;
    var.position.y += 10;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y = 120;
    var.position.x -= 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 10;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    return (letters16(var));
}

variables_t letters14(variables_t var)
{
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 10;
    var.position.y = 120;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    return (letters15(var));
}

variables_t letters13(variables_t var)
{
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 10;
    var.position.y = 120;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y -= 10;
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y = 120;
    var.position.x -= 5;
    return (letters14(var));
}

variables_t letters12(variables_t var)
{
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 10;
    var.position.y = 120;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y -= 10;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y -= 10;
    return (letters13(var));
}

variables_t letters11(variables_t var)
{
    var.position.y = 120;
    var.position.x -= 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 10;
    var.position.y = 120;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    return (letters12(var));
}
