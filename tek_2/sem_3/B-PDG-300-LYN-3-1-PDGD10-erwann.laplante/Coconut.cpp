/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** Coconut
*/

#include "Coconut.hpp"

Coconut::Coconut() : AFruit::AFruit(), ANut::ANut()
{
    _name = "coconut";
    _vitamins = 4;
}

Coconut::~Coconut()
{
}
