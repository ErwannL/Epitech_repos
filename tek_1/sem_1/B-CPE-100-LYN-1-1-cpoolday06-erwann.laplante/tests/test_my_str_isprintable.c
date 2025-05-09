/*
** EPITECH PROJECT, 2021
** Task 17 - Unit tests - part III
** File description:
** test my_str_isprintable
*/
#include <criterion/criterion.h>

int my_str_isprintable(char const *str);

Test(my_str_isprintable, is_alpha)
{
    char str[] = "hello ";
    int i = 0;

    i = my_str_isprintable(str);
    cr_assert_eq(i, 1);
}
