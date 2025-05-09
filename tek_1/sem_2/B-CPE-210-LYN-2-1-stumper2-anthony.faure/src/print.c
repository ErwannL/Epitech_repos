/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper2-anthony.faure
** File description:
** print
*/

#include "../include/my.h"

int print_tie(var_t *vars, char *str)
{
    free(str);
    print_map(vars);
    my_putstr("It's a tie, nobody wins\n", 1);
    return 1;
}

int print_vic(var_t *vars, char *str)
{
    free(str);
    print_map(vars);
    if (vars->player == 2) {
        my_putstr("Congrats, player ", 1);
        my_putchar(vars->p1, 1);
        my_putstr(" won !\n", 1);
    }
    if (vars->player == 1) {
        my_putstr("Congrats, player ", 1);
        my_putchar(vars->p2, 1);
        my_putstr(" won !\n", 1);
    }
    return 1;
}

void print_ask(var_t *vars)
{
    if (vars->player == 1) {
        my_putstr("Player ", 1);
        my_putchar(vars->p1, 1);
        my_putstr(", where do you want to play: ", 1);
    }
    if (vars->player == 2) {
        my_putstr("Player ", 1);
        my_putchar(vars->p2, 1);
        my_putstr(", where do you want to play: ", 1);
    }
    return;
}
