/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD12-erwann.laplante
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(std::string name) : Toy::Toy(WOODY, name, "woody.txt")
{
}

Woody::Woody(std::string name, std::string ascii) : Toy::Toy(WOODY, name, ascii)
{
}

Woody::~Woody()
{
}
