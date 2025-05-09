/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** test_function
*/

#include "criterion/criterion.h"
#include "IComponent.hpp"

Test(test_function_clear_str, test_condition_clear_str_isnt)
{
    cr_assert_eq(test_function_clear_str('a'), 0);
}

Test(test_function_clear_str, test_condition_clear_str_is)
{
    cr_assert_eq(test_function_clear_str(' '), 1);
}

Test(clear_str, test_clear_str)
{
    cr_assert_str_eq(clear_str("		  	 	Bonjour").c_str(), "Bonjour");
}

Test(clear_str, test_clear_str_com)
{
    cr_assert_str_eq(clear_str("Bonjour #this is a test").c_str(), "Bonjour");
}

Test(get_name, test_get_name_semi_colon)
{
    cr_assert_str_eq(get_name("name:a").c_str(), "name");
}

Test(get_name, test_get_name_semi_equal)
{
    cr_assert_str_eq(get_name("name=a").c_str(), "name");
}

Test(get_pin, test_get_pin)
{
    cr_assert_str_eq(get_pin("22 ").c_str(), "22");
}

Test(tekspice_function, test_too_few_args)
{
    char **res;

    cr_assert_eq(tekspice_function(0, res), 84);
}

Test(tekspice_function, test_too_many_args)
{
    std::string str[] = {"1", "2", "3"};
    std::vector<char*> tmp;

    std::transform(std::begin(str), std::end(str), std::back_inserter(tmp), [](std::string& s){ s.push_back(0); return &s[0]; });
    tmp.push_back(nullptr);
    cr_assert_eq(tekspice_function(3, tmp.data()), 84);
}

Test(tekspice_function, test_not_file)
{
    std::string str[] = {"1", "2"};
    std::vector<char*> tmp;

    std::transform(std::begin(str), std::end(str), std::back_inserter(tmp), [](std::string& s){ s.push_back(0); return &s[0]; });
    tmp.push_back(nullptr);
    cr_assert_eq(tekspice_function(2, tmp.data()), 84);
}

Test(tekspice_function, test_bad_file)
{
    std::string str[] = {"1", "tests/test_function.cpp"};
    std::vector<char*> tmp;

    std::transform(std::begin(str), std::end(str), std::back_inserter(tmp), [](std::string& s){ s.push_back(0); return &s[0]; });
    tmp.push_back(nullptr);
    cr_assert_eq(tekspice_function(2, tmp.data()), 84);
}

Test(tekspice_function, test_bad_line)
{
    std::string str[] = {"1", "tests/bad_line.nts"};
    std::vector<char*> tmp;

    std::transform(std::begin(str), std::end(str), std::back_inserter(tmp), [](std::string& s){ s.push_back(0); return &s[0]; });
    tmp.push_back(nullptr);
    cr_assert_eq(tekspice_function(2, tmp.data()), 84);
}

Test(tekspice_function, test_empty_file)
{
    std::string str[] = {"1", "tests/empty.nts"};
    std::vector<char*> tmp;

    std::transform(std::begin(str), std::end(str), std::back_inserter(tmp), [](std::string& s){ s.push_back(0); return &s[0]; });
    tmp.push_back(nullptr);
    cr_assert_eq(tekspice_function(2, tmp.data()), 84);
}

Test(tekspice_function, test_no_component)
{
    std::string str[] = {"1", "tests/no_component.nts"};
    std::vector<char*> tmp;

    std::transform(std::begin(str), std::end(str), std::back_inserter(tmp), [](std::string& s){ s.push_back(0); return &s[0]; });
    tmp.push_back(nullptr);
    cr_assert_eq(tekspice_function(2, tmp.data()), 84);
}
