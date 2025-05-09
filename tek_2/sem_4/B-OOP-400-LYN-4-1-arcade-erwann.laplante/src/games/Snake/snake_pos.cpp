/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Fruit
*/

#include "Snake.hpp"

void Snake::snake_move()
{
    Move dir = getPlayer().getDirection();
    std::tuple<int, int> pos = getPlayer().getPosition();

    switch (dir) {
        case LEFT :
            getPlayer().setPosition({std::get<0>(pos) - _player.getSpeed(), std::get<1>(pos)});
        case RIGHT :
            getPlayer().setPosition({std::get<0>(pos) + _player.getSpeed(), std::get<1>(pos)});
        case UP :
            getPlayer().setPosition({std::get<0>(pos), std::get<1>(pos) - _player.getSpeed()});
        case DOWN :
            getPlayer().setPosition({std::get<0>(pos), std::get<1>(pos) + _player.getSpeed()});
    }
}

std::tuple<int, int> Snake::getNewTuple(std::tuple<int, int> tuple, Move dir)
{
    int x = std::get<0>(tuple);
    int y = std::get<1>(tuple);
    switch (dir) {
        case LEFT:
            return {x, y-1};
        case RIGHT:
            return {x, y+1};
        case UP:
            return {x-1, y};
        case DOWN:
            return {x+1, y};
    }
}

bool Snake::fruit_and_snake(void)
{
    return (_fruitPos == _player.getPosition());
}

bool Snake::snake_in_wall(void)
{
    int x = std::get<0>(_player.getPosition());
    int y = std::get<1>(_player.getPosition());
    std::tuple<int,int> tuple = {x, y};
    int x_max = std::get<0>(_size);
    int y_max = std::get<1>(_size);

    if (x < 0 || y < 0)
        return true;
    if (x_max < x || y_max < y)
        return true;
    for (int i = 1; i <= _player._snake.size(); i++) {
        if (_player._snake.find(i)->second.getPos() == tuple)
            return true;
    }
    return false;
}

