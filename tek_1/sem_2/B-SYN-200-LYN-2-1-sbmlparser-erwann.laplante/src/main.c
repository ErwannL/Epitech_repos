/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** main
*/

#include "my.h"

int print_h(void)
{
    printf("USAGE\n");
    printf("    ./SBMLparser SBMLfile [-i ID [-e]] [-json]\n");
    printf("DESCRIPTION\n");
    printf("    SBMLfile SBML file\n");
    printf("    -i ID id of the compartment, reaction or product to be extra");
    printf("cted\n    (ignored if uncorrect)\n");
    printf("    -e print the equation if a reaction ID is given as argument");
    printf("\n    (ignored otherwise)\n");
    printf("    -json transform the file into a JSON file\n");
    return 0;
}

int parsing(var_t *var, char **av)
{
    while (var->bad_chained->name != NULL) {
        reverse_chained(var);
        var->bad_chained = var->bad_chained->next;
    }
    while (var->good_chained->name != NULL) {
        var->elements[var->elem++] = var->good_chained->name;
        var->elements = realloc(var->elements
        , sizeof(char *) * (var->elem + 1));
        var->good_chained = var->good_chained->next;
    }
    var->elements[var->elem] = NULL;
    if ((var->flag->e_flag == 0 && var->flag->i_flag == 0
    && var->flag->json_flag == 0) || var->r_val == 84)
        display_no_flag(var);
    if ((var->flag->e_flag == 0 && var->flag->i_flag == 1
    && var->flag->json_flag == 0) || (var->flag->e_flag == 1
    && var->flag->i_flag == 1 && var->flag->json_flag == 0)) {
        display_i_flag(var, av[3], var->flag->e_flag);
    }
    return free_all(0, var);
}

int main(int ac, char **av)
{
    var_t *var;

    for (int i = 0; i != ac; i++) {
        if (strcmp(av[i], "-h") == 0)
            return print_h();
    }
    if (ac == 1 || ac > 6)
        return 84;
    var = init_struct(var, ac, av);
    if ((var->flag->e_flag == 1 && var->flag->i_flag == 0)
    || var->flag->e_flag > 1 || var->flag->i_flag > 1
    || var->flag->json_flag > 1)
        return free_all(84, var);
    if (get_file_info(var, av) == 84)
        return 84;
    var->array = my_str_to_word_array(var->buf);
    for (int i = 0; var->array[i] != NULL; i++)
        chained_complete(var, var->array[i]);
    return parsing(var, av);
}
