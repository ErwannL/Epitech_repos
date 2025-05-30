/*
** EPITECH PROJECT, 2021
** Task 03 - btree_apply_infix
** File description:
** description
*/
#include "include/btree.h"

void btree_apply_infix(btree_t *root , int (*applyf)(void *))
{
    if (root) {
        btree_apply_infix(root->left, (*applyf));
        (*applyf)(root->item);
        btree_apply_infix(root->right, (*applyf));
    }
}
