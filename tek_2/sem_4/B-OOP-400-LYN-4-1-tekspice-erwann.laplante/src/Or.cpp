/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** Or
*/

#include "Or.hpp"

Or::Or()
{
    for (auto i = 0; i != 3; i++)
        state.push_back(nts::Undefined);
}

Or::~Or()
{
}

nts::Tristate Or::OrFunction(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::True || b == nts::Tristate::True)
        return nts::Tristate::True;
    else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    else
        return nts::Tristate::False;
}

void Or::simulation(size_t first, nts::Tristate new_state, size_t pin)
{
    this->setState(new_state, pin);
    this->checker = set_data(this->checker, pin, 1);
    switch (pin)
    {
    case 1:
        if (retrieve_data(this->checker, 2) == 0)
            return;
        this->setState(this->OrFunction(this->getState(2), new_state), 3);
        this->checker = set_data(this->checker, 3, 1);
        break;
    case 2:
        if (retrieve_data(this->checker, 1) == 0)
            return;
        this->setState(this->OrFunction(this->getState(1), new_state), 3);
        this->checker = set_data(this->checker, 3, 1);
        break;
    default:
        break;
    }
}
