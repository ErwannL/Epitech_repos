/*
** EPITECH PROJECT, 2021
** Task 02 - my_list_size
** File description:
** description
*/
#include <stdlib.h>
#include "include/mylist.h"
#include "include/my.h"

int my_list_size(linked_list_t const *begin)
{
    int compteur = 0;

    while (begin) {
        compteur++;
        begin = begin->next;
    }
    return (compteur);
}
