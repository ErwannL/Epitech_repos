/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** main
*/

#include "my.h"

char *add_str(char *str, int base)
{
    int len = strlen(str);
    char *res = malloc(sizeof(char) * (len + 2));
    int ret = 0;

    for (int i = len, num = 0; i != -1; res[i + 1] = (char)num, i--) {
        num = (int)str[i] + (int)my_revstr(str)[i] - '0' + ret;
        ret = 0;
        (num > '0' + base - 1) ? num -= base, ret = 1 : 0;
    }
    if (ret == 1) {
        res[0] = '1';
        res[len + 1] = '\0';
    } else {
        for (int j = 1; j != len + 1; j++)
            res[j - 1] = res[j];
        res[len] = '\0';
    }
    free(str);
    return res;
}

void n_fonction(int number, int base, int min, int max)
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
        printf("%i leads to %i in %i iteration(s) in base %i\n", number
        , convert_to_deci(str_num, base), i, base);
    } else
        printf("no solution\n");
    free(str_num);
    free(rev);
}

void p_fonction(int number, int base, int min, int max)
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
        if (my_strcmp_free(str_num, 0, convert_from_deci(base, number)
        , 1) == 0) {
            printf("%i leads to %i in %i iteration(s) in base %i\n", j, number
            , i, base);
            solution = 1;
        }
    }
    free(str_num);
    (solution == 0) ? printf("no solution\n") : 0;
}

int flag_function(var_t *var)
{
    if (var->i_max < var->i_min || (var->p_flag != 0 && var->n_flag != 0)
    || (var->p_flag == 0 && var->n_flag == 0) || (var->p_flag != 0
    && my_strcmp_free(convert_from_deci(var->base, var->palindrome), 1
    , my_revstr(convert_from_deci(var->base, var->palindrome)), 1) != 0)) {
        dprintf(2, "invalid argument\n");
        return 84;
    } else if (var->p_flag != 0) {
        p_fonction(var->palindrome, var->base, var->i_min, var->i_max);
    } else {
        n_fonction(var->number, var->base, var->i_min, var->i_max);
    }
    return 0;
}

int main(int ac, char **av)
{
    var_t *var = init_struct();
    int r = 0;

    for (int i = 0; i != ac; i++)
        if (strcmp(av[i], "-h") == 0)
            return print_h(var);
    if (ac < 3 || ac > 9) {
        free(var);
        return 84;
    }
    for (int i = 1; i != ac; i++) {
        var = arg_parsing(var, av, i);
        if (var->r_val == 84) {
            free(var);
            return 84;
        }
    }
    r = flag_function(var);
    free(var);
    return r;
}
