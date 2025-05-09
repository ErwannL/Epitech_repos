/*
** EPITECH PROJECT, 2022
** private_palindrome
** File description:
** struct
*/

#include "my.h"

var_t *init_struct(void)
{
    var_t *var = malloc(sizeof(var_t));

    var->n_flag = 0;
    var->number = 0;
    var->p_flag = 0;
    var->palindrome = 0;
    var->b_flag = 0;
    var->base = 10;
    var->imin_flag = 0;
    var->i_min = 0;
    var->imax_flag = 0;
    var->i_max = 100;
    var->r_val = 0;
    return var;
}
