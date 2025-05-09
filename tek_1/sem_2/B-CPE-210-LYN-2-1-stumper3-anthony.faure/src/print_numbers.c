/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper3-anthony.faure
** File description:
** print_numbers
*/

#include "../include/my.h"

char **get_numbers(numbers_t *num, int i)
{
    if (num->to_print[i] == '0')
        return num->zero;
    if (num->to_print[i] == '1')
        return num->one;
    if (num->to_print[i] == '2')
        return num->two;
    if (num->to_print[i] == '3')
        return num->three;
    if (num->to_print[i] == '4')
        return num->four;
    if (num->to_print[i] == '5')
        return num->five;
    if (num->to_print[i] == '6')
        return num->six;
    if (num->to_print[i] == '7')
        return num->seven;
    if (num->to_print[i] == '8')
        return num->eight;
    return num->nine;
}

void print_line(numbers_t *num, int i, int j)
{
    my_putstr(get_numbers(num, i)[j], 1);
    if (i + 1 != my_strlen(num->to_print)) {
        my_putchar(' ', 1);
    }
}

void print_numbers(numbers_t *num)
{
    for (int j = 0; j != 5; j++) {
        for (int i = 0; i != my_strlen(num->to_print); i++) {
            print_line(num, i, j);
        }
        my_putchar('\n', 1);
    }
}
