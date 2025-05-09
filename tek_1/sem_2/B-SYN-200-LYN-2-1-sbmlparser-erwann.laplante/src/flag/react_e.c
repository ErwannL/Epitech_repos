/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** react_e
*/

#include "my.h"

var_t *get_rectants_products_e(var_t *var, char *id, int i)
{
    if (var->value.on == 1 && strcmp(var->elements[i]
    , "listOfReactants>") == 0)
        var->value.react = 1;
    if (var->value.on == 1 && strcmp(var->elements[i]
    , "/listOfReactants>") == 0)
        var->value.react = 0;
    if (var->value.on == 1 && var->value.react == 1)
        var->i_flag_struct->tmp[var->i_flag_struct->rea_int++]
        = strdup(var->elements[i]);
    if (var->value.on == 1 && strcmp(var->elements[i]
    , "listOfProducts>") == 0)
        var->value.produ = 1;
    if (var->value.on == 1 && strcmp(var->elements[i]
    , "/listOfProducts>") == 0)
        var->value.produ = 0;
    if (var->value.on == 1 && var->value.produ == 1)
        var->i_flag_struct->result[var->i_flag_struct->pro_int++]
        = strdup(var->elements[i]);
    return var;
}

void start_start_react_e(var_t *var)
{
    for (int i = 0; var->array[i] != NULL; i++)
        chained_complete(var, var->array[i]);
    while (var->bad_chained->name != NULL) {
        reverse_chained_bis(var);
        var->bad_chained = var->bad_chained->next;
    }
    while (var->good_chained->name != NULL) {
        var->elements[var->elem++] = var->good_chained->name;
        var->elements = realloc(var->elements
        , sizeof(char *) * (var->elem + 1));
        var->good_chained = var->good_chained->next;
    }
}

void start_react_e(var_t *var, int *val, char *id)
{
    start_start_react_f(var);
    for (int i = 0; i != var->elem; i++) {
        var->value.on = val[0];
        var->value.react = val[1];
        var->value.produ = val[2];
        if (strcmp(var->elements[i], "<listOfReactions>") == 0)
            var->value.on = 1;
        if (strcmp(var->elements[i], "</listOfReactions>") == 0)
            var->value.on = 0;
        (var->value.on == 1) ? var->value.on = get_reaction(var, i, id
        , var->value.on) : 0;
        var = get_rectants_products_e(var, id, i);
        val[0] = var->value.on;
        val[1] = var->value.react;
        val[2] = var->value.produ;
    }
}
