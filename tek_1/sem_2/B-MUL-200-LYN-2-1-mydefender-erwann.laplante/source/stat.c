/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** stat
*/

#include "../include/my.h"

var_t *print_stat_five(var_t *var)
{
    if (var->etat == STAT_LOOSE) {
        var = print_loose(var);
    } else {
        var->e_nbr = 84;
    }
    return var;
}

var_t *print_stat_four(var_t *var)
{
    if (var->etat == STAT_INTRO) {
        var = print_intro(var);
    } else if (var->etat == STAT_BUY) {
        var = print_buy(var);
    } else {
        var = print_stat_five(var);
    }
    return var;
}

var_t *print_stat_three(var_t *var)
{
    if (var->etat == STAT_BUILDING) {
        var = print_building(var);
    } else if (var->etat == STAT_HOW_PLAY) {
        var = print_how_play(var);
    } else {
        var = print_stat_four(var);
    }
    return var;
}

var_t *print_stat_two(var_t *var)
{
    if (var->etat == STAT_GAME) {
        var = print_game(var);
    } else if (var->etat == STAT_PAUSE) {
        var = print_pause(var);
    } else {
        var = print_stat_three(var);
    }
    return var;
}

var_t *print_stat(var_t *var)
{
    if (var->etat == STAT_MENU) {
        var = print_menu(var);
    } else if (var->etat == STAT_SETTINGS) {
        var = print_settings(var);
    } else {
        var = print_stat_two(var);
    }
    return var;
}
