/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD07am-erwann.laplante
** File description:
** Borg
*/

#include "Borg.hpp"

Borg::Ship::Ship (int weaponFrequency, short repair)
{
    _side = 300;
    _maxWarp = 9;
    _home = UNICOMPLEX;
    _location = _home;
    _shield = 100;
    _weaponFrequency = weaponFrequency;
    _repair = repair;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}

void Borg::Ship::checkCore(void)
{
    std::cout << ((_core->checkReactor()->isStable() == true) ? "Everything is in order." : "Critical failure imminent.") << std::endl;
}

bool Borg::Ship::move (int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move (int warp)
{
    if (warp <= _maxWarp && _home != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return true;
    }
    return false;
}

bool Borg::Ship::move (Destination d)
{
    if (d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move ()
{
    if (_home != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return true;
    }
    return false;
}

int Borg::Ship::getShield()
{
    return _shield;
}

void Borg::Ship::setShield (int shield)
{
    _shield = shield;
}

int Borg::Ship::getWeaponFrequency ()
{
    return _weaponFrequency;
}

void Borg::Ship::setWeaponFrequency (int frequency)
{
    _weaponFrequency = frequency;
}

short Borg::Ship::getRepair ()
{
    return _repair;
}

void Borg::Ship::setRepair (short repair)
{
    _repair = repair;
}

void Borg::Ship::fire (Federation::Starfleet::Ship *target)
{
    target->setShield(target->getShield() - _weaponFrequency);
    std::cout << "Firing on target with " << _weaponFrequency << " GW frequency ." << std::endl;
}

void Borg::Ship::fire (Federation::Ship *target)
{
    target->getCore()->checkReactor()->setStability(false);
    std::cout << "Firing on target with " << _weaponFrequency << " GW frequency ." << std::endl;
}

void Borg::Ship::repair ()
{
    if (_repair > 0) {
        _repair -= 1;
        _shield = 100;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions."<< std::endl;
    } else {
        std::cout << "Energy cells depleted, shield weakening ."<< std::endl;
    }
}
