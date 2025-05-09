/*
** EPITECH PROJECT, 2021
** find_char
** File description:
** find the recurence of char
*/

#include "lemin.h"

List *init(void)
{
    List *list = malloc(sizeof(*list));
    Element *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL) {
        return(list);
    }
    element->name = NULL;
    element->next = NULL;
    list->first = element;
    return list;
}

int insertion(List *list, char *newname, int nb)
{
    Element *new = malloc(sizeof(*new));

    if (list == NULL || new == NULL)
        return(EXIT_FAILURE);
    new->start = 0;
    new->end = 0;
    if (nb == 1)
        new->start = nb;
    if (nb == 2)
        new->end = nb;
    new->name = newname;
    new->next = list->first;
    list->first = new;
    return (0);
}

int len_chain(List *list)
{
    Element *current_list = list->first;
    int compteur = 0;

    if (list == NULL) {
        return(0);
    }
    while (current_list != NULL) {
        compteur ++;
        current_list = current_list->next;
    }
    return (compteur);
}

int print_chain(List *list)
{
    Element *current_list = list->first;

    if (list == NULL) {
        return(EXIT_FAILURE);
    }
    while (current_list != NULL) {
        if (current_list->name == NULL)
            return(0);
        my_putstr(current_list->name);
        my_putstr("\n");
        current_list = current_list->next;
    }
    return (0);
}

char **chain_to_array(List *list)
{
    Element *current_list = list->first;
    int len = len_chain(list);
    char **array = malloc(sizeof(char *) * len);
    int compteur = 0;

    if (list == NULL) {
        return(0);
    }
    while (current_list != NULL) {
        array[compteur] = current_list->name;
        current_list = current_list->next;
        compteur ++;
    }
    return (array);
}
