/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** Lemon
*/

#include "Lemon.hpp"

Lemon::Lemon() : AFruit::AFruit(), ACitrus::ACitrus()
{
    _name = "lemon";
    _vitamins = 4;
}

Lemon::~Lemon()
{
}
