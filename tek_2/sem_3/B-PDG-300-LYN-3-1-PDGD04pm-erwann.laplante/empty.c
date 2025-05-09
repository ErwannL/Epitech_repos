/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04pm-erwann.laplante
** File description:
** empty
*/

#include "int_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"

bool int_list_is_empty (int_list_t list)
{
    if (list == NULL)
        return true;
    return false;
}

bool list_is_empty(list_t list)
{
    if (list == NULL)
        return true;
    return false;
}

bool stack_is_empty(stack_t stack)
{
    if (stack == NULL)
        return true;
    return false;
}
