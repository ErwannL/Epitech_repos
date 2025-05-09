/*
** EPITECH PROJECT, 2021
** Task 06 - btree_search_item
** File description:
** description
*/
#include "include/btree.h"
#include <stdlib.h>

void *btree_search_item(btree_t const *root, void const *data_ref,
int (*cmpf)())
{
    if (((*cmpf)(root->item, data_ref)) == 0)
        return(root);
    else if (((*cmpf)(root->item, data_ref)) < 0)
        infix_tree_search(root->left, data_ref);
    else
        infix_tree_search(root->right, data_ref);
    return(NULL);
}
