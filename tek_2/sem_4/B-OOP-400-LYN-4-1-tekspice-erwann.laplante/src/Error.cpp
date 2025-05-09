/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** error
*/

#include "IComponent.hpp"

nts::IComponent::Error::Error(ErrorType erreur)
{
    type = erreur;
}

nts::IComponent::Error::~Error()
{
}

const char *nts::IComponent::Error::what() const noexcept
{
    if (this->type == ARGUMENTS) {
        return "Need only 1 parameters : the configuration file";
    } else if (this->type == OPEN) {
        return "Can't open configuartion file";
    } else if (this->type == TYPE) {
        return "Unknown type in file";
    } else if (this->type == VALUE) {
        std::cerr << "Unknow component name '" + str + "'.";
        return "";
    } else if (this->type == DEC_NAME) {
        return "No name after déclaration";
    } else if (this->type == NAME) {
        return "Need a name in links";
    } else if (this->type == PIN) {
        return "Need a pin in links";
    } else if (this->type == DELI) {
        return "Need a \"component:pin component:pin\" for links";
    } else if (this->type == ALREADY) {
        return "Several components share the same name.";
    } else if (this->type == LINE) {
        return "Bad line detected";
    } else if (this->type == COMMAND) {
        std::cerr << "Unknow command '" + str + "'.";
        return "";
    } else if (this->type == C_TYPE) {
        std::cerr << "Unknow type '" + str + "'.";
        return "";
    } else if (this->type == MODIF) {
        return "Can only modify input or clock";
    } else if (this->type == NTS) {
        return "Configuration file must be .nts";
    } else if (this->type == NUM_PIN) {
        return "Unvalid pin in configuration file";
    } else if (this->type == NO_COMP) {
        return "No component defined.";
    } else {
        return "unknown error, please identify it !";
    }
}
