/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-myprintf-erwann.laplante
** File description:
** unit_test
*/

#include "../includes/my.h"

void test_fonction3(char *str, int nbr)
{
    my_printf(str, nbr);
}

Test(test_fonction3, test_printf3)
{
    cr_redirect_stdout();
    test_fonction3("%i", 10);
    cr_assert_stdout_eq_str("10");
}

void test_fonction4(char *str, int nbr)
{
    my_printf(str, nbr);
}

Test(test_fonction4, test_printf4)
{
    cr_redirect_stdout();
    test_fonction4("%d", 10);
    cr_assert_stdout_eq_str("10");
}
