/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD09-erwann.laplante
** File description:
** Knight
*/

#include "Knight.hpp"

Knight::Knight(const std::string &name, int power) : Peasant::Peasant(name, power)
{
    std::cout << _name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << _name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else {
        if (_power < 10) {
            std::cout << _name << " is out of power." << std::endl;
            return 0;
        }
        _power -= 10;
        std::cout << _name << " strikes with his sword." << std::endl;
        return 20;
    }
    return 0;
}

int Knight::special()
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else {
        if (_power < 30) {
            std::cout << _name << " is out of power." << std::endl;
            return 0;
        }
        _power -= 30;
        std::cout << _name << " impales his enemy." << std::endl;
        return 50;
    }
    return 0;
}

void Knight::rest()
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else {
        _power += 50;
        if (_power > 100)
            _power = 100;
        std::cout << _name << " eats." << std::endl;
    }
}
