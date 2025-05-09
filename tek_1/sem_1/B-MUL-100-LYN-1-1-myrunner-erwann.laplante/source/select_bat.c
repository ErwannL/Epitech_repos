/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** select_bat
*/

#include"../includes/my.h"

var_t select_bat_first(var_t var)
{
    var.bat.left += var.bat.width;
    if (var.bat.left >= 209) {
        var.bat.top += var.bat.height;
        var.bat.left = 0;
    }
    if (var.bat.top >= 99)
        var.bat.top = 0;
    return var;
}

var_t select_bat_second(var_t var)
{
    var.bat2.left += var.bat2.width;
    if (var.bat2.left >= 209) {
        var.bat2.top += var.bat2.height;
        var.bat2.left = 0;
    }
    if (var.bat2.top >= 99)
        var.bat2.top = 0;
    return var;
}

var_t select_bat_third(var_t var)
{
    var.bat3.left += var.bat3.width;
    if (var.bat3.left >= 209) {
        var.bat3.top += var.bat3.height;
        var.bat3.left = 0;
    }
    if (var.bat3.top >= 99)
        var.bat3.top = 0;
    return var;
}

var_t select_bat_fourth(var_t var)
{
    var.bat4.left += var.bat4.width;
    if (var.bat4.left >= 209) {
        var.bat4.top += var.bat4.height;
        var.bat4.left = 0;
    }
    if (var.bat4.top >= 99)
        var.bat4.top = 0;
    return var;
}

var_t select_bat_fifth(var_t var)
{
    var.bat5.left += var.bat5.width;
    if (var.bat5.left >= 209) {
        var.bat5.top += var.bat5.height;
        var.bat5.left = 0;
    }
    if (var.bat5.top >= 99)
        var.bat5.top = 0;
    return var;
}
