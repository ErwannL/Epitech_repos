/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** BloodOrange
*/

#include "BloodOrange.hpp"

BloodOrange::BloodOrange() : AFruit::AFruit(), ACitrus::ACitrus(), Orange::Orange()
{
    _name = "blood orange";
    _vitamins = 6;
}

BloodOrange::~BloodOrange()
{
}
