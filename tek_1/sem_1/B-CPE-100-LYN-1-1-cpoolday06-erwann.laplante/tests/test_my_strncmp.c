/*
** EPITECH PROJECT, 2021
** Task 11 - Unit tests - part II
** File description:
** test my_strncmp
*/

#include <criterion/criterion.h>
int my_strncmp(char const *s1 , char const *s2 , int n);
Test(my_strncmp , cherche_str_in_str)
{
    char my_str [] = "Hello world";
    char my_to_find[] = "orl";
    char str [] = "Hello world";
    char to_find[] = "orl";
    my_strncmp(my_str, my_to_find,2);
    strncmp(str, to_find,2);
    cr_assert_str_eq(my_str,str);
}
