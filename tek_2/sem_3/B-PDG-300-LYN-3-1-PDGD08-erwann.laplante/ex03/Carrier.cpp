/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD08-erwann.laplante
** File description:
** Carrier
*/

#include "Carrier.hpp"

Carrier::Carrier(std::string id)
{
    Id = id;
    for (int i = 0; i != 5; i++)
        Droids[i] = NULL;
}

Carrier::~Carrier()
{
    for (int i = 0; i != 5; i++) {
        if (Droids[i] != NULL)
            delete Droids[i];
    }
}

std::string Carrier::getId() const
{
    return Id;
}

size_t Carrier::getEnergy() const
{
    return Energy;
}

size_t Carrier::getSpeed() const
{
    return Speed;
}

void Carrier::setId(std::string new_id)
{
    Id = new_id;
}

void Carrier::setEnergy(size_t  new_energy)
{
    Energy = new_energy;
}

void Carrier::setSpeed(size_t new_speed)
{
    Speed = new_speed;
}

Carrier &Carrier::operator<<(Droid *&droid)
{
    int nbr = 0;

    for (int i = 0; i != 5; i++) {
        if (Droids[i] == NULL) {
            Droids[i] = droid;
            droid = NULL;
            for (int i = 0; i != 5; i++) {
                if (Droids[i] != NULL)
                    nbr += 1;
            }
            if (nbr == 0)
                Speed = 0;
            else
                Speed = 100 - nbr * 10;
            return *this;
        }
    }
    return *this;
}

Carrier &Carrier::operator>>(Droid *&droid)
{
    int nbr = 0;

    for (int i = 0; i != 5; i++) {
        if (Droids[i] != NULL) {
            droid = Droids[i];
            Droids[i] = NULL;
            for (int i = 0; i != 5; i++) {
                if (Droids[i] != NULL)
                    nbr += 1;
            }
            if (nbr == 0)
                Speed = 0;
            else
                Speed = 100 - nbr * 10;
            return *this;
        }
    }
    return *this;
}

Droid *& Carrier::operator[](const size_t &where)
{
    return Droids[where];
}

Carrier &Carrier::operator~()
{
    int nbr = 0;

    for (int i = 0; i != 5; i++) {
        if (Droids[i] != NULL)
            nbr += 1;
    }
    if (nbr == 0)
        Speed = 0;
    else
        Speed = 100 - nbr * 10;
  return *this;
}

bool Carrier::operator()(const int &x, const int &y)
{
    int nbr = 0;

    for (int i = 0; i != 5; i++) {
        if (Droids[i] != NULL)
            nbr += 1;
    }
    if (Speed == 0 || Energy < (size_t)(std::abs(x) + std::abs(y)) * (10 + nbr))
        return false;
    Energy -= (std::abs(x) + std::abs(y)) * (10 + nbr);
    return true;
}

Carrier &Carrier::operator<<(size_t &want_reload)
{
    size_t to_reload = want_reload;

    if (Energy >= 600) {
        Energy = 600;
        return *this;
    }
    if (Energy + want_reload >= 600) {
        to_reload = 600 - Energy;
    }
    Energy += to_reload;
    want_reload -= to_reload;
    return *this;
}

std::ostream &Carrier::informations(std::ostream &stream) const
{
    stream << "Carrier '" << getId() << "' Droid(s) on-board:" << std::endl;
    for (size_t i = 0; i < 5; i++)
    {
        stream << "[" << i << "] : ";
        if (Droids[i] == NULL)
            stream << "Free";
        else
            stream << *Droids[i];
        stream << std::endl;
    }
    stream << "Speed : " << getSpeed() << ", Energy " << getEnergy();
    return stream;
}

std::ostream &operator<<(std::ostream &stream, Carrier const &carrier)
{
    return carrier.informations(stream);
}
