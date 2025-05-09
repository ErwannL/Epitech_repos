/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler()
:   _score(0), _size({19,19}), _player(Player())
{
    std::tuple<int, int> temp = {std::get<0>(_size) / 2, std::get<1>(_size) / 2};
    setRandomFruit();
    _player.setPosition(temp);
}

Nibbler::Nibbler(const Nibbler &cpy)
:   _score(0), _size(cpy._size), _fruitPos(cpy._fruitPos), _player(cpy._player)
{
}

Nibbler::~Nibbler()
{
}

void Nibbler::reset()
{
    _score = 0;
    _size = {15, 15};
    _player = Player();
    std::tuple<int, int> temp = {std::get<0>(_size) / 2, std::get<1>(_size) / 2};
    setRandomFruit();
    _player.setPosition(temp);
}

void Nibbler::setSize(std::tuple<int, int> s)
{
    _size = s;
}

void Nibbler::setRandomFruit()
{
    int x = rand() % (std::get<0>(getSize()) + 1);
    int y = rand() % (std::get<0>(getSize()) + 1);
    std::tuple<int, int> temp = {x, y};

    while (temp == _fruitPos) {
        x = rand() % (std::get<0>(getSize()) + 1);
        y = rand() % (std::get<0>(getSize()) + 1);
        temp = {x, y};
    }
    _fruitPos = temp;
}

void Nibbler::setFruitPos(std::tuple<int, int> pos)
{
    _fruitPos = pos;
}

std::tuple<int, int> Nibbler::getSize() const
{
    return (_size);
}

std::tuple<int, int> Nibbler::getFruit() const
{
    return (_fruitPos);
}

Player Nibbler::getPlayer()
{
    return (_player);
}
