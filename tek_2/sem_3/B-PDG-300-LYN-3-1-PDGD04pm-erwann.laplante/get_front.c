/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04pm-erwann.laplante
** File description:
** get_front
*/

#include "int_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"

int int_list_get_elem_at_front(int_list_t list)
{
    if (int_list_is_empty(list) == true)
        return 0;
    return list->value;
}

void *list_get_elem_at_front(list_t list)
{
    if (list_is_empty(list) == true)
        return 0;
    return list->value;
}

void *stack_top(stack_t stack)
{
    if (stack_is_empty(stack) == true)
        return 0;
    return stack->value;
}
