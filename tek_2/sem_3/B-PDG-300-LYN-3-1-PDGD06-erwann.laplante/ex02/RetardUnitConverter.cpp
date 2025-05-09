/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD06-erwann.laplante
** File description:
** RetardUnitConverter
*/

#include <iostream>
#include <cstring>
#include <math.h>
#include <sstream>

std::string check_error(float new_temperature)
{
    std::ostringstream my_o_string;
    float result;
    std::ostringstream a;

    if (new_temperature == -0)
        new_temperature = 0;
    my_o_string << new_temperature;
    std::string my_string(my_o_string.str());
    result = round((abs(new_temperature) - abs((int)new_temperature)) * 1000) / 1000;
    a << result;
    std::string b(a.str());
    if (b.length() == 1)
        my_string += ".000";
    else if (b.length() == 3)
        my_string += "00";
    else if (b.length() == 4)
        my_string += "0";
    while (my_string.length() < 16)
        my_string = " " + my_string;
    return my_string;
}

int main(void)
{
    float old_temperature;
    float new_temperature;
    std::string scale;

    while (std::cin >> old_temperature >> scale) {
        if (scale == "Celsius") {
            new_temperature = round((old_temperature / 5 * 9 + 32) * 1000) / 1000;
            std::cout << check_error(new_temperature) << "      Fahrenheit" << std::endl;
        }
        if (scale == "Fahrenheit") {
            new_temperature = round((5.0 / 9.0 * (old_temperature - 32)) * 1000) / 1000;
            std::cout << check_error(new_temperature) << "         Celsius" << std::endl;
        }
    }
    return 0;
}
