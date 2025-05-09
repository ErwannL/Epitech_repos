/*
** EPITECH PROJECT, 2021
** ask 04 - my_apply_on_nodes
** File description:
** description
*/
#include <stdlib.h>
#include "include/mylist.h"
#include "include/my.h"

int my_apply_on_nodes(linked_list_t *begin , int (*f)(void *))
{
    while (begin)
        (*f)(begin->data);
    return (0);
}
