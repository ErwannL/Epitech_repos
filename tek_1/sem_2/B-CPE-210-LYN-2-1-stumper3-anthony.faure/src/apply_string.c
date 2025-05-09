/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper3-anthony.faure
** File description:
** apply_string
*/

#include "../include/my.h"

void do_change(char **number, char to_change, int i, int j)
{
    if (number[i][j] == '0')
        number[i][j] = to_change;
    return;
}

void change_char(char **number, char to_change)
{
    for (int i = 0; i != 5; i += 1) {
        for (int j = 0; number[i][j] != '\0'; j += 1)
            do_change(number, to_change, i, j);
    }
    return;
}

void find_number(numbers_t *numbers, int i, char apply)
{
    if ((numbers->to_print[i] - 48) == 4)
        change_char(numbers->four, apply);
    if ((numbers->to_print[i] - 48) == 5)
        change_char(numbers->five, apply);
    if ((numbers->to_print[i] - 48) == 6)
        change_char(numbers->six, apply);
    if ((numbers->to_print[i] - 48) == 7)
        change_char(numbers->seven, apply);
    if ((numbers->to_print[i] - 48) == 8)
        change_char(numbers->eight, apply);
    if ((numbers->to_print[i] - 48) == 9)
        change_char(numbers->nine, apply);
    return;
}

void apply_sting(numbers_t *numbers)
{
    int nb;
    char apply;

    if (numbers->string == NULL)
        return;
    for (int i = 0; i != my_strlen(numbers->to_print); i += 1) {
        nb = (numbers->to_print[i] - 48) % my_strlen(numbers->string);
        apply = numbers->string[nb];
        if ((numbers->to_print[i] - 48) == 0)
            change_char(numbers->zero, apply);
        if ((numbers->to_print[i] - 48) == 1)
            change_char(numbers->one, apply);
        if ((numbers->to_print[i] - 48) == 2)
            change_char(numbers->two, apply);
        if ((numbers->to_print[i] - 48) == 3)
            change_char(numbers->three, apply);
        find_number(numbers, i, apply);
    }
    return;
}
