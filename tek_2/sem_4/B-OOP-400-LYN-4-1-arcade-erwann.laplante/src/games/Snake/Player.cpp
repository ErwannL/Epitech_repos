/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Player
*/

#include "Snake.hpp"

Snake_part::Snake_part(Move dir, std::tuple<int, int> pos)
: _direction(dir), _pos(pos)
{
}

Snake_part::Snake_part(const Snake_part &cpy)
:   _pos(cpy._pos), _direction(cpy._direction)
{
}

Snake_part::~Snake_part()
{
}

Player::Player()
:   _speed(1), _length(4),_direction(LEFT), _position()
{
    _snake.insert(std::pair<int, Snake_part>(1, Snake_part(LEFT, {7, 7})));
    _snake.insert(std::pair<int, Snake_part>(2,Snake_part(LEFT, {7, 8})));
    _snake.insert(std::pair<int, Snake_part>(3, Snake_part(LEFT, {7, 9})));
    _snake.insert(std::pair<int, Snake_part>(4,Snake_part(LEFT, {7, 10})));
}

Player::Player(const Player &c)
:   _speed(c._speed), _length(c._length), _snake(c._snake),
    _position(c._position), _direction(c._direction)
{
}

Player::~Player()
{
}

void Player::setPosition(std::tuple<int, int> pos)
{
    _position = pos;
}

void Player::setSpeed(int x)
{
    _speed = x;
}

void Player::setDirection(Move temp)
{
    _direction = temp;
}

void Player::setLength(int len)
{
    _length = len;
}

std::tuple<int, int> Player::getPosition() const
{
    return (_position);
}

int Player::getSpeed() const
{
    return (_speed);
}

int Player::getLength() const
{
    return (_length);
}

Move Player::getDirection() const
{
    return (_direction);
}