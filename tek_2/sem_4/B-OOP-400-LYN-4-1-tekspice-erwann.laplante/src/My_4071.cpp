/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** My_4071
*/

#include "My_4071.hpp"

My_4071::My_4071()
{
    for (auto i = 0; i != 14; i++)
        state.push_back(nts::Undefined);
}

My_4071::~My_4071()
{
}

void My_4071::simulation(size_t first, nts::Tristate new_state, size_t pin)
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
    case 5:
        if (retrieve_data(this->checker, 6) == 0)
            return;
        this->setState(this->OrFunction(this->getState(6), new_state), 4);
        this->checker = set_data(this->checker, 4, 1);
        break;
    case 6:
        if (retrieve_data(this->checker, 5) == 0)
            return;
        this->setState(this->OrFunction(this->getState(5), new_state), 4);
        this->checker = set_data(this->checker, 4, 1);
        break;
    case 8:
        if (retrieve_data(this->checker, 9) == 0)
            return;
        this->setState(this->OrFunction(this->getState(9), new_state), 10);
        this->checker = set_data(this->checker, 10, 1);
        break;
    case 9:
        if (retrieve_data(this->checker, 8) == 0)
            return;
        this->setState(this->OrFunction(this->getState(8), new_state), 10);
        this->checker = set_data(this->checker, 10, 1);
        break;
    case 12:
        if (retrieve_data(this->checker, 13) == 0)
            return;
        this->setState(this->OrFunction(this->getState(13), new_state), 11);
        this->checker = set_data(this->checker, 11, 1);
        break;
    case 13:
        if (retrieve_data(this->checker, 12) == 0)
            return;
        this->setState(this->OrFunction(this->getState(12), new_state), 11);
        this->checker = set_data(this->checker, 11, 1);
        break;
    default:
        break;
    }
}
