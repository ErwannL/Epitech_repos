/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** no_flag
*/

#include "my.h"

char *get_word(char *str)
{
    char *dest;
    int lenght = 0;
    int quote = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 34)
            quote = quote == 1 ? 0 : 1;
        if (str[i] != 34 && (quote == 0 && str[i] != '=' && (str[i] < '0'
        || (str[i] > '9' && str[i] < 'A') || (str[i] > 'Z' && str[i] < 'a')
        || str[i] > 'z'))) {
            break;
        }
        lenght++;
    }
    dest = malloc(sizeof(char) * (lenght));
    dest = strncpy(dest, str, lenght);
    return dest;
}

var_t *get_letters(var_t *var, int i, int j)
{
    if (var->no_flag_struct->word == 0)
        printf("%c", var->elements[i][j]);
    else {
        var->no_flag_struct->tmp[var->no_flag_struct->what]
        = var->elements[i][j];
        var->no_flag_struct->what++;
    }
    return var;
}

var_t *get_sentence(var_t *var, int i, int j)
{
    if (var->elements[i][j] == 34)
        var->no_flag_struct->can = var->no_flag_struct->can == 0
        ? 1 : 0;
    if (var->elements[i][j] == '=')
        var->no_flag_struct->end = 1;
    if (var->elements[i][j] == ' '
    && var->no_flag_struct->can == 0) {
        var->no_flag_struct->word++;
        var->no_flag_struct->what = 0;
        var->no_flag_struct->out[var->no_flag_struct->where]
        = strdup(var->no_flag_struct->tmp);
        var->no_flag_struct->where++;
        free(var->no_flag_struct->tmp);
        var->no_flag_struct->tmp = malloc(sizeof(char)
        * (strlen(var->elements[i])));
        var->no_flag_struct->end = 0;
    } else if (var->no_flag_struct->end == 0)
        var = get_letters(var, i, j);
    return var;
}

var_t *find_word(var_t *var, int i)
{
    var->no_flag_struct->prev_word[var->no_flag_struct->index]
    = get_word(var->elements[i]);
    var->no_flag_struct->index++;
    for (int j = 0; var->elements[i][j] != '\0'; j++)
        var = get_sentence(var, i, j);
    var->no_flag_struct->out[var->no_flag_struct->where]
    = strdup(var->no_flag_struct->tmp);
    var->no_flag_struct->where++;
    free(var->no_flag_struct->tmp);
    var->no_flag_struct->out = sort_array(var->no_flag_struct->out
    , var->no_flag_struct->where);
    for (int i = 1; i != var->no_flag_struct->where; i++)
        if (var->no_flag_struct->out[i] != NULL)
            printf("\n--->%s", var->no_flag_struct->out[i]);
    var->no_flag_struct->where = 0;
    var->no_flag_struct->what = 0;
    printf("\n");
    var->no_flag_struct->word = 0;
    var->no_flag_struct->can = 0;
    return var;
}

void display_no_flag(var_t *var)
{
    var->no_flag_struct->word = 0;
    var->no_flag_struct->can = 0;
    var->no_flag_struct->end = 0;
    var->no_flag_struct->prev_word = malloc(sizeof(char *) * (var->elem + 1));
    var->no_flag_struct->index = 0;
    var->no_flag_struct->min_id = 0;
    var->no_flag_struct->where = 0;
    var->no_flag_struct->out = malloc(sizeof(char *) * (var->elem + 1));
    var->no_flag_struct->lenght = 0;
    var->no_flag_struct->what = 0;
    var->elements = sort_array(var->elements, var->elem);
    for (int i = 0; i != var->elem; i++) {
        var->no_flag_struct->tmp = malloc(sizeof(char)
        * (strlen(var->elements[i])));
        if (i == 0 || (i != 0 && already_meet(var->no_flag_struct->prev_word
        , get_word(var->elements[i]), var->no_flag_struct->index) == 0)) {
            var = find_word(var, i);
            var->no_flag_struct->end = 0;
        }
    }
}
