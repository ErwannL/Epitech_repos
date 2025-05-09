/*
** EPITECH PROJECT, 2021
** ask 04 - my_apply_on_nodes
** File description:
** description
*/
#include <stdlib.h>
#include "include/mylist.h"
#include "include/my.h"

linked_list_t *my_find_node(linked_list_t const *begin
, void const *data_ref, int (*cmp)())
{
    while (begin) {
        if (((*cmp)(begin->data, data_ref)) == 0)
            return (begin);
    }
    return (0);
}
