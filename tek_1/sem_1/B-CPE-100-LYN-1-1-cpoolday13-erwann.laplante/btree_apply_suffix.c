/*
** EPITECH PROJECT, 2021
** Task 04 - btree_apply_suffix
** File description:
** description
*/
#include "include/btree.h"

void btree_apply_suffix(btree_t *root , int (*applyf)(void *))
{
    if (root) {
        btree_apply_suffix(root->left, (*applyf));
        btree_apply_suffix(root->right, (*applyf));
        (*applyf)(root->item);
    }
}
