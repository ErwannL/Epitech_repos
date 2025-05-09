/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04pm-erwann.laplante
** File description:
** add_back
*/

#include "int_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_node_t *node = malloc(sizeof(int_node_t));
    int_node_t *tmp = (*front_ptr);

    node->value = elem;
    node->next = NULL;
    if (int_list_is_empty(*front_ptr) == true) {
        (*front_ptr) = node;
        return false;
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = node;
    return true;
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    node_t *node = malloc(sizeof(node_t));
    node_t *tmp = (*front_ptr);

    node->value = elem;
    node->next = NULL;
    if (list_is_empty(*front_ptr) == true) {
        (*front_ptr) = node;
        return false;
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = node;
    return true;
}
