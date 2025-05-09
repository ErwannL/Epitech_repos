/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper3-anthony.faure
** File description:
** main
*/

#include "../include/my.h"

void free_word_array(char **to_free)
{
    for (int i = 0; i != 5; i++)
        free(to_free[i]);
    free(to_free);
}

void free_all(numbers_t *num)
{
    free_word_array(num->zero);
    free_word_array(num->one);
    free_word_array(num->two);
    free_word_array(num->three);
    free_word_array(num->four);
    free_word_array(num->five);
    free_word_array(num->six);
    free_word_array(num->seven);
    free_word_array(num->eight);
    free_word_array(num->nine);
    free(num->string);
    free(num->to_print);
    free(num);
}

int main(int argc, char **argv)
{
    numbers_t *num = fill_numbers();

    if (error_handling(argc, argv, num) == 84) {
        free_all(num);
        return 84;
    }
    apply_sting(num);
    print_numbers(num);
    free_all(num);
    return 0;
}
