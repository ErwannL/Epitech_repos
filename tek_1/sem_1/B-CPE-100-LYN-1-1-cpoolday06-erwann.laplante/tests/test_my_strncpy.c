/*
** EPITECH PROJECT, 2021
** Task 04 - Unit tests - part I
** File description:
** test my_strncpy
*/
#include <criterion/criterion.h>

char *my_strncpy(char *dest , char const *src , int n);

Test(my_strncpy , copy_string_in_empty_array)
{
    char my_dest[6] = {0};
    char dest[6] = {0};

    my_strncpy(my_dest , "Hello", 6);
    strncpy(dest , "Hello", 6);
    cr_assert_str_eq(my_dest , dest);
}
