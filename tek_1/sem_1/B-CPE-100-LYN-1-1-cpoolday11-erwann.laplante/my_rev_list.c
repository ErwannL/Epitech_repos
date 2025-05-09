/*
** EPITECH PROJECT, 2021
** Task 03 - my_rev_list
** File description:
** description
*/
#include <stdlib.h>
#include "include/mylist.h"
#include "include/my.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *new;
    linked_list_t *previous;

    while (*begin) {
        new = (*begin)->next;
        (*begin)->next = previous;
        previous = (*begin);
        (*begin) = new;
    }
    (*begin) = previous;
}
