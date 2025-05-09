/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD08-erwann.laplante
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
{
    Exp = 0;
    Fingerprint = (size_t)random();
}

DroidMemory::~DroidMemory()
{
}

size_t DroidMemory::getFingerprint() const
{
    return Fingerprint;
}

size_t DroidMemory::getExp() const
{
    return Exp;
}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    Fingerprint = fingerprint;
}

void DroidMemory::setExp(size_t exp)
{
    Exp = exp;
}

DroidMemory &DroidMemory::operator<<(DroidMemory const &droid)
{
    Exp += droid.getExp();
    Fingerprint = droid.getFingerprint() ^ Fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &droid)
{
    droid.setExp(droid.getExp() + Exp);
    droid.setFingerprint(Fingerprint ^ droid.getFingerprint());
    return droid;
}

DroidMemory &DroidMemory::operator+=(DroidMemory const &droid)
{
    return operator<<(droid);
}

DroidMemory &DroidMemory::operator+=(size_t add)
{
    Exp += add;
    Fingerprint = add ^ Fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+(DroidMemory const &droid)
{
    DroidMemory *new_one = new DroidMemory();

    new_one->Exp = Exp + droid.getExp();
    new_one->Fingerprint = Fingerprint ^ droid.getFingerprint();
    return *new_one;
}

DroidMemory &DroidMemory::operator+(size_t add)
{
    DroidMemory *new_one = new DroidMemory();

    new_one->Exp = Exp + add;
    new_one->Fingerprint = add ^ Fingerprint;
    return *new_one;
}

std::ostream &operator<<(std::ostream &stream, DroidMemory const &droid)
{
  stream << "DroidMemory '" << droid.getFingerprint() << "', " << droid.getExp();
  return stream;
}

DroidMemory::DroidMemory(DroidMemory const &droid)
{
    Exp = droid.getExp();
    Fingerprint = droid.getFingerprint();
}

DroidMemory &DroidMemory::operator=(DroidMemory const &droid)
{
    Fingerprint = droid.getFingerprint();
    Exp = droid.getExp();
    return *this;
}
