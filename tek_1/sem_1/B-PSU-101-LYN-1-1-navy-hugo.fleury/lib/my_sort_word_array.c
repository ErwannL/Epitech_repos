/*
** EPITECH PROJECT, 2021
** my_sort_word_array
** File description:
** description
*/

#include "my.h"

void my_swap_array(char **tab, int i)
{
    char *swap_str = 0;

    swap_str = my_strdup(tab[i]);
    tab[i] = my_strdup(tab[i - 1]);
    tab[i - 1] = my_strdup(swap_str);
}

int my_sort_word_array(char **tab)
{
    for (int i = 1; tab[i] != 0; i++) {
        if (tab[i][0] == '-') {
            tab++;
        }
    }
    for (int i = 0; tab[i] != 0; i++) {
        if (i > 0 && (my_strcmp(tab[i], tab[i - 1]) < 0)) {
            my_swap_array(tab, i);
            i -= 2;
        } else if (i == 0) {
            tab[i] = my_strdup(tab[0]);
        }
    }
    return 0;
}
