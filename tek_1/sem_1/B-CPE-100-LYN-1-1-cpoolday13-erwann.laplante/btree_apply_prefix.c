/*
** EPITECH PROJECT, 2021
** Task 02 - btree_apply_prefix
** File description:
** description
*/
#include "include/btree.h"

void btree_apply_prefix(btree_t *root , int (*applyf)(void*))
{
    if (root) {
        (*applyf)(root->item);
        btree_apply_prefix(root->left, (*applyf));
        btree_apply_prefix(root->right, (*applyf));
    }
}
