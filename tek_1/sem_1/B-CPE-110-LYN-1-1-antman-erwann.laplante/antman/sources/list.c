/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** list
*/

#include "../include/my.h"

void add_after(dlist_t *li, char new_sym)
{
    dlist_node_t *new = malloc(sizeof(dlist_node_t));

    if (new != NULL) {
        new->symbol = new_sym;
        new->nbr = 1;
        new->next = li->start;
        li->start = new;
    }
}

void browse_list_add_next(dlist_t *li, char symb, dlist_node_t *it)
{
    int ident;

    for (ident = 0; it != NULL; it = it->next) {
        if (it->symbol == symb)
            ident = 1;
    }
    if (ident == 1) {
        it = li->start;
        while (it->symbol != symb) {
            it = it->next;
        }
        it->nbr++;
    } else
        add_after(li, symb);
}

void browse_list_add(dlist_t *li, char symb)
{
    dlist_node_t *it = li->start;

    if (li->start == NULL)
        add_after(li, symb);
    else
        browse_list_add_next(li, symb, it);
}

void browse(dlist_t *li)
{
    dlist_node_t *it;
    char *str;

    for (it = li->start; it->next != NULL; it = it->next) {
        str = my_strcat(str, &it->symbol);
        str = my_strcat(str, "=");
        str = my_strcat(str, int_to_str(it->nbr));
        str = my_strcat(str, " ");
    }
    my_putstr(str);
    my_putchar('\n');
    binary_tree(str);
}

void sorting_list(dlist_t *li, dlist_t *sorted_list, variable_t var)
{
    dlist_node_t *it;
    dlist_node_t *it_2;
    int max;
    int max_prev = 2147483647;

    for (int i = 0; i < 4; i++) {
        for (max = 0, it = li->start; it != NULL; it = it->next)
            (it->nbr > max && it->nbr < max_prev) ? max = it->nbr : 0;
        max_prev = max;
        if (max > 1)
            if_sorting_list(var, max, it, it_2);
        else if (max == 1)
            else_sorting_list(var, it);
    }
}
