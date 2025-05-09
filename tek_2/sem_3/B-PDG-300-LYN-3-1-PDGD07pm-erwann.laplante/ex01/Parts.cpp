/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD07pm-erwann.laplante
** File description:
** Parts
*/

#include "Parts.hpp"

Arms::Arms(std::string serial, bool functional)
{
    _serial = serial;
    _functionnal = functional;
}

Arms::~Arms()
{
}

Legs::Legs(std::string serial, bool functional)
{
    _serial = serial;
    _functionnal = functional;
}

Legs::~Legs()
{
}

Head::Head(std::string serial, bool functional)
{
    _serial = serial;
    _functionnal = functional;
}

Head::~Head()
{
}

bool Arms::isFunctional() const
{
    return _functionnal;
}

bool Legs::isFunctional() const
{
    return _functionnal;
}

bool Head::isFunctional() const
{
    return _functionnal;
}

std::string Arms::serial() const
{
    return _serial;
}

std::string Legs::serial() const
{
    return _serial;
}

std::string Head::serial() const
{
    return _serial;
}

void Arms::informations() const
{
    std::cout << "\t[Parts] Arms " << _serial << " status : " << ((_functionnal == true) ? "OK" : "KO") << std::endl;
}

void Legs::informations() const
{
    std::cout << "\t[Parts] Legs " << _serial << " status : " << ((_functionnal == true) ? "OK" : "KO") << std::endl;
}

void Head::informations() const
{
    std::cout << "\t[Parts] Head " << _serial << " status : " << ((_functionnal == true) ? "OK" : "KO") << std::endl;
}
