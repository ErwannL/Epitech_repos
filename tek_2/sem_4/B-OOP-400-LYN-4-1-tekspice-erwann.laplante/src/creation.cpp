/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** creation
*/

#include "My_4011.hpp"
#include "My_4081.hpp"
#include "My_4001.hpp"
#include "My_4071.hpp"
#include "My_4030.hpp"
#include "My_4069.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Clock.hpp"

std::unique_ptr<nts::IComponent> Component::createComponent(const std::string &type)
{
    std::unique_ptr<nts::IComponent> tmp;

    if (type == "input")
        tmp = createInput();
    else if (type == "output")
        tmp = createOutput();
    else if (type == "clock")
        tmp = createClock();
    else if (type == "true")
        tmp = createTrue();
    else if (type == "false")
        tmp = createFalse();
    else if (type == "and")
        tmp = createAnd();
    else if (type == "or")
        tmp = createOr();
    else if (type == "xor")
        tmp = createXor();
    else if (type == "not")
        tmp = createNot();
    else if (type == "4011")
        tmp = create4011();
    else if (type == "4081")
        tmp = create4081();
    else if (type == "4001")
        tmp = create4001();
    else if (type == "4071")
        tmp = create4071();
    else if (type == "4030")
        tmp = create4030();
    else if (type == "4069")
        tmp = create4069();
    else
        throw nts::IComponent::Error(nts::IComponent::Error::TYPE);
    return move(tmp);
}

std::unique_ptr<nts::IComponent> Component::createInput() const
{
    std::unique_ptr<Input> tmp;
    return move(tmp);
}

std::unique_ptr<nts::IComponent> Component::createOutput() const
{
    std::unique_ptr<Output> tmp;
    return move(tmp);
}

std::unique_ptr<nts::IComponent> Component::createTrue() const
{
    std::unique_ptr<True> tmp;
    return move(tmp);
}

std::unique_ptr<nts::IComponent> Component::createFalse() const
{
    std::unique_ptr<False> tmp;
    return move(tmp);
}

std::unique_ptr<nts::IComponent> Component::createClock() const
{
    std::unique_ptr<Clock> tmp;
    return move(tmp);
}

std::unique_ptr<nts::IComponent> Component::createAnd() const
{
    std::unique_ptr<And> tmp;
    return move(tmp);
}

std::unique_ptr<nts::IComponent> Component::createOr() const
{
    std::unique_ptr<Or> tmp;
    return move(tmp);
}

std::unique_ptr<nts::IComponent> Component::createXor() const
{
    std::unique_ptr<Xor> tmp;
    return move(tmp);
}

std::unique_ptr<nts::IComponent> Component::createNot() const
{
    std::unique_ptr<Not> tmp;
    return move(tmp);
}

std::unique_ptr<nts::IComponent> Component::create4011() const
{
    std::unique_ptr<My_4011> tmp;
    return move(tmp);
}

std::unique_ptr<nts::IComponent> Component::create4081() const
{
    std::unique_ptr<My_4081> tmp;
    return move(tmp);
}

std::unique_ptr<nts::IComponent> Component::create4001() const
{
    std::unique_ptr<My_4001> tmp;
    return move(tmp);
}

std::unique_ptr<nts::IComponent> Component::create4071() const
{
    std::unique_ptr<My_4071> tmp;
    return move(tmp);
}

std::unique_ptr<nts::IComponent> Component::create4030() const
{
    std::unique_ptr<My_4081> tmp;
    return move(tmp);
}

std::unique_ptr<nts::IComponent> Component::create4069() const
{
    std::unique_ptr<My_4069> tmp;
    return move(tmp);
}
