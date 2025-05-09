/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** My_4069
*/

#include "My_4069.hpp"

My_4069::My_4069()
{
    for (auto i = 0; i != 14; i++)
        state.push_back(nts::Undefined);
}

My_4069::~My_4069()
{
}

void My_4069::simulation(size_t first, nts::Tristate new_state, size_t pin)
{
    this->setState(new_state, pin);
    this->checker = set_data(this->checker, pin, 1);
    switch (pin)
    {
    case 1:
        this->setState(this->NotFunction(this->getState(1)), 2);
        this->checker = set_data(this->checker, 2, 1);
        break;
    case 3:
        this->setState(this->NotFunction(this->getState(3)), 4);
        this->checker = set_data(this->checker, 4, 1);
        break;
    case 5:
        this->setState(this->NotFunction(this->getState(5)), 6);
        this->checker = set_data(this->checker, 6, 1);
        break;
    case 9:
        this->setState(this->NotFunction(this->getState(9)), 8);
        this->checker = set_data(this->checker, 8, 1);
        break;
    case 11:
        this->setState(this->NotFunction(this->getState(11)), 10);
        this->checker = set_data(this->checker, 10, 1);
        break;
    case 13:
        this->setState(this->NotFunction(this->getState(13)), 12);
        this->checker = set_data(this->checker, 12, 1);
        break;
    default:
        break;
    }
}
