/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-myprintf-erwann.laplante
** File description:
** unit_test
*/

#include "../includes/my.h"

void test_fonction9(char *str, int nbr)
{
    my_printf(str, nbr);
}

Test(test_fonction9, test_printf9)
{
    cr_redirect_stdout();
    test_fonction9("%O", 10);
    cr_assert_stdout_eq_str("12");
}

void test_fonction10(char *str, int nbr)
{
    my_printf(str, nbr);
}

Test(test_fonction10, test_printf10)
{
    cr_redirect_stdout();
    test_fonction10("%b", 10);
    cr_assert_stdout_eq_str("1010");
}
