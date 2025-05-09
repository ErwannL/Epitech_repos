/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-palindrome-erwann.laplante
** File description:
** fn_flag
*/

#include "bonus.h"

int test_error_flag(var_t *var)
{
    if (var->i_max < var->i_min || (var->p_flag != 0 && var->n_flag != 0)
    || (var->pn_flag != 0 && var->n_flag != 0) || (var->p_flag != 0
    && var->pn_flag != 0) || (var->p_flag != 0 && var->fn_flag != 0)
    || (var->pn_flag != 0 && var->fn_flag != 0) || (var->n_flag != 0
    && var->fn_flag != 0) || (var->p_flag == 0 && var->n_flag == 0
    && var->pn_flag == 0 && var->fn_flag == 0) || (var->p_flag != 0
    && my_strcmp_free(convert_from_deci(var->base, var->palindrome), 1
    , my_revstr(convert_from_deci(var->base, var->palindrome)), 1) != 0)
    || (var->pn_flag != 0 && my_strcmp_free(convert_from_deci(var->base
    , var->pn), 1, my_revstr(convert_from_deci(var->base, var->pn))
    , 1) != 0))
        return 84;
    return 0;
}

void fn_fonction(int number, int base, int min, int max)
{
    for (int i = 0; i != number; i++)
        n_fonction(i, base, min, max);

}
