/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04pm-erwann.laplante
** File description:
** add_position
*/

#include "int_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

bool int_list_add_elem_at_position (int_list_t *front_ptr, int elem,
    unsigned int position)
{
    int_node_t *tmp = (*front_ptr);
    int_node_t *node = malloc(sizeof(int_node_t));

    if (int_list_is_empty(*front_ptr) == true ||
        int_list_get_size((*front_ptr)) == 0) {
        free(node);
        return false;
    }
    if (position == 0) {
        free(node);
        return int_list_add_elem_at_front(front_ptr, elem);
    }
    node->value = elem;
    node->next = NULL;
    for (; --position; tmp = tmp->next);
    node->next = tmp->next;
    tmp->next = node;
    return true;
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
    unsigned int position)
{
    node_t *tmp = (*front_ptr);
    node_t *node = malloc(sizeof(node_t));

    if (list_is_empty(*front_ptr) == true ||
        list_get_size((*front_ptr)) == 0) {
        free(node);
        return false;
    }
    if (position == 0) {
        free(node);
        return list_add_elem_at_front(front_ptr, elem);
    }
    node->value = elem;
    node->next = NULL;
    for (; --position; tmp = tmp->next);
    node->next = tmp->next;
    tmp->next = node;
    return true;
}
