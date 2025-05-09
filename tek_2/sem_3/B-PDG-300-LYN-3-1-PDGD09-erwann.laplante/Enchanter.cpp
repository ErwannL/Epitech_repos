/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD09-erwann.laplante
** File description:
** Enchanter
*/

#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string &name, int power) : Peasant::Peasant(name, power)
{
    std::cout << _name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << _name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else {
        std::cout << _name << " doesn't know how to fight." << std::endl;
    }
    return 0;
}

int Enchanter::special()
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else {
        if (_power < 50) {
            std::cout << _name << " is out of power." << std::endl;
            return 0;
        }
        _power -= 50;
        std::cout << _name << " casts a fireball." << std::endl;
        return 99;
    }
    return 0;
}

void Enchanter::rest()
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else {
        _power += 100;
        if (_power > 100)
            _power = 100;
        std::cout << _name << " meditates." << std::endl;
    }
}
