/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** IFruit
*/

#include "IFruit.hpp"


std::ostream &operator<<(std::ostream &stream, IFruit const &fruit)
{
    stream << "[name: \"" << fruit.getName() << "\", vitamins: " << fruit.getVitamins() << ", peeled: " << ((fruit.isPeeled() == true) ? "true]" : "false]");
    return stream;
}
