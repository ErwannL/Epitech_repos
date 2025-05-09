/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-erwann.laplante
** File description:
** main
*/

#include "../include/my.h"

void set_param(void)
{
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
}

int my_sokoban(int argc, char **argv)
{
    var_t *var = malloc(sizeof(var_t));

    var = init_struct(var, argv);
    if (error(var->buf_map) == 1) {
        my_putstr("Error in the map\n");
        free_all(var);
        return 84;
    }
    var->save_map = malloc(sizeof(var->map));
    my_str_to_word_array(var->buf_map, var);
    var = cpy_word_array(var);
    initscr();
    print_map(var->map, var);
    set_param();
    var = move_player(var);
    var = restart(argc, argv, var);
    endwin();
    free_all(var);
    return var->r_val;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        my_putstr("error, need 2 argument.\ntry -h!\n");
        return 84;
    } else if (my_strcmp(argv[1], "-h") == 0) {
        print_h();
        return 84;
    } else {
        return (my_sokoban(argc, argv));
    }
    return 0;
}
