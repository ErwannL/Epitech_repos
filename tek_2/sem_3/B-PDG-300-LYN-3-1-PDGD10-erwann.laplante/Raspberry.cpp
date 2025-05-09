/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** Raspberry
*/

#include "Raspberry.hpp"

Raspberry::Raspberry() : AFruit::AFruit(), ABerry::ABerry()
{
    _name = "raspberry";
    _vitamins = 5;
}

Raspberry::~Raspberry()
{
}
