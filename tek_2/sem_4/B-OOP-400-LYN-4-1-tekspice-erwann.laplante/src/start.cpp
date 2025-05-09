/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** start
*/

#include "Shell.hpp"
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

int test_function_clear_str(char c)
{
    if (c != ' ' && c != '\t')
        return 0;
    return 1;
}

std::string clear_str(std::string str)
{
    std::string new_str = "";
    int state = 2;

    while ((test_function_clear_str(str[0]) == 1) && (str[1] != '\0'))
        str.erase(0, 1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '#') {
            if (state == 0) {
                new_str.pop_back();
            }
            break;
        }
        if (test_function_clear_str(str[i]) == 0) {
            new_str.push_back(str[i]);
            state = 1;
        } else if ((test_function_clear_str(str[i]) == 1) && state == 1
        && str[i + 1] != '\0' && test_function_clear_str(str[i + 1]) == 0) {
            new_str.push_back(' ');
            state = 0;
        }
    }
    return new_str;
}

std::string get_name(std::string str)
{
    std::string new_str = "";

    for (auto i = 0; str[i]; i++) {
        if (str[i] == ':' || str[i] == '=')
            return new_str;
        new_str.push_back(str[i]);
    }
    return new_str;
}

std::string get_pin(std::string str)
{
    std::string new_str = "";

    for (auto i = 0; str[i]; i++) {
        if (str[i] == ' ')
            break;
        new_str.push_back(str[i]);
    }
    return new_str;
}

