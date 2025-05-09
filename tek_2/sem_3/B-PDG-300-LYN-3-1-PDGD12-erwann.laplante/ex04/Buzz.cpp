/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD12-erwann.laplante
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name) : Toy::Toy(BUZZ, name, "buzz.txt")
{
}

Buzz::Buzz(std::string name, std::string ascii) : Toy::Toy(BUZZ, name, ascii)
{
}

Buzz::~Buzz()
{
}
