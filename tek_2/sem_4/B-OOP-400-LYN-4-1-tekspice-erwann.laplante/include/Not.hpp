/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** Not
*/

#ifndef NOT_HPP_
    #define NOT_HPP_

    #include "Component.hpp"

    class Not : virtual public Component {
        public:
            Not();
            ~Not();

            nts::Tristate NotFunction(nts::Tristate a);

            void simulation(size_t first, nts::Tristate new_state, size_t pin);

        protected:
        private:
    };

#endif /* !NOT_HPP_ */
