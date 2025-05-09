/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** species_i
*/

#include "my.h"

int get_reaction(var_t *var, int i, char *id, int on)
{
    var->elements[i]++;
    if (strcmp(get_word(var->elements[i]), "reaction") == 0) {
        while (strncmp(var->elements[i], "id=\"", 4) != 0)
            var->elements[i]++;
        for (int j = 0; j != 4; j++, var->elements[i]++);
        var->elements[i] = my_revstr(var->elements[i]);
        var->elements[i]++;
        var->elements[i]++;
        var->elements[i] = my_revstr(var->elements[i]);
        if (strcmp(var->elements[i], id) != 0)
            on = 0;
    }
    return on;
}

char *print_species(char *str)
{
    int c = 0;

    str = my_revstr(str);
    while (str[0] != '\"')
        str++;
    str = my_revstr(str);
    while (strncmp(str, "species=\"", 9) != 0)
        str++;
    for (int j = 0; j != 9; j++, str++);
    for (int i = 0; str[i] != '\"'; i++, c++);
    return strndup(str, c);
}

int print_reactants(var_t *var, char *id)
{
    for (int i = 0; i != var->i_flag_struct->rea_int; i++)
        if (strcmp(var->i_flag_struct->tmp[i], "listOfReactants>") != 0)
            var->i_flag_struct->tmp[i]
            = print_species(var->i_flag_struct->tmp[i]);
    for (int i = 0; i != var->i_flag_struct->pro_int; i++)
        if (strcmp(var->i_flag_struct->result[i], "listOfProducts>") != 0)
            var->i_flag_struct->result[i]
            = print_species(var->i_flag_struct->result[i]);
    if (var->i_flag_struct->rea_int == 0 && var->i_flag_struct->pro_int == 0) {
        else_i_flag(var);
        return 84;
    }
    printf("List of reactants of reaction %s\n", id);
    var->i_flag_struct->tmp = sort_array(var->i_flag_struct->tmp
    , var->i_flag_struct->rea_int);
    return 0;
}

var_t *get_rectants_products(var_t *var, char *id, int i)
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

void start_start_react_f(var_t *var)
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
