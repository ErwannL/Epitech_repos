/*
** EPITECH PROJECT, 2021
** Task 11 - Unit tests - part II
** File description:
** test my_strstr
*/
#include <criterion/criterion.h>

char *my_strstr(char *str , char const *to_find);

Test(my_strstr , cherche_str_in_str)
{
    char my_str[] = "Hello";
    char my_to_find[] = "orl";
    char str[] = "Hello";
    char to_find[] = "orl";

    my_strstr(my_str, my_to_find);
    strstr(str, to_find);
    cr_assert_str_eq(my_str,str);
}
