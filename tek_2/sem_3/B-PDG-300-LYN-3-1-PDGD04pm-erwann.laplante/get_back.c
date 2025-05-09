/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04pm-erwann.laplante
** File description:
** get_back
*/

#include "int_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int int_list_get_elem_at_back (int_list_t list)
{
    if (int_list_is_empty(list) == true)
        return 0;
    for (; list->next != NULL; list = list->next);
    return list->value;
}

void *list_get_elem_at_back(list_t list)
{
    if (list_is_empty(list) == true)
        return 0;
    for (; list->next != NULL; list = list->next);
    return list->value;
}
