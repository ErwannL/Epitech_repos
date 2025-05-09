/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** i_flag
*/

#include "my.h"

void start_react_f(var_t *var, int *val, char *id)
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
        var = get_rectants_products(var, id, i);
        val[0] = var->value.on;
        val[1] = var->value.react;
        val[2] = var->value.produ;
    }
}

void reaction_fonction(var_t *var, char *id)
{
    int on = 0;
    int react = 0;
    int produ = 0;

    start_react_f(var, (int[3]){on, react, produ}, id);
    if (print_reactants(var, id) == 84)
        return;
    for (int i = 0; i != var->i_flag_struct->rea_int; i++)
        (strcmp(var->i_flag_struct->tmp[i], "listOfReactants>") != 0)
        ? printf("-->%s\n", var->i_flag_struct->tmp[i]) : 0;
    printf("List of products of reaction %s\n", id);
    var->i_flag_struct->result = sort_array(var->i_flag_struct->result
    , var->i_flag_struct->pro_int);
    for (int i = 0; i != var->i_flag_struct->pro_int; i++)
        (strcmp(var->i_flag_struct->result[i], "listOfProducts>") != 0)
        ? printf("-->%s\n", var->i_flag_struct->result[i]) : 0;
    return;
}

void i_flag(var_t *var, char *id, int what)
{
    if (var->i_flag_struct->yes == 0
    && strcmp(var->i_flag_struct->word, "species") == 0) {
        printf("List of reactions consuming species %s (quantities)", id);
        var->i_flag_struct->all = malloc(sizeof(char)
        * (strlen(var->i_flag_struct->word) + strlen(id) + 4));
        var->i_flag_struct->all
        = strcat(strcat(strcat(var->i_flag_struct->word, "=\""), id), "\"\0");
        var->i_flag_struct->all = my_revstr(var->i_flag_struct->all);
        for (int i = 0; i != var->elem; var->i_flag_struct->tmp[i]
        = strdup(strcat(var->elements[i], "\"")), i++);
        for (int i = var->elem - 1, a = 0; i != -1; i--)
            a = species_function(var, i, a);
        printf("\n");
    } else if (var->i_flag_struct->yes == 0
    && strcmp(var->i_flag_struct->word, "reaction") == 0)
        what == 0 ? reaction_fonction(var, id) : display_e_flag(var, id);
    else
        else_i_flag(var);
    return;
}

void print_i_flag(var_t *var, char *id, int what)
{
    if (var->i_flag_struct->yes == 0 && strcmp(var->i_flag_struct->word
    , "compartment") == 0) {
        printf("List of species in compartment %s\n", id);
        var->i_flag_struct->all = malloc(sizeof(char)
        * (strlen(var->i_flag_struct->word) + strlen(id) + 4));
        var->i_flag_struct->all
        = strcat(strcat(strcat(var->i_flag_struct->word, "=\""), id), "\"\0");
        for (int i = 0; i != var->elem; i++)
            var->i_flag_struct->tmp[i] = strdup(var->elements[i]);
        for (int i = 0; i != var->elem; i++)
            var = fill_elements(var, i);
        sort_array(var->i_flag_struct->result, var->i_flag_struct->res);
        for (int i = 0; i != var->elem; i++)
            (var->i_flag_struct->result[i] != NULL) ? printf("-->%s\n"
            , var->i_flag_struct->result[i]) : 0;
    } else
        i_flag(var, id, what);
}

void display_i_flag(var_t *var, char *id, int what)
{
    var->i_flag_struct->tmp = malloc(sizeof(char *) * (var->elem + 1));
    var->i_flag_struct->all;
    var->i_flag_struct->lenght = 0;
    var->i_flag_struct->before = 0;
    var->i_flag_struct->word = NULL;
    var->i_flag_struct->result = malloc(sizeof(char *) * (var->elem + 1));
    var->i_flag_struct->res = 0;
    var->i_flag_struct->where = 0;
    var->i_flag_struct->mode = 0;
    var->i_flag_struct->nbr;
    var->i_flag_struct->len = 0;
    var->i_flag_struct->rea_int = 0;
    var->i_flag_struct->pro_int = 0;
    var->i_flag_struct->yes = 0;
    for (int i = 0; i != var->elem; i++)
        var->i_flag_struct->tmp[i] = strdup(var->elements[i]);
    for (int i = 0; i != var->elem; i++)
        var = get_id(var, i, id);
    (!var->i_flag_struct->word) ? var->i_flag_struct->yes = 1 : 0;
    return print_i_flag(var, id, what);
}
