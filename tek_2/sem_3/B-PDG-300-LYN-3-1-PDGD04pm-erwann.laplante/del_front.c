/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04pm-erwann.laplante
** File description:
** del_front
*/

#include "int_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

bool int_list_del_elem_at_front (int_list_t *front_ptr)
{
    int_list_t tmp = (*front_ptr);

    if (int_list_is_empty(*front_ptr) == true)
        return false;
    (*front_ptr) = (*front_ptr)->next;
    free(tmp);
    return true;
}

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t tmp = (*front_ptr);

    if (list_is_empty(*front_ptr) == true)
        return false;
    (*front_ptr) = (*front_ptr)->next;
    free(tmp);
    return true;
}
