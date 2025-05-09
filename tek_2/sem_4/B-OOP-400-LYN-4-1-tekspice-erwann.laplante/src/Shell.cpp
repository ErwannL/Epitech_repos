/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** Shell
*/

#include "Shell.hpp"

sig_atomic_t volatile end_loope = false;

Shell::Shell(std::map<std::string, std::unique_ptr<nts::IComponent>> Elements, std::vector<std::string> keys)
{
    sig = false;
    tick = 0;
    _keys = keys;
    _Elements = move(Elements);
}

Shell::~Shell()
{
}

void stop_loop(int signum)
{
    end_loope = true;
}

int Shell::commands(std::string str)
{
    str = clear_str(str);
    std::string key;
    std::string input = str;
    if (str == "display") {
        this->display();
        return 0;
    } else if (str == "exit") {
        return 1;
    } else if (strchr(str.c_str(), '=') != NULL) {
        key = get_name(str);
        input = input.erase(0, input.find('=', 0) + 1);
        if (input == "1" | input == "0" | input == "U") {
            this->replace_input(key, input);
        } else {
            nts::IComponent::Error erreur(nts::IComponent::Error::C_TYPE);
            erreur.str = input;
            throw erreur;
        }
    } else if (str == "simulate") {
        this->simulate();
    } else if (str == "loop") {
        signal(SIGINT, stop_loop);
        while (end_loope == false) {
           this->simulate();
           this->display();
        }
        signal(SIGINT, SIG_DFL);
        end_loope = false;
    } else {
        nts::IComponent::Error erreur(nts::IComponent::Error::COMMAND);
        erreur.str = str;
        throw erreur;
    }
    return 0;
}

int Shell::terminal()
{
    std::vector<std::string> keys = this->get_keys();
    for (const auto &key: keys) {
        if (_Elements[key]->getType() == "clock") {
            if (_Elements[key]->getState() == nts::True)
                _Elements[key]->setState(nts::False);
            else if (_Elements[key]->getState() == nts::False)
                _Elements[key]->setState(nts::True);
        }
    }
    while (_FakeElements.size() != 0) {
        this->set_elem(std::get<0>(_FakeElements.front()), std::get<1>(_FakeElements.front()));
        this->_FakeElements.pop_front();
    }
    this->recursive_function();

    std::string str;
    std::cout << "> ";

    while (getline(std::cin, str)) {
        if (this->commands(str) == 1) {
            break;
        }
        std::cout << "> ";
    }
    return 0;
}

void Shell::display()
{
    std::cout << "tick: " << this->get_tick() << std::endl;
    std::cout << "input(s):" << std::endl;
    std::map<std::string, std::unique_ptr<nts::IComponent>> el = this->get_elem();
    std::vector<std::string> keys = this->get_keys();
    for (const auto &key: keys) {
        if (el[key]->getType() == "input" || el[key]->getType() == "clock") {
            std::cout << "  " << key << ": " << el[key]->getReadableState() << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (const auto &key: keys) {
        if (el[key]->getType() == "output") {
            std::cout << "  " << key << ": " << el[key]->getReadableState() << std::endl;
        }
    }
    this->_Elements = move(el);
}

bool Shell::checkOutput(std::vector<std::string> keys)
{
    bool check = true;

    for (const auto &key: keys) {
        if (this->_Elements[key]->getType() == "output" && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 1) == 0) {
            check = false;
        }
    }
    return check;
}

void Shell::recursive_function()
{
    std::vector<std::string> keys;
    std::string end;
    for (auto it = this->_Elements.begin(); it != this->_Elements.end(); it++) {
        keys.push_back(it->first);
    }
    for (const auto &key: keys) {
        std::vector<std::size_t> keys_bis;
        std::map<std::size_t, std::tuple<nts::IComponent *, std::size_t>> tmp = this->_Elements[key]->getLinks();
        for (auto it = tmp.begin(); it != tmp.end(); it++) {
            keys_bis.push_back(it->first);
        }
        if (checkOutput(keys) == true) {
            return;
        }
        for (const auto &key_bis: keys_bis) {
            std::tuple<nts::IComponent *, std::size_t> other = this->_Elements[key]->getLinks()[key_bis];
            if ((this->_Elements[key]->getType() == "input" && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 1) == 0)
            || (this->_Elements[key]->getType() == "clock" && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 1) == 0)
            || (this->_Elements[key]->getType() == "true" && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 1) == 0)
            || (this->_Elements[key]->getType() == "false" && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 1) == 0)
            || (this->_Elements[key]->getType() == "not" && key_bis == 2 && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 2) == 1)
            || (this->_Elements[key]->getType() == "4069"
                && ((key_bis == 2 && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 2) == 1)
                || (key_bis == 4 && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 4) == 1)
                || (key_bis == 6 && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 6) == 1)
                || (key_bis == 8 && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 8) == 1)
                || (key_bis == 10 && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 10) == 1)
                || (key_bis == 12 && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 12) == 1)))
            || (key_bis == 3 && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 3) == 1)
            || (key_bis == 4 && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 4) == 1)
            || (key_bis == 10 && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 10) == 1)
            || (key_bis == 11 && this->_Elements[key]->retrieve_data(this->_Elements[key]->getChecker(), 11) == 1)) {
                std::get<0>(other)->simulation(key_bis, this->_Elements[key]->getState(key_bis), std::get<1>(other));
                if (this->_Elements[key]->getType() == "input") {
                    this->_Elements[key]->setChecker(this->_Elements[key]->getChecker() = this->_Elements[key]->set_data(this->_Elements[key]->getChecker(), 1, 1));
                }
            }
        }
    }
    recursive_function();
}

