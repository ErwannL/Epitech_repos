/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-myprintf-erwann.laplante
** File description:
** unit_test
*/

#include "../includes/my.h"

void test_fonction(char *str, char *str2)
{
    my_printf(str, str2);
}

Test(test_fonction, test_printf)
{
    cr_redirect_stdout();
    test_fonction("%s", "test");
    cr_assert_stdout_eq_str("test");
}

void test_fonction2(char *str, char c)
{
    my_printf(str, c);
}

Test(test_fonction2, test_printf2)
{
    cr_redirect_stdout();
    test_fonction2("%c", 't');
    cr_assert_stdout_eq_str("t");
}
