/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** And
*/

#ifndef AND_HPP_
    #define AND_HPP_

    #include "Component.hpp"

    class And : virtual public Component {
        public:
            And();
            ~And();

            nts::Tristate AndFunction(nts::Tristate a, nts::Tristate b);

            void simulation(size_t first, nts::Tristate new_state, size_t pin);

        protected:
        private:
    };

#endif /* !AND_HPP_ */
