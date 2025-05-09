/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD09-erwann.laplante
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int power) : Peasant::Peasant(name, power), Knight::Knight(name, power), Enchanter::Enchanter(name, power), Priest::Priest(name, power)
{
    std::cout << _name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << _name << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return Knight::attack();
}

int Paladin::special()
{
    return Enchanter::special();
}

void Paladin::rest()
{
    Priest::rest();
}
