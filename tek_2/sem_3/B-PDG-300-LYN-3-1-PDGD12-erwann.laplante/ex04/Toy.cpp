/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD12-erwann.laplante
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    _type = BASIC_TOY;
    _name = "toy";
    _picture = Picture();
}

Toy::Toy(ToyType type, std::string name, std::string filename)
{
    _type = type;
    _name = name;
    _picture = Picture(filename);
}

Toy::~Toy()
{
}

Toy::ToyType Toy::getType() const
{
    return _type;
}

std::string Toy::getName() const
{
    return _name;
}

void Toy::setName(std::string name)
{
    _name = name;
}

bool Toy::setAscii(std::string file_name)
{
    return _picture.getPictureFromFile(file_name);
}

std::string Toy::getAscii() const
{
    return _picture.data;
}

Toy &Toy::operator=(Toy const &toy)
{
    _type = toy.getType();
    _name = toy.getName();
    _picture.data = toy.getAscii();
    return *this;
}

void Toy::speak(std::string statement)
{
    if (_type == BUZZ)
        std::cout << "BUZZ: " << _name << " \"" << statement << "\"" << std::endl;
    else if (_type == WOODY)
        std::cout << "WOODY: " << _name << " \"" << statement << "\"" << std::endl;
    else
        std::cout << _name << " \"" << statement << "\"" << std::endl;
}

Toy &Toy::operator<<(std::string const &string)
{
    _picture.data = string;
    return *this;
}

std::ostream &operator<<(std::ostream &stream, Toy const &toy)
{
    stream << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return stream;
}
