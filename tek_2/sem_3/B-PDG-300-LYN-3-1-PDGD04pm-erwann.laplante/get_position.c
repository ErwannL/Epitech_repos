/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04pm-erwann.laplante
** File description:
** get_position
*/

#include "int_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int int_list_get_elem_at_position (int_list_t list, unsigned int position)
{
    if (int_list_is_empty(list) == true || int_list_get_size(list) == 0) {
        return 0;
    }
    if (position == 0) {
        return int_list_get_elem_at_front(list);
    }
    for (; position; list = list->next, position -= 1);
    return list->value;
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    if (list_is_empty(list) == true || list_get_size(list) == 0) {
        return 0;
    }
    if (position == 0) {
        return list_get_elem_at_front(list);
    }
    for (; position; list = list->next, position -= 1);
    return list->value;
}
