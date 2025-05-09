/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-erwann.laplante
** File description:
** move_player
*/

#include "../include/my.h"

var_t *move_player_bis(var_t *var)
{
    if (var->ch == KEY_UP)
        var = move_up(var);
    else if (var->ch == KEY_DOWN)
        var = move_down(var);
    else
        print_map(var->map, var);
    return var;
}

var_t *do_check(var_t *var)
{
    if (check_win(var->save_map, var->index, var->map) == 0) {
        var->r_val = 0;
        clear();
        printw("You win to replay press space or to quit press q");
        refresh();
    }
    if (check_loose(var->save_map, var->index, var->map) == 84) {
        var->r_val = 1;
        var->ex_num = 84;
        print_map(var->map, var);
        return var;
    }
    return var;
}

var_t *move_player(var_t *var)
{
    while (var->ch != 'q' && var->ch != ' ') {
        var->ch = getch();
        if (var->ch == KEY_LEFT)
            var = move_left(var);
        else if (var->ch == KEY_RIGHT)
            var = move_right(var);
        else
            var = move_player_bis(var);
        var->map = find_o(var->save_map, var->index, var->map);
        print_map(var->map, var);
        var = do_check(var);
        if (var->ex_num == 84)
            return var;
    }
    return var;
}
