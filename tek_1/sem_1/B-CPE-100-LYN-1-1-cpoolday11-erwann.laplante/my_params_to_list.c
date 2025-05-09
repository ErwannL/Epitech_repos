/*
** EPITECH PROJECT, 2021
** Task 01 - my_params_to_list
** File description:
** description
*/
#include <stdlib.h>
#include "include/mylist.h"
#include "include/my.h"

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    linked_list_t *list;
    linked_list_t *save = 0;

    for (int i = 0; i < ac; i++) {
        list = malloc(sizeof(*list));
        list->data = my_strdup(av[i]);
        list->next = save;
        save = list;
    }
    return (list);
}
