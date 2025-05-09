/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** Component
*/

#include "Component.hpp"

Component::Component()
{
    checker.assign(14, 0);
}

Component::~Component()
{
}

void Component::simulate(std::size_t tick)
{
}

nts::Tristate Component::compute(std::size_t pin)
{
    return nts::Undefined;
}

void Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    std::tuple<nts::IComponent *, std::size_t> temp = {&other, otherPin};

    Links[pin] = temp;
}

void Component::setLinkBi(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    setLink(pin, other, otherPin);
    other.setLink(otherPin, *this, pin);
}

void Component::setType(std::string new_type)
{
    type = new_type;
}

void Component::setName(std::string new_name)
{
    name = new_name;
}
std::list<int> Component::getChecker(void)
{
    return this->checker;
}
void Component::setState(nts::Tristate new_state, std::size_t pin)
{
    int i = 0;
    for (auto size = state.size(); size != 0; size--) {
        if (i == pin - 1)
            state.push_back(new_state);
        else
            state.push_back(state.front());
        state.pop_front();
        i++;
    }
}

int Component::retrieve_data(std::list<int> _checker, int x)
{
    int end;
    for (int i = 0; i != x - 1; i++)
        _checker.pop_front();
    end = _checker.front();
    return end;
}

std::list<int> Component::set_data(std::list<int> origin, int pos, int value)
{
    std::list<int> temp;
    int tmp;

    if (pos == 1) {
        origin.pop_front();
        origin.push_front(value);
    }
    for (int i = 0; i != pos - 1; i++) {
        temp.push_front(origin.front());
        origin.pop_front();
    }
    origin.pop_front();
    origin.push_front(value);
    for (int i = 0; i != pos - 1; i++) {
        origin.push_front(temp.front());
        temp.pop_front();
    }
    return origin;
}

void Component::setChecker(std::list<int> _checker)
{
    this->checker = _checker;
    return;
}

std::string Component::getType(void)
{
    return type;
}

std::string Component::getName(void)
{
    return name;
}

void Component::verifState(std::size_t pin)
{
    if (pin > state.size())
        throw nts::IComponent::Error(nts::IComponent::Error::NUM_PIN);
}

nts::Tristate Component::getState(std::size_t pin)
{
    verifState(pin);
    std::list<nts::Tristate>::iterator it = state.begin();
    advance(it, pin - 1);
    return *it;
}

std::map<std::size_t, std::tuple<nts::IComponent *, std::size_t>> Component::getLinks(void)
{
    return Links;
}

std::string Component::getReadableState()
{
    std::string u = "U";
    std::string one = "1";
    std::string zero = "0";
    if (this->getState() == nts::Tristate::Undefined) {
        return u;
    }
    if (this->getState() == nts::Tristate::True) {
        return one;
    }
    else {
        return zero;
    }
}
