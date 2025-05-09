/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** move
*/

#include "../includes/my.h"

var_t animate_bird(var_t var)
{
    var.time_bird = sfClock_getElapsedTime(var.clock_bird);
    var.second_bird = var.time_bird.microseconds / 100000;
    if (var.second_bird > 0.5) {
        var.bird.left += var.bird.width;
        if (var.bird.left >= 882) {
            var.bird.left = 0;
        }
        sfClock_restart(var.clock_bird);
    }
    var.second_bird = 0;
    return var;
}

var_t animate_bat(var_t var)
{
    var.time_bat = sfClock_getElapsedTime(var.clock_bat);
    var.second_bat = var.time_bat.microseconds / 100000;
    if (var.second_bat > 0.8) {
        var = select_bat_first(var);
        var = select_bat_second(var);
        var = select_bat_third(var);
        var = select_bat_fourth(var);
        var = select_bat_fifth(var);
        sfClock_restart(var.clock_bat);
    }
    var.second_bat = 0;
    return var;
}

var_t move_bat(var_t var)
{
    var.time_speed = sfClock_getElapsedTime(var.clock_speed);
    var.second_speed = var.time_speed.microseconds / 100000;
    if (var.second_speed > 0.5) {
        var = set_bat_first(var);
        var = set_bat_second(var);
        var = set_bat_third(var);
        var = set_bat_fourth(var);
        var = set_bat_fifth(var);
        sfClock_restart(var.clock_speed);
    }
    var.second_speed = 0;
    return var;
}

var_t move_sun(var_t var)
{
    var.time_sun = sfClock_getElapsedTime(var.clock_sun);
    var.second_sun = var.time_sun.microseconds / 10;
    if (var.second_sun > 1) {
        var.x_sun -= 1;
        if (var.x_sun == -50)
            var.x_sun = 800;
        sfClock_restart(var.clock_sun);
    }
    var.second_sun = 0;
    return var;
}

var_t move_cloud(var_t var)
{
    var.time_cloud = sfClock_getElapsedTime(var.clock_cloud);
    var.second_cloud = var.time_cloud.microseconds / 10;
    if (var.second_cloud > 1) {
        var.x_cloud -= 5;
        var.x_cloud2 -= 5;
        var.x_cloud3 -= 3;
        var.x_cloud4 -= 3;
        if (var.x_cloud2 == 0)
            var.x_cloud = 800;
        if (var.x_cloud == 0)
            var.x_cloud2 = 800;
        if (var.x_cloud3 <= -800)
            var.x_cloud3 = 800;
        if (var.x_cloud4 <= -800)
            var.x_cloud4 = 800;
        sfClock_restart(var.clock_cloud);
    }
    var.second_cloud = 0;
    return var;
}
