/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD09-erwann.laplante
** File description:
** Peasant
*/

#include "Peasant.hpp"

Peasant::Peasant(const std::string &name, int power) : _name(name)
{
    _power = power;
    std::cout << _name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << _name << " is back to his crops." << std::endl;
}

const std::string &Peasant::getName() const
{
    return _name;
}

int Peasant::getPower() const
{
    return _power;
}

int Peasant::getHp() const
{
    return _hp;
}

int Peasant::attack()
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else {
        if (_power < 10) {
            std::cout << _name << " is out of power." << std::endl;
            return 0;
        }
        _power -= 10;
        std::cout << _name << " tosses a stone." << std::endl;
        return 5;
    }
    return 0;
}

int Peasant::special()
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    std::cout << _name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else {
        _power += 30;
        if (_power > 100)
            _power = 100;
        std::cout << _name << " takes a nap." << std::endl;
    }
}

void Peasant::damage(int damage)
{
    _hp -= damage;
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        _hp = 0;
    } else
        std::cout << _name << " takes " << damage << " damage." << std::endl;
}

void Peasant::drink(const HealthPotion& potion)
{
    _hp += potion.getValue();
    if (_hp > 100)
        _hp = 100;
    std::cout << _name << " feels rejuvenated." << std::endl;
}

void Peasant::drink(const PowerPotion &potion)
{
    _power += potion.getValue();
    if (_power > 100)
        _power = 100;
    std::cout << _name << "'s power is restored." << std::endl;
}

void Peasant::drink(const PoisonPotion &potion)
{
    _hp -= potion.getValue();
    if (_hp < 0)
        _hp = 0;
    std::cout << _name << " has been poisoned." << std::endl;
}

void Peasant::drink(const IPotion &potion)
{
    std::cout << _name << " drinks a mysterious potion." << std::endl;
    if (potion.getType() == 0) {
        _hp += potion.getValue();
        if (_hp > 100)
            _hp = 100;
    } else if (potion.getType() == 1) {
        _hp -= potion.getValue();
        if (_hp < 0)
            _hp = 0;
    } else {
        _power += potion.getValue();
        if (_power > 100)
            _power = 100;
    }
}
