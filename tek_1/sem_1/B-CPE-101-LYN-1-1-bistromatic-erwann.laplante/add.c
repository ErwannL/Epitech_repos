/*
** EPITECH PROJECT, 2021
** B-CPE-101-LYN-1-1-bistromatic-erwann.laplante
** File description:
** add
*/

#include "include/my.h"
#include <stdlib.h>

add_t add5(add_t var)
{
    if (var.str[var.len1 - var.i] + var.str2[var.len2 - var.i] + var.nb - 48 \
    > '9') {
        var.new_str[var.i - 1] = var.str[var.len1 - var.i] + \
        var.str2[var.len2 - var.i] + var.nb - 10 - 48;
        var.nb = 1;
    } else {
        var.new_str[var.i - 1] = var.str[var.len1 - var.i] + \
        var.str2[var.len2 - var.i] - 48 + var.nb;
        var.nb = 0;
    }
    return (var);
}

add_t add4(add_t var)
{
    if (var.str[var.len1 - var.i] + var.nb > '9') {
        var.new_str[var.i - 1] = var.str[var.len1 - var.i] + var.nb - 10;
        var.nb = 1;
    } else {
        var.new_str[var.i - 1] = var.str[var.len1 - var.i] + var.nb;
        var.nb = 0;
    }
    return (var);
}

add_t add3(add_t var)
{
    if (var.str2[var.len2 - var.i] + var.nb > '9') {
        var.new_str[var.i - 1] = var.str2[var.len2 - var.i] + var.nb - 10;
        var.nb = 1;
    } else {
        var.new_str[var.i - 1] = var.str2[var.len2 - var.i] + var.nb;
        var.nb = 0;
    }
    return (var);
}

char *add2(add_t var)
{
    ((var.len1 > var.len2) ? (var.len = var.len1) : (var.len = var.len2));
    while (var.i <= var.len) {
        if (var.len1 - var.i < 0)
            var = add3(var);
        else if (var.len2 - var.i < 0)
            var = add4(var);
        else
            var = add5(var);
        var.i++;
    }
    if (var.nb == 1)
        var.new_str[var.i - 1] = '1';
    var.new_str = my_rev_str(var.new_str);
    return (var.new_str);
}

char *add(char *str, char *str2)
{
    add_t var;

    var.len1 = my_strlen(str);
    var.len2 = my_strlen(str2);
    var.len = 0;
    var.new_str = malloc(sizeof(char) * (var.len1 + var.len2));
    var.i = 1;
    var.nb = 0;
    var.str = my_strdup(str);
    var.str2 = my_strdup(str2);
    return (add2(var));
}
