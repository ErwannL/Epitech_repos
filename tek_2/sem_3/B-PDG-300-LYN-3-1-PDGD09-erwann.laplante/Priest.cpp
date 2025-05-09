/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD09-erwann.laplante
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int power) : Peasant::Peasant(name, power), Enchanter::Enchanter(name, power)
{
    std::cout << _name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << _name << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else {
        _hp += 100;
        if (_hp > 100)
            _hp = 100;
        _power += 100;
        if (_power > 100)
            _power = 100;
        std::cout << _name << " prays." << std::endl;
    }
}
