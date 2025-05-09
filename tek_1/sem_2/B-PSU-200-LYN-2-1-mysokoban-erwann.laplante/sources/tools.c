/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-erwann.laplante
** File description:
** tools
*/

#include "../include/my.h"

void print_h(void)
{
    my_putstr("USAGE\n    ./my_sokoban map\nDESCRIPTION\n    map file repres");
    my_putstr("enting the warehouse map, containing '#' for walls, \n       ");
    my_putstr(" 'P' for the player, 'X' for boxes and 'O' for storage locati");
    my_putstr("ons.\n");
}

int error(char *str)
{
    int number_o = 0;
    int number_x = 0;
    int number_p = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i + 1] == '\0' && str[i] != '\n') {
            str[i + 1] = '\n';
            str[i + 2] = '\0';
        }
        (str[i] == 'O') ? number_o++ : 0;
        (str[i] == 'X') ? number_x++ : 0;
        (str[i] == 'P') ? number_p++ : 0;
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '#' && str[i] != 'X'
        && str[i] != 'O' && str[i] != 'P')
            return 1;
    }
    if (number_o != number_x || number_p != 1)
        return 1;
    return 0;
}

var_t *restart(int argc, char **argv, var_t *var)
{
    if (var->ch == ' ') {
        endwin();
        free_all(var);
        clear();
        my_sokoban(argc, argv);
    }
    return var;
}
