/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04pm-erwann.laplante
** File description:
** dump
*/

#include "int_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"

void int_list_dump (int_list_t list)
{
    int_list_t cur = list;

    for (; cur != NULL;) {
        printf("%d\n", cur->value);
        cur = cur->next;
    }
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    list_t cur = list;

    for (; cur != NULL;) {
        val_disp(cur->value);
        cur = cur->next;
    }
}

bool stack_push(stack_t *stack_ptr, void *elem)
{
    node_t *node = malloc(sizeof(node_t));

    node->value = elem;
    node->next = (*stack_ptr);
    if (stack_is_empty((*stack_ptr)) == true) {
        (*stack_ptr) = node;
        return false;
    }
    (*stack_ptr) = node;
    return true;
}
