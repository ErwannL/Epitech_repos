/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** Xor
*/

#ifndef XOR_HPP_
    #define XOR_HPP_

    #include "Component.hpp"

    class Xor : virtual public Component {
        public:
            Xor();
            ~Xor();

            nts::Tristate XorFunction(nts::Tristate a, nts::Tristate b);

            void simulation(size_t first, nts::Tristate new_state, size_t pin);

        protected:
        private:
    };

#endif /* !XOR_HPP_ */
