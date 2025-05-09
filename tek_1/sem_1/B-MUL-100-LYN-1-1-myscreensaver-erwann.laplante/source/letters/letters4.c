/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myscreensaver-erwann.laplante
** File description:
** letters4
*/

#include "../../includes/my.h"

variables_t letters20(variables_t var)
{
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
    var.position.y += 10;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 10;
    var.position.y = 120;
    return (letters21(var));
}

variables_t letters19(variables_t var)
{
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
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    return (letters20(var));
}

variables_t letters18(variables_t var)
{
    var.position.y = 130;
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
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 10;
    var.position.y = 120;
    return (letters19(var));
}

variables_t letters17(variables_t var)
{
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
    var.position.y = 130;
    var.position.x += 10;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.y += 5;
    var.position.x -= 5;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 10;
    var.position.y -= 10;
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    return (letters18(var));
}

variables_t letters16(variables_t var)
{
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
    my_draw_square(var.framebuffer, var.position, 5, sfWhite);
    var.position.x += 10;
    var.position.y = 120;
    return (letters17(var));
}
