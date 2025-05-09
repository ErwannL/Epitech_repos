/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** chained_list
*/

#include "my.h"

void chained_complete(var_t *var, char *str)
{
    chained_t *new = malloc(sizeof(chained_t));

    new->name = malloc(sizeof(char) * (strlen(str) + 1));
    new->name = strcpy(new->name, str);
    new->next = var->bad_chained;
    var->bad_chained = new;
}

int cond_reverse(char c)
{
    if (c != '=' && (c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a')
    || c > 'z'))
        return 84;
    return 0;
}

void reverse_chained(var_t *var)
{
    chained_t *new = malloc(sizeof(chained_t));
    int good = 0;

    new->name = malloc(sizeof(char) * (strlen(var->bad_chained->name) + 1));
    new->name = strcpy(new->name, var->bad_chained->name);
    for (; new->name[0] && cond_reverse(new->name[0]) == 84
    && new->name[0] != '<'; new->name++);
    new->name[0] && cond_reverse(new->name[0]) == 84 ? new->name++ : 0;
    new->name = my_revstr(new->name);
    for (; new->name[0] && cond_reverse(new->name[0]) == 84
    && new->name[0] != '<'; new->name++);
    new->name[0] && cond_reverse(new->name[0]) == 84 ? new->name++ : 0;
    new->name = my_revstr(new->name);
    for (int i = 0; new->name[i] != '\0'; i++)
        (new->name[i] == ' ') ? good = 1 : 0;
    if (new->name[0] > 'a' && new->name[0] < 'z' && good == 1) {
        new->next = var->good_chained;
        var->good_chained = new;
    }
}

void reverse_chained_bis(var_t *var)
{
    chained_t *new = malloc(sizeof(chained_t));

    new->name = malloc(sizeof(char) * (strlen(var->bad_chained->name) + 1));
    new->name = strcpy(new->name, var->bad_chained->name);
    while (new->name[0] == ' ')
        new->name++;
    new->next = var->good_chained;
    var->good_chained = new;
}
