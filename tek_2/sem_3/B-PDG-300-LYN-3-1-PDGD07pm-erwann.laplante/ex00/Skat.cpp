/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD07pm-erwann.laplante
** File description:
** Skat
*/

#include "Skat.hpp"

Skat::Skat (const std::string &name, int stimPaks)
{
    _name = name;
    _stimPaks = stimPaks;
}

Skat::Skat ()
{
    _name = "bob";
    _stimPaks = 15;
}

Skat::~Skat()
{
}

int &Skat::stimPaks ()
{
    return _stimPaks;
}

const std::string &Skat::name ()
{
    return _name;
}

void Skat::shareStimPaks (int number, int &stock)
{
    if (number <= _stimPaks) {
        stock += number;
        _stimPaks -= number;
        std::cout << "Keep the change." << std::endl;
    } else {
        std::cout << "Don't be greedy" << std::endl;
    }
}

void Skat::addStimPaks (unsigned int number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
    }
    _stimPaks += number;
}

void Skat::useStimPaks ()
{
    if (_stimPaks > 0) {
        _stimPaks -= 1;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    } else {
        std::cout << "Mediiiiiic" << std::endl;
    }
}

void Skat::status ()
{
    std::cout << "Soldier " << _name <<" reporting " << _stimPaks << " stimpaks remaining sir!" << std::endl;
}
