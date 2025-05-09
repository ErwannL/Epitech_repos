/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** Almond
*/

#include "Almond.hpp"

Almond::Almond() : AFruit::AFruit(),  ANut::ANut()
{
    _name = "almond";
    _vitamins = 2;
}

Almond::~Almond()
{
}
