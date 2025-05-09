/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** Output
*/

#include "Output.hpp"

Output::Output()
{
    for (auto i = 0; i != 1; i++)
        state.push_back(nts::Undefined);
}

Output::~Output()
{
}

void Output::simulation(size_t first, nts::Tristate new_state, size_t pin)
{
    this->setState(new_state, 1);
    this->checker = this->set_data(this->checker, 1, 1);
}