/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** main
*/

#include"../includes/my.h"

var_t test_replay(var_t var)
{
    if (var.etat == -1) {
        if (var.exit_nbr == 84) {
            return var;
        } else {
            var = print_end(var);
            if (var.exit_nbr == 84)
                return var;
            var = free_foncion(var);
            sfRenderWindow_destroy(var.window);
            var = replay(var);
            var = dec_var(var);
            var = set_sprite(var);
        }
    }
    return var;
}

var_t play_game_loop(var_t var)
{
    while (sfRenderWindow_isOpen(var.window)) {
        if (var.etat == 0 || var.etat == 3 || var.etat == 12)
            var = print_menu(var);
        if (var.etat == 1)
            var = print_game(var);
        if (var.etat == 2)
            var = print_pause(var);
        if (var.etat == 11)
            var = print_level(var);
        if (var.etat == 5)
            var = first_level(var);
        if (var.etat == 8)
            var = second_level(var);
        var = test_replay(var);
        if (var.exit_nbr == 84)
            return var;
        sfText_setString(setup_font(var), int_to_str(var.score));
        var = resize_window(var);
    }
    return var;
}

void test_level(int ac, char **av, var_t var)
{
    if (my_strcmp(av[1], "map/map1.txt") == 0) {
        var = dec_var(var);
        var = set_sprite(var);
        var = first_level(var);
        var = free_foncion(var);
    } else if (my_strcmp(av[1], "map/map2.txt") == 0) {
        var = dec_var(var);
        var = set_sprite(var);
        var = second_level(var);
        var = free_foncion(var);
    } else
        my_putstr("This level doesn't exist.\n");
}

int main(int ac, char **av)
{
    var_t var;

    if (ac != 2) {
        case_null(ac);
        return (84);
    } else if (av[1][0] == '-') {
        test_flag(ac, av, var);
    } else {
        test_level(ac, av, var);
    }
    return 0;
}
