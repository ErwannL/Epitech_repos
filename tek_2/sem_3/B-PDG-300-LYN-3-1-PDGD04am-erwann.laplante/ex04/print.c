/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04am-erwann.laplante
** File description:
** print
*/

#include "print.h"

void print_normal (const char *str)
{
    printf("%s\n", str);
}

void print_reverse (const char *str)
{
    for (int i = strlen(str) - 1; str[i]; i--)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper (const char *str)
{
    for (int i = 0; str[i]; i++) {
        printf("%c", (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i]);
    }
    printf("\n");
}

void print_42 (const char *str)
{
    printf("42\n");
}

void do_action (action_t action, const char *str)
{
    void (*my_fonction[4])(const char *str) = {print_normal, print_reverse,
        print_upper, print_42};

    (*my_fonction[action])(str);
}
