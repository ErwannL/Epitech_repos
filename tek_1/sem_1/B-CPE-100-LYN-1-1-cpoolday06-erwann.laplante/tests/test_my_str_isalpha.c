/*
** EPITECH PROJECT, 2021
** Task 17 - Unit tests - part III
** File description:
** test my_str_isalpha
*/
#include <criterion/criterion.h>

int my_str_isalpha(char const *str);

Test(my_str_isalpha, is_alpha)
{
    char str[] = "Hello";
    int i = 0;

    i = my_str_isalpha(str);
    cr_assert_eq(i, 1);
}
