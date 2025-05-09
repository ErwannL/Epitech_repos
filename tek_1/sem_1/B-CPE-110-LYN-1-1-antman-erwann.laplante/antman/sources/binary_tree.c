/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** binary_tree
*/

#include "../include/my.h"

void add_node(node **tree, unsigned int key, char symb)
{
    node *tmpNode;
    node *tmpTree = *tree;
    node *elem = malloc(sizeof(node));

    elem->key = key;
    elem->symb = symb;
    elem->left = NULL;
    elem->right = NULL;
    if (tmpTree) {
        while (tmpTree) {;
            tmpNode = tmpTree;
            ((symb > tmpTree->symb) ? (tmpTree = tmpTree->right, (!tmpTree)
            ? tmpNode->right = elem : 0) : (tmpTree = tmpTree->left, (!tmpTree)
            ? tmpNode->left = elem : 0));
        }
    } else
        *tree = elem;
}

void clear_tree(node **tree)
{
    node *tmpTree = *tree;

    if (!tree)
        return;
    if (tmpTree->left)
        clear_tree(&tmpTree->left);
    if (tmpTree->right)
        clear_tree(&tmpTree->right);
    free(tmpTree);
    *tree = NULL;
}

char *search_node(node *tree, unsigned int symb)
{
    char *num = "";

    while (tree) {
        if (symb == tree->symb)
            return num;
        if (symb > tree->symb) {
            num = my_strcat(num, "0");
            tree = tree->right;
        } else {
            num = my_strcat(num, "1");
            tree = tree->left;
        }
    }
    return num;
}

void print_tree(char *str, unsigned int key, node *tree)
{
    int s;

    for (int i = 0; str[i] != '\0'; i++) {
        s = str[i];
        i++;
        i++;
        key = str[i] - 48;
        i++;
        while (str[i] > 47 && str[i] < 58) {
            key = key * 10 + str[i] - 48;
            i++;
        }
        my_putstr(search_node(tree, s));
        my_putchar('.');
        key = 0;
    }
}

int binary_tree(char *str)
{
    unsigned int key = 0;
    char symb;
    node *tree = NULL;

    for (int i = 0; str[i + 2] != '\0'; i++) {
        symb = str[i];
        i++;
        i++;
        key = str[i] - 48;
        i++;
        while (str[i] > 47 && str[i] < 58) {
            key = key * 10 + str[i] - 48;
            i++;
        }
        add_node(&tree, key, symb);
        key = 0;
    }
    print_tree(str, key, tree);
    clear_tree(&tree);
    return 0;
}
