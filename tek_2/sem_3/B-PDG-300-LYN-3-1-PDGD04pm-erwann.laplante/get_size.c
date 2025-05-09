/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04pm-erwann.laplante
** File description:
** get_size
*/

#include "int_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"

unsigned int int_list_get_size (int_list_t list)
{
    unsigned int len = 0;
    int_list_t cur = list;

    for (; cur != NULL;) {
        len++;
        cur = cur->next;
    }
    return len;
}

unsigned int list_get_size(list_t list)
{
    unsigned int len = 0;
    list_t cur = list;

    for (; cur != NULL;) {
        len++;
        cur = cur->next;
    }
    return len;
}

unsigned int stack_get_size(stack_t stack)
{
    unsigned int len = 0;
    stack_t cur = stack;

    for (; cur != NULL;) {
        len++;
        cur = cur->next;
    }
    return len;
}
