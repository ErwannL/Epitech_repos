/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** Not
*/

#include "Not.hpp"

Not::Not()
{
    for (auto i = 0; i != 2; i++)
        state.push_back(nts::Undefined);
}

Not::~Not()
{
}

nts::Tristate Not::NotFunction(nts::Tristate a)
{
    if (a == nts::Tristate::False)
        return nts::Tristate::True;
    else if (a == nts::Tristate::True)
        return nts::Tristate::False;
    return nts::Undefined;
}

void Not::simulation(size_t first, nts::Tristate new_state, size_t pin)
{
    this->setState(new_state, pin);
    this->checker = set_data(this->checker, pin, 1);
    switch (pin)
    {
    case 1:
        this->setState(this->NotFunction(this->getState(1)), 2);
        this->checker = set_data(this->checker, 2, 1);
        break;
    default:
        break;
    }
}
