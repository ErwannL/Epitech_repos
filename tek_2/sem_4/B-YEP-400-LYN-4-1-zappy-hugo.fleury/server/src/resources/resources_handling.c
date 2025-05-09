/*
** EPITECH PROJECT, 2023
** antoine [WSL: Ubuntu]
** File description:
** resources_mapping
*/

#include "../../include/zappy_resources.h"

int init_resources(resources_t **res)
{
    for (unsigned int i = 0; i < 7; i++)
        new_resource(res, i);
    return (0);
}

int new_resource(resources_t **res, res_type_t key)
{
    resources_t *elem = malloc(sizeof(resources_t));

    for (resources_t *tmp = *res; tmp; tmp = tmp->next)
        if (tmp->key == key)
            return (-1);
    elem->key = key;
    elem->amount = 0;
    elem->next = *res;
    *res = elem;
    return (0);
}

int get_resource(resources_t *res, res_type_t key)
{
    for (resources_t *tmp = res; tmp; tmp = tmp->next) {
        if (tmp->key == key) {
            return (tmp->amount);
        }
    }
    return (-1);
}

int change_resource_amount(resources_t *res, res_type_t key, int amount)
{
    for (resources_t *tmp = res; tmp; tmp = tmp->next)
        if ((tmp->key == key) && (tmp->amount = amount))
            return (0);
    return (-1);
}
