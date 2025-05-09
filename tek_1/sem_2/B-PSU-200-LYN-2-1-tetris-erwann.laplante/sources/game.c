/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** game
*/

#include "../include/my.h"

void init_all(void)
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
}

int init_game(var_t *var)
{
    if (init_chained(var) == 84)
        return 84;
    var->cursor = var->tetri;
    var->n = rand() % (var->nbr_node - 1);
    for (; var->n >= var->nbr_node; var->n = rand() % (var->nbr_node - 1));
    for (int i = 0; i != var->n; var->cursor = var->cursor->next, i++);
    var->next_cursor = var->tetri;
    var->next_n = rand() % (var->nbr_node - 1);
    for (; var->next_n >= var->nbr_node;)
        var->next_n = rand() % (var->nbr_node - 1);
    for (int i = 0; i != var->next_n; i++)
        var->next_cursor = var->next_cursor->next;
    init_all();
    var = init_map(var);
    var->ch = 0;
    return 0;
}

void print_info(var_t *var)
{
    var = place_piece(var, 0);
    if (var->arg->without_next == FALSE) {
        printw("next = \n");
        print_info_for(var);
    }
    printw("speed = %i\n", (var->speed - 10) * -1);
    printw("level = %i\n", var->destroy_line);
    var->stat == PAUSE ? printw("game in pause\n") : 0;
    halfdelay(var->speed);
    var->ch = getch();
}

void launch_game_condition(var_t *var)
{
    var = put_piece(var, var->cursor, var->a, var->b);
    var->full = full_line(var);
    while (var->full != -1)
        var = del_full_line(var);
    var = new_piece(var);
}

int launch_game(var_t *var)
{
    if (init_game(var) == 84) {
        free_all(var);
        return 84;
    }
    var = place_piece(var, 0);
    while (check_loose(var) == 0) {
        print_info(var);
        var = handle_key(var);
        if (check_down(var->map, var->cursor, var->a, var->b) == 84
        && var->stat == GAME)
            launch_game_condition(var);
    }
    endwin();
    free_all(var);
    return 0;
}
