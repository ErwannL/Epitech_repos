/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myscreensaver-erwann.laplante
** File description:
** letters2
*/

#include "../../includes/my.h"

variables_t letters10(variables_t var)
{
    var.position.x -= 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 10;
    var.position.y = 120;
    var.position.x += 10;
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
    return (letters11(var));
}

variables_t letters9(variables_t var)
{
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y -= 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x -= 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y = 120;
    var.position.x -= 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 10;
    var.position.y = 120;
    var.position.y = 140;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    return (letters10(var));
}

variables_t letters8(variables_t var)
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
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y -= 5;
    return (letters9(var));
}

variables_t letters7(variables_t var)
{
    var.position.y -= 15;
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y = 120;
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    return (letters8(var));
}

variables_t letters6(variables_t var)
{
    var.position.y = 120;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 10;
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
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    return (letters7(var));
}
