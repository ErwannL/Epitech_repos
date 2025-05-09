/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-myprintf-erwann.laplante
** File description:
** unit_test
*/

#include "../includes/my.h"

void test_fonction7(char *str, int nbr)
{
    my_printf(str, nbr);
}

Test(test_fonction7, test_printf7)
{
    cr_redirect_stdout();
    test_fonction7("%x", 10);
    cr_assert_stdout_eq_str("a");
}

void test_fonction8(char *str, int nbr)
{
    my_printf(str, nbr);
}

Test(test_fonction8, test_printf8)
{
    cr_redirect_stdout();
    test_fonction8("%X", 10);
    cr_assert_stdout_eq_str("A");
}
