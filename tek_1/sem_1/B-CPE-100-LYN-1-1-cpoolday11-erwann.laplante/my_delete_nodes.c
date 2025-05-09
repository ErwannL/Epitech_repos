/*
** EPITECH PROJECT, 2021
** ask 04 - my_apply_on_nodes
** File description:
** description
*/
#include <stdlib.h>
#include "include/mylist.h"
#include "include/my.h"

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    while (*begin) {
        if (((*cmp)((*begin)->data, data_ref)) == 0) {
            (*begin) = (*begin)->next;
        }
        if (((*cmp)((*begin)->next->data, data_ref)) == 0) {
            (*begin)->next = (*begin)->next->next;
        }
    }
    return (0);
}
