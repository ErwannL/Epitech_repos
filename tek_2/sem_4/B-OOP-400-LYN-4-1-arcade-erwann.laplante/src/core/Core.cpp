/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-erwann.laplante
** File description:
** Core
*/

#include "Core.hpp"

Arcade::Core::Core()
{
}

Arcade::Core::~Core()
{
}

void Arcade::Core::addGraphicalLib(std::string str)
{
    this->graphical_lib.push_back(str);
}

void Arcade::Core::addGameLib(std::string str)
{
    this->game_lib.push_back(str);
}

std::vector<std::string> Arcade::Core::getGraphicalLib(void) const
{
    return this->graphical_lib;
}

std::vector<std::string> Arcade::Core::getGameLib(void) const
{
    return this->game_lib;
}
