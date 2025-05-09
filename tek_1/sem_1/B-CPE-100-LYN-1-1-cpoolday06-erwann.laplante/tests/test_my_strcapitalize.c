/*
** EPITECH PROJECT, 2021
** Task 11 - Unit tests - part II
** File description:
** test my_strcapitalize.
*/
#include <criterion/criterion.h>

char *my_strcapitalize(char *str);

Test(my_strcapitalize , cherche_str_in_str)
{
    char my_str[] = "hey, how are you? 42WORds forty-two; fifty+one";

    my_strcapitalize(my_str);
    cr_assert_str_eq(my_str,"Hey, How Are You? 42words Forty-Two; Fifty+One");
}
