/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** Strawberry
*/

#include "Strawberry.hpp"

Strawberry::Strawberry() : AFruit::AFruit(), ABerry::ABerry()
{
    _name = "strawberry";
    _vitamins = 6;
}

Strawberry::~Strawberry()
{
}
