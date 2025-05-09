/*
** EPITECH PROJECT, 2021
** Task 03 - my_show_word_array
** File description:
** function
*/
#include"../../include/my.h"

void my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
    return (0);
}
