/*
** EPITECH PROJECT, 2021
** Task 01 - btree_create_node
** File description:
** description
*/
#include "include/btree.h"
#include <stdio.h>

btree_t *btree_create_node(void *item)
{
    btree_t *tree;

    tree = malloc(sizeof(*tree));
    tree->item = item;
    tree->left = 0;
    tree->right = 0;
    return (tree);
}
