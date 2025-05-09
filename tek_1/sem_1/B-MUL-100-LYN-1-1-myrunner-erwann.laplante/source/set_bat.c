/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** set_bat
*/

#include "../includes/my.h"

var_t set_bat_first(var_t var)
{
    var.x_bat -= var.speed_bat / 10;
    if (var.x_bat <= -70) {
        var.x_bat = 800;
        var.y_bat = rand() % 540;
        var.speed_bat += 5;
    }
    return var;
}

var_t set_bat_second(var_t var)
{
    var.x_bat2 -= var.speed_bat / 10;
    if (var.x_bat2 <= -70) {
        var.x_bat2 = 800;
        var.y_bat2 = rand() % 540;
        var.speed_bat += 5;
    }
    return var;
}

var_t set_bat_third(var_t var)
{
    var.x_bat3 -= var.speed_bat / 10;
    if (var.x_bat3 <= -70) {
        var.x_bat3 = 800;
        var.y_bat3 = rand() % 540;
        var.speed_bat += 5;
    }
    return var;
}

var_t set_bat_fourth(var_t var)
{
    var.x_bat4 -= var.speed_bat / 10;
    if (var.x_bat4 <= -70) {
        var.x_bat4 = 800;
        var.y_bat4 = rand() % 540;
        var.speed_bat += 5;
    }
    return var;
}

var_t set_bat_fifth(var_t var)
{
    var.x_bat5 -= var.speed_bat / 10;
    if (var.x_bat5 <= -70) {
        var.x_bat5 = 800;
        var.y_bat5 = rand() % 540;
        var.speed_bat += 5;
    }
    return var;
}
