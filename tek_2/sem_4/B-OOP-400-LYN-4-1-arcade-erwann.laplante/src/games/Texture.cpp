/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Texture
*/

#include "Texture.hpp"

Texture::Texture(std::string path, std::string sym, std::pair<int, int> size, std::pair<int, int> pos)
:   _path(path), _symbol(sym), _xSize(size.first), _ySize(size.second),
    _xPos(pos.first), _yPos(pos.second)
{
}

Texture::~Texture()
{
}

int Texture::getxSize(void) const
{
    return (_xSize);
}

int Texture::getySize(void) const
{
    return (_ySize);
}

int Texture::getxPos(void) const
{
    return (_xPos);
}

int Texture::getyPos(void) const
{
    return (_yPos);
}

std::pair<float, float> Texture::getOrigin(void) const
{
    return (_origin);
}

std::string Texture::getPath(void) const
{
    return (_path);
}

std::string Texture::getSymbol(void) const
{
    return (_symbol);
}

void Texture::setOrigin(float x, float y)
{
    _origin = std::pair<float,float>(x, y);
}