void Shell::simulate()
{
    std::vector<std::string> keys = this->get_keys();
    for (const auto &key: keys) {
        if (_Elements[key]->getType() == "clock") {
            if (_Elements[key]->getState() == nts::True)
                _Elements[key]->setState(nts::False);
            else if (_Elements[key]->getState() == nts::False)
                _Elements[key]->setState(nts::True);
        }
    }
    while (_FakeElements.size() != 0) {
        this->set_elem(std::get<0>(_FakeElements.front()), std::get<1>(_FakeElements.front()));
        this->_FakeElements.pop_front();
    }
    this->recursive_function();
    std::vector<std::string> checky;
    for (auto it = this->_Elements.begin(); it != this->_Elements.end(); it++) {
        checky.push_back(it->first);
    }
    for (const auto &key: checky) {
        std::list<int> check;
        check.assign(14, 0);
        this->_Elements[key]->setChecker(check);
    }
    this->recursive_function();
    std::vector<std::string> checka;
    for (auto it = this->_Elements.begin(); it != this->_Elements.end(); it++) {
        checka.push_back(it->first);
    }
    for (const auto &key: checka) {
        std::list<int> check;
        check.assign(14, 0);
        this->_Elements[key]->setChecker(check);
    }
    tick++;
}

void Shell::replace_input(std::string key, std::string input)
{
    nts::Tristate state;

    if (input == "1")
        state = nts::Tristate::True;
    else if (input == "0")
        state = nts::Tristate::False;
    else
        state = nts::Tristate::Undefined;
    if (_Elements.count(key)) {
        if (_Elements[key]->getType() == "input" || _Elements[key]->getType()  == "clock")
            _FakeElements.push_back({key, state});
        else
            throw nts::IComponent::Error(nts::IComponent::Error::MODIF);
    } else {
        nts::IComponent::Error erreur(nts::IComponent::Error::VALUE);
        erreur.str = key;
        throw erreur;
    }
}

void Shell::set_elem(std::string key, nts::Tristate state)
{
    std::string str = this->_Elements[key]->getType();
    if (str == "input" || str == "clock")
        this->_Elements[key]->setState(state);
    else
        throw nts::IComponent::Error(nts::IComponent::Error::MODIF);
}

int Shell::get_tick()
{
    return this->tick;
}

std::vector<std::string> Shell::get_keys()
{
    return _keys;
}

std::map<std::string, std::unique_ptr<nts::IComponent>> Shell::get_elem()
{
    return move(this->_Elements);
}
