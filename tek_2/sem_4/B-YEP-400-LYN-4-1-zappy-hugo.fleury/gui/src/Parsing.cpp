/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** Parsing
*/

#include "../include/Parsing.hpp"

// ----- Public -----

void Parsing::parse(int argc, char **argv) {
    try {
        for (int i = 1; i < argc; i++) {
            std::string arg = argv[i];
            if (arg == "-p") {
                if (i + 1 < argc) {
                    this->_port = std::atoi(argv[i + 1]);
                    i++;
                } else {
                    throw std::invalid_argument("Missing port number argument.");
                }
            } else if (arg == "-h") {
                if (i + 1 < argc) {
                    this->_machine = argv[i + 1];
                    i++;
                } else {
                    throw std::invalid_argument("Missing machine name argument.");
                }
            } else if (arg == "-help") {
                printUsage();
                std::exit(0);
            } else {
                throw std::invalid_argument("Invalid argument: " + arg);
            }
        }

        if (this->_port == -1) {
            throw std::invalid_argument("Missing mandatory -p argument.");
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        printUsage();
        std::exit(84);
    }
}

// ----- Private -----

void Parsing::printUsage(void) const
{
    std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
    std::cout << "\tport\t\tis the port number" << std::endl;
    std::cout << "\tmachine\t\tis the name of the machine; localhost by default" << std::endl;
}