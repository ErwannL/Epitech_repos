/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** shell
*/

#ifndef SHELL_HPP_
    #define SHELL_HPP_

    #include "Component.hpp"

    class Shell {
        public:
            Shell(std::map<std::string, std::unique_ptr<nts::IComponent>>, std::vector<std::string>);
            ~Shell();

            int commands(std::string str);
            void display();
            int terminal();
            void simulate();
            void replace_input(std::string x, std::string y);
            void recursive_function();
            bool checkOutput(std::vector<std::string> keys);

            void set_elem(std::string key, nts::Tristate state);

            int get_tick();
            std::vector<std::string> get_keys();
            std::map<std::string, std::unique_ptr<nts::IComponent>> get_elem();

        protected:
            bool sig;
            int tick;
            std::map<std::string, std::unique_ptr<nts::IComponent>> _Elements;
            std::list<std::tuple<std::string, nts::Tristate>> _FakeElements;
            std::vector<std::string> _keys;

        private:
    };

#endif /* !SHELL_HPP_ */
