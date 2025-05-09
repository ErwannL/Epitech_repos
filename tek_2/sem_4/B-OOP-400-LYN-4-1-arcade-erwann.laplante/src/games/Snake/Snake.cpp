/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-erwann.laplante
** File description:
** Snake
*/

#include "Snake.hpp"

extern "C" std::shared_ptr<Snake> init(void)
{
    return std::make_shared<Snake>();
}

Snake::Snake()
:   _score(0), _size({15, 15}), _player(Player())
{
    setRandomFruit();
    _player.setPosition({7, 7});
}

Snake::Snake(const Snake &cpy)
:   _score(0), _size(cpy._size), _fruitPos(cpy._fruitPos), _player(cpy._player)
{
}

Arcade::Type Snake::getTypeClass (void)
{
    return this->what;
}

void Snake::setInput(std::pair<std::string, bool> temp)
{
    _input = temp;
}

void Snake::reset()
{
    _score = 0;
    _size = {15, 15};
    _player = Player();
    std::tuple<int, int> temp = {std::get<0>(_size) / 2, std::get<1>(_size) / 2};
    setRandomFruit();
    _player.setPosition(temp);
}

void Snake::setSize(std::tuple<int, int> s)
{
    _size = s;
}

void Snake::setRandomFruit()
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

void Snake::setFruitPos(std::tuple<int, int> pos)
{
    _fruitPos = pos;
}

std::tuple<int, int> Snake::getSize() const
{
    return (_size);
}

std::tuple<int, int> Snake::getFruit() const
{
    return (_fruitPos);
}

void Snake::setMap(Sprite &sprite, std::string name)
{
    _spriteMap.insert(std::pair<std::string, Sprite>(name, sprite));
}


std::map<std::string, Sprite> &Snake::getMapSprite(void)
{
    return (_spriteMap);
}

Player Snake::getPlayer()
{
    return (_player);
}
