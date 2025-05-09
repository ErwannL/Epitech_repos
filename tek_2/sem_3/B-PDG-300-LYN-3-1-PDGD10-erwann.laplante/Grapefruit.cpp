/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** Grapefruit
*/

#include "Grapefruit.hpp"

Grapefruit::Grapefruit() : AFruit::AFruit(), ACitrus::ACitrus()
{
    _name = "grapefruit";
    _vitamins = 5;
}

Grapefruit::~Grapefruit()
{
}
