/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-hugo.fleury
** File description:
** Texture
*/

#include "Texture.hpp"

Texture::Texture(std::string path, std::string symbol, std::pair<int, int> size, std::pair<int, int> pos)
{
    this->_path = path;
    this->_symbol = symbol;
    this->_xSize = size.first;
    this->_ySize = size.second;
    this->_xPos = pos.first;
    this->_yPos = pos.second;
}

std::string Texture::getPath(void) const
{
    return(this->_path);
}

int Texture::getxSize(void) const
{
    return(this->_xSize);
}

int Texture::getySize(void) const
{
    return(this->_ySize);
}

std::string Texture::getSymbol(void) const
{
    return(this->_symbol);
}

int Texture::getxPos(void) const
{
    return(this->_xPos);
}

int Texture::getyPos(void) const
{
    return(this->_yPos);
}

std::pair<float, float> Texture::getOrigin(void) const
{
    return(this->_origin);
}

void Texture::setOrigin(float x, float y)
{
    this->_origin = {x, y};
}