/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** main
*/

#include "../include/my.h"

void print_h(void)
{
    my_putstr("Usage: ./tetris [options]\n");
    my_putstr("Options:\n");
    my_putstr("--help               Display this help\n");
    my_putstr("-L --level={num}     Start Tetris at level num (def: 1)\n");
    my_putstr("-l --key-left={K}    Move the tetrimino LEFT using the K key ");
    my_putstr("(def: left arrow)\n");
    my_putstr("-r --key-right={K}   Move the tetrimino RIGHT using the K key");
    my_putstr(" (def: right arrow)\n");
    my_putstr("-t --key-turn={K}    TURN the tetrimino clockwise 90d using t");
    my_putstr("he K key (def: top arrow)\n");
    my_putstr("-d --key-drop={K}    DROP the tetrimino using the K key (def:");
    my_putstr(" down arrow)\n");
    my_putstr("-q --key-quit={K}    QUIT the game using the K key (def: 'q' ");
    my_putstr("key)\n");
    my_putstr("-p --key-pause={K}   PAUSE/RESTART the game using the K key (");
    my_putstr("def: space bar)\n");
    my_putstr("--map-size={row,col} Set the numbers of rows and columns of t");
    my_putstr("he map (def: 20,10)\n");
    my_putstr("-w --without-next    Hide next tetrimino (def: false)\n");
    my_putstr("-D --debug           Debug mode (def: false)\n");
}

int main(int ac, char **av)
{
    var_t *var = malloc(sizeof(var_t));

    srand(time(NULL));
    var = init_struct(var);
    for (int i = 1; i != ac; i++) {
        if (my_strcmp(av[i], "--help") == 0) {
            print_h();
            free_all(var);
            return 0;
        }
    }
    var = arg_pars(var, ac, av);
    for (int i = 1; i != ac; i++) {
        if (my_strcmp(av[i], "-D") == 0 || my_strcmp(av[i], "--debug") == 0) {
            return launch_debug(var);
        }
    }
    return launch_game(var);
}
