/*
** EPITECH PROJECT, 2021
** Task 11 - Unit tests - part II
** File description:
** test my_strcapitalize.
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int main(int ac, char **av);

Test(main , test_f_cat)
{
    cr_redirect_stdout();
    main(1, "lol");
    cr_assert_stdout_eq_str("lol");
}
