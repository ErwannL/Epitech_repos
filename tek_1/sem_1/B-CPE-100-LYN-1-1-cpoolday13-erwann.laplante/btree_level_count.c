/*
** EPITECH PROJECT, 2021
** Task 07 - btree_level_count
** File description:
** description
*/
#include "include/btree.h"
#include <stddef.h>

size_t btree_level_count(btree_t const *root)
{
    int right = 0;
    int left = 0;

    if (root)
        right = btree_level_count(root->right);
        left = btree_level_count(root->left);
        if (right > left)
            return (right + 1);
        else
            return (left + 1);
    return (0);
}
