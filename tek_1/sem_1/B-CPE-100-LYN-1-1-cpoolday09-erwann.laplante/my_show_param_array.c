/*
** EPITECH PROJECT, 2021
** Task 04 - my_show_param_array
** File description:
** my_params_to_array
*/
#include"include/my.h"

int my_show_param_array(struct info_param const *par)
{
    for (int i = 0; par[i].str != 0; i++) {
        my_putstr(par[i].copy);
        my_putnbr(par[i].length);
        my_show_word_array(par[i].word_array);
    }
    return(0);
}
