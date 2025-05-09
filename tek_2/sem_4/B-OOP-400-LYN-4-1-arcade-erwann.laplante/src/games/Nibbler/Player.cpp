/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Player
*/

#include "Nibbler.hpp"

Player::Player()
:   _speed(1), _length(4),_direction(LEFT), _position()
{
}

Player::Player(const Player &c)
:   _speed(c._speed), _length(c._length),
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

void Player::setDirection(Move moving)
{
    _direction = moving;
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

Player::Move Player::getDirection() const
{
    return (_direction);
}