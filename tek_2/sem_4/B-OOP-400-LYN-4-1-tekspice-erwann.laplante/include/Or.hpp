/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** Or
*/

#ifndef OR_HPP_
    #define OR_HPP_

    #include "Component.hpp"

    class Or : virtual public Component {
        public:
            Or();
            ~Or();

            nts::Tristate OrFunction(nts::Tristate a, nts::Tristate b);

            void simulation(size_t first, nts::Tristate new_state, size_t pin);

        protected:
        private:
    };

#endif /* !OR_HPP_ */
