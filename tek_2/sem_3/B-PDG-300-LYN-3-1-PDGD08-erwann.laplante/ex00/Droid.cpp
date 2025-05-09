/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD08-erwann.laplante
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string id) : Attack(25), Toughness(15)
{
    Id = id;
    Energy = 50;
    Status = new std::string ("Standing by");
    std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &droid) : Id {droid.getId()}, Energy {droid.getEnergy()}, Attack(25), Toughness(15), Status{new std::string (*droid.getStatus())}
{
    std::cout << "Droid '" << Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    delete Status;
    std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
}

std::string Droid::getId() const
{
    return Id;
}

void Droid::setId(std::string id)
{
    Id = id;
}

size_t Droid::getEnergy() const
{
    return Energy;
}

void Droid::setEnergy(size_t energy)
{
    Energy = energy;
    if (Energy > 100)
        Energy = 100;
}

std::string *Droid::getStatus() const
{
    return Status;
}

void Droid::setStatus(std::string *status)
{
    Status = status;
}

size_t Droid::getAttack() const
{
  return Attack;
}

size_t Droid::getToughness() const
{
  return Toughness;
}

bool Droid::operator==(Droid const &droid) const
{
    if (Id == droid.getId() && Energy == droid.getEnergy() && *Status == *droid.getStatus())
        return true;
    return false;
}

bool Droid::operator!=(Droid const &droid) const
{
    if (operator==(droid) == true)
        return false;
    return true;
}

Droid &Droid::operator<<(size_t &want_reload)
{
    size_t to_reload = want_reload;

    if (Energy >= 100) {
        Energy = 100;
        return *this;
    }
    if (Energy + want_reload >= 100) {
        to_reload = 100 - Energy;
    }
    Energy += to_reload;
    want_reload -= to_reload;
    return *this;
}

Droid &Droid::operator=(Droid const &droid)
{
    if (&droid == this)
        return *this;
    Id = droid.getId();
    Energy = droid.getEnergy();
    if (Status != NULL)
        delete Status;
    Status = new std::string(*droid.getStatus());
    return *this;
}

std::ostream &operator<<(std::ostream &stream, Droid const &droid)
{
  stream << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
  return stream;
}
