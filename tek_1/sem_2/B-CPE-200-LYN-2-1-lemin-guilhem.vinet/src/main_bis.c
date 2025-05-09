/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** main_bis
*/

#include "lemin.h"

int get_len_path(char *path)
{
    int c = 0;

    for (int i = 0; path[i]; i++) {
        if (path[i] == ' ')
            c++;
    }
    return c;
}

int fin_mini_path(int *path, int max)
{
    int min = -1;
    int min_pos = -1;

    for (int i = 0; i != max; i++) {
        if (min == -1 || min > path[i]) {
            min = path[i];
            min_pos = i;
        }
    }
    return min_pos;
}

int all_finish(ants_t *ant, int nbr)
{
    for (int i = 0; i != nbr; i++) {
        if (ant[i].finish == 0) {
            return 84;
        }
    }
    return 0;
}

void print_info_ant(int max, ants_t *all_ants, int space, ants_t ants)
{
    if (max != 0 && all_ants[max - 1].print == 1 && space == 0)
        my_putstr(" ");
    my_putstr("P");
    my_putstr(clean_string(my_int_to_str(max)));
    my_putstr("-");
    my_putstr(clean_string(ants.where));
}

ants_t get_next_ant(ants_t ants, ants_t *all_ants, int max, int space)
{
    char *node;
    int i = 0;
    int test = 0;

    for (; ants.path[i] != '\0' && ants.path[i] != ' '; i++);
    node = malloc(sizeof(char) * (++i));
    for (int j = 0; j != i; j++)
        node[j] = ants.path[j];
    for (int j = 0; j != max; j++) {
        if (all_ants[j].finish == 0
        && my_strcmp(node, all_ants[j].where) == 0)
            test = 1;
    }
    if (test == 0) {
        ants.print = 1;
        for (int j = 0; j != my_strlen(node); ants.path++, j++);
        ants.where = node;
        print_info_ant(max, all_ants, space, ants);
    }
    return ants;
}
