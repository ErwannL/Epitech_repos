/*
** EPITECH PROJECT, 2021
** oscar
** File description:
** sous
*/

#include <stdlib.h>
#include"include/my.h"

char *following_minus(char *new_str, int bit)
{
    int i = 0;
    char *real_str = malloc(sizeof(char) * my_strlen(new_str));

    new_str = my_rev_str(new_str);
    if (new_str[i] == '0' && new_str[i + 1] != '\0') {
        while (new_str[i] == '0' && new_str[i + 1] != '\0')
            new_str++;
    }
    if (bit == 1) {
        real_str[0] = '-';
        i = 0;
        while (new_str[i] != '\0') {
            real_str[i + 1] = new_str[i];
            i++;
        }
        return (real_str);
    }
    return (new_str);
}

sous_t minus4(sous_t var)
{
    if (var.str[var.len - var.i] - var.str2[var.len2 - var.i] - var.nb + 48 \
    < '0') {
        var.new_str[var.i - 1] = var.str[var.len - var.i] - var.str2[var.len2 \
        - var.i] - var.nb + 10 + 48;
        var.nb = 1;
    } else {
        var.new_str[var.i - 1] = var.str[var.len - var.i] - var.str2[var.len2 \
        - var.i] + 48 - var.nb;
        var.nb = 0;
    }
    return var;
}

sous_t minus3(sous_t var)
{
    if (var.str[var.len - var.i] - var.nb < '0') {
        var.new_str[var.i - 1] = var.str[var.len - var.i] - var.nb + 10;
        var.nb = 1;
    } else {
        var.new_str[var.i - 1] = var.str[var.len - var.i] - var.nb;
        var.nb = 0;
    }
    return var;
}

char *minus2(sous_t var)
{
    if ((var.len == var.len2 && var.len2 != var.len1) || (var.len1 == \
    var.len2 && my_strcmp(var.str, var.str2) < 0)) {
        var.temp = my_strdup(var.str2);
        var.str2 = my_strdup(var.str);
        var.str = my_strdup(var.temp);
        var.len2 = var.len1;
        var.bit = 1;
    }
    while (var.i <= var.len) {
        if (var.len2 - var.i < 0)
            var = minus3(var);
        else
            var = minus4(var);
        var.i++;
    }
    return (following_minus(var.new_str, var.bit));
}

char *minus(char *str, char *str2)
{
    sous_t var;

    var.str = sous2(my_strdup(str));
    var.str2 = sous2(my_strdup(str2));
    var.real_str = malloc(sizeof(char) * my_strlen(var.str) * \
    my_strlen(var.str2));
    var.len1 = 0;
    var.len2 = 0;
    var.len = 0;
    var.bit = 0;
    var.new_str = malloc(sizeof(char) * my_strlen(var.str) * \
    my_strlen(var.str2));
    var.i = 1;
    var.nbr = 0;
    var.nb = 0;
    var.len2 = my_strlen(var.str2);
    var.len1 = my_strlen(var.str);
    (var.len1 > var.len2) ? (var.len = var.len1) : (var.len = var.len2);
    return (minus2(var));
}
