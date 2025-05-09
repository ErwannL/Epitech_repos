/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04pm-erwann.laplante
** File description:
** del_position
*/

#include "int_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

bool int_list_del_elem_at_position (int_list_t *front_ptr,
    unsigned int position)
{
    int_list_t tmp = (*front_ptr);
    int_list_t nxt;

    if (int_list_is_empty(*front_ptr) == true ||
        int_list_get_size((*front_ptr)) == 0) {
        free(tmp);
        return false;
    }
    if (position == 0) {
        return int_list_del_elem_at_front(front_ptr);
    }
    position--;
    for (; position; tmp = tmp->next, position -= 1);
    nxt = tmp->next->next;
    free(tmp->next);
    tmp->next = nxt;
    return true;
}

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t tmp = (*front_ptr);
    list_t nxt;

    if (list_is_empty(*front_ptr) == true ||
        list_get_size((*front_ptr)) == 0) {
        free(tmp);
        return false;
    }
    if (position == 0) {
        return list_del_elem_at_front(front_ptr);
    }
    position--;
    for (; position; tmp = tmp->next, position -= 1);
    nxt = tmp->next->next;
    free(tmp->next);
    tmp->next = nxt;
    return true;
}
