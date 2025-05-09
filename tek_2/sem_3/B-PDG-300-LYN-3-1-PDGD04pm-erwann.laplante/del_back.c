/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04pm-erwann.laplante
** File description:
** del_back
*/

#include "int_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

bool int_list_del_elem_at_back (int_list_t *front_ptr)
{
    int_list_t tmp = (*front_ptr);
    int_list_t prev;

    if (int_list_is_empty(*front_ptr) == true) {
        free(tmp);
        return false;
    }
    if (tmp->next == NULL) {
        free(tmp);
        (*front_ptr) = NULL;
        return true;
    }
    for (; tmp->next != NULL; prev = tmp, tmp = tmp->next);
    prev->next = NULL;
    free(tmp);
    return true;
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t tmp = (*front_ptr);
    list_t prev;

    if (list_is_empty(*front_ptr) == true) {
        free(tmp);
        return false;
    }
    if (tmp->next == NULL) {
        free(tmp);
        (*front_ptr) = NULL;
        return true;
    }
    for (; tmp->next != NULL; prev = tmp, tmp = tmp->next);
    prev->next = NULL;
    free(tmp);
    return true;
}
