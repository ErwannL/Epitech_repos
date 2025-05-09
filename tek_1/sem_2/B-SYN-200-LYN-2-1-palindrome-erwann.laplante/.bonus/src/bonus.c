/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-palindrome-erwann.laplante
** File description:
** bonus
*/

#include "bonus.h"

char *free_n(char *str, char *rev)
{
    free(rev);
    free(str);
    return NULL;
}

char *n_fonction_bonus(int number, int base, int min, int max)
{
    int i = 0;
    char *str_num = convert_from_deci(base, number);
    char *rev;

    for (; i != min; i++, str_num = add_str(str_num, base));
    rev = malloc(sizeof(char) * (strlen(str_num) + 1));
    rev = my_revstr(strcpy(rev, str_num));
    for (; strcmp(str_num, rev) != 0 && i != max; i++) {
        str_num = add_str(str_num, base);
        free(rev);
        rev = malloc(sizeof(char) * (strlen(str_num) + 1));
        rev = my_revstr(strcpy(rev, str_num));
    }
    if (strcmp(str_num, rev) == 0) {
        free(rev);
        return int_to_str(convert_to_deci(str_num, base));
    } else
        return free_n(str_num, rev);
}

void print_soluce(int j, int number, int i, int base)
{
    printf("First palindrome of %i is %i in %i iteration(s) in base %i\
    \n", j, number, i, base);
}

void p_fonction_bonus(int number, int base, int min, int max)
{
    int i = 0;
    char *str_num = NULL;
    int solution = 0;

    for (int j = 0; j != number + 1; j++, i = 0) {
        free(str_num);
        str_num = my_strcpy_free(str_num, convert_from_deci(base, j), 1);
        for (; i != min; i++, str_num = add_str(str_num, base));
        for (; (my_strcmp_free(str_num, 0, convert_from_deci(base, number)
        , 1) != 0) && i != max; i++)
            str_num = add_str(str_num, base);
        if ((my_strcmp_free(str_num, 0, convert_from_deci(base, number)
        , 1) == 0) && my_strcmp_free(n_fonction_bonus(j, base, min, max), 1
        , int_to_str(number), 1) == 0) {
            print_soluce(j, number, i, base);
            solution = 1;
        }
    }
    (solution == 0) ? printf("no solution\n"), free(str_num) : free(str_num);
}

void flag_function_bonus(var_t *var)
{
    if (var->fn_flag != 0)
        fn_fonction(var->fn, var->base, var->i_min, var->i_max);
    if (var->pn_flag != 0)
        p_fonction_bonus (var->pn, var->base, var->i_min, var->i_max);
    if (var->p_flag != 0)
        p_fonction(var->palindrome, var->base, var->i_min, var->i_max);
    if (var->n_flag != 0)
        n_fonction(var->number, var->base, var->i_min, var->i_max);
}
