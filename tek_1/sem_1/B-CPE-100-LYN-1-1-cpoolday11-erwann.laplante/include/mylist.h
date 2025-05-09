/*
** EPITECH PROJECT, 2021
** Task 01 - my_params_to_list
** File description:
** description
*/

#ifndef LIST_H_
    #define LIST_H_
    typedef struct linked_list
    {
        void *data;
        struct linked_list *next;
    } linked_list_t;
    linked_list_t *my_params_to_list(int ac, char * const *av);
#endif