std::map<std::string, std::unique_ptr<nts::IComponent>> read_file(std::string filename, std::map<std::string, std::unique_ptr<nts::IComponent>> Elements)
{
    reverse(filename.begin(), filename.end());
    if (filename.compare(0, 4, "stn.") != 0)
        throw nts::IComponent::Error(nts::IComponent::Error::NTS);
    reverse(filename.begin(), filename.end());

    std::ifstream file(filename);
    std::string line;
    int level = 0;

    if (!file)
        throw nts::IComponent::Error(nts::IComponent::Error::OPEN);
    while (std::getline(file, line)) {
        line = clear_str(line);
        if (line.compare(0, 10, ".chipsets:") == 0)
            level = 1;
        else if (line.compare(0, 7, ".links:") == 0)
            level = 2;
        else if (line.length() != 0 && line[0] != '#' && line[0] != '\n') {
            if (level == 1) {
                if (line.compare(0, 5, "input") == 0) {
                    std::string name;
                    line = line.erase(0, 6);
                    name = get_name(line);
                    if (name == "")
                        throw nts::IComponent::Error(nts::IComponent::Error::DEC_NAME);
                    if (Elements.find(name) != Elements.end())
                        throw nts::IComponent::Error(nts::IComponent::Error::ALREADY);
                    Elements[name] = std::make_unique<Input>();
                    Elements[name]->createComponent("input");
                    Elements[name]->setType("input");
                    Elements[name]->setName(name);
                } else if (line.compare(0, 6, "output") == 0) {
                    std::string name;
                    line = line.erase(0, 7);
                    name = get_name(line);
                    if (name == "")
                        throw nts::IComponent::Error(nts::IComponent::Error::DEC_NAME);
                    if (Elements.find(name) != Elements.end())
                        throw nts::IComponent::Error(nts::IComponent::Error::ALREADY);
                    Elements[name] = std::make_unique<Output>();
                    Elements[name]->createComponent("output");
                    Elements[name]->setType("output");
                    Elements[name]->setName(name);
                } else if (line.compare(0, 4, "true") == 0) {
                    std::string name;
                    line = line.erase(0, 5);
                    name = get_name(line);
                    if (name == "")
                        throw nts::IComponent::Error(nts::IComponent::Error::DEC_NAME);
                    if (Elements.find(name) != Elements.end())
                        throw nts::IComponent::Error(nts::IComponent::Error::ALREADY);
                    Elements[name] = std::make_unique<True>();
                    Elements[name]->createComponent("true");
                    Elements[name]->setType("true");
                    Elements[name]->setName(name);
                } else if (line.compare(0, 5, "false") == 0) {
                    std::string name;
                    line = line.erase(0, 6);
                    name = get_name(line);
                    if (name == "")
                        throw nts::IComponent::Error(nts::IComponent::Error::DEC_NAME);
                    if (Elements.find(name) != Elements.end())
                        throw nts::IComponent::Error(nts::IComponent::Error::ALREADY);
                    Elements[name] = std::make_unique<False>();
                    Elements[name]->createComponent("false");
                    Elements[name]->setType("false");
                    Elements[name]->setName(name);
                } else if (line.compare(0, 5, "clock") == 0) {
                    std::string name;
                    line = line.erase(0, 6);
                    name = get_name(line);
                    if (name == "")
                        throw nts::IComponent::Error(nts::IComponent::Error::DEC_NAME);
                    if (Elements.find(name) != Elements.end())
                        throw nts::IComponent::Error(nts::IComponent::Error::ALREADY);
                    Elements[name] = std::make_unique<Clock>();
                    Elements[name]->createComponent("clock");
                    Elements[name]->setType("clock");
                    Elements[name]->setName(name);
                } else if (line.compare(0, 3, "and") == 0) {
                    std::string name;
                    line = line.erase(0, 4);
                    name = get_name(line);
                    if (name == "")
                        throw nts::IComponent::Error(nts::IComponent::Error::DEC_NAME);
                    if (Elements.find(name) != Elements.end())
                        throw nts::IComponent::Error(nts::IComponent::Error::ALREADY);
                    Elements[name] = std::make_unique<And>();
                    Elements[name]->createComponent("and");
                    Elements[name]->setType("and");
                    Elements[name]->setName(name);
                } else if (line.compare(0, 2, "or") == 0) {
                    std::string name;
                    line = line.erase(0, 3);
                    name = get_name(line);
                    if (name == "")
                        throw nts::IComponent::Error(nts::IComponent::Error::DEC_NAME);
                    if (Elements.find(name) != Elements.end())
                        throw nts::IComponent::Error(nts::IComponent::Error::ALREADY);
                    Elements[name] = std::make_unique<Or>();
                    Elements[name]->createComponent("or");
                    Elements[name]->setType("or");
                    Elements[name]->setName(name);
                } else if (line.compare(0, 3, "xor") == 0) {
                    std::string name;
                    line = line.erase(0, 4);
                    name = get_name(line);
                    if (name == "")
                        throw nts::IComponent::Error(nts::IComponent::Error::DEC_NAME);
                    if (Elements.find(name) != Elements.end())
                        throw nts::IComponent::Error(nts::IComponent::Error::ALREADY);
                    Elements[name] = std::make_unique<Xor>();
                    Elements[name]->createComponent("xor");
                    Elements[name]->setType("xor");
                    Elements[name]->setName(name);
                } else if (line.compare(0, 3, "not") == 0) {
                    std::string name;
                    line = line.erase(0, 4);
                    name = get_name(line);
                    if (name == "")
                        throw nts::IComponent::Error(nts::IComponent::Error::DEC_NAME);
                    if (Elements.find(name) != Elements.end())
                        throw nts::IComponent::Error(nts::IComponent::Error::ALREADY);
                    Elements[name] = std::make_unique<Not>();
                    Elements[name]->createComponent("not");
                    Elements[name]->setType("not");
                    Elements[name]->setName(name);
                } else if (line.compare(0, 4, "4001") == 0) {
                    std::string name;
                    line = line.erase(0, 5);
                    name = get_name(line);
                    if (name == "")
                        throw nts::IComponent::Error(nts::IComponent::Error::DEC_NAME);
                    if (Elements.find(name) != Elements.end())
                        throw nts::IComponent::Error(nts::IComponent::Error::ALREADY);
                    Elements[name] = std::make_unique<My_4001>();
                    Elements[name]->createComponent("4001");
                    Elements[name]->setType("4001");
                    Elements[name]->setName(name);
                } else if (line.compare(0, 4, "4011") == 0) {
                    std::string name;
                    line = line.erase(0, 5);
                    name = get_name(line);
                    if (name == "")
                        throw nts::IComponent::Error(nts::IComponent::Error::DEC_NAME);
                    if (Elements.find(name) != Elements.end())
                        throw nts::IComponent::Error(nts::IComponent::Error::ALREADY);
                    Elements[name] = std::make_unique<My_4011>();
                    Elements[name]->createComponent("4011");
                    Elements[name]->setType("4011");
                    Elements[name]->setName(name);
                } else if (line.compare(0, 4, "4030") == 0) {
                    std::string name;
                    line = line.erase(0, 5);
                    name = get_name(line);
                    if (name == "")
                        throw nts::IComponent::Error(nts::IComponent::Error::DEC_NAME);
                    if (Elements.find(name) != Elements.end())
                        throw nts::IComponent::Error(nts::IComponent::Error::ALREADY);
                    Elements[name] = std::make_unique<My_4030>();
                    Elements[name]->createComponent("4030");
                    Elements[name]->setType("4030");
                    Elements[name]->setName(name);
                } else if (line.compare(0, 4, "4069") == 0) {
                    std::string name;
                    line = line.erase(0, 5);
                    name = get_name(line);
                    if (name == "")
                        throw nts::IComponent::Error(nts::IComponent::Error::DEC_NAME);
                    if (Elements.find(name) != Elements.end())
                        throw nts::IComponent::Error(nts::IComponent::Error::ALREADY);
                    Elements[name] = std::make_unique<My_4069>();
                    Elements[name]->createComponent("4069");
                    Elements[name]->setType("4069");
                    Elements[name]->setName(name);
                } else if (line.compare(0, 4, "4071") == 0) {
                    std::string name;
                    line = line.erase(0, 5);
                    name = get_name(line);
                    if (name == "")
                        throw nts::IComponent::Error(nts::IComponent::Error::DEC_NAME);
                    if (Elements.find(name) != Elements.end())
                        throw nts::IComponent::Error(nts::IComponent::Error::ALREADY);
                    Elements[name] = std::make_unique<My_4071>();
                    Elements[name]->createComponent("4071");
                    Elements[name]->setType("4071");
                    Elements[name]->setName(name);
                } else if (line.compare(0, 4, "4081") == 0) {
                    std::string name;
                    line = line.erase(0, 5);
                    name = get_name(line);
                    if (name == "")
                        throw nts::IComponent::Error(nts::IComponent::Error::DEC_NAME);
                    if (Elements.find(name) != Elements.end())
                        throw nts::IComponent::Error(nts::IComponent::Error::ALREADY);
                    Elements[name] = std::make_unique<My_4081>();
                    Elements[name]->createComponent("4081");
                    Elements[name]->setType("4081");
                    Elements[name]->setName(name);
                } else
                    throw nts::IComponent::Error(nts::IComponent::Error::TYPE);
            } else if (level == 2) {
                std::string name = get_name(line);
                std::string pin;
                std::string other_name;
                std::string other_pin;
                if (name == "")
                    throw nts::IComponent::Error(nts::IComponent::Error::NAME);
                line.erase(0, name.length());
                if (line[0] != ':')
                    throw nts::IComponent::Error(nts::IComponent::Error::DELI);
                line.erase(0, 1);
                pin = get_pin(line);
                if (pin == "")
                    throw nts::IComponent::Error(nts::IComponent::Error::PIN);
                line.erase(0, pin.length() + 1);
                other_name = get_name(line);
                if (other_name == "")
                    throw nts::IComponent::Error(nts::IComponent::Error::NAME);
                line.erase(0, other_name.length());
                if (line[0] != ':')
                    throw nts::IComponent::Error(nts::IComponent::Error::DELI);
                line.erase(0, 1);
                other_pin = get_pin(line);
                if (other_pin == "")
                    throw nts::IComponent::Error(nts::IComponent::Error::PIN);
                std::stringstream stream_pin(pin);
                std::stringstream stream_other_pin(other_pin);
                std::size_t my_pin;
                std::size_t my_other_pin;
                stream_pin >> my_pin;
                stream_other_pin >> my_other_pin;
                if (Elements.find(name) != Elements.end() && Elements.find(other_name) != Elements.end()) {
                    Elements[name]->verifState(my_pin);
                    Elements[other_name]->verifState(my_other_pin);
                    Elements[name]->setLinkBi(my_pin, *Elements[other_name], my_other_pin);
                } else if (Elements.find(name) == Elements.end()) {
                    nts::IComponent::Error erreur(nts::IComponent::Error::VALUE);
                    erreur.str = name;
                    throw erreur;
                } else {
                    nts::IComponent::Error erreur(nts::IComponent::Error::VALUE);
                    erreur.str = other_name;
                    throw erreur;
                }
            } else {
                nts::IComponent::Error erreur(nts::IComponent::Error::LINE);
                erreur.str = line;
                throw erreur;
            }
        }
    }
    std::vector<std::string> keys;
    for (auto it = Elements.begin(); it != Elements.end(); it++) {
        keys.push_back(it->first);
    }
    return Elements;
}

int tekspice_function(int ac, char **av)
{
    std::map<std::string, std::unique_ptr<nts::IComponent>> Elements;

    try {
        if (ac != 2)
            throw nts::IComponent::Error(nts::IComponent::Error::ARGUMENTS);
        Elements = read_file(av[1], move(Elements));
        if (Elements.empty() == true)
            throw nts::IComponent::Error(nts::IComponent::Error::NO_COMP);
        std::vector<std::string> keys;
        for (auto it = Elements.begin(); it != Elements.end(); it++) {
            keys.push_back(it->first);
        }
        Shell term(move(Elements), keys);
        term.terminal();
    }
    catch (std::exception const &e) {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
        return 84;
    }
    return 0;
}
