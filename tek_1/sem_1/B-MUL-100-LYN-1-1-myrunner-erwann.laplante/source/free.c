/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** free
*/

#include"../includes/my.h"

var_t free_foncion(var_t var)
{
    sfMusic_stop(var.music);
    sfMusic_destroy(var.music);
    return var;
}
