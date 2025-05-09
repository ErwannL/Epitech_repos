/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** AFruit
*/

#include "AFruit.hpp"

AFruit::AFruit()
{
}

AFruit::~AFruit()
{
}

unsigned int AFruit::getVitamins() const
{
    if (_peeled == true)
        return _vitamins;
    return 0;
}

std::string AFruit::getName() const
{
    return _name;
}

bool AFruit::isPeeled() const
{
    return _peeled;
}

void AFruit::peel()
{
    if (_peeled == false)
        _peeled = true;
}
