/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** Orange
*/

#include "Orange.hpp"

Orange::Orange() : AFruit::AFruit(), ACitrus::ACitrus()
{
    _name = "orange";
    _vitamins = 7;
}

Orange::~Orange()
{
}
