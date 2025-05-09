/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** flag
*/

#include "../includes/my.h"

var_t second_flag (var_t var)
{
    var = dec_var(var);
    var = set_sprite(var);
    var.etat = 1;
    while (sfRenderWindow_isOpen(var.window)) {
        if (var.etat == 1)
            var = print_game(var);
        if (var.etat == 2)
            var = print_pause(var);
        var = detects_event(var);
        if (var.r_nbr == 84 || var.exit_nbr == 84) {
            var = print_end(var);
            var.etat = -1;
            return var;
        }
    }
    return var;
}

void test_flag(int ac, char **av, var_t var)
{
    if (av[1][1] == 'h' && av[1][2] == '\0') {
        case_h();
    } else if (av[1][1] == 'm' && av[1][2] == '\0') {
        var = dec_var(var);
        var = set_sprite(var);
        var = play_game_loop(var);
        var = free_foncion(var);
    } else if (av[1][1] == 'i' && av[1][2] == '\0') {
        var = second_flag(var);
    } else {
        my_putstr("./my_runner: bad options.\nretry with -h\n");
    }
    return;
}
