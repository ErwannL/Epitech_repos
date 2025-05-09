/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04pm-erwann.laplante
** File description:
** add_front
*/

#include "int_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"

bool int_list_add_elem_at_front (int_list_t *front_ptr, int elem)
{
    int_node_t *node = malloc(sizeof(int_node_t));

    node->value = elem;
    node->next = (*front_ptr);
    if (int_list_is_empty((*front_ptr)) == true) {
        (*front_ptr) = node;
        return false;
    }
    (*front_ptr) = node;
    free(node);
    return true;
}

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    node_t *node = malloc(sizeof(node_t));

    node->value = elem;
    node->next = (*front_ptr);
    if (list_is_empty((*front_ptr)) == true) {
        (*front_ptr) = node;
        return false;
    }
    (*front_ptr) = node;
    free(node);
    return true;
}

bool stack_pop(stack_t *stack_ptr)
{
    list_t tmp = (*stack_ptr);

    if (stack_is_empty(*stack_ptr) == true)
        return false;
    (*stack_ptr) = (*stack_ptr)->next;
    free(tmp);
    return true;
}
