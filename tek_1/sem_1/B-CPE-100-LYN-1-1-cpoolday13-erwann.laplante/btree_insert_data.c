/*
** EPITECH PROJECT, 2021
** Task 05 - btree_insert_data
** File description:
** description
*/
#include "include/btree.h"

void btree_insert_data(btree_t **root , void *item , int (*cmpf)())
{
    btree_t *tree = *root;
    if (tree->item == 0)
        tree = btree_create_node(item);
    if (((*cmpf)(tree->item, item)) < 0)
        btree_insert_data(&tree->left, item, (*cmpf));
    else
        btree_insert_data(&tree->right, item, (*cmpf));
}
