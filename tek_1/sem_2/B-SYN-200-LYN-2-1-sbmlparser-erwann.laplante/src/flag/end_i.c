/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** end_i
*/

#include "my.h"

void else_i_flag(var_t *var)
{
    for (int i = 0; i != var->elem; i++) {
        if (strcmp(get_word(var->elements[i]), "species") == 0) {
            var->elements[i] = destroy_str(var->elements[i], "name=\"", 6);
            var->i_flag_struct->result[var->i_flag_struct->res++]
            = get_word(var->elements[i]);
        }
    }
    var->i_flag_struct->result = sort_array(var->i_flag_struct->result
    , var->i_flag_struct->res);
    printf("List of species\n");
    for (int i = 0; i != var->i_flag_struct->res; i++) {
        for (int j = 0; j != strlen("name=\""); j++
        , var->i_flag_struct->result[i]++);
        var->i_flag_struct->result[i]
        = my_revstr(var->i_flag_struct->result[i]);
        var->i_flag_struct->result[i]++;
        var->i_flag_struct->result[i]
        = my_revstr(var->i_flag_struct->result[i]);
        printf("-->%s\n", var->i_flag_struct->result[i]);
    }
}

var_t *new_id(var_t *var, int i)
{
    while (var->elements[i] && strncmp(var->elements[i]
    , "reversible=\"", 11) != 0) {
        var->elements[i]++;
    }
    for (int j = 0; j != 11; j++, var->elements[i]++);
    if (strcmp(get_word(var->elements[i]), "\"true\"") == 0)
        var->i_flag_struct->reverse = 1;
    return var;
}

var_t *get_id(var_t *var, int i, char *id)
{
    var->i_flag_struct->lenght = strlen(var->i_flag_struct->tmp[i]);
    for (int j = 0; j != var->i_flag_struct->lenght; j++
    , var->i_flag_struct->tmp[i]++) {
        if (var->i_flag_struct->word != NULL)
            break;
        (var->i_flag_struct->tmp[i][0] == '=')
        ? var->i_flag_struct->before = 3 : (var->i_flag_struct->before > 0)
        ? var->i_flag_struct->before-- : 0;
        if (strncmp(var->i_flag_struct->tmp[i], id, strlen(id)) == 0
        && var->i_flag_struct->before == 1
        && var->i_flag_struct->word == NULL) {
            var->i_flag_struct->word = strdup(get_word(var->elements[i]));
            var = new_id(var, i);
            var->i_flag_struct->where = i;
        }
    }
    return var;
}

var_t *get_species(var_t *var, int i, int a)
{
    while (strncmp(var->i_flag_struct->tmp[i], "stoichiometry", 13) != 0)
        var->i_flag_struct->tmp[i]++;
    for (int j = 0; j != 15; j++, var->i_flag_struct->tmp[i]++);
    for (int j = 0; var->i_flag_struct->tmp[i][j] >= '0'
    && var->i_flag_struct->tmp[i][j] <= '9'; j++, var->i_flag_struct->len++);
    var->i_flag_struct->nbr = strndup(var->i_flag_struct->tmp[i]
    , var->i_flag_struct->len);
    var->i_flag_struct->nbr = my_revstr(var->i_flag_struct->nbr);
    for (int k = 0; k != a; k++, var->i_flag_struct->nbr++);
    return var;
}
