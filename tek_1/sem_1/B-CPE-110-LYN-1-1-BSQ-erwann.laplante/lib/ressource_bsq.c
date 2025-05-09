/*
** EPITECH PROJECT, 2021
** CPool
** File description:
** my_get_width
*/

#include"../includes/my.h"

int my_get_width(char *str)
{
    int count = 0;

    for (; str[count] != '\n'; count++);
    return (count);
}

int alpha_num(char c)
{
    if ((c != '.') && (c != 'o'))
        return (1);
    return (0);
}

int number_of_word(char *str)
{
    int word = 0;

    for (int i = 0; str != NULL && str[i]; i++) {
        if (alpha_num(str[i]) == 0 && alpha_num(str[i + 1]) == 1)
            word++;
    }
    return (word);
}

variables_t minimmum(variables_t var, int a, int b)
{
    ((var.map[a - 1][b] <= var.map[a][b - 1] && var.map[a - 1][b] <= \
    var.map[a - 1][b - 1]) ? (var.map[a][b] = var.map[a - 1][b]) : \
    ((var.map[a][b - 1] <= var.map[a - 1][b - 1] && var.map[a][b - 1] <= \
    var.map[a - 1][b]) ? (var.map[a][b] = var.map[a][b - 1]) : (var.map[a][b] \
    = var.map[a - 1][b - 1])));
    var.map[a][b] = var.map[a][b] + 1;
    return (var);
}

void one_c_l(variables_t var)
{
    for (int i = 0; var.buf[i] != '\0'; i++) {
        if (var.buf[i] == '.') {
            var.buf[i] = 'x';
            my_putstr(var.buf);
            my_putstr("\n\0");
            exit(0);
        }
    }
    my_putstr(var.buf);
    my_putstr("\n\0");
    exit(0);
}
