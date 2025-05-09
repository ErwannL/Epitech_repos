/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Sprite
*/

#include "Sprite.hpp"

Sprite::Sprite(std::string name, int x, int y, Texture &text)
:   _name(name), _xPos(x), _yPos(y)
{
    std::vector<Texture> vect;
    vect.push_back(text);
    _texture = vect;
}

Sprite::~Sprite()
{
}

std::string Sprite::getName(void) const
{
    return (_name);
}

int Sprite::getxPos(void) const
{
    return (_xPos);
}

int Sprite::getyPos(void) const
{
    return (_yPos);
}

int Sprite::getFacing(void) const
{
    return (_facing);
}

std::vector<Texture> Sprite::getTexture(void) const
{
    return (_texture);
}

std::pair<std::string, int> Sprite::getCollide() const
{
    return (_collide);
}

void Sprite::setPos(std::pair<int, int> pos)
{
    _xPos = pos.first;
    _yPos = pos.second;
}

void Sprite::setCollide(std::pair<std::string, int> col)
{
    _collide = col;
}

void Sprite::setFacing(int face)
{
    _facing = face;
}

void Sprite::setTextureOrigin(float x, float y)
{
    _texture[0].setOrigin(x, y);
}
