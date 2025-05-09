/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-hugo.fleury
** File description:
** Sprite
*/

#include "Sprite.hpp"

Sprite::Sprite(std::string name, int xPos, int yPos, Texture &texture)
{
    this->name = name;
    this->_xPos = xPos;
    this->_yPos = yPos;
    this->_texture.push_back(texture);
}

Sprite::~Sprite()
{
}

std::vector<Texture> Sprite::getTexture(void) const
{
    return(this->_texture);
}

int Sprite::getxPos(void) const
{
    return(this->_xPos);
}

int Sprite::getyPos(void) const
{
    return(this->_yPos);
}

std::string Sprite::getName(void) const
{
    return(this->name);
}

std::pair<std::string, int> Sprite::getCollide(void) const
{
    return (this->_collide);
}

void Sprite::setCollide(std::pair<std::string, int> collide)
{
    this->_collide.first = collide.first;
    this->_collide.second = collide.second;
}

int Sprite::getFacing(void) const
{
    return(this->_facing);
}

void Sprite::setFacing(int facing)
{
    this->_facing = facing;
}

void Sprite::setPos(std::pair<int, int> pos)
{
    this->_xPos = pos.first;
    this->_yPos = pos.second;
}

void Sprite::setTextureOrigin(float x, float y)
{
    this->_texture[0].setOrigin(x, y);
}
