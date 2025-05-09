/*
** EPITECH PROJECT, 2021
** Task 17 - Unit tests - part III
** File description:
** test my_str_islower
*/
#include <criterion/criterion.h>

int my_str_islower(char const *str);

Test(my_str_islower, is_alpha)
{
    char str[] = "hello";
    int i = 0;

    i = my_str_islower(str);
    cr_assert_eq(i, 1);
}
