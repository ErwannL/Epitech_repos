/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-myprintf-erwann.laplante
** File description:
** unit_test
*/

#include "../includes/my.h"

void test_fonction5(char *str, int nbr)
{
    my_printf(str, nbr);
}

Test(test_fonction5, test_printf5)
{
    cr_redirect_stdout();
    test_fonction5("%u", 10);
    cr_assert_stdout_eq_str("10");
}

void test_fonction6(char *str, int nbr)
{
    my_printf(str, nbr);
}

Test(test_fonction6, test_printf6)
{
    cr_redirect_stdout();
    test_fonction6("%o", 10);
    cr_assert_stdout_eq_str("12");
}
