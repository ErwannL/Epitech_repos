/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** bistro3
*/

#include"include/my.h"
#include <unistd.h>
#include <stdlib.h>

int my_char_in_base(var_t var, char c)
{
    for (int i = 0; var.base[i] != '\0';i++) {
        if (var.base[i] == c)
            return (0);
    }
    return (1);
}

int my_str_only_base(var_t var)
{
    int temp = 0;

    for (int i = 1; i != my_strlen(var.new_str) - 1; i++) {
        temp = my_char_in_base(var, var.new_str[i]);
        if (temp == 1) {
            return (1);
        }
    }
    return (0);
}

var_t parenthis2(var_t var)
{
    char *temp = "0";
    int a;

    while (var.nbr_p != 0 && var.calcul[var.i] != '\0') {
        ((var.calcul[var.i] == var.operators[0]) ? (var.nbr_p++) : 0);
        ((var.calcul[var.i] == var.operators[1]) ? (var.nbr_p--) : 0);
        var.str_calc[var.k++] = var.calcul[var.i++];
    }
    if (var.nbr_p != 0) {
        var.val_return = 84;
        return (var);
    }
    var.i--;
    var.nbr_p = 0;
    var.str_calc[my_strlen(var.str_calc) - 1] = '\0';
    for (var.l = 0; temp[var.l] != '\0'; var.l++, var.tempo++, var.j++)
        var.new_str[var.j] = temp[var.l];
    return (var);
}

var_t parenthis(var_t var)
{
    char *temp = "0";

    var.nbr_p++;
    var.i++;
    var = parenthis2(var);
    if (var.val_return == 84)
        return (var);
    var.j = var.j - var.tempo + (my_strlen(temp) - 1);
    var.tempo = 0;
    free (var.str_calc);
    var.k = 0;
    var.val = 1;
    var.val_return = 0;
    return (var);
}

int my_char_in_op(var_t var, char c, int d)
{
    for (; var.operators[d] != '\0';d++) {
        if (var.operators[d] == c)
            return (0);
    }
    return (1);
}
