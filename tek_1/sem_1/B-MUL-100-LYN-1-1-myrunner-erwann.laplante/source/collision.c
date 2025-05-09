/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** collision
*/

#include "../includes/my.h"

var_t collision(var_t var)
{
    if ((var.x_bat <= var.x_bird + var.bird.width
    && var.y_bat <= var.y_bird + var.bat.height
    && var.y_bat >= var.y_bird)
    || (var.x_bat2 <= var.x_bird + var.bird.width
    && var.y_bat2 <= var.y_bird + var.bat2.height
    && var.y_bat2 >= var.y_bird)
    || (var.x_bat3 <= var.x_bird + var.bird.width
    && var.y_bat3 <= var.y_bird + var.bat3.height
    && var.y_bat3 >= var.y_bird)
    || (var.x_bat4 <= var.x_bird + var.bird.width
    && var.y_bat4 <= var.y_bird + var.bat4.height
    && var.y_bat4 >= var.y_bird)
    || (var.x_bat5 <= var.x_bird + var.bird.width
    && var.y_bat5 <= var.y_bird + var.bat5.height
    && var.y_bat5 >= var.y_bird)) {
        var.r_nbr = 84;
    }
    return var;
}
