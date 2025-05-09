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
    BattleData = new DroidMemory();
    std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &droid) : Attack(droid.getAttack()), Toughness(droid.getToughness())
{
    Id = droid.getId();
    Energy = 50;
    Status = new std::string (*droid.getStatus());
    BattleData = new DroidMemory (*droid.getBattleData());
    std::cout << "Droid '" << Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    if (Status != NULL)
        delete Status;
    if (BattleData != NULL)
        delete BattleData;
    std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
}

std::string Droid::getId() const
{
    return Id;
}

void Droid::setId(std::string const &id)
{
    Id = id;
}

size_t Droid::getEnergy() const
{
    return Energy;
}

void Droid::setEnergy(size_t const &energy)
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
    if (Status != NULL)
        delete Status;
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
    if (*Status == *droid.getStatus())
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
    Status = new std::string (*droid.getStatus());
    if (BattleData != NULL)
        delete BattleData;
    BattleData = new DroidMemory (*droid.getBattleData());
    return *this;
}

std::ostream &operator<<(std::ostream &stream, Droid const &droid)
{
  stream << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
  return stream;
}

DroidMemory *Droid::getBattleData() const
{
    return BattleData;
}

void Droid::setBattleData(DroidMemory *battleData)
{
    if (BattleData != NULL)
        delete BattleData;
    BattleData = battleData;
}

bool Droid::operator()(const std::string *task, size_t exp_req)
{
    if (Energy <= 10) {
        Energy = 0;
        setStatus(new std::string("Battery Low"));
        return false;
    }
    Energy -= 10;
    if (BattleData->getExp() >= exp_req) {
        setStatus(new std::string(*task + " - Completed!"));
        BattleData->setExp(BattleData->getExp() + exp_req / 2);
        return true;
    }
    setStatus(new std::string(*task + " - Failed!"));
    BattleData->setExp(BattleData->getExp() + exp_req);
    return false;
}
