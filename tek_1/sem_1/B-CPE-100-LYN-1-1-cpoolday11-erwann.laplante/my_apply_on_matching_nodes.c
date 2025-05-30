/*
** EPITECH PROJECT, 2021
** ask 04 - my_apply_on_nodes
** File description:
** description
*/
#include <stdlib.h>
#include "include/mylist.h"
#include "include/my.h"

int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)()
, void const *data_ref, int (*cmp)())
{
    while (begin) {
        if (((*cmp)(begin->data, data_ref)) == 0) {
            (*f)(begin->data);
        }
    }
    return (0);
}
