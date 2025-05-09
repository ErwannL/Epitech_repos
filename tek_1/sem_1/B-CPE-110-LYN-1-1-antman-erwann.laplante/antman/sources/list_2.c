/*
** EPITECH PROJECT, 2022
** antman
** File description:
** list_2
*/

#include "../include/my.h"

void if_sorting_list(variable_t var, int max, dlist_node_t *it,
dlist_node_t *it_2)
{
    for (it = var.my_list->start; it != NULL; it_2 = it, it = it->next) {
        if (it->nbr == max && var.my_list->start == it) {
            var.my_list->start = it->next;
            it->next = var.sorted_list->start;
            it = var.my_list->start;
            var.sorted_list->start = it;
        } else if (it->nbr == max) {
            it_2->next = it->next;
            it->next = var.sorted_list->start;
            var.sorted_list->start = it;
            it = var.my_list->start;
        }
    }
}

void else_sorting_list(variable_t var, dlist_node_t *it)
{
    while (var.my_list->start != NULL) {
        it = var.my_list->start;
        var.my_list->start = var.my_list->start->next;
        it->next = var.sorted_list->start;
        var.sorted_list->start = it;
    }
    var.sorted_list->start = var.sorted_list->start->next;
}
