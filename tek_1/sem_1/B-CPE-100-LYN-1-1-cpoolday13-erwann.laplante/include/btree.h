/*
** EPITECH PROJECT, 2021
** Task 00 - libbtree.a
** File description:
** test my_strcapitalize.
*/

#ifndef LIST_H_
    #define LIST_H_
    typedef struct btree
    {
        struct btree *left;
        struct btree *right;
        void *item;
    }btree_t;
    btree_t *btree_create_node(void *item);
#endif
