/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-myprintf-erwann.laplante
** File description:
** unit_test
*/

#include "../includes/my.h"

void test_fonction11(char *str, char *str2)
{
    my_printf(str, str2);
}

Test(test_fonction11, test_printf11)
{
    cr_redirect_stdout();
    test_fonction11("%p", "test");
    cr_assert_stdout_eq_str("test");
}

void test_fonction12(char *str, char *str2)
{
    my_printf(str, str2);
}

Test(test_fonction12, test_printf12)
{
    cr_redirect_stdout();
    test_fonction12("%S", "test");
    cr_assert_stdout_eq_str("test");
}
