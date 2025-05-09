/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04pm-erwann.laplante
** File description:
** clear
*/

#include "int_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"

void int_list_clear (int_list_t *front_ptr)
{
    int_list_t cur = *front_ptr;
    int_list_t nxt;

    while (cur != NULL) {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
    *front_ptr = NULL;
}

void list_clear(list_t *front_ptr)
{
    list_t cur = *front_ptr;
    list_t nxt;

    while (cur != NULL) {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
    *front_ptr = NULL;
}

void stack_clear(stack_t *stack_ptr)
{
    list_t cur = *stack_ptr;
    list_t nxt;

    while (cur != NULL) {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
    *stack_ptr = NULL;
}
