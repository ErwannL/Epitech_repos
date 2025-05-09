/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** e_flag
*/

#include "my.h"

char *print_sto_e(char *str)
{
    int c = 0;

    str = my_revstr(str);
    while (str[0] != '\"')
        str++;
    str = my_revstr(str);
    while (strncmp(str, "stoichiometry=\"", 15) != 0)
        str++;
    for (int j = 0; j != 15; j++, str++);
    for (int i = 0; str[i] != '\"'; i++, c++);
    return strndup(str, c);
}

char *print_species_e(char *str)
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

int print_reactants_e(var_t *var, char *id)
{
    for (int i = 0; i != var->i_flag_struct->rea_int; i++)
        if (strcmp(var->i_flag_struct->tmp[i], "listOfReactants>") != 0)
            var->i_flag_struct->tmp[i]
            = strcat(strcat(print_sto_e(var->i_flag_struct->tmp[i]), " ")
            , print_species_e(var->i_flag_struct->tmp[i]));
    for (int i = 0; i != var->i_flag_struct->pro_int; i++)
        if (strcmp(var->i_flag_struct->result[i], "listOfProducts>") != 0)
            var->i_flag_struct->result[i]
            = strcat(strcat(print_sto_e(var->i_flag_struct->result[i]), " ")
            , print_species_e(var->i_flag_struct->result[i]));
    if (var->i_flag_struct->rea_int == 0 && var->i_flag_struct->pro_int == 0) {
        else_i_flag(var);
        return 84;
    }
    var->i_flag_struct->tmp = sort_array(var->i_flag_struct->tmp
    , var->i_flag_struct->rea_int);
    return 0;
}

void display_product_e(var_t *var)
{
    for (int i = 0, c = 0; i != var->i_flag_struct->pro_int; i++) {
        if (strcmp(var->i_flag_struct->result[i], "listOfProducts>") != 0) {
            (i != 0) ? printf(" ") : 0;
            (c != 0) ? printf("+ ") : 0;
            printf("%s", var->i_flag_struct->result[i]);
            c++;
        }
    }
}

void display_e_flag(var_t *var, char *id)
{
    int on = 0;
    int react = 0;
    int produ = 0;

    start_react_e(var, (int[3]){on, react, produ}, id);
    if (print_reactants_e(var, id) == 84)
        return;
    for (int i = 0, c = 0; i != var->i_flag_struct->rea_int; i++) {
        if (strcmp(var->i_flag_struct->tmp[i], "listOfReactants>") != 0) {
            (i != 0) ? printf(" ") : 0;
            (c != 0) ? printf("+ ") : 0;
            printf("%s", var->i_flag_struct->tmp[i]);
            c++;
        }
    }
    var->i_flag_struct->result = sort_array(var->i_flag_struct->result
    , var->i_flag_struct->pro_int);
    (var->i_flag_struct->reverse != 1) ? printf(" -> ") : printf(" <-> ");
    display_product_e(var);
    printf("\n");
}
