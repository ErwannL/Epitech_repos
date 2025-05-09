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
    if (_picture.getPictureFromFile(file_name) == true)
        return true;
    else {
        _error.type = Error::PICTURE;
        return false;
    }
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

bool Toy::speak(const std::string &statement)
{
    if (_type == BUZZ)
        std::cout << "BUZZ: " << _name << " \"" << statement << "\"" << std::endl;
    else if (_type == WOODY)
        std::cout << "WOODY: " << _name << " \"" << statement << "\"" << std::endl;
    else
        std::cout << _name << " \"" << statement << "\"" << std::endl;
    return true;
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

bool Toy::speak_es(const std::string &statement)
{
    if (_type == BUZZ) {
        std::cout << "BUZZ: " << _name << " senorita \"" << statement << "\" senorita" << std::endl;
        return true;
    }
    _error.type = Error::SPEAK;
    return false;
}

Toy::Error::Error()
{
    type = UNKNOWN;
}

Toy::Error::~Error()
{
}

std::string Toy::Error::what() const noexcept
{
    if (this->type == UNKNOWN)
        return "";
    else if (this->type == PICTURE)
        return "bad new illustration";
    else
        return "wrong mode";
}

std::string Toy::Error::where() const noexcept
{
    if (this->type == UNKNOWN)
        return "";
    else if (this->type == PICTURE)
        return "setAscii";
    else
        return "speak_es";
}

Toy::Error Toy::getLastError() const
{
    return _error;
}
