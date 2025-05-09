/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD07am-erwann.laplante
** File description:
** Federation
*/

#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = maxWarp;
    _home = EARTH;
    _location = _home;
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
    _shield = 100;
    _photonTorpedo = torpedo;
    if (_photonTorpedo != 0)
        std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    _length = length;
    _width = width;
    _name = name;
    _home = VULCAN;
    _location = _home;
    std::cout << "The independent ship " << _name << " just finished its construction." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore(void)
{
    std::cout << "USS " << _name << ": The core is " << ((_core->checkReactor()->isStable() == true) ? "stable" : "unstable") <<" at the time." << std::endl;
}

void Federation::Ship::checkCore(void)
{
    std::cout << _name << ": The core is " << ((_core->checkReactor()->isStable() == true) ? "stable" : "unstable") <<" at the time." << std::endl;
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    _name = name;
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName ()
{
    return _name;
}

int Federation::Starfleet::Captain::getAge ()
{
    return _age;
}

void Federation::Starfleet::Captain::setAge (int age)
{
    _age = age;
}

void Federation::Starfleet::Ship::promote (Captain *captain)
{
    _captain = captain->getName();
    std::cout << _captain << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    _name = name;
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}

bool Federation::Ship::move (int warp, Destination d)
{
    if (warp <= 1 && d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move (int warp)
{
    if (warp <= 1 && _home != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Ship::move (Destination d)
{
    if (d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move ()
{
    if (_home != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move (int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move (int warp)
{
    if (warp <= _maxWarp && _home != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move (Destination d)
{
    if (d != _location && _core->checkReactor()->isStable() == true) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move ()
{
    if (_home != _location && _core->checkReactor()->isStable() == true) {
        _location = _home;
        return true;
    }
    return false;
}

int Federation::Starfleet::Ship::getShield ()
{
    return _shield;
}

void Federation::Starfleet::Ship::setShield (int shield)
{
    _shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo ()
{
    return _photonTorpedo;
}

void Federation::Starfleet::Ship::setTorpedo (int torpedo)
{
    _photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire (Borg::Ship *target)
{
    if (_photonTorpedo >= 1) {
        _photonTorpedo -= 1;
        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() - (1 * 50));
        if (_photonTorpedo <= 0)
            std::cout << _name << ": No more torpedo to fire, " << _captain << "!" << std::endl;
    } else {
        std::cout << _name << ": No enough torpedoes to fire, " << _captain << "!" << std::endl;
    }
}

void Federation::Starfleet::Ship::fire (int torpedoes, Borg::Ship *target)
{
    if (_photonTorpedo >= torpedoes) {
        _photonTorpedo -= torpedoes;
        std::cout << _name << ": Firing on target. " << _photonTorpedo << "torpedoes remaining." << std::endl;
        target->setShield(target->getShield() - (torpedoes * 50));
        if (_photonTorpedo <= 0)
            std::cout << _name << ": No more torpedo to fire, " << _captain << "!" << std::endl;
    } else {
        std::cout << _name << ": No enough torpedoes to fire, " << _captain << "!" << std::endl;
    }
}

WarpSystem::Core *Federation::Ship::getCore(void)
{
    return _core;
}
