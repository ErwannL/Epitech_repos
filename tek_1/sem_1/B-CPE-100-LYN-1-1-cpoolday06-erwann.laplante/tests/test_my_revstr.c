/*
** EPITECH PROJECT, 2021
** Task 04 - Unit tests - part I
** File description:
** test my_revstr
*/
#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, revers_string)
{
    char str[] = "Hello";

    my_revstr(str);
    cr_assert_str_eq(str, "olleH");
}
