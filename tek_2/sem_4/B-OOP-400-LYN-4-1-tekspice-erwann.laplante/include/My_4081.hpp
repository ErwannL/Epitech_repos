/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** My_4081
*/

#ifndef MY_4081_HPP_
    #define MY_4081_HPP_

    #include "And.hpp"

    class My_4081: virtual public And {
        public:
            My_4081();
            ~My_4081();

            void simulation(size_t first, nts::Tristate new_state, size_t pin);

        protected:
        private:
    };

#endif /* !MY_4081_HPP_ */
