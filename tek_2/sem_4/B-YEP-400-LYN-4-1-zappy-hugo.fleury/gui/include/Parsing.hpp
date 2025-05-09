/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** Parsing
*/

#ifndef PARSING_HPP_
    #define PARSING_HPP_
    #include <iostream>
    #include <string.h>

    class Parsing {
        private:
            int _port;
            std::string _machine;

        public:
            ~Parsing(void) {}
            Parsing(void) : _port(4242), _machine("127.0.0.1") {}

            int getPort(void) const { return this->_port; }
            std::string getMachine(void) const { return this->_machine; }

            void parse(int argc, char **argv);

            void printUsage(void) const;
    };

#endif /* !PARSING_HPP_ */