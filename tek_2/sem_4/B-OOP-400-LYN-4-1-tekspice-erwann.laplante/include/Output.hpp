/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
    #define OUTPUT_HPP_

    #include "Component.hpp"

    class Output : virtual public Component {
        public:
            Output();
            ~Output();
            void simulation(size_t first, nts::Tristate new_state, size_t pin);

        protected:
        private:
    };

#endif /* !OUTPUT_HPP_ */
