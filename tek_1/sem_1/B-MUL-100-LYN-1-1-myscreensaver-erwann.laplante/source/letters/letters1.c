/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myscreensaver-erwann.laplante
** File description:
** letters1
*/

#include "../../includes/my.h"

variables_t letters5(variables_t var)
{
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    var.position.y -= 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y = 120;
    var.position.x -= 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 10;
    return (letters6(var));
}

variables_t letters4(variables_t var)
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
    return (letters5(var));
}

variables_t letters3(variables_t var)
{
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
    var.position.y -= 10;
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    return (letters4(var));
}

variables_t letters2(variables_t var)
{
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
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
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    return (letters3(var));
}

variables_t letters1(variables_t var)
{
    var.position.x = 225;
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
    var.position.x += 10;
    var.position.y = 120;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    return (letters2(var));
}
