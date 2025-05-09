/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD07am-erwann.laplante
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor()
{
    _stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

bool WarpSystem::QuantumReactor::isStable ()
{
    return _stability;
}

void WarpSystem::QuantumReactor::setStability (bool stability)
{
    _stability = stability;
}

WarpSystem::Core::Core(QuantumReactor *coreReactor)
{
    _coreReactor = coreReactor;
}

WarpSystem::Core::~Core()
{
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor(void)
{
    return _coreReactor;
}
