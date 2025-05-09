/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** fill_elemnts_i
*/

#include "my.h"

int comp_elements(var_t *var, int i)
{
    if (strncmp(var->i_flag_struct->tmp[i]
    , var->i_flag_struct->all, strlen(var->i_flag_struct->all)) == 0) {
        var->i_flag_struct->word = strdup(get_word(var->elements[i]));
        var = fill_elements_next(var, i);
        if (var->i_flag_struct->word[0] != '\"')
            return 84;
        var->i_flag_struct->word++;
        var->i_flag_struct->word = my_revstr(var->i_flag_struct->word);
        var->i_flag_struct->result[var->i_flag_struct->res]
        = strdup(var->i_flag_struct->word);
        var->i_flag_struct->res++;
    }
    return 0;
}

var_t *fill_elements_next(var_t *var, int i)
{
    for (int k = 0; k != strlen(var->i_flag_struct->word); k++
    , var->elements[i]++);
    var->elements[i]++;
    var->i_flag_struct->word = strdup(get_word(var->elements[i]));
    for (int k = 0; k != strlen(var->i_flag_struct->word); k++
    , var->elements[i]++);
    var->elements[i]++;
    var->i_flag_struct->word = strdup(get_word(var->elements[i]));
    for (int k = 0; k != 6; k++, var->i_flag_struct->word++);
    var->i_flag_struct->word = my_revstr(var->i_flag_struct->word);
    return var;
}

var_t *fill_elements(var_t *var, int i)
{
    var->i_flag_struct->lenght = strlen(var->i_flag_struct->tmp[i]);
    for (int j = 0; j != var->i_flag_struct->lenght; j++
    , var->i_flag_struct->tmp[i]++) {
        if (comp_elements(var, i) == 84)
            break;
    }
    return var;
}

int find_spieces(var_t *var, int i, int a)
{
    var->i_flag_struct->result[0] != NULL ? printf("\n--->%s (%s)"
    , var->i_flag_struct->result[0], var->i_flag_struct->nbr)
    , var->i_flag_struct->result[0] = NULL : 0;
    if (var->i_flag_struct->mode == 0) {
        var->i_flag_struct->tmp[i] = my_revstr(var->i_flag_struct->tmp[i]);
        if (strcmp(var->i_flag_struct->all
        , get_word(var->i_flag_struct->tmp[i])) == 0) {
            var->i_flag_struct->mode++;
            my_revstr(var->i_flag_struct->tmp[i]);
            var = get_species(var, i, a);
            a++;
            var->i_flag_struct->nbr = my_revstr(var->i_flag_struct->nbr);
        }
        var->i_flag_struct->tmp[i] = my_revstr(var->i_flag_struct->tmp[i]);
    }
    return a;
}

int species_function(var_t *var, int i, int a)
{
    a = find_spieces(var, i, a);
    if (var->i_flag_struct->mode == 1) {
        if (strcmp(get_word(var->i_flag_struct->tmp[i]), "reaction") == 0)
            var->i_flag_struct->mode++;
    }
    if (var->i_flag_struct->mode == 2) {
        var->i_flag_struct->result[var->i_flag_struct->res]
        = strdup(get_word(my_revstr(var->i_flag_struct->tmp[i])));
        var->i_flag_struct->result[var->i_flag_struct->res]++;
        var->i_flag_struct->result[var->i_flag_struct->res]
        = my_revstr(var->i_flag_struct->result[0]);
        for (int j = 0; j != 4; j++, var->i_flag_struct->result[0]++);
        var->i_flag_struct->res = 0;
        var->i_flag_struct->mode = 0;
    }
    return a;
}
